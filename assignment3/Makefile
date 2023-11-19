objects = CellPhone.o Entity.o Tower.o Location.o Message.o List.o Tester.o

all: test
	
test: test.cc $(objects)
	g++ -o test test.cc $(objects)
	
CellPhone.o:	CellPhone.h CellPhone.cc
	g++ -c CellPhone.cc

Entity.o:	Entity.h Entity.cc
	g++ -c Entity.cc

Tower.o:	Tower.h Tower.cc
	g++ -c Tower.cc

List.o:	List.h List.cc
	g++ -c List.cc

Message.o:	Message.h Message.cc
	g++ -c Message.cc

Location.o:	Location.h Location.cc
	g++ -c Location.cc

Tester.o:	Tester.h Tester.cc
	g++ -c Tester.cc
	
clean:
	rm -f test *.o
