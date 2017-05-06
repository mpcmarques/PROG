#ifndef TURNO_HPP
#define TURNO_HPP


#include "Time.hpp"

/**
 * Representa um turno de um motorista
 */
class Turno {
private:

int linhaUID;
int condutorUID;
int numAutocarroNaLinha;
Time tempoInicio;
Time tempoFim;

public:
Turno(int linhaUID, int condutorUID, int numAutocarroNaLinha, Time tempoInicio, Time tempoFim);

};



#endif
