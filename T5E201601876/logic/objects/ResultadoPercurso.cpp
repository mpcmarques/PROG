//
// Created by mateus on 08/05/17.
//

#include "ResultadoPercurso.h"

Percurso::Percurso(int posPrimeiraParagem, int posSegundaParagem, Linha linha, int tempoPercurso) {
    this->posPrimeiraParagem = posPrimeiraParagem;
    this->posSegundaParagem = posSegundaParagem;
    this->linha = linha;
    this->tempoPercurso = tempoPercurso;
}

int Percurso::getTempoPercurso() {
    return this->tempoPercurso;
}

const Linha &Percurso::getLinha() const {
    return linha;
}

int Percurso::getPosPrimeiraParagem() const {
    return posPrimeiraParagem;
}

int Percurso::getPosSegundaParagem() const {
    return posSegundaParagem;
}

ResultadoPercurso::ResultadoPercurso() {}

void ResultadoPercurso::addPercurso(Percurso percurso) {
    this->percursos.push_back(percurso);
}

int ResultadoPercurso::getTempoTotal() const {
    int total = 0;
    for (Percurso perc: percursos) {
        total += perc.getTempoPercurso();
    }
    return total;
}

const vector<Percurso> &ResultadoPercurso::getPercursos() const {
    return percursos;
}
