#include "Condutor.hpp"


istream& operator>>(istream &is, Condutor &condutor){
  string str;
  string nome;
  string sobrenome;

  is >> condutor.uid >> str >> nome >> sobrenome >> str >> condutor.turno;
  is >> str >> condutor.horasPorSemana >> str >> condutor.descanso;

  condutor.nome = nome + " " + sobrenome;

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
