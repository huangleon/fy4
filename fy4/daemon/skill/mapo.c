 // TIE@FY3
// mapo.c
inherit SKILL;
void setup() {
        set("name", "���ź�����");
        set("usage/spells", 1);
        set("skill_class", "assassin");
} 
int practice_skill(object me)
{
        return notify_fail("���ź�����ֻ����ѧ��\n");
}    
