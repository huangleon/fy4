#include <ansi.h>
#include <command.h>
inherit "/d/taiping/npc/smart_npc"; 
void create()
{ 
        set_name("������",({"long wang","wang"}));
        set("title","����һ��");
        set("long", "������������������ϺƬ���ŵķ��ţ�����һ�����Ĩ���졣��ϲ���������Ϻ��
�����������ݺ��ߺ�ʱ���ɵ�ϰ�ߣ�����ʳ�������������������档��\n");
        set("age",40);
        set("combat_exp", 4000000);
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",100);
        set("reward_npc", 1);
        set("difficulty", 3); 
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("chat_chance", 1);
        set("chat_msg", ({
           "�����������ȥ������Ů�����������������Ц�ˡ�\n",
                "��������������ļ�˵����Ů�˵ĺ������������������������������ӣ��������˵ġ���\n",
        }) ); 
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );
                
        auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","shenji-blade",2);
        setup();
        carry_object(__DIR__"obj/7blade")->wield();
}  
void init()
{
    ::init();   
    add_action("do_look", "look");
}  
int do_look(string arg)
{
    object me,girl;
    me = this_player();
    
    if (girl=present("naked girl",environment(this_object())))
    if( arg == "naked girl" || arg == "girl" )
    {
        message_vision(CYN"$N��������ļ��˵����ô������ɫ�ɲͣ�ʮ���ƽ�������ô�����ô�档\n\n"NOR, this_object());
        return 0;
    }
    else return 0;
} 
int accept_object(object who, object ob)
{
        if( ob->value() >= 100000) {
                        command("spank "+this_player()->get_id());
                        who->set_temp("taiping/longwang_kill",1) ;
                        command("say �ã��������ӻ�����ζ���������͡�\n");
                        return 1;
                } else {
                        command("shake");
                        return 0;
                }
        return 0;
}     
