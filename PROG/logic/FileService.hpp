//
//  FileService.hpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#ifndef FileService_hpp
#define FileService_hpp

#define TXT_CONDUTORES "condutores.txt"
#define TXT_LINHAS "linhas.txt"

#include "Header.hpp"
#include "Transportadora.hpp"

class FileService {

public:
    vector<Linha> getLinhas();
    vector<Condutor> getCondutores();
    void saveData(Transportadora transportadora);
};

#endif /* FileService_hpp */
