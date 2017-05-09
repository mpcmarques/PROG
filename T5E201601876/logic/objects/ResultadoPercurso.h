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
    Percurso(int posPrimeiraParagem, int posSegundaParagem, Linha linha, int tempoPercurso);

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
    const vector<Percurso> &getPercursos() const;

public:
    ResultadoPercurso();

    void addPercurso(Percurso percurso);

    int getTempoTotal() const;

};

class ResultadoCompare {
public:
    bool operator()(const ResultadoPercurso &r1, const ResultadoPercurso &r2) const {
        return r1.getTempoTotal() < r2.getTempoTotal();
    }
};


#endif //PROG_RESULTADOPERCURSO_H
