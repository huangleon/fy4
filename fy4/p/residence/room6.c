 inherit ROOM;
void create ()
{
  set ("short", "̩���㳡");
  set ("long", @LONG
�������������ܵ��������е��徻����ɫʯ���̳ɵĴ�����ķ����ӡ��㳡
�����Σ�����������ڴ�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ����㳡���и���
ˮ�أ�������Ϻ��浹Ҳ���˲��٣������ļ��紺�������£��ɻ�˯���ޱ���次�
LONG);
        set("exits", ([
  "southwest" : __DIR__"room4",
  "northwest" : __DIR__"room7",
]));
        set("coor/x",15);
        set("coor/y",2035);
        set("coor/z",40);
        set("owner","public");
        setup();
  replace_program(ROOM); 
}     
