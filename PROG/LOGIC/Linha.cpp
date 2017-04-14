#include "Linha.hpp"


istream& operator>> (istream &is, Linha &linha){
  string str;

  getline(is, str);

  return is;
}

ostream& operator<< (ostream &os, Linha &linha){

  os << linha.uid;
  os << " ; ";
  os << linha.freq;
  os << " ; ";

  return os;
}
