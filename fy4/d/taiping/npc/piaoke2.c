 inherit "/d/taiping/npc/smart_npc";
void create()
{
        set_name("�Ϲ���", ({ "piaoke", "ke"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "��λ�ɸ����ݵ��οͣ��ǡ���ͷ��İ����Ϲ��ס�\n");
        
        set("combat_exp", 4000000);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        
        }) );
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
        
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                 (: auto_smart_fight(20) :),
        }) );
        
        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","xuanyuan-axe",2);
        
        setup();
        carry_object(__DIR__"obj/axe")->wield();
        
} 
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        message_vision("�Ϲ������˸�����������ү���ȥ�ˡ���˵�������˴���\n",this_object());
        destruct(this_object());
}    
