#include <ansi.h>
#include <combat.h>
inherit ITEM; 
void create()
{
    set_name(MAG"����������"NOR, ({ "handkerchief" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("long", "һ��ԼĪ�ĳ߼����İ׶��������Ľ��϶�����һ��컨���������Σ�ÿ��\n���Զ�����һ�Ŵ���ɫ��Ҷ�ӣ�ӭ��΢�磬��ס�ض�����shaking����\n");
                }
     setup();
} 
void init()
{
        if(this_player()==environment())
        add_action("do_shake","shaking");
} 
int do_shake(string arg)
{
        object ob;
        object me; 
        if (!arg) 
                return notify_fail("�����Ե�˭��\n"); 
        if (query("used")) 
                return notify_fail(this_object()->name()+"ֻ����һ�Ρ�\n");
        me=this_player();
        if( environment(me)->query("no_fight") ||
        environment(me)->query("no_magic") ||
        environment(me)->query("no_spells") 
        )
                return notify_fail("���ⲻ��͵Ϯ��\n");
        ob=present(arg,environment(me));
        if (!objectp(ob) || !living(ob)) 
                return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ�á�\n");
        if (!me->is_fighting(ob)) 
    message_vision(GRN"\n$N��������һ���$n���˶����е�"+this_object()->name()+GRN"��һ˿�������޵�����������...\n"NOR,me,ob);
   if ((int)me->query_cps() > random ((int)ob->query_cps()))
        {
        message_vision(MAG "\n\n$Nֻ������ǰ��ʰ�쵣�����΢����ת�˼���Ȧ�ӣ����ڵ���...\n"NOR,ob);
                ob->unconcious();
        }
        else
        {
        message_vision(CYN"\n\n$N��æ�����ڱǣ���ס��������ȥ��������...\n"NOR,ob);
        message_vision(HIR"\n$N����$n���һ���������Ķ�������֪�߳�...\n"NOR,ob,me);
                ob->kill_ob(me);
        }
        set("used",1);
        me->start_busy(3);
        return 1;
}   
