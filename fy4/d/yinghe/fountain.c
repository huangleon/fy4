 // Room: fountain.c --- by MapMaker
#include <ansi.h>
inherit ROOM; 
string fountain();
void create()
{
        set("short", "荧水喷泉"); 
        set("long", @LONG
这里是天上的荧河与谷地的长河相汇的地方。两条河上下交会，河水却毫无
紊乱。就如同在一面光洁的镜子上，垂下一条丝带，与镜中的影像就那样平平整
整地相接在一起。一座玉雕喷泉自自然然地喷涌着莹洁的水雾，把一切包围在一
种幽静迷蒙的平衡中。
LONG); 
        //{{ --- by MapMaker
        set("exits",([
        "southeast":__DIR__"stonecave",
        "southwest":__DIR__"riverroad1",
        ]) );
        //}}
        set("item_desc", ([
                "fountain" : (: fountain :),
                "喷泉" : (: fountain :),
        ]));
        set("balanced", 1);
        set("indoors", "linghe");
        setup();
} 
string fountain(){
        object me;
        me = this_player();
        if(query("balanced")){
                tell_object(me, "一座玉雕喷泉自自然然地喷涌着莹洁的水雾，水雾落在如镜面般的水面上不溅起一点
儿涟漪。你不由得想丢东西进去看看如何。（ｔｈｒｏｗ）\n");
                add_action("do_throw", "throw");
        } else {
                tell_object(me, "玉雕喷泉微斜，泉水已然干涸。\n");
        }
        return "";
} 
int do_throw(string arg){
    object me;
    object tar; 
    me = this_player();
    if( !arg || arg == "") 
            return notify_fail("你要丢什么东西。\n");
    tar = present(arg, me);
    if( !tar) 
            return notify_fail("你身上没有这东西。\n");
    if( userp(tar))
            return notify_fail("你不可丢活的东西。\n");
    if( tar->query("owner"))
            return notify_fail("你不可丢订的东西。\n");
    if (tar->query("no_drop"))
            return notify_fail("这样东西不能丢。\n");
        if(tar->query("id") == "hel sand"){
                message_vision("$N扬起手中的黑沙，黑沙缓缓飘落在莹洁的水雾上。。\n", me);
            tar->move(environment(me));
                destruct(tar);
                call_out("flash", 1, me);
                return 1;
        }
    message_vision("$N将$n投入了荧水喷泉，水面始终平滑如镜。\n", me, tar);
    tar->move(environment(me));
    destruct(tar);
    return 1;
} 
int flash(object me){
        object *inv, room;
        int i;
        
        message_vision(HIC"\n只听“轰隆隆。。。”喷泉倾斜，河水犹如脱缰野马般冲了过来。\n\n"NOR, me);
        room = find_object("d/fy/fysquare");
    if(!objectp(room)) {
        room=load_object("d/fy/fysquare");
    }
        delete("balanced");
        set("long", @LONG
这里是天上的荧河与谷地的长河相汇的地方。两条河上下交会，原本应该平
滑如镜的河水上此时却波涛汹涌，荧河携带着千军万马之势注入谷地的长河，一
座已然干涸了的玉雕喷泉微微倒斜。
LONG);
    inv = all_inventory(this_object());
    for(i=0; i<sizeof(inv); i++) {
        if(userp(inv[i])){
                inv[i]->move(room);
        } else {
                destruct(inv[i]);
        }
    }
        return 1;
} 
void reset(){
        set("long", @LONG
这里是天上的荧河与谷地的长河相汇的地方。两条河上下交会，河水却毫无
紊乱。就如同在一面光洁的镜子上，垂下一条丝带，与镜中的影像就那样平平整
整地相接在一起。一座玉雕喷泉自自然然地喷涌着莹洁的水雾，把一切包围在一
种幽静迷蒙的平衡中。
LONG);
        set("balanced", 1);     
}     
