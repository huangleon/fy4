 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("����Ӣ", ({ "yan renying","yan" }) );
        set("gender", "����" );
        set("title", "������ ����" );
        set("nickname", HIC"��Ӣ����֮"NOR );
        set("long",
       "һ���۾�����Ѫ˿�������ˣ�ϸ���������ֽ��ս��������������ܵĲ���һ����˿��\n��������������ʱ������ʹ����������������������Ŷ��߳��ĺ���\n"
                );
        set("attitude", "peaceful");
        set("age", 25);
        set("cps", 40);
        set("int", 50);
        set("per", 40);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 300000);
        
        set("force", 500);
        set("max_force", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 20);
        set("inquiry",  ([
                "Ҷ�³�" : "��Ҳ����˵Ҷ�³Ƕ����������Ѱ�˹��������ǳ���һ����\nѪ�յĲ����⣬��ʲôҲû���ˡ���\n",
                "master ye" : "��Ҳ����˵Ҷ�³Ƕ����������Ѱ�˹��������ǳ���һ����\nѪ�յĲ����⣬��ʲôҲû���ˡ���\n",
                "���Ŵ�ѩ" : "���š������������İ���ʦ�ã�ɱ��ʦ�ܣ�������ɱ����ʦ������Ѫ�����\n�Ҿ���ƴ����ҲҪ����\n",
                "master ximen" : "���š������������İ���ʦ�ã�ɱ��ʦ�ܣ�������ɱ����ʦ������Ѫ�����\n�Ҿ���ƴ����ҲҪ����\n",
        ])                      );
       set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        set("chat_chance", 5);
        set("chat_msg", ({
                "����Ӣ��������Ϻ����Ƶ���Ҷ�³ǵ��ϳ�����Ī���������Ŵ�ѩ���ӻ�ȥ�ˣ�\n",
                "����Ӣ�ս�ȭͷ����Ҷ�³ǡ���Ҷ�³ǣ��������ֻ���ҵ���ſ����ҵ����������֡����� \n",
                }) ); 
        set_skill("sword", 200);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
                
        setup(); 
        carry_object("/obj/weapon/sword")->wield();
        add_money("gold",5);
        carry_object("/obj/armor/cloth")->wear();
}      
