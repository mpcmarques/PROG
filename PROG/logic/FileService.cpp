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
    do {
      string linha;

      getline(ficheiroCondutores, linha);

      cout << linha << endl;
    } while (!ficheiroCondutores.eof());
    
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
      Linha linha;

      ficheiroLinhas >> linha;

      newLinhas.push_back(linha);
    }
  }

  ficheiroLinhas.close();
  return newLinhas;
}
