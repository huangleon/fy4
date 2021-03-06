 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("叶星士", ({ "ye xingshi", "ye"}) );
        set("nickname", CYN "医仙"NOR);
        set("vendetta_mark","shaolin");
        set("gender", "男性" );
        set("age", 44);
        set("per", 25);
        set("int",28);
        set("attitude","friendly");
        
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor",50); 
        set("long",
        "叶星士是少林铁扇大帅的唯—俗家弟子，也是江湖中久著盛誉的四大名医之—，\n医术精绝，天下公认，被举为“医仙”。\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
        name()+"捋捋长髯叹道：无怪叶孤城在此长居，的确是个仙境般的所在。\n",
        "叶星士沉吟半晌苦笑道：叶城主这次把我“请”到白云城，不知究竟为何？\n",
        "叶星士翻了翻手中『黄帝内经』，皱眉道：叶城主眉间微有青黑，难道中了毒？\n",
        }) );
        
    set("combat_exp", 400000);
        
        set_skill("move", 200);
        set_skill("dodge", 200);
        set_skill("force", 160);
        set_skill("unarmed",200);
    set_skill("changquan",200);
        set_skill("parry",200);
        
    map_skill("unarmed", "changquan");
        
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
}      
