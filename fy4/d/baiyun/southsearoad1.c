 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "�Ϻ����"); 
        set("long", @LONG 
����ͨ���Ϻ���һ���ؾ�֮·��·���ϵ�ɳʯԽ��Խϸ��������������һ����ζ�� 
Խ�����ߣ���ζԽ���ԡ��������������İ�������ҲԽ��Խ������ͬʱ������������ 
��Ÿ��������������Ķ�����һ�ҳ��⴬�ߵĴ��У���Ҫ���������Ƕ����������ѯ 
������ֻ�ļ۸���������һ���ں��������������ͷ��
LONG 
           ); 
        set("exits",  
           ([  
             "north" : __DIR__"southsearoad", 
        // "west" : "/d/shanliu/qiongjie1",
             "south" : __DIR__"beach", 
//           "west"  : __DIR__"teashop" 
             "east"  : __DIR__"rentingboat" 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-660); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}      
