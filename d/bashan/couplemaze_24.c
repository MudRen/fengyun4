
#include <ansi.h>
inherit ROOM;

void create()
{
	object box;
	set("short", "低矮石屋");
        set("long", @LONG
这是一间低矮的屋子，四壁都是厚实的黑石，屋中带着些许轻微的潮气，石壁
贴近地面的地方爬着一层薄薄的乌苔。石屋的四面各立着一扇石门，或开或闭。出
路也许就在石门之后，可是究竟哪一扇门才是生机？
LONG
        );
	set("room_num",24);
	set("exits",([
  		"west" : __DIR__"couplemaze_"+(query("room_num")-1),
	]) );
	set("objects", ([
		__DIR__"obj/box" :1,
	]) );
	set("exist_exits",query("exits"));
	// nothing
	set("no_fly",1);
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	box = present("woodcase",this_object());
	if (box)
		new(__DIR__"obj/map")->move(box);
	if (box)
		new(__DIR__"obj/map")->move(box);
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

