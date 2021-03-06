 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int leave(); 
void create()
{
    set_name("雪蕊儿", ({ "master xuerui", "master","xuerui" }) );
    set("class","legend");      
    set("gender", "女性" );
    set("nickname", HIG "多情剑客"NOR);
    set("reward_npc", 1);
    set("difficulty", 35);
    set("age", 26);
    set("int", 30);
    set("per", 30);
    set("cor",40);
    set("str",100);
    
    set("apprentice_available", 50);
    create_family("铁雪山庄", 1, "庄主夫人");
    set("rank_nogen",1);
    set("ranks",({"棋童","小侠","少侠","大侠","奇侠",WHT"狂侠"NOR,WHT"侠圣"NOR,HIW"隐侠"NOR}));
    set("long",
        "雪蕊儿从十五岁开始就和爱夫铁少行侠江湖，俩人刀剑合壁，\n"
        "天下无敌。正当俩人名声顶盛之时，又忽然退出江湖，隐居于此。\n");
    set("inquiry", ([
        "leave" : (: leave :),
                ]));    
    set("fly_target",1);
    set("force_factor", 100);
    set("max_atman", 300);
    set("atman", 300);
    set("max_force", 1500);
    set("force", 1500);
    set("max_mana", 300);
    set("mana", 300); 
    set("combat_exp", 9999999);
    set("score", 90000);
    set_skill("unarmed", 100);
    set_skill("sword", 200);
    set_skill("force", 140);
    set_skill("parry", 100);
    set_skill("literate", 140);
    set_skill("dodge", 150);
    set_skill("perception", 200);
    set_skill("move",150);
    set_skill("blade",150);
    set_skill("shortsong-blade",100);
    set_skill("six-sense",200); 
    set_skill("meihua-shou", 120);
    set_skill("diesword",150);
    set_skill("qidaoforce", 140);
    set_skill("fall-steps", 120);
    
    map_skill("perception","six-sense");
    map_skill("unarmed", "meihua-shou");
    map_skill("sword","diesword");
    map_skill("force", "qidaoforce");
    map_skill("parry", "diesword");
    map_skill("dodge", "fall-steps"); 
    set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.luoyeqiufeng" :),
                (: perform_action, "sword.caidiekuangwu" :),
        }) );  
    setup();
    carry_object(__DIR__"obj/yellowcloth")->wear();
    carry_object(__DIR__"obj/msword")->wield();
}
void reset()
{
    delete_temp("learned");
    set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say 慢著，一个一个来。");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say 本庄主今天已经收了二十个弟子，不想再收徒了。");
    }
}
void do_recruit(object ob)
{
    if( (string)ob->query("gender") != "女性" )
    {      command("say 我只收女弟子，你还是去拜我的外子吧！");
    }
    else { 
        command("smile");
        command("say 你日后必有大成！");
        command("smile");
        command("recruit " + ob->query("id") );
    }
}
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "legend");
    add("apprentice_availavble", -1);
}
int accept_fight(object me)
{
    object xiaocui;
    if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
    {
        command("smile");
        command("say 还是让小翠来吧。");
        return 0;
    }
    else
        command("sigh");
    command("雪蕊儿慢慢的从翠竹凳上站起来，放下了手中的紫砂杯。");
    command("wield wangsword");
    command("say 请！");
    remove_call_out("do_unwie");
    call_out("do_unwie", 3);
    return 1;
} 
int do_unwie()
{
    if( !this_object()->is_fighting()) 
    {   
//      command("unwield wangsword");
        message_vision("$N拿起茶杯浅啖一口，含情脉脉的望了铁少一眼，又坐在竹凳上。\n", this_object());
        command("smile");
        return 1;
    }
    else
        call_out("do_unwie", 3);
}  
int do_killing(string arg)
{
    object player, victim, weapon;
    string name, id, id_class;
    if(!arg) return 0;
    player = this_player();
    if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
    {
        name = victim->name();
        if( name == "铁少")
        {
            message_vision("$N皱皱眉头。\n", this_object());
            weapon = present("wangsword", this_object());
            if(weapon)
            {
                message_vision("$N从赤皮剑鞘中抽出一把只有两指宽的虞姬剑握在手中。\n", this_object());
                weapon->wield();
            }
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            return 0;
        }
        if( name == "雪蕊儿")
        {
            message_vision("$N皱皱眉头。\n", this_object());
            weapon = present("wangsword", this_object());
            if(weapon)
            {
                message_vision("$N从赤皮剑鞘中抽出一把只有两指宽的虞姬剑握在手中。\n", this_object());
                weapon->wield();
            }
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            return 0;
        }
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "legend"&& userp(victim)&&player!=victim)
        {
            message_vision("$N皱皱眉头。\n", this_object());
            weapon = present("wangsword", this_object());
            if(weapon)
            {
                message_vision("$N从赤皮剑鞘中抽出一把只有两指宽的虞姬剑握在手中。\n", this_object());
                weapon->wield();
            }
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            message_vision("$N对著$n喝道：" + RANK_D->query_rude(player) 
                                                + "竟敢杀" + RANK_D->query_self_rude(this_object()) 
                                                + "的徒弟，去死吧。\n", this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
        
        return 0;
    }
    return 0;
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
} 
int leave() {
        if (this_player()->query("class")!="legend") return 0;
        message_vision(CYN"$N道：人各有志，我不勉强你留下。\n"NOR, this_object(),this_player());
        message_vision(CYN"$N说：只是聚气心法非弟子不能使用，蝶恋花剑法的精髓你大概也体会不到了。\n"NOR,this_object(),this_player());
        return 1;
} 
