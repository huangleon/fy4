 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("谢长卿", ({ "xie changqing" }) );
        set("gender", "男性");
        set("age", 25);
        set("long",
"一个年轻而英俊的少年，他甚至在颤抖着，英俊的面庞上，也蒙着一层
死灰之色。。\n"
);
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "谢长卿喃喃道：“我还年轻，我不能就这样无声无息地死去，
而且这谷中再无他人，即使我作了昧心之事，又有谁会传将出去，唉！我想人
人都该为自己打算吧。”
。”\n",
        }) );
          
        set("attitude", "friendly");
        set("title",HIG"点苍"NOR);
        set("nickname", HIG"落英剑"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",20);
        set("class","tiexue");
        
        set("combat_exp", 2500000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",50);
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 40);
        set("atman", 500);
        set("max_atman", 500);
        set("mana", 500);
        set("max_mana", 500);
        
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("qidaoforce", 150);
        set_skill("fall-steps",150);
        set_skill("meihua-shou",150);
        set_skill("diesword",140);
        
        map_skill("unarmed","meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        map_skill("parry","diesword");
        map_skill("sword","diesword");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
        
