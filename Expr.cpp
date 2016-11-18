//
// Created by Evan Graïne on 30/10/16.
//

#include <map>
#include <cassert>
#include "Expr.h"
#include "StringOperations.h"

template<typename T>
void pop_front(std::vector<T> &vec) {
    assert(!vec.empty());
    vec.erase(vec.begin());
}

/* convertToRPN : Convertit une chaîne de la notation infixe vers RPN */
vector<ExprToken> Expr::convertToRPN(const vector<ExprToken> infix_expr) {

    // Vector to be returned containing the converted expression
    vector<ExprToken> output_expr;
    vector<ExprToken> operator_stack;

    // Pour chacun des tokens
    for (const ExprToken &token : infix_expr) {
        // On regarde si c'est un littéral
        // On regarde si c'est un symbole
        // On regarde si c'est un signe =
        if (token.type() == ExprToken::operand_t
            || token.type() == ExprToken::symbol_t
            || token.type() == ExprToken::assign_t) {
            // Si c'est le cas on le pousse à la sortie
            output_expr.push_back(token);
        // Si c'est une parenthèse
        } else if (token.type() == ExprToken::parenthesis_t) {
            if (!token.value()) {// left parenthesis
                operator_stack.push_back(token);
            } else {
                // Tant que la pile n'est pas vide et que
                while (not operator_stack.empty()
                       // Le token est une parenthèse ouverte ou une fonction
                       && ((operator_stack.back().type() != ExprToken::parenthesis_t && operator_stack.back().value())
                           || operator_stack.back().type() == ExprToken::function_t)) {
                    // On dépile tant que l'operateur en tête de pile n'est pas une parenthese droite
                    ExprToken operator_back = operator_stack.back();
                    operator_stack.pop_back();
                    output_expr.push_back(operator_back);

                }
                // Si la pile d'opérateur n'est pas vide
                if (not operator_stack.empty()) {
                    // On dépile la parenthèse
                    operator_stack.pop_back();
                    // Si l'opérateur suivant est une fonction
                    if (operator_stack.back().type() == ExprToken::function_t) {
                        // On la déplace dans la sortie
                        ExprToken operator_back = operator_stack.back();
                        operator_stack.pop_back();
                        output_expr.push_back(operator_back);
                    }
                } else {
                    throw MismatchedParenthesis();
                }
            }
        // Si c'est un opérateur
        } else {
            ExprToken operator_back;
            // Si la pile d'opérateurs n'est pas vide
            if (not operator_stack.empty()) operator_back = operator_stack.back();
            if (operator_back.type() == ExprToken::operator_t) {
                while (not operator_stack.empty() && token < operator_back) {
                    // On dépile tant que l'operateur en tête de pile est
                    // inférieur à celui en entrée
                    operator_stack.pop_back();
                    output_expr.push_back(operator_back);
                    operator_back = operator_stack.back();
                }
            }
            // On empile le nouvel opérateur
            operator_stack.push_back(token);

        }
        cout << '\n';
        for (ExprToken &e:output_expr)cout << e.str() << " ";
        cout << '\n';

    }

    // On vide la pile dans la sortie
    while (not operator_stack.empty()) {
        if (operator_stack.back().type() == ExprToken::parenthesis_t)
            throw MismatchedParenthesis();
        output_expr.push_back(operator_stack.back());
        operator_stack.pop_back();
    }

    return output_expr;
}

/* Constructeur : Construit une expression a partir du texte */
Expr::Expr(const char *str) throw(InvalidExpression) {
    string input{str};
    try {
        // Conversion en notation polonaise inversée (Reverse Polish Notation)
        _exprTokens = convertToRPN(StringOperations::split_expr_complex(input));
    } catch (NotAToken) {
        cerr << ". Make sure you have spaces between operands and operators -> ";
        throw InvalidExpression();
    }
}

/* eval : Retourne la valeur de l'expression */
float Expr::eval(map<string, Expr> &symbols) {
    vector<ExprToken> operand_stack;
    bool first = true;
    bool assignment = false;
    string assignment_name;

    // pour tous les éléments de la représentation interne
    for (const ExprToken &token : _exprTokens) {
        // Si c'est un littéral
        if (token.type() == ExprToken::operand_t)
            // On le push dans la pile des opérandes
            operand_stack.push_back(token);
            // Si c'est un symbole
        else if (token.type() == ExprToken::symbol_t) {
            // Si c'est le premier élément alors c'est une assignation
            if (first && is_assignment(_exprTokens)) {
                assignment = true;
                assignment_name = token.str();
            }
                // Sinon c'est une variable supposée "connue"
            else {
                try {
                    // évaluer la variable
                    ExprToken eval_tmp{symbols.at(token.str()).eval(symbols)};
                    // push le résultat dans la stack opérandes
                    operand_stack.push_back(eval_tmp);
                } catch (out_of_range) {
                    cerr << "Variable " << token.str() << " non référencée ";
                    throw InvalidExpression();
                }
            }
        }
            // Si c'est un signe égal
        else if (token.type() == ExprToken::assign_t) {
            // Si on vient de passer par un symbole
            // (Système de jeton)
            if (assignment) {
                // On ignore le signe égal et on enregistre l'évaluation qui suit
                vector<ExprToken> exprToAssign = vector<ExprToken>(_exprTokens.begin() + 2, _exprTokens.end());

                symbols[assignment_name] = {StringOperations::joinExprToString(exprToAssign).c_str()};
                //cout << "\n" << assignment_name << " referenced. *";
                return 0;
                // Si on trouve le signe égal n'importe ou
            } else
                // L'expression est invalide
                throw InvalidExpression();
        } else {
            // On récupère les deux dernières opérandes
            float operand_right = operand_stack.back().value();
            operand_stack.pop_back();
            float operand_left = operand_stack.back().value();
            operand_stack.pop_back();

            // On push le résultat des deux opérandes récupérées, calculé via l'opérateur en entrée
            switch (token.str()[0]) {
                case '+' :
                    operand_stack.push_back(ExprToken{operand_left + operand_right});
                    break;
                case '-' :
                    operand_stack.push_back(ExprToken{operand_left - operand_right});
                    break;
                case '*' :
                    operand_stack.push_back(ExprToken{operand_left * operand_right});
                    break;
                case '/' :
                    operand_stack.push_back(ExprToken{operand_left / operand_right});
                    break;
                default:
                    throw NotAToken();
            }
        }
        first = false;
    }
    // On retourne l'élément restant de la pile
    return operand_stack.front().value();
}

/* Affiche la représentation interne */
void Expr::print() {
    //cout << "Représentation interne:\n";
    for (ExprToken &element : _exprTokens) {
        cout << element.str() << " ";
    }
    cout << "\n";
}

Expr::Expr(const Expr &expr) {
    _exprTokens = vector<ExprToken>(expr._exprTokens);
}

bool Expr::is_assignment(vector<ExprToken> tokens) {
    for (ExprToken &token : tokens)
        if (token.type() == ExprToken::assign_t) return true;
    return false;
}



