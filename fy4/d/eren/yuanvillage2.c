 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����ɽׯ����");
        set("long", @LONG
���������Ŵ��ĵ�̺��ǽ�ϵ���һʮ��֧ͨ���ţ�;��򡣴����ľ�ͷ������
�źܴ�ġ�ϲ���֣���ɫ���֣��ʺ�ĳ񡣺��Ǽ���ģ�������ϲ����
LONG       );
        set("exits", ([ 
                "south" : __DIR__"yuanvillage",
                "east": __DIR__"yuanvillage3",
        ]));
        set("objects", ([
                __DIR__"npc/yuanqiuyun": 1,
                __DIR__"npc/liudonglai": 1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
