#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("���ӹ�ĸ", ({ "guimu","���ӹ�ĸ","��ĸ","ghost" }) );
        set("long","�����Ŀ�Ĺ�ĸվ���ھŸ���״���죬��Ŀ�����Ĺ���֮�䡣\n");
        set("gender", "Ů��" );
        set("age",2200);
        set("no_arrest",1);
        set("int",22);
        set("cor",30);
        set("per",1);
        set("cps",20); 
        set("combat_exp",9500000);  
        set("attitude", "friendly");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             
        }) );
        set("chat_chance",1);
        set("chat_msg",({ 
        }) );
        setup();    
        carry_object(__DIR__"obj/ghostcloth")->wear();
} 
int is_ghost() { return 1; }        
