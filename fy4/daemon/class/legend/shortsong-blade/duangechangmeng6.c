// tie@fengyun
//ʳ֥Ӣ������Ȫ�����ȹ�֦�������� 
//�����£��λ�Ԫ���������Σ���Ƿ�����档 
//��δ�ƣ�����ǧ��������ɽ������ 
/* 
    �̸��У����ף� 
 
�ԾƵ��裬�������Σ� 
Ʃ�糯¶��ȥ�տ�ࡣ 
�����Կ�����˼������ 
���Խ��ǣ�Ψ�жſ��� 
�������ƣ��������ġ� 
��Ϊ���ʣ��������� 
����¹����ʳҰ֮ƻ�� 
���мα�����ɪ���ϡ� 
�������£���ʱ�ɶޣ� 
�Ǵ����������ɶϾ��� 
Խİ���䣬������档 
����̸�磬����ɶ��� 
������ϡ����ȵ�Ϸɣ� 
�������ѣ���֦������ 
ɽ����ߣ�������� 
�ܹ��²������¹��ġ� 
 
*/ 
#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
int third_blade(object me,object target,int extra,object weapon); 
int perform(object me, object target) 
{ 
        string msg; 
        int extra,i; 
        object weapon; 
        extra = me->query_skill("shortsong-blade",1); 
        if ( extra < 30) return notify_fail("��Ķ̸赶�����������죡\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
           return notify_fail("�۶̸賤�Σ�ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        weapon = me->query_temp("weapon"); 
 
if (me->query("class")!="legend") { 
        msg = HIY  "$Nʹ���̸赶���еģ۶̸賤�Σݣ�һ��������ʽ�����е�"+ weapon->name()+  "�������$n������һ������" NOR; 
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg); 
//      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg); 
        msg = HIY  "�ڶ�����" NOR; 
        me->add_temp("apply/damage",extra); 
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg); 
        me->add_temp("apply/damage",-extra); 
        if (extra<150) { 
        me->start_busy(3); 
        return 1; 
        }  
        me->add_temp("apply/damage",extra*2); 
        msg = HIY  "��������" NOR; 
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg); 
        me->add_temp("apply/damage",-extra*2); 
        me->start_busy(3); 
        return 1; 
} 
 
        me->add_temp("apply/damage",extra); 
        msg = HIY  "$Nʹ���̸赶���еģ۶̸賤�Σݣ�һ��������ʽ��\n���е�"+ weapon->name()+  "�������$n������һ������ʳ֥Ӣ������Ȫ�����ȹ�֦����������" NOR; 
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg); 
        msg = HIY  "�ڶ������������£��λ�Ԫ���������������档��" NOR; 
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg); 
        me->add_temp("apply/damage",-extra);             
         
        if (extra <150) { 
        me->start_busy(3); 
        return 1; 
        } 
         
//              if(i=random(2)) 
//                      call_out("third_blade",i,me,target,extra,weapon); 
//              else 
        third_blade(me,target,extra,weapon);                             
        me->start_busy(3); 
   return 1; 
         
} 
         
int third_blade(object me,object target,int extra,object weapon) 
{ 
        string msg; 
        int bonus; 
         
        if (extra>150) extra = 150; 
        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me)) return 0; 
        if(!present(weapon,me)||weapon->query("equipped")!="wielded") 
                return 0; 
        me->add_temp("apply/damage",extra*6); 
        msg = HIY  "������������δ�ƣ�����ǧ��������ɽ��������" NOR; 
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg); 
        me->add_temp("apply/damage",-extra*6); 
        return 1; 
}
