
all:
	cc -c ./src/main.cpp -o ./obj/main.o
	cc -c ./src/models/LinkedList.cpp -o ./obj/linkedlist.o
	cc -c ./src/models/Yard.cpp -o ./obj/yard.o
	cc -c ./src/models/Player.cpp -o ./obj/player.o
	cc -c ./src/models/Card.cpp  -o ./obj/card.o
	cc -c ./src/models/Drawer.cpp -o ./obj/drawer.o
	cc -c ./src/InputDetector.cpp -o ./obj/input.o
	cc -o ./build/main ./obj/main.o ./obj/yard.o ./obj/input.o ./obj/player.o ./obj/drawer.o  ./obj/card.o ./obj/linkedlist.o  -lstdc++ -lm  -s -lraylib

clean:
	rm -rf ./obj/*.o
	rm -rf ./build/*.*
