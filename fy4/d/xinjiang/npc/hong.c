 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����ѩ", ({ "hongxue", "fu hongxue", "fu hong xue" }) );
        set("gender", "����" );
        set("age", 24);
        set("cps", 30);
        set("int", 30);
        
        set("attitude","friendly");
        set("max_force", 1000);
        set("force", 1000);
        set("cor",100);
        set("force_factor", 60);
        
        set("reward_npc", 1);
        set("difficulty", 5);
        
        set("long","����ѩ���������ŵ���һ����״�����صĵ���������ڣ�������ڡ�
����������ʲô��ʱ��û�зŹ��������\n"); 
        set("combat_exp",4000000);
        set("score", 1000);
        set("no_busy",4);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ѩ���ڳԷ�����һ�ڷ�����һ�ڲˣ��Եú�����\n",
                "����ѩ��ڵĵ�����ڵ��·�����ڵ����ӣ��ڵ÷�����\n",
        }) );
        
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("blade", 300);
        set_skill("shortsong-blade",160);
        set_skill("fengyu-piaoxiang",200);
        set_skill("meihua-shou",200);
        set_skill("unarmed",200);
        
        map_skill("unarmed","meihua-shou");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","shortsong-blade");
        map_skill("blade","shortsong-blade");
        map_skill("move","fengyu-piaoxiang");
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
        if (!random(10)) carry_object(__DIR__"obj/fbblade")->wield();
                else carry_object(__DIR__"obj/bblade")->wield();
}      
