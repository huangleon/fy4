 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "Ǳ��Ȫ");
        set("long", @LONG 
�������У�������ب����һ��Ϫ���������ð��������ǧ����ǰ���Ʊ�Ϊ��ɽ��
ǧ�ض��£���ɽ���٣������ȷḻ�����м�����������˲��ܲ��������ʣ�������
�Ƶ��ĵ���Ͱ��Ƴǵĵ��ӵ�Ҳ������������״�������̵�Ȫˮ����ԡ��ʱ��һ��
���ӷ���������������ʵ���÷Ƿ���
LONG 
           ); 
        set("exits",  
           ([  
       "eastup" : __DIR__"jianlin",
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
