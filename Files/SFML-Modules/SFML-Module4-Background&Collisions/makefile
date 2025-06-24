
app:precomp
	g++ -c main.cpp player.cpp button.cpp bg.cpp enemy.cpp
	g++ main.o player.o button.o bg.o enemy.o -o app -lsfml-graphics -lsfml-window -lsfml-system
	./app

precomp:
	touch app
	rm app


clean:
	rm *.o
