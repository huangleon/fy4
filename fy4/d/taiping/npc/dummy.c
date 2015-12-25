#include <ansi.h>
#include <command.h>
inherit "/d/taiping/npc/smart_npc"; 
int call_guard(); 
void create()
{ 
        set_name("����",({"wuyan"}));
        set("long", "���ƹ������Ա��\n");
        set("title", "ɱ�˲�գ��");
        set("nickname", "ɱɱɱ");
        set("age",40);
        
        set("group","test");
        set("combat_exp", 8000000);
        set("gender","����");   
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        set("str",40);
        
        set("max_force",1200);
        set("force",1200);
        set("force_factor",133);
        set("reward_npc", 1);
        set("difficulty", 3); 
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
        ]));
                
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",1);  
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
   
        set("win_msg",CYN"$N��Цһ����������ȥ���͵���������\n"NOR);
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
             // 10:     "\n"+name()+"�ȵ������˷��ˣ���Ȼ��ɱ�ٲ����\n",
             // 100:    (: call_guard() :),
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(100) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "����˵����ɱɱɱ����\n",
        }) );  
        
        auto_npc_setup("wang",300,160,1,"/obj/weapon/","fighter_w","model",1);
        setup();
        carry_object(__DIR__"obj/o_cloth")->wear();
//      carry_object(__DIR__"obj/sspear")->wield();
        carry_object("obj/weapon/sword");
        carry_object("obj/weapon/whip");
        carry_object("obj/weapon/hammer");
}  
int call_guard() { 
        int oldbusy;
        
        if (this_object()->query_temp("guard_count")<4
                && this_object()->query("class")=="official") {
                if (this_object()->query("npc")=="yue-spear2")
                        this_object()->set("family/master_id","master yue");
                this_object()->set_skill("strategy",200);
                this_object()->set_skill("leadership",250);
                oldbusy=this_object()->query_busy();
                this_object()->stop_busy();
                perform_action("unarmed.npc_alert");
                this_object()->start_busy(oldbusy);
        }
        return 1;
}  
void die(){
        object ob=this_object();
        object owner,winner, *enemy,*temp_team,*win_team;
        int en_exp,ob_exp,i,num;
        int base_exp,base_pot,my_exp,my_pot;
        string reward_msg;
        
        
        base_exp=1000;
        base_pot=500; 
//      decides whether we need a winner. rival means anyone who ever kills me
        enemy=query_rival();
        i=sizeof(enemy);
        if (i) {
                while(i--)
                if( enemy[i]->query("combat_exp")>en_exp) {
                        en_exp=enemy[i]->query("combat_exp");
                        num=i;
                }
        }
        ob_exp=query("combat_exp");
        
//      only give reward if you are <120% NPC exp       
        if (en_exp<=ob_exp*6/5) {
                
//      decides who deals the most damage.      
                winner=query_max_damage();
                if(owner=winner->query("possessed"))    
                        winner = owner;
                if (winner)
                        tell_object(winner,HIW" your team wins, baby. \n"NOR);
                
//      get the winner's group and reward them
                temp_team=winner->query_team();
                if (temp_team && sizeof(temp_team)>1) {
                        win_team=filter_array(temp_team,(: environment($1)==environment($2) :),ob);
                        num=sizeof(win_team);
                }       else num=1;
                my_exp=base_exp/num+1;
                my_pot=base_pot/num+1;
           reward_msg = HIW+"������˵���ս�У���õ��ˣ�\n\t" +
                                        chinese_number(my_exp) + "��ʵս����\n\t"+
                                        chinese_number(my_pot) + "��Ǳ��\n\t" +
                                        chinese_number(1) + "������\n" + NOR;
                tell_object(winner,reward_msg);                 
                if (num>1){
                        reward_msg =HIW+"����"+winner->name()+"�������ս�У���õ��ˣ�\n\t" +
                                        chinese_number(my_exp) + "��ʵս����\n\t"+
                                        chinese_number(my_pot) + "��Ǳ��\n\t" +
                                        chinese_number(1) + "������\n" + NOR;
                        while(num--){
                                if (win_team[num]==winner) continue;
                                win_team[num]->add("potential",my_pot);
                                win_team[num]->add("combat_exp",my_exp);
                                tell_object(win_team[num],reward_msg);
                        }
                }
        }
        ::die();
}  
        
        
        
        
        
