 //feiyuancurse.c
inherit SKILL; 
void setup() { 
        set("name", "非冤布毒术"); 
        set("usage/herb", 1); 
        set("usage/parry", 1); 
        set("practice_damage", 40); 
        set("effective_level", 250); 
        set("practice_bonus", -5); 
        set("skill_class", "quanli"); 
         
        set("parry_msg", ({ 
                "$n双肩一抖，突然一团白雾将$N逼得连退几步。\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
        "$n反客为主，手中灰沙反向$N撒去。\n", 
        }) ); 
        action = ({ 
                ([      "action":               "$N左手一撒，一团白雾照向$n的$l", 
                        "force":                400, 
                        "damage":               200, 
                        "damage_type":  "瘀伤" 
                ]), 
                ([      "action":               "$N一招「烟雨蒙蒙」，裹向$n的$l", 
                        "damage":               200, 
                        "force":                300, 
                        "damage_type":  "瘀伤" 
                ]), 
                ([      "action":               "$N忽聚忽散出毒物击向$n的$l", 
                        "force":                100, 
                        "damage":               200, 
                        "damage_type":  "瘀伤" 
                ]), 
                ([      "action":               "$N晃动着左右双袖，不时地发出要命的白光散向$n的$l", 
                        "force":                100, 
                        "damage":               200, 
                        "damage_type":  "瘀伤" 
                ]), 
                ([      "action":               "$N回首一挥，不知不觉中已施放了巨毒向$n散去", 
                   "force":                200, 
                        "damage":               200, 
                        "damage_type":  "瘀伤" 
                ]), 
        }); 
} 
int valid_learn(object me) 
{ 
    if((int)me->query_skill("force", 1) < 100) { 
        return notify_fail("你的内功心法火候不足，无法练非冤布毒术。\n"); 
        } 
        return 1; 
} 
       
