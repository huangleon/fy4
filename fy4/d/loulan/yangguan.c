 inherit ROOM;
void create()
{
        set("short", "���Ź�");
        set("long", @LONG
���ŵ��ϵĻ�ɳ����ؼ�·��ѳ���һƬ���Եİ���ɫ��Ҳ��֪�����ﴫ����
һ������ĸ�������һ�����Źأ������᲻�ɡ�������һ��绯�˵�ʯ������Լ��
�Կ��������Źء�������׭���֡�
LONG
        ); 
        set("exits", ([ 
                "southeast" : __DIR__"mirage",
                "northwest" : __DIR__"kongquehe",
                "west" : AREA_EREN"yangguan",
        ]));
        set("outdoors", "loulan");
        set("coor/x",-950);
        set("coor/y",110);
        set("coor/z",0);
        setup();
}  
int valid_leave(object who, string dir) {
        if (dir=="west") {
                if (!wizardp(who) && !who->query("beta_test"))
                        return notify_fail("��ɳ�ն����е�·��ʱ�رա�\n");
        }
        return 1;
}  
