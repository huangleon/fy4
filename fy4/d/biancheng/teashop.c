 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "һƷ��");
        set("long", @LONG
һƷ���Ǹ��ܴ�Ĳ�ݣ������ͨ�����и�ʽ�������ˣ�Խ��Ĳ������Խ�ࡣ
�������ǲ���������е�ʱ������Ŀ���ȴ���ܶ࣬��������ģ�һ���������ģ�
һ�����У�һ�����ӣ�һ����������ͷ������һ���Ƿ������ϴ��˯�Ĵ����ӡ�
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"nstreet2",
        ]));
        set("objects", ([
                
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
