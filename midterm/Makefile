OBJECTS=main.o node.o funcs.o
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o node.o funcs.o
	$(CXX) -o main $(OBJECTS)

tests: tests.o node.o funcs.o
	$(CXX) -o tests tests.o node.o funcs.o

main.o: main.cpp node.h funcs.h

funcs.o: funcs.cpp node.h

node.o: node.cpp node.h

tests.o: tests.cpp node.h funcs.h

clean:
	rm -f $(OBJECTS) tests.o
