//
//  Time.hpp
//  prog
//
//  Created by <author> on 16/04/2017.
//
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>

/**
 * Classe representa um tempo
 */
class Time {
private:
    int horas;
    int minutos;
public:
    Time();

    /**
     * Construtor
     * @param horas Horas
     * @param minutos  Minutos
     */
    Time(int horas, int minutos);

    /**
     * Adiciona minutos ao tempo
     * @param minutos Minutos a serem adicionados
     */
    void addMinutos(int minutos);

    // Getters
    /**
     * @return Horas do tempo
     */
    const int getHoras();

    /**
     *
     * @return Minutos do tempo
     */
    const int getMinutos();

    /**
     *
     * @return Tempo total em minutos
     */
    const int getTimeMinutes();

    const Time operator-(Time &t1);
};


#endif /* Time_hpp */
