
inherit ROOM;
void create()
{
        set("short", "就公塔塔顶");
        set("long", @LONG
                                      /\
                                      /\
                                      /\
                                      /\
                                    _`=='_
                                 _-~......~-_
                             _--~............~--_
                       __--~~....................~~--__
           .___..---~~~................................~~~---..___,
            `=.________________________________________________,='
               @^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@
                        |  |  I   I   II   I   I  |  |
                        |  |__I___I___II___I___I__|  |
                        | /___I_  I   II   I  _I___\ |
                        |'_     ~~~~~~~~~~~~~~     _`|
                    __-~...~~~~~--------------~~~~~...~-__
            ___---~~......................................~~---___
.___..---~~~......................................................~~~---..___,
 `=.______________________________________________________________________,='
    @^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@
              |   |    | |    |  |    ||    |  |    | |    |   |
              |   |____| |____|  |    ||    |  |____| |____|   |
              |__________________|____||____|__________________|
            _-|_____|_____|_____|__|------|__|_____|_____|_____|-_  

LONG
        );
        set("exits", ([ 
  			"down" : __DIR__"talin",
		]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"npc/lama1a" : 1,
                __DIR__"npc/lama2a" : 1,
                __DIR__"npc/lama3a" : 1,
       ]) );
        
        
		set("coor/x",65);
		set("coor/y",25);
		set("coor/z",30);
		setup();
        
}
