//
//  Time.cpp
//  prog
//
//  Created by <author> on 16/04/2017.
//
//

#include "Time.hpp"

Time::Time(){
  this->horas = 0;
  this->minutos = 0;
}

Time::Time(int horas, int minutos){
  this->horas = horas;
  this->minutos = minutos;
}

void addMinutos(int minutos);

const int Time::getHoras(){
  return this->horas;
}
const int Time::getMinutos(){
  return this->horas;
}
