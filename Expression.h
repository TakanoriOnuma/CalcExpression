#pragma once

class Expression {

    void skip_space(const char*& ch);
    double exp1(const char*& ch);
    double exp2(const char*& ch);
    double exp3(const char*& ch);
    double read_value(const char*& ch);

public:
    double calc_exp(const char* exp_str);
};