//
// Created by Evan Graïne on 30/10/16.
//

#include <sstream>
#include <algorithm>
#include "StringOperations.h"
#include "Func.h"

/* Partitionne une chaîne avec un délimiteur
     * TODO : à modifier / faire une autre méthode pour la partie 3 */
vector<OLD_ExprToken> StringOperations::split_expr_simple(string &s, const char delimiter) {
    vector<OLD_ExprToken> split_vector;
    stringstream ss;
    ss << s;
    for (string word; getline(ss, word, delimiter);) {
        split_vector.push_back(OLD_ExprToken{word});
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

string StringOperations::joinExprToString(vector<OLD_ExprToken> vector) {
    stringstream ss;
    for (OLD_ExprToken &token : vector) {
        ss << token.str() << " ";
    }
    return ss.str();
}

vector<OLD_ExprToken> StringOperations::split_expr_medium(string &s) {

    stringstream parser(s);
    vector<OLD_ExprToken> output;
    while (not parser.eof()) {

        double value;
        char sign;
        string nominal;

        if (isdigit(parser.peek())) {
            parser >> value;
            printf("\nNUM:%f", value);
            output.push_back(OLD_ExprToken{value});
        } else {
            if (parser.eof()) break;
            parser >> sign;
            string str;
            str = sign;
            printf("\nSIGN:%c", sign);
            try {
                output.push_back(OLD_ExprToken(str));
                OLD_ExprToken strtoken = output.back();
                cout << "\tTest_str_token: " << strtoken.str() << "\t";
                if (not nominal.empty()) {
                    output.pop_back();
                    cout << nominal;
                    continue;
                }

            } catch (NotAToken) {
            }
        }

    }
    return output;
}


vector<OLD_ExprToken> StringOperations::split_expr_complex(string &s) {

    regex doubleing("([[:digit:]]+)?(\\.[[:digit:]]+)?");
    regex var("([_[:alpha:]]|[[:lower:]])[[:alpha:]]*");
    regex fun("([_[:alpha:]]|[[:lower:]])[[:alpha:]]*\\(.*\\)");
    regex oper("(\\+|-|\\*|/)");
    regex parenthesis("(\\(|\\))");
    regex comma(",");
    regex equals("=");


    vector<OLD_ExprToken> tokens;

    string input = s;
    int cursor = 0;

    input = s;

    while (input.length() != cursor) {
        if (input.at(cursor) == ' ')
            input.erase(cursor, 1);
        else
            cursor++;
    }


    cursor = 0;
    // Parse char by char
    while (input.length()) {



        // Init Cursor at end pos
        cursor = (int) input.length();

        // Vars to check if any is recognized (First value is true to go in the while loop)
        bool recognized_double = false;
        bool recognized_var = false;
        bool recognized_fun = false;
        bool recognized_oper = false;
        bool recognized_par = false;
        bool recognized_comma = false;
        bool recognized_equals = false;

        string current;
        // While nothing is recognized
        while (cursor != 0
               && !recognized_double && !recognized_fun && !recognized_oper && !recognized_var && !recognized_par &&
               !recognized_comma) {

            // Subset becomes bigger
            current = input.substr(0, (unsigned long) cursor);

            recognized_double = regex_match(current, doubleing);
            recognized_equals = regex_match(current, equals);
            recognized_fun = regex_match(current, fun);
            recognized_oper = regex_match(current, oper);
            recognized_var = regex_match(current, var);
            recognized_par = regex_match(current, parenthesis);
            recognized_comma = regex_match(current, comma);

            cursor--;
        }

        if (cursor == -1) throw InvalidExpression();
        // Add last recognized token

        if (recognized_double) {
            //cout << "DOUBLE:" << current << endl;
            tokens.push_back(OLD_ExprToken(current));
        } else if (recognized_equals) {
            //cout << "EQUALS:" << current << endl;
            tokens.push_back(OLD_ExprToken(current));
        } else if (recognized_var) {
            //cout << "VAR:" << current << endl;
            tokens.push_back(OLD_ExprToken(current));
        } else if (recognized_oper) {
            //cout << "OPER:" << current << endl;
            tokens.push_back(OLD_ExprToken(current));
        } else if (recognized_comma) {
            //cout << "COMMA:" << current << endl;
            tokens.push_back(OLD_ExprToken(current));
        } else if (recognized_fun) {

            string fun = string(current);
            unsigned long fun_cursor = fun.length();
            while (!regex_match(fun.substr(0, fun_cursor), var)) fun_cursor--;
            // Add function name
            string fun_name = fun.substr(0, fun_cursor);
            //cout << "FUN:" << fun_name << endl;
            tokens.push_back(OLD_ExprToken(fun_name));
            tokens.back().forceType(OLD_ExprToken::function_t);
            //cout << "PAR:" << "(" << endl;
            tokens.push_back(OLD_ExprToken("("));
            string args = fun.substr(fun_cursor + 1, fun.length() - (fun_cursor + 2));

            for (OLD_ExprToken &token : split_expr_complex(args))
                tokens.push_back(token);
            //cout << "PAR:" << ")" << endl;
            tokens.push_back(OLD_ExprToken(")"));
        } else if (recognized_par) {
            //cout << "PAR:" << current << endl;
            tokens.push_back(OLD_ExprToken(current));
        } else {
            throw InvalidExpression();
        }
        // Subset the input
        input = input.substr(cursor + 1, input.length() - 1);
    }

    return tokens;
}


