 // This software can not be used, copied, or modified in any form without
// the written permission from authors.
// created by suu for flower delivery Nov/2/2001 
#include <ansi.h> 
int flower_delivery_reward(object me, object who) {
        mapping delivery;
        int exp,pot;
        object flower,coin;
        flower = this_object();
        if(!mapp(delivery = flower->query("delivery"))) return 0;
        if(base_name(who) != delivery["receiver"]) return 0;
        
        switch (random(3))
        {
        case 0:
                message_vision("$N�˷ܵؾ���һ������������������ô�� ��\n",who);
                break;
        case 1:
                message_vision("$N����ض�$nһЦ��\n",who,me);
                break;
        case 2:
                message_vision("$N���洺�磬Ц��ӯӯ��������$n���������Ǹ���ģ��������ˡ���\n",who,me );
                coin = new("/obj/money/coin");
                coin->set_amount(random(100)+100);
                coin->move(me);
                tell_object(me,who->name()+"�ݸ���һЩǮ��\n");
                break;
        }
        pot = random(10);
        exp = 10+random(10);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        tell_object(me,"�㱻�����ˣ�\n" + chinese_number(exp) + "��ʵս����\n"
                        + chinese_number(pot) + "��Ǳ��\n");
        me->delete("delivery");
        me->delete("delivery_time");
        /*
        if(!undefinedp(quest["fin_func"])) {
                call_other(this_object(),quest["fin_func"],me,who,quest_item);
        }*/
   if(flower) {
                destruct(flower);
        }
        return 1;
}  
/*void wither()
{
        if (query("delivery"))
        {
                set("name","��ή��"+name());
                set("long","��ԭ����һ��"+query("long")+"���������Ѿ���ή�ˡ�\n");
                delete("delivery");
        }
}*/
