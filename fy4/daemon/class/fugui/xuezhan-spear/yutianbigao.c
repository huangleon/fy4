#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        int basic;
        int i, flag;
        object weapon;
        
        extra = me->query_skill("xuezhan-spear",1);
        tmp = me->query_skill("hawk-steps",1);
        flag = 0;
        
        if ( extra < 40) 
                return notify_fail("你的血战枪法还不够纯熟！\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "hawk-steps")
                return notify_fail("［与天比高］需要［鲲鹏步法］的配和！\n");
        if ( tmp < 40 )
                return notify_fail("你的［鲲鹏步法］还不够纯熟！\n");
        
        if ( userp(me) && me->query_skill_mapped("force") != "skyforce")
                return notify_fail("［与天比高］需要［碧空心法］的配合！\n");
        
                
        basic = extra/40 + tmp/40;
        if (basic>4)
                basic=4;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［与天比高］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        msg = HIR"$N以手中"NOR+weapon->name()+HIR"点地，身形如鲲鹏展翅，一飞冲天！\n"NOR;
        message_vision(msg, me, target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
   {
                message_vision("结果$N目瞪口呆，不知如何招架！\n",target);
                target->start_busy(1);
                me->add_temp("apply/damage",extra);
                for(i=0;i<basic;i++)
                {
                        if (me->is_busy()) continue;
                        msg = HIY"长笑声中，$N凌空下击，接着又借力上跃！\n"NOR;
                        message_vision(msg, me, target);
                        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                }
                target->stop_busy();
                if (me->query_busy()<3) 
                        me->start_busy(3);
                me->add_temp("apply/damage",-extra);
        }
        else{
                message_vision("但是$N已经看破$n的攻式，$n处处受制！\n",target,me);
                me->start_busy(2);
                if (me->query("class")!="fugui"|| extra<140)
                        COMBAT_D->do_attack(target,me,target->query_temp("weapon"),TYPE_PERFORM,msg);
                
        }
        return 1;
}      
