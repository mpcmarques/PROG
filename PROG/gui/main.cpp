//
//  main.cpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//
#include "../logic/FileService.hpp"
#include <iomanip>
#include "Time.hpp"

using namespace std;

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
  int count = 1;
  for (Linha linha: linhas) {
    cout << count++ << " ~>" << " " << linha << endl;
  }
}

/**
* Mostra opções de remoção de linha.
*/
void removerLinha(){
  unsigned int opt;
  cout << " - Remover Linha - " << endl;
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
* Mostra as opções de adição de uma linha
*/
void adicionarLinha(){
  vector<Paragem> newParagens;
  vector<int> newTempos;

  cout << " - Adicionar linha - " << endl;
  //  frequencia
  int freq;
  cout << "Qual a frequência?" << endl;
  if (!(cin >> freq) || freq < 0){
    cout << "Frequência inválida" << endl;
    return;
  }

  //  paragens
  int numParagens;
  cout << "Qual a quantidade de paragens que a linha vai ter? " << endl;

  if(!(cin >> numParagens) || numParagens < 0){
    cout << "Número de paragens inválido" << endl;
    return;
  }

  cin.ignore();
  //  loop adicionando paragens
  for (int i = 1; i <= numParagens; i++) {
    string nome;
    cout << "Qual o nome da " << i << " paragem?" << endl;

    if (!(getline(cin, nome))){
      cout << "Erro: Nome inválido!" << endl;
      return;
    }

    Paragem paragem = Paragem(nome);
    newParagens.push_back(paragem);
  }

  // adicionar tempos
  for(int i = 1; i <= (int)newParagens.size(); i++){
    int tempo;
    cout << "Qual o tempo do " << i << " percurso?" << endl;

    if (!(cin >> tempo) || tempo < 0) {
      cout << "Erro: Tempo inválido!" << endl;
      return;
    }

    newTempos.push_back(tempo);
  }

  Linha linha = Linha(transportadora.getLinhas().size(), freq, newParagens, newTempos);
  transportadora.addLinha(linha);

  cout << "Linha adicionada com sucesso!" << endl;
}

/**
* Handler do menu de gestão de linnhas
* @param opt Opção escolhida da gestão de linhas
*/
void gerirLinhasHandler(int opt){
  switch (opt) {
    case 1: adicionarLinha();
    break;
    case 2: removerLinha();
    break;
    case 3: listarLinhasDisponiveis();
    break;
    case 4: // TODO editar linha
    break;
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
  //  TODO gerir linhas
  cout << "0 -> Voltar ao menu" << endl;

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
  cout << " - Remover condutor - " << endl;
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
* Mostra o menu de adição de condutores
*/
void adicionarCondutor(){
  string nome;
  int turno, horasPorSemana, descanso;

  cout << " - Adicionar Condutor - " << endl;
  cout << "Qual o nome do condutor?" << endl;
  //nome
  cin.ignore();
  if(!(getline(cin, nome))){
    cout << "Erro: nome inválido!" << endl;
    return;
  }
  //turno
  cout << "Quantas horas é o turno diário?" << endl;
  if (!(cin >> turno) || turno > 24 || turno < 0){
    cout << "Erro: turno inválido!" << endl;
    return;
  }
  //horas por semana
  cout << "Quantas horas por semana?" << endl;
  if (!(cin >> horasPorSemana) || horasPorSemana > 168 || horasPorSemana < 0){
    cout << "Erro: horas por semana inválida!" << endl;
    return;
  }
  //descanso
  cout << "Qual o número mínimo de horas de descanso?"<< endl;
  if (!(cin >> descanso) || descanso > 24 || descanso < 0) {
    cout << "Erro: horário de descanso inválido" << endl;
  }

  Condutor condutor = Condutor(transportadora.getCondutores().size(), nome, turno,  horasPorSemana, descanso);

  transportadora.addCondutor(condutor);
  cout << "Condutor adicionado com sucesso!" << endl;
}

/**
* Handler do menu de gestão de linhas
* @param opt Opção escolhida da gestão de linhas
*/
void gerirCondutoresHandler(int opt){
  switch (opt) {
    case 1: adicionarCondutor();
    break;
    case 2: removerCondutor();
    break;
    case 3: listarCondutoresDisponiveis();
    break;
    case 4: //  TODO editar condutor
    break;
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
  //  TODO editar condutor
  cout << "0 -> Voltar ao menu" << endl;

  if (!(cin >> opt) || opt < 0 || opt > 4) {
    cout << "Opção inválida!" << endl;
    return;
  }
  //  chamar handler
  gerirCondutoresHandler(opt);
}

void verHorariosDeUmaLinha(){
  int opt;

  cout << " - Visualizar horários de uma linha - " << endl;
  cout << "Escolha a linha:" << endl;
  listarLinhasDisponiveis();

  if (!(cin >> opt) || opt < 0 || opt > (int)transportadora.getLinhas().size()) {
    cout << "Erro: opção inválida" << endl;
    return;
  }
  //  print nome da linha
  Linha linha = transportadora.getLinhas()[opt-1];
  cout << setw(35) << setfill(' ') << "Linha: " << linha.getUid() << endl;
  //  print paragem final
  Paragem paragemFinal =  linha.getParagens().back();
  cout << setw(25) << setfill(' ') << "Rumo "<< paragemFinal.getNome() << endl;
  //linha de começo
  Time tempoInicio = Time(8,0);

  for (int i = 0; i < (int)linha.getParagens().size(); i++) {
    //set start time
    Time tempo = tempoInicio;

    //print paragem
    Paragem paragem = linha.getParagens()[i];
    cout << setw(3) << setfill(' ') << " ";
    cout << setw(10) << setfill(' ') << left << paragem.getNome() << endl;

    int count = 0;
    while (tempo.getHoras() < 22) {
      cout << setw(3) << setfill(' ') << " ";
      cout << setw(2) << setfill('0') << right << tempo.getHoras() << ":";
      cout << setw(2) << setfill('0') << tempo.getMinutos();
      cout << setw(3) << setfill(' ') << " ";
      tempo.addMinutos(linha.getFreq());

      count++;

      if (count == 6) {
        cout << endl;
        count = 0;
      }
    }
    tempoInicio.addMinutos(linha.getTempos()[i]);
    cout << endl;
    cout << endl;
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
    case 4: verHorariosDeUmaLinha();
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
  cout << "4 -> Gerar e visualizar horário de uma linha" << endl;
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

  if (opt != 0) {
    menuOptHandler(opt);
    //  chama menu recursivamente
    cout << "Tecle enter para voltar ao menu principal.." << endl;
    cin.ignore(); cin.ignore();
    showMenu();
  }
}
