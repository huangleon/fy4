#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int extradam;
        object corp,new1,room;
        if(me->query("class")!="yinshi")
                return notify_fail("ֻ�е����ȵ��Ӳ����½�ͷ��\n");
        if( !target ) target = offensive_target(me); 
        if((int)me->query_skill("cursism") < 120 )
                return notify_fail("��Ľ�ͷ�������ߣ�\n"); 
        if( !target
        || !target->is_ghost()
        ||      target==me
        ||  userp(target) )
                return notify_fail("��ֻ�ܶԹ���������ͷ��\n");
        room=environment(target); 
        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ������\n");
        if(!corp = present("corpse",environment(me)))
                return notify_fail("�����Χû��ʬ�壡\n");
        if( target->query("combat_exp") > 3 * me->query("combat_exp"))
                return notify_fail("��ĵľ��鲻���Կ���"+target->name()+"��\n");
        
        me->receive_wound("kee", 100);
        msg = HIC "$N��ն���$n��㼸�£�$n������վ��������\n\n" NOR;
        message_vision(msg,me,corp);
        destruct(corp);
        target->be_ghost(0);
        target->set("title",HIB"��ʬ����"NOR);
        extradam = (int) target->query("combat_exp");
        target->set("combat_exp",  extradam/2); 
        
        msg = HIC "$n��$N����������ë���Ȼ��Ц���������ˣ���ʲô�Ը���������\n\n" NOR;
        message_vision(msg,me,target);
        
        target->set("possessed",me);
        target->set("acc_cmd",me);
   target->set_leader(me);
        me->start_busy(2);
        return 1;
}     
