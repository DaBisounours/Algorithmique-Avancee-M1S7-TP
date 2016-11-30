//
// Created by evangraine on 30/11/16.
//

#ifndef M1S7_TP1_SPECIALTOKEN_H
#define M1S7_TP1_SPECIALTOKEN_H


#include "Specials/Special.h"
#include "../ExprToken.h"

class SpecialToken : public ExprToken  {
public:

    SpecialToken(Special oper){ this->_value = oper; }
    virtual TokenValue value() { return this->_value; }

private:
};


#endif //M1S7_TP1_SPECIALTOKEN_H
