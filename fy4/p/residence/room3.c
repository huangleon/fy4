 inherit ROOM;
void create ()
{
  set ("short", "��Ϫ̶");
  set ("long", @LONG
��Ϫ̶����������ˮ�������������Ͽ���С�ɽȪ�Ҹ�ӿ��������к����
Ϫ��أ�׳�����裬��������ˮ��ʯ������̽��ӣ����׳����Ϫ��Ϫǰ���²�
԰�������̣������˱ǡ���ͨ�裬����گʱ��������ֲ�����׿���ɽ������ͦ
�㣬����ʮ�����
LONG);
        set("exits", ([
"eastup" : __DIR__"duzhong1037397672",
"southwest" : __DIR__"yeee1034829620",
"northeast" : __DIR__"digi1030355695",
"northwest" : __DIR__"davis1029346153",
"down" : __DIR__"xigua1022982983",
"west" : __DIR__"tuzi1022459949",
"east" : __DIR__"xigua1021996344",
"up" : __DIR__"xigua1021957669", 
  "south" : __DIR__"room2",
  "north" : __DIR__"room4",
]));
        set("coor/x",10);
        set("coor/y",2020);
        set("coor/z",20);
        set("owner","public");
        setup();
  replace_program(ROOM); 
} 
      
