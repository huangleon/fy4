 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "ն��̨");
        set("long", @LONG 
������Ÿ�ɮ��ϴ�ʦӦ���Ƴ���֮�����������ˣ�������̨���ɴ󾪣��Ե���
��ʵ�˰��Ƶ��ķ�ˮ�������ڣ�һ���˴��������⣬����Ƴ�Σ�ڵ�Ϧ�����Ƴ�����
˼���գ���ʱ�����ڴ��˽��˸ߴ���ɵ�ն��̨��Ρ�����졣��������δ�̨ʱ����
ɫ������ã���ڲ��ԡ�
LONG 
           ); 
        set("exits",  
           ([  
       "east" : __DIR__"skystreet",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/kugua" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-1680); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}
