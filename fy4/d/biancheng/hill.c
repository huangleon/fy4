 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "ɽ��");
        set("long", @LONG
ɽ��һƬ���̣����������ߣ�Ҳ��̫Զ���¶���һ����أ���ͷ������һ���
�߸ߵ���ʯ�������ϲ�ɫ�Ѳԣ����ð�������վ�������ɽ��ǰһƬ���ԭ��
�����ű��졣�紵���ݣ����纣���еĲ��ˡ�
LONG
        );
        set("exits", ([ 
                "southdown" : __DIR__"grassland6",
        ]));
        set("objects", ([
                __DIR__"obj/tomb" : 1,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        set("discussion_shen",1);
        setup();
        replace_program(ROOM);
}       
