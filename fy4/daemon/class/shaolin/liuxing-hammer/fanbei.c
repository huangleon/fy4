 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,n;
        extra = me->query_skill("liuxing-hammer",1);
        if ( extra < 50) 
                return notify_fail("��ķ�ת���Ǵ������������죡\n");
        
        if (userp(me) && me->query_skill_mapped("force") != "xiaochengforce" && extra<170)
                return notify_fail("170�����µķ�ת���Ǵ�����Ҫ��С���ķ��ݵ���ϣ�\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        msg = HIY  "$Nʹ����ת���Ǵ����еģ۷��������ݣ���������ˣ���ط�����һ����" NOR;          
                me->add_temp("apply/attack",extra/2);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack",-extra/2);
                n=2;
        if (extra > 75) {
                msg = HIY  "$N����һ�У���һ����������һ������" NOR;
                me->add_temp("apply/attack",extra/2);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack",-extra/2);
                n=2;
        }       
        if (extra > 100) {
                msg = HIY  "$N��Ȼ������ͷ������һ������һ����" NOR;
                me->add_temp("apply/attack",extra/2);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack",-extra/2);
                n=2;
        }
        if (me->query("class")!="shaolin" && extra>100) n=3; 
   if (me->query_busy()<2) me->start_busy(n);
        return 1;
}       
