 // silencer@fy4 workgroup 五行阵之木阵
inherit VRM_SERVER; 
void create()
{
        // 迷宫房间所继承的物件的档案名称。
        set_inherit_room(__DIR__"wood-room"); 
        //迷宫的单边长 (5-100)
        set_maze_long(50); 
        //迷宫房间里的npc.
        //note: this one is optional
//      set_maze_npcs(__DIR__"npc/w-sentry-1"); 
        //迷宫房间内放置 npc 的可能性(1-100)
        //note: this one is optional too, if not set, then default is 20 (1/5)
//      set_maze_npc_rate(100); 
        //迷宫重建时间 pass in integer 以秒为单位
        //note: this one is optional, if not set then default is no refresh
        //if pass in 0, then means no refresh too.
        // this example means maze will be refreshed in 1 hour.
        set_maze_refresh(3600); 
        //入口方向(出口在对面)
        set_entry_dir("east"); 
        //入口与区域的连接方向
        set_link_entry_dir("east"); 
        //入口与区域的连接档案名
        set_link_entry_room(__DIR__"wood-entry");
        
        //入口的坐标(根据连接link_entry_room的那个真实room来定。
        set_link_entry_room_x(1000);
        set_link_entry_room_y(2000);
        set_link_entry_room_z(3000);
         
        //出口与区域的连接方向
        set_link_exit_dir("west"); 
        //出口与区域的连接档案名
        set_link_exit_room(__DIR__"wood-exit"); 
        //入口房间短描述
        set_entry_short("密林"); 
        //入口房间描述
        set_entry_desc(@LONG
走进密林，突然明白你刚才错的有多厉害，林子迷幻般在你面前延伸开来，走
了四五步，眼前仍是一片树林又一片树林，突然间，只有落叶的沙沙声响，前、后、
左、右都是树木，一蓬又一蓬的落叶纷纷飘落，树林里是幽昏一片。没有天光，只
有一种蒙蒙的黯光。如果不及时回头的话，可能再也走不出去了。
LONG
); 
        //出口房间短描述
        set_exit_short("草地"); 
        //出口房间描述
        set_exit_desc(@LONG
拨开最后一簇树枝，眼前猛然间开阔起来，你终于走出了这片密林。
LONG
); 
        //迷宫房间的短描述
        set_maze_room_short("密林"); 
        //迷宫房间的描述，如果有多条描述，制造每个房
        //间的时候会从中随机选择一个。
        set_maze_room_desc(@LONG
走了四五步，眼前仍是一片树林又一片树林，突然间，只有落叶的沙沙声响，
前、后、左、右都是树木，一蓬又一蓬的落叶纷纷飘落，树林里是幽昏一片。没
有天光，只有一种蒙蒙的黯光。你不由生起了一种迷失的感觉。
LONG
); 
        // 迷宫房间是否为户外房间？
        set_outdoors(1);
}  
