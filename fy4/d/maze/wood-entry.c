 // silencer@fy4 workgroup 五行阵之木阵
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "木阵");
        set("long", @LONG
木阵是一片树林，看上去只有数里方圆，却很茂密，沉寂无声，神秘莫测。日
光偶尔穿透树巅，沿树身照下来，忽而照出一块绿草茵茵的林中空地，忽而照出半
截埋在土里的巨大枯木，日光过后，一切又堕入沉寂而神秘的黑暗之中。 
LONG
        ); 
        set("outdoors", "shaolin"); 
        set("exits", ([ 
                "west" : __DIR__"wood-maze/entry",
        ])); 
        setup(); 
} 
//      这儿演示 refresh maze 
void    init(){
        add_action("flush_maze","flush");
}  
int     flush_maze(){
        object maze_room;
        string flush_msg;
        maze_room=find_object(__DIR__"wood-maze");
        if (!maze_room) return 1;
        flush_msg=HIG"忽然间一阵怪风吹过，周围的树枝似有灵性般舞动起来。。。。
一阵天摇地转，你发现自己又回到了林子的进口。\n"NOR,
        maze_room->remove_all_players(maze_room,this_object(),flush_msg);
        maze_room->refresh_maze();
        return 1;
}     
