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

const int Time::getTimeMinutes(){
  return this->getHoras()*60 + this->getMinutos();
}

const Time Time::operator-(Time &t1){
  int minutosTotaisFinais = getTimeMinutes() - t1.getTimeMinutes();
  if (minutos < 0 ) minutos = 0;
  
  // tempo a retornar
  Time timeToReturn = Time(0, 0);
  timeToReturn.addMinutos(minutosTotaisFinais);

  return timeToReturn;
}

Time::Time(int horas, int minutos){
  this->horas = horas;
  this->minutos = minutos;
}

void Time::addMinutos(int minutos){
  this->minutos += minutos;

  while (this->minutos >= 60) {
    this->horas += 1;
    this->minutos = this->minutos - 60;
  }
}

const int Time::getHoras(){
  return this->horas;
}
const int Time::getMinutos(){
  return this->minutos;
}
