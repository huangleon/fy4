 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "СԺ");
        set("long", @LONG
�߽������ţ����Ǵ�Ũ����롣СԺ��������������ż�ʮ�ʹ��񣬳��Ž���
������ÿ�����һ�Ե�����С�ƻ����Ե����Ŷ������ϡ�������������ľ�������
�������̲ݡ�����������Ǯ�ͷ紵����������
LONG
        );
        set("exits", ([ 
        "north": __DIR__"xiaojinku",
        "enter": __DIR__"xiaojinku3",
        ]));
        set("objects", ([
                __DIR__"npc/girl":      1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}    
