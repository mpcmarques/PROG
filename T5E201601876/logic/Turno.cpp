#include "Turno.hpp"


Turno::Turno(int linhaUID, int condutorUID, int numAutocarroNaLinha, Time tempoInicio, Time tempoFim){
  this->linhaUID = linhaUID;
  this->condutorUID = condutorUID;
  this->numAutocarroNaLinha = numAutocarroNaLinha;
  this->tempoInicio = tempoInicio;
  this->tempoFim = tempoFim;
}
