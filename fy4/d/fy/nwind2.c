inherit ROOM;
void midnight_event();
void sunrise_event(); 
void create()
{
        set("short", "北风街");
        set("long", @LONG
这里是风云广场的北边，再往北眺望可以看到远处高耸的城墙。热闹的街道上
充溢着清新的花香和甜丝丝脂粉的香气。花香是从大街东侧的飘香花店荡漾出来的，
而浓厚的脂粉气息则是西首倾城胭脂店的招牌。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"nwind1",
                "north" : __DIR__"nwind3",
                "east" : __DIR__"pxhdian",
                "west" : __DIR__"qcyzdian",
        ]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",20);
        set("coor/z",0);
        setup();
        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
} 
void midnight_event() 
{
        object badguy;
        object room = this_object();
        int i, bandit_no = 2 + random(5);
        
        if(!random(10)) {
                for(i=0; i<bandit_no; i++) {
                        if(objectp(badguy = new("/obj/npc/bandit"))) {
                                badguy->setup_bandit("山西土匪", "/obj/armor/cloth", "/obj/weapon/blade_guitou", "fy");
                                badguy->move(room);
                                badguy->ccommand("chat 月黑杀人，风高放火！");
                        }
                }
                NATURE_D->add_day_event(3, 1, this_object(), (: sunrise_event :));
} else {
                NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
        }
} 
void sunrise_event() 
{
        object *ob_list;
        int i;
        
        ob_list = children("/obj/npc/bandit");
        for(i=0; i<sizeof(ob_list); i++) {
                if(ob_list[i]->query("area_mark") == "fy") {
                        if(environment(ob_list[i])) {
                                message_vision("$N叫道：天晓也，扯乎！\n",ob_list[i]);
                        }
                        destruct(ob_list[i]);
                }
        }
        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}
