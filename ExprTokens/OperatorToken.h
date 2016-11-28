//
// Created by evangraine on 28/11/16.
//

#ifndef M1S7_TP1_OPERATORTOKEN_H
#define M1S7_TP1_OPERATORTOKEN_H

#include <string>
#include "../ExprToken.h"
#include "Operators/Operator.h"

using namespace std;

class OperatorToken : ExprToken<Operator> {
    virtual Operator value();

};


#endif //M1S7_TP1_OPERATORTOKEN_H
