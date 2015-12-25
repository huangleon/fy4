 // Room: snakehall.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "蛇窟"); 
        set("long", @LONG
这里仿佛是一个恐怖的蛇虫地狱。脚下，洞壁甚至洞顶到处爬满了各种各样的
蛇。洞内的岩石因为涂满了蛇虫的涎液已经看不出本来的颜色。各种古怪的声响纷
至沓来，有簌簌的爬行声，有咯咯的摇尾声，有吐信的嘘嘘声。。。偶尔还从洞深
处传来荡人心魄的幽幽娇笑。
LONG); 
        set("indoors","yinghe");
        set("objects", ([
                __DIR__"npc/snake_c" : 2,
                __DIR__"npc/snake_k" : 2,
                __DIR__"npc/snake_b" : 1,
                __DIR__"npc/snake_r" : 1,
        ]));
        set("exits",([
                "enter" : __DIR__"pearlcurtain",
                "southwest":__DIR__"irongate4",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}    
