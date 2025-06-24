
app:precomp
	g++ -c main.cpp player.cpp button.cpp bg.cpp enemy.cpp pool.cpp bullet.cpp
	g++ main.o player.o button.o bg.o enemy.o pool.o bullet.o -o app -lsfml-graphics -lsfml-window -lsfml-system
	./app

precomp:
	touch app
	rm app


clean:
	rm *.o
