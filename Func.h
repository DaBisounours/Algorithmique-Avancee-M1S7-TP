//
// Created by evangraine on 20/11/16.
//

#ifndef M1S7_TP1_FUNC_H
#define M1S7_TP1_FUNC_H


#include "Expr.h"

class Func : public Expr {
public:
    Func(const string name);
    /* eval : Retourne la valeur de l'a fonction */
    virtual float eval(map<string, Expr>& symbols);
    /* */
    void addArg(const Expr& arg);
private:
    bool is_assignment(vector<ExprToken> vector);
    vector<Expr> _args;
    string _name;
};


#endif //M1S7_TP1_FUNC_H