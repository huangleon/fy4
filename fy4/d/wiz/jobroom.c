 // Tie@fy3
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
���µĵ�ɢ������͵Ĺ⣬��ľ��̨����Χ���˼���
���ӡ���������Ĳ�������ô�ĺ�г��������볨�����
���飬ʹʹ���ؽ����е�ʵ��ʹ�ҷ�����������Ϣ
�ң������Ƿ�Ժ���������Ǽ�����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hall",
  "north" : __DIR__"courthouse",
  "east"  : __DIR__"jail",
  "down"  : AREA_FY"fysquare",
]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",10);
        set("no_magic",1);
        setup();
        call_other("/obj/board/wizard_j", "???");
        replace_program(ROOM);
}    
