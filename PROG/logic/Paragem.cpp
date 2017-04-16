#include "Paragem.hpp"

Paragem::Paragem(std::string nome){
  this->nome = nome;
}

std::string Paragem::getNome(){
  return this->nome;
}
