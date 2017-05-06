CC=g++
CFLAGS=-c -Wall -std=c++11

## paths
LOGICPATH=../logic/

LOGICSOURCES=$(LOGICPATH)FileService.cpp $(LOGICPATH)Linha.cpp $(LOGICPATH)Transportadora.cpp $(LOGICPATH)Paragem.cpp $(LOGICPATH)Condutor.cpp $(LOGICPATH)Header.cpp $(LOGICPATH)Autocarro.cpp $(LOGICPATH)Turno.cpp

SOURCES=main.cpp $(LOGICPATH)Time.cpp $(LOGICSOURCES)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=prog.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	rm $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *o ../logic/*o *gch ../logic/*gch prog
