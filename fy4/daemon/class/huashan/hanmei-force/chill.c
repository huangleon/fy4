#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int exert(object me, object target)
{
        object wp,weapon;
        int extra, myexp,yourexp, i;
        int base;
        string msg, skill;
        object  *enemy; 
        
        if (me->query("class") != "huashan") 
                return notify_fail("只有华山弟子可以使用「寒霜凝梅」。\n");
        extra = me->query_skill("hanmei-force", 1);
        if(extra < 50) 
                return notify_fail("你的寒梅心法不够纯熟，无法使用［寒霜凝梅］。\n");
        if( !me->is_fighting() )
                return notify_fail("［寒霜凝梅］只能在战斗中使用。\n");
        if( !target ) target = offensive_target(me);
        if(me->query_temp("ninjitsu_berserk")) 
                return notify_fail("使用忍术时不能使用攻击性特殊技能。\n");
        if( (int)me->query("force") < 200 )
                return notify_fail("你的内力不够。\n");
        
        if (me->query("force_factor")<40) me->add("force", -20);
        wp = me->query_temp("weapon");
        myexp = me->query("combat_exp");
        yourexp = target->query("combat_exp");  
        if (extra>100) base = extra;
        if (extra>150) base = extra*3/2; 
        skill = objectp(weapon = me->query_temp("weapon")) ? weapon->query("skill_type") : "unarmed";
        skill = me->query_skill_mapped(skill);
        if (!skill || SKILL_D(skill)->skill_class()!="huashan") {
                extra = extra/2;
                base = 0;
        }
        
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra + base);
         
   enemy = me->query_enemy(); 
        if(!wp){
                message_vision(HIW"$N内力凝聚，手上似罩了一层寒霜。\n$N双掌泛白，轻飘飘拍出，似乎并没有什么目标。\n"NOR, me);
                
        } else {
                message_vision(HIW"$N"NOR+HIW"内力凝聚，一层寒霜罩在了手中的"+ wp->name()+HIW"上。\n"NOR+HIW"$N"+HIW"手中挂满了白霜的" + wp->name() + HIW"划出了一道弯曲的曲线。\n", me); 
        } 
        
        for (i = 0 ; i< sizeof(enemy); i++) {   
                if( enemy[i]&& enemy[i]->is_character()
                        && me->is_fighting(enemy[i]) )
                
                {       target = enemy[i];
                        if(!wp){
                                msg = HIW "$n不由自主打了一个寒战。\n" NOR;
                        } else {
                                msg = HIW + wp->name() + HIW"散出的缕缕白气围上了$n！\n" NOR;
                        }
        
                        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        
                        if(extra > 150 &&  target->query_temp("damaged_during_attack") 
                                && !target->is_busy()) target->start_busy(1);
                }
        }                                
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -(extra + base));      
        if (me->query_busy()<2) 
                me->start_busy(2); 
        return 1;
}    
