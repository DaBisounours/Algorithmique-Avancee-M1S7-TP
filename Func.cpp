//
// Created by evangraine on 20/11/16.
//

#include "Func.h"

bool Func::is_assignment(vector<ExprToken> vector) {
    return false;
}

float Func::eval(map<string, Expr> &symbols) {

}


void Func::addArg(const Expr &arg) {
    _args.push_back(Expr(arg));
}

Func::Func(const string name) {
    _name = name;
}
