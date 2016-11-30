//
// Created by evangraine on 28/11/16.
//

#ifndef M1S7_TP1_OPERATOR_H
#define M1S7_TP1_OPERATOR_H


#include "../TokenValue.h"

class Operator : public TokenValue{
    virtual unsigned int priority() { return 0; }
};


#endif //M1S7_TP1_OPERATOR_H
