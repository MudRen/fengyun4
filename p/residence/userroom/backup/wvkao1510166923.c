#define X_COOR -10
#define Y_COOR -40
#define Z_COOR 320
#define R_FLAG 17
#define FREE_SPACE 4
#define CONSTRUCT_TREE 1
#define BASIC_TAX 1120
#define BASIC_SCORE_TAX 400

#define TOTAL_GOLD 1200
#define TOTAL_SCORE 560

#define OWNER "wvkao"
#define TIMESTAMP "1"
#define TIMESTAMP2 "1510166923"
#define CLASS "annie"

#include <ansi.h>

inherit XROOM;

void create()
{
set("short", "女未窝");
set("long", @LONG
根本木有东西
根本木有东西
根本木有东西
根本木有东西
根本木有东西
根本木有东西
根本木有东西
根本木有东西
根本木有东西
根本木有东西
根本木有东西
根本木有东西
根本木有东西
根本木有东西
根本木有东西

LONG
);
        set("exits", ([
"out" : "/p/residence/tower8.c",
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
