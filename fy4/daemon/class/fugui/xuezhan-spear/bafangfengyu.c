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
                return notify_fail("�۰˷���������ݣ���Ҫ�����������ݵ���ϣ�\n");
        if ( tmp < 100 )return notify_fail("��ģ����������ݻ��������죡\n");
        
        if ( userp(me) && me->query_skill_mapped("force") != "skyforce")
                return notify_fail("�۰˷���������ݣ���Ҫ�۱̿��ķ��ݵ���ϣ�\n");
        if ( me->query_skill("skyforce",1) < 100 )return notify_fail("��ģ۱̿��ķ��ݻ��������죡\n");
                
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۰˷���������ݣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (me->query_temp("timer/bafang")+60>time())
                return notify_fail("�۰˷���������ݣݲ�������ʹ�á�\n"); 
        if(me->query("class")!="fugui") { 
                          extra=0;
                          tmp=tmp/2;
                        }
        tmp=tmp/2;       
        me->add_temp("apply/attack",tmp);
//      me->add_temp("apply/damage",extra);
    msg = HIR "\n\n$N���һ��������ìӰ�к�Ȼʹ����Ѫսǹ�����е�����һ����--�˷�--����--������--��!!\n\n\n�����š�\n$N����$w"+HIR"�ɻ�������$n"+HIR"������" NOR;
   COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�����š�\n$N����$w"NOR+HIR",��������ìӰ,���մ���$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "����š�\n$N��$w"NOR+HIR"��������,Ӳ�����㳯$n"NOR+HIR"���˹�����" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�ﾰ�š�\n����$N����$w"NOR+HIR"�û���ǧ��������,�����ܶ�,����$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�ﾪ�š�\n$N��$w"NOR+HIR"��û�������,����һ����һ��������ˣ�����$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);        
    msg = HIR  "�￪�š�\n$N��������,����$w"NOR+HIR"�󿪴���,����㳯$n"+HIR"Ϯ�˹�����" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�����š�\n$N�Ϻ�һ��,����$w"NOR+HIR"Ѹ�籼�׿���糸,����ͱ��$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "�����š�\n$w"NOR+HIW"����һ�������κ�����֮���Ļ���,���絶�а㻮��$n"NOR+HIW"�����ţ�" NOR;
        me->add_temp("apply/attack",tmp*2);
        me->add_temp("apply/damage",extra*2);   
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-tmp*3);
        me->add_temp("apply/damage",-extra*2);
        me->set_temp("timer/bafang",time());
        if (me->query_busy()<4) 
                me->start_busy(4);
        return 1;
}   
