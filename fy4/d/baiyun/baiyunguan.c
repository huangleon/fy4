 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "���ƹ�"); 
        set("long", @LONG 
��������Ҷ�³�����ס�ĵط���Ҷ�³���ͼ��λ�Ѿá����԰��ƳǴ����Իʹ�Ϊ 
ͼ��������Ψ�д˴���Ϊ���š�СС�ĵ����ڣ�һ����һ�Σ�һ�Զ��ѡ�ǽ��һ���� 
�������飺һ��������������ɣ�
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"changlang3",
//           "west"  : __DIR__"beach1", 
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/master" : 1,
            ])); 
        set("indoors", "baiyun");
        set("coor/x",10); 
        set("coor/y",-1680); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}     
