CC=g++
CFLAGS=-c -Wall -std=c++11

## paths
LOGICPATH=logic/
SERVICEPATH=$(LOGICPATH)services/
OBJECTSPATH=$(LOGICPATH)objects/

SERVICESOURCES=$(SERVICEPATH)FileService.cpp $(SERVICEPATH)Utility.cpp
OBJECTSSOURCES=$(OBJECTSPATH)Time.cpp $(OBJECTSPATH)Linha.cpp $(OBJECTSPATH)Transportadora.cpp $(OBJECTSPATH)Paragem.cpp $(OBJECTSPATH)Condutor.cpp $(OBJECTSPATH)ResultadoPercurso.cpp $(OBJECTSPATH)Autocarro.cpp $(OBJECTSPATH)Turno.cpp
LOGICSOURCES=$(SERVICESOURCES) $(OBJECTSSOURCES)

SOURCES=gui/main.cpp $(LOGICSOURCES)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=prog.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	rm $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o prog.out
