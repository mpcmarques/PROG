#include "Autocarro.hpp"

Autocarro:: Autocarro(int linhaId, int condutorId, int ordemNaLinha){
  this->linhaId = linhaId;
  this->condutorId = condutorId;
  this->ordemNaLinha = ordemNaLinha;
}

void Autocarro::addTurno(Turno turno){
  this->programacao.push_back(turno);
}
