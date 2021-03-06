#include <ansi.h>
#include <command.h>
inherit SSERVER; 
int perform(object me, object target)
{
        string msg;
        int lvl;
        object *enemy,*enemy_here;
        
        if( !target ) target = me;
        if( target != me)
                return notify_fail("［抽身法］只能对自己使用。\n");
        
        if (me->query("force")<200)
                return notify_fail("你的内力不够。\n");
        
        enemy=me->query_enemy();
        if (enemy)      
                enemy_here=filter_array(enemy,(: environment($1)==environment($2) :),me);
        
        if (!enemy_here || !sizeof(enemy_here))
                return notify_fail("［抽身法］只能在战斗中使用。\n"); 
        if(!me->is_fighting() ) 
                return notify_fail("［抽身法］只能在战斗中使用。\n");
                        
        msg = YEL "$N虚晃一招，纵身向外跳开，企图避开敌人的攻势。。。。\n" NOR;
        lvl = (int)me->query_skill("move");
        me->add_temp("apply/move",lvl);
        message_vision(msg, me);
        GO_CMD->do_flee(me);
        me->add("force",-100);
        me->add_temp("apply/move",-lvl);
        return 1;
}        
