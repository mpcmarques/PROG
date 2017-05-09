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

class Paragem {
  std::string nome;

public:
  Paragem(std::string nome);

    string getNome() const;

};


#endif /* Paragem_h */
