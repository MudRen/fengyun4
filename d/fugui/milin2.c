#include <ansi.h>
inherit ROOM;
#include "milin.h"

void create()
{
	set("short", HIG"密林"NOR);

	set("long", @LONG
这是一片密林，周围树木参天而立，遮云蔽日，四周昏昏暗暗，间杂着一些说
不出名字的绿色野花，但见落叶铺地，踩上去沙沙做响，你高一脚低一脚地向前摸
索，隐隐有些担心，别该是迷路了吧。
LONG);
	set("type","forest");
	set("outdoors", "fugui");
	set("attribute","mu");
	set("exits",([
		"east":__DIR__"milin3",
		"south":__DIR__"milin1",
		"west":__DIR__"milin7",
		"north":__DIR__"milin20",
	]) );
	set("coor/x",-10);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}
