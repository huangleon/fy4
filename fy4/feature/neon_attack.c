 // attack.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//  
#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h> 
static int attackTick = 0;
static int Max_Action_Count = 4;
static int actionCount = 0;
static object *enemy = ({});
static string *killer_user = ({});
static object *killer_npc = ({}); 
// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob) {
        if(!ob) return sizeof(enemy) > 0;
        return member_array(ob, enemy)!=-1;
} 
// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(string id){ 
        if(!id) return sizeof(killer_user) > 0;
        if (member_array(id, killer_user)!=-1) return 1;
        
        if (sizeof(killer_npc)<1) return 0;
        if (sizeof(killer_npc)==1 && (!killer_npc[0])) return 0; 
        for(int i=0; i<sizeof(killer_npc); i++) {
            if( id == killer_npc[i]->query("id")) return 1;
        }
        return 0;
} 
//This function starts fight between this_object() and ob
void fight_ob(object ob) {
        if(!ob || ob==this_object()) return;
        set_heart_beat(1);
        if( member_array(ob, enemy)==-1 ) 
                enemy += ({ ob });
} 
// This function starts killing between this_object() and ob
void kill_ob(object ob) {
        object *pros;
    if(!ob || ob==this_object()) return;
    if (userp(ob)) {
            if( member_array(ob->query("id"), killer_user)==-1)                 
                    killer_user += ({ ob->query("id") });
    }
    else {
        if( member_array(ob, killer_npc)==-1)           
                    killer_npc += ({ ob });
        }
        tell_object(ob, HIR "������" + this_object()->name() + "��ɱ���㣡\n" NOR);
        fight_ob(ob);
} 
void clean_up_enemy() { 
        if(sizeof(enemy) > 0) {
                for(int i=0; i<sizeof(enemy); i++) {
                        if(!objectp(enemy[i]) || environment(enemy[i])!=environment()
                                        || (!living(enemy[i]) && !is_killing(enemy[i]->query("id")))) {
                                enemy[i] = 0;
                        }
                }
                enemy -= ({ 0 });
        }
} 
// This function checks if the current opponent is available or
// select a new one.
object select_opponent() {
        if(!sizeof(enemy)) {
                return 0;
        }
        clean_up_enemy();
        if(!sizeof(enemy)) {
                return 0;
        }       
        return enemy[random(sizeof(enemy))];
} 
// Stop fighting ob.
int remove_enemy(object ob) {
        if(is_killing(ob->query("id"))) {
           return 0;
        }
        enemy -= ({ ob });
        return 1;
} 
// Stop killing ob.
int remove_killer(object ob) {
        if(is_killing(ob->query("id"))) {
                killer_npc -= ({ ob });
                killer_user -= ({ ob->query("id")});
        }
        return remove_enemy(ob);
} 
// Stop all fighting, but killer remains.
void remove_all_enemy() {
        if(!sizeof(enemy)) {
                return;
        }
        for(int i=0; i<sizeof(enemy); i++) {
                if(objectp(enemy[i]) && enemy[i]->remove_enemy(this_object())) {
                        enemy[i] = 0;
                }
        }
        enemy -= ({ 0 });
} 
// Stop all fighting and killing.
void remove_all_killer() {
        if((!sizeof(killer_npc))&&(!sizeof(killer_user))) {
                return;
        }
        for(int i=0; i<sizeof(killer_npc); i++) {
                if(objectp(killer_npc[i]) && killer_npc[i]->remove_killer(this_object())) {
                        killer_npc[i] = 0;
                }
        }
    killer_npc -= ({});
//      for(int i=0; i<sizeof(killer_user); i++) {
//              if(objectp(killer_user[i]) && killer_user[i]->remove_killer(this_object())) {
//                      killer_user[i] = 0;
//              }
// }
//
    killer_user = ({});
      
        if(!sizeof(enemy)) {
                return;
        } 
        for(int i=0; i<sizeof(enemy); i++) {
                if(objectp(enemy[i]) && enemy[i]->remove_enemy(this_object())) {
                        enemy[i] = 0;
                }
        }
        enemy -= ({ 0 });
} 
// reset_action()
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
void reset_action() {
        object ob;
        string type, skill;
        
        if(ob = query_temp("weapon")) {
                type = ob->query("skill_type");
        } else if(ob = query_temp("secondary_weapon")) {
                type = ob->query("skill_type");
        } else {
                type = "unarmed";
        } 
        if(stringp(skill = query_skill_mapped(type))) {
                set("actions", (: call_other, SKILL_D(skill), "query_action" :));
        } else {
                if(ob) {
                        set("actions", (: call_other, ob, "query_action" :));
                } else {
                        set("actions", query("default_actions",1) );
                }
        }
} 
void reset_action_count() {
        int level;
   
        level = this_object()->query_skill("move");
        Max_Action_Count = 4 + level/100;
        actionCount = 0;
} 
int increase_action(int num) {
        Max_Action_Count += num;        
        return Max_Action_Count;
} 
// This is called in heart_beat() to perform attack action.
int attack() {
        object opponent;
/*      
        if(attackTick > 0) {
                attackTick--;
        } else {
*/
                opponent = select_opponent();
                if(objectp(opponent)) {
//                      attackTick = (int)((30 - this_object()->query_agi()) / 5);
//                      reset_action_count();   
                        set_temp("last_opponent", opponent);
                        COMBAT_D->fight(this_object(), opponent);
                        return 1;
                } else {
//                      attackTick = 0;
                        return 0;
                }
/*      }
        return 0;
*/
} 
int actionOK() {
        actionCount++;
        if(actionCount <= Max_Action_Count) {
                return 1;
        }
        return 0;       
} 
//
// init() - called by MudOS when another object is moved to us.
//
void init() {
        object ob, me;
        string vendetta_mark, mark; 
        me = this_object();
        ob = this_player();
        
        // We check these conditions here prior to handle auto fights. Although
        // most of these conditions are checked again in COMBAT_D's auto_fight()
        // function, these check reduces lots of possible failure in the call_out
        // launched by auto_fight() and saves some overhead.
        if(is_fighting() || !living(me) || !(ob) || environment(ob)!=environment() 
                        || !living(ob) || ob->query("linkdead")) {
                return;
        }       
        if(userp(me) || userp(ob) || !me->query_temp("is_unconcious")) {
                mark = "no_fight";              
                if(userp(ob) && is_killing(ob->query("id")) 
                                && !query("vendetta_mark")) {
                        mark = "hatred";
                } else if(stringp(vendetta_mark = query("vendetta_mark")) 
                                && ob->query("vendetta/" + vendetta_mark) ) {
                        mark = "vendetta";
                } else if(userp(ob) && (string)query("attitude")=="aggressive" ) {
                        mark = "aggressive";
                } else if(random((int)query("bellicosity") / 40) > 
                                (int)this_object()->query_cps() ) {
                        mark = "berserk";
                } else if(userp(ob) && ob->is_naked()) {
                        mark = "naked";
                }
                if(mark != "no_fight") {
                        call_out((: call_other, COMBAT_D, "auto_fight", me, ob, mark :) , random(10));
                }
        }
        return;
} 
object *query_enemy() {
        clean_up_enemy(); 
   return enemy; 
} 
string *query_killer() { 
        
        if (sizeof(killer_npc)<1) return killer_user;
        if (sizeof(killer_npc)==1 && (!killer_npc[0])) return killer_user;
        for(int i=0; i<sizeof(killer_npc); i++) {
            killer_user += ({ killer_npc[i]->query("id") });
        }
        
        return killer_user; 
}       
