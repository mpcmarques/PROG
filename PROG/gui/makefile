CC=g++
CFLAGS=-c -Wall -std=c++11

LOGICPATH=../logic/

LOGICSOURCES=$(LOGICPATH)FileService.cpp $(LOGICPATH)Linha.cpp $(LOGICPATH)Transportadora.cpp $(LOGICPATH)Paragem.cpp $(LOGICPATH)Condutor.cpp $(LOGICPATH)Header.cpp

SOURCES=main.cpp $(LOGICSOURCES)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=prog

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	rm $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *o ../logic/*o prog
