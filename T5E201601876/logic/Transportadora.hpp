//
//  Transportadora.hpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.

#ifndef Transportadora_h
#define Transportadora_h

#include "Linha.hpp"
#include "Condutor.hpp"

using namespace std;

class Transportadora {
    vector<Linha> linhas;
    vector<Condutor> condutores;

public:
    Transportadora();
    Transportadora(std::vector<Linha> linhas, std::vector<Condutor> condutores);

    void removerCondutor(int opt);
    void removerLinha(int opt);

    void addLinha(const Linha linha);
    void addCondutor(const Condutor condutor);

    vector<Linha> getLinhasComParagem(string nome);

    //  getters
    std::vector<Condutor> getCondutores();
    std::vector<Linha> getLinhas();
};


#endif /* Transportadora_h */
