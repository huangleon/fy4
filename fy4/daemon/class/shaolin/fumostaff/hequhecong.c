 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
    string msg;
    int extra,myexp, hisexp;
    object weapon;
    extra = me->query_skill("fumostaff",1);
    if (me->query_skill("staff") < 220 || extra<145) 
                return notify_fail("���Τ�ӷ�ħ�ȷ����������죡\n");
      
    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail("�ۺ�ȥ�δӣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n"); 
    if (target->query("step_less")==2) 
                return notify_fail(HIW"����������������տ�����ᱻ�˼����Ի�ġ�\n"NOR); 
    myexp = (int) me->query("combat_exp");
    hisexp= (int)target->query("combat_exp");
    message_vision(HIW"$Nչ��Τ�ӷ�ħ�ȷ�����Ȼ�ó�����ã���֣�\n"NOR,me); 
    if (me->query("class")=="shaolin")      myexp=myexp/2+random(myexp)*5/2;
                else myexp=random(myexp)*5/2;
    
    if (!userp(me)) myexp=myexp/2+random(myexp)*3;
                
    if(hisexp < myexp)
    {
        target->start_busy(3);
        message_vision(YEL"$N���ȷ����󣬶�������������\n"NOR,target);
        me->start_busy(1);
    }
    else
    {
        message_vision(HIR"$N��$n�ľٶ������޶ã�\n"NOR,target,me);             
        me->start_busy(2);
    }
    return 1;
} 
