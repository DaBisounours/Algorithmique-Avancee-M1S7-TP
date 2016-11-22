//
// Created by evangraine on 20/11/16.
//

#ifndef M1S7_TP1_FUNC_H
#define M1S7_TP1_FUNC_H


#include "Expr.h"

class Func : public Expr {
public:
    Func(const string name, double argc = -1);
    /* eval : Retourne la valeur de l'a fonction */
    virtual double eval(map<string, Expr>& symbols);
    /* */
    void addArg(const ExprToken& arg);

    bool hasArgCount();

    const double argCount();

private:
    bool is_assignment(vector<ExprToken> vector);
    vector<ExprToken> _args;
    string _name;
    double _argc;

    double lerp(double value, double value1, double value2);
};


#endif //M1S7_TP1_FUNC_H
