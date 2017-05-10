#include "Turno.hpp"

void Turno::setCondutorUID(int condutorId){
    this->condutorUID = condutorId;
}

const int Turno::getOrdemNaLinha(){
    return this->ordemNaLinha;
}

Turno::Turno(int linhaUID, int condutorUID, int numAutocarroNaLinha, int tempoInicio, int tempoFim){
    this->linhaUID = linhaUID;
    this->condutorUID = condutorUID;
    this->ordemNaLinha = numAutocarroNaLinha;
    this->tempoInicio = tempoInicio;
    this->tempoFim = tempoFim;
}

const int Turno::getLinhaId(){
    return this->linhaUID;
}

const int Turno::getTempoTotalEmMinutos(){
    return tempoFim - tempoInicio;
}

const int Turno::getCondutorId(){
    return this->condutorUID;
}

const bool Turno::operator==(Turno &i1){
    return i1.condutorUID == this->condutorUID && i1.linhaUID == this->linhaUID &&
           i1.ordemNaLinha == this->ordemNaLinha && i1.tempoInicio == this->tempoInicio &&
           i1.tempoFim == this->tempoFim;
}

const int Turno::getTempoInicio(){
    return this->tempoInicio;
}

const int Turno::getTempoFim(){
    return this->tempoFim;
}
