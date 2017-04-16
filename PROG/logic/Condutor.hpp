//
//  Condutor.hpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#ifndef Condutor_h
#define Condutor_h

#include <iostream>
#include <string>
#include <stdlib.h>

class Condutor {
    int uid;            //n de identificacao unico
    int turno;          //n de horas por turno
    int horasPorSemana; //n de horas trabalhadas por semana
    int descanso;       //n de horas de descanso obrigatório entre os turnos
    std::string nome;        //nome do condutor

public:
  Condutor(){}; //  to be used by file I/O
  
  Condutor(int uid, std::string nome, int turno, int horasPorSemana, int descanso);

  std::string getNome(){ return nome;};
  int getUid(){ return uid; };

  friend std::istream& operator>>(std::istream &is, Condutor &condutor);
  friend std::ostream& operator<<(std::ostream &os, Condutor &condutor);
};

#endif /* Condutor_h */
