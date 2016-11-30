//
// Created by evangraine on 30/11/16.
//

#ifndef M1S7_TP1_OPERATORTOKEN_H
#define M1S7_TP1_OPERATORTOKEN_H


#include "Operators/Operator.h"
#include "Specials/Special.h"
#include "../ExprToken.h"

class OperatorToken : ExprToken {
public:

    OperatorToken(Operator oper){ this->_value = oper; }
    virtual TokenValue value() { return this->_value; }

};


#endif //M1S7_TP1_OPERATORTOKEN_H
