//
//  main.cpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#include "../LOGIC/Transportadora.hpp"
#include "../LOGIC/FileService.hpp"

int main(int argc, const char * argv[]) {
  vector<Linha> linhas = FileService().getLinhas();
  //vector<Condutor> condutores = FileService().getCondutores();
}
