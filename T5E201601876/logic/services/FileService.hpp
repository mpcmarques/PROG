//
//  FileService.hpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#ifndef FileService_hpp
#define FileService_hpp

#define TXT_CONDUTORES "ficheiros/condutores.txt"
#define TXT_LINHAS "ficheiros/linhas.txt"

#include "Utility.hpp"
#include "../objects/Transportadora.hpp"

class FileService {

public:
    vector<Linha> getLinhas();
    vector<Condutor> getCondutores();
    Transportadora getTransportadora();
    void saveData(Transportadora transportadora);
};

#endif /* FileService_hpp */
