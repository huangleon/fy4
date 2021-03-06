 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
                
        extra = me->query_skill("duanhun-spear",1) ;
        if ( extra < 145) return notify_fail("你的断魂枪还不够纯熟！\n");
        
/*      if ( userp(me) && me->query_skill_mapped("force") != "xiaochengforce"
                || me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("断魂枪需要少林内功的配合！\n");     */
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［锁梦缠魂］只能对战斗中的对手使用。\n");
        weapon = target->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        
        if (hisexp>3500000) hisexp=hisexp*3;
        
        if(random(hisexp) < myexp && weapon && random(2))       {
                message_vision(HIW "\n\n$N使出一式锁梦缠魂枪，枪身似灵蛇般缠住$n手中的兵刃，"NOR+ 
weapon->name()+  HIW"脱手而飞！\n\n" NOR, me,target);
                if( weapon->unequip()) 
                        weapon->move(environment(target));
        } else  {
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage", extra*2);
                msg = HIR+ "\n\n$N使出一式锁梦缠魂枪，手中的"NOR+(me->query_temp("weapon"))->name()+HIR"如灵蛇般直咬$n的$l！\n\n"+ NOR;
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
           me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -extra*2);
        }
        if (me->query_busy()<2) me->start_busy(2);
        return 1;
}   
