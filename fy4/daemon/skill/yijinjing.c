 //mimicat@fy4
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                     "�׽");
        set("bounce_ratio",             25); 
        set("learn_bonus",              -900);
        set("black_white_ness",         20);
        set("effective_level",          200);
        set("usage/force",              1);
        set("usage/iron-cloth",         1);
        set("usage/unarmed",            1);
        set("skill_class",                      "shaolin");
        
                
        
        set("absorb_msg",                       ({
                        "�ۿ�$N��ʽѸ����$n������ǰӭ��һ����һȦ��ǽӦ�������$N������\n",
                        "$n˫�ֺ�ʮ���Ŀ������һ���ھ�͸�������$N���˻�ȥ��\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "�ۿ�$N��ʽѸ����$n������ǰӭ��һ����һȦ��ǽӦ�������$N������\n",
                        "$n˫�ֺ�ʮ���Ŀ������һ���ھ�͸�������$N���˻�ȥ��\n",
                        })
        ); 
        action = ({
                        ([      "action":
                        "$N����һ����ƽ�͵������紺�����̣�����$n$l",
                                "parry":                300,
                                "force":                100,
                                "damage_type":  "����"
                        ]),
                        ([      "action":
                        "$Nչ��һ�ӣ�������һ����������һ�����θ�ǽѹ��$n",
                                "parry":                200,
                                "force":                140,
                                "damage_type":  "����"
                        ]),
                        ([      "action":
                   "$Nһ���������䣬����Ѱ����ȴ��֪Ϊ�ε��޿ɵ������޿ɱ�",
                                "parry":                300,
                                "dodge":                400,
                                "force":                160,
                                "damage_type":  "����"
                        ]),
        });
} 
int valid_learn(object me) {
        if((string)me->query("class") != "shaolin" ) {
                return notify_fail("�׽��ֻ�����ָ�ɮ���������书��\n");
        }       
        if( (int)me->query_skill("zen",1) < (int)me->query_skill("yijinjing",1))
                return notify_fail("���������Ϊ�������޷������������׽��\n");
        if(!::valid_learn(me)) {
                return 0;
        }
        if((int)me->query("max_force") < 350) {
                return notify_fail("�������������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        return notify_fail("�׽ֻ��ͨ��ѧϰ����ߡ�\n");
                
}     
