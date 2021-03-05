inherit NPC;

void create()
{
	set_name("麻雀", ({ "bird" }) );
	set("race", "飞禽");
	set("age", 1);
	set("long", "咭咭喳喳的一只小麻雀。\n");
	
	set("chat_chance", 1);
	set("chat_msg", ({
		"咭咭，喳喳。\n",
	}));
	set("combat_exp",2000);
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
	setup();
}
