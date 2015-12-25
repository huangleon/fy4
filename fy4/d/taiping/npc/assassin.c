#include <ansi.h>
#include <command.h> 
inherit "/d/taiping/npc/smart_npc";  
void create()
{ 
        set_name("�������̵�������",({"middle age man","man"}));
        set("long", "�������̵������ˣ��ֳ�һ�Ѷ̽���\n");
        set("age",37);
        set("combat_exp", 5000000);
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",100);
        
        set("pursuer", 1);
        set("parrot_killer",1);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        set("death_msg",CYN"\n$N˵�����ˣ��ܵ������ٶ���ʲô�á��� \n"NOR); 
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n������˵������ʲô�¶����ܣ�ֻ��ɱ�ˣ�����\n",
        ]) ); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_smart_fight(50) :),    
        }) );
        
        CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","sharen-sword",1);
        set_skill("move",1000);
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(AREA_FY"npc/obj/killersword")->wield();
}    
 
void die() {
        
        object me, ob, owner;
        ob=this_object();
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        
        if (me)
        if(me->query("parrot/��ү�̿�")) {
                me->set("parrot/��ү�̿�",1);
        }
        ::die();
}   
