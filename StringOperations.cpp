//
// Created by Evan Graïne on 30/10/16.
//

#include <sstream>
#include "StringOperations.h"
#include "Func.h"

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

vector<ExprToken> StringOperations::split_expr_medium(string &s) {

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

vector<ExprToken> StringOperations::split_expr_complex(string &s) {

    regex floating("([[:digit:]]+)?(\\.[[:digit:]]+)?");
    regex var("([_[:alpha:]]|[[:lower:]])[[:alpha:]]*");
    regex fun("([_[:alpha:]]|[[:lower:]])[[:alpha:]]*\\(.*\\)");
    regex oper("(\\+|-|\\*|/)");
    regex parenthesis("(\\(|\\))");


    vector<ExprToken> tokens;

    string input = s;
    int cursor = 0;

    // Parse char by char
    while(input.length()) {
        // Init Cursor at pos 1
        cursor = (int) input.length();

        // Vars to check if any is recognized (First value is true to go in the while loop)
        bool recognized_float = false;
        bool recognized_var = false;
        bool recognized_fun = false;
        bool recognized_oper = false;
        bool recognized_par = false;

        string current;
        // While nothing is recognized
        while (cursor != 0
               && !recognized_float && ! recognized_fun && !recognized_oper && !recognized_var && !recognized_par) {

            // Subset becomes bigger
            current = input.substr(0, (unsigned long) cursor);

            recognized_float = regex_match(current, floating);
            recognized_fun = regex_match(current, fun);
            recognized_oper = regex_match(current, oper);
            recognized_var = regex_match(current, var);
            recognized_par = regex_match(current, parenthesis);

            cursor--;
        }

        if (cursor == -1) throw "Invalid Expression";
        // Add last recognized token

        if (recognized_float){
            cout << "FLOAT:" << current << endl;
            tokens.push_back(ExprToken(current));
        } else if (recognized_var) {
            cout << "VAR:" << current << endl;
            tokens.push_back(ExprToken(current));
        } else if (recognized_oper){
            cout << "OPER:" << current << endl;
            tokens.push_back(ExprToken(current));
        } else if (recognized_fun){

            string fun = string(current);
            unsigned long fun_cursor = fun.length();
            while (!regex_match(fun.substr(0,fun_cursor), var)) fun_cursor--;
            // Add function name
            string fun_name = fun.substr(0,fun_cursor);
            cout << "FUN:" << fun_name << endl;
            tokens.push_back(ExprToken(fun_name));
            tokens.back().forceType(ExprToken::function_t);
            cout << "PAR:" << "(" << endl;
            tokens.push_back(ExprToken("("));
            string args = fun.substr(fun_cursor+1,fun.length()-(fun_cursor+2));

            vector<ExprToken> split_vector;
            stringstream ss;
            ss << args;
            for (string arg; getline(ss, arg, ',');) {
                for (ExprToken &token : split_expr_complex(arg))
                    tokens.push_back(token);
                cout << "COMMA:" << "," << endl;
                tokens.push_back(ExprToken(","));
            }
            cout << "PAR:" << ")" << endl;
            tokens.push_back(ExprToken("("));
        } else if (recognized_par) {
            cout << "PAR:" << current << endl;
            tokens.push_back(ExprToken(current));
        } else {
            throw "Invalid Expression";
        }
        // TODO Subset the input
        input = input.substr(cursor+1,input.length()-1);
    }

    return tokens;
}


