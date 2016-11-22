//
// Created by evangraine on 20/11/16.
//

#ifndef M1S7_TP1_FUNC_H
#define M1S7_TP1_FUNC_H


#include "Expr.h"

class Func : public Expr {
public:
    Func(const string name, float argc = -1);
    /* eval : Retourne la valeur de l'a fonction */
    virtual float eval(map<string, Expr>& symbols);
    /* */
    void addArg(const ExprToken& arg);

    bool hasArgCount();

    const float argCount();

private:
    bool is_assignment(vector<ExprToken> vector);
    vector<ExprToken> _args;
    string _name;
    float _argc;

    float lerp(float value, float value1, float value2);
};


#endif //M1S7_TP1_FUNC_H
