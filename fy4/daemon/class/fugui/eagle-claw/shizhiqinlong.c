 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl,extra;
        extra=me->query_skill("eagle-claw",1);
        
//      if (me->query("class")!="fugui")
//              return notify_fail ("只有王动的弟子才领悟［十指擒龙］的要诀。\n");
        if(extra<130)
                return notify_fail("你鹰爪功的修为还不够高。\n");       
        if(me->query("force")<150)
                return notify_fail("你的内力不够\n");   
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［十指擒龙］只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");        
                
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        lvl = (int) me->query_skill("unarmed")/40 + 3;
        if(me->query("class")!="fugui") lvl=lvl/2;
        msg = HIR "$N使出鹰爪功中的［十指擒龙］，双手宛若布下天罗地网，招招扣向$n的关节要害！\n" NOR;
        message_vision(msg, me, target);
        
        if (random(6)) {
                if( random(myexp * lvl)+myexp/2 > yourexp)
                {
                        msg = BLU"$n大惊失色，连连中指，竟被$N扣住手腕！\n"NOR;
                        message_vision(msg, me, target);
                        me->add("force",-150);
                        target->start_busy(4+random(2));
                        me->start_busy(5+random(2));
           } else  {
                        msg = YEL"$n不退反进，长袖一圈一带，$N竟递不进招去。\n"NOR;
                        message_vision(msg,me,target);
                        me->start_busy(2);
                        }
        } else {        
                msg = HIG"$n凝神定心，无懈可击，$N一抓不中，反手向$n的$l击去。"NOR;
                me->add_temp("apply/attack",extra/3);   
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
                me->add_temp("apply/attack",-extra/3);  
                me->start_busy(1);
        }
        return 1;
}    
