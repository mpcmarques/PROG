#ifndef MAIN_HPP
#define MAIN_HPP

#include "../logic/FileService.hpp"
#include <iomanip>
#include "Time.hpp"

/**
 * Mostra a paragem no console de modo formatado, lembrar de colocar um endl depois, pois ela é impressa na mesma linha.
 * @param paragem Paragem a ser mostrada
 */
void displayParagem(Paragem paragem);

/**
 * Calcular e visualizar um percurso e tempos entre duas quaisquer paragens indicadas pelo utilizador
 */
void calcularMostrarPercursoEntreParagens();

/**
 * Mostra as informações de uma linha de maneira formatada
 * @param linha Linha a ser mostrada
 */
void displayLinha(Linha linha);

/**
 * Lista as listas disponíveis no sistema
 */
void listarLinhasDisponiveis();

/**
* Mostra opções de remoção de linha.
*/
void removerLinha();

/**
* Mostra as opções de adição de uma linha
*/
void adicionarLinha();

/**
* Handler do menu de gestão de linnhas
* @param opt Opção escolhida da gestão de linhas
*/
void gerirLinhasHandler(int opt);

/**
* Apresentao menu de gestão de linhas
*/
void gerirLinhas();

/**
 * Mostra de maneira formatada as informações de um condutor
 * @param condutor Condutor a ser mostrado
 */
void displayCondutor(Condutor condutor);

/**
* Lista condutores disponíveis
*/
void listarCondutoresDisponiveis();

/**
* Mostra as opções de remoção de um condutor
*/
void removerCondutor();

/**
* Mostra o menu de adição de condutores
*/
void adicionarCondutor();

/**
* Handler do menu de gestão de linhas
* @param opt Opção escolhida da gestão de linhas
*/
void gerirCondutoresHandler(int opt);

/**
* Apresenta o menu de gestão de condutores
*/
void gerirCondutores();

/**
 * Mostra de maneira formatada os horários de uma paragem
 * @param tempoInicio Horário da primeira viagem
 * @param paragem     Paragem a ser mostrada
 * @param linha       Linha a qual pertence a paragem
 */
void displayHorariosParagem(Time tempoInicio, Paragem paragem, Linha linha);

/**
 * Mostra horários de uma determinada linha
 */
void verHorariosDeUmaLinha();

/**
 * Gerar e visualizar de modo formatado tabelas com horários de uma paragem
 */
void visualizarTabelaComHorarioDeUmaParagem();

/**
 * Visualizar o trabalho atribuído a um condutor.
 */
void visualizarTrabalhoDeUmCondutor();

/**
 * Inquirir sobe quais as linhas que incluem determinada paragem
 */
void inquirirLinhasDeDeterminadaParagem();

/**
* Handler do menu principal
* @param opt Opção do menu escolhida
*/
void menuOptHandler(int opt);

/**
* Mostra menu principal
*/
void showMenu();



#endif
