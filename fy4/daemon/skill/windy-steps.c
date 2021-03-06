 inherit SKILL;
void setup() {
        set("name", "急风三十六式");
        set("usage/dodge", 1.2);
        set("usage/move",1);
        set("effective_level", 150);
        set("learn_bonus", -30);
        set("practice_bonus", -30);
        set("black_white_ness", 0);
        set("skill_class", "knight");
        set("dodge_msg", ({
                "$n衣袖飘飘，如流云，如泻水，一式『自传芳酒翻红袖』浑然天成。 \n",
                "$n身形随风，一招『似有微词动绛唇』，早已避在七尺之外。\n",
                "$n衣衫突然鼓动而起，正是『雾气暗通青桂苑』，敌招尽皆落空。\n",
                "只见$n身形宛如千百条青蛇，一式『日华摇动黄金袍』，避开这一击。\n",
                "$n双足轻点地面，身形流动自如之中使出一式『垂手乱翻雕玉佩』。\n",
                "$n身形突回旋三次，斜斜地冲天而起，一式『背人多整绿上鬟』轻轻闪过。\n",
                "但是$n一招『黄鹏久住浑相识』使出，早已绕到$N身後！\n",
                "但是$n身形飘忽，一招『青鸟西飞意未回』，灵动无方避开这一击。\n",
        }));
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 ) {
                return notify_fail("你的内力不够，没有办法练急风三十六式。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 3 ) {
                return notify_fail("你的内力不够，不能练急风三十六式。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -3);
        return 1;
}      
