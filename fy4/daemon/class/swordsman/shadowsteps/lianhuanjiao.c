 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        if( !target ) target = offensive_target(me); 
        if(me->query("class")!="swordsman")
                return notify_fail("［迷踪幻影连环脚］只有神剑山庄的弟子才能用！\n");
        
//      if (userp(me) && me->query_skill_mapped("force") != "cloudforce")
//              return notify_fail("［迷踪幻影连环脚］需要［淡云心法］的配合！\n");
                
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［迷踪幻影连环脚］只能对战斗中的对手使用。\n");
                
        extra = me->query_skill("shadowsteps",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIR  "$N施展出［迷踪幻影连环脚］，身形极度旋转，一丛人影中突然向$n飞出一腿！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"瘀伤");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        msg = HIR  "人影中又飞出一腿！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"瘀伤");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        msg = HIR  "$N身形渐稳，反身又是一腿！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"瘀伤");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        if (me->query_busy()<2) me->start_busy(2);
        return 1;
}   
