#include "gtest/gtest.h"
int divFun(int numerator,int denominator){
    if(denominator==0 || denominator < 0){return 0;}

    return numerator/denominator;
}
TEST(DivFunTestSuite,HandleValidInputs){
    int numerator=10;
    int denomiator=5;
    int expectedValue=2;
    int actualValue=divFun(numerator,denomiator);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST(DivFunTestSuite,HandleDivideByZero){
    int numerator=10;
    int denomiator=0;
    int expectedValue=0;
    int actualValue=divFun(numerator,denomiator);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST(DivFunTestSuite,HandleNegetiveDenominator){
    int numerator=10;
    int denomiator=-5;
    int expectedValue=0;
    int actualValue=divFun(numerator,denomiator);
    ASSERT_EQ(actualValue,expectedValue);
}
