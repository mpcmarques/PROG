#include "Paragem.hpp"

Paragem::Paragem(std::string nome){
  this->nome = nome;
}

const std::string Paragem::getNome(){
  return this->nome;
}
