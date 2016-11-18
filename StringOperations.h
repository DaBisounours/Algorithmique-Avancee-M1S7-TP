//
// Created by Evan Graïne on 30/10/16.
//

#ifndef M1S7_TP1_STRINGOPERATIONS_H
#define M1S7_TP1_STRINGOPERATIONS_H

#include <string>
#include <vector>
#include "ExprToken.h"
#include "Expr.h"

using namespace std;

/***************************************************************************
 * Classe StringOperations : sert à regrouper les opérations customisées
 * sur les chaines de caractères
 * *************************************************************************/
class StringOperations {
public:
    /* Partitionne une chaîne avec un délimiteur
     * TODO : à modifier / faire une autre méthode pour la partie 3 */
    static vector<ExprToken> split_expr_simple(string &s, const char delimiter = ' ');
    static vector<ExprToken> split_expr_complex(string &s);
    static vector<string> split_program(string &s, const char delimiter = ';');


    static string joinExprToString(std::vector<ExprToken> vector);
};


#endif //M1S7_TP1_STRINGOPERATIONS_H
