objects = main.o leiqu.o
name =saolei.exe
$(name)  : $(objects)
		g++ $(objects) -o $(name)
main.o : main.cpp leiqu.h
		g++ -c main.cpp
leiqu.o : leiqu.cpp leiqu.h
		g++ -c leiqu.cpp	
run :   $(name)
		$(name)
clean :
		del *.o
		del *.exe