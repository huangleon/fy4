 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "南海码头"); 
        set("long", @LONG 
这里是南海最大的码头，许许多多的海船停靠在此，岸上人来人往，热闹非凡。 
很多人正忙着往船上搬运货物，这些货物将会经海路运往全国各大港口，甚至远赴 
重洋。 
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
