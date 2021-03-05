// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	string *order = ({"豆沙", "莲蓉", "枣泥", "凤梨", "百果"});
    set_name( order[random(5)] + "月饼", ({ "mooncake", "moon cake" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个皮薄馅多香气扑鼻的月饼。\n");
		set("unit", "个");
		set("value", 200);
		set("food_remaining", 3);
		set("material", "food");
		set("food_supply", 60);
		set("holiday", "中秋节");
	}
	 ::init_item();
}

	