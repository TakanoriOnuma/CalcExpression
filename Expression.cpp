#include <iostream>
#include <stdlib.h>

#include "Expression.h"

using namespace std;

// skip space
inline void Expression::skip_space(const char*& ch)
{
    for ( ; *ch == ' '; ++ch) ;
}

// <数式1> ::= <数式2> {{+|-} <数式2>}*
double Expression::exp1(const char*& ch)
{
    double value = exp2(ch);

    while (true) {
        skip_space(ch);

        if (*ch == '+') {
            ++ch;
            value += exp2(ch);
        }
        else if (*ch == '-') {
            ++ch;
            value -= exp2(ch);
        }
        else {
            break;
        }
    }

    return value;
}

// <数式2> ::= <数式3> {{*|/} <数式3>}*
double Expression::exp2(const char*& ch)
{
    double value = exp3(ch);

    while (true) {
        skip_space(ch);

        if (*ch == '*') {
            ++ch;
            value *= exp3(ch);
        }
        else if (*ch == '/') {
            ++ch;
            value /= exp3(ch);
        }
        else {
            break;
        }
    }

    return value;
}

// <数式3> ::= (<数式1>) | <数>
double Expression::exp3(const char*& ch)
{
    skip_space(ch);
    if (*ch == '(') {
        ++ch;
        double value = exp1(ch);
        skip_space(ch);
        if (*ch == ')'){
            ++ch;
            return value;
        }
        else {
            cout << "cannot find ')'." << endl;
            exit(-1);
        }
    }

    return read_value(ch);
}

// 数字を読み込む
double Expression::read_value(const char*& ch)
{
    skip_space(ch);

    double value = 0.0;

    for (; *ch >= '0' && *ch <= '9'; ++ch) {
        value = value * 10 + (*ch - '0');
    }

    if (*ch == '.') {
        ++ch;
        for (int mult_num = 10; *ch >= '0' && *ch <= '9'; ++ch, mult_num *= 10) {
            value += (double)(*ch - '0') / mult_num;
        }
    }

    return value;
}

// 数式の計算をする
double Expression::calc_exp(const char* exp_str)
{
    return exp1(exp_str);
}