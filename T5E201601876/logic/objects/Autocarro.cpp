#include "Autocarro.hpp"

Autocarro:: Autocarro(int linhaId, int condutorId, int ordemNaLinha){
  this->linhaId = linhaId;
  this->condutorId = condutorId;
  this->ordemNaLinha = ordemNaLinha;
}

const std::vector<Turno> Autocarro::getProgramacao(){
  return this->programacao;
}

void Autocarro::removerTurno(Turno turno){
  for (int i = 0; i < (int)programacao.size() ; i++) {
    if (programacao[i] == turno) {
        this->programacao.erase(programacao.begin() + i);
        i--;
    }
  }
}

void Autocarro::addTurno(Turno turno){
  this->programacao.push_back(turno);
}

const int Autocarro::getOrdemNaLinha(){
  return this->ordemNaLinha;
}
const int Autocarro::getCondutorId(){
  return this->condutorId;
}
const int Autocarro::getLinhaId(){
  return this->linhaId;
}
