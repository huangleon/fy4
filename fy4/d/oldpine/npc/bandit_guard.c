 // bandit_guard.c
inherit NPC; 
void create()
{
        set_name("土匪喽罗", ({ "bandit" }) );
        set("gender", "男性");
        set("age", 33);
        set("long","这家伙满脸横肉，一付凶神恶煞的模样，令人望而生畏。\n");
        set("combat_exp", 3600);
        set("pursuer", 1);
        set("score", 260);
        set("bellicosity", 600);
        set("attitude", "aggressive");
        set_skill("sword", 50);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        setup();
        carry_object(__DIR__"obj/short_sword")->wield();
        carry_object("/obj/armor/cloth")->wear();
        add_money("coin", 5);
}  
int heal_up()
{
        if(environment() && !is_fighting() && !is_busy()
                && query("startroom") 
                && file_name(environment()) != query("startroom")) {
//              command("say ok");
                return_home(query("startroom"));
                return 1;
        }
        return ::heal_up() + 1;
} 
