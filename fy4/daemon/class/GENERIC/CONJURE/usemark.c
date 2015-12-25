 // drift_sense.c
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
        string roomname;
        object room;
        int skill,atman;
        if( me->is_fighting() )
                return notify_fail("ս�����޷�ʹ���ɷ���\n");
        if( (atman=me->query("atman")) < 50 )
                return notify_fail("�������������\n");
        if( me->query("gin") <= 100 )
                return notify_fail("��ľ�������\n");
        if( me->is_ghost())
                return notify_fail("����޷�ʹ���ɷ���\n");     
        if( (skill=me->query_skill("incarnation",1)) < 155 )
        return notify_fail("����������������\n");
        if( !(roomname=me->query_temp("timespacemark")))
                return notify_fail("��û���趨���ꡣ\n");
        if( time()>me->query_temp("timespacemark_time"))
                return notify_fail("���趨�ĵ����Ѿ�ʧЧ�ˡ�\n");
        
        if(environment(me)->query("no_death_penalty") || environment(me)->query("no_fly"))
                return notify_fail("�˵ز���ʹ��ʱ��ת����\n");
        
        me->add("atman", -50);
        me->receive_damage("gin", 100);
        if( random(atman/5+(skill-90)/2+180) <100)
                {
                 message_vision( HIY "$N��ָ����������Ĭ���ʲô��Ҳû������\n" NOR, me);
                 return notify_fail("��ģ�ʱ�յ���ݻ�����������\n");  
                }
        message_vision( HIY "$N��ָ����������Ĭ���Ȼ����һ��������ʧ�� ....\n" NOR, me);
        room = load_object(roomname);
        me->move(room);
        message( "vision", HIY "\n��Ȼһ�����̴ӵ���ð����"+me->query("name")+"�������г��֣�\n\n" NOR,
                room, ({ me }) );
        return 1;
}  
