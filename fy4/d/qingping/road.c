 inherit ROOM;
void create()
{
        set("short", "青石路");
        set("long", @LONG
一条长而窄的青石路，路的尽头便是赫赫有名的清平山庄，路上行人
不多，来往的多半是武林豪杰，因为清平剑客白三空正是中原武林的第一
剑手，一手清平剑法早已无敌天下，所以慕名而来者甚多。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"gate",
  "southwest" : AREA_JINAN"road2",
  "north" : AREA_JINAN"road3",
])); 
        set("outdoors","qingping");
        set("coor/x",100);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
        
        replace_program(ROOM);
}       
