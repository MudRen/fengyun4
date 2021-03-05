// medicine.c

inherit MEDICINE;
#include <ansi.h>

void create()
{
    	set_name(GRN"三叶凤尾草"NOR,({"sanyecao"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
                "一棵已经晾干的三叶凤尾草，淡淡散发着草香，可以用来治疗1500点外伤。\n");
        	set("unit","束");
        	set("base_unit","棵");
        	set("base_value", 6000);
        	set("base_weight",60);
				set("field","kee");
	    	set("type","cure");
	    	set("effect",1500);
	    	set("heal_type","kee/1500");
	    	set("usage_type","herb");	
	    	set("volumn", 10);
	}
	set_amount(10);
}
