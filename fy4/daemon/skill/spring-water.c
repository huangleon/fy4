 //spring-water.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "春水罗衫");
        set("usage/iron-cloth", 1);
    set("effective_level", 120);
        set("bounce_ratio", 10);
        set("learn_bonus", -300);
        set("practice_bonus", -5);
        set("black_white_ness", 20);
    set("skill_class", "huashan");
        set("absorb_msg", ({
        "$n秀眉微蹙，施展「两重心字罗衣」，周身衣衫飘舞，竟然似乎有点点微光浮动。\n",
        "$n施展春水罗衫的「梦后楼台高锁」，暗劲绵密，缕缕寒气传入$N的体内。\n",
        "$n微微侧身，一式「落花人独立」，在$N的攻势下，衣带飘飘，如风吹花舞。\n",
        "$n施展出「微雨燕双飞」，双袖飞展，接下$N的一击。\n",
        }) );
} 
int valid_learn(object me){
    if( (string)me->query("gender") != "女性" ) {
        return notify_fail("春水罗衫是只有女子才能练的武功。\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
}  
int practice_skill(object me)
{
        return notify_fail("春水罗衫只能通过学习来提高。\n");
                
}  
