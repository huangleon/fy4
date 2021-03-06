#include <ansi.h>
inherit "/d/taiping/npc/smart_npc"; 
void look_for_company(object me, object room, int n);
void summon_npc(object me, object next_room);
int kill_him(); 
void create()
{
        set_name("张老实",({"zhang laoshi","zhang","laoshi"}));
        set("title","面馆老板");
        set("long","张老实真的是个老实人，他不但是这小面馆的老板，也是厨子和伙计，所以一
年到头，身上总是围着块油腻腻的围裙，从早上一直忙到大黑，赚来的钱却连
个老婆都养不起。。\n");
        set("gender","男性");
        set("group","citizen"); 
        
        set("combat_exp",4000000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
                
        set("max_atman",random(1000));
        set("atman",query("max_atman"));
        set("max_mana",random(500));
        set("mana",query("max_mana"));
        set("max_force",1000+random(500));
        set("force",query("max_force"));
        set("force_factor",100);
        
        set("resistance/kee",random(30));
        set("resistance/gin",random(30));
        set("resistance/sen",random(30));
                
        set("inquiry", ([
                "日子" : "镇外有强盗，镇内也有强盗，这日子可怎么过下去呀！\n",
                "强盗" : "镇外有强盗，镇内也有强盗，这日子可怎么过下去呀！\n",
                "镇外的强盗" : "还不就是龙虎寨的那些山贼么！\n",
                "镇内的强盗" : "不能说，不能说呀。。\n",
                "江湖五毒"      :       (: kill_him :),
                   "潘伶"  :               (: kill_him :),
        ]));
        
        
        set("death_msg",CYN"\n$N悔恨地说：“我看来是没希望娶媳妇了。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
//              10: name()+"叫道：“来人啊，强盗打劫店铺啦！”\n",
                100: (: look_for_company(this_object(),environment(this_object()),5) :)
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "张老实笑眯眯地道：“吃面，吃面。”\n",
                "张老实叹了口气说：“这日子可怎么过下去呀！”\n",
        }) );                   
        
        CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","tigerstrike",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
    
}  
int accept_object(object who, object ob)
{
        if (ob->value()>=300000) {
                if (!who->query_temp("wanma/胜地痞")) {
                                command("say 你给我也没用。。胡歪瓜一来又要拿走。。。");
                                command("sigh");
                                return 0;
                } else {
                        command("touch "+who->get_id());
                        command("say 太感谢了，我决不会忘记英雄的大恩大德的！");
                        if (!who->query("wanma/义助张老实")) {
                                who->set("wanma/义助张老实",1);
                                who->add("combat_exp",1000);
                           who->add("potential",200);
                                who->add("wanma/声誉",1);
                                tell_object(who,HIW"你被奖励了！一千点实战经验，二百点潜能！\n"NOR);
                                tell_object(who,HIW"你在这个边远小镇的声誉上升了！\n"NOR);
                        } 
                        return 1;
                }       
        }
        command("shake");
        command("say 这点哪够糊口啊。");
        return 0;
}  
int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"张老实现在没空回答你。\n");
                return 1;
                }
        message_vision(CYN"$N脸上忽然露出种冷淡而诡秘的微笑，这种笑容本不该出现脸上的。\n"NOR,this_object());
        message_vision(CYN"$N冷冷笑着道：“既然你知道了，就不能让你再活着出去。\n",this_object());
        another = new(__DIR__"panling");
        another->move(environment(this_object()));
        destruct(ob);
        return 1;
}   
/*
void look_for_company(object me, object room, int n) { 
        object *inv, next_room;
        int i;  
        mapping exits;
        string *dirs, dest;
        
        
        if( mapp(exits = room->query("exits")) ) 
        {
           dirs=keys(exits);
                for(i=0;i<sizeof(dirs);i++)
                {
                        dest=room->query("exits/"+dirs[i]);
                        if(!next_room=find_object(dest))
                                next_room=load_object(dest);
                        if(!objectp(next_room)) continue;
                        if (next_room==environment(me)) continue;
                        if (next_room->query("summoned")) continue;
                        if(!n) continue;
                        summon_npc(me,next_room);
                        look_for_company(me,next_room,n-1);
                }
        }
        room->delete("summoned");
}  
void summon_npc(object me, object room) {
        object *inv;
        int i;
        
        room->set("summoned",1);
        inv=all_inventory(room);
        if (!sizeof(inv)) return;
        for(i=0;i<sizeof(inv);i++){
                if (inv[i]->is_character() && !userp(inv[i]) 
                        && inv[i]->query("group")==me->query("group")
                        && !inv[i]->is_fighting()) {
                        message_vision("there is a "+inv[i]->query("id")+".\n",me);
                        message_vision("$N说：“"+me->query("name")+"好像出事了，我得去看看。”\n",inv[i]);
                        message_vision("$N匆匆忙忙地离开了。\n",inv[i]);
                        inv[i]->move(environment(me));
                        message_vision("$N急急忙忙地走了过来。\n",inv[i]);
                }
        }
}  
*/ 
