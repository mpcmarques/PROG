//
//  Transportadora.cpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#include "Transportadora.hpp"

Transportadora::Transportadora(vector<Linha> linhas, vector<Condutor> condutores){
    this->linhas = linhas;
    this->condutores = condutores;
}
