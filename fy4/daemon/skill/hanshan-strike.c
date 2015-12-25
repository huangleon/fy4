 //hanshan-strike.c
inherit SKILL;
void setup() {
        set("name", "��ɽ�Ʒ�");
        set("usage/unarmed", 1);
        set("usage/parry",1);
        set("effective_level", 100);
        set("skill_class", "knight");
        set("learn_bonus", 10);
        set("practice_bonus", -10);
        set("parry_msg", ({
        "$nһ�С�����һ�ߡ����ͻ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
        "$n��ȭ��ϣ���ȭһ�С�����Ϊ�������Ƶ�$N����������\n",
        "$n����Ϊ����һ�С�ʨ��Ի͡����ͻ�$N��$w������\n",
        "$nһ�С����Ρ�������һ��$N��$w���֣���ƫ��$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$nһ�С�������������Ƶ�$N��;���С�\n",
        "$n����������һ�С����׳�н������$N֮�ؾȡ�\n",
        "$n��ȭ���£���ȭ�Ա���һ�С����ų�塹����$N���ڳ��⡣\n",
        "$n˫ȭ�����ʹ��һ�С�һ��˫�񡹣�$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",
        }) );   
        action = ({
                ([      "action":               "$Nʹһ�С����ɲ��¡�����׼$n��$l��������һȭ",
                        "dodge":                60,
                        "parry":                40,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����ȭͷ��һ�С���ѩ��ɽ������$n��$l�к���ȥ",
                        "dodge":                70,
                        "parry":                30,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N������Σ���ȭ����ɽ���Ρ���$n��$l����",
                        "dodge":                80,
                        "parry":                30,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����һ������ȭ��������ȭʹ�����������졹����$n$l",
                        "dodge":                90,
                   "parry":                30,
                        "damage_type":  "����"
                ]),
        });
} 
int practice_skill(object me)
{
        
        if ((int)me->query("force") < 10) {
                return notify_fail("�������������ϰ��\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -5);
        return 1;
} 
