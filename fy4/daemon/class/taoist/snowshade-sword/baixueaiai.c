 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, power=0,nd;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［白雪皑皑］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        extra = me->query_skill("snowshade-sword",1);
        if (me->query("class")=="taoist" && me->query_skill("scratching")) {
                power=me->query_skill("scratching")/4;
                }
        nd=me->query("no_dodge_snow");
        me->delete("no_dodge_snow");    
        me->add_temp("apply/attack", extra+power);      
        me->add_temp("apply/damage", extra+power*2);
        msg = HIR  "$N手中的"+ weapon->name() +"撒出漫天飞雪，一道白光象闪电般挥向$n！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra-power);
        me->add_temp("apply/damage", -extra-power*2);
        if (me->query_busy()<2) me->start_busy(2);
        me->set("no_dodge_snow",nd);
        return 1;
}   
