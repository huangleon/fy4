 //mimicat@fy4
inherit SKILL; 
void setup() {
        set("name",                                     "һָ��");
        set("effective_level",          210);
        set("learn_bonus",                      -400);
        set("practice_bonus",           -1000);
        set("black_white_ness",         15);
        set("skill_class",                      "shaolin");
        set("usage/unarmed",            1);
        set("usage/parry",              1);
        
        set("parry_msg",                        ({
                        "Ȼ��$n��ָ��㣬������ָ�罫$N���ˡ�\n",
                        "$n����һ��֮�䣬������$N���棬����һ�ƣ�һָ����$N�����ȵ�$N������� ��\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "Ȼ��$n��ָ��㣬������ָ�罫$N���ˡ�\n",
                        "$n����һ��֮�䣬������$N���棬����һ�ƣ�һָ����$N�����ȵ�$N������� ��\n",
                        })
        );
        action = ({
                        ([      "action":               
                        "$Nб��ʳָ���������£�����Ȼ��һ��������������$n$l ",
                                "dodge":                90,
                                "parry":                150,
                                "force":                100,
                                "damage_type":  "����",
                                "weapon":               "����",
                        ]),
                        ([      "action":               
                        "$Nһָ������󿪴��أ����ɺ�ΰ����ʯ���쾪���������֮�ƴ���$n$l ",
                                "dodge":                140,
                                "parry":                210,
                                "force":                190,
                                "damage_type":  "����",
                                "weapon":               "����",
                        ]),
                        ([      "action":               
                   "ֻ��$N����ǰ�壬���ֳ��Ƶ�ֱָ�㣬������������������͡������� ",
                                "dodge":                230,
                                "parry":                170,
                                "force":                220,
                                "damage_type":  "����",
                                "weapon":               "����",
                        ]),
                        ([      "action":               
                        "$N��ָ��ǰһ�࣬һ��������ָ���佫��ȥ������$n$l ",
                                "dodge":                380,
                                "parry":                360,
                                "force":                390,
                                "damage_type":  "����",
                                "weapon":               "����",
                        ]),
        });
} 
int valid_learn(object me) {
        
        if( (int)me->query_skill("zen",1)-50 < (int)me->query_skill("yizhichan",1))
                return notify_fail("���������Ϊ�������޷�����������һָ����\n");
        if(!::valid_learn(me)) {
                return 0;
        }
        if((string)me->query("class") != "shaolin" ) {
                return notify_fail("һָ����ֻ�����ָ�ɮ���������书��\n");
        }
        if((int)me->query("max_force") < 350) {
                return notify_fail("�������������\n");
        }
        return 1;
}  
int practice_skill(object me) {
        return notify_fail("һָ��ֻ��ѧ�ġ�\n");
}    
