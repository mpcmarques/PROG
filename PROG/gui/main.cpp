//
//  main.cpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#include "../logic/Transportadora.hpp"
#include "../logic/FileService.hpp"
#include <unistd.h>


void showMenu();

int main(int argc, const char * argv[]) {
  FileService fileService;

  vector<Linha> linhas = fileService.getLinhas();
  vector<Condutor> condutores = fileService.getCondutores();

  Transportadora transportadora = Transportadora(linhas, condutores);

  cout << "Criado uma transportadora com " << linhas.size() << " linhas e " << condutores.size() << " condutores." << endl;

  //  mostrar menu
  //showMenu();

  //  terminar programa, salvar dados.
  fileService.saveData(transportadora);
  cout << "Dados salvos com sucesso!" << endl;
  return 0;
}

/**
* Apresentao menu de gestão de linhas
*/
void gerirLinhas(){
  //  TODO adicionar linha
  //  TODO remove linha
  //  TODO listar linhas disponíveis
}

/**
* Apresenta o menu de gestão de condutores
*/
void gerirCondutores(){
  //  TODO adicionar condutor
  //  TODO remover condutor
  //  TODO listar condutores disponíveis
}


void menuOptHandler(int opt){

}

void showMenu(){
  int opt;

  cout << "Bem vindo a transportradora" << endl;
  cout << "O que deseja fazer?" << endl;

  //  opcoes
  cout << "1 -> Gerir linhas" << endl;
  cout << "2 -> Gerir condutores" << endl;
  cout << "3 -> Gerar e visualizar horários de uma paragem" << endl;
  cout << "4 -> Visualizar trabalho de um condutor" << endl;
  cout << "5 -> Inquirir sobre quais linhas que incluem determinada paragem" << endl;
  cout << "6 -> Calcular e visualizar um percurso e tempos entre duas paragens" << endl;
  cout << "7 -> Calcular para uma linha quantos condutores são necessários" << endl;
  cout << "0 -> Sair" << endl;

  //  verificar input
  if (!(cin >> opt) || opt > 7 || opt < 0) {
    cout << "Opção inválida!" << endl;
    return;
  }

  menuOptHandler(opt);
}
