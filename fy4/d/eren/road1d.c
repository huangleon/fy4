 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��·");
        set("long", @LONG
��·�������������������ݵ���һ���������۹�����·���Ե���ľ������
�˾��Ļ���ɽɫ��䣬����ɫ��ɽ���ϣ�һ�������ɫ���ݶ���̫�������Ź⡣
ǰ����ש���ߣ���һ��ׯ԰����Զ���˰���������Ԭ�ҵİ���ׯ��
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"road1c",
                "west": __DIR__"road1e",
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
