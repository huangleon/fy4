 // void_sense.c
#include <ansi.h> 
inherit SSERVER;
int conjure(object me, object target)
{
        int lvl,i,extra;
        object env, *inv;
        
//      if (me->query("class")!="ninja")
//              return notify_fail("ֻ�����߲���������.\n");
        
        if(me->query_temp("ninjitsu_durup")) return notify_fail("�������Ѿ����ھ���ļ��ȿ���״̬�ˡ�\n");
        
        lvl = (int) me->query_skill("magic");
                
        if ( (int) me->query_skill("ninjitsu",1) <= 50)
                return notify_fail("�����������ߣ�\n");
        if( target != me ) 
                return notify_fail("��ֻ�������Լ������ϡ�\n");        
            
        if( me->query("atman") < 300 )
                return notify_fail("�������������\n");
        if( me->query("gin") <= 250 )
                return notify_fail("��ľ�������\n");
        me->add("atman", -300);
        me->receive_damage("gin", 250);
        
        extra=lvl/2;
        me->add_temp("apply/durability",extra);
        me->set_temp("ninjitsu_durup",1);
        me->set_temp("mark/no_uncon",1);
        message_vision(HIM "$N���۹������룬�ƺ��Ѿ���һ��ǿ��ľ������������ƣ�����\n" NOR, me);
            
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me ,extra:), lvl/10);
        if( me->is_fighting() ) me->start_busy(2);
        return 1; 
}
void remove_effect(object me,int extra)
{
        me->add_temp("apply/durability", - extra);
        me->delete_temp("ninjitsu_durup");
        me->delete_temp("mark/no_uncon");
        message_vision(HIW"$N������ָ������������Ѿ��ص�������״̬��\n"NOR,me);
        
}     
