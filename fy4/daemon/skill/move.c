 // move.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "�����Ṧ");
        set("effective_level",          50);
} 
void skill_improved(object me)
{
        int s; 
        s = me->query_skill("move", 1);
        if( s%10==9 && (int)me->query("agi") < s/5) {
                tell_object(me, HIW "����������Ṧ������ٶ�����ˡ�\n" NOR);
//              me->add("agi", 2);
                me->set("agi",(s+1)/5);
        }
}       
