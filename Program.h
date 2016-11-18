//
// Created by Evan Graïne on 30/10/16.
//

#ifndef M1S7_TP1_PROGRAM_H
#define M1S7_TP1_PROGRAM_H

#include "Expr.h"

class Program {

public:
    /* Constructeur de base */
    Program() {

    };

    /* Constructeur via une chaine de caractères */
    Program(const char *prg_str);

    /* Affichage des représentations internes */
    void print();

    /* Execution du programme */
    vector<float> exec();

    /* Redéfinition de l'opérateur d'entrée >> */
    friend istream &operator>>( istream  &input, Program &D );

private:
    /* Séquence des expressions sous forme de chaîne de caractères */
    vector<string> _expressions_str;

    /* Table des symboles propre au programme */
    map<string, Expr> _symbols;

    /* Initialiseur */
    void _setProgramCStr(const char *prg_str);
};


#endif //M1S7_TP1_PROGRAM_H
