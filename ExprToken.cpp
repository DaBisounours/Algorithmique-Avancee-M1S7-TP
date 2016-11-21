//
// Created by Evan Graïne on 30/10/16.
//

#include "ExprToken.h"

/* Constructeur depuis un flottant (forcément littéral) */
ExprToken::ExprToken(float value) : _value(value), _type(operand_t) {
    stringstream ss;
    ss << value;
    _s = string(ss.str());
}

/* Constructeur d'ExprToken avec gestion de priorité */
ExprToken::ExprToken(string str) throw(NotAToken) {
    // if not a littéral and not operator
    _s = str;
    if (not is_parenthesis(_s)){
        if (not is_comma(_s)) {
            if (not is_litteral(_s)) {
                if (not is_operator(_s)) {
                    if (not is_symbol(_s)) {
                        if (not is_equal_sign(_s)) {
                            throw NotAToken();
                        }
                    }
                }
            }
        }
    }




    // Values updated by is_littéral() or is_operator()
}

/* Accesseur de la priorité */
float ExprToken::priority() const { if(_type == operator_t) return _value; else throw BadRequest(); }

/* Accesseur de la priorité */
float ExprToken::value() const { return _value; }


/* Accesseur de la chaîne */
string ExprToken::str() const { return _s; }

bool ExprToken::is_litteral(const string s){
    const char *characters = s.c_str();
    int dot = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(characters[i])) {
            if (dot)
                return false;
            else
                if(characters[i] == '.' || characters[i] == ',')
                    ++dot;
                else return false;
        }
    }
    // Update local
    _type = operand_t; _value = std::stof(_s);
    return true;
}

bool ExprToken::is_operator(const string s) {
    if (s == "+" || s == "-")
        _value = 1;
    else if (s == "*" || s == "/")
        _value = 2;
    else
        return false;
    _type = operator_t;
    return true;
}

bool ExprToken::is_symbol(const string s) {
    if (s.empty()) return false;
    const char *characters = s.c_str();
    int dot = 0;
    for (int i = 0; i < s.length(); i++) {
        // if first char is alpha
        if(i == 0)
            if (not (islower(characters[i]) && isalpha(characters[i]))) return false;
        // if others are alpha
        if (!isalnum(characters[i])) return false;
    }
    //then its a symbol
    _value = 0; _type = symbol_t;
    return true;
}

bool ExprToken::is_equal_sign(string s) {
    if (s == "=") {
        _value = 0;
        _type = assign_t;
        return true;
    }
    return false;
}

bool ExprToken::is_parenthesis(string s) {
    if(s == "(") {
        _value = 0;
        _type = parenthesis_t;
        return true;
    }
    else if(s == ")") {
        _value = 1;
        _type = parenthesis_t;
        return true;
    }
    return false;
}

float ExprToken::type() const {
    return _type;
}

void ExprToken::forceType(ExprToken::TokenType t) {
    _type = t;
}

bool ExprToken::is_comma(const string s) {
    if (s == ",") {
        _value = 0;
        _type = argseparator_t;
        return true;
    }
    return false;
}


/* Surcharge d'opérateurs de comparaison d'ExprToken */
bool operator<(ExprToken const& o1, ExprToken const& o2){
    if(o1.type() == ExprToken::operator_t && o2.type() == ExprToken::operator_t) return o1.priority()<o2.priority();
    else if (o1.type() == ExprToken::operand_t && o2.type() == ExprToken::operand_t) return o1.value()<o2.value();
    throw NotAToken();
}
bool operator==(ExprToken const& o1, ExprToken const& o2){
    if(o1.type() == ExprToken::operator_t && o2.type() == ExprToken::operator_t) return o1.priority()==o2.priority();
    else if (o1.type() == ExprToken::operand_t && o2.type() == ExprToken::operand_t) return o1.value()==o2.value();
    throw NotAToken();
}