#include <combat.h>
#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIY"�廨��"NOR, ({ "iron-bow" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������������;͵��廨�񹭣���˵�е��廨���ֻ�к����\n����ϣ�install���ž������������� \n");
                set("installed", 0);
        }
} 
void init()
{
        if(this_player()==environment())
        add_action("do_install","install");
        add_action("do_shoot","shoot");
} 
int do_install()
{
        int i,arrower=0;
        object me, *inv;
        object arrow;
        me = this_player();
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
                if(inv[i]->query("name") == RED"��"BLU"��"HIG"���"NOR) 
                {
                        arrower = 1; 
                        arrow = inv[i];
                }
        }
        if( arrower )
        {
                destruct(arrow);
        message_vision(CYN "$N��"+this_object()->name()+CYN"�ϴ���һ֧�廨�����\n"NOR,this_player());
           set("installed",1);
                return 1;
        }
        else 
                message_vision("$N����������"+this_object()->name()+"������û�м���\n",this_player());
                return 1;
} 
int do_shoot(string arg)
{
        object ob;
        object me;
        int dpme,dpob;
        int damage;
        if (!arg) return notify_fail("��Ҫ��˭��\n");
        if (!query("installed")) 
                return notify_fail(this_object()->name()+"����װ����û�а취����ġ�\n");
        me=this_player();
        if( environment(me)->query("no_fight") ||
                environment(me)->query("no_magic") ||
                environment(me)->query("no_spells"))
                return notify_fail("���ⲻ��͵Ϯ��\n");
        ob=present(arg,environment(me));
        if (!objectp(ob) || !living(ob)) 
                return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ�á�\n");
    message_vision(CYN"\n$N��Ц���У�������������"+this_object()->name()+CYN"�������£�����\n\n",me);
    message_vision(CYN"\n$N���һ����"+RED"�填"BLU"����"HIG"�񡫼�����"NOR+"������\n",me);
    message_vision(HIR"\n��"+this_object()->name()+HIR"�����һƬ���⣬��ͷ�û��廨����������$N������\n\n",ob);
        dpob=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
        dpme=COMBAT_D->skill_power(me, SKILL_USAGE_DODGE);
        damage=150000-dpob+dpme;
    damage/=200;
        if (damage<0) damage=0;
        if( random(me->query("combat_exp")) > (int)ob->query("combat_exp")/50 )
        {
        message_vision(HIR"$Nֻ������ǰ������˸��һʱ֮�侹�޴Ӷ�����\n"NOR,ob);
                ob->start_busy(3);
        message_vision(HIR"\n�������������$N�����壮����\n" NOR,ob);
                ob->receive_wound("kee",damage,me);
                COMBAT_D->report_status(ob);
                me->start_busy(5);
   }
        else
        {
                message_vision(HIR"��������У�$N�ƺ�����һ˿����������\n"NOR,ob);
                message_vision(HIW"$N�͵�һ�������ն��"+RED"��"BLU"��"HIG"���"HIW+"��Ϯ��������\n"NOR,ob);
                me->start_busy(3);
        }
        ob->kill_ob(me); 
        set("installed",0);
        return 1;
}     
