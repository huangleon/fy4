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
                return notify_fail("ֻ����ˮ�����Ӳ���ʹ������­���ľ�����\n");
        if (me->query_skill("nine-moon-claw",1)<150)
                return notify_fail("��ģ۾����׹�צ�ݻ��������졣\n");
        if (me->query_skill("nine-moon-steps",1)<150)
                return notify_fail("��ģ۾������ݻ��������졣\n");
        if (me->query_skill("nine-moon-force",1)<150)
                return notify_fail("��ģ۾����ľ��ݻ��������졣\n");
        if (me->query_skill("nine-moon-spirit",1)<150)
                return notify_fail("��ģ��Ů�񹦣ݻ��������졣\n"); 
        if (me->query_skill_mapped("force") != "nine-moon-force")
                return notify_fail("����­����Ҫ�����ľ�����ϡ�\n");
        if (me->query_skill_mapped("dodge") != "nine-moon-steps")
                return notify_fail("����­����Ҫ����������ϡ�\n");
        
        if((int)me->query("timer/polu") + 300 > time())
         {
                return notify_fail(HIM"����­���ķ��������󣬲�������ʹ�á�\n"NOR);
                return 1;
        }
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����­��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        extra = me->query_skill("nine-moon-claw",1)*3/2+ me->query_skill("nine-moon-steps",1)/2
                + me->query_skill("nine-moon-force",1)+ me->query_skill("nine-moon-spirit",1);
        extra = extra *4;
        
   message_vision(HIW"$N�����������������䣬Ѹ���ޱȣ�����Ȱ��۵�$n��ߣ�
             ��������������֣������ָ��$n��ͷ��������ȥ��\n"NOR,me,target);
                
        if(target->query("combat_exp") < random((int)me->query("combat_exp"))*10)
        {
        message_vision(MAG"$N�ҽ�һ���������ѱ�$n��������ס��\n"NOR,target,me);
        resist=target->query("resistance/kee");
        target->set("resistance/kee",0);
        target->receive_wound("kee",extra/2+random(extra)/2);
        target->receive_damage("kee",extra/2+random(extra)/2);
        target->set("resistance/kee",resist);
        target->set_temp("last_damage_from",me);
        COMBAT_D->report_status(target);
        }
        else    message_vision(YEL"$N���Ų�æ����ǰ�벽���ܿ�������Ҫ����\n"NOR,target);
        me->set("timer/polu",time());
        me->start_busy(3);
        return 1;
}  
int help(object me)
{
        write(@HELP
ָ���ʽ : perform polu
���������ݣ������ʼ��ߵ�һ�У�Ϊ��ˮ�书��
�������ۡ���������������ȣ�ֻ������ɱ��
̫ʢ�������롰������ͬʱʹ�á� 
HELP
        );
        return 1;
}
