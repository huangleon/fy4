 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void smart_fight();
int leave();
void create()
{
    set_name("兴国大师", ({ "master xing", "master", "xing" }) ); 
    set("gender", "男性");
    set("nickname", HIY "佛法无边"NOR);
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 74);
    set("attitude", "peaceful");
    set("class", "bonze");
    set("apprentice_available", 3); 
    set("resistance/kee",30);
    set("resistance/sen",30);   
    set("resistance/gin",30);
    
    set("int", 30);
    set("spi", 30);
    set("con", 30);
    set("cps", 30);
    set("cor", 50);
    set("agi",25); 
    set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
    set("fly_target",1);
    set("atman", 1000);
    set("max_atman", 1000);
    set("force", 1200);
    set("max_force", 1200);
    set("force_factor", 90);
    set("mana", 2000);
    set("max_mana", 2000);
     
    set("combat_exp", 8000000); 
    set_temp("apply/armor", 200);
    set_temp("apply/damage", 200);
    set("score", 9000); 
    set_skill("staff", 200);
    set_skill("unarmed", 190);
    set_skill("force", 200);
    set_skill("dodge", 120);
    set_skill("literate", 140);
    set_skill("chanting", 200);
    set_skill("parry", 120);
    set_skill("magic", 200);
    set_skill("cloudstaff", 170);
    set_skill("lotusforce", 150);
    set_skill("buddhism", 200);
    set_skill("essencemagic", 200);
    set_skill("notracesnow",120);
    set_skill("dabei-strike",120);
    set_skill("move",120);
    set_skill("perception", 100);
    
    map_skill("staff", "cloudstaff");
    map_skill("parry", "cloudstaff");
    map_skill("force", "lotusforce");
    map_skill("magic", "essencemagic");
    map_skill("dodge","notracesnow");
    map_skill("unarmed","dabei-strike");
    map_skill("move","notracesnow");
    
    set("inquiry", ([
        "leave" : (: leave :),
                ]));
    create_family("兴国禅寺", 3, "住持");
    set("rank_nogen",1);
    set("ranks",({"僧人","大师","罗汉","金刚","高僧",YEL"神僧"NOR,YEL"圣僧"NOR,HIY"主持"NOR})); 
    setup();
    carry_object(__DIR__"obj/buddha_staff")->wield();
    carry_object("/obj/armor/cloth")->wear(); 
} 
void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say 慢著，一个一个来。");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say 老纳今天已经收够了弟子，不想再收徒了。");
    }
} 
void do_recruit(object ob)
{
    if (ob->query("once_menpai/bonze") && ob->query("class")!="bonze") {
                command("shake");
                command("say 施主反复无常，没有向佛之心。\n");
                return;
        }
    if(ob->query("marry")){
                message_vision("$N抬头看了看$n：这位施主六根未净，还是请回吧。\n", 
                                this_object(), ob);
                return;
        }
    if( (string)ob->query("gender") != "男性" )
        command("say 阿弥陀佛，女施主不要跟老纳开玩笑。");
    else if(ob->query_temp("marks/ye")){
        ob->set("class","bonze");
        command("say 看在白云城主的份上，我就收你为徒吧！");
        command("say 阿弥陀佛，善哉！善哉！");
        command("recruit " + ob->query("id") );
        ob->set("once_menpai/bonze",1);
    }
    else if(ob->query_temp("marks/lady")){
        ob->set("class","bonze");
        command("say 看在你不惧生死，见义勇为的份上，我就收你为徒吧！");
        command("say 阿弥陀佛，善哉！善哉！");
        command("recruit " + ob->query("id") );
        ob->set("once_menpai/bonze",1);
        }
} 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) ) {
        add("apprentice_availavble", -1);
        return 1;
    }
} 
int accept_fight(object me)
{
    if( (string)me->query("class")=="bonze" )
        command("say 阿弥陀佛！出家人戒逞强恶斗！老衲不敢违反清规。");
    else
        command("say 施主既然身负绝艺，老衲佩服便是，也不必较量了。"); 
    return 0;
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "bonze"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：阿弥陀佛,出家人与世无争，却也不任人欺侮，施主请了！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="bonze") return 0;
        message_vision(CYN"$N合掌道：阿弥陀佛，既是无缘，何必再留，以后也不要再回来了。\n"NOR, this_object(),this_player());
        message_vision(CYN"$N说：佛门的神通术和心法非弟子不能使用。\n"NOR,this_object(),this_player());
        return 1;
} 
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie2");
                return;
        }
        who->perform_action("staff.longxianyuye"); 
        return;
}        
