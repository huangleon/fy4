#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,mystr,yourstr,lvl;
        object weapon; 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷�����ӿ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = target->query_temp("weapon");
        if(!objectp(weapon)) return notify_fail("��Ķ���û���ñ�����\n");
        myexp = (int) me->query("combat_exp") / 1000;
        mystr = (int) me->query_str();
        yourexp = (int) target->query("combat_exp") / 1000;
        yourstr = (int) target->query_str();
        lvl = (int) me->query_skill("sword") / 10 + 1;
        msg = YEL "$N˫��һ�ӣ�$n�ı�����֪��ô�������˵��£� \n" NOR;
if(objectp(weapon) )
{
        if( random(myexp * lvl * mystr) > (yourexp * yourstr) )
        {
                weapon->unequip();              
                weapon->move(environment(target));
                message_vision(msg, me, target);
                target->start_busy(2);
        }
        else 
        {
                COMBAT_D->do_attack(target,me, TYPE_PERFORM);
        }
                me->start_busy(2);
}
        return 1;
}      
