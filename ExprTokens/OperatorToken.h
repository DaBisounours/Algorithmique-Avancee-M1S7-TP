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
public:

    OperatorToken(Operator oper){ _operator=oper; }
    virtual Operator value() { return _operator; }

private:
    Operator _operator;
};


#endif //M1S7_TP1_OPERATORTOKEN_H
