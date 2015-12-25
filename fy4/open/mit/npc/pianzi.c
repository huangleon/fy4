#include <login.h>
#include <ansi.h> 
inherit NPC;
object player;
// Whether playing with a player
int in_game;
#define NP 5
int* p=({0,0,0,0,0});
// Whether the question was answered correctly
int right;
string pile="�������������";
string cnum="�٢ڢۢܢݢޢߢ���"; 
void start_game();
int show();
void ctake();
void take(object who, int which, int howmany)
{
    p[which]-=howmany;
    message_vision("$N�ӵ�"+chinese_number(which+1)+
                   "����������"+chinese_number(howmany)+"��Сʯ�ӡ�\n",who);
    show();
}  
void start_game()
{
    int i,sum=0;
    in_game=1;
    for(i=0;i<NP-1;i++)
    {
        p[i]=random(15)+1;
        sum^=p[i];
    }
    p[NP-1]=sum;
    show();
    message_vision(RED"$N���ðɡ�\n"NOR, player);
} 
int show()
{
    int i;
    for(i=0;i<NP;i++)
        if(p[i]!=0)
            message_vision(CYN+cnum[i*2..i*2+1]+NOR"��"GRN+
                           pile[0..p[i]*2-1]+NOR"\n",
                           this_object());
    return 1;
} 
int do_take(string arg)
{
    int i,h;
    if(!arg || sscanf(arg,"%d %d",i,h)!=2)
        return notify_fail("take <pile> <how many>");
    if(i>NP || i<=0) return notify_fail("must be 1 to NP");
    if(h<=0 || h>p[i-1]) return notify_fail("there are only few to talk");
    take(this_player(), i-1, h);
    remove_call_out("ctake");
    call_out("ctake",1);
    return 1;
} 
int CheckWin(object who)
{
    int i;
    for(i=0;i<NP;i++)
        if(p[i]!=0) return 0;
    message_vision(HIR"$NӮ�ˡ�\n"NOR,who);
    command("ya");
    in_game=0;
    return 1;
} 
void ctake()
{
    int sum, i;
    int best=100, besti=-1;
    for(i=0,sum=0;i<NP;i++)
        sum^=p[i];
    if(sum!=0)
        for(i=0;i<NP;i++)
            if(p[i] > (p[i]^sum) && (best > p[i]-(p[i]^sum)))
            {
                best=p[i]-(p[i]^sum);
                besti=i;
            }
    if(besti!=-1)
    {
        take(this_object(),besti, best);
        if(!CheckWin(this_object()))
            message_vision(RED"��$N�ˡ�\n"NOR, player);
        return;
    }
    command("say shit!");
} 
int do_start()
{
    if(in_game==1)
        return notify_fail("already in game\n");
    //Check for money...
    
    player=this_player();
    add_action("do_take", "take");
    add_action("show","show");
    start_game();
    return 1;
}
    
void create()
{
    set_name(HIC"����ƭ��"NOR, ({ "pianzi" }) );
    set("title",HIY "ͯ������" NOR);
    set("long", "\n");
    set("gender", "����");
    set("age", 70);
    set("no_fight",1);
    set("combat_exp", 9000);
    setup();
    in_game = 0;
} 
void init()
{
    ::init();
    //if( !query_heart_beat(this_object()) ) set_heart_beat(1);
    add_action("do_start","start");
}
