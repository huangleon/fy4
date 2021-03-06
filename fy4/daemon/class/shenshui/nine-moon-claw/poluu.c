 // silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg;
        int extra;
        int resist;
        if(me->query("class")!="shenshui")
                return notify_fail("只有神水宫弟子才能使出「破颅」的绝技。\n");
        if (me->query_skill("nine-moon-claw",1)<150)
                return notify_fail("你的［九阴白骨爪］还不够纯熟。\n");
        if (me->query_skill("nine-moon-steps",1)<150)
                return notify_fail("你的［九阴身法］还不够纯熟。\n");
        if (me->query_skill("nine-moon-force",1)<150)
                return notify_fail("你的［九阴心经］还不够纯熟。\n");
        if (me->query_skill("nine-moon-spirit",1)<150)
                return notify_fail("你的［姹女神功］还不够纯熟。\n"); 
        if (me->query_skill_mapped("force") != "nine-moon-force")
                return notify_fail("「破颅」需要九阴心经的配合。\n");
        if (me->query_skill_mapped("dodge") != "nine-moon-steps")
                return notify_fail("「破颅」需要九阴身法的配合。\n");
        
        if((int)me->query("timer/polu") + 300 > time())
         {
                return notify_fail(HIM"「破颅」耗费体力极大，不能连续使用。\n"NOR);
                return 1;
        }
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［破颅］只能对战斗中的对手使用。\n");
        
        extra = me->query_skill("nine-moon-claw",1)*3/2+ me->query_skill("nine-moon-steps",1)/2
                + me->query_skill("nine-moon-force",1)+ me->query_skill("nine-moon-spirit",1);
        extra = extra *4;
        
   message_vision(HIW"$N身形闪动，兔起鹘落，迅捷无比，如鬼魅般欺到$n身边，
             袖中伸出纤纤素手，五根手指向$n的头顶插了下去。\n"NOR,me,target);
                
        if(target->query("combat_exp") < random((int)me->query("combat_exp"))*10)
        {
        message_vision(MAG"$N惨叫一声，顶门已被$n的手掌罩住！\n"NOR,target,me);
        resist=target->query("resistance/kee");
        target->set("resistance/kee",0);
        target->receive_wound("kee",extra/2+random(extra)/2);
        target->receive_damage("kee",extra/2+random(extra)/2);
        target->set("resistance/kee",resist);
        target->set_temp("last_damage_from",me);
        COMBAT_D->report_status(target);
        }
        else    message_vision(YEL"$N不慌不忙，抢前半步，避开了脑门要害。\n"NOR,target);
        me->set("timer/polu",time());
        me->start_busy(3);
        return 1;
}  
int help(object me)
{
        write(@HELP
指令格式 : perform polu
极毒，极狠，命中率极高的一招，为神水武功的
精华所聚。出招如鬼，收招似魅，只是由于杀气
太盛，不能与“假死“同时使用。 
HELP
        );
        return 1;
}
