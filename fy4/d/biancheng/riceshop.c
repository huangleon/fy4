 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "С����");
        set("long", @LONG
��Ȼ���Ǳ�Զ��һ��С�򣬿��ǵ��аټ�ʮ���˼ң���ª�Ŀ�ջ��С����Ҳ��
�ü��ң���������׼����Щ��������ҹ��·������ʳ��֮���������Ĺ��ߣ�������
���������Ҳ�ֲ�����Ψ������Ĳ��������·�������֡�
LONG
        );
        set("exits", ([ 
        "south": __DIR__"road4",
        ]));
        set("objects", ([
                __DIR__"npc/bossding":  1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
