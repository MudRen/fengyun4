
inherit ROOM;

void create()
{
	set("short", "天梯");
	set("long", @LONG
这是一条狭窄的甬道,宛如登天的天梯。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
        "up"   : __DIR__"tianti3",
            "down" : __DIR__"tianti1",
	]));
        set("objects", ([
        __DIR__"npc/bianfu2": 1,
	]) );
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",20);
	setup();
      replace_program(ROOM);
}

