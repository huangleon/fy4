 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "ɽ���");
        set("long", @LONG
����ʯ������·תΪƽ̹����˵�������ɷ�Ƽ��ġ����˹ȡ�ԭ�����Ǹ�����
ͨͨ��ɽ��ģ����һ�������ݣ�һƬƬ��ƺ�����������ҫ�£��Ե���ô������ƽ
�͡�·���и���̯��һ������������ϸ������������£������к��Ź������ˡ�
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"road5",
        "east" : __DIR__"vroad1",
        "northeast" : __DIR__"groad1",
        ]));
        set("objects", ([
                __DIR__"npc/teawoman": 1,
                
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
