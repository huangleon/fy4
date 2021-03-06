#include <ansi.h>
#include <combat.h>
inherit SSERVER;
string single_perform(object target, object me, int myexp, int skill); 
int perform(object me, object target)
{
        string msg;
        int myexp, ownexp, ownskill;
        int skill, gin_cost, i, extra, boosted;
        string *style = ({
        HIY"［休门］－ $N身影从滚滚风沙中现出，攻向$n的$l！"NOR,
        HIG"［生门］－ $N招式连绵不绝，如江涛起浪将$n迫得喘不过气来！"NOR,
        RED"［伤门］－ $N在剑鼓交鸣的巨响中向$n猛扑过去！"NOR,
        CYN"［杜门］－ $N欺身急进，气势如十万甲兵卷地而来！"NOR,
        HIM"［景门］－ $N手中暗蓄内力，一团紫气隐隐点向$n的$l！"NOR,
        HIB"［死门］－ $N随着阵内的杀气冲天而起，身形闪动攻向$n！"NOR,
        HIC"［惊门］－ $N手一扬，一股强大的震流，如电击一般飞向$n的$l！"NOR,
        WHT"［开门］－ $N如迅雷乍现，急取$n的$l！"NOR});
        object ob,*obs,*myteam,*env; 
        skill = (int) me->query_skill("five-steps",1);
        gin_cost = (int)me->query_int() + 45;
        if ((string)me->query("class") != "wudang")
                return notify_fail(WHT"你不是武当弟子，不能演变「八阵图」。\n"NOR); 
        if( !skill || (skill < 100))
                return notify_fail(WHT"你的五行身法不够精深, 不能演变「八阵图」！\n"NOR);
        
        if( me->is_fighting() ) {
                myexp = (int) me->query("combat_exp");
                if( !target ) target = offensive_target(me);
                if( !target
                        || !target->is_character()
                        || !me->is_fighting(target) )
                return notify_fail("「八阵图」只能对战斗中的对手展开。\n"); 
       /*Single player perform*/
        if (!me->query_team()) { 
                single_perform(target, me, myexp, skill);
                return 1;
                }
                
        if (member_array(target,myteam=me->query_team())!=-1) 
           return notify_fail("你不能攻击队友。\n"); 
//      Here is the checking to excluding all that not satisfy the condition.   
        obs = ({});
        env=all_inventory(environment(me));
        for (i=0;i<sizeof(env);i++) {
                if (member_array(env[i],myteam)==-1) continue;
                if (env[i]->is_busy()) continue;
                if (!env[i]->query_skill("five-steps")) continue;
                if (env[i]->query_skill_mapped("dodge") != "five-steps"
                        && env[i]->query_skill_mapped("move") != "five-steps")  continue;
                if (env[i]->query_skill("five-steps",1)<120) continue;
                obs += ({ env[i] });
                if (sizeof(obs)>=8) break;
        }
         
        if (sizeof(obs)<2) {
                single_perform(target, me, myexp, skill);
                return 1;
        } 
                /* team perform*/
                else { 
//===============Team==================================================
                        if(skill<160) {
                                single_perform(target, me, myexp, skill);
//                              return notify_fail(WHT"你对「八阵图」的理解不足以发动阵法！\n"NOR);
                                return 1;
                        }
                        
                        // confirm everyone using five-steps
                        if(sizeof(obs) > 8 ) {
                                single_perform(target, me, myexp, skill);
                                return notify_fail("「八阵图」阵法最多八个人！！\n");
                        }
                        
                        myexp =0;
                        extra=0;
                        
                        for(i=0;i<sizeof(obs);i++)
                        {
                                myexp += (int) obs[i]->query("combat_exp");
                           extra += (int) obs[i]->query_skill("five-steps");
                        }
                        ownskill=me->query_skill("five-steps");
                        ownexp=me->query("combat_exp");
                                
                        message_vision(MAG"\n只见$N"NOR MAG"五行身法一变，阵中诸人竟按遁甲"YEL" 休、生、伤、杜、景、死、惊、开"MAG" 部好位置，衍出"WHT"「八阵图」"MAG"！\n"NOR, me);
                        if ( random(myexp)*5/i + ownexp/2 > (int) target->query("combat_exp") ){
                                msg = HIR"$N只觉森森杀气直透心头。惟见怪石磋峨，槎丫似剑，横沙立土，重叠如山。\n一时心胆皆寒，寸步难移！\n\n"NOR;
                                if (target->query_busy()<=2) target->start_busy(2);
                                target->receive_damage("sen", ownskill + 3*random(extra)/i ,me);
                        }
                        else{
                                msg = HIW"\n$N脚踏生门，左转右闪抵挡「八阵图」的围困。\n"NOR;
                        }
                        extra = extra/i ;       
                        message_vision(msg, target);
                        
                        for(i=0;i<sizeof(obs);i++)
                        {
                                msg = HIR +  style[i] + NOR;
                                obs[i]->add_temp("apply/attack", extra/2);
                                obs[i]->add_temp("apply/damage", extra);
                                COMBAT_D->do_attack(obs[i],target, TYPE_PERFORM,msg);
                                obs[i]->kill_ob(target);        
                                obs[i]->add_temp("apply/attack", -extra/2);
                                obs[i]->add_temp("apply/damage", -extra);
                                obs[i]->start_busy(3);
                        }
                        return 1; 
//===============End Team==================================================
                }
        }
        else {
                if( (int)me->query("force") < 70 )
                        return notify_fail("你的内力不够，没有力气演练「八阵图」！\n");
                if( (int)me->query("gin") < gin_cost )
                        return notify_fail("你现在无法集中精神演练「八阵图」！\n"); 
                msg = MAG"$N身形展开，试图将"HIY" 金 "HIG"木 "HIC" 水 "HIR" 火 "NOR YEL" 土 "MAG"五行步法变幻融入古阵法「八阵图」中。\n" NOR;
                message_vision(msg, me);
                me->start_busy(random(3)+1);
           if (skill*skill*skill*3/5>me->query("combat_exp"))
                        return notify_fail(WHT"你的实战经验还不够进一步领悟「八阵图」。\n"NOR);
                if (skill>=200 || skill>=200-me->query("betrayer")*20) 
                        return notify_fail(WHT"你已经不能通过演变身法来进一步领悟「八阵图」了！\n"NOR);
                me->add("force", -70);
                me->add("gin", -gin_cost);
                me->improve_skill("five-steps",  random((int)me->query_int()) + 1);
                return 1;
        }
} 
string single_perform(object target, object me, int myexp, int skill) {
                string msg = MAG"\n只见$N"NOR MAG"五行身法一变，竟按遁甲"YEL" 休、生、伤、杜、景、死、惊、开"MAG" 衍出"WHT"「八阵图」"MAG"！\n"NOR;
                msg += WHT"\n霎时间狂风大作，飞沙走石，遮天盖地。$n只觉涛声浪涌，有如剑鼓之声！\n"NOR;
                if ( skill*(random(myexp)/40) + (myexp/2) > (int) target->query("combat_exp") ){
                        msg+= HIR"森森杀气直透$n心头，惟见怪石磋峨，槎丫似剑，横沙立土，重叠如山。\n$n一时心胆皆寒，寸步难移！\n\n"NOR;
                                if (target->query_busy()<2) target->start_busy(2);
                                if (target->query("no_busy")) me->start_busy(2);
                                        else me->start_busy(3);
                                target->receive_wound("sen",5*random(skill)/2, me);
                                target->receive_damage("sen", skill*5/2,me);         
//                      average 750, lowest 500, highest 1000                           
                                message_vision(msg, me, target);
                                COMBAT_D->report_status(target);
                                COMBAT_D->win_lose_check(me,target,1);
                }
                else {
                        msg+= HIW"\n$n脚踏生门，左转右转脱离了「八阵图」的围困。\n"NOR;
                        me->start_busy(2);
                        message_vision(msg, me, target);
                }                
}
                            
