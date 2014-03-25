#include <iostream>
#include <string>

#include "Expression.h"

using namespace std;


int main()
{
    string str;

    cout << "”Ž®F";
    getline(cin, str);

    Expression expression;
    cout << str << " = " << expression.calc_exp(str.c_str()) << endl;

    return 0;
}