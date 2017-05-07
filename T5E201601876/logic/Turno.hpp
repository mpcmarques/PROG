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
int ordemNaLinha;
int tempoInicio;
int tempoFim;

public:
Turno(int linhaUID, int condutorUID, int numAutocarroNaLinha, int tempoInicio, int tempoFim);

const bool operator ==(Turno &i1);

// getters
const int getCondutorId();
const int getTempoInicio();
const int getTempoFim();
const int getTempoTotalEmMinutos();
const int getOrdemNaLinha();
const int getLinhaId();

// setters
void setCondutorUID(int conturoUID);
};


#endif
