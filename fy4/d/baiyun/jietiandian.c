 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "����¥");
        set("long", @LONG 
Σ�����գ��������������֮�ߣ�Ҷ�³��Ļ����£���־�г�һ����¹��ԭ����
��¥�ش����Ƶ����֮�����·�һ���������Ƴ���ңָ��ԭ���ݡ�¥�ϱ������һ
����̨�Ϻ������ɵ������汱ӭ�硣
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"yuequedian",
       "south" : __DIR__"changlang",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/fakemaster" : 1,
       __DIR__"npc/jiankuang" : 1,
            ])); 
        set("indoors", "baiyun");
        set("coor/x",10); 
        set("coor/y",-1680); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}  
