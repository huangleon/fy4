 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        extra = me->query_skill("shenji-steps",1);
        if ( userp(me) && extra < 100) 
                return notify_fail("��ģ���������ݻ��������죡\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                
        message_vision(HIG"$N"+HIG"���������磬��������$n"+HIG"�����$n"+HIG"��һ��һ��������$N"+HIG"�����֮�У�\n"NOR,me,target);
        
        if(target->query("combat_exp") < me->query("combat_exp")/2+3*random(me->query("combat_exp")))
        {
        message_vision(HIB"���$N"+HIB"�����ô�ʧɫ����æ���ң�\n"NOR,target);
        target->start_busy(3);
        }
        else{
        message_vision(HIY"���$N"+HIY"�������ţ�\n"NOR,target);
        me->start_busy(2);
        }
        return 1;
}       
