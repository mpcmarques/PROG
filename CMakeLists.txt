cmake_minimum_required(VERSION 3.7)
project(prog)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        T5E201601876/gui/main.cpp
        T5E201601876/gui/main.hpp
        T5E201601876/logic/objects/Autocarro.cpp
        T5E201601876/logic/objects/Autocarro.hpp
        T5E201601876/logic/objects/Condutor.cpp
        T5E201601876/logic/objects/Condutor.hpp
        T5E201601876/logic/services/FileService.cpp
        T5E201601876/logic/services/FileService.hpp
        T5E201601876/logic/services/Utility.cpp
        T5E201601876/logic/services/Utility.hpp
        T5E201601876/logic/objects/Linha.cpp
        T5E201601876/logic/objects/Linha.hpp
        T5E201601876/logic/objects/Paragem.cpp
        T5E201601876/logic/objects/Paragem.hpp
        T5E201601876/logic/objects/Time.cpp
        T5E201601876/logic/objects/Time.hpp
        T5E201601876/logic/objects/Transportadora.cpp
        T5E201601876/logic/objects/Transportadora.hpp
        T5E201601876/logic/objects/Turno.cpp
        T5E201601876/logic/objects/Turno.hpp T5E201601876/logic/objects/ResultadoPercurso.cpp T5E201601876/logic/objects/ResultadoPercurso.h)

add_executable(prog ${SOURCE_FILES})