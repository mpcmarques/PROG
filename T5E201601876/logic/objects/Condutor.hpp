//
//  Condutor.hpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#ifndef Condutor_h
#define Condutor_h

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Autocarro.hpp"

/**
 * Classe representa um condutor
 */
class Condutor {
    int uid;                      //n de identificacao unico
    int turnoMax;                    //n de minutos do turno
    int horasPorSemana;           //n de minutos trabalhados por semana
    int descanso; //n de de minutos em descanso
    std::string nome; //nome do condutor
    std::vector<Turno> turnos;    //turnos

public:
    // construtores
    Condutor();              //  to be used by file I/O
    /**
     * Construtor do condutor
     * @param uid Id do condutor
     * @param nome Nome do condutor
     * @param turno Horas maximas por turno
     * @param horasPorSemana Horas maximas por semana
     * @param descanso Horas de descanso
     */
    Condutor(int uid, std::string nome, int turno, int horasPorSemana, int descanso);

    /**
     * Adiciona um turno ao condutor
     * @param turno Turno a ser adicionado
     */
    void addTurno(Turno turno);

    /**
    * Retorna true se o condutor pode realizar o turno
    * @param turno Turno a ser verificado
    */
    bool podeRealizarTurno(Turno turno);

    //  Getters
    /**
     * Retorna o nome do condutor
     */
    std::string getNome();

    /**
     * Retorna o id do condutor
     */
    int getUid();

    /**
     * Retorna o turno maximo do condutor
     */
    int getTurnoMax();

    /**
     * Retorna as horas de descanso do condutor
     */
    int getDescanso();

    /**
     * Retorna as horas por semana do condutor
     */
    int getHorasPorSemana();

    /**
     * Retorna os minutos semanais restantes do condutor
     */
    int getMinutosSemanaisRestantes();

    /**
     * Retorna os turnos do condutor
     * */
    std::vector<Turno> getTurnos();

    // Setters
    /**
     * Define o maximo de horas por turno
     * @param turnoMax Maximo de horas por turno
     */
    void setTurnoMax(int turnoMax);

    /**
     * Define o maximo de horas por semana
     * @param horasPorSemana Maximo de horas por semana
     */
    void setHorasPorSemana(int horasPorSemana);

    /**
     * Define as horas de descanso
     * @param descanso Horas de descanso
     */
    void setDescanso(int descanso);

    /**
     * Define o nome do condutor
     * @param nome Nome do condutor
     */
    void setNome(const std::string &nome);

    // operadores file IO
    friend std::istream &operator>>(std::istream &is, Condutor &condutor);

    friend std::ostream &operator<<(std::ostream &os, Condutor &condutor);
};

#endif /* Condutor_h */
