#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    string msg;
    int extra;
    object weapon;
    if( !target ) target = offensive_target(me); 
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
    weapon = me->query_temp("weapon");
    extra = me->query_skill("thunderwhip",1);
    if( extra <=50) return notify_fail("��������ƻ�����������\n"); 
    if(!me->query("marks/hammerwhip") || me->query_skill("hammer")< 350
        || me->query_skill_mapped("hammer") != "pangu-hammer")
    {
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage", extra);
                msg = HIR
                "$N"+HIR"������ң����е�"+weapon->query("name")+
                HIR"���ȣ���һ����������������$n"NOR+HIR"��ȥ��" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -extra);
                if (me->query_busy()<2) me->start_busy(2);
    }   else    {
                extra = me->query_skill("whip")+ me->query_skill("hammer");
                extra = extra /4;
                if (me->query("class")!="yinshi") extra = extra /2;
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage", extra);
                msg = HIR
                "$N"+HIR"������ң����е�"+weapon->query("name")+
                HIR"���ȣ���һ����������������$n"NOR+HIR"��ȥ��" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/damage", extra);    
           msg = HIR"$N"+HIR"�������������һ�������е�"+weapon->query("name")+
                        HIR"���ž���֮����$n"NOR+HIR"�����ȥ��" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -extra-extra);
                if (me->query_busy()<2) me->start_busy(2);
                }
        return 1;
}
