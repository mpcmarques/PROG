cmake_minimum_required(VERSION 3.7)
project(prog)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        T5E201601876/gui/main.cpp
        T5E201601876/gui/main.hpp
        T5E201601876/logic/Autocarro.cpp
        T5E201601876/logic/Autocarro.hpp
        T5E201601876/logic/Condutor.cpp
        T5E201601876/logic/Condutor.hpp
        T5E201601876/logic/FileService.cpp
        T5E201601876/logic/FileService.hpp
        T5E201601876/logic/Header.cpp
        T5E201601876/logic/Header.hpp
        T5E201601876/logic/Linha.cpp
        T5E201601876/logic/Linha.hpp
        T5E201601876/logic/Paragem.cpp
        T5E201601876/logic/Paragem.hpp
        T5E201601876/logic/Time.cpp
        T5E201601876/logic/Time.hpp
        T5E201601876/logic/Transportadora.cpp
        T5E201601876/logic/Transportadora.hpp
        T5E201601876/logic/Turno.cpp
        T5E201601876/logic/Turno.hpp T5E201601876/logic/ResultadoPercurso.cpp T5E201601876/logic/ResultadoPercurso.h)

add_executable(prog ${SOURCE_FILES})