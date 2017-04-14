//
//  main.cpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#include "FileService.hpp"
#include "Transportadora.hpp"

int main(int argc, const char * argv[]) {
    
    //  abrir ficheiro de linhas
    ifstream ficheiroLinhas;
    ficheiroLinhas.open("linhas.txt");
    
    //  ver se ficheiro esta aberto
    if (ficheiroLinhas.is_open()) {
        // loop de linhas do ficheiro
        while (!ficheiroLinhas.eof()) {
            string linha;
            
            getline(ficheiroLinhas, linha);
            
            cout << linha << endl;
        }
    }
    ficheiroLinhas.close();
    
    
    //  abrir ficheiro de condutores
    ifstream ficheiroCondutores;
    ficheiroCondutores.open("condutores.txt");
    
    //  ver se ficheiro esta aberto
    if (ficheiroCondutores.is_open()) {
        // loop de linhas do ficheiro
        while (!ficheiroCondutores.eof()) {
            string linha;
            
            getline(ficheiroCondutores, linha);
            
            cout << linha << endl;
        }
    }
    ficheiroCondutores.close();
    
}
