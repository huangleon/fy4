 安装说明
首先请将您游戏的的 MASTER_OB 内的 compile_object()
函数内容改成以下形式：
mixed compile_object(string file)
{
        object daemon;
        if( daemon = find_object(VIRTUAL_D) )
                return daemon->compile_object(file);
        else
                return 0;
}
一般的 es2 类构架的游戏大概都是这么写的，VIRTUAL_D 
为 "/adm/daemons/virtuald"，您游戏中如果没有此定义
可以自己将其加入您游戏的 global include file 中，
一般为 "/include/globals.h"，将 /adm/daemons/ 下的
两个文件拷贝至您游戏的相应目录下，vrm_server.c 内
我作了一些注释。/d/try/ 下为一个20x20迷宫的例子，
vrm_help 为迷宫制作的帮助文件。
声明：虚拟迷宫生成器源代码的公布仅出于与大家共同学
      习探讨提高的初衷，本人不对此提供任何技术支持。
      代码可以被任意修改，如没有妨碍希望能保留本游
      戏与本作者的名字。此代码可根据需要用于任何用
      途，本游戏与本作者也不对运行此代码的后果负任
      何责任。
      发现号(Find)
               网络游戏 MUD：天下
                      210.78.144.10 6666
