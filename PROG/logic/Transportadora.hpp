//
//  Transportadora.hpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#ifndef Transportadora_h
#define Transportadora_h

#include "Linha.hpp"
#include "Condutor.hpp"

class Transportadora {
    vector<Linha> linhas;
    vector<Condutor> condutores;

public:

    Transportadora(vector<Linha> linhas, vector<Condutor> condutores);

    vector<Condutor> getCondutores();
    vector<Linha> getLinhas();
};


#endif /* Transportadora_h */
