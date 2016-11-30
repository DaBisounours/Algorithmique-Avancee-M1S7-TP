//
// Created by evangraine on 28/11/16.
//

#ifndef M1S7_TP1_EXPRTOKEN_H
#define M1S7_TP1_EXPRTOKEN_H

#include <string>
#include <typeinfo>
#include "ExprTokens/TokenValue.h"

using namespace std;

class ExprToken {
public:
    // Accesseur du type
    virtual string type() { return typeid(this).name(); }
    // Accesseur de la chaine de caractères
    string str() const { return _s; }

protected:
    string _s;
    TokenValue _value;
};


#endif //M1S7_TP1_EXPRTOKEN_H
