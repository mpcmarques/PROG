#ifndef AUTOCARRO_HPP
#define AUTOCARRO_HPP

#include <iostream>
#include <vector>
#include "Turno.hpp"

/**
 * Representa um autocarro
 */
class Autocarro {
private:
    int ordemNaLinha;
    int linhaId;

    std::vector<Turno> programacao;

public:
    /**
     * Construtor do Autocarro
     * @param linhaId Id da linha do autocarro
     * @param ordemNaLinha Num ordem do autocarro na linha
    */
    Autocarro(int linhaId, int ordemNaLinha);

    /**
     * Adicionar um turno ao autocarro
     * @param turno Turno a ser adicionado
     */
    void addTurno(Turno turno);

    /**
     * Remove um turno do autocarro
     * @param turno Turno a ser removido
     */
    void removerTurno(Turno turno);

    /**
     * Retorna a programacao
     * @return  Turnos do autocarro
     */
    const std::vector<Turno> getProgramacao();

    /**
     * Retorna a ordem na linha do autocarro
     * @return ordem na linha do autocarro
     */
    const int getOrdemNaLinha();

    /**
     * Retorna o id da linha do autocarro
     * */
    const int getLinhaId();
};







#endif
