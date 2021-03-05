inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("破酒壶", ({ "winepot" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个破酒壶，大概装得八、九升的酒。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "烧刀子酒",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
	::init_item();
}
