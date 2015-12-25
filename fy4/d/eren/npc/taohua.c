#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit SMART_NPC; 
void create()
{ 
        set_name("�һ�����",({"taohua","niangzi","taohua niangzi"}));
        set("title",YEL"÷��������"NOR);
        set("long", "�����������ϵı��飬�������۾������ֳ��Թ��֮ɫ����������˭���ܿ��ó��ġ���\n");
        set("age",39);
        set("combat_exp", 7000000);
         set("attitude", "aggressive");
        
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}  
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        object another;
        message("vision",name() + "̾�˿������ֳ���һ�����ϸɿݵ����ᡣ\n", environment(),
                this_object() );
        another = new(__DIR__"liaoyin");
        another->move(environment(this_object()));
        destruct(this_object());
}     
