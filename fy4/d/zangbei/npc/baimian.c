#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";  
void create()
{
        set_name("��������",({"baimian langzhong","baimian","langzhong"}));
        set("title",YEL"����կ �϶�"NOR);
        set("long","
��������������կ�Ķ����ҡ������������ܰף�Ҳ��û�������У�����������
�ú���û��һ����������ţ��ǻ���ʲô���ֺú��������������ѽ��Լ�����
�������ˡ�\n");
        
        set("gender","����");
        set("group","longhuzhai");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("death_msg",CYN"\n$N˵�������߲��������߲��ư�����\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: auto_smart_fight(100) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "�������е���������������˱����Ͳ�ϲ����ܵġ���\n",
        }) );                   
        
        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","fy-sword",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/gsword")->wield();    
    
}  
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") )) {    
                if(owner=me->query("possessed")) me = owner;
                if(me->query("wanma/׼��ɱɽ��"))
                        me->set_temp("wanma/��������",1);
        }
        ::die();
}      
