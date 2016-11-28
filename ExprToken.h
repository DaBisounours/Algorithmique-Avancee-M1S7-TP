//
// Created by evangraine on 28/11/16.
//

#ifndef M1S7_TP1_EXPRTOKEN_H
#define M1S7_TP1_EXPRTOKEN_H

#include <string>
#include <typeinfo>

using namespace std;

template <typename T = double>
class ExprToken {
public:
    virtual T value() = 0;
    string type() { return typeid(this).name(); }
private:
    T _value;

};


#endif //M1S7_TP1_EXPRTOKEN_H
