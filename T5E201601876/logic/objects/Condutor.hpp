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
#include <vector>
#include "Autocarro.hpp"

class Condutor {
  int uid;                      //n de identificacao unico
  int turnoMax;                    //n de minutos do turno
  int horasPorSemana;           //n de minutos trabalhados por semana
  int descanso;                 //n de de minutos em descanso
  std::string nome;             //nome do condutor
  std::vector<Turno> turnos;    //turnos

public:
  // construtores
  Condutor();              //  to be used by file I/O
  Condutor(int uid, std::string nome, int turno, int horasPorSemana, int descanso);

  void addTurno(Turno turno);

  // gets
  std::string getNome();
  int getUid();
  int getTurnoMax();
  int getDescanso();
  int getHorasPorSemana();
  std::vector<Turno> getTurnos();

  // operadores file IO
  friend std::istream& operator>>(std::istream &is, Condutor &condutor);
  friend std::ostream& operator<<(std::ostream &os, Condutor &condutor);
};

#endif /* Condutor_h */
