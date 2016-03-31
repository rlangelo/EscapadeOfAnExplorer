Team Cloaked Eagle
Jeffrey Bardon / jbardonjr
Rafael Angelo / rlangelo

Platform: 64 bit Linux, specifically the CCC machines.

Files: Block.cpp/.h
       Bomb.cpp/.h
	   Death.cpp/.h
	   Dirt.cpp/.h
	   Exit.cpp/.h
	   Explosion.cpp/.h
	   game.cpp
	   GameStart.cpp/.h
	   Gate.cpp/.h
	   Hero.cpp/.h
	   Makefile
	   map1.txt
	   map2.txt
	   map3.txt
	   map4.txt
	   map5.txt
	   map6.txt
	   map7.txt
	   map8.txt
	   map9.txt
	   map10.txt
	   map11.txt
	   map12.txt
	   map13.txt
	   map14.txt
	   Map.cpp/.h
	   Plate.cpp/.h
	   Wall.cpp/.h
	   Water.cpp/.h
	   Tutorial.cpp/.h
	   Select.cpp/.h
	   Select2.cpp/.h
	   Select3.cpp/.h
	   Select4.cpp/.h
	   Select5.cpp/.h
	   Select6.cpp/.h
	   Select7.cpp/.h
	   Select8.cpp/.h
	   Select9.cpp/.h
	   Select10.cpp/.h
	   Select11.cpp/.h
	   Select12.cpp/.h
	   Select13.cpp/.h
	   Select14.cpp/.h
	   
Spritelist: blockoff-spr.txt
            blockon-spr.txt
		bomb-spr.txt
		dirt-spr.txt
		exit-spr.txt
		explosion-spr.txt
		gamestart-spr.txt
		gate-spr.txt
		gateoff-spr.txt
		herodie-spr.txt
		herodown-spr.txt
		heroleft-spr.txt
		heroright-spr.txt
		heroup-spr.txt
		howto-spr.txt
		plate-spr.txt
		wall-spr.txt
		water-spr.txt
		tutorial1-spr.txt
		tutorial2-spr.txt
		tutorial3-spr.txt
		Select-spr.txt
		Select2-spr.txt
		Select3-spr.txt
		Select4-spr.txt
		Select5-spr.txt
		Select6-spr.txt
		Select7-spr.txt
		Select8-spr.txt
		Select9-spr.txt
		Select10-spr.txt
		Select11-spr.txt
		Select12-spr.txt
		Select13-spr.txt
		Select14-spr.txt

Code Structure: 
    Dependencies:
	    Block:  Block is dependent on Bomb, Dirt and Water.
        Bomb:  Bomb is dependent on nothing.
	    Death:  Death is dependent on Selects.
	    Dirt:  Dirt is dependent on nothing.
	    Exit:  Exit is dependent on nothing.
	    Explosion:  Explosion is dependent on Selects.
	    GameStart:  Gamestart is dependent on Selects.
	    Gate:  Gate is dependent on Block and Plate.
	    Hero:  Hero is dependent on Block, Bomb, Death, Dirt, Exit, Explosion, Selects, and Water.
	    Select-Select14: These are all dependent on Map.
	    Map:  Map is dependent on Block, Bomb, Dirt, Exit, Gate, Hero, Plate, Wall and Water.
	    Plate:  Plate is dependent on nothing.
	    Wall:  Wall is dependent on nothing.
	    Water:  Water is dependent on nothing.
	    Tutorial is dependent on Map.

	On running game.cpp, GameStart runs, then Select runs, creating a Map object which runs loadMap.  
	loadMap populates the game world with objects from reading a map file, which is a specifically formatted text file.



Compilation Instructions: Extract the folder, navigate to the extracted folder in the terminal, 
				type "make" and then "./game" to run "Escapade of an Explorer".

Additional Information:

	- We used Professors Claypool's Dragonfly v3.1 engine.
	- You are only able to push one block at a time, and can't pull them, so be smart with your use!
	- Remember, the pressure gates only open if ALL pressure plates are held down.
	- 
There is an on-screen that will show up in earlier levels.
	- Q to quit at anytime.