// foreknowledge.c

#include <ansi.h>

inherit SKILL;

void setup() {
	set("name","占卜学");
	set("skill_class","basic");
	set("type","knowledge");
	set("effective_level",50);
	set("difficulty",100);
	set("eff_learn_level", 150);
	set("no_refund","attr");
}



void skill_improved(object me)
{
	string att = "kar";
	string c_att = "运气";
	int s = me->query_skill("foreknowledge", 1);
	
	if (s > 50 && s < 201 && !(s%10)) {
		if ( s/5 > 10 + me->query("improve/"+ att)) {
			tell_object(me, HIW "由於对占卜学的更深一步的理解，你的运气提高了。\n" NOR);
			me ->add(att, 2);
			me ->add("improve/"+att,2);
		}
		if (s == 200)
			tell_object(me,HIR"你的"+c_att+"已经不能再通过"+ name()+ "提高了。\n"NOR);
		
	}
	
}
