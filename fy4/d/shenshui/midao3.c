 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山洞秘道");
        set("long", @LONG
转了几个弯，入洞已深，面前伸手不见五指，周围不时传来小动物掠
过的沙沙声，令人生畏。你想回头却已不知来时的道路。在这里你也分不
清东西南北，只好揣测着方向，壮着胆子摸索着往前走。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"midao2",
  "north" : __DIR__"midao7",
]));
        set("coor/x",100);
        set("coor/y",12070);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
