

#include <weapon.h>
inherit STAFF;

void create() {
	set_name("大悲杖", ({ "staff" }) );
	set_weight(2500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
//		set("long", "这是一把看起相当普通的木棍");
		set("value", 400000);
		set("weapon_prop/attack",30);
		set("level_required",50);
		set("material", "iron");
		set("wield_msg", "$N把$n紧紧地握在手中。\n");
		set("unwield_msg", "$N松开了手中的$n。\n");
	}
    ::init_staff(60);
}
