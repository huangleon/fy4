 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���ɽ");
        set("long", @LONG
�����ж��ɽ����˼���������ɽ��ɽ��ƽ����������ããԭʼɭ�֣��＾��
�־�Ⱦ����ɽ��飬���������������⡣����ɽ��Զ�������ϵĺ���ɽ����ɽ�彻
�����������ֳ�����ĵ����ȣ����ܵ��ﴫ˵�е���ɽ�������ɹ���ѩ�塣����
ɽ���³����ӵĶ԰����Ǳ߳ǡ�
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"zhihuo",
                "southwest":  __DIR__"valley1",
                "eastdown":             __DIR__"hellvalley1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}   
