 //������֮���콣��
#include <ansi.h> 
inherit SKILL;
void setup(){
    set("name", "���콣��");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("practice_damage", 100);
        set("effective_level", 300);
        set("learn_bonus", -1000);
        set("practice_bonus", -1000);
        set("black_white_ness", 10);
        set("skill_class", "task_npc");
        set("parry_msg", ({
        "$nͦ��һ�С����������С�,���ν���������$N�Ĺ��ƶ�Ȼʧȥ�˷���\n",
                "$n������������һ���������ղ�������Ȼ������$N����Ĺ��ơ�\n",
                "$n��̾һ��������$v������磬$N�����Ĺ����ѱ�һ�С�������粨���������Ӱ���١�\n",
                "$n���������ʹ��һʽ����鮿�ʧ׹�����������Ѵ�$N������������\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$nͦ��һ�С����������С�,���ν���������$N�Ĺ��ƶ�Ȼʧȥ�˷���\n",
                "$n������������һ���������ղ�������Ȼ������$N����Ĺ��ơ�\n",
                "$n��̾һ��������$v������磬$N�����Ĺ����ѱ�һ�С�������粨���������Ӱ���١�\n",
                "$n���������ʹ��һʽ����鮿�ʧ׹�����������Ѵ�$N������������\n",
        }) ); 
        action = ({
                ([      "name":                 "�ڸ�������",
                        "action":               
                        "$N�ƹ��ȵ�ٿ�˺�����һ�С��ڸ�����������������������ӣ��޿ײ���ع���$n",
                        "dodge":                200,
                        "parry" :               400,
                        "damage":               170,
                        "force" :               200,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "˹�˶���",
                        "action":               
                        "$N�����һ������һʽ��˹�˶��㲡�,$w�������磬��������$n",
                        "dodge":                220,
                        "parry" :               200,
                   "damage":               300,
                        "force" :               100,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "ǧ��������",
                        "action":               
                        "$N˫Ŀ�ʹ���$w���أ�������ɮ�붨�����ּ�����ǰ����$n���ؿھ���һ�С�ǧ������������",
                        "dodge":                220,
                        "parry" :               340,
                        "damage":               140,
                        "force" :               250,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "��į�����",
                        "action":               
                        "$N���˷��������缲�磬����ʹ��һʽ����į����¡�������ױ���һ������$n��$l��",
                        "dodge":                170,
                        "parry" :               240,
                        "damage":               250,
                        "force" :               150,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 500 ){
                return notify_fail("�������������û�а취�����콣����\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 50 ){
                return notify_fail("�����������������û�а취��ϰ���콣����\n");
        }
        if(!::practice_skill(me)){
   }
        me->add("force", -50);
        write("�㰴����ѧ����һ�����콣����\n");
        return 1;
}   
