//
// Created by mateus on 08/05/17.
//

#ifndef PROG_RESULTADOPERCURSO_H
#define PROG_RESULTADOPERCURSO_H


#include "Linha.hpp"

/**
 * Classe representa um percurso
 * */
class Percurso {
    Linha linha;
    int posPrimeiraParagem;
    int posSegundaParagem;
    int tempoPercurso;

public:
    /**
     * Construtor da classe Percurso
     * @param posPrimeiraParagem Posicao da primeira paragem na linha
     * @param posSegundaParagem Posicao da segunda paragem na linha
     * @param linha Linha do percurso
     * @param tempoPercurso Tempo total de percurso
     */
    Percurso(int posPrimeiraParagem, int posSegundaParagem, Linha linha, int tempoPercurso);

    // getters
    int getTempoPercurso();
    int getPosPrimeiraParagem() const;
    int getPosSegundaParagem() const;
    const Linha &getLinha() const;
};

/**
 * Classe representa um resultado de uma consulta de percurso valida
 * */
class ResultadoPercurso {
    vector<Percurso> percursos;

public:
    ResultadoPercurso();

    /*
     * Adiciona tempo ao percurso
     */
    void addPercurso(Percurso percurso);

    // getters
    const vector<Percurso> &getPercursos() const;
    int getTempoTotal() const;
};

/**
 * Classe e utilizada na priority queue ordenada pela tempo de distancia
 */
class ResultadoCompare {
public:
    bool operator()(const ResultadoPercurso &r1, const ResultadoPercurso &r2) const {
        return r1.getTempoTotal() > r2.getTempoTotal();
    }
};


#endif //PROG_RESULTADOPERCURSO_H
