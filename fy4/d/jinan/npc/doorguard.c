#include <ansi.h> 
inherit NPC;
int give_guard();
void create()
{
        set_name("殷羡", ({ "yinxian" }) );
        set("long",
                "一个锦衣华服的带刀侍卫，也是钦差大人殷正廉的远方侄儿。
殷大人命其负责济南府众侍卫调度,朝廷将领可向他征召护卫(guard).\n"); 
        set("attitude", "heroism");
        set("title", "朝廷命官 四品带刀侍卫");
        set("vendetta_mark","authority");
        set("reward_npc", 1);
        set("difficulty", 10); 
        set("cor", 26);
        set("cps", 55); 
        set("combat_exp", 5000000); 
        set_skill("unarmed", 150+random(500));
        set_skill("blade", 100+random(500));
        set_skill("parry", 100+random(500));
        set_skill("dodge", 100+random(500));
        set_skill("move", 100+random(500));
        set_skill("shortsong-blade",150);
        set_skill("fall-steps",150); 
        map_skill("parry","shortsong-blade");
        map_skill("blade","shortsong-blade");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps"); 
        set_temp("apply/damage", 200+random(200));
        set_temp("apply/armor", 200); 
        set("chat_chance", 1);
        set("chat_msg", ({
"殷羡眼睛里闪着光，苦笑道：后天便是叶孤城与西门吹雪决战紫禁城之\n日。哎！可殷大人却丢了尚方宝剑，实在又离开不得。。。\n"
        }) ); 
        set("inquiry"   ,       ([
                "护卫"  : (:give_guard:),
                "guard" : (:give_guard:),
                "huwei" : (:give_guard:),
                "shiwei" : (:give_guard:),
                ]) );
    setup(); 
        carry_object(__DIR__"obj/yafu")->wear();
    carry_object(__DIR__"obj/peidao")->wield();
} 
int give_guard()
{
        object me,shiwei;
        int extra,maximum,gcount,gcount1,i,j;
        
        me=this_player();
        
        if(me->query("class")!="official")
        {
                message_vision("殷羡对$N说道：“你算什么东西，有什么资格要护卫？”\n",me);
                return 1;
        }
        
        if (me->query_skill("strategy",1)<100
                || me->query_skill("leadership",1)<100) {
                message_vision("殷羡叹了口气：“近来盗匪横行，兵源不够了。”\n",me);
                message_vision("殷羡对$N说道：“抱歉，护卫得留给更大的官儿了。”\n",me);
                return 1;
        }       
                
        extra=me->query_skill("strategy",1)*me->query_skill("strategy",1);
        maximum = me->query_skill("leadership",1);
        maximum = maximum/50-1;
        if (maximum <1) maximum =0;
              
        gcount=me->query_temp("guard_count");
        if(gcount>=maximum)
        {
                message_vision("殷羡对$N说道：“朝廷的典制，你不可以指挥再多兵士了。”\n",me);
                return 1;
        } 
        if(me->query("family/master_id")!="master yue"&& me->query("marks/shiwei")+600>time()) {
                message_vision("殷羡对$N说道：“你对手下太不爱惜了,我都来不及训练了.”\n",me);
                message_vision("殷羡说：“过一会儿再来要护卫吧.”\n",me);
                return 1;
        } 
  gcount1=maximum-gcount;
        me->set("marks/shiwei",time());
        for(i=0;i<gcount1;i++)
        {
                if(me->query("sen")<150) 
                {
                        tell_object(me,"你的神不够，无法指挥再多兵士了。\n");
                        break;
                }
                if (me->query("family/master_id")=="master yue") {
                        if (extra>48400) extra=48400;
                        shiwei=new("/obj/npc/fighter1");
                        shiwei->invocation(me,extra/100);
                        shiwei->move(environment());
                        if (me->query("combat_exp")>2700000) {
                        if (shiwei->query("combat_exp")>me->query("combat_exp")*4/5)    
                                shiwei->set("combat_exp",me->query("combat_exp")*4/5);
                        }
                        message_vision("殷羡对$N说道：“好好跟着"+me->query("name")+"将军干，报效朝廷。”\n",shiwei);
                } else
                {
                        if (extra>40000) extra=40000;
                        shiwei=new("/obj/npc/shiwei");
                        shiwei->invocation(me,extra/100);
                        shiwei->move(environment());
                        j=8-(me->query_skill("leadership",1)-100)/20;
                        shiwei->set("title", "朝廷 "+chinese_number(j)+"品带刀侍卫");
                        if (me->query("combat_exp")>2700000) {
                        if (shiwei->query("combat_exp")>me->query("combat_exp")*4/5)    
                                shiwei->set("combat_exp",me->query("combat_exp")*4/5);
                        }
                        message_vision("殷羡对$N说道：“好好跟着"+me->query("name")+"将军干，有你的好处。”\n",shiwei);
                }
                                
                me->add_temp("guard_count",1);
                me->add("sen",-50);
        }
        return 1;
}   
