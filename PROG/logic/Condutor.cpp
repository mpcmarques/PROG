#include "Condutor.hpp"


istream& operator>>(istream &is, Condutor &condutor){
  string str;

  is >> condutor.uid >> str >> condutor.nome >> str >> str >> condutor.turno;
  is >> str >> condutor.horasPorSemana >> str >> condutor.descanso;

  return is;
}

ostream& operator<<(ostream &os, Condutor &condutor){
  os << condutor.uid << " ; ";
  os << condutor.nome << " ; ";
  os << condutor.turno << " ; ";
  os << condutor.horasPorSemana << " ; ";
  os << condutor.descanso;

  return os;
}
