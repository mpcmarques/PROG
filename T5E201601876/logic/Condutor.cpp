#include "Condutor.hpp"

Condutor::Condutor(){}

Condutor::Condutor(int uid, std::string nome, int turno, int horasPorSemana, int descanso){
  this->uid = uid;
  this->nome = nome;
  this->turno = turno;
  this->horasPorSemana = horasPorSemana;
  this->descanso = descanso;
}

std::string Condutor::getNome(){
   return nome;
 }
int Condutor::getUid(){
  return uid;
}
int Condutor::getTurno(){
  return turno;
}
int Condutor::getDescanso(){
  return descanso;
}
int Condutor::getHorasPorSemana(){
  return horasPorSemana;
}

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
