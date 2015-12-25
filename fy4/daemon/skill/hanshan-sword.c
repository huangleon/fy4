 // hanshan-sword.c
 
#include <ansi.h> 
 
inherit SKILL; 
void setup() { 
        set("name", "��ɽʮ��ʽ"); 
        set("usage/sword", 1); 
        set("usage/parry", 1); 
        set("effective_level", 270); 
        set("black_white_ness", -10); 
        set("skill_class", "quanli"); 
        set("parry_msg", ({ 
        "$n���˷������������죬һ�С��ޱߡ������е�$v�ݺݿĿ���$N��$w��\n", 
                "$n�ؽ����أ�һ�С���𡹣���ס��$N��$w��\n", 
                "$nһ�С����衹�����е�$v����ǧ�ٰѣ���ס��ȫ��\n", 
                "$n���е�$v�������£�������$N��$w�������Ρ�\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
        "$nʹ��һ�С����ϡ�������ǰ������һ��ͭǽ���ڣ���ס��$N�Ĺ��ơ�\n", 
                "$nһ�����е�$v��ʹ��һ�С����项�����е�$v��ס��ȫ��\n", 
                "$n��$v������һ�̣�$v�����������պ�ֱ��$N��˫�ۡ�\n", 
                "$n�ٽ�������һ�������ӽ���͸�����ƿ���$N��\n", 
        }) );    
        action = ({ 
                ([      "name":                 "Ⱥħ����", 
                        "action":               "$Nʹһ�С����ơ�������$w�����������$n��$l��������", 
                        "dodge":                -200, 
                        "parry" :               -200, 
                        "damage":               70, 
                        "force" :               200, 
                        "damage_type":  "����" 
                ]), 
                ([      "name":                 "�������", 
                        "action":               "$N����һת��һ�С�������$wն��$n��$l", 
                        "dodge":                -200, 
                        "parry" :               -200, 
                        "damage":               50, 
                        "force" :               100, 
                   "damage_type":  "����" 
                ]), 
                ([      "name":                 "�ٹ�ҹ��", 
                        "action":               "$N�趯$w��һ�С����ա�Ю�������������$n��$l", 
                        "dodge":                -200, 
                        "parry" :               -300, 
                        "damage":               150, 
                        "force" :               250, 
                        "damage_type":  "����" 
                ]), 
                ([      "name":                 "������·", 
                        "action":               "$N����$wһ����ʹ�������ȡ���$n��$l�̳�һ��", 
                        "dodge":                -100, 
                        "parry" :               -100, 
                        "damage":               50, 
                        "force" :               150, 
                        "damage_type":  "����" 
                ]), 
                ([      "name":                 "��Ӱ����", 
                        "action":               "$N����$w���Ⱪ����һ�С���Ӱ����$n$l��ȥ", 
                        "dodge":                -250, 
                        "parry" :               -250, 
                        "damage":               90, 
                        "force" :               220, 
                        "damage_type":  "����" 
                ]), 
                ([      "name":                 "��ع�", 
                        "action":               "$N����$wֱָ$n$l��һ�С���ء��������˽�����ȥ", 
                        "dodge":                -20, 
                        "damage":               50, 
                        "damage_type":  "����" 
                ]), 
        }); 
} 
 
int valid_learn(object me) 
{ 
        object ob; 
 
        if( (int)me->query("max_force") < 100 ) { 
           return notify_fail("�������������û�а취����ɽʮ��ʽ��\n"); 
        } 
        if(!::valid_learn(me)) { 
                return 0; 
        } 
        return 1; 
} 
 
int practice_skill(object me) 
{ 
 
        if((int)me->query("force") < 5 ) { 
                return notify_fail("�������������û�а취��ϰ��ɽʮ��ʽ��\n"); 
        } 
        if(!::practice_skill(me)) { 
                return 0; 
        } 
        me->add("force", -5); 
        write("�㰴����ѧ����һ�麮ɽʮ��ʽ��\n"); 
        return 1; 
} 
 
   
