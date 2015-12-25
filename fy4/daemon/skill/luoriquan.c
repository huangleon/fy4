 // luoriquan.c
inherit SKILL;
void setup() {
        set("name", "������ȭ");
        set("usage/unarmed", 1);
        set("effective_level", 120);
        set("learn_bonus", -150);
        set("skill_class", "bat");
        set("parry_msg", ({
        "$nһ�����ʹ������������䡹���ó�������Ӱ����$N������ʽ�������Ρ�\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$nȽȽ�ڿն�������һ�С�����ҹ��������$N������ʽ�����ڿմ���\n",
        }) );   
        action = ({
                ([      "action":               "$N��Х������ʹһ�С�ĺɫǧɽ�롹��˫����������$n$l",
                        "force":                70,
                        "dodge":                30,
                        "parry":                70,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$NƮȻ�г���֮�⣬һ�С�����¶���¡�����$n��$l",
                        "force":                80,
                        "dodge":                40,
                        "parry":                70,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N��Ȼ����һת��һ�С����ƻ����ϡ���$n$l����ĳ�һ��",
                        "force":                90,
                        "dodge":                50,
                        "parry":                80,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$Nһ�С�����뺣�ϡ�������Ʈ�������̣�������$n��$lһ��",
                        "force":                80,
                        "dodge":                20,
                        "parry":                80,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N˫�ֺϻ���һ�С���ӿ��������Ȼ����$n��$l",
                   "force":                70,
                        "dodge":                10,
                        "parry":                80,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
        }
        if ((int)me->query("max_force") < 500){
        return notify_fail("�������̫�����޷���������ȭ��\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if (me->query_skill("luoriquan",1) > 180)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");       
        if ((int)me->query("force") < 20) {
                return notify_fail("�������������ϰ��\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}   
