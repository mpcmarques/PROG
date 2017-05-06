//
//  Transportadora.cpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#include "Transportadora.hpp"

void Transportadora::atribuirCondutorPorAutocarro(){

  for (Condutor condutor: condutores) {



  }
}

Transportadora::Transportadora(vector<Linha> linhas, vector<Condutor> condutores){
    this->linhas = linhas;
    this->condutores = condutores;
    // cria autocarros
    criarAutocarros();
    // atribuir condutor por autocarro
}

Transportadora::Transportadora(){
  this->linhas = vector<Linha>();
  this->condutores = vector<Condutor>();
}

void Transportadora::criarAutocarros(){
  // loop linhas
  for(Linha linha: getLinhas()){
    vector<Autocarro> autocarros;
    int ordemNaLinha = 1;

    // para cada autocarro necessario
    for(int i = 0; i < linha.getNumeroAutocarrosNecessarios(); i++){ // loop autocarros necessarios

      // criar autocarro
      Autocarro autocarro = Autocarro(linha.getUid(), -1, ordemNaLinha);

      // criar um turno por dia da semana
      for (int i = 0; i < 6; i++) {
        // tempo de inicio do turno
        Time tempoInicioTurno = TEMPO_INICIO;
        tempoInicioTurno.addMinutos( (ordemNaLinha-1) * linha.getFreq() );
        // tempo do fim do turno
        Time tempoFimTurno = tempoInicioTurno;
        tempoFimTurno.addMinutos(linha.getTempoPercurso()*2);
        // criar objeto
        Turno turno = Turno(linha.getUid(), -1, ordemNaLinha, tempoInicioTurno, tempoFimTurno);
        // adicionar ao autocarro
        autocarro.addTurno(turno);
      }

      // adicionar na lista
      autocarros.push_back(autocarro);

      // acrescentar num na linha
      ordemNaLinha++;
    }
  }
  // adicionar a transportadora
  this->autocarros = autocarros;
}

vector<Linha> Transportadora::getLinhasComParagem(string nome){
  vector<Linha> foundLinhas;

  for (Linha linha: this->linhas) {
    for(Paragem paragem: linha.getParagens()){
      if (paragem.getNome() == nome) {
        foundLinhas.push_back(linha);
      }
    }
  }
  return foundLinhas;
}

void Transportadora::addLinha(const Linha linha){
  this->linhas.push_back(linha);
}

void Transportadora::addCondutor(const Condutor condutor){
  this->condutores.push_back(condutor);
}

void Transportadora::removerLinha(int opt){
  this->linhas.erase(linhas.begin() + opt);
}

void Transportadora::removerCondutor(int opt){
  this->condutores.erase(condutores.begin() + opt);
}

vector<Condutor> Transportadora::getCondutores(){
  return this->condutores;
}

vector<Linha> Transportadora::getLinhas(){
  return this->linhas;
}
