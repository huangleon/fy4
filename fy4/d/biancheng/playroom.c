 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���Ǹ�");
        set("long", @LONG
ʮ��ǰ���ϳ��˸����ˣ��뾩ǰ��������˸�������ү����������˻�û����
���ϣ��ͱ�ǿ�������Դ����Ӵ���û�˹�ˡ��Դ����������������ͳ�������
�����ǺȾ�ȡ�֣�����ˤ�ӱ���ĳ�����
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"nstreet3",
        ]));
        set("objects", ([
                
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
