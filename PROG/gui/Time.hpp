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

class Time {
private:
  int horas;
  int minutos;
public:
    Time();
    Time(int horas, int minutos);

    void addMinutos(int minutos);

    const int getHoras();
    const int getMinutos();
};


#endif /* Time_hpp */
