 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����ɽׯƫ��");
        set("long", @LONG
ƫ�������һ�ٶ�ʮ�Ű�������ÿ�����Զ������˿��ˣ�ֻ�ǣ�ÿ�����˶�����
�������ŵ�����������ӡ��ƺ�������ʲô����֮�¡�������ͷ���ĸ��ˣ�����
������裬�ں��Աߵ�Ů������˽�
LONG       );
        set("exits", ([ 
                "west": __DIR__"yuanvillage2",
        ]));
        set("objects", ([
                
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
