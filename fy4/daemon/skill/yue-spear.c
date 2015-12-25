 // yue-spear.c
//TIE@FY3
inherit SKILL; 
void setup() {
        set("name",                                     "������ƽǹ��");
        set("effective_level",          200);
        set("learn_bonus",              -300);
        set("practice_bonus",           -15);
        set("black_white_ness",         0);
        set("usage/spear",                      1);
        set("usage/parry",                      1);
        set("skill_class",                      "official");
        set("parry_msg",                        ({
                        "$n�������ƣ���������Ц̸������ūѪ�������е�$v���¶��ϣ�������$N��$w��\n",
                        "$n��������ƾ������������Ъ�������е�$v����ܲ�͸�磬��$N��$w�������⡣\n",
                        "$n�������е�����Ī���а�������ͷ���ձ��С������е�$v����������գ�������$N��$w��\n",
                        "$n���е�$vһ����ǹ��������$N��$w�������ȥ��\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "$nʹ��һ�С�ŭ����ڡ��������е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
                        "$nʹ��һ�С�׳�����ҡ�����������ʧ��һ��ǹӰ֮�С�\n",
                        "$n����ת��$vֱ��$N��˫�֡�\n",
                        "$n�����е�$vһ�����������ǹӰ���ȵ�$N�������ˡ�\n",
                        })
        );
        
        action = ({
                        ([      "action":               
                                        "$N��������: ������ͷ��ʰ��ɽ�ӣ������ڡ���������$w��ת��ǹ��\n�������ϣ�ֱ��$n��$l��ȥ",
                                "dodge":                32,
                                "parry":                20,
                                "force" :               40,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N��̾�����������ܣ���δѩ�����Ӻޣ���ʱ�𣡡�������$w�γ�����\nǹӰ����Ȼһǹ��$n��$l��ȥ",
                                "dodge":                10,
                                "parry":                40,
                                "force":               15,
                           "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N�����ɫ������������ʮ��������������ǹ��ͻת����$n������ɨȥ",
                                "dodge":                20,
                                "parry":                30,
                                "force":               50,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$Nһ����Х�����ݳ�����̤�ƺ���ɽȱ��������̤����ǰ����������$w\nƽƽ�ݳ���ֱȡ$n��$l",
                                "force":                30,
                                "dodge":                20,
                                "parry":                30,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N��ͷ��Ŷ������ǧ��·�ƺ��¡�������$w�����㣬��ؽ�������\n��$nɨ��һ��ǹӰ",
                                "dodge":                20,
                                "parry":                20,
                                "force":               30,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N�����������е�����׳־���ͺ�²�⡹�����г�ǹ������ң����Ʋ�����ļȻ��\n����$n��$l��ȥ",
                                "dodge":                56,
                                "parry":                13,
                                "force":               10,
                                "damage_type":  "����"
                        ]),
        });
} 
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("max_force") < 30) {
                return notify_fail("�������������û�а취��������ƽǹ����\n");
        }
        
   return 1;
} 
int practice_skill(object me) {
        
        if (me->query_skill("yue-spear",1) > 120)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");
        if((int)me->query("force") <10 ) {
                return notify_fail("�������������û�а취��ϰ������ƽǹ����\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        write("�㰴����ѧ����һ��������ƽǹ����\n");
        return 1;
}  
