 // bandit.c
inherit NPC; 
void create()
{
        set_name("����", ({ "bandit" }) );
        set("gender", "����");
        set("age", 33);
        set("long",
                "��һ��������⣬һ�������ɷ��ģ��������������η��\n");
        set("combat_exp", 600);
        set("score", 60);
        set("attitude", "aggressive");
        set_skill("sword", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
        carry_object(__DIR__"obj/short_sword")->wield();
        add_money("coin", 3);
}
