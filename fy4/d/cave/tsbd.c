 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "天西北道");
        set("long", @LONG
紧靠洞边，洞壁笔直，根本无法攀爬。一个个火把忽明
忽暗。洞壁上有很多的裂缝，不是地渗出一滴滴的水珠，把
整条路弄得湿湿的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"twt",
  "west" : __DIR__"sbm",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
        set("coor/x",-50);
        set("coor/y",-0);
        set("coor/z",-20);
        setup();
} 
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "east" && !obj->query("vendetta/authority")){
                if (present("killer e", this_object()))
                {
                        another = present("killer e", this_object());
                        return notify_fail(another->name()+"闪身挡住了你的路。\n");
                } else if (random(10)>6) {
                        another = new(__DIR__"npc/killer_e");
                        another->move(environment(obj));
                   message_vision(HIB"路边黑影一闪!\n"NOR, obj);   
                        return notify_fail(another->name()+"喝道，什么人敢私闯青龙会，拿命来！\n");
                }
        }       
        return 1;
}       
