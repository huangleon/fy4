#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int third_sword(object me,object target,int extra,object blade);
int perform(object me, object target)
{
        string msg;
        int extra,i;
        object weapon;
        extra = me->query_skill("diesword",1);
        weapon=me->query_temp("weapon");
        if ( extra < 30) return notify_fail("��ĵ������������������죡\n"); 
        if (userp(me) && me->query_skill_mapped("force") != "qidaoforce")
                return notify_fail("�۲ʵ��������Ҫ������ķ��ݵ���ͣ�\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۲ʵ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
if (me->query("class")!="legend") {
        msg = HIG  "$Nʹ�������������еģ۲ʵ�����ݣ�һ������������\n���е�"+ weapon->name()+  HIG"�������$n"HIG"������һ����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIG  "�ڶ�����" NOR;
        me->add_temp("apply/damage",extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra);
        if (extra<130) {
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
        } 
        me->add_temp("apply/damage",extra*2);
        msg = HIG  "$N���⼱����һƬ��Ӱ���ֹ�����������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*2);
        if (me->query_busy()<3)  me->start_busy(3);
        return 1;
} 
        me->add_temp("apply/damage",extra);
        msg = HIG  "$Nʹ�������������еģ۲ʵ�����ݣ�һ������������\n���е�"+ weapon->name()+  HIG"�������$n"HIG"������һ���������羵������ϸ���ɡ�" NOR;
   COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIG  "�ڶ�������Ӧ���޷�Ͷ����, ���ó���ȥ�˻ء�" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra);            
        
        if (extra <130) {
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
        }
        
        third_sword(me,target,extra,weapon);                            
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
        
} 
        
int third_sword(object me,object target,int extra,object weapon)
{
        string msg;
        int bonus, exp_bonus;
        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me)) return 0;
        if(!present(weapon,me)||weapon->query("equipped")!="wielded")
                return 0;
        exp_bonus = me->query("combat_exp")/1000*extra/8000;    
        if(me->query("����A/����_����")) bonus=extra;
        me->add_temp("apply/damage",extra*7+ bonus+exp_bonus);
        msg = HIG  "$N���⼱����һƬ��Ӱ���ֹ�����������������Ӱ�ѹ顣��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*7-bonus-exp_bonus);
        return 1;
}      
