//
//  Paragem.hpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#ifndef Paragem_h
#define Paragem_h

#include <iostream>

using namespace std;

/**
 * Classe representa uma paragem de autocarros
 */
class Paragem {
    std::string nome;

public:
    /**
     * Construtor
     * @param nome  Nome da paragem
     */
    Paragem(std::string nome);

    /**
     *
     * @return Nome da paragem
     */
    string getNome() const;

};


#endif /* Paragem_h */
