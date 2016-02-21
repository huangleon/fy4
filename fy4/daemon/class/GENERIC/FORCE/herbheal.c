#include <ansi.h>
int exert(object me, object target, int amount)
{
        int extra;
        
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n"); 
        extra = me->query_skill("herb",1);
        
        if(extra < 100 )
                return notify_fail("你的药道还不够高深。\n"); 
        if(me->query("force")<500)
                return notify_fail("你的真气不够。\n");
                
        write( HIG "你全身放松，坐下来开始将真气在经脉中缓缓流动。\n" NOR);
        
        message("vision",
                HIG + me->name() + 
"坐下来运起药道心法疗伤，头上冒出缕缕白气，不久，吐出一口瘀血，脸色看起来好多了。\n" 
NOR,
                environment(me), me); 
        me->receive_curing("gin",200+(extra-100)*2);
        me->receive_curing("sen",200+(extra-100)*2);
        me->receive_curing("kee", 2000);
        
        me->add("force", -500);
        me->set("force_factor", 0);
        me->start_busy(2);
        
        return 1;
}
  
