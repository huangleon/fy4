 // buddhism.c
inherit SKILL; 
void setup() {
        set("name",                             "大乘佛法");
        set("type",                             "knowledge");
        set("learn_bonus",                      -30);
        set("practice_bonus",           -10);
        set("black_white_ness",         40);
        set("effective_level",          200);
        set("usage/literate",           1);
} 
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("你的杀气太重，无法修炼大乘佛法。\n");
        return 1;
}         
