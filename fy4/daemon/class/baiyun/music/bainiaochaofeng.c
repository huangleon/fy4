#include <ansi.h>
inherit SSERVER; 
int conjure(object me, object target)
{       int damage,dp,ap;
        string msg;
        if (me->query("class") != "baiyun") return notify_fail("ֻ�а��Ƶ����ӿ������ࡸ���񳯷��\n");
    //add qin check here ->
    
    //<-
    if( me->is_fighting() )
        return notify_fail("�����񳯷������ս�����ࡣ\n"); 
/*
play ���񳯷play bainiaochaofeng) ��60 lev music��������100�㣬���1���� 
���ܷ���ʹ��) 
CYN���Ღ���ң�����������ƽ���кͣ�����������֮�⣬�����ÿ�������֮�������������� 
������ȸ�񣬻�ֹЪ���ۣ������°��裬ë���ͷף�εΪ��ۡ� 
GRN�̿���һֻ�������������˼��£�����һ����ݶ��������ϣ�����һ�������˿�ȥ�� 
*/
        if((int)me->query_skill("essencemagic",1) < 40)
                return notify_fail("��ķ��������ߣ�\n");
               
        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ַ���ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if((int)me->query("atman") < 100 )
                return notify_fail("��ķ���������\n"); 
        if( random(me->query("max_atman")) < 40 ) {
                write("��ʧ���ˣ�\n");
                return 1;
        } 
        msg = HIC "$N��Ŀ����ӡ�÷���һ����â����$n��\n\n" NOR;
        damage = me->query_skill("magic")*5/2;
        dp = target->query("combat_exp");
        ap = me->query("combat_exp");
        
        if( random(ap *3 ) > dp ) {
                damage = damage + random(damage);
                msg +=  HIY "��â��$p����͸��������ϳ�һ��������Ѫ��ֱ�䵽��������ĵ��£�\n" NOR;
           target->receive_damage("kee", damage, me);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,damage);
        } else
                {       msg += HIB"���Ǳ�$n�㿪�ˡ�\n\n"NOR;
                        message_vision(msg, me, target);
                        }
        me->start_busy(2);
        me->add("atman",-40);
        return 1;
}      
