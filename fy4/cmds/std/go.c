 // go.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 

// comment out by HL to avoid warning.
// #pragma optimize
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP; 
mapping default_dirs = ([
        "north":                "北",
        "south":                "南",
        "east":                 "东",
        "west":                 "西",
        "northup":              "北边高处",
        "southup":              "南边高处",
        "eastup":               "东边高处",
        "westup":               "西边高处",
        "northdown":            "北边低处",
        "southdown":            "南边低处",
        "eastdown":             "东边低处",
        "westdown":             "西边低处",
        "northeast":            "东北",
        "northwest":            "西北",
        "southeast":            "东南",
        "southwest":            "西南",
        "up":                   "上",
        "down":                 "下",
        "out":                  "外",
        "enter":                "里",
]); 
void create() {
        seteuid(getuid());
} 
int drop_things(object me) {
        int i, result;
        object *inv;
        object env; 
        env = environment(me);
        inv = all_inventory(me);
   result = 0;
        for(i=0;i<sizeof(inv);i++){
                if(inv[i]->query("no_drop") || inv[i]->query("equipped") || inv[i]->query("owner")
                                || random(me->query_max_encumbrance()) > inv[i]->weight()) {
                        continue;
                }
                result = me->ccommand("drop "+inv[i]->query("id")) ? 1 : result;
        }
        if(result) {
                message_vision("慌乱而去。", me);
                return 1;
        }
        return 0;
} 
int check_flee(object me, string arg)  {
    // comment out by HL to avoid warning.
        // mapping         my, your;
        object  *enemy;
        int             fp, bp, i; 
        i = me->query("combat_exp");
        if((random(i) < 300) && userp(me) ) return 1;
        enemy = me->query_enemy();
        for(i=0; i<sizeof(enemy); i++) {
        if( objectp(enemy[i]) && environment(enemy[i])== environment(me) && living(enemy[i])) {
                fp = COMBAT_D->skill_power(me, SKILL_USAGE_MOVE);
                if(fp<1) fp = 1;
                bp = COMBAT_D->skill_power(enemy[i], SKILL_USAGE_MOVE);
                if(bp<1) bp = 1; 
                if(random(fp*2+bp) > fp*2) {
                        message_vision(YEL "$N向" + arg + "逃去！\n" NOR, me);
                        message_vision(RED "$N身影一闪，挡在了$n的面前！\n" NOR, enemy[i], me);
                        return 0;
                 }
          }
        }
        return 1;
} 
int main(object me, string arg) {
        string dest, mout, min, dir, blk;
        object env, obj, blocker;
        mapping exit;
   mapping block; 
        if( !arg ) return notify_fail("你要往哪个方向走？\n"); 
        if( me->over_encumbranced() )
                return notify_fail("你的负荷过重，动弹不得。\n"); 
        if( me->is_busy() )
                return notify_fail("你现在忙得很，不能移动。\n");  
        env = environment(me);
        if(!env) return notify_fail("你哪里也去不了。\n");
        if(env->query_temp("lock_scene"))
        {
                if(time()<env->query_temp("lock_scene")+120)//防止万一没有去掉那个temp mark，出问题。
                        return notify_fail("你感觉到周围被一阵气场紧紧缩住，无法动弹。\n");
        }
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                if( query_verb()=="go")
                        return notify_fail("这个方向没有出路。\n");
                else
                        return 0;
        }
        if( mapp(block = env->query("blocks"))&& blk=block[arg]) {
                if( objectp(blocker = present(blk, env)) &&  living(blocker))
                return notify_fail("这个方向的路被"+ blocker->name() + "挡住了 。\n");
        } 
        dest = exit[arg]; 
        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("无法移动。\n"); 
        if( !env->valid_leave(me, arg) ) return 0; 
        if( !undefinedp(default_dirs[arg]) )
                        dir = default_dirs[arg];
                else if (dest->query("short")) dir=dest->query("short");
                else dir = arg; 
        if( me->is_fighting() ) {
                if(check_flee(me, dir) == 0) {
                        return notify_fail("你被挡了回来。\n");
                }
                drop_things(me);
                
                if (me->query("fleeout_message"))
                    mout = replace_string( me->query("fleeout_message"), "$d", dir );
                        else mout = "往" + dir + "落荒而逃了。\n";
                if (me->query("fleein_message"))
                         min  = me->query("fleein_message");
                        else  min = "跌跌撞撞地跑了过来，模样有些狼狈。\n"; 
        } else {
// Let's add this messages here to make go and come more interesting...
                if( mout = me->query("leave_msg"))
                        mout = "往" + dir + mout +"。\n";
                else 
                        mout = "往" + dir + "离开。\n";
                if( min = me->query("arrive_msg") )
                        min = min + "。\n";
                else
                        min = "走了过来。\n";
        }
        if (!userp(me) && obj->query("NONPC"))
                return notify_fail("你不可去那里。\n");
        else if(function_exists("valid_enter", obj) && !obj->valid_enter(me))
                return notify_fail("你不可去别人的私宅。\n"); 
        if(!me->is_ghost())
                if( me->query("self_go_msg") )          // this is for 自定义的不带主语的离开
                        message( "vision", me->query("leave_msg")+"\n", environment(me), ({me}) );
                else if (me->query("env/invisibility"))
                        message("vision","似乎有什么东西一闪后不知向什么方向去了。\n",environment(me),({me}));
                else  message( "vision", me->name() + mout, environment(me), ({me}) ); 
        if( me->move(obj) ) {
                me->remove_all_enemy();
                if(!me->is_ghost())
                        if( me->query("self_go_msg") )  // this is for 自定义的不带主语的进入
                                message( "vision", me->query("arrive_msg")+"\n", environment(me), ({me}) );
                        else if(me->query("env/invisibility"))
                                message("vision","似乎有什么东西闪了进来。\n",environment(me),({me}));
                        else    message( "vision", me->name()+ min, environment(me), ({me}) );
                me->set_temp("pending", 0);
                if(environment(me) != env) {
                        all_inventory(env)->follow_me(me, arg);
                }
                return 1;
        } 
   return 0;
}  
void do_flee(object me) {
        mapping exits;
        string *directions; 
        if(!environment(me) || !living(me)) {
                return;
        }
        exits = environment(me)->query("exits");
        if(!mapp(exits) || !sizeof(exits)) {
                return;
        }
        directions = keys(exits);
        tell_object(me, "看来该找机会逃跑了...\n");
        main(me, directions[random(sizeof(directions))]);
}    
int help(object me) {
        write(@HELP
指令格式 : go <方向> 
让你往指定的方向移动。 
HELP
        );
        return 1;
}   
