#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if ( (string) me->query_skill_mapped("dodge") != "feixian-steps")
                return notify_fail("�������ֻ�ܺͷ��ɲ�����ϣ�\n");
        
        extra = me->query_skill("feixian-sword",1) / 10;
        extra += me->query_skill("feixian-steps",1) /10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra); 
        weapon=me->query_temp("weapon");
        
        msg = HIR  "$N��̤�۷��ɲ����ݣ�ͬʱʹ���۷��ɽ������еľ��裭���������\n���е�"+ weapon->name() +"����һ�����磬�����Ļ���$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg =  HIW "����һ������ʧ��������\n" NOR;
        message_vision(msg, me, target);
        
        for(i=0;i<extra/4;i++)
        {
        msg = HIY "$N����ͻת�������طɣ�\n" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        }
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        if ( me->query_busy()<3 ) me->start_busy(2);
        return 1;
}  
