 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "������");
        set("long", @LONG
���������������£��޴��ɽӰ�����ص�ѹ�ڹ����ĳ����ϡ����ں��ţ�ȴҲ
����������ɭ���Ե�����ɽ´��Ӱ�У��м�����������ЪϢ��������һ�������
�����ͨ��߳ǡ�������ͨ�������嶥��ɽ·����᫶��������ϡ�
LONG
        );
        set("exits", ([ 
                "southeast" : __DIR__"kunlun3",
                "northup" : __DIR__"road0",
                "west":         AREA_ZANGBEI"wild1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
