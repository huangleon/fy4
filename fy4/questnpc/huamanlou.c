#include <ansi.h>
inherit QUESTNPC;
void create()
{
        set_name("����¥", ({ "hua manlou","hua" }) );
        set("gender", "����");
        set("age", 32);
    set("nickname",WHT"�ʻ���¥"NOR);
    set("title","��������");
        set("long",
"�ʻ���¥������¥���ʻ���������ǿ�ҵ��Ȱ����������Ȱ����е�����һ����
\n"
               );  
        set("attitude", "peaceful");
        set("combat_exp", 8000000);
        set("chat_chance", 10);
        set("chat_msg", ({
              "����¥˵������ֻҪ���ȥ���ԣ��ͻᷢ���������Ƕ�ô��
����ÿ�������ﶼ�кܶ����������������з��յ��������¡���\n",
"����¥�������кܳ����˯�ߣ��кܺõ�θ�ڣ������
����������ӣ���һ�������ܺõĹ��٣���Щ�����㹻����
���һ��и��ܺõ����ѡ���\n",
        }) );
                set("chat_chance_combat",40);
//              set("chat_msg_combat", ({
//                      (:perform_action,"unarmed.xinyoulingxi":)
//              })      );
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 10);
                set("max_gin",1500);
                set("max_sen",1200);
                set("fle",30);
                set("int",41);
                set("cor",40);
        set_skill("force", 80);
        set_skill("unarmed", 120);
        set_skill("dodge", 220);
                set_skill("parry",220);
                set_skill("lingxi-zhi",120);
   set_skill("move", 120);
        map_skill("unarmed","lingxi-zhi");
        setup();
    carry_object("/obj/armor/cloth")->wear();
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int myexp,hisexp;
        myexp=me->query("combat_exp");
        hisexp=victim->query("combat_exp"); 
        if (random(myexp+hisexp)>hisexp&&(!random(2)))
        {
                victim->start_busy(10+random(10));
                victim->remove_all_killer();
        return HIR "$nֻ����һ�飬ҪѨ���ƣ�һ�������ܶ��ˡ�\n" NOR;
        }
}    

// add empty implementation to avoid compiling time error.
int do_flee()
{
    return 0;
}
