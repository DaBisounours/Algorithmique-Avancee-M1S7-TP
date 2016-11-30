//
// Created by evangraine on 29/11/16.
//

#ifndef M1S7_TP1_ADD_H
#define M1S7_TP1_ADD_H


#include "Operator.h"

class Add : Operator{
    virtual unsigned int priority() { return 1; }
};


#endif //M1S7_TP1_ADD_H
