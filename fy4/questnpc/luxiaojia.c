 inherit QUESTNPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("·С��", ({ "lu xiaojia", "lu" }) );
        set("gender", "����" );
    set("age", 25);
    set("title", "���п�" );
    set("nickname", HIR"���⽭��"NOR );
        set("int", 35);
        set("per", 30);
        set("long",
                "���Ǹ������ˣ�һ����ֵ������ˣ�����˫��ֵ��۾�������Ц��ʱ����˫�۾���
������ģ����������˵��۾���û����У�Ҳû�б��顣
\n"
                );
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_force", 4000);
        set("force", 4000);
        set("force_factor", 100);
        set("cor",80);
        set("str",50);
        set("combat_exp", 8000000);
        set("score", 3000);
        set_skill("sword", 150);
        set_skill("force", 70);
        set_skill("parry", 180);
        set_skill("literate", 90);
        set_skill("dodge", 280);
        set("agi",25);
        set("int",30);
           set("chat_chance",10);
                set("chat_msg",({
"·С������һ�Ż���������������Ȼ������Ż����䵽�Լ���������۾���
������̾�˿�������ʼ�����׽���\n",
"·С�Ѻ�ȻЦЦ ��˵������ɱ���Ǽ��ɾ�ʹ������顣��������һ�٣���˵����
��������ɱ��֮ǰ����һ��Ҫϴ���衣��\n",
                })      );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sharenruma" :),
        }) );
        set_skill("sharen-sword", 120);
        map_skill("sword", "sharen-sword");
        map_skill("parry","suiyuan-sword");
        setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/lusword")->wield();
}   
// add empty implementation to avoid compiling time error.
int do_flee()
{
    return 0;
}
