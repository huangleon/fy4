#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int count,int tmp,int extra,object weapon);
int perform(object me, object target)
{
        string forceskill,msg;
        int extra, exp_bonus;
        int tmp;
        object weapon;
        forceskill= me->query_skill_mapped("force"); 
        weapon=me->query_temp("weapon");
        extra = me->query_skill("yue-spear",1);
        if ( extra < 60) 
                return notify_fail("���������ƽǹ�����������죡\n");
        tmp = me->query_skill("manjianghong",1);
        if ( tmp < 60 )return notify_fail("��ġ��������ķ������������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ݺ����¡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
                
        exp_bonus = me->query("combat_exp")/1000*extra/2000;    
        if (exp_bonus>extra*4) exp_bonus=extra*4;
        
        if (me->query("class")!="official") exp_bonus =exp_bonus/4;
                      
        if ( me->query("family/master_id")!="master yue" 
                ||extra < 150||me->query("class")!="official"){ 
                me->add_temp("apply/attack", tmp+exp_bonus/5);    
                me->add_temp("apply/damage", extra+ exp_bonus);
        msg = HIR  "$N���쳤Х������$w"+HIR"�û���ǧ��ìӰ��һʽ���ݺ����¡�������˷�ֱ��$n����\n" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -tmp-exp_bonus/5);
                me->add_temp("apply/damage", -extra-exp_bonus);
                if (me->query_busy()<2) me->start_busy(2); 
                return 1;
        }
        
        else {
        
        forceskill = (string) me->query_skill_mapped("force");
        if ( forceskill != "manjianghong") tmp = 0;
                
        me->add_temp("apply/attack",tmp);
        msg = HIW "\n$N���쳤Х����Ȼ����ֱ������������$w"+HIW"�û���ǧ��ìӰ�����ǡ�������ƽǹ����\n��ս�޵�֮ʽ��--��-��-��-��--��!!"NOR+HIC"\n\n��\n$N����$w"HIC"ֱָ���գ���Ȼֱ��$n!" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "����\n$Nŭ��һ����ǧ��ìӰ���κ��˰�ֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "����Ȼ\n$N��ǹ֮�������м䣬ǹͷǹβ���������������$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "�ݺ�����\n$N����$w"+HIC"������Ҷ���޴����ڣ�����ǹӰ��һ����ֱ��$n��" NOR;
        me->add_temp("apply/attack",tmp*2);
        me->add_temp("apply/damage",extra*2);  
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "��˻\n$w"+HIC"�������磬�������죬�·������ڣ�" NOR;
        me->add_temp("apply/attack",-tmp*2);
        me->add_temp("apply/damage",-extra*2); 
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);        
    msg = HIC  "Ѫ��\n$N����$w"+HIC"ǹͷ����ٿ�ñ������������Ѫ�⣡" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIC  "��\n����һ��ͻ��������$N����$w"+HIC"ǹӰ��ʧ��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-tmp);
           
        if (me->query_busy()<6) me->start_busy(6);   
        } 
        return 1;
}       
