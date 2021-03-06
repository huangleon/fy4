 // feixian-sword.c
#include <ansi.h> 
inherit SKILL;
void setup() {
        set("name", "飞仙剑法");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("skill_class", "baiyun");
        set("effective_level", 150);
        set("learn_bonus", -50);
        set("practice_bonus", 10);
        set("black_white_ness", 15);
        set("parry_msg", ({
        "$n使出一招「凤舞九天」，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n使出「封」字诀，将$N的$w封于丈外。\n",
        "$n使出一招「朝朝瑞雪」，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「旱地春雷」，向$N拿$w的手腕削去。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手一招「阳光普照」，整个人消失在一团剑光之中。\n",
        "$n使出一招「龙舞九天」，$v直刺$N的双手。\n",
        "$n将手中的$v化做七条剑气，迫得$N连连后退。\n",
        }) );   
        action = ({
        ([      "action":               
"$N使一招「峰回路转」，手中$w如一条银蛇般刺向$n的$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出飞仙剑法中的「空山鸟语」，剑光霍霍斩向$n的$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「御风而行」，身形陡然滑出数尺，手中$w斩向$n的$l",
                "dodge":                30,
                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w中宫直进，一式「旭日东升」对准$n的$l刺出一剑",
                "dodge":                40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w一招「金光泻地」对准$n的$l斜斜刺出一剑",
                "dodge":                40,
                "force":                120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，一招「一剑西来」刺向$n的$l",
                "dodge":                20,
                "damage":               140,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招「柳暗花明」反手对准$n$l一剑刺去",
                "dodge":                20,
                "damage":               120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N横剑上前，身形一转手中$w使一招「仙云密布」画出一道光弧刺向$n的$l",
                "dodge":                30,
                "damage":               50,
                "force":                100,
                "damage_type":  "刺伤"
        ]),
        });
}
int valid_learn(object me)
{
    if( (int)me->query("max_force") < 50 ) {
            return notify_fail("你的内力不够，没有办法练飞仙剑法。\n");
        }
    if( (string)me->query_skill_mapped("force")!= "painting") {
            return notify_fail("飞仙剑法必须配合［画道］才能练习。\n");
        }
        if(!::valid_learn(me)) {
                return 0;
        }
    return 1;
} 
int practice_skill(object me)
{
    if((int)me->query("force") < 3) {
        return notify_fail("你的内力不够，没有办法练习飞仙剑法。\n");
    }
    if(!::practice_skill(me)) {
        return 0;
    }
    me->add("force", -3);
    write("你按著所学练了一遍飞仙剑法。\n");
    return 1;
}  
mixed hit_ob(object me, object victim)
{       
        int level_bonus, extra;
        object weapon;
        if (me->query_skill_mapped("force") != "painting")
                return ("");
        level_bonus = me->query_skill("chess", 1);
        
        if (extra =(int) me->query_temp("apply/painting") && random(8)) {
                extra += extra * ((int) me->query("combat_exp")/800000) 
                                + 20 * (int)victim->query("resistance/kee")
                                + (int)victim->query_skill("iron-cloth")/20;
                victim->receive_wound("kee", extra/2 +  random(extra), me);
                message_vision(CYN"$N招式幻动空灵，似淡云星光入画，剑气化做点点青芒刺向$n！\n"NOR, me, victim);
                COMBAT_D->report_status(victim);
                
        }
        if ((int) me->query("force_factor")/4 + level_bonus/5 + random(level_bonus/4) >
 (int) victim->query("force_factor") )
        {
           if ( random(3)&& !victim->is_busy()){
                        victim->start_busy(1+ random(2));  
            return (WHT "$N心剑合一，弈道的［攻算篇］先机在握，剑势变幻无方。\n$n被顿时攻得手忙脚乱！\n" NOR);
                }
        }
        return ("");
                
}     
