 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM; 
void create()
{
        set("short", "˽��ѧ��");
        set("long", @LONG
������ǰ��һ��ϴ�µ꣬����Ǯ�˽��·�������ϴ�ĵط����Դ��������
����ȥ���Ժ���һ������ס�˽�����������ĳ�һ��˽�ӣ�����Ϊ����̫�ң�
��û�м���ѧ�����ſ���һ����ľ�ƣ�������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"workroom",
])); 
        set("item_desc", ([
        ]) );
        set("objects", ([
                        ]) );
        set("coor/x",30);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
