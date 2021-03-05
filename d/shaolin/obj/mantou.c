// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("馒头", ({ "mantou" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个干硬的大馒头\n");
		set("unit", "个");
		set("value", 10);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
