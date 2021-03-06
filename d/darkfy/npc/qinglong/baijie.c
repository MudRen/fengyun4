//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("白婕", ({ "bai jie" }) );
        set("gender", "女性");
        set("age", 28);   
      	set("chat_chance", 1);
	set("chat_msg", ({
"白婕靠在你身边轻轻的问道：“让我杀了你好么？”\n",
	}) );

        set("attitude", "friendly");
        set("title",HIG"亢狩"NOR);
        set("nickname", HIG"浅笑"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",30);
		    set("class","swordsman");
        set("death_msg",CYN"\n$N叹道：人若是能死两次，也不失为一件新鲜的事。\n"NOR);
        set("combat_exp", 12000000);        
        
    set("perform_busy_d", "npc/dodge/shenji-steps/shenjimiaosuan");
		set("perform_weapon_attack", "swordsman/sword/13-sword/14sword");
    set("perform_weapon_attack2", "swordsman/sword/softsword/changtianluodian");

		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("unarmed", 200);
        set_skill("sword", 300);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic", 200); 
        set_skill("perception", 200);
        
        set_skill("cloudforce", 180);
		    set_skill("shenji-steps", 200);
		    set_skill("softsword", 200);
        set_skill("13-sword", 200);
        set_skill("dabei-fu", 200);
        
        map_skill("unarmed","dabei-fu");
        map_skill("force", "cloudforce");
        map_skill("dodge","shenji-steps");
        map_skill("move","shenji-steps");
        map_skill("parry","softsword");
        map_skill("sword","softsword");
        setup();
 
       	carry_object("/obj/weapon/sword",([	
    						"name":  HIB"温柔一笑"NOR,
    						 ]))->wield();  

       	carry_object("/obj/armor/cloth",([	
    						"name":  "亢之衣",
    						 ]))->wear();  

}

