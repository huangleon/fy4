 inherit NPC;
#include <ansi.h> 
int growup(); 
void create()
{
        set_name("蚩尤", ({ "chi you", "chiyou" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 10000);
        set("long", "蚩尤，与黄帝涿鹿中原的一代大神，鬓如剑戟，头有利角，铜头铁额，诛杀 
无道，乃古往今来睥睨天下之第一凶魔！\n");
        set("title", "不世战神");
        set("nickname", HIR"万古凶魔"NOR);
        set("str", 50);
        set("cor", 100);
        set("per", 1);
        set("int", 100);
        set("fle", 200);
        set("boss",1);
        set("big_boss",1);
        set("max_kee", 500000);
        set("max_gin", 500000);
        set("max_sen", 500000);
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "爪子" }) );
        set("verbs", ({ "bite", "claw" }) );
        
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: growup() :),
        }) ); 
        
        set_skill("unarmed", 800);
        set_skill("iron-cloth", 500);
        set_skill("yiqiforce", 100);
        set_skill("dodge", 400);
        set_skill("parry", 400);
        set_skill("perception",400);
        map_skill("unarmed","yiqiforce");
        
   set("combat_exp", 25000000);
                
        set_temp("apply/attack", 200);
        set_temp("apply/dodge", 200);
        set_temp("apply/damage",200);
        set_temp("apply/armor", 300);
        setup(); 
} 
void init() {
        ::init();
        add_action("do_kneel", "kneel");
        add_action("do_reject", "reject");
}  
int growup() {
        int time;
        if (time()>this_object()->query("time")+2700 && this_object()->query("str")<90) {
                this_object()->set("str",90);
                message_vision(CYN"\n$N仰天发出令人心胆俱裂的震天怒吼，山石雨下，乌云翻滚！\n"NOR, this_object()); 
        }
                else if (time()>this_object()->query("time")+1800 && this_object()->query("str")<75) {
                        this_object()->set("str",75);
                        message_vision(HIR"\n$N仰天发出令人心胆俱裂的震天怒吼，山石雨下，乌云翻滚！\n"NOR, this_object()); 
        }
        return 1;
}  
void chiyou_call(object ob){
        if(ob->query("marks/wolfmount_chiyou_kneel")){
                message_vision(CYN"$N仰天发出令人心胆俱裂的震天怒吼，山石雨下，乌云翻滚！\n"NOR, this_object()); 
                message_vision(CYN"万道血光之间，乌云突然裂开道长缝，$N那庞大身躯冲上云霄。。。\n"NOR, this_object());
                message_vision(CYN"四下归于死一般的寂静。。\n"NOR, this_object());
                destruct(this_object());
        } else { 
                message_vision(HIG"$N仰天发出令人心胆俱裂的震天怒吼，山石雨下，乌云翻滚！\n"NOR, this_object()); 
                message_vision(RED"\n$N微微低首，散发着无穷杀机的血色赤眸盯着$n一字字道：蚩尤重生，君临天下！\n"NOR, this_object(),ob); 
                message_vision(RED"汝等怯懦人兽，还不匍地臣服！（kneel or reject）\n"NOR, this_object()); 
        }
} 
int do_kneel(){
        object me;
        me = this_player();
   tell_object(me, YEL"你只觉身陷无边的火海和恐惧之中，双膝一弯，五体匍地，诚惶诚恐膜拜道：\n"NOR); 
        tell_object(me, YEL"战神重生，君临天下！\n"NOR);
        message("vision", YEL""+me->name() + "双膝一弯，五体匍地，诚惶诚恐膜拜道：战神重生，君临天下！\n"NOR,
                        environment(me), me);
        if(query("busy") || this_object()->is_fighting()){
                return notify_fail(WHT"蚩尤似乎正在忙而没有时间理你。\n"NOR);
        }
/*      if(me->query("class") == "wolfmount"){
                message_vision(RED"\n$N血眸精光四射，狂笑半晌道：不错，某先去天界找那轩辕帝出出这万世不得\n"NOR, this_object()); 
                message_vision(RED"翻身的晦气。汝不妨觅得我再世传人－－太阳使者，拜他为师，嘿～，轩辕老鬼！\n"NOR, this_object()); 
                message_vision(RED"万道血光之间，乌云突然裂开道长缝，蚩尤那庞大身躯冲上云霄。。。\n"NOR, this_object()); 
                message_vision(RED"四下归于死一般的寂静。。 \n"NOR, this_object());
                me->add("score", -2000);
                me->set("title", "狼山 "+ HIR"蚩尤传人"NOR);
                me->set("marks/狼山_拜太阳使者", 1);
        } else { */
                message_vision(RED"\n$N血眸精光四射，狂笑半晌道：不错，某先去天界找那轩辕帝出出这万世不得\n"NOR,this_object()); 
                message_vision(RED"翻身的晦气。嘿～，轩辕老鬼！ 万道血光之间，乌云突然裂开道长缝，蚩尤那庞\n"NOR, this_object()); 
                message_vision(RED"大身躯冲上云霄。。。 四下归于死一般的寂静。。\n", this_object()); 
                me->add("score", -1000);
//      }       
//      me->set("marks/wolfmount_chiyou_kneel", 1);
// --------- sun legate's skill not finished, therefore the code is disabled here -- silencer 1/21/2002
        destruct(this_object());
        return 1;
} 
int do_reject(){
        object me;
        me = this_player();
        set("busy", 1);
        message_vision(HIG"$N弹衣而起，仰天长笑道：纵使血溅于此，万劫不复，也绝不屈膝半寸！\n"NOR, me); 
        message_vision(HIR"\n$N双眸血光暴起，喝道：顺我者昌，逆我者～～亡～！\n"NOR, this_object()); 
        me->kill_ob(this_object());
        this_object()->kill_ob(me);
        return 1;
}  
void die(){
        object me,staff;
        object owner,room;
        
   room=find_object(AREA_WOLFMOUNT"cliffroad3");
        if (!objectp(room)) room=load_object(AREA_WOLFMOUNT"cliffroad3");
        
        room->set("count",0);
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if (me)
        if(!me->query("m_success/蚩尤")){
                me->set("m_success/蚩尤",1);
                me->add("score",5000);
                me->add("potential", 20000);
                me->add("combat_exp", 100000);
        }
        message_vision(HIR"\n$N嘶叫道：“可恶的。。。。我会再回来的。”"NOR, this_object());
        message_vision(HIR"$N那庞大身躯突然化为一股浓烟消失不见了。\n"NOR, this_object());
        if (me) 
        CHANNEL_D->do_sys_channel("info",sprintf("%s，%s于蚩尤秘窟击杀蚩尤。", NATURE_D->game_time(),me->query("name")) ); 
        
        seteuid(getuid());
        switch (random(5)) {
                case 0: staff=new(__DIR__"obj/putistaff");
                        staff->move(environment(this_object()));
                        break;
                case 1: staff=new(__DIR__"obj/tigersoul");
                        staff->move(environment(this_object()));
                        break;
                case 2: staff=new(__DIR__"obj/skull_whip");
                        staff->move(environment(this_object()));
                        break;
                case 3: staff=new(__DIR__"obj/shield");
                        staff->move(environment(this_object()));
                        break;
                default: staff=new(__DIR__"obj/wolf-fist");
                        staff->move(environment(this_object()));
                        break;
        }
        destruct(this_object());
}  
