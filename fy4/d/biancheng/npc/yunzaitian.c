#include <ansi.h>
inherit "/d/taiping/npc/smart_npc"; 
int show_me(); 
void create()
{
    set_name("������",({"yun zaitian","yun"}));
    set("title","���зɺ�");
    set("long","һ�������ѩ��������ͱȻ�����СЩ����Ҳ����ʮ�����ң�ԲԲ���������΢�룬
��Цʱ�����˾��úܿ��ס�\n");
        set("gender","����");
        set("age",42);
                
        set("int",22);
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
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
        set("inquiry", ([
                "������" :      (: show_me :),
                "���Ⱥ" :       (: show_me :),
                "��"   :       (: show_me :),
                "������" :       (: show_me :),
        ]));
        
        set("death_msg",CYN"\n$N˵������һ���Ҳ����İ��� \n"NOR);             
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
           set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                name()+"���������·������ϰ�֮�������λӢ�۽�ҹ��ȥС�á���\n"
        }) );                   
        
        CHAR_D->setup_char(this_object());
        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
    
}  
int show_me(){
        object me,ob;
        
        me=this_player();
        ob=this_object();       
        
        if (!me->query("wanma/��")){
                message_vision(CYN"$N����$n����������Ŀ���ƺ�Ҫ��$n������\n",ob,me);
                command("say ������Ҫ��Ŀ��ˣ���������Ȼ���뵽��");
                command("say �����ò���Ŀ��ˣ�����Ҳ�Ƕ��ࡣ");
                return 1;
        }
        
        message_vision(CYN"$Nһ����˵�����ϳ������ϰ���ӭ���������ݡ�\n"NOR,ob);
        me->set("wanma/ӭ��",1);
        return 1;
}    
