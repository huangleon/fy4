 // waiter.c
inherit NPC;
inherit F_VENDOR;
inherit F_FLOWERSELLER;
#include <ansi.h>
void create()
{
        set_name("花姑", ({ "huagu" }) );
        set("gender", "女性" );
        set("age", 31);
        set("title", HIM "赛牡丹"NOR);
        set("long",
                "这位老板正对你露出慈祥的笑容。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ([
                AREA_FY"npc/obj/purple_flower":30,
                AREA_FY"npc/obj/red_flower":25,
                AREA_FY"npc/obj/yellow_flower":33,
                AREA_FY"npc/obj/blue_flower":44,
                AREA_FY"npc/obj/white_flower":14,
                AREA_FY"npc/obj/black_flower":10,
        ]) );
        set_skill("unarmed",5);
        set_skill("dodge",5);
        setup();
        carry_object("/obj/armor/cloth")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
        add_action("assign_delivery","delivery");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
message_vision("$N笑着说道：刚采下来的花儿呦，买吧。\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N笑咪咪地说道：这位"+RANK_D->query_respect(ob)+
"要买什么花儿？\n",this_object(),ob);
                        break;
        }
} 
void reset()
{
        set("vendor_goods", ([
                AREA_FY"npc/obj/purple_flower":30,
                AREA_FY"npc/obj/red_flower":25,
                AREA_FY"npc/obj/yellow_flower":33,
                AREA_FY"npc/obj/blue_flower":44,
                AREA_FY"npc/obj/white_flower":14,
                AREA_FY"npc/obj/black_flower":10,
        ]) );
}   
