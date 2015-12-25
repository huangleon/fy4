 // flowerowner.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// created by suu for flower delivery Oct/29/2001 
#include <ansi.h>
#include <dbase.h> 
string *delivery_list = ({
"��Ѱ��:/d/songshan/npc/bu_waiter",
"������:/d/jinan/npc/surong",
"½С��:/d/yingou/npc/leng",
"�����:/d/yingou/npc/fangyuxiang",
"���ִ���:/d/fy/npc/bookgirl",
"���С��:/d/fugui/npc/tianxin",
"������:/d/fugui/npc/clothlady",
"�����๫:/d/fugui/npc/beauty",
"������:/d/jinan/npc/songtian",
"��ԭһ���:/d/guanyin/npc/qu",
"С��:/d/guanwai/npc/sunshine",
"С��:/d/guanwai/npc/qi",
"չ�ΰ�:/d/palace/npc/feiyu",
"����:/d/palace/npc/manfeng",
"������:/d/huashan/npc/jin",
"����:/d/huashan/npc/linger",
"������:/d/huashan/npc/gao",
"��ʮһ��:/d/huangshan/npc/feng",
"̫����:/d/huangshan/npc/yan",
"��ʮһ��:/d/huangshan/npc/bing",
"��ʮһ��:/d/taishan/npc/shenbijun",
}); 
string wait_period(int timep); 
string get_flower()
{
        //get flower from the vendor list
        int i;
        mapping goods;
        string *names;
        if( !mapp(goods = query("vendor_goods")) )      return "";
        names = keys(goods);
        if (!sizeof(names))
   {
                //should we give out a default flower or don't let them deliver?
                return "";              // no more delivery
        }
        i = sizeof(names);
        return names[random(i)];
} 
mapping query_delivery()
{
        int i;
        string *delivery;
        i = sizeof(delivery_list);
        delivery = explode(delivery_list[random(i)],":");
        return (["sender": delivery[0],
                        "receiver": delivery[1],
                        ]);
}  
int assign_delivery()
{
        mapping delivery;
    string dstr;
        object who,flower,silver;
    who = this_player();
        if (who->query("combat_exp") >= 10000 )
        {
                message_vision("$N�ϻ̳Ͽֶ�$n��������ô��������ݡ���\n",this_object(),who );
                return 1;
        }
        if (who->query("KILLED") >= 20 )
        {
                message_vision("$N������һ���������"+RANK_D->query_respect(who)+"СС��ͣ���ôӡ�÷��ڣ���\n",this_object(),who );
                message_vision("$Nҡҡͷ˵�������������������ͻ������㲻�ʺϸɡ���\n",this_object());
                return 1;
        }
        
         
        if(who->is_ghost() || who->is_zombie()) {
                tell_object(who,this_object()->name()+"���������ǲ�Ҫ����ͻ�����\n");
                return 1;
        } 
   if((delivery =  who->query("delivery")) && (time() - who->query("delivery_time") <= 600)) {
                return 0;
        }
        //delivery unfinished and back to ask again in 10 mins
        if ((delivery =  who->query("delivery")) && (time() - who->query("delivery_time"))<= 1200)
        {
                tell_object(who,HIW"��Ҫ��" 
                                +  QUESTS_D->wait_period(1200-time()+who->query("delivery_time")) 
                                + "֮��ſɼ����ͻ���\n"NOR);
                return 1;
        }
        //delivery cancled by player
        if ((!delivery =  who->query("delivery")) && ((who->query("next_delivery_time")) > time()))
        {
                tell_object(who,HIW"��Ҫ��" 
                                +  QUESTS_D->wait_period(who->query("next_delivery_time") - time()) 
                                + "֮��ſɼ����ͻ���\n"NOR);
                return 1;
        } 
        silver=present("silver_money", who);
    if(!silver) 
        {
                tell_object(who,"������û���㹻�����Ӹ�����ѽ��\n");
                return 1;
        }
    if (silver->query_amount()<1)
        {
                tell_object(who,"������û���㹻�����Ӹ�����ѽ��\n");
                return 1;
        }
    silver->add_amount(-1); 
        delivery = query_delivery();
        flower = new(get_flower());
        if (!flower) {
                message_vision("$Nҡҡͷ˵��������Ļ����͹��ˡ���\n",this_object());
                return 1;
        } 
        //flower->set("sender",delivery["sender"]);
        //flower->set("receiver",delivery["receiver"]);
        flower->set("delivery",delivery);
   flower->wither();
        if (flower->move(who))
        {
                who->set("delivery", delivery);
                flower->set("delivery_time", (int)time());      
                who->set("delivery_time", (int)time()); 
                dstr = "������" + delivery["sender"] + "�����͸�"+  delivery["receiver"]->name(1) + "С��Ļ�������ȥ�ٻء���\n";
                message_vision("$NС������ݸ�$nһ��"+flower->name()+"����\n" + dstr,this_object(),who); 
        }
        return 1;
} 
int cancel_delivery(string arg)
{
        object who;
        who = this_player();
        if (arg != "delivery" && arg != "�ͻ�")
        {
                return 0;
        }
        if(  who->query("delivery") && (time() - who->query("delivery_time") < 600))
        {
                who->delete("delivery");
                who->delete("delivery_time");
                tell_object(who, this_object()->name() + "˵�����ðɣ�����ͻ���������˰ɣ���\n");
                who->set("next_delivery_time", time() + random(300));
                return 1;
        }else if (!who->query("delivery"))
        {
                return notify_fail("������û���κ��ͻ�����\n");
        }else
        {
                return notify_fail("���Ѵ����һ�����񡣵���һ���ɡ�\n");
        }
} 
int give_deposit()
{
        int amount;
        object silver,me;
        me = this_player();
        amount = me->query("delivery/success");
   if (amount>=1)
        {
                silver = new("/obj/money/silver");
                silver->set_amount(amount);
                message_vision("$N��$n�������������ȫ��Ѻ�𡣡�\n",this_object(),me);
                silver->move(me);
                me->set("delivery/success",0);
                return 1;
        }
        message_vision("$N��$n�������㲢û��Ѻ�����������\n",this_object(),me);
        return 1; 
} 
/* 
the code which player place reservation
not in use right now
int book_flowers(string arg)
{
        string starget,sflower;
        object target,flower,who;
        mapping goods,userdelivery;
        string *names,flowerlist;
        who = this_player();
        flowerlist = "";
        if (!arg || sscanf(arg, "%s %s", starget,sflower) != 2 ) 
        {
                return notify_fail("�����ʽ:book ���ID ����ID\n");
        }       
        if (sizeof(user_reservation_list)>=20)
        {
                return notify_fail("���궩�����������ڽ����µĶ�����\n");
        } 
        if (!target = find_player(starget))
        {
                return notify_fail("��ֻ��Ԥ������������ҡ�\n");
        }
        if( mapp(goods = query("vendor_goods")) ) 
        {
                names = keys(goods);
                if (sizeof(names)) 
                {
                   for (int i=0;i<sizeof(names);i++ )
                        { 
                                flowerlist = flowerlist + names[i]->name() + "("+names[i]->query("id")+")"+"\n";
                                if ( names[i]->query("id") == sflower )
                                {
                                        userdelivery = (["sender": who->name(1),
                                                "receiver": target->query("id"),
                                                "flower":names[i],
                                        ]);
                                        user_reservation_list = user_reservation_list + ({userdelivery});
                                        message_vision("$NԤ����һ֧"+names[i]->name()+"��"+target->name(1)+"\n",who);
                                        return 1;
                                        
                                }
                        }
                }
        } 
        if (flowerlist == "")
        {
                return notify_fail("����Ļ��������ˡ�\n");
        }
        tell_object(who,"������ֻ��Ԥ�����л���\n"+flowerlist);
        return 1; 
}
*/
