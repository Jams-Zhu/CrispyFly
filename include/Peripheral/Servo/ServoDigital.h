//
// Created by melonjams on 23-10-28.
//

#ifndef CRISPYFLY_DIGITALSERVO_H
#define CRISPYFLY_DIGITALSERVO_H


# include "ServoComm.h"


class DigitalServo : public ServoComm {
public:
    DigitalServo (int pin, int angelScaleH, int angelScaleL, int angelDivisionDegree = 100)
    : ServoComm (pin, angelScaleH, angelScaleL, angelDivisionDegree)
    {}
};


#endif //CRISPYFLY_DIGITALSERVO_H
