 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("盛大娘", ({ "sheng daniang" }) );
        set("nickname",HIR "散花玄女" NOR);
        set("gender", "女性");
        set("age", 65);
        set("long",
"满头银发如丝的盛家庄女主人，昔年人称‘散花玄女’的盛大娘。\n"
);
        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "盛大娘说：我三个媳妇一个接着一个都死在大旗门人的手里，害得我这儿子十余年都不愿再娶亲了。\n",
        }) );
          
        set("attitude", "friendly");
        set("score", 2000);
        set("class", "huashan");
        set("reward_npc", 1);
        set("difficulty", 2); 
        
        set("combat_exp", 1500000);        
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("fle",50);
        set("pursuer", 1); 
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 40);
        set("atman", 300);
        set("max_atman", 300);
        set("mana", 300);
        set("max_mana", 300);
        
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "throwing.mantianhuayu" :),
                (: perform_action, "throwing.tanzhijinghun" :),
        }) ); 
          
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("throwing",150);            
        set_skill("hanmei-force", 100);
        set_skill("tanzhi-shentong",120);
        set_skill("anxiang-steps",140);
        set_skill("zhaixin-claw",120);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("force", "hanmei-force");
        map_skill("throwing","tanzhi-shentong");
        map_skill("dodge","anxiang-steps");
        map_skill("move","anxiang-steps");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(1));
        carry_object(__DIR__"obj/n_stone")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
   
