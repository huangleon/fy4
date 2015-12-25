 // TIE@FY3
//liumang-strike.c 
inherit SKILL; 
void setup() { 
        set("name", "��å��ȭ"); 
        set("usage/unarmed", 1); 
        set("usage/parry", 1); 
        set("skill_class", "quanli"); 
        set("parry_msg", ({ 
        "$nһʽ���һ�׶����˫�������»���ȭ�����棬����$N��$w��\n", 
                "$n�ڿշ���һʽ���˷��꡹��˫��˫�������������$N��$w��\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
                "$n���ⶪ��������һ�С���ˮ���ۡ���˫ȭ������$N֮�ؾȡ�\n", 
                "$nһ�С�������ѩ����ȫȻ����$N�Ĺ�����˫��ֱ��$N��ȥ���Ƶ�$N�����Ա���\n", 
        }) ); 
 
        action = ({ 
        ([      "action":                
"$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l��", 
                "damage":               400, 
                "dodge":                400, 
                "parry":                400, 
                "post_action":  "bash_weapon", 
 
                "damage_type":  "����" 
        ]),  
        ([      "action":                
"$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l��", 
                "damage":               400, 
                "dodge":                200, 
                "parry":                600, 
                "post_action":  "bash_weapon", 
 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N�������������֣�һ�С�������������ץ��$n��$l��", 
                "damage":               800, 
                "dodge":                100, 
                "parry":                400, 
                "post_action":  "bash_weapon", 
 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N˫��Ю��һ���ȳ�֮������$n��$l��", 
                "damage":               200, 
                "dodge":                110, 
                "parry":                400, 
                "post_action":  "bash_weapon", 
 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N������ɽ��һʽ�����������˫ȭ���ƶ���������$n��$l��", 
                "damage":               100, 
                "dodge":                100, 
                "parry":                200, 
                "post_action":  "bash_weapon", 
 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N�������أ�����������һʽ��ľ�ѳ��ۡ���������$n�Ƴ���", 
                "damage":               200, 
                "dodge":                100, 
                "parry":                200,                                "post_action":  "bash_weapon", 
 
                "damage_type":  "����" 
        ]), 
        ([      "action":                
"$N�������飬����������ޣ�һʽ��ˮ�����¡�����$n�޿ɶ���", 
                "damage":               100, 
                "dodge":                100, 
                "parry":                200, 
                "post_action":  "bash_weapon", 
 
                "damage_type":  "����" 
        ]), 
        }); 
} 
int valid_learn(object me) 
{ 
        if(!::valid_learn(me)) { 
                return 0; 
        } 
    if ((int)me->query_skill("wuchenforce", 1) < 20){ 
                return notify_fail("����޳��ķ���򲻹����޷�����å��ȭ��\n"); 
        }        
    if((int)me->query("str") + (int)me->query("max_force") / 100 < 35 ) { 
        return notify_fail("���������������Ҳ�����һ����������ǿ������\n"); 
        } 
    return 1; 
} 
 
mapping query_action(object me) 
{ 
    if (random(me->query_skill("unarmed")) > 100 && 
        me->query_skill("wuchenforce") > 70 && 
        me->query("force") > 100 ) { 
            me->add("force", -100); 
            return ([ 
            "action": "$Nһ������Ծ�����ɣ��ۼ�ȫ�����������$n", 
            "force": 500, 
            "damage_type": "����"]); 
    } 
    return action[random(sizeof(action))]; 
} 
        
