 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����");
        set("long", @LONG
�����һ���ǳ�����������Ʈ�����㡣����һ�ŷ��������Ϸ��������ռ�
�õĺɰ������������ʵĶ�����ݫ�������ˮ��Ļ�����
LONG
        );
        set("exits", ([ 
        "east": __DIR__"cabin4",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
