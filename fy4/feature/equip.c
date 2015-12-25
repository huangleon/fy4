 //    equip.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//              - 07/05/2001 by Daniel Q. Yu.
// 
#include <dbase.h>
#include <weapon.h> 
int wear() {
        object owner;
        mapping armor_prop, applied_prop;
        string *apply, type; 
        // Only character object can wear armors.
        if(!objectp(owner = environment()) || !owner->is_character()) {
                return 0;
        }
        
        // If already worn, just recognize it.
        if(query("equipped")) {
                return 1;
        }
        
        // Check if we have "armor_prop" defined.
        if(!mapp(armor_prop = query("armor_prop"))) {
                return notify_fail("��ֻ�ܴ����ɵ������ߵĶ�����\n");
        }
        
        // Check for armor_type
        type = query("armor_type");
        if(!stringp(type)) {
                return notify_fail("��ֻ�ܴ����ɵ������ߵĶ�����\n");
        }
        if(owner->query_temp("armor/" + type)) {
                return notify_fail("���Ѿ�������ͬ���͵Ļ����ˡ�\n");
        }
        if(type == "shield") {
                if(owner->query_temp("left_hand") && owner->query_temp("right_hand")) {
                        return notify_fail("��������ٿճ�һֻ����ʹ��������\n");
           }
                if(!objectp(owner->query_temp("left_hand"))) {
                        owner->set_temp("left_hand",this_object());
                } else if(!objectp(owner->query_temp("right_hand"))) {
                        owner->set_temp("right_hand",this_object());
                }
        }
        owner->set_temp("armor/" + type, this_object());
        
        // Add armor prop to charactor apply prop.
        apply = keys(armor_prop);
        applied_prop = owner->query_temp("apply");
        if(!mapp(applied_prop)) {
                applied_prop = ([]);
        }
        for(int i = 0; i<sizeof(apply); i++) {
                if(undefinedp(applied_prop[apply[i]])) {
                        applied_prop[apply[i]] = armor_prop[apply[i]];
                } else {
                        applied_prop[apply[i]] += armor_prop[apply[i]];
                }
        }
        owner->set_temp("apply", applied_prop);
        set("equipped", "worn");
        
        return 1;
} 
int wield() {
        object owner, old_weapon;
        mapping weapon_prop;
        string *apply, type;
        int flag; 
        // Only character object can wear armors.
        if(!(owner = environment())->is_character()) {
                return 0;
        }
        
        // If already wielded, just recognize it.
        if(query("equipped")) {
                return 1;
   }
        
        // Check if we have "weapon_prop" defined.
        if(!mapp(weapon_prop = query("weapon_prop"))) {
                return notify_fail("��ֻ��װ���ɵ��������Ķ�����\n");
        }
        
        // if both hands has something, then forget about it
        // the rule is also that primary weapon can only be in RIGHT hand
        if(owner->query_temp("left_hand") && owner->query_temp("right_hand")) {
                return notify_fail("��������ٿճ�һֻ������\n");
        }
        flag = query("flag");
        if(flag & NO_HANDED) {
                if(!(owner->query_temp("left_hand"))) {
                        owner->set_temp("left_hand", this_object());
                } else {
                        owner->set_temp("right_hand",this_object());
                }
        } else if (flag & UNARMED_TWO_HANDED) {
                if( owner->query_temp("left_hand") || owner->query_temp("right_hand")) {
                        return notify_fail("�����ճ�˫�ֲ���װ���˶�������\n");
                }
                owner->set_temp("left_hand", this_object());
                owner->set_temp("right_hand", this_object());
        } else if (flag & TWO_HANDED) {
                if( owner->query_temp("left_hand") || owner->query_temp("right_hand")) {
                        return notify_fail("�����ճ�˫�ֲ���װ��˫��������\n");
                }
                owner->set_temp("weapon", this_object());
                owner->set_temp("left_hand", this_object());
                owner->set_temp("right_hand", this_object());
        } else if ( flag & SECONDARY ) {
                if(!(owner->query_temp("right_hand"))) {
                        owner->set_temp("right_hand",this_object());
                } else {
                        owner->set_temp("left_hand",this_object());
                }
                if(!(owner->query_temp("weapon"))) {
                        owner->set_temp("weapon",this_object());
           } else {
                        owner->set_temp("secondary_weapon",this_object());
                }
        } else { //  we try to wield a single hand primary weapon
                // both hand empty
                if(!(owner->query_temp("left_hand")) && !(owner->query_temp("right_hand"))) {
                        owner->set_temp("right_hand",this_object()); owner->set_temp("weapon",this_object());
                } else {
                        if(old_weapon = owner->query_temp("right_hand")) {
                                if(!((int)old_weapon->query("flag") & SECONDARY)) {
                                        return notify_fail("������ȷ�����Ŀǰװ����������\n");
                                }
                                // do a switch
                                owner->set_temp("left_hand",old_weapon);
                                owner->set_temp("secondary_weapon",old_weapon);
                                owner->set_temp("right_hand",this_object());
                                owner->set_temp("weapon",this_object());
                        } else {
                                owner->set_temp("right_hand",this_object());
                        owner->set_temp("weapon",this_object());
                        }
                }
        } 
        apply = keys(weapon_prop);
        for(int i = 0; i<sizeof(apply); i++) 
                owner->add_temp("apply/" + apply[i], weapon_prop[apply[i]]);
        
        
        owner->reset_action();
        set("equipped", "wielded");
        return 1;
} 
int unequip() {
        object owner;
        mapping prop, applied_prop;
        string *apply, equipped; 
        if(!(owner = environment())->is_character()) {
                return 0;
        }
        
   if(!stringp(equipped = query("equipped"))) {
                return notify_fail("��Ŀǰ��û��װ������������\n");
        }
        
        if(equipped=="wielded") {
                if((object)owner->query_temp("weapon") == this_object()) {
                        owner->delete_temp("weapon");
                        if(objectp(owner->query_temp("secondary_weapon"))) {
                                owner->set_temp("weapon",(owner->query_temp("secondary_weapon")));
                                owner->delete_temp("secondary_weapon");
                         }      
                } else if((object)owner->query_temp("secondary_weapon") == this_object()) {
                        owner->delete_temp("secondary_weapon");
                }
                prop = query("weapon_prop");
                owner->reset_action();
        } else if(equipped=="worn") {
                owner->delete_temp("armor/" + query("armor_type"));
                prop = query("armor_prop");
        }
    if((object)owner->query_temp("left_hand") == this_object()) {
        owner->delete_temp("left_hand");
    }
    if ((object)owner->query_temp("right_hand") == this_object()) {
        owner->delete_temp("right_hand");
        }
        
        apply = keys(prop);
        applied_prop = owner->query_temp("apply");
        for(int i = 0; i<sizeof(apply); i++) {
                // To support array apply, we cannot add_temp() here.
                applied_prop[apply[i]] -= prop[apply[i]];
        }
        delete("equipped");
        return 1;
}  
int     selective_message(string msg,object me,object you, string flag) {
        
        string my_gender, my_name, your_name;
        string str1, str3;
   object *exclude= ({});
        int my_flag;
        int i;
                
        my_name= me->name();
        my_gender = me->query("gender");
        str1 = replace_string(msg,  "$P", gender_self(my_gender));
        str1 = replace_string(str1, "$N", gender_self(my_gender));
        str3 = replace_string(msg,  "$P", my_name);
        str3 = replace_string(str3, "$N", my_name);
        
        your_name= you->name();
        str1 = replace_string(str1, "$n", your_name);
        str3 = replace_string(str3, "$n", your_name);
        
        my_flag = me->query("env/"+flag); 
        exclude=filter_array(all_inventory(environment(me)),(: $1->query("env/"+$2)>1 :),flag); 
        exclude += ({me});
        message("vision", str3, environment(me),exclude);
        
        if (my_flag !=1 && my_flag !=3) 
                message("vision", str1, me);
//              else message("vision","\n",me);         
        return 1; 
} 
