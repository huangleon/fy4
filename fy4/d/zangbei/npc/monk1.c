#include <ansi.h>
inherit "/d/taiping/npc/smart_npc"; 
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("long", "����ֱ���´�ɨ��Ժ�����\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 1500000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",30);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "�����������������飬���²������ӵ�����ȥι�㡣\n",  
        }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
          
        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        set_name("����µ�����",({"chonggu lama","lama"}));
        set("force_factor",40);
        setup();
        carry_object(__DIR__"obj/lamacloth")->wear();
        
}
