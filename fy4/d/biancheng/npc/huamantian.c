#include <ansi.h>
inherit "/d/taiping/npc/smart_npc"; 
int show_me(); 
void create()
{
    set_name("������",({"hua mantian","hua"}));
    set("title","������");
    set("long","���������Ѿ�վ�˺ܾ��ˣ�ѩ�׵��·��ϻ���ɳ����ͷ��Ҳ�ѱ�Ⱦ�ƣ�����������
ȴ�ǲ԰׵ģ��԰׵�ȫ��һ˿Ѫɫ��\n");
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
                "�����컹վ����ҹͬ���ĵط������������ƶ�û�иı����\n"
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
        
        if (me->get_id()=="yekai" || me->get_id()=="fu hongxue") {
                command("puke");
                command("say ����Ϊ����������ߴ������ģ�");
                return 1;
        }
        
        if (me->query("wanma/����")<5) {
                command("hmm");
                command("say �Һ���û��˵���㣬���ϰ�����ˣ�����������ͷ���������");
                command("say �㻹�����뷨�������������������Ұɡ�");
                tell_object(me,WHT"��������������Ҫ����������������ڱ߳ǵ�����Ϊ"+chinese_number(me->query("wanma/����"))+"�㡣\n"NOR);
                return 1;
        }
        
        message_vision(CYN"$N��$nһ���֣����������´������������ֿڣ��������г���ӭ����\n"NOR,ob,me);
        me->set("wanma/��",1);
        return 1;
}
