//
//  Transportadora.cpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#include "Transportadora.hpp"

Transportadora::Transportadora(vector<Linha> linhas, vector<Condutor> condutores){
    this->linhas = linhas;
    this->condutores = condutores;
}

Transportadora::Transportadora(){
  this->linhas = vector<Linha>();
  this->condutores = vector<Condutor>();
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
