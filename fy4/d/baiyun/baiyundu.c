 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "���ƶ�");
        set("long", @LONG 
�������ģ�����һ�ߡ�������ǰ��Ƶ��ˣ�����������ã�����ɳ̲�����ϸ��
��ˮտ����̣����δ������������İ�ĭ�����ź���������������ƣ��������۴��̡�
һ�������ɾ�һ�㡣���Ű����Ǹ��������ͷ��ͣ�����������Ƶ��Ĵ�ֻ�������ĺ�
��������䣬ԭ������������ֻҪ������ͷ�Ĵ��Ҽ��ɹʹ��뵺��
LONG 
           ); 
        set("exits",  
           ([  
       "south" : __DIR__"huangsha1",
            ])); 
        set("objects",  
           ([  
//           __DIR__"obj/sand" : 1, 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-1680); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}      
