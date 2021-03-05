inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", HIR"祭剑亭"NOR);
    set("long", @LONG
祭剑是每个习武之人必做之事。每逢一年一度的风云城比武大赛，凡是参赛的
人都会到这儿来祭一次兵刃，以求好运。亭子间不大，四面通风，一道长长的木柜
把房间隔成了两部分，里面石板地正当中是一个冶剑炉，通红的炉火把亭内一切都
染上一层红色。门口有一块大石碑（ｓｉｇｎ）。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"huanyun8",
      ]));
    set("objects", ([
	__DIR__"npc/wangfuren" : 1,
      ]) );
    set("item_desc", ([
	"sign": @TEXT	
[0;1;37m────────────────────────────────[0m
[0;1;36m			祭剑亭业务[0m
[0;1;37m────────────────────────────────[0m

你在张铁匠那里打完自制武器后，就可以来这里祭剑，以提高武器的
伤害力，祭剑的指令很简单：	ji  武器名
不过，想要有一把好武器，不仅腰包要鼓，还要能找到好的辅助矿料。

[0;1;37m────────────────────────────────[0m
TEXT
      ]) );

    set("coor/x",80);
    set("coor/y",-240);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}
