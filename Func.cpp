//
// Created by evangraine on 20/11/16.
//

#include "Func.h"

bool Func::is_assignment(vector<ExprToken> vector) {
    return false;
}

float Func::eval(map<string, Expr> &symbols) {
    if(_name == "sin")
        return sin(_args.back().value());
    else if(_name == "tan")
        return tan(_args.back().value());
    else if(_name == "cos")
        return cos(_args.back().value());
    else if(_name == "sqrt")
        return sqrt(_args.back().value());
    else if(_name == "log")
        return log(_args.back().value());
    else if(_name == "exp")
        return exp(_args.back().value());
    else if(_name == "min")
        return min(_args.back().value(), _args.front().value());
    else if(_name == "max")
        return max(_args.back().value(), _args.front().value());
    else if(_name == "pow")
        return pow(_args.front().value(), _args.back().value());
    else if(_name == "lerp")
        return lerp(_args.front().value(), _args.at(1).value(), _args.back().value());
    else {
        return 0;
    }
}


void Func::addArg(const ExprToken &arg) {
    _args.push_back(ExprToken(arg));
}

Func::Func(const string name, float argc) {
    _name = name;
    _argc = argc;
    if(name == "sin"
    || name == "cos"
    || name == "tan"
    || name == "sqrt"
    || name == "log"
    || name == "exp"
    ){
        _argc = 1;
    }
    else if(name == "max"
    || name == "min"
    || name == "pow"
    || name == "hypot"
    ){
        _argc = 2;
    }
    else if(name == "lerp") {
        _argc = 3;
    }
}

bool Func::hasArgCount() {
    return _argc != -1;
}


const float Func::argCount() {
    return _argc;
}

float Func::lerp(float t, float a, float b) {
        return (1-t)*a + t*b;
}
