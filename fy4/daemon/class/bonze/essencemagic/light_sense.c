#include <ansi.h>
inherit SSERVER;
int bbqthem(object me, object obj);
int check_legit( object ob); 
int conjure(object me, object target)
{
        int lvl,i,j,k;
        
        object env, *inv, obj;
        object *myteam;
        string id_enemy;
        
        if(me->query("class")!="bonze")
                return notify_fail("只有兴国禅寺的弟子才可以使用光识！\n");
        
        lvl = (int) me->query_skill("magic");
        lvl += (int) me->query("spi");
        if((int) me->query_skill("essencemagic",1) < 120)
                return notify_fail("你的八识神通不够高深！");
        if( me->query("atman") < 300 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 50 )
                return notify_fail("你的精不够！\n");
        me->add("atman", -300);
        me->receive_damage("gin", 50);
        message_vision(HIW "$N腾空飞起，暴喝一声．．．\n" NOR, me);
        
        env = environment(me);
        inv = all_inventory(env);
                
        if (lvl <= random(300))
        {
                for(i=0; i<sizeof(inv); i++) {
                        if (check_legit(inv[i])) continue;
                        inv[i]->kill_ob(me);
                        me->kill_ob(inv[i]);
                }
                me->start_busy(2);
                return notify_fail("你因法术不够高而失败了！\n");
        }
   
        message_vision(HIR "．．．$N全身发出炽热的血红光芒！！！\n\n" NOR, me);
        
        for(i=0; i<sizeof(inv); i++) {
                if (check_legit(inv[i])) continue;
                inv[i]->kill_ob(me);
                me->kill_ob(inv[i]);
                if (me->is_busy()) 
                        return notify_fail("你的光识被打断了！！！\n");
                bbqthem(me, inv[i]);
        }
        me->start_busy(3);
        return 1; 
} 
int check_legit(object ob) {
        object me, *team, owner;
        me=this_player();
        
        if (ob->is_corpse() || !ob->is_character() || ob==me) return 1;
        if (owner=ob->query("possessed"))
        if (owner==me) return 1;
        
        team=me->query_team();
        if (team) {
                if (member_array(ob,team)!=-1) return 1;
                if (owner=ob->query("possessed"))
                if (member_array(owner,team)!=-1) return 1;
        }
        return 0;
}
         
int bbqthem(object me, object obj)
{
        int magic;
        string id_enemy;
        magic = (int) me->query_skill("magic");
        message_vision(HIR "\n炽热的红光象利剑般射向$N，\n" NOR, obj);
        obj->receive_damage("sen", 0, me);
        
        if(obj->is_ghost()) {
                message_vision(YEL "$N惨叫了一声，化为了灰烬！\n" NOR, obj);
                obj->die();
                return 1;
        }
        if(obj->is_zombie()) {
                message_vision(YEL "$N惨叫了一声，化为了一滩血水！\n" NOR, obj);
                obj->die();
                return 1;
        }
        
        magic = 3*random(magic) + magic;
        obj->receive_damage("sen",magic,me);
        obj->set_temp("damaged_during_attack", 1);
        obj->set_temp("last_damage_from",me);
        COMBAT_D->report_status(obj);
        return 1;
}    
