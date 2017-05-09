#include "Paragem.hpp"

Paragem::Paragem(std::string nome){
  this->nome = nome;
}

string Paragem::getNome() const {
  return this->nome;
}
