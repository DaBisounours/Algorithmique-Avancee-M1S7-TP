//
// Created by Evan Graïne on 30/10/16.
//

#ifndef M1S7_TP1_EXPR_H
#define M1S7_TP1_EXPR_H

#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <map>
#include "ExprToken.h"

using namespace std;

/* InvalidException est thrown quand l'expression contient des
     * caractères non compris ou le format est mauvais*/
class InvalidExpression {
};

/***************************************************************************
 * Classe Expr : représente une expression
 * *************************************************************************/
class Expr {


public:
    /* convertToRPN : Convertit une chaîne de la notation infixe vers RPN */
    vector<ExprToken> convertToRPN(const vector<ExprToken> infix_expr);

    /* Constructeur de base */
    Expr() {}

    /* Constructeur par copie */
    Expr(const Expr &expr);

    /* Constructeur : Construit une expression a partir du texte */
    Expr(const char *str) throw(InvalidExpression);

    /* eval : Retourne la valeur de l'expression */
    float eval(map<string, Expr>& symbols);

    /* Affiche la représentation interne */
    void print();


private:
    /* Vecteur des éléments de l'expression */
    vector<ExprToken> _exprTokens;

    bool is_assignment(vector<ExprToken> vector);
};


#endif //M1S7_TP1_EXPR_H
