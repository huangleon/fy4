 inherit ROOM;
void create ()
{
  set ("short", "֮����С·");
  set ("long", @LONG
��ɽ��С·Խ���꣬����ׯ������Ұ��Լ�����������������ˮ���ĺ�����
��ǰ������һƬ�µص�ǰ�ˣ����ֵ�Ѿ�������䣬�Ǿ޴�ĺ����������Ǵ�����
���ﴫ���ġ������ϵ�֮����С·���ٷ�ʯ���Ѷ��£�Լ����ɣ�����ף�һƬ
����׳�۵��ٲ���������������ǰ��
LONG);
        set("exits", ([ 
  "south" : AREA_QIANFO"road1",
  "north" : __DIR__"room3",
]));
        set("coor/x",10);
        set("coor/y",2010);
        set("coor/z",10);
        setup();
  replace_program(ROOM); 
}   
