 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "С��");
        set("long", @LONG
С�ﲻ���խ���η��ʱ���ɰ���죬�����ʱ����Ţ��·���������ᶼ��ƶ��
�˼ң����ű����С���������������������޴����ˣ����Ѽè������ʺ�������У�
�Ҽһ������ſڶ�ɹ��С���·����򲼡�
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"smallroad1",
        "south" : __DIR__"smallroad3",
        "west"  : __DIR__"cabin2",
        ]));
        set("objects", ([
                __DIR__"npc/huwaigua":  1,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
