 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�������ÿ�");
        set("long", 
"���������� ���աաաաաաաաաաաաաաաա�
 �����������������աա��������������������������ա�
�� ���������������աա�����"HIR"�򡡡�������"NOR"�������ա�
 �����������������աա��������������������������ա�
 �����������������աաաաաաաաաաաաաաաա�\n"+
@LONG
    ������ɼľΧ�ɵ�դ�����ߴ����ɡ�����һƬ����������ж��ټ䡣һ����
�Ŵ�����ҹɫ�У����ڵĵ���˿������߲����ʡ�һյ��ƣ�������������ʮ��
�ߵ�����ϣ�ѩ�׵ĵ����������ʺ�Ĵ��֡�
LONG
        );
        set("exits", ([ 
                "enter" : __DIR__"yard",
                "south" : __DIR__"grassland2",
                "southeast": __DIR__"grassland3",
        ]));
        set("objects", ([
                __DIR__"npc/vguard":    2,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object me, string arg) {
        object ob;
        
        ob=present("white cloth man",this_object());
        
        if (!ob) return 1;
        
        if (userp(me))
        if (arg== "enter") {
           message_vision("$N˵������������������Ҫ���ˣ������˵ȣ���׼���ڡ���\n",ob);
                return notify_fail("");
        }
        
        return 1;
}
