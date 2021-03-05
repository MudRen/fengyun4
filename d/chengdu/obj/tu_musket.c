#include <ansi.h>
#include <weapon.h>
inherit MUSKET;
void create()
{
        set_name(HIY"火绳枪"NOR, ({ "matchlock musket" }) );
        set_weight(10000);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long",
"火绳枪的结构是，枪上有一金属弯钩，弯钩的一端固定在枪上，并
可绕轴旋转，另一端夹持一燃烧的火绳，士兵发射时，用手将金属
弯钩往火门里推压，使火绳点燃黑火药，进而将枪膛内装的弹丸发
射出去（ＦＩＲＥ）。"
);
                set("value", 0);
                set("no_stack",1);
//                set("no_drop",1);
                set("material", "steel");
                set("level_required",0);
                set("wield_msg", "$N将$n靠在左肩，左手持枪。\n");
                set("unequip_msg", "$N将手中的$n挂回背后。\n");
        }
        ::init_musket(50);

}

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam;
	dam = (int) me->query("max_force")/40;
	dam = COMBAT_D->magic_modifier(me, victim, "gin", dam);
	victim->receive_damage("gin",dam,me);
    return HIR"沥泉神枪似巨蟒吐信上下翻滚，漫天血芒使$n魂飞魄散，精疲力尽。\n"NOR;
}
*/

void init()
{
       add_action("do_get1", "get");
       add_action("do_put1", "put");
       add_action("do_prime", "prime");
       add_action("do_clear", "clear");
//     add_action("do_use", "fishing");
       add_action("do_fire", "fire");
}

int do_get1(string arg)
{
	string get_from;
  if( !arg ) return notify_fail("你要捡起什麽东西？\n");
  if (sscanf(arg, "%s from %s", arg, get_from)==2)
  {
  	if (get_from==this_object()->query("id"))
  	{
  		message_vision("请使用专用指令清空枪膛。（ＣＬＥＡＲ）\n"NOR,this_player());
			return 1;
		}
	}
	return 0;
}

int do_put1(string arg)
{
  string put_in;
  if( !arg ) return notify_fail("你要将什麽东西放进哪里？\n");
  if (sscanf(arg, "%s in %s", arg, put_in)==2)
  {
  	if (put_in==this_object()->query("id"))
  	{
			message_vision("请使用专用指令填装弹药。（ＰＲＩＭＥ）\n"NOR,this_player());
			return 1;
		}
	}
	return 0;
}

int do_prime(string arg)
{
	int i,powder=0,bullet=0;
	object *inv;
	object powderi,bulleti,into_powderi,into_bulleti;
	inv = all_inventory(this_player());
	
	if( !arg ) return notify_fail("填装弹药格式ＰＲＩＭＥ ＧＵＮＰＯＷＤＥＲ\n");
	if (arg=="gunpowder") 
	{
		  message_vision("$N蹲下身子开始填装弹药。。。\n"NOR,this_player());
			tell_object(this_player(),"check1...ok\n"NOR);
			for(i=0; i<sizeof(inv); i++)
		  {
		  	if(inv[i]->query("id") == "gun powder") {powder = 1; powderi = inv[i];}
		   	if(inv[i]->query("id") == "iron bullet") {bullet = 1; bulleti = inv[i];}
			}
			tell_object(this_player(),"check2...ok\n"NOR);
			if (!sizeof(all_inventory(this_object())))
			{
				if(powder && bullet)
				{
					tell_object(this_player(),"check3...ok\n"NOR);
					if (powderi->query_amount() >= 3)
					{
						call_out("do_prime_2", 6, powderi, bulleti, into_powderi, into_bulleti,environment(this_player()));	
						this_player()->start_busy(4);
					} else {
					tell_object(this_player(),"check5...ok\n"NOR);
					tell_object(this_player(),"火药不够，无法继续填装！\n"NOR);
					}
				} else {
					tell_object(this_player(),"check6...ok\n"NOR);
					tell_object(this_player(),"没有弹药了，拿什么填装！\n"NOR);
				}
			} else {
					tell_object(this_player(),"枪膛内已经有东西了，无法再次填装！\n"NOR);
			}
	} else {
			tell_object(this_player(),"填装弹药格式ＰＲＩＭＥ ＧＵＮＰＯＷＤＥＲ\n"NOR);
	}
	return 1;
}

void do_prime_2(object powderi,object bulleti,object into_powderi,object into_bulleti)
{
	tell_object(this_player(),"check4...ok\n"NOR);
	powderi->add_amount(-3);
	bulleti->add_amount(-1);
	into_powderi = new("/d/chengdu/obj/gun_powder.c");
	into_powderi->set_amount(3);
  into_powderi->move(this_object());
	into_bulleti = new("/d/chengdu/obj/iron_bullet.c");
	into_bulleti->set_amount(1);
  into_bulleti->move(this_object());
	message_vision("填装完毕，$N迅速地站起身来！\n"NOR,this_player());
	this_player()->stop_busy();
	return;
}

int do_clear(string arg)
{
	int i,powder_dust;
	object *inv,powder_dusti;
	inv = all_inventory(this_object());

	if( !arg ) return notify_fail("清空枪膛格式ＣＬＥＡＲ ＤＵＳＴ\n");
	if (arg=="dust") 
	{
		  if (this_player()->query_temp("timer/ct_musket_heart") + 12 > time())
		  	return notify_fail(this_object()->name()+"枪膛过烫，手根本没办法触碰。\n");
		  	
		  message_vision("$N蹲在一边仔细检查枪膛。。。\n"NOR,this_player());
			tell_object(this_player(),"check1...ok\n"NOR);
			for(i=0; i<sizeof(inv); i++)
		  {
		  	if(inv[i]->query("id") == "powder dust") {powder_dust = 1; powder_dusti = inv[i];}
			}
			tell_object(this_player(),"check2...ok\n"NOR);
			if(sizeof(inv)) 
			{
				tell_object(this_player(),"check3...ok\n"NOR);
				if(powder_dust) {
						call_out("do_clear_2", 6, powder_dusti, environment(this_player()));	
				  	this_player()->start_busy(4);
				} else {
				tell_object(this_player(),"check5...ok\n"NOR);
				tell_object(this_player(),"刚填装好的弹药，清理掉不是可惜了！\n"NOR);
				}
			} else {
			tell_object(this_player(),"check6...ok\n"NOR);
			tell_object(this_player(),"枪膛里都干净的发亮了，没必要再清理了吧！\n"NOR);
			}
	} else {
			tell_object(this_player(),"清空枪膛格式ＣＬＥＡＲ ＤＵＳＴ\n"NOR);
	}
	return 1;
}

void do_clear_2(object powder_dusti)
{
	tell_object(this_player(),"check4...ok\n"NOR);
	destruct(powder_dusti);
	message_vision("枪膛清空完成，$N迅速地站起身来！\n"NOR,this_player());
	this_player()->stop_busy();
	return;
}

/*
int do_use(string arg)
{
        object *inv,bait;
        inv = all_inventory(this_object());
        //tell_object(this_player(),"你掏出一个" + this_object()->name() + "。\n");
        bait=inv[0];
        tell_object(this_player(),"你掏出一个" + bait->name() + "。\n");
        //environment(this_player())->fish_notify(this_object(),0);
        return 1;
}
*/

/*
int fish_notify(object obj){
   	object me, room, fish, *inv, bait;
   	int i,llvl;

   	me = this_player();
   	llvl = (int)me->query("kar");

	inv = all_inventory(obj);
	if(sizeof(inv) == 0){
		message("vision",me->name() + "掏出了" + obj->name() + "又放了回去。\n", environment(me), me);
     	tell_object(me, obj->name() + "上没有饵怎么可以钓鱼呢 ? \n");		
		return 1;
	}		
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->query("fish_bait")) {
			bait = inv[i];
      		message_vision("$N坐在树干上静静的开始垂钓。 \n" , me);
      		me->start_busy(3);
      		if(llvl > 15 && random(20) < llvl) {
            		tell_object(me, "无聊中你注意到桥头雪白的石头上似乎有一块黑斑。\n");
            		me->set_temp("marks/bridge", 1);
      		} else if(random(300) < llvl) {
            	tell_object(me, "无聊中你注意到桥头雪白的石头上似乎有一块黑斑。\n");
            	me->set_temp("marks/bridge", 1);
      		}
      		remove_call_out("do_fishing");              
      		call_out("do_fishing", 5, me, bait);			
			return 1;
		} 
	}
   	tell_object(me, "你用的饵不太对吧 ? \n");			
	return 1;
}

void do_fishing(object me, object bait)
{
   object 	fish;

   if(me && environment(me) == this_object()) {
   message_vision("$N很快又扯动了一下鱼杆, " , me);
   switch (random(3)) {
      case 0:
         message_vision("却什么都没钓上来 ! \n", me);
         break;
      case 1:
         message_vision("什么都没钓上来 , 鱼饵却被鱼吃了 !!  \n", me);
         destruct(bait);
         break;
      case 2:
         message_vision("鱼钩上钓着一条鱼 !!  \n", me);
         fish = new(__DIR__"obj/fish");
         fish->move(me);
         destruct(bait);
         break;
      }
   }
   return;
}
*/

int do_fire(string arg)
{
	object ob, me, *inv,powderi,bulleti;
	int i,shoot_error=0;
  inv = all_inventory(this_object());
		
	if(!this_object()->query("equipped")) return notify_fail(this_object()->name()+"没有装备火枪就想射击吗？\n");
	
	if(!this_player()->query_skill("musket",1)) return notify_fail(this_object()->name()+"你根本不懂得火枪使用，就不要和生命开玩笑了！\n");
	
	if (sizeof(inv) == 0) 
			return notify_fail(this_object()->name()+"没有弹药无法射击。\n");

	if (!arg) return notify_fail("你要打谁？\n");
	me=this_player();
    	
  if (me->query_temp("timer/ct_musket_heart") + 0 > time())
 		return notify_fail(this_object()->name()+"刚刚使用过，火枪正在回复中。\n");
    		
  if( environment(me)->query("no_fight")
 	 || environment(me)->query("no_magic") 
 	 || environment(me)->query("no_spells"))
 	 return notify_fail("在这不可偷袭！\n");
    	
  ob=present(arg,environment(me));
  if (!objectp(ob) || !living(ob)) 
  	return notify_fail(this_object()->name()+"只能对活的生物使用。\n");
    	
  if (userp(me) && me!= ob)
	if (!COMBAT_D->legitimate_kill(me, ob)) {
		if (stringp(ob->query("NO_KILL")))
			return notify_fail(ob->query("NO_KILL"));
		if (stringp(ob->query("NO_PK")))
			return notify_fail(ob->query("NO_PK"));	
	else 
		return notify_fail("你无法攻击此人。\n");
	}
		
	if (me->is_busy())
		return notify_fail("你现在正忙！\n");
	
		/*if (!me->is_fighting(ob))
				return notify_fail( this_object()->name()+ "是用来防身的，可不是去招惹他人。\n");*/
			
  if (ob == me)
  	return notify_fail("小小年纪就自己找死？\n");
    	
	for(i=0; i<sizeof(inv); i++)
  {
  	if(inv[i]->query("id") == "powder dust") {shoot_error = 1;}
  	if(inv[i]->query("id") == "gun powder") {powderi = inv[i];}
		if(inv[i]->query("id") == "iron bullet") {bulleti = inv[i];}
	}
			
	if (shoot_error)
  	return notify_fail(this_object()->name()+"火枪里有残留杂物无法继续射击，请使用ＣＬＥＡＲ排除。\n");

	message_vision(HIR"\n$N"HIR"端起"+this_object()->name()+HIR"瞄准目标并点燃了火绳。\n"NOR,me,ob);
	call_out("do_fire2", 6, me, ob, inv,powderi, bulleti, environment(this_player()));	
	this_player()->start_busy(4);
	return 1;
}

void do_fire2(object me,object ob,object *inv,object powderi,object bulleti)
{
	object target,powder_dusti;
	int i,damage,damage2=0,damage3=0,damage4=0;
	string msg;	
	
	damage2 = (int)this_object()->query("weapon_prop/damage");
	damage3 = (int)powderi->query("base_weight");
	damage4 = (int)bulleti->query("base_weight");

    	
  damage = 500 + (me->query_skill("musket") + damage2 * 5 + damage3 * 10 + damage4 * 2) * F_LEVEL->get_level(me->query("combat_exp")) /5; 
  //damage = 500 +  * (extra + cloud/2) /5;	
  if (damage < 1800) damage = 1800;	// 保证最低输出1800   	
    	
  //message_vision(HIR"\n$N"HIR"端起"+this_object()->name()+HIR"瞄准目标并点燃了火绳。\n"NOR,me,ob);
  me->set_temp("timer/ct_musket_heart",time());
    	
  target = ob;
    	
  if (COMBAT_D->do_busy_attack(me, target, "nine-moon-claw/weiwoduzun","unarmed", 700, 10))
  {
   	msg = RED"随着一声巨响就连$n的惨嚎声也已被盖过，只眼前瞬间血肉横飞，$n手捂伤口一脸痛苦的表情呆呆的望着$N！\n" NOR;
   	damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
   	target->receive_wound("kee", damage, me);
   	message_vision(msg, me, target);
   	COMBAT_D->report_status(target,0);
  }
  else {
  	msg = CYN"$n把头一闪，身后砰的一声巨响，黑火色的烟顿时冲上青天！\n";
		message_vision(msg, me, target);
	}
    		
  ob->kill_ob(me); 
	//add("ammo",-1-random(2));
	   	
	for(i=0; i<sizeof(inv); i++)
	{
		//bait = inv[0];
	  destruct(inv[i]);	   	
	}
	powder_dusti = new("/d/chengdu/obj/powder_dust.c");
	powder_dusti->set_amount(1);
	powder_dusti->move(this_object());
  //me->perform_busy(3);
  me->stop_busy();
  return;
}

int is_container() { return 1; }