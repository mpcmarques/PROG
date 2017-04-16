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

  cout << "Foi carregado uma transportadora com " << linhas.size() << " linhas e " << condutores.size() << " condutores." << endl;

  //  mostrar menu
  showMenu();

  //  terminar programa, salvar dados.
  fileService.saveData(transportadora);
  cout << endl << "Dados salvos com sucesso!" << endl;
  return 0;
}

//  MARK: GUI



/**
* Apresentao menu de gestão de linhas
*/
void gerirLinhas(){
  int opt;

  cout << endl << "## GERIR LINHAS ##" << endl;
  cout << "1 -> Adicionar linha " << endl;
  cout << "2 -> Remover linha" << endl;
  cout << "3 -> Listar linhas disponíveis" << endl;
  cout << "4 -> Voltar ao menu" << endl;
  cout << "0 -> Sair" << endl;

  if (!(cin >> opt) || opt < 0 || opt > 4) {
    cout << "Opção inválida!" << endl;
    return;
  }


}

/**
* Apresenta o menu de gestão de condutores
*/
void gerirCondutores(){
  int opt;

  cout << endl << "## GERIR CONDUTORES ##" << endl;
  cout << "1 -> Adicionar condutor" << endl;
  cout << "2 -> Remover condutor" << endl;
  cout << "3 -> Listar condutores disponíveis" << endl;
  cout << "4 -> Voltar ao menu" << endl;
  cout << "0 -> Sair" << endl;

  if (!(cin >> opt) || opt < 0 || opt > 4) {
    cout << "Opção inválida!" << endl;
    return;
  }
}

/**
 * Handler do menu principal
 * @param opt Opção do menu escolhida
 */
void menuOptHandler(int opt){
  switch (opt) {
    case 1: gerirLinhas();
    break;
    case 2: gerirCondutores();
    break;
    default: break;
  }
}

/**
 * Mostra menu principal
 */
void showMenu(){
  int opt;

  cout << endl <<  "## MENU PRINCIPAL ##" << endl;
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
