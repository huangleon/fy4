#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        
        extra = me->query_skill("unarmed");
        if (me->query_skill("luoriquan",1) < 220 && userp(me)) 
                return notify_fail("����ȭ����Ҫ220��������ȭ��\n");
        if( !target ) target = offensive_target(me);
        if( !target
                ||      !target->is_character()
                ||      !me->is_fighting(target) )
                return notify_fail("�����գ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        me->add_temp("apply/attack",extra/3);
        me->add_temp("apply/damage",extra/5);
        
        msg = HIR  "\n$N���췢��һ����Ц��ʹ��������ȭ�еģ����գݣ�\n���Ʋ����ޱȵ�Ϧ������ʱ�������Ϊ֮��ɫ��\n" NOR;
        message_vision(msg,me,target);
        msg = HIC    " ��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "          ��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIW  "                    ��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR   "                             ��\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIB   "                                       Բ\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra/3);
        me->add_temp("apply/damage",-extra/5); 
        if (me->query_busy()<3) 
                me->start_busy(3);
        return 1;
}
