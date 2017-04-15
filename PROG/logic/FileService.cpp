//
//  FileService.cpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#include "FileService.hpp"


vector<Condutor> FileService::getCondutores(){
  //  começar com arrays vazias
  vector<Condutor> newCondutores = vector<Condutor>();

  //  abrir ficheiro de condutores
  ifstream ficheiroCondutores;
  ficheiroCondutores.open("condutores.txt");

  //  ver se ficheiro esta aberto
  if (ficheiroCondutores.is_open()) {
    // loop de linhas do ficheiro
    while(!ficheiroCondutores.eof()){
      Condutor condutor;

      ficheiroCondutores >> condutor;

      newCondutores.push_back(condutor);
    }
  }

  ficheiroCondutores.close();
  return newCondutores;
}


vector<Linha> FileService::getLinhas(){
  //  começar com arrays vazias
  vector<Linha> newLinhas = vector<Linha>();

  //  abrir ficheiro de linhas
  ifstream ficheiroLinhas;
  ficheiroLinhas.open("linhas.txt");

  //  ver se ficheiro esta aberto
  if (ficheiroLinhas.is_open()) {
    // loop de linhas do ficheiro
    while (!ficheiroLinhas.eof()) {
      //  criar nova linha e obter dados
      Linha linha;
      ficheiroLinhas >> linha;
      // adicionar linha ao novo vetor
      newLinhas.push_back(linha);
    }
  }
  //  retornar as linhas adquiridas
  ficheiroLinhas.close();
  return newLinhas;
}
