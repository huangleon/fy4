 // fengyu-piaoxiang.c  ����Ʈ�㲽
inherit SKILL;
void setup() {
        set("name", "����Ʈ�㲽");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 120);
        set("practice_damage", 60);
        set("learn_bonus", -400);
        set("practice_bonus", -30);
        set("black_white_ness", 0);
        set("skill_class", "bat");
        set("dodge_msg", ({
            "$nһ����ĮĮ�����ء�������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�\n",
            "$nʹ��һ�С�ڤڤ��ȥ�١�����Ȼ�������࣬���$N���˸��ա�\n",
            "$n����һҡ���ó�������Ӱ��һ�С�ɽ�紵���֡������$N�Ĺ��ơ�\n",
            "$nһ�С�ǧ��ͬһɫ������Ծ��ٿ��������$N���\n",
            "$n��һҡ����һ�Σ�һ�С�����ȥ�岨��������������\n",
            "$n˫��һ�㣬бб����ʹ����������֡�������$N��ࡣ\n",
        }) ); 
} 
int practice_skill(object me)
{
        if (me->query_skill("fengyu-piaoxiang",1) > 170)
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
