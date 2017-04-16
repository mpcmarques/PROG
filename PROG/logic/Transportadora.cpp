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

void Transportadora::addLinha(Linha linha){
  this->linhas.push_back(linha);
}

void Transportadora::addCondutor(Condutor condutor){
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
