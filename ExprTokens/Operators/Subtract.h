//
// Created by evangraine on 29/11/16.
//

#ifndef M1S7_TP1_SUBTRACT_H
#define M1S7_TP1_SUBTRACT_H


#include "Operator.h"

class Subtract : Operator {
    virtual unsigned int priority() { return 1; }
};


#endif //M1S7_TP1_SUBTRACT_H
