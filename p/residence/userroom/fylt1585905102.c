#define X_COOR -20
#define Y_COOR -30
#define Z_COOR 160
#define R_FLAG 15
#define FREE_SPACE 4
#define CONSTRUCT_TREE 1
#define BASIC_TAX 1120
#define BASIC_SCORE_TAX 400

#define TOTAL_GOLD 1200
#define TOTAL_SCORE 560

#define OWNER "fylt"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1585905102"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "水上乐园");
set("long", @LONG
这里是侯府巨大的私人水上乐园侯龙涛的寻欢之地众美宽衣出水芙蓉羡煞旁人此地禁斗这里是侯府巨大的私人水上乐园侯龙涛的寻欢之地众美宽衣出水芙蓉羡煞旁人此地禁斗这里是侯府巨大的私人水上乐园侯龙涛的寻欢之地众美宽衣出水芙蓉羡煞旁人此地禁斗

LONG
);
        set("exits", ([
"out" : "/p/residence/smile4.c",
]));
set("objects", ([
       ]) );
	set("coor/x",X_COOR);
	set("coor/y",Y_COOR);
	set("coor/z",Z_COOR);
	set("room_flag",R_FLAG);
	set("owner", OWNER);
	set("class", CLASS);
	set("timestamp",TIMESTAMP);
	set("timestamp2",TIMESTAMP2);
	set("free_space",FREE_SPACE);
	set("basic_tax",BASIC_TAX);
	set("basic_score_tax",BASIC_SCORE_TAX);
	set("tree",CONSTRUCT_TREE);
	set("total_gold",TOTAL_GOLD);
	set("total_score",TOTAL_SCORE);
	setup();

}
