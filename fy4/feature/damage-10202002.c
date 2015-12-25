 // damage.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
// Last modification:
//              - 06/28/2001 by Daniel Q. Yu.
// 
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h> 
int ghost = 0; 
int is_ghost() { return ghost; } 
//Added by tie to deal with attribute damages boots
varargs int attr_change(string type, int change, object who)
{
    int val; 
    if( type!="strength" && type!="courage" && type!="intelligence" &&
        type!="spirituality" && type!="composure" && type!="personality" &&
        type!="constitution" && type!="karma" && type!="agility" &&
        type!="durability" && type!="flexibility" && type!="tolerance" ) 
        error("F_DAMAGE: �˺��������( ֻ���� strength,courage,intelligence,spirituality,composure,personality,
constitution,karma,agility,durability,flexibility,tolerance����֮һ )��\n"); 
    if( objectp(who) ) set_temp("last_attr_from", who);
    val = (int)query("attr_apply/"+type) +change; 
    set("attr_apply/"+type, val);
    set_heart_beat(1);
    return change;
} 
varargs int receive_damage(string type, int damage, object who)
{
    int val;
    int reduction; 
//  if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
    if (damage <0) damage =0;
    if( type!="gin" && type!="kee" && type!="sen" )
        error("F_DAMAGE: �˺��������( ֻ���� gin, kee, sen ����֮һ )��\n"); 
    if (query("resistance/"+type) || query_temp("resistance/"+type)){
                reduction=query("resistance/"+type) + query_temp("resistance/"+type);
           damage=damage-damage*reduction/100;
        } 
    if( objectp(who) ) set_temp("last_damage_from", who);
    val = (int)query(type) - damage; 
    set(type, val);
    set_heart_beat(1);
    return damage;
} 
varargs int receive_wound(string type, int damage, object who)
{
    int val,reduction; 
//  if( damage < 0 ) error("F_DAMAGE: �˺�ֵΪ��ֵ��\n");
    if (damage <0) damage =0;
    if( type!="gin" && type!="kee" && type!="sen" )
        error("F_DAMAGE: �˺��������( ֻ���� gin, kee, sen ����֮һ )��\n"); 
    if (query("resistance/"+type) || query_temp("resistance/"+type)){
                reduction=query("resistance/"+type) + query_temp("resistance/"+type);
                damage=damage-damage*reduction/100;
        } 
    if( objectp(who) ) set_temp("last_damage_from", who);
    val = (int)query("eff_" + type) - damage; 
    set("eff_" + type, val);
    if( (int)query(type) > val ) set(type, val);
    set_heart_beat(1);
    return damage;
} 
int receive_heal(string type, int heal)
{
    int val; 
    if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
    if( type!="gin" && type!="kee" && type!="sen" )
        error("F_DAMAGE: �ָ��������( ֻ���� gin, kee, sen ����֮һ )��\n"); 
    val = (int)query(type) + heal;
    if( val > (int)query("eff_" + type)) {
        set(type, (int)query("eff_" + type));
    } else {
        set( type, val );
    } 
    return heal;
} 
int receive_curing(string type, int heal) {
    int max, val; 
    if( heal < 0 ) error("F_DAMAGE: �ָ�ֵΪ��ֵ��\n");
    if( type!="gin" && type!="kee" && type!="sen" )
        error("F_DAMAGE: �ָ��������( ֻ���� gin, kee, sen ����֮һ )��\n"); 
    val = (int)query("eff_" + type);
    max = (int)query("max_" + type); 
    if( val + heal > max ) {
        set("eff_" + type, max);
        return max - val;
    } else {
        set( "eff_" + type, val + heal);
        return heal;
    }
} 
void unconcious()
{
    object defeater; 
    if( !living(this_object()) ) return;
    //if(query_temp("unconsious")
    if( wizardp(this_object()) && query("env/immortal") ) return;
// set the unconcious flag
    if(this_object()->query_temp("is_unconcious")) return;
    this_object()->set_temp("is_unconcious",1);
    if( objectp(defeater = query_temp("last_damage_from")) )
        COMBAT_D->winner_reward(defeater, this_object());
    COMBAT_D->loser_penalty(defeater, this_object());
    if( ! this_object()->query("possessed"))
        this_object()->remove_all_enemy(); 
    message("system", HIR "\n�����ǰһ�ڣ�����ʲ��Ҳ��֪����....\n\n" NOR,
            this_object());
    this_object()->disable_player(" <���Բ���>");
    set("gin", 0);
    set("kee", 0);
    set("sen", 0);
    set_temp("block_msg/all", 1);
    COMBAT_D->announce(this_object(), "unconcious");
    if(this_object()->query_temp("mark/no_uncon")) call_out("revive",1);
    else call_out("revive", random(50 - (int) this_object()->query_con()) + 10);
}  
varargs void revive(int quiet)
{
    remove_call_out("revive");
// unset unconcious flag
    this_object()->delete_temp("is_unconcious");
    while( environment()->is_character() )
        this_object()->move(environment(environment()));
    if( (int) this_object()->query("gin") < 0 ) this_object()->set("gin",0);
    if( (int) this_object()->query("kee") < 0 ) this_object()->set("kee",0);
    if( (int) this_object()->query("sen") < 0 ) this_object()->set("sen",0);
    if( !quiet )
    {
        COMBAT_D->announce(this_object(), "revive");
        message("system", HIY "\n�����������������֪��....\n\n" NOR,
                this_object());
    }
    set_temp("block_msg/all", 0);
    this_object()->enable_player();
}  
void be_ghost(int flag)
{
    ghost = flag;
}  
varargs void die(int flag) {
    object corpse, trap_room,me, *inv;
    mixed killer;
    int i, j,fate;
    string special_death_place; 
    if(this_object()->query_temp("is_unconcious")) revive(1);
    //if( !living(this_object()) ) revive(1);
    if( wizardp(this_object()) && query("env/immortal") ) return; 
    // here add for the usage of lifesave potion
    if((time()-this_object()->query("timer/lifesave"))<(3600+this_object()->query_skill("herb")*12))//�������Сʱ
    {
        me = this_object();
        fate=me->query("����B/��ɽ_����")+me->query("����B/��ɽ_���")+me->query("����B/��ɽ_�ճ�")-me->query("����B/��Դ����")-me->query("����B/̩ɽ_�ճ�");
        //�����30����С��-20
        //�������������ô˥����-20��fate�ɣ�����Ҳû����
        //�����Իָ�1/2����Ѫ
        if(fate+20>random(100))
           {
                message_vision("\n$Nǿ��һ�����������Ϸ���һ˿��⣬�ƺ��ֳ�����������\n",this_object());
                set("gin", me->query("max_gin")/100*(fate+20));
                set("eff_gin", me->query("max_gin")/100*(fate+20));
                set("kee", me->query("max_kee")/100*(fate+20));
                set("eff_kee", me->query("max_kee")/100*(fate+20));
                set("sen", me->query("max_sen")/100*(fate+20));
                set("eff_sen", me->query("max_sen")/100*(fate+20));
                return;
        } 
    } 
    // added for eren2 special death setup.
    if( objectp(killer = query_temp("last_damage_from")) && userp(this_object()) ) {
    if (special_death_place=killer->query("dungeon_npc")) {
                        if (special_death_place="eren2"
                                && domain_file(file_name(environment(this_object())))=="eren2"){
                                trap_room = find_object(AREA_EREN2"underjail1");
                                if(!objectp(trap_room))
                                        trap_room = load_object(AREA_EREN2"underjail1");
                                if (!random(3) && environment(this_object())!= trap_room) {
                                        me = this_object();
                                        message_vision("\n$Nһͷ�Ե��ڵ��ϣ����Թ�ȥ��\n",this_object());
                                        message("vision", "�ڰ���������ѹ���ǹ����"+this_object()->query("name")+"������ȥ��\n"NOR, environment(me));
                                        tell_object(me,"���Ժ�����������Լ����ӵ���һ������\n\n");
                                        me->move(trap_room);
                                        set("gin", me->query("max_gin")/2);
                                        set("eff_gin", me->query("max_gin")/2);
                                        set("kee", me->query("max_kee")/2);
                                        set("eff_kee", me->query("max_kee")/2);
                                        set("sen", me->query("max_sen")/2);
                                        set("eff_sen", me->query("max_sen")/2);
//                                      me->unconcious();
                                        return;
                                }
                        }
                }
        } 
    // Clear all the conditions by death.
    this_object()->clear_all_condition();
    this_object()->delete_temp("block_msg/all"); 
    // Clear all attribute changes by death.
    this_object()->delete("attr_apply"); 
     // remove all wearing items to clear mask-related identity problem.
    inv = all_inventory(this_object());
                for(j=0; j<sizeof(inv); j++)
                        inv[j]->unequip(); 
    COMBAT_D->announce(this_object(), "dead");
    if( objectp(killer = query_temp("last_damage_from")) ) {
        set_temp("my_killer", killer->query("id"));
        set_temp("my_killer_name", killer->query("name"));
        COMBAT_D->killer_reward(killer, this_object());
    }
    if(!flag)
        COMBAT_D->victim_penalty(this_object(), killer);
    else
        COMBAT_D->victim_penalty(this_object(), killer,flag);
    if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
        corpse->move(environment()); 
    this_object()->remove_all_killer();
    all_inventory(environment())->remove_killer(this_object());  
         // added for eren2 special death setup.
    if( objectp(killer = query_temp("last_damage_from")) && userp(this_object())) {
    if (special_death_place=killer->query("dungeon_npc")) {
                        if (special_death_place="eren2"
                                && domain_file(file_name(environment(this_object())))=="eren2"){
                                trap_room = find_object(AREA_EREN"chunliuju1");
                                if(!objectp(trap_room))
                                        trap_room = load_object(AREA_EREN"chunliuju1");
                                this_object()->move(trap_room);
                                this_object()->set_temp("chunliu_wakeup",1);
                                me=this_object();
                                set("gin", 0);
                                set("eff_gin", me->query("max_gin"));
                                set("kee", 0);
                                set("eff_kee", me->query("max_kee"));
                                set("sen", 0);
                                set("eff_sen", me->query("max_sen"));
                                this_object()->unconcious();
                                this_object()->save();
                                return;
                   }
                }
        } 
        this_object()->dismiss_team();
        if(userp(this_object()) ) {  
                if(this_object()->query_temp("no_death_penalty"))
                {
                    //akuma changes here:
                    //for no_death_penalty player, we dont want him to study by get half gin kee sen
                    //so we change it to 1 1 1 :)
                    //on 2002-10-08
                        set("eff_gin",query("max_gin"));
                        set("eff_kee",query("max_kee"));
                        set("eff_sen",query("max_sen"));
                        if(query("combat_exp")<750000)//guyupai requirement
                        {
                                set("gin",1);
                                set("kee",1);
                                set("sen",1);
                        }
                        else
                        {
                                set("gin",query("max_gin")/2);
                                set("kee",query("max_kee")/2);
                                set("sen",query("max_sen")/2);
                        } 
                        this_object()->move("/d/fy/church");
                        this_object()->delete_temp("no_death_penalty");
                }else
                {
                        set("gin", 1);  set("eff_gin", 1);
                        set("kee", 1);  set("eff_kee", 1);
                        set("sen", 1);  set("eff_sen", 1);
                        ghost = 1;
                        this_object()->move(DEATH_ROOM);
                        DEATH_ROOM->start_death(this_object());
                }
                this_object()->save();  
        } else
                        destruct(this_object());
} 
void reincarnate()
{
    ghost = 0;
    set("eff_gin", query("max_gin"));
    set("eff_kee", query("max_kee"));
    set("eff_sen", query("max_sen"));
} 
int max_food_capacity() { return query_weight() / 200; } 
int max_water_capacity() { return query_weight() / 200; } 
int calc_heal_up(string val, int change, mapping my)
{
        int update_flag=0; 
        if(my[val] > my["eff_"+val]) {
                my[val]-=change;
                if(my[val] < my["eff_"+val] ) {
                        my[val]=my["eff_"+val];
                }
                update_flag++;
        } else {
                my[val]+=change;
                if(my[val] > my["eff_"+val] ) {
                        my[val]=my["eff_"+val];
                        if( my["eff_"+val] < my["max_"+val] ){
                                my["eff_"+val]++;
                                update_flag++;
                        }
                }
        }
        return update_flag;
} 
int heal_up() {
    int update_flag, i;
    mapping my; 
        // can't heal while fighting.
    if( this_object()->is_fighting() ) {
        return -1;
    } 
    // Da zuo will increase the heal points by 2x
    update_flag = 0;
    if (this_object()->query_temp("in_dazuo")) i = 2;
    else i = 1; 
    my = query_entire_dbase(); 
        // Decrease water and food, and if they are zero, can't heal.
    if( my["water"] > 0 ) { my["water"] -= 1; update_flag++; }
    if( my["food"] > 0 ) { my["food"] -= 1; update_flag++; } 
    if( my["water"] < 1 && userp(this_object()) ) return update_flag;
    if( my["food"] < 1 && userp(this_object()) ) return update_flag; 
        // Heal points calcuated base on the spi and atman/force/mana
    update_flag+=calc_heal_up("gin",(my["spi"]  + my["atman"] / 10) * i +1,my);
    update_flag+=calc_heal_up("kee",(my["con"]  + my["force"] / 10) * i +1,my);
    update_flag+=calc_heal_up("sen",(my["int"]  + my["mana"] / 10) * i +1,my); 
    if( my["max_atman"] && my["atman"] < my["max_atman"] ) {
        my["atman"] += ((int)this_object()->query_skill("magic", 1) / 2) * i;
        if( my["atman"] > my["max_atman"] ) my["atman"] = my["max_atman"];
        update_flag++;
    } 
    if( my["max_force"] && my["force"] < my["max_force"] ) {
        my["force"] += ((int)this_object()->query_skill("force", 1) / 2) * i;
        if( my["force"] > my["max_force"] ) my["force"] = my["max_force"];
        update_flag++;
    } 
    if( my["max_mana"] && my["mana"] < my["max_mana"] ) {
        my["mana"] += ((int)this_object()->query_skill("spells", 1) / 2) * i;
        if( my["mana"] > my["max_mana"] ) my["mana"] = my["max_mana"];
        update_flag++;
    }
    return update_flag;
} 
void check_status()
{
        mapping my;
        my=query_entire_dbase();
        if( my["eff_kee"] < 0
         || my["eff_sen"] < 0
         || my["eff_gin"] < 0
         || my["kee"] < -10 * my["dur"]
         || my["sen"] < -10 * my["dur"]
         || my["gin"] < -10 * my["dur"])
        {
                this_object()->remove_all_enemy();
                die();
                return;
        }
        if( my["kee"] < 0 || my["sen"] < 0 || my["gin"] < 0) {
                this_object()->remove_all_enemy();
                unconcious();
                return;
        } 
}
