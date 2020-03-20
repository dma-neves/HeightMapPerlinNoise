INC_DIRECOTRY=src -I src -I src/pnHeightMap -I src/util -I src/pnHeightMap/rendering -I src/util/PerlinNoise2D
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

CPPC=g++ -std=c++11 -g

OBJECT_FILES=obj/main.o obj/PN_HeightMap.o obj/HeightMap.o obj/HeightMapRenderer.o obj/Vector2D.o obj/Octave.o

pnhmap.out: $(OBJECT_FILES)
	$(CPPC) $(OBJECT_FILES) -o bin/pnhmap.out $(LIBS)

obj/main.o: src/main.cpp
	$(CPPC) -c src/main.cpp -I $(INC_DIRECOTRY) -o obj/main.o

obj/PN_HeightMap.o: src/pnHeightMap/PN_HeightMap.h src/pnHeightMap/PN_HeightMap.cpp
	$(CPPC) -c src/pnHeightMap/PN_HeightMap.cpp -I $(INC_DIRECOTRY) -o obj/PN_HeightMap.o

obj/HeightMap.o: src/pnHeightMap/HeightMap.h src/pnHeightMap/HeightMap.cpp
	$(CPPC) -c src/pnHeightMap/HeightMap.cpp -I $(INC_DIRECOTRY) -o obj/HeightMap.o

obj/HeightMapRenderer.o: src/pnHeightMap/rendering/HeightMapRenderer.h src/pnHeightMap/rendering/HeightMapRenderer.cpp
	$(CPPC) -c src/pnHeightMap/rendering/HeightMapRenderer.cpp -I $(INC_DIRECOTRY) -o obj/HeightMapRenderer.o

obj/Vector2D.o: src/util/Vector2D.h src/util/Vector2D.cpp
	$(CPPC) -c src/util/Vector2D.cpp -I $(INC_DIRECOTRY) -o obj/Vector2D.o

obj/Octave.o: src/util/PerlinNoise2D/Octave.h src/util/PerlinNoise2D/Octave.cpp
	$(CPPC) -c src/util/PerlinNoise2D/Octave.cpp -I $(INC_DIRECOTRY) -o obj/Octave.o

clean:
	rm obj/*.o bin/pnhmap.out
