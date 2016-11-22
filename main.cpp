#include <string>
#include <iostream>
#include "Expr.h"
#include "Program.h"
#include "StringOperations.h"

using namespace std;


void test(string title, const string& testLine, float expected, Program p){
    string separator = "\n==================================================================\n";
    bool ok = false;

    // Début des tests
    float result = (Expr(testLine.c_str())).eval(p.context());
    cout << separator << title << ": \"" << testLine << "\""  << endl;
    cout << "\tExpected: " << expected << endl;
    cout << "\tResult: " << result << endl;
    ok = result == expected;
    cout << "\t" << ( ok ? "OK" : "KO") << endl;

}


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
    test("Addition", "1+2+3.4+5", 11.4, p);
    test("Soustraction", "11.5-5-3.4-2", 1, p);


    return 0;
}
