#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
void do_fight();
void create()
{
        set_name("����", ({ "gong jiu", "gong" }) );
        set("gender", "����" );
    set("age", 27);
        set("int", 70);
        set("per", 38);
        set("str", 80);
        set("dur", 35);
        set("cor", 110);
        set("agi",100);
    create_family("̫ƽ����",7, "����");
        set("long",
"�����ǹ��ţ��Ǹ��ɶ��ߵ�Һ��������ģ������еı�ѩ����ɽ�ϵ���ʯ��ʨ�ӵ����ͣ�����
�ĺ��������յ����ͣ��˵Ĵ������ټ���һ������ʮ�˲�ز��µĹ�깹�ɵĹ��š�\n"
                );
        set("force_factor", 100);
        set("max_gin", 1300);
        set("max_kee", 1800);
        set("max_sen", 1200);
                set("max_force",4000);
                set("force",4000); 
        set("combat_exp", 70000000);
        set("score", -3000);
        set_skill("unarmed", 270);
        set_skill("sword", 270);
        set_skill("force", 200);
        set_skill("parry", 270);
        set_skill("literate", 300);
        set_skill("dodge", 270);
        
                set("chat_chance",10);
                set("chat_msg",({
                        "���ŵ�����Ŀ�������������ϣ���Ȼ�����Ҿ��ǹ��ţ���һ�޶��Ĺ��š���\n",
                })      );
//         set("chat_chance_combat",100);
//              set("chat_msg_combat",({
//                      (:do_fight:),
//              })      );
        
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
//        carry_object(__DIR__"obj/diewusword")->wield();
        add_money("tenthousand-cash",1);
} 
object offensive_target(object me)
{
        int sz;
        object *enemy; 
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0; 
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4; 
        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
} 
void crazy(int i,int exp);
void init()
{       
        add_action("do_show","show");
} 
void begin_crazy(); 
void remove_crazied()
{
        set("crazied",0);
} 
int do_show(string arg)
{       
        object whip; 
        if(!arg) 
        {
                write("��������˿�ʲô������\n");
                return 1;
        }
        if( !whip=present(arg,this_player()))
   {       
                write("������û����������ѽ��\n");
                return 1;
        }
        if (whip->query("skill_type")!="whip"||query("crazied")||(string)(NATURE_D->outdoor_room_description()) != "    " +
"ҹĻ�ʹ������췱�ǣ�����һƬ���ҡ�
")
        {
                message_vision("$N�ó����е�"+whip->name()+"��$n������$nʲô��Ӧ��û�С�����\n",this_player(),this_object());
                return 1;
        }
        message_vision("$N�ó�����"+whip->name()+"��$n��ǰ���˻�\n",this_player(),this_object());
        begin_crazy();
        set("crazied",1);
        call_out("remove_crazied",900);
        return 1;
} 
void begin_crazy()
{
        object weapon;
        object me,ob;
        int exp; 
        ob=this_object();
        me=this_player();
        
//      weapon=me->query_temp("weapon");
//      if(!this_object()->query_temp("crazy") )
//      if (weapon->query("skill_type")=="whip") 
        {
                message_vision("������ɫ��Ȼ��䣬�����𽥱�죬���ڵ���˺�з���������\n",this_object());
                exp=this_object()->query("combat_exp");
                this_object()->start_busy(100);
                this_object()->set("combat_exp",1);
                call_out("crazy",4+random(1),0,exp);
                return;
        }
}  
void crazy(int i,int exp)
{       
        object ob,me,weapon;
   
        ob=this_object();
        me=this_player();
        weapon=me->query_temp("weapon"); 
        if(ob)
        if (!weapon||weapon->query("skill_type")!="whip"||i>12)
        {
                message_vision("$N���ָֻ����侲�����������$n���������Ǻ������Եģ���ֻ����·һ������\n",ob,this_player());
                ob->stop_busy();
                ob->set("combat_exp",exp);
//              ob->set("kee",ob->query("max_kee"));
                ob->delete_temp("crazy");
                return;
        }
        else
        {       
                if(!random(2))
                        message_vision("���ŵ���Ϣ������һͷ��������ʮ�����ţ���Ѿ�����˺���Լ����·�������������е��������ң����ҡ���\n",ob);
                ob->receive_damage("kee",100);
                call_out("crazy",1+random(1),i+1,exp);
        }
}   
