#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        extra = me->query_skill("xuezhan-spear",1);
        tmp = me->query_skill("hawk-steps",1); 
        if(me->query("class")!="fugui")
                return notify_fail("ֻ�и���ɽׯ���Ӳ���ʹ�����˷���������ݡ��ľ�����\n");
        if ( extra < 120) 
                return notify_fail("���Ѫսǹ�����������죡\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "hawk-steps")
                return notify_fail("�۰˷���������ݣ���Ҫ�����������ݵ���ͣ�\n");
        if ( tmp < 120 )return notify_fail("��ģ����������ݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۰˷���������ݣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (me->query_temp("perform/bafang")+20>time())
                return notify_fail("�۰˷���������ݣݲ�������ʹ�á�\n"); 
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
    msg = HIR "\n\n$N���һ��������ìӰ�к�Ȼʹ����Ѫսǹ�����е�����һ����--�˷�--����--������--��!!\n\n\n�����š�\n$N����$w�ɻ�������$n������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�����š�\n$N����$w,��������ìӰ,���մ���$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "����š�\n$N��$w��������,Ӳ�����㳯$n���˹�����" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�ﾰ�š�\n����$N����$w�û���ǧ��������,�����ܶ�,����$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�ﾪ�š�\n$N��$w��û�������,����һ����һ��������ˣ�����$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);        
    msg = HIR  "�￪�š�\n$N��������,����$w�󿪴���,����㳯$nϮ�˹���!��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�����š�\n$N�Ϻ�һ��,����$wѸ�籼�׿���糸,����ͱ��$n��" NOR;
   COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "�����š�\n$w����һ�������κ�����֮���Ļ���,����㻮��$n�����ţ�" NOR;
        me->add_temp("apply/attack",tmp*4);
        me->add_temp("apply/damage",extra*4);   
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-tmp*5);
        me->add_temp("apply/damage",-extra*5);
        me->set_temp("perform/bafang",time());
        me->start_busy(4);
        return 1;
}   
