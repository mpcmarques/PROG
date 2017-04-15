//
//  FileService.hpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#ifndef FileService_hpp
#define FileService_hpp

#include "Header.hpp"
#include "Transportadora.hpp"

class FileService {

public:

    static vector<Linha> getLinhas();
    static vector<Condutor> getCondutores();
};

#endif /* FileService_hpp */
