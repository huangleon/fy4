 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra, step;
        extra = me->query_skill("demon-blade",1);
        if ( extra < 100) 
                return notify_fail("��ģ������ħ������ʽ�ݻ��������죡\n");
        step = me->query_skill("demon-steps",1);
        if ( step < 100) 
                return notify_fail("��ģ������ħ�����˲��ݻ��������죡\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "demon-steps")
                return notify_fail("�������ħ����Ҫ������ħ�����˲�����ͣ�\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        step = me->query_skill("demon-steps",1);
        
        me->add_temp("apply/attack",step);
        me->add_temp("apply/damage",extra);     
        msg = HIY  "$N������ͨ���������ħ������ʽһ���ǳɣ�\n��ħ���ѣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "ħ�����ɣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "ħ��է�֣�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "��ħ����" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "������ħ��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "��ħ���죡" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "��ħ���֣�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "��ħ���ڣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-step);
        me->add_temp("apply/damage",-extra);    
        me->start_busy(4);
        return 1;
}     
