//
// Created by Evan Graïne on 30/10/16.
//

#include <sstream>
#include "StringOperations.h"

/* Partitionne une chaîne avec un délimiteur
     * TODO : à modifier / faire une autre méthode pour la partie 3 */
vector<ExprToken> StringOperations::split_expr_simple(string &s, const char delimiter) {
    vector<ExprToken> split_vector;
    stringstream ss;
    ss << s;
    for (string word; getline(ss, word, delimiter);) {
        split_vector.push_back(ExprToken{word});
    }
    return split_vector;
}

vector<string> StringOperations::split_program(string &s, const char delimiter) {
    vector<string> split_vector;
    stringstream ss;
    ss << s;
    for (string expr_str; getline(ss, expr_str, delimiter);) {
        split_vector.push_back(expr_str.c_str());
    }
    return split_vector;
}

string StringOperations::joinExprToString(vector<ExprToken> vector) {
    stringstream ss;
    for(ExprToken & token : vector){
        ss << token.str() << " ";
    }
    return ss.str();
}

vector<ExprToken> StringOperations::split_expr_complex(string &s) {

    stringstream parser(s);
    vector<ExprToken> output;
    while(not parser.eof()) {

        float value;
        char sign;
        string nominal;

        if (isdigit(parser.peek())) {
            parser >> value;
            printf("\nNUM:%f", value);
            output.push_back(ExprToken{value});
        }
        else {
            if (parser.eof()) break;
            parser >> sign;
            string str;
            str = sign;
            printf("\nSIGN:%c", sign);
            try {
                output.push_back(ExprToken(str));
                ExprToken strtoken = output.back();
                cout << "\tTest_str_token: " << strtoken.str() << "\t";
                if (not nominal.empty()) {
                    output.pop_back();
                    cout << nominal;
                    continue;
                }

            } catch (NotAToken){
            }
        }

    }

    return output;


}


