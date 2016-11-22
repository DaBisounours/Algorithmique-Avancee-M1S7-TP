//
// Created by Evan Graïne on 30/10/16.
//

#ifndef M1S7_TP1_EXPRTOKEN_H
#define M1S7_TP1_EXPRTOKEN_H

#include <string>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

/* Exception NotAToken : thrown quand la chaîne en entrée n'est pas un opérateur connu */
class NotAToken {
};
/* Exception BadRequest : thrown quand une fonction est appelée sur le mauvais type */
class BadRequest {
};
/* Exception MismatchedParenthesis : thrown quand une fonction est appelée sur le mauvais type */
class MismatchedParenthesis {
};

/***************************************************************************
 * Classe Oper : représente un opérateur
 * *************************************************************************/
class ExprToken {

public:
    enum TokenType {
        operator_t,
        operand_t,
        symbol_t,
        assign_t,
        parenthesis_t,
        function_t,
        argseparator_t,
    };

    /* Constructeur vide */
    ExprToken() {}

    /* Constructeur d'ExprToken avec gestion de priorité */
    ExprToken(const string str) throw(NotAToken);

    /* Constructeur depuis un flottant (forcément littéral) */
    ExprToken(double _value);

    /* Accesseur de la priorité */
    double priority() const;
    /* Accesseur de la valeur */
    double value() const;
    /* Accesseur du type */
    double type() const;

    /* Setter du type */
    void forceType(TokenType t);

    /* Accesseur de la chaîne */
    string str() const;

protected:
    /* Chaîne en entrée sauvegardée */
    string _s;
    /* Ordre de priorité ou valeur */
    double _value;
    /* Type de token */
    TokenType _type;

    /* is_litteral : Détermine si c'est un littéral */
    bool is_litteral(const string s);
    /* is_operator : Détermine si c'est un opérateur */
    bool is_operator(const string s);
    /* is_operator : Détermine si c'est un opérateur */
    bool is_comma(const string s);
    /* is_operator : Détermine si c'est un opérateur */
    bool is_symbol(const string s);

    bool is_equal_sign(string basic_string);

    bool is_parenthesis(string basic_string);
};

/* Surcharge d'opérateurs de comparaison d'ExprToken */
bool operator<(ExprToken const& o1, ExprToken const& o2);
/* Surcharge d'opérateurs de comparaison d'ExprToken */
bool operator==(ExprToken const& o1, ExprToken const& o2);

#endif //M1S7_TP1_EXPRTOKEN_H
