 // changquan.c
inherit SKILL; 
void setup() {
        set("name",                                     "���ֳ�ȭ");
        set("effective_level",          60);
        set("practice_limit",220);
        set("usage/unarmed",            1);
        set("skill_class",                      "official");
        set("parry_msg",                        ({
                        "$n����Ϊ����һ�С�����Ϊ�������ͻ�$N��$w������\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "$n��ȭ���£���ȭ�Ա���һ�С����ų�塹����$N���ڳ��⡣\n",
                        })
        );
        action = ({
                        ([      "action":               "$Nʹһ�С��ڻ����ġ�����׼$n��$l��������һȭ",
                                "force":                80,
                                "parry":                60,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����ȭͷ��һ�С�̩ɽѹ��������$n��$l�к���ȥ",
                                "force":                60,
                                "parry":                30,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N������Σ���ȭ���й�ֱ��������$n��$l����",
                                "force":                60,
                                "parry":                30,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����һ������ȭ��������ȭʹ�����Ϻ��Ƴ�������$n$l",
                                "force":                60,
                                "parry":                80,
                                "damage_type":  "����"
                        ]),
        });
} 
/*
int effective_level()
{
        object me=this_player();
        int skill,n;
        
        skill=me->query_skill("changquan",1);
        if (skill<=220) return 60;
        if (skill>=240) return 100;
        
        n=(skill-220)/5*10+60;
        return n;
}*/  
