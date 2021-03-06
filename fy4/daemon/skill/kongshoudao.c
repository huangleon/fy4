 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// kongshoudao.c
inherit SKILL;
void setup() {
        set("name", "空手道");
        set("usage/unarmed", 1);
        set("learn_bonus", 10);
        set("practice_bonus", 5);
        set("black_white_ness", -10);
        set("skill_class", "others");
        set("parry_msg", ({
        "$n就势一滚，双手一撑地，全身弹出$N的$w的攻击范围。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n就势一滚，双手一撑地，全身弹出$N的攻击范围。\n",
        }) );   
        action = ({
        ([      "action":               
"$N左腿在前，右腿在后，双掌用力向$n的$l挥来",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左脚点地，身体向后旋转，右腿像疾风扫落叶般扫向$n的$l",
                "dodge":                10,
                "parry":                30,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右手虚晃，左肘从意想不到的角度撞向$n的$l",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右脚凌空，晃出一片腿影，霎那间向$n的$l一连踢出三脚",
                "dodge":                10,
                "parry":                30,
                "damage":                70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N凌空跃起，身体向后急转，双脚从下往上一前一后地撩向$n的$l",
                "dodge":                20,
                "parry":                30,
                "damage":                60,
                "damage_type":  "瘀伤"
        ]),
        });
} 
int practice_skill(object me)
{
    if( (int)me->query("force") < 5 ) {
        return notify_fail("你的内力不够了，休息一下再练吧。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -5);
    return 1;
}       
