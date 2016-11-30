#include <string>
#include <iostream>
#include "Expr.h"
#include "Program.h"


using namespace std;


void test(string title, const string& testLine, double expected, Program p){
    string separator = "\n==================================================================\n";

    // Début des tests
    double result = (Expr(testLine.c_str())).eval(p.context());
    cout << separator << title << ": \"" << testLine << "\""  << endl;
    cout << "\tAttendu: " << expected << endl;
    cout << "\tResultat: " << result << endl;

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
    for (double res : program.exec())
        //cout << "Résultat : \n";
        cout<< res << "\n";
*/
    /*Program p;

    system("clear");

    cout << "<> Tests d'opérateurs <>";
        test("Addition", "1+2+3.4+5", 1+2+3.4+5, p);
        test("Soustraction", "11.4-5-3.4-2", 11.4-5-3.4-2, p);
        test("Multiplication", "1.5*4", 1.5*4, p);
        test("Division", "6/4", (float)6/(float)4, p);
        cout << endl << "Appuyez sur Entrée pour continuer:" << endl;
        getchar();
        system("clear");
    cout << "<> Tests des parenthèses <>";
        test("Sans parenthèses", "1-2+3*4-5", 1-2+3*4-5, p);
        test("Priorité sur un op supérieur", "1-(2+3)*4-5", 1-(2+3)*4-5, p);
        test("Priorité sur un op supérieur", "1-2+3*(4-5)", 1-2+3*(4-5), p);
        test("Parenthèses imbriquées", "((1-2+3)*4-5)*2-1", ((1-2+3)*4-5)*2-1, p);
        cout << endl << "Appuyez sur Entrée pour continuer:" << endl;
        getchar();
        system("clear");
    cout << "<> Tests des fonctions <>";
        test("Un argument", "5*sin(0)", 5*sin(0), p);
        test("Deux arguments", "1-pow(2,10)", 1-pow(2,10), p);
        test("Nombre variable", "polynome(3,1,2,3,4,5)", 1 + 2*5+ 3*pow(5,2) + 4*pow(5,3), p);
        test("Fonctions imbriquées", "(cos(sin(0)))-1", (cos(sin(0)))-1, p);
        cout << endl << "Appuyez sur Entrée pour continuer:" << endl;
        getchar();
        system("clear");

    cout << endl << "<> Mode interactif (Faites-vous plaisir) <>" << endl;

    cin >> p;
*/

    cout << "" << endl;
    //OperatorToken addSign(Add());
    return 0;
}
