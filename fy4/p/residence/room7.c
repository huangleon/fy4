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
"northup" : __DIR__"sanfeng1024378933",
  "southwest" : __DIR__"room5",
  "southeast" : __DIR__"room6",
]));
        set("coor/x",10);
        set("coor/y",2038);
        set("coor/z",50);
        set("owner","public");
        setup();
  replace_program(ROOM); 
} 
    
