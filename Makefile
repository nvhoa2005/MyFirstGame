all:
	g++ -Isource64/include -Lsource64/lib -o main main.cpp Base.cpp Defs.cpp Map.cpp Time.cpp Player.cpp Menu.cpp Text.cpp  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf