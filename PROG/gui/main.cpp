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

//  mantem uma só instância da transportadora
static Transportadora transportadora;

void showMenu();

int main(int argc, const char * argv[]) {
  FileService fileService;

  vector<Linha> linhas = fileService.getLinhas();
  vector<Condutor> condutores = fileService.getCondutores();

  transportadora = Transportadora(linhas, condutores);

  cout << "Foi carregado uma transportadora com " << linhas.size() << " linhas e " << condutores.size() << " condutores." << endl;

  //  mostrar menu
  showMenu();

  //  terminar programa, salvar dados.
  fileService.saveData(transportadora);
  cout << endl << "Dados salvos com sucesso!" << endl;
  return 0;
}

//  MARK: GUI

void listarLinhasDisponiveis(){
  std::vector<Linha> linhas = transportadora.getLinhas();
  int count = 0;
  for (Linha linha: linhas) {
    cout << count++ << " ~>" << " " << linha << endl;
  }
}

/**
 * Mostra opções de remoção de linha.
 */
void removerLinha(){
  unsigned int opt;

  //  mostrar linhas
  listarLinhasDisponiveis();
  //  pedir para escolher linha
  cout << "Deseja remover qual linha? " << endl;

  if (!(cin >> opt) || opt > transportadora.getLinhas().size()){
    cout << "Opção inválida" << endl;
    return;
  }

  transportadora.removerLinha(opt);
  cout << "Linha removida com sucesso!" << endl;
}

/**
 * Handler do menu de gestão de linnhas
 * @param opt Opção escolhida da gestão de linhas
 */
void gerirLinhasHandler(int opt){
  switch (opt) {
    case 1: // TODO adiciona linha
    break;
    case 2: removerLinha();
    break;
    case 3: listarLinhasDisponiveis();
    default:
    break;
  }
}

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
  // chamar handler
  gerirLinhasHandler(opt);
}

/**
 * Lista condutores disponíveis
 */
void listarCondutoresDisponiveis(){
  std::vector<Condutor> condutores = transportadora.getCondutores();
  int count = 0;
  for (Condutor condutor: condutores) {
    cout << count++ << " ~>" << " " << condutor.getUid() << " " << condutor.getNome() << endl;
  }
}

/**
 * Mostra as opções de remoção de um condutor
 */
void removerCondutor(){
  unsigned int opt;

  //  mostrar linhas
  listarCondutoresDisponiveis();

  //  pedir para escolher linha
  cout << "Deseja remover qual condutor?" << endl;

  if (!(cin >> opt) || opt > transportadora.getCondutores().size()){
    cout << "Opção inválida" << endl;
    return;
  }

  transportadora.removerCondutor(opt);
  cout << "Condutor removido com sucesso!" << endl;
}

/**
 * Handler do menu de gestão de linnhas
 * @param opt Opção escolhida da gestão de linhas
 */
void gerirCondutoresHandler(int opt){
  switch (opt) {
    case 1: // TODO adiciona condutor
    break;
    case 2: // TODO remove condutor
    break;
    case 3: listarCondutoresDisponiveis();
    default:
    break;
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
  //  chamar handler
  gerirCondutoresHandler(opt);
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
