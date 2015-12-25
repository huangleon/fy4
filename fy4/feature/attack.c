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
static object *rival = ({});
static string *killer = ({}); 
// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob) {
        if(!ob) return sizeof(enemy) > 0;
        return member_array(ob, enemy)!=-1;
} 
// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(string id){
        if(!id) return sizeof(killer) > 0;
        return member_array(id, killer)!=-1;
} 
//This function starts fight between this_object() and ob
void fight_ob(object ob) {
        if(!ob || ob==this_object()) return;
        set_heart_beat(1);
        if( member_array(ob, enemy)==-1 )
        {
                enemy += ({ ob });
                rival  += ({ ob });
        }
} 
// This function starts killing between this_object() and ob
void kill_ob(object ob) {
                object *pros;
                int i;
                string master_id;
           object master_ob; 
        if( member_array(ob->query("id"), killer)==-1) {
                        killer += ({ ob->query("id") }); 
        }
        tell_object(ob, HIR "������"+this_object()->name() + HIR"��ɱ���㣡\n" NOR); 
        fight_ob(ob);
} 
void clean_up_enemy() {
        if(sizeof(enemy) > 0) {
                for(int i=0; i<sizeof(enemy); i++) {
                        if(!objectp(enemy[i]) || environment(enemy[i])!= environment()
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
                killer -= ({ ob->query("id") });
                rival -= ({ ob });
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
        killer = ({});
        if(!sizeof(rival)) {
                return remove_all_enemy();
        }
        for(int i=0; i<sizeof(rival); i++) {
                if(objectp(rival[i]) && rival[i]->remove_killer(this_object())) {
                        rival[i] = 0;
                }
        }
        rival -= ({ 0 });
        return remove_all_enemy();
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
                set("actions", (: call_other, SKILL_D(skill), "query_action", this_object(), ob :));
        } else {
                if(ob) {
                        set("actions", (: call_other, ob, "query_action", this_object(), ob :));
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
        if( (is_fighting()&& (string)query("attitude")!="aggressive")
                || !living(me) || !(ob) || environment(ob)!=environment()
                        || !living(ob) || ob->query("linkdead") || ob->query_temp("in_jiasi")) {
                return;
        }
        if(userp(me) || userp(ob) || !me->query_temp("is_unconcious")) {
                mark = "no_fight";
                if(userp(ob) && is_killing(ob->query("id"))) {
                        mark = "hatred";
                } else if(stringp(vendetta_mark = query("vendetta_mark"))
                                && ob->query("vendetta/" + vendetta_mark) && me->visible(ob)) {
                        mark = "vendetta";
                } else if(userp(ob) && (string)query("attitude")=="aggressive" && me->visible(ob)) {
                   mark = "aggressive";
                } else if(random((int)query("bellicosity") / 80) >
                                (int)this_object()->query_cps()) {
                        mark = "berserk";
                } else if(userp(ob) && ob->is_naked()) {
                        mark = "naked";
                }
                if(mark != "no_fight") {
                        call_out((: call_other, COMBAT_D, "auto_fight", me, ob, mark :) , random(3));
                }
        }
        return;
} 
object *query_enemy() {
        clean_up_enemy();
        return enemy;
} 
object *query_rival() {
        return rival;
} 
string *query_killer() {
        return killer;
} 
void add_rival(object ob)
{
        if(member_array(ob, rival)==-1)
                rival += ({ob});
} 
void add_enemy(object ob)
{
        if( member_array(ob, enemy)==-1)
                enemy += ({ob});
} 
void add_killer(string id)
{
        if( member_array(id, killer)==-1)
                killer += ({id});
}
