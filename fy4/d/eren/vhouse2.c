 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���");
        set("long", @LONG
���ӵ����������Դ���Ϊ���ģ��ſ�һ����ˮ���Ｘ����������е�������ȥ��
�Աߵ�ˮͰ���Ǻ�ɫ����档��������ɹ��һ���ܴ�������������������λ�����
���ŵģ���һ��ɹ���˵ĺ������ͼ�����ͷ��
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"groad3b",
        ]));
        set("objects", ([
                __DIR__"npc/fishman":1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
