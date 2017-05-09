//
//  linha.hpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#ifndef linha_h
#define linha_h

/* Includes */
#include "Paragem.hpp"
#include <vector>
#include "../services/Utility.hpp"

/**
 Representa uma linha
 */
class Linha {
    int uid;                         //  id unico
    int freq;                        //  frequencia de circulacao
    std::vector<Paragem> paragens;   //  paragens que constituem
    std::vector<int> tempos;         //  tempos de viagens

public:
    // construtores
    Linha() {};

    Linha(int uid, int freq, std::vector<Paragem> paragens, std::vector<int> tempos);

    const int getPosParagem(string nome);

    int calcularTempoTotalEntreParagens(int posPrimeiraParagem, int posSegundaParagem);

    // getters
    const int getUid();

    vector<Paragem> getParagens()const;

    vector<int> getTempos()const;

    const int getFreq();

    const int getTempoPercurso();

    const int getNumeroAutocarrosNecessarios();

    // operator files IO
    friend std::istream &operator>>(std::istream &is, Linha &linha);

    friend std::ostream &operator<<(std::ostream &os, Linha &linha);
};



#endif /* linha_h */
