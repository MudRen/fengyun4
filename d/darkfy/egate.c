inherit ROOM;
void create()
{
        set("short", "风云东城门");
        set("long", @LONG
风云东门高三丈，宽约二丈有余，尺许厚的城门上镶满了拳头般大小的柳钉。
门洞长约四丈，大约每隔两个时辰就换官兵把守。洞侧帖满了悬赏捉拿之类的官
府通谍。门洞西侧则是一条上城墙的窄梯。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"ecloud5",
]));
        set("objects", ([
        __DIR__"npc/wind_solider" : 2,
        __DIR__"npc/cloud_solider": 2, 
			]) );
        set("outdoors", "fengyun");
        set("coor/x",60);
        set("coor/y",0);
        set("coor/z",-300);
        setup();
}


