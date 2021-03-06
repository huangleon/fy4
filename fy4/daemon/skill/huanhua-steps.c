 // huanhua-steps.c
inherit SKILL; 
void setup() {
        set("name", "浣花步法");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 200);    
        set("black_white_ness", 10);
        set("skill_class", "npc");
        set("dodge_msg", ({
                "$n一招「雨水藏缔」轻轻巧巧地避了开去。\n",
                "只见$n身影一晃，一式「打叠菡萏」早已避在七尺之外。\n",
                "$n使出「倒转提盒」，轻轻松松地闪过。\n",
                "$n左足一点，一招「逐影回死」腾空而起，避了开去。\n",
                "可是$n使一招「风动玉动」，身子轻轻飘了开去。\n",
                "$n身影微动，已经藉一招「抑郁薄雾」轻轻闪过。\n",
                "但是$n一招「瑶摇飞地」使出，早已绕到$N身後！\n"
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 20 ){
                return notify_fail("你的内力不够，没有办法练浣花步法。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 3 ){
                return notify_fail("你的内力不够，不能练浣花步法。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -3);
        return 1;
}        
