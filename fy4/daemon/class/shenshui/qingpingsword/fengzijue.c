#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg;
        int my_exp,your_exp;
        
        if(me->query_skill("qingpingsword",1)<50)
                return notify_fail("你的清平剑法等级不够。\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「封」字诀只能对战斗中的对手使用。\n"); 
        if (target->query("step_less")==1) 
                return notify_fail(HIW"对方身势灵活，功力深湛，不会被此剑法迷惑的。\n"NOR);
        
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
        
        msg = CYN "$N"+CYN"使出清平剑法中的「封」字诀，连递数个虚招企图扰乱$n"+CYN"的攻势，";
        me->start_busy(1);
        
        my_exp = random(me->query("combat_exp")*15/4);
        your_exp = (int)target->query("combat_exp");
        
        if(me->query("class")!="shenshui") 
                my_exp= 3*random(me->query("combat_exp"));
        
        if( my_exp > your_exp) {
                msg += "结果$p"+CYN"被$P"+CYN"攻了个措手不及！\n" NOR;
        
        if (userp(me)) target->start_busy((int)me->query_skill("qingpingsword", 1) / 100 + 2);
                else target->start_busy(3);
        } else {
                msg += "可是$p"+CYN"看破了$P"+CYN"的企图，并没有上当。\n" NOR;
        }
        message_vision(msg, me, target); 
        return 1;
}      
