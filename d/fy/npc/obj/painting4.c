inherit ITEM;

void create()
{
        set_name("《昭君出塞图》", ({ "painting"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("long", "一卷描绘精致的《昭君出塞图》，只是没有印方，应是临摹之作。\n");
                set("value", 30000);
        }
        ::init_item();
}


