#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
    string msg;
    int extra; 
    if(me->query("class")!="wudang" && userp(me))
                return notify_fail("̫��ճ�־����䵱���֮����\n"); 
    extra = me->query_skill("taiji",1);
    if (extra < 60)
        return notify_fail("���̫��ȭ���������\n"); 
    if (userp(me) && me->query_skill_mapped("force") != "taijiforce")
                return notify_fail("��̫��ȭ����Ҫ��̫���ķ��ݵ���ϣ�\n"); 
    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail("��ճ�־���ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if (target->query("step_less")==1) 
                return notify_fail(HIW"����������������տ�����ᱻ��ȭ���Ի�ġ�\n"NOR); 
    if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n"); 
    if (extra < 165) {
        msg = CYN "$Nʹ��̫��ȭ���еġ�ճ���־�����ͼ����$n�Ĺ��ƣ�";
        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2
 ) {
            msg += "���$p��$P���˸����ֲ�����\n" NOR;
            target->start_busy( (int)me->query_skill("taiji",1) / 50 + random(2)
);
        }
        else {
            msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
    }
    else {
        msg = HIR "$N�����Ķ���˫ȭ�û�Ϊ�������СС��ԲȦ��$n��ȥ��";
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3
 ) {
            msg += "���$pͷ��Ŀѣ����$P��ȭ��Χס��������ƵƵ���У�\n" NOR;
            target->start_busy(3);
            me->start_busy(random(2));
            target->receive_damage("kee",((int) me->query("max_force")/2),me);
            message_vision(msg, me, target);
            target->set_temp("damaged_during_attack", 1);
            COMBAT_D->report_status(target, 0);
            COMBAT_D->win_lose_check(me,target,1);
        }
        else {
            msg += "����$p����Ӧ�У���$P�Ĺ����������Ρ�\n" NOR;
            me->start_busy(random(2));
            message_vision(msg, me, target);
        } 
        return 1;
    }
}   
