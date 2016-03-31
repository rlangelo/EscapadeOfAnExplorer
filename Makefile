CC = g++
LDFLAGS = -lncurses -lrt
INCPATH = ./include/
ENG = ./libdragonfly.a
GAMESRC= \
	Hero.cpp \
	Wall.cpp \
	Block.cpp \
	Exit.cpp \
	GameStart.cpp \
	Plate.cpp \
	Bomb.cpp \
	Explosion.cpp \
	Water.cpp \
	Death.cpp \
	Dirt.cpp \
	Gate.cpp \
	Map.cpp \
	Select.cpp \
	Select2.cpp \
	Select3.cpp \
	Select4.cpp \
	Select5.cpp \
	Select6.cpp \
	Select7.cpp \
	Select8.cpp \
	Select9.cpp \
	Select10.cpp \
	Select11.cpp \
	Select12.cpp \
	Select13.cpp \
	Select14.cpp \
	Tutorial.cpp \

GAME= game.cpp
EXECUTABLE= game
OBJECTS= $(GAMESRC:.cpp=.o)

all: $(EXECUTABLE) Makefile

$(EXECUTABLE): $(ENG) $(OBJECTS) $(GAME) $(GAMESRC)
	$(CC) $(GAME) $(OBJECTS) $(ENG) -o $@ -I$(INCPATH) $(LDFLAGS)

.cpp.o:
	$(CC) -c $(DEBUG) -I$(INCPATH) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) core dragonfly.log Makefile.bak *~

depend:
	makedepend *.cpp 2> /dev/null
# DO NOT DELETE

Block.o: Block.h Plate.h Dirt.h
Bomb.o: Bomb.h
Death.o: Death.h GameStart.h Select.h
Dirt.o: Dirt.h
Exit.o: Exit.h GameStart.h Select.h
Explosion.o: Explosion.h GameStart.h Select.h
game.o: Hero.h Wall.h Block.h Exit.h GameStart.h
GameStart.o: GameStart.h Map.h /usr/include/string.h /usr/include/features.h
GameStart.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
GameStart.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h Select.h
Gate.o: Gate.h Block.h
Hero.o: Hero.h Explosion.h Block.h Death.h GameStart.h /usr/include/time.h
Hero.o: /usr/include/features.h /usr/include/sys/cdefs.h
Hero.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
Hero.o: /usr/include/gnu/stubs-64.h /usr/include/bits/time.h
Hero.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h Gate.h
Map.o: Map.h /usr/include/string.h /usr/include/features.h
Map.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Map.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h Hero.h Block.h
Map.o: Exit.h Wall.h Bomb.h Water.h Dirt.h Plate.h Gate.h Tutorial.h
Plate.o: Plate.h
Select10.o: Select10.h Map.h /usr/include/string.h /usr/include/features.h
Select10.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select10.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select10.o: Select3.h Select11.h Select9.h
Select11.o: Select12.h Map.h /usr/include/string.h /usr/include/features.h
Select11.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select11.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select11.o: Select4.h Select11.h Select10.h
Select12.o: Select13.h Map.h /usr/include/string.h /usr/include/features.h
Select12.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select12.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select12.o: Select5.h Select11.h Select12.h
Select13.o: Select6.h Map.h /usr/include/string.h /usr/include/features.h
Select13.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select13.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select13.o: Select14.h Select12.h Select13.h
Select14.o: Select7.h Map.h /usr/include/string.h /usr/include/features.h
Select14.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select14.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select14.o: Select.h Select13.h Select14.h
Select2.o: Select2.h Map.h /usr/include/string.h /usr/include/features.h
Select2.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select2.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select2.o: Select.h Select3.h Select9.h
Select3.o: Select3.h Map.h /usr/include/string.h /usr/include/features.h
Select3.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select3.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select3.o: Select2.h Select4.h Select10.h
Select4.o: Select4.h Map.h /usr/include/string.h /usr/include/features.h
Select4.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select4.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select4.o: Select5.h Select3.h Select11.h
Select5.o: Select5.h Map.h /usr/include/string.h /usr/include/features.h
Select5.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select5.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select5.o: Select6.h Select4.h Select12.h
Select6.o: Select6.h Map.h /usr/include/string.h /usr/include/features.h
Select6.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select6.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select6.o: Select7.h Select5.h Select13.h
Select7.o: Select7.h Map.h /usr/include/string.h /usr/include/features.h
Select7.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select7.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select7.o: Select8.h Select6.h Select14.h
Select8.o: Select8.h Map.h /usr/include/string.h /usr/include/features.h
Select8.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select8.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select8.o: Select.h Select7.h Select9.h
Select9.o: Select8.h Map.h /usr/include/string.h /usr/include/features.h
Select9.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select9.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select9.o: Select2.h Select10.h Select9.h
Select.o: Select.h Map.h /usr/include/string.h /usr/include/features.h
Select.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Select.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h GameStart.h
Select.o: Select2.h Select8.h Select14.h
Tutorial.o: Tutorial.h Exit.h Block.h Water.h Bomb.h Plate.h Gate.h Dirt.h
Wall.o: Wall.h
Water.o: Water.h
