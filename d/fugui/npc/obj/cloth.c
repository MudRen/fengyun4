
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("青布衫", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	::init_cloth();
}
