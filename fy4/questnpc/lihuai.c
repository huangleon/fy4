#include <ansi.h>
inherit QUESTNPC; 
void create()
{
        set_name("�", ({ "li huai", "li" }) );
        set("long",
                "����������糾���������ڣ�����ȥʮ�����ǣ�������ȥȴ����˵���������š�
\n");
    set("attitude", "heroism");
        create_family("����һ��",4,"�˽�");
    set("str", 40);
    set("cor", 70);
    set("cps", 12);
        set("agi",32);
        set("int",20);
        set("per",31);
        set("con",25);
        set("dur",20);
        set("fle",25);
        set("tol",30);
        set("chat_chance",10);
        set("chat_msg", ({
"�ʱ��Ŀ����ͣ�ʱ����Ц������Ϊʲô��Ϊʲô���ң�Ϊʲô�ǿɿɣ�
ֻ��������������ֻ��ʤ������ܣ�Ϊʲô���ѵ�����Ϊ����С��ɵ��ĺ��ˣ���\n"
                                })  ); 
        set("chat_chance_combat", 97);
        set("chat_msg_combat", ({
                (: perform_action, "throwing.xiaoli-feidao" :),
        }) );
        set("combat_exp", 6000000);
                set("max_gin",800);
                set("max_kee",1500);
                set("max_sen",1000);
        set_skill("throwing", 280);
                set_skill("feidao",220);
                set_skill("force",70);
        set_skill("dodge", 280);
                set_skill("move",180);
                set_skill("parry",260);
        map_skill("throwing","feidao"); 
   setup(); 
        carry_object("/d/fugui/npc/obj/cloth")->wear();
                carry_object(__DIR__"obj/leaf")->wield();
} 
int accept_object(object me,object obj)
{
        if(obj->query("keke"))
        {
                message_vision("$N����һ��ս�飬˫Ŀ��죬���һ���Ц������������ƴ���಻ֹ��\n",this_object());
                obj->destruct();
                call_out("obj_drunk",10+random(10),this_object(),0);
                return 1;
        }
        return 0;
} 
void do_drunk(object obj);
void obj_drunk(object obj,int i)
{       
        
        message_vision("$N����ƴ���������ƴ�������й�ơ�\n",obj);
        i++;
        if (i<2) call_out("obj_drunk",10+random(10),obj,i);
        else do_drunk(obj);
} 
void do_drunk(object obj)
{       int busy_time;
        message_vision("$N���ˣ�$N��û�б��ˡ��ʵ���ʧ�⡢ʧ�ܣ�$Nֻ����������һ��$P�����ܽ�������⣬����$N���ˣ����׵����ˡ�",obj);
        busy_time=6+random(4);
        obj->start_busy(100);
        call_out("obj_revive",busy_time,obj);
} 
void obj_revive(object obj)
{
        if (objectp(obj))
        {
                message_vision("$N�������ѹ����ˡ�\n",obj);
                obj->stop_busy();
        } 
}   

// add empty implementation to avoid compiling time error.
int do_flee()
{
    return 0;
}
