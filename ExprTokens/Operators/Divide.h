//
// Created by evangraine on 29/11/16.
//

#ifndef M1S7_TP1_DIVIDE_H
#define M1S7_TP1_DIVIDE_H


#include "Operator.h"

class Divide : Operator {
    virtual unsigned int priority(){ return 2; }
};


#endif //M1S7_TP1_DIVIDE_H
