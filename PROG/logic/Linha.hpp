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

/**
 Representa uma linha
 */
class Linha {
    int uid;                    //  id unico
    int freq;                   //  frequencia de circulacao
    vector<Paragem> paragens;   //  paragens que constituem
    vector<int> tempos;         //  tempos de viagens

public:

  /**
   * Operator function
   */
  friend istream& operator>> (istream &is, Linha &linha);
  friend ostream& operator<< (ostream &os, Linha &linha);
};



#endif /* linha_h */
