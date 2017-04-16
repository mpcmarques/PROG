//
//  FileService.cpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#include "FileService.hpp"

void FileService::saveData(Transportadora transportadora){
  //  salvar condutores
  ofstream ficheiroCondutores;
  ficheiroCondutores.open(TXT_CONDUTORES);

  for (Condutor cond: transportadora.getCondutores()) {
    ficheiroCondutores << cond << endl;
  }
  ficheiroCondutores.close();

  //  salvar linhas
  ofstream ficheiroLinhas;
  ficheiroLinhas.open(TXT_LINHAS);

  for (Linha linha: transportadora.getLinhas()) {
    ficheiroLinhas << linha << endl;
  }
  ficheiroCondutores.close();
}

vector<Condutor> FileService::getCondutores(){
  //  começar com arrays vazias
  vector<Condutor> newCondutores = vector<Condutor>();

  //  abrir ficheiro de condutores
  ifstream ficheiroCondutores;
  ficheiroCondutores.open(TXT_CONDUTORES);

  //  ver se ficheiro esta aberto
  if (ficheiroCondutores.is_open()) {
    // loop de linhas do ficheiro
    while(!ficheiroCondutores.eof()){
      Condutor condutor;

      if (ficheiroCondutores >> condutor)
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
  ficheiroLinhas.open(TXT_LINHAS);

  //  ver se ficheiro esta aberto
  if (ficheiroLinhas.is_open()) {
    // loop de linhas do ficheiro
    while (!ficheiroLinhas.eof()) {
      //  criar nova linha e obter dados
      Linha linha;

      if(ficheiroLinhas >> linha)
        newLinhas.push_back(linha);
    }
  }
  //  retornar as linhas adquiridas
  ficheiroLinhas.close();
  return newLinhas;
}
