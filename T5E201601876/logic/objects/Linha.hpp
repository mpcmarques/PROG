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
* Classe representa uma linha
 */
class Linha {
    int uid;                         //  id unico
    int freq;                        //  frequencia de circulacao
    std::vector<Paragem> paragens;   //  paragens que constituem
    std::vector<int> tempos;         //  tempos de viagens

public:
    // construtores
    Linha() {};

    /**
     * Construtor
     * @param uid  Id da linha
     * @param freq Frequencia da linha
     * @param paragens Paragens da linha
     * @param tempos Tempo entre as paragens da linha
     */
    Linha(int uid, int freq, std::vector<Paragem> paragens, std::vector<int> tempos);

    /**
     * Retorna a posicao da paragem, se nao encontrar retorna -1
     * @param nome Nome da paragem
     * @return Posicao da paragem se existir, se nao -1
     */
    const int getPosParagem(string nome);

    /**
     * Calcula o tempo entre duas paragens
     * @param posPrimeiraParagem Posicao da primeira paragem na linha
     * @param posSegundaParagem Posicao da segunda paragem na linha
     * @return Tempo entre as duas paragens
     */
    int calcularTempoTotalEntreParagens(int posPrimeiraParagem, int posSegundaParagem);

    // getters
    int getUid() const;
    vector<Paragem> getParagens()const;
    vector<int> getTempos()const;

    int getFreq() const;

    int getTempoPercurso() const;

    int getNumeroAutocarrosNecessarios() const;

    // operator files IO
    friend std::istream &operator>>(std::istream &is, Linha &linha);
    friend std::ostream &operator<<(std::ostream &os, Linha &linha);
};



#endif /* linha_h */
