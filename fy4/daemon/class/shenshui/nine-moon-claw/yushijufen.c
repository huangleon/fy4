#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
    string msg; 
    if( !target ) target = offensive_target(me); 
    if(me->query("class")!="shen_shui")
          return notify_fail("ֻ�����ӻ��˵���ˮ�����Ӳ���ʹ������ʯ��١��ľ�����\n"); 
    
    // pls apply exp check here, only allow to use on exp higher than urself
    if(!me->query_condition("tianyi"))
        return notify_fail("����ʯ��١�����Ҫ������һ��ˮ�Ķ��Բ���ʹ�ã���\n");
    if( !target ||!target->is_character()|| !me->is_fighting(target) )
        return notify_fail("����ʯ��١�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    
    //if(  )
    //    return notify_fail("����ʯ��١�ֻ�ܶ��������ʹ�á�\n"); 
    if( me->query_skill("nine-moon-force",1) < 150)
        return notify_fail("��ľ����ľ�������������\n"); 
    msg = RED
        "$N�����������������Ҫ����ͬ���ھ�����˵�������Ѫ��˲ʱ�����Ϊ֮��ɫ��\n";
    if(me->query("combat_exp") > random(target->query("combat_exp")/10) )
    {
        msg += "�����أ�$n��һƬ��ɫ��Ѫ���Χ��ʲô���������ˣ�\n"NOR;
        //target->receive_damage("kee",(int)me->query("max_kee")+1,me);
        //receive_wound("kee", ((int)me->query("max_kee")+5000),me);
        message_vision(msg, me, target);
        target->die();
        me->die();
        me->set_skill("nine-moon-force",random(150));
    }
    else
    {
        msg += "����$n���Ƕ����$N�����һ������"
            "$n�����ƺ�������һ�㵭��������ɫ��\n" NOR;
        message_vision(msg, me, target);
        target->apply_condition("tianyi",100);
        me->unconcious();
    }
    
    return 1;
}    
