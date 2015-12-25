 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without 
// the written permission from authors. 
inherit SKILL; 
void setup(){ 
        set("name", "Ϣ������"); 
        set("usage/blade", 1); 
        set("usage/parry", 1); 
        set("practice_damage", 40); 
        set("effective_level", 250); 
        set("practice_bonus", -10); 
        set("skill_class", "quanli"); 
        set("parry_msg", ({ 
                "$n�����ؽ����е�$v������ǰ��ǿ�ҵĵ��罫$N�Ƶ����˼�����\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
        "$n���е�$v�����ػӳ������Ҳ����ĵ������$N��\n", 
        }) );    
        action = ({ 
                ([      "action":               "$N���е�$wһ�Σ�һ��[�ĵ�]����$n��$l", 
                        "force":                400, 
                        "damage":               200, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N���е�$w���裬Ϯ����$n��$l", 
                        "damage":               200, 
                        "force":                300, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N��$wն�����ƣ����ۺ�ɢ�ؿ���$n��$l", 
                        "force":                100, 
                        "damage":               200, 
                        "damage_type":  "����" 
                ]), 
                ([      "action":               "$N�ζ����е�$w������������֣�����$n��$l", 
                        "force":                100, 
                        "damage":               200, 
                        "damage_type":  "����" 
                ]), 
           ([      "action":               "$N���������е�$w����������$n", 
                        "force":                200, 
                        "damage":               200, 
                        "damage_type":  "����" 
                ]), 
        }); 
} 
int valid_learn(object me){ 
        if( (int)me->query_skill("force", 1) < 100 ) { 
            return notify_fail("����ڹ��ķ�����㣬�޷���Ϣ��������\n"); 
        } 
        if(!::valid_learn(me)){ 
                return 0; 
        } 
        return 1; 
} 
   
