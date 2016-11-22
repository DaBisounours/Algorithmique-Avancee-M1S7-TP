//
// Created by evangraine on 20/11/16.
//

#include "Func.h"

bool Func::is_assignment(vector<ExprToken> vector) {
    return false;
}

double Func::eval(map<string, Expr> &symbols) {
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
    else if(_name == "hypot")
        return sqrt(((long)_args.back().value())^2 + ((long)_args.front().value())^2);
    else if(_name == "min")
        return min(_args.back().value(), _args.front().value());
    else if(_name == "max")
        return max(_args.back().value(), _args.front().value());
    else if(_name == "pow")
        return pow(_args.back().value(), _args.front().value());
    else if(_name == "lerp")
        return lerp(_args.back().value(), _args.at(1).value(), _args.front().value());
    else if(_name == "polynome"){
        double sum = 0;
        double x = _args.front().value();
        for (int i = 1; i < _args.size()-1; ++i) {
            unsigned long degree = _args.size()-i-1;
            double coeff = _args[degree].value();
            sum += coeff * pow(x,i-1);
        }
        return sum;
    }
    else {
        return 0;
    }
}


void Func::addArg(const ExprToken &arg) {
    _args.push_back(ExprToken(arg));
}

Func::Func(const string name, double argc) {
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


const double Func::argCount() {
    return _argc;
}

double Func::lerp(double t, double a, double b) {
        return (1-t)*a + t*b;
}
