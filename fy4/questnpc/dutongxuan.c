#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER; 
void create()
{
        set_name("��ͩ��", ({ "du tongxuan", "du" }) );
        set("gender", "����" );
        set("nickname",BLU"����ѧʿ"NOR); 
        set("age", 47);
        set("int", 25);
        set("per", 20);
        set("str", 40);
        set("dur", 35);
        set("cor", 35);
        set("fle",20);
        set("long",
"���˺ܸߣ����ݣ�������������̬�ȼ�˹�ģ�����䲻��
������ȴ�Ѱ߰ף�һ���������������ϣ��·��������
���ݣ�ȴ�ִ����߷����ϣ����˾����Ҷ�����˿�����ӡ�\n");
        set("force_factor", 35);
        set("max_gin", 1900);
        set("max_kee", 3200);
        set("max_sen", 1800);
                set("max_force",2000);
                set("force",2000); 
        set("combat_exp", 1300000);
        set("score", 12000);
        set_skill("unarmed", 180);
        set_skill("force", 80);
        set_skill("parry", 160);
        set_skill("literate", 130);
        set_skill("dodge", 150); 
        set_skill("changquan", 130);
                
        map_skill("unarmed", "changquan");
     
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.changquan":),
        }) );
        setup();
        carry_object(__DIR__"obj/bluecloth")->wear();
        carry_object(__DIR__"obj/baiyubi");
        carry_object(__DIR__"obj/yubanzhi");
//      add_money("gold",15);
//        carry_object(__DIR__"obj/feiyunspear")->wield();
}
/*
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
*/

// add empty implementation to avoid compiling time error.
int do_flee()
{
    return 0;
}
