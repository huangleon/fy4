 //feiyuancurse.c
inherit SKILL; 
void setup() { 
        set("name", "��ԩ������"); 
        set("usage/herb", 1); 
        set("usage/parry", 1); 
        set("practice_damage", 40); 
        set("effective_level", 250); 
        set("practice_bonus", -5); 
        set("skill_class", "quanli"); 
         
        set("parry_msg", ({ 
                "$n˫��һ����ͻȻһ�Ű���$N�Ƶ����˼�����\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
        "$n����Ϊ�������л�ɳ����$N��ȥ��\n", 
        }) ); 
        action = ({ 
                ([      "action":               "$N����һ����һ�Ű�������$n��$l", 
                        "force":                400, 
                        "damage":               200, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$Nһ�С��������ɡ�������$n��$l", 
                        "damage":               200, 
                        "force":                300, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N���ۺ�ɢ���������$n��$l", 
                        "force":                100, 
                        "damage":               200, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N�ζ�������˫�䣬��ʱ�ط���Ҫ���İ׹�ɢ��$n��$l", 
                        "force":                100, 
                        "damage":               200, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N����һ�ӣ���֪��������ʩ���˾޶���$nɢȥ", 
                   "force":                200, 
                        "damage":               200, 
                        "damage_type":  "����" 
                ]), 
        }); 
} 
int valid_learn(object me) 
{ 
    if((int)me->query_skill("force", 1) < 100) { 
        return notify_fail("����ڹ��ķ�����㣬�޷�����ԩ��������\n"); 
        } 
        return 1; 
} 
       
