#include "Condutor.hpp"



std::istream& operator>>(std::istream &is, Condutor &condutor){
  std::string str;
  std::string nome;
  std::string sobrenome;

  is >> condutor.uid >> str >> nome >> sobrenome >> str >> condutor.turno;
  is >> str >> condutor.horasPorSemana >> str >> condutor.descanso;

  condutor.nome = nome + " " + sobrenome;

  return is;
}

std::ostream& operator<<(std::ostream &os, Condutor &condutor){
  os << condutor.uid << " ; ";
  os << condutor.nome << " ; ";
  os << condutor.turno << " ; ";
  os << condutor.horasPorSemana << " ; ";
  os << condutor.descanso;

  return os;
}
