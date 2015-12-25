#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit SMART_NPC; 
void create()
{ 
        set_name("ɨ�ص�����Ů��",({"middle aged nun","nun"}));
        set("long", "һ������ʮ���Ů�ᣬ������ǰ��ɨ��Ҷ���������������¶�����֮ɫ��\n");
        set("age",39);
        set("combat_exp", 3500000);
         set("attitude", "friendly");
        
        set("max_atman", 700);
        set("atman", 700);
        set("max_mana", 1250);
        set("mana", 1250);
        set("max_force",1200);
        set("force",1200);
        set("force_factor",90); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("no_fly",1);
        
        set("resistance/gin",15);
        set("resistance/kee",25);
        set("resistance/sen",20);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("nun",200,160,0,"/obj/weapon/","magician","necromancy");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}      
