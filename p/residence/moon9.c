inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",9);

  set ("short", "新月楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
    
    舍却残生犹不悔
     
    身已空 尽成泪
       
    路长梦短无寻处 总是情愁滋味 
       
    眉间心上 柔肠百结 尽付东流水
    
LONG);
        set("exits", ([
  "down" : __DIR__"moon"+(query("floor")-1),
]));
        set("coor/x",-15);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/