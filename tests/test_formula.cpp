/*
TODO::Check how to avoid the multiple definition of formula.inl
#include "../include/libs/doctest.h"
#include "../include/math/formula.inl"

TEST_CASE("it can calculate delta")
{
    double a = 2;
    double b = -6;
    double c = 0;
    double result = deltaBhaskara(a, b, c);
    CHECK_EQ(result, 36);
}

TEST_CASE("it can calculate bhaskara with two roots")
{
    double a = 2;
    double b = -6;
    double c = 0;
    auto result = bhaskara(a, b, c);
    CHECK_EQ(result.first, 0);
    CHECK_EQ(result.second, 3);
}

TEST_CASE("it can calculate bhaskara with one root")
{
    double a = 1;
    double b = -8;
    double c = 16;
    auto result = bhaskara(a, b, c);
    CHECK_EQ(result.first, 4);
    CHECK_EQ(result.second, 4);
}
*/