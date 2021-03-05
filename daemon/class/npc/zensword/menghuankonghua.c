// yawn pfm
// *bored,#10 *yawn,*bored annie
// 少林专用pfm? doubt


// 2009 FengYun
// Edit by hippo 2009.11
//既然作为2005fy7/7额外可奖励技能,给予玩家使用.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra,extra2,busy,busy2,pp=0,pd=0;
	object weapon;
	mapping buff;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『梦幻空花』只能对战斗中的对手使用。\n");
/*
	if (me->query("marry") || me->query("divorced"))
		return notify_fail("你心头有所挂念，无法施展『梦幻空花』。\n");

	if (me->query("quest"))
		return notify_fail("你心头尚有挂念，无法施展『梦幻空花』。\n");
 		//任务不可使用无意义,调整.
*/
	
	if (me->query_skill("zen",1) < 50) //根据fy2005能学习free zen给予调整.
		return notify_fail("你禅机未悟，无法施展『梦幻空花』。\n");
	
	if (me->query_skill("xiaodao",1) < 150) //根据新的riddle可以获得xiaodao 调整pf难度
		return notify_fail("你孝道浅薄，无法施展『梦幻空花』。\n");
	
	if (me->query_skill("zensword",1) < 170) //调整难度
		return notify_fail("『梦幻空花』需要170级安洁苦禅剑！\n");
	
	extra = me->query_skill("sword");
	extra /= 3;
	extra2 = me->query_skill("xiaodao",1);

	if (me->query("marry") || me->query("divorced")) {
		extra = extra * 9 / 10;
		extra2 = extra2 * 9 / 10;
	}
	me->add_temp("apply/attack",extra);
	//me->add_temp("apply/damage",me->query_skill("xiaodao",1));	
	me->add_temp("apply/damage",extra2);	

	msg =  CYN"$N"NOR CYN"双眼微合，只觉万事空无，意兴阑珊，手中"+ (me->query_weapon())->name()+ NOR CYN"倚着禅机信手随舞，胡乱击出。\n" NOR;
	message_vision(msg, me, target);
	
	busy = target->query_busy();
	busy2 = target->query("no_busy");

	
    msg =  YEL"梦…"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	if (target->query_temp("damaged_during_attack"))
	{
		message_vision(HIB"$N只觉得世事宛如春梦一场，人生几无意趣，动作渐渐迟缓。\n",target);
		target->start_busy(1);
	}
	
	
    msg =  NOR YEL  "幻…"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        
        
	if (target->query_temp("damaged_during_attack") && !target->query("boss") && !target->query("big_boss"))
	{
		message_vision(HIB"种种往时幻像如走马灯般流过$N眼前，$N目光迷离，神智大乱。\n",target);
		pp = extra * 2;
		pd = me->query_skill("zen",1);
		if (me->query("marry") || me->query("divorced")) {
			pp = pp * 9 / 10;
			pd = pd * 9 / 10;
		}
		target->add_temp("apply/parry",-pp);
		target->add_temp("apply/dodge",-pd);	
	}
	
    msg =  NOR YEL  "空…"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	if (target->query_temp("damaged_during_attack"))
	{
		message_vision(HIB"回首旧时光阴，竟是韶光虚掷，一事无成，$N不由觉得心头一片茫然。\n",target);
		ANNIE_D->debuff(target,"powerup");
	}
	
	
    msg =  NOR YEL  "花…"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	
		me->add_temp("apply/attack",-extra);
		//me->add_temp("apply/damage",-me->query_skill("xiaodao",1));	
		me->add_temp("apply/damage",-extra2);	


	if (me->query("quest")) { //修改运用为任务惩罚
		me->perform_busy(4);
	} else {
		me->perform_busy(3);
	}
		
	
	if (target) {
		target->stop_busy();
		target->perform_busy(busy);
		target->add_temp("apply/parry",pp);
		target->add_temp("apply/dodge",pd);	
		
		weapon = target->query_temp("weapon");
		if (target->query_temp("damaged_during_attack") 
			&& !target->query("boss") && !target->query("big_boss")
			&& target->query_temp("marks/disarmed") + 60 < time()
			&& weapon && !weapon->query("nodrop_weapon"))
		{
			if (random(me->query("combat_exp") + target->query("combat_exp")) > target->query("combat_exp") / 2 * 3)
			{
				if (weapon->query("skill_type") != "throwing" 
					&& weapon->query("skill_type") != "ring" 
					&& weapon->query("skill_type") != "unarmed")
				{
					message_vision(HIB"$N但觉万念俱灰，大千世界里再无自己容身之处，长长叹息一声，将手中"+weapon->name()+HIB"收起。\n"NOR,target);
					if(weapon->unequip()) {
					buff =
						([
							"caster":me,
							"who":  target,
							"type":"disarmed",
							"att":"curse",
							"name":"安洁苦禅剑·梦幻空花",
							"buff1":"disarmed",
							"buff1_c":1,
							"time":  60,
							"buff_msg":" ",			
						]);
					ANNIE_D->buffup(buff);
					}
				}
				target->set_temp("marks/disarmed",time());
			}
		}
	}
    return 1;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

