//
// Created by Evan Graïne on 30/10/16.
//

#include <map>
#include "Program.h"
#include "StringOperations.h"

void Program::print() {
    int c = 0;
    cout << "\nReprésentations Internes:\n";
    for(string expr_str : _expressions_str) {
        cout << c++ << ":\t";
        Expr(expr_str.c_str()).print();
    }

}

vector<float> Program::exec() {
    vector<float> results;

    for(string expr_str : _expressions_str) {
        Expr expr {expr_str.c_str()};
        float result = expr.eval(_symbols);
        results.push_back(result);
    }
    return results;
}



Program::Program(const char *prg_str) {
    _setProgramCStr(prg_str);
}

istream &operator>>( istream  &input, Program &P ) {
    string s;
    stringstream ss;
    while(not input.eof()) {
        input >> s;
        ss << s << " ";
        // Retour a la ligne
        if(input.peek()=='\n')

            // Fin d'instruction
            if(s.back() == ';'){
                // sortie de l'entrée
                if(s == "exit;") break;
                P._expressions_str.push_back(ss.str().substr(0, ss.str().length()-2));
                ss.str(string());
                ss.clear();
            }
            // Fin de programme
            else {
                P._expressions_str.push_back(ss.str().substr(0, ss.str().length()-1));
                vector<float> results = P.exec();
                if(not results.empty())
                    cout << results.back();
                //P._expressions_str.clear();
                ss.str(string());
                ss.clear();
                cout << "\n";
            }
    }



    return input;
}

void Program::_setProgramCStr(const char *prg_str) {
    // Conversion en std::string
    string program_string{prg_str};
    // Séparation des différents programmes par ';'
    _expressions_str = StringOperations::split_program(program_string);
}
