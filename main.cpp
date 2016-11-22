#include <string>
#include <iostream>
#include "Expr.h"
#include "Program.h"
#include "StringOperations.h"

using namespace std;





int main() {

/*  DEPRECATED : Version TP
    // Entrée utilisateur
    string input;
    cout << "Expr? :";
    getline(cin, input);

    // Evaluation de l'expression
    Expr expression {input.c_str()};
    expression.print();
    cout << "Résultat : " << expression.eval();


    // Entrée utilisateur
    string input;
    cout << "Program? : ";
    getline(cin, input);

    // Evaluation du programme
    Program program{input.c_str()};
    //program.print();
    for (float res : program.exec())
        //cout << "Résultat : \n";
        cout<< res << "\n";
*/
    Program p;
    string separator = "==================================================================";
    string testline;

    // Début des tests
    cout << separator << "Addition:" << endl;
    
    cin >> p;

    p.print();

    return 0;
}
