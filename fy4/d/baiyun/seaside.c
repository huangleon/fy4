 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "�Ϻ���ͷ"); 
        set("long", @LONG 
�������Ϻ�������ͷ��������ĺ���ͣ���ڴˣ������������������ַǷ��� 
�ܶ�����æ�������ϰ��˻����Щ���ｫ�ᾭ��·����ȫ������ۿڣ�����Զ�� 
���� 
LONG 
           ); 
        set("exits",  
           ([  
             "west"  : __DIR__"beach2", 
            ])); 
         
        set("objects",  
           ([  
             __DIR__"npc/oldfox" : 1, 
             __DIR__"npc/sailor" : 5, 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",30); 
        set("coor/y",-680); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}     
