/* Copyright 2024 valeryje
 *
 * This file contains Original Code created by Alexander Alexanyan
 * aka valeryje or Alex-A-Nyan.
 *
 * The Original Code and all software developed in the process of
 * participation on learning by experimental programming educational method.
 * The whole methodology was developed and distributed by
 * Autonomous non-profit organization «School 21» (ANO «School 21»).
 *
 * Redistribution and use of this file, its parts, or entire project
 * are permitted by confirmation of its original creator.
 */

/* ========================================================================== */

#include <gtest/gtest.h>
#include <sys/resource.h>
#include <cmath>
#include <string>
#include "Model/model.h"

constexpr int kEqSize = 256;

// Запрет на ввод не числе в поле для Х забор масштаба
//             и или его игнор построение графика
//             сделать иконку программы *кредитный калькулятор проверить на лики

//         // 13.21+2-3+4*5/6^7*(2-4)-sqrt(x)-sin(x)-cos(x)-tan(x)-asin(x-3.0)-acos(x)-atan(x)-log(x)-ln(x)=


TEST(Representation, SimpleNumbers) {                   // +++ГОТОВО+++
  char eq_00_[kEqSize] = "0";
  char eq_01_[kEqSize] = "1";
  char eq_02_[kEqSize] = "10";
  char eq_03_[kEqSize] = "06";
  char eq_04_[kEqSize] = "0004000";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 1);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 10);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 6);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 4000);
}

TEST(Representation, DecimalNumbersWithDotOrComma) {    // +++ГОТОВО+++
  char eq_00_[kEqSize] = "0.";
  char eq_01_[kEqSize] = ".0";
  char eq_02_[kEqSize] = "1.13";
  char eq_03_[kEqSize] = "1.0";
  char eq_04_[kEqSize] = "0,";
  char eq_05_[kEqSize] = ",0";
  char eq_06_[kEqSize] = "1,13";
  char eq_07_[kEqSize] = "1,0";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 0);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 1.13);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 1);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_04_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_05_), 0);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_06_), 1.13);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_07_), 1);
}

TEST(SimpleOperators, Addition) {                       // +++ГОТОВО+++
  char eq_00_[kEqSize] = "0+0";
  char eq_01_[kEqSize] = "1+1";
  char eq_02_[kEqSize] = "2+1";
  char eq_03_[kEqSize] = "2+90";
  char eq_04_[kEqSize] = "24+90";
  char eq_05_[kEqSize] = "2400+86";
  char eq_06_[kEqSize] = "2400+86+14";
  char eq_07_[kEqSize] = "2500+2400+86+14";
  char eq_09_[kEqSize] = "123456789+876543211";
  char eq_08_[kEqSize] = "37+450+13";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 2);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 3);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 92);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 114);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 2486);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 2500);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 5000);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), 500);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), 1000000000);
}

TEST(SimpleOperators, Substraction) {                   // +++ГОТОВО+++
  char eq_00_[kEqSize] = "0-0";
  char eq_01_[kEqSize] = "1-1";
  char eq_02_[kEqSize] = "2-1";
  char eq_03_[kEqSize] = "2-90";
  char eq_04_[kEqSize] = "45-90";
  char eq_05_[kEqSize] = "100-86";
  char eq_06_[kEqSize] = "2600-86-14";
  char eq_07_[kEqSize] = "2500-2400-86-14";
  char eq_08_[kEqSize] = "48+35-13-124-78+32";
  char eq_09_[kEqSize] = "37-450+13";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 0);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 1);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), -88);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), -45);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 14);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 2500);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 0);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), -100);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), -400);
}

TEST(SimpleOperators, Multiplication) {                 // +++ГОТОВО+++
  char eq_00_[kEqSize] = "0*0";
  char eq_01_[kEqSize] = "1*0";
  char eq_02_[kEqSize] = "1*3";
  char eq_03_[kEqSize] = "5*2*100";
  char eq_04_[kEqSize] = "50*5";
  char eq_05_[kEqSize] = "3*6*9+38";
  char eq_06_[kEqSize] = "2+3-5*1000";
  char eq_07_[kEqSize] = "100+10*2*7-340";
  char eq_08_[kEqSize] = "2*2*2-3*3+4*4+5";
  char eq_09_[kEqSize] = "325*4-300*1*2";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 0);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 3);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 1000);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 250);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 200);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), -4995);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), -100);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), 20);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), 700);
}

TEST(SimpleOperators, Division) {                       // +++ГОТОВО+++
  char eq_00_[kEqSize] = "123/0";
  char eq_01_[kEqSize] = "-123/0";
  char eq_02_[kEqSize] = "0/0";
  char eq_03_[kEqSize] = "1/1";
  char eq_04_[kEqSize] = "6/3";
  char eq_05_[kEqSize] = "24/6/2/2";
  char eq_06_[kEqSize] = "0/1/2/3/4/5";
  char eq_07_[kEqSize] = "12/2/3*4/8";
  char eq_08_[kEqSize] = "25*4/100+20";
  char eq_09_[kEqSize] = "3+8/2-6";
  char eq_10_[kEqSize] = "1+8/4*3/6*10/5*2";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  s21::Model calc_10_(eq_10_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), INFINITY);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), -INFINITY);
  EXPECT_NE(calc_02_.ModelProcedure(calc_02_), calc_02_.ModelProcedure(calc_02_));
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 1);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 2);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 1);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 0);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 1);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), 21);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), 1);
  EXPECT_EQ(calc_10_.ModelProcedure(calc_10_), 5);
}

TEST(SimpleOperators, Modulus) {                        // +++ГОТОВО+++
char eq_00_[kEqSize] = "1mod1";
char eq_01_[kEqSize] = "34mod70";
char eq_02_[kEqSize] = "70mod34";
char eq_03_[kEqSize] = "10mod3*3";
char eq_04_[kEqSize] = "3*10mod3";
char eq_05_[kEqSize] = "1+10mod7*8";
char eq_06_[kEqSize] = "32mod6-4*2-4";
char eq_07_[kEqSize] = "1mod2mod3mod4mod5";
char eq_08_[kEqSize] = "10mod4mod3mod1";
char eq_09_[kEqSize] = "1+2-20/5mod3+8";
char eq_10_[kEqSize] = "1%1";
char eq_11_[kEqSize] = "34%70";
char eq_12_[kEqSize] = "70%34";
char eq_13_[kEqSize] = "10%3*3";
char eq_14_[kEqSize] = "1%2mod3%4mod5";
char eq_15_[kEqSize] = "10%4mod3%1";
s21::Model calc_00_(eq_00_, 0);
s21::Model calc_01_(eq_01_, 0);
s21::Model calc_02_(eq_02_, 0);
s21::Model calc_03_(eq_03_, 0);
s21::Model calc_04_(eq_04_, 0);
s21::Model calc_05_(eq_05_, 0);
s21::Model calc_06_(eq_06_, 0);
s21::Model calc_07_(eq_07_, 0);
s21::Model calc_08_(eq_08_, 0);
s21::Model calc_09_(eq_09_, 0);
s21::Model calc_10_(eq_10_, 0);
s21::Model calc_11_(eq_11_, 0);
s21::Model calc_12_(eq_12_, 0);
s21::Model calc_13_(eq_13_, 0);
s21::Model calc_14_(eq_14_, 0);
s21::Model calc_15_(eq_15_, 0);
EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 34);
EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 2);
EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 3);
EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 0);
EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 25);
EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), -10);
EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 1);
EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), 0);
EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), 10);
EXPECT_EQ(calc_10_.ModelProcedure(calc_10_), 0);
EXPECT_EQ(calc_11_.ModelProcedure(calc_11_), 34);
EXPECT_EQ(calc_12_.ModelProcedure(calc_12_), 2);
EXPECT_EQ(calc_13_.ModelProcedure(calc_13_), 3);
EXPECT_EQ(calc_14_.ModelProcedure(calc_14_), 1);
EXPECT_EQ(calc_15_.ModelProcedure(calc_15_), 0);
}

TEST(SimpleOperators, Power) {                          // +++ГОТОВО+++
  char eq_00_[kEqSize] = "2^2";
  char eq_01_[kEqSize] = "2^0";
  char eq_02_[kEqSize] = "0^4";
  char eq_03_[kEqSize] = "1^0";
  char eq_04_[kEqSize] = "2^3^2";
  char eq_05_[kEqSize] = "2^2+2^2";
  char eq_06_[kEqSize] = "3^2-2^2";
  char eq_07_[kEqSize] = "150*5+75^2-25^2-35^2-55^2";
  char eq_08_[kEqSize] = "4^3^2^1";
  char eq_09_[kEqSize] = "1^2^3^4";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 4);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 1);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 0);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 1);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 512);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 8);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 5);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 1500);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), 262144);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), 1);
}

TEST(Brackets, CorrectBrackets) {                       // +++ГОТОВО+++
  char eq_00_[kEqSize] = "(1)";
  char eq_01_[kEqSize] = "((2))";
  char eq_02_[kEqSize] = "(1+2)";
  char eq_03_[kEqSize] = "5*(4-2)";
  char eq_04_[kEqSize] = "((2-2))*(3+3)";
  char eq_05_[kEqSize] = "2*(3-(4-5))";
  char eq_06_[kEqSize] = "10-((5*3)-5)*2";
  char eq_07_[kEqSize] = "(10/2)+5";
  char eq_08_[kEqSize] = "(1000-999)*(35/5)+(2.5*4)*(3)/(20/2)";
  char eq_09_[kEqSize] = "(4871220/5/3/((1+1)*2)+(1*2))/9/3-7-2500";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 1);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 2);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 3);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 10);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 0);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 8);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), -10);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 10);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), 10);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), 500);
}

TEST(Unary, Plus) {                                     // +++ГОТОВО+++
  char eq_02_[kEqSize] = "(+2)";
  char eq_03_[kEqSize] = "+2";
  char eq_04_[kEqSize] = "+2+4";
  char eq_05_[kEqSize] = "+4+(+4)";
  char eq_06_[kEqSize] = "3mod(+3)";
  char eq_07_[kEqSize] = "+3mod(+3)";
  char eq_08_[kEqSize] = "3mod(+3)+(+5)";
  char eq_09_[kEqSize] = "1+(+2)+(+3+(+4))";
  char eq_10_[kEqSize] = "+45234+(23*543)+(+34)";
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  s21::Model calc_10_(eq_10_, 0);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 2);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 2);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 6);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 8);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 0);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 0);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), 5);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), 10);
  EXPECT_EQ(calc_10_.ModelProcedure(calc_10_), 57757);
}

TEST(Unary, Minus) {                                    // +++ГОТОВО+++
  char eq_00_[kEqSize] = "-1";
  char eq_01_[kEqSize] = "(-2)";
  char eq_02_[kEqSize] = "-2-4";
  char eq_03_[kEqSize] = "-5+(+4)";
  char eq_04_[kEqSize] = "-5+(-4)";
  char eq_05_[kEqSize] = "+5+(+4)";
  char eq_06_[kEqSize] = "+5+(-4)";
  char eq_07_[kEqSize] = "-2mod(-4)";
  char eq_08_[kEqSize] = "-1+(-2)+(-3+(-4))";
  char eq_09_[kEqSize] = "-1-(-2)+(-3-(-4))";
  char eq_10_[kEqSize] = "(-(2))";
  char eq_11_[kEqSize] = "(+(-2))";
  char eq_12_[kEqSize] = "+(+(-2))";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  s21::Model calc_10_(eq_10_, 0);
  s21::Model calc_11_(eq_11_, 0);
  s21::Model calc_12_(eq_12_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), -1);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), -2);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), -6);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), -1);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), -9);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 9);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 1);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), -2);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), -10);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), 2);
  EXPECT_EQ(calc_10_.ModelProcedure(calc_10_), -2);
  EXPECT_EQ(calc_11_.ModelProcedure(calc_11_), -2);
  EXPECT_EQ(calc_12_.ModelProcedure(calc_12_), -2);
}

TEST(ComplexFunctions, SQRT) {                          // +++ГОТОВО+++
  char eq_00_[kEqSize] = "sqrt(0)";
  char eq_01_[kEqSize] = "sqrt(1)";
  char eq_02_[kEqSize] = "sqrt(4)";
  char eq_03_[kEqSize] = "sqrt(sqrt(16))";
  char eq_04_[kEqSize] = "sqrt(6.25)";
  char eq_05_[kEqSize] = "sqrt(6.2)";
  char eq_06_[kEqSize] = "sqrt(4+5)";
  char eq_07_[kEqSize] = "3^sqrt(4)";
  char eq_08_[kEqSize] = "sqrt(2^4)";
  char eq_09_[kEqSize] = "sqrt(2-3)";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 1);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 2);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 2);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 2.5000000);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 2.4899799);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 3);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 9);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), 4);
  EXPECT_NE(calc_09_.ModelProcedure(calc_09_), calc_09_.ModelProcedure(calc_09_));
}

TEST(ComplexFunctions, LogarithmDecimal) {              // +++ГОТОВО+++
  char eq_00_[kEqSize] = "log(0)";
  char eq_01_[kEqSize] = "log(1)";
  char eq_02_[kEqSize] = "lg(2)";
  char eq_03_[kEqSize] = "log10(10)";
  char eq_04_[kEqSize] = "log(1000)";
  char eq_05_[kEqSize] = "log10(1000000)";
  char eq_06_[kEqSize] = "log(0.001)";
  char eq_07_[kEqSize] = "log10(0.000009)";
  char eq_08_[kEqSize] = "lg(1-2)";
  char eq_09_[kEqSize] = "lg(1000-100000)";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), -INFINITY);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 0);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 0.3010300);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 1);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 3);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 6);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), -3);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), -5.0457575);
  EXPECT_NE(calc_08_.ModelProcedure(calc_08_), calc_08_.ModelProcedure(calc_08_));
  EXPECT_NE(calc_09_.ModelProcedure(calc_09_), calc_09_.ModelProcedure(calc_09_));
}

TEST(ComplexFunctions, LogarithmNatural) {              // +++ГОТОВО+++
  char eq_00_[kEqSize] = "ln(0)";
  char eq_01_[kEqSize] = "loge(1)";
  char eq_02_[kEqSize] = "logE(2)";
  char eq_03_[kEqSize] = "loge(10)";
  char eq_04_[kEqSize] = "ln(1000)";
  char eq_05_[kEqSize] = "logE(1000000)";
  char eq_06_[kEqSize] = "ln(0.001)";
  char eq_07_[kEqSize] = "ln(0.000009)";
  char eq_08_[kEqSize] = "logE(1-2)";
  char eq_09_[kEqSize] = "loge(1000-100000)";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), -INFINITY);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 0);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 0.6931472);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 2.3025851);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 6.9077553);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 13.8155106);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), -6.9077553);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), -11.6182860);
  EXPECT_NE(calc_08_.ModelProcedure(calc_08_), calc_08_.ModelProcedure(calc_08_));
  EXPECT_NE(calc_09_.ModelProcedure(calc_09_), calc_09_.ModelProcedure(calc_09_));
}

TEST(ComplexFunctions, Ceil) {                          
  char eq_00_[kEqSize] = "ceil(0)";
  char eq_01_[kEqSize] = "ceil(1)";
  char eq_02_[kEqSize] = "ceil(10.)";
  char eq_03_[kEqSize] = "ceil(-10.)";
  char eq_04_[kEqSize] = "ceil(10.1)";
  char eq_05_[kEqSize] = "ceil(-10.1)";
  char eq_06_[kEqSize] = "ceil(10.9)";
  char eq_07_[kEqSize] = "ceil(-10.9)";
  char eq_08_[kEqSize] = "ceil(0./0.)";
  char eq_09_[kEqSize] = "ceil(-1./0.)";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 1);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 10);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), -10);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 11);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), -10);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 11);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), -10);
  EXPECT_NE(calc_08_.ModelProcedure(calc_08_), calc_08_.ModelProcedure(calc_08_));
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), -INFINITY);
}

TEST(ComplexFunctions, Floor) {                         // добавить тесты на точность
  char eq_00_[kEqSize] = "floor(0)";
  char eq_01_[kEqSize] = "floor(1)";
  char eq_02_[kEqSize] = "floor(10.)";
  char eq_03_[kEqSize] = "floor(-10.)";
  char eq_04_[kEqSize] = "floor(10.1)";
  char eq_05_[kEqSize] = "floor(-10.1)";
  char eq_06_[kEqSize] = "floor(10.9)";
  char eq_07_[kEqSize] = "floor(-10.9)";
  char eq_08_[kEqSize] = "floor(0./0.)";
  char eq_09_[kEqSize] = "floor(-1./0.)";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 1);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 10);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), -10);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 10);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), -11);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 10);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), -11);
  EXPECT_NE(calc_08_.ModelProcedure(calc_08_), calc_08_.ModelProcedure(calc_08_));
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), -INFINITY);
}

TEST(Trigonometry, Sinus) {                             // +++ГОТОВО+++
  char eq_00_[kEqSize] = "sin(0)";
  char eq_01_[kEqSize] = "sin(5/5)";
  char eq_02_[kEqSize] = "sin((2-3)*0)";
  char eq_03_[kEqSize] = "sin(sin(sin(0)))";
  char eq_04_[kEqSize] = "sin(1)+sin(1)+sin(1)+sin(1)";
  char eq_05_[kEqSize] = "sin(4^4)";
  char eq_06_[kEqSize] = "sin(1000)";
  char eq_07_[kEqSize] = "sin(-4)";
  char eq_08_[kEqSize] = "-sin(+1000)";
  char eq_09_[kEqSize] = "-1*(-sin(-1000))";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 0.8414710);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 0);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 0);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 3.3658839);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), -0.9992080);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 0.8268795);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 0.7568025);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), -0.8268795);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), -0.8268795);
}

TEST(Trigonometry, Cosinus) {                           // +++ГОТОВО+++
  char eq_00_[kEqSize] = "cos(0)";
  char eq_01_[kEqSize] = "cos(sin(0))";
  char eq_02_[kEqSize] = "sin(cos(sin(0)))";
  char eq_03_[kEqSize] = "cos(0)-cos(0)*2";
  char eq_04_[kEqSize] = "(cos(0)-cos(0))*2";
  char eq_05_[kEqSize] = "1+4/(cos(0)*2)";
  char eq_06_[kEqSize] = "1+4/cos(0)*2";
  char eq_07_[kEqSize] = "(1+4/cos(0))*2";
  char eq_08_[kEqSize] = "cos(cos(cos(0)))";
  char eq_09_[kEqSize] = "-cos(-cos(-cos(0)))";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 1);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 1);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 0.8414710);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), -1);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 0);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 3);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 9);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 10);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), 0.8575532);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), -0.8575532);
}

TEST(Trigonometry, Tangens) {                           // +++ГОТОВО+++
  char eq_00_[kEqSize] = "tan(0)";
  char eq_01_[kEqSize] = "tan(1)";
  char eq_02_[kEqSize] = "tan(3.1416)";
  char eq_03_[kEqSize] = "tan(cos(0))";
  char eq_04_[kEqSize] = "tan(cos(0)+cos(0))";
  char eq_05_[kEqSize] = "tan(cos(0))+cos(0)";
  char eq_06_[kEqSize] = "1+tan(cos(0))*cos(0)";
  char eq_07_[kEqSize] = "(1+tan(cos(0)))+sin(0)/2";
  char eq_08_[kEqSize] = "-tan(cos(0))mod(-35)";
  char eq_09_[kEqSize] = "-tg(cos(0))%(-35)";
  char eq_10_[kEqSize] = "4-(-(+cos(sin(tg(423)))))";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  s21::Model calc_10_(eq_10_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 1.5574077);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 0.0000073);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 1.5574077);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), -2.1850399);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 2.5574077);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 2.5574077);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 2.5574077);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), -1.5574077);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), -1.5574077);
  EXPECT_EQ(calc_10_.ModelProcedure(calc_10_), 4.6278861);
}

TEST(Trigonometry, ArcSinus) {                          // +++ГОТОВО+++                                  
  char eq_00_[kEqSize] = "asin(0)";
  char eq_01_[kEqSize] = "asin(0.5)";
  char eq_02_[kEqSize] = "asin(0.9)";
  char eq_03_[kEqSize] = "asin(0.999999)";
  char eq_04_[kEqSize] = "arcsin(0.9999999)";
  char eq_05_[kEqSize] = "asin(0.9999999999)";
  char eq_06_[kEqSize] = "arcsin(0.999999999999999999999)";
  char eq_07_[kEqSize] = "asin(1)";
  char eq_08_[kEqSize] = "arcsin(1.00000000000001)";
  char eq_09_[kEqSize] = "arcsin(-1.00000000000001)";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 0.5235988);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 1.1197695);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 1.5693821);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 1.5703491);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 1.5707822);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 1.5707963);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 1.5707963);
  EXPECT_NE(calc_08_.ModelProcedure(calc_08_), calc_08_.ModelProcedure(calc_08_));
  EXPECT_NE(calc_09_.ModelProcedure(calc_09_), calc_09_.ModelProcedure(calc_09_));
}

TEST(Trigonometry, ArcCosinus) {                        // +++ГОТОВО+++                                 
  char eq_00_[kEqSize] = "acos(0)";
  char eq_01_[kEqSize] = "acos(0.5)";
  char eq_02_[kEqSize] = "arccos(0.9)";
  char eq_03_[kEqSize] = "acos(0.999999)";
  char eq_04_[kEqSize] = "arccos(0.9999999)";
  char eq_05_[kEqSize] = "acos(0.9999999999)";
  char eq_06_[kEqSize] = "arccos(0.999999999999999999999)";
  char eq_07_[kEqSize] = "arccos(1)";
  char eq_08_[kEqSize] = "acos(1.00000000000001)";
  char eq_09_[kEqSize] = "arccos(-1.00000000000001)";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 1.5707963);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 1.0471976);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 0.4510268);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 0.0014142);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 0.0004472);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 0.0000141);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 0);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 0);
  EXPECT_NE(calc_08_.ModelProcedure(calc_08_), calc_08_.ModelProcedure(calc_08_));
  EXPECT_NE(calc_09_.ModelProcedure(calc_09_), calc_09_.ModelProcedure(calc_09_));
}

TEST(Trigonometry, ArcTangens) {                        // +++ГОТОВО+++
  char eq_00_[kEqSize] = "atan(0)";
  char eq_01_[kEqSize] = "arctan(1000)";
  char eq_02_[kEqSize] = "atan(10)";
  char eq_03_[kEqSize] = "arctg(5)";
  char eq_04_[kEqSize] = "arctg(0.2)";
  char eq_05_[kEqSize] = "atan(34-50)";
  char eq_06_[kEqSize] = "-atan(+432)";
  char eq_07_[kEqSize] = "arctan(atan(0))";
  char eq_08_[kEqSize] = "-atan(45)";
  char eq_09_[kEqSize] = "atan(-500)";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 0);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 1.5697963);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 1.4711277);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 1.3734008);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 0.1973956);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), -1.5083775);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), -1.5684815);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 0);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), -1.5485778);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), -1.5687963);
}

// // TEST(X_Number, X_TEST) {
// //   char eq_00_[kEqSize] = "x";
// //   char eq_01_[kEqSize] = "x";
// //   char eq_02_[kEqSize] = "x";
// //   char eq_03_[kEqSize] = "x+1";
// //   char eq_04_[kEqSize] = "x+1";
// //   char eq_05_[kEqSize] = "x+1";
// //   char eq_06_[kEqSize] = "x*x";
// //   char eq_07_[kEqSize] = "x*x";
// //   char eq_08_[kEqSize] = "x*x";
// //   char eq_09_[kEqSize] = "1+(x/3-5)";
// //   char eq_10_[kEqSize] = "1+(x/3-5)";
// //   char eq_11_[kEqSize] = "1+(x/3-5)";
// //   char eq_12_[kEqSize] = "x+3*x-25/x";
// //   char eq_13_[kEqSize] = "x+3*x-25/x";
// //   char eq_14_[kEqSize] = "x+3*x-25/x";
// //   char eq_15_[kEqSize] = "x+3*x-25/x";
// //   char eq_16_[kEqSize] = "x+3*x-25/x";
// //   s21::Model calc_00_(eq_00_, 0);
// //   s21::Model calc_01_(eq_01_, 0);
// //   s21::Model calc_02_(eq_02_, 0);
// //   s21::Model calc_03_(eq_03_, 0);
// //   s21::Model calc_04_(eq_04_, 0);
// //   s21::Model calc_05_(eq_05_, 0);
// //   s21::Model calc_06_(eq_06_, 0);
// //   s21::Model calc_07_(eq_07_, 0);
// //   s21::Model calc_08_(eq_08_, 0);
// //   s21::Model calc_09_(eq_09_, 0);
// //   s21::Model calc_10_(eq_04_, 0);
// //   s21::Model calc_11_(eq_05_, 0);
// //   s21::Model calc_12_(eq_06_, 0);
// //   s21::Model calc_13_(eq_07_, 0);
// //   s21::Model calc_14_(eq_08_, 0);
// //   s21::Model calc_15_(eq_09_, 0);
// //   s21::Model calc_16_(eq_09_, 0);
// //   EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), EMPTY X-NUMBER);
// //   EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 1);
// //   EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 4540);
// //   EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), INCORRECT X-NUMBER);
// //   EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 2);
// //   EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), 4541);
// //   EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), INCORRECT X-NUMBER);
// //   EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 1);
// //   EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), 20611600);
// //   EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), INCORRECT X-NUMBER);
// //   EXPECT_EQ(calc_10_.ModelProcedure(calc_10_), -3.6666667);
// //   EXPECT_EQ(calc_11_.ModelProcedure(calc_11_), 1509.3333333);
// //   EXPECT_EQ(calc_12_.ModelProcedure(calc_12_), INCORRECT X-NUMBER);
// //   EXPECT_EQ(calc_13_.ModelProcedure(calc_13_), -21);
// //   EXPECT_EQ(calc_14_.ModelProcedure(calc_14_), 18159.9944934);
// //   EXPECT_EQ(calc_15_.ModelProcedure(calc_15_), -21);
// //   EXPECT_EQ(calc_16_.ModelProcedure(calc_16_), -18159.9944934);
// // }

// TEST(Syntax, UnevenMulti) {                                      // НАПИСАТЬ ТЕСТЫ
//   // char eq_00_[kEqSize] = "(1+8)3+1";
//   char eq_01_[kEqSize] = "3(1+8)+1";
//   char eq_02_[kEqSize] = "1*3(2)+1";
//   char eq_03_[kEqSize] = "(1-4)(5+5)";
//   // char eq_04_[kEqSize] = "(0-4)2(4)";
//   char eq_05_[kEqSize] = "2(0-4)(4)";
//   char eq_06_[kEqSize] = "sin(0)tan(0)";
//   // s21::Model calc_00_(eq_00_, 0);
//   s21::Model calc_01_(eq_01_, 0);
//   s21::Model calc_02_(eq_02_, 0);
//   s21::Model calc_03_(eq_03_, 0);
//   // s21::Model calc_04_(eq_04_, 0);
//   s21::Model calc_05_(eq_05_, 0);
//   s21::Model calc_06_(eq_06_, 0);
//   // EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 28);
//   EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 28);
//   EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 7);
//   EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), -30);
//   // EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), -32);
//   EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), -32);
//   EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 0);
// }

// TEST(Syntax, ScientificNotation) {                               // НАПИСАТЬ ТЕСТЫ на экспоненциальную запись (в том числе несколько знаков 2,5E+-+10 подряд и букв е)
// }

TEST(Accuracy, DecimalNumbers) {    // +++ГОТОВО+++
  char eq_00_[kEqSize] = "1.";
  char eq_01_[kEqSize] = "1.2+2.1";
  char eq_02_[kEqSize] = "4,+5.99999999";
  char eq_03_[kEqSize] = "0.9999999";
  char eq_04_[kEqSize] = "0.99999999";
  char eq_05_[kEqSize] = "0,9999999-1";
  char eq_06_[kEqSize] = "0.2*5";
  char eq_07_[kEqSize] = "0.2+0,2+0,2+0.2+0,2";
  char eq_08_[kEqSize] = "0,00000001*4.9999999";
  char eq_09_[kEqSize] = "1,+2";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), 1);
  EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 3.3);
  EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), 10.0000000);
  EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), 0.9999999);
  EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), 1.0000000);
  EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), -0.0000001);
  EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), 1);
  EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), 1);
  EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), 0.0000000);
  EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), 3);
}

// TEST(Accuracy, VariousAccuracy) {                                       // добавить тесты на точность >20 от максимума, на округление чисел, примеры на очень больших и малых числах.
// 
// }


TEST(Errors, LengthIssues) {                            // +++ГОТОВО+++
  char eq_00_[kEqSize] = "";
  char eq_01_[kEqSize] = {0};
  char eq_02_[kEqSize + 1] = {0};
  for (int i = 0; i < kEqSize + 1; i++) {
    eq_02_[i] = 2;
  }
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  try {
    EXPECT_THROW(calc_00_.ModelProcedure(calc_00_), std::underflow_error);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "EMPTY EQUATION");
  }
  try {
    EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), 0);
  } catch (...) {}
  try {
    EXPECT_THROW(calc_02_.ModelProcedure(calc_02_), std::overflow_error);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "EXCEEDED MAX LENGTH");
  }
}

// TEST(Errors, RepresentationForbiddenSymbols) {
//   char eq_00_[kEqSize] = "w";
//   char eq_01_[kEqSize] = "swn(2)";
//   char eq_02_[kEqSize] = "j*3";
//   char eq_03_[kEqSize] = "___";
//   char eq_04_[kEqSize] = "sin(1)_sin(1)";
//   char eq_05_[kEqSize] = "1&2";
//   char eq_06_[kEqSize] = "#####";
//   char eq_07_[kEqSize] = "?!";
//   char eq_08_[kEqSize] = "@";
//   char eq_09_[kEqSize] = "$";
//   s21::Model calc_00_(eq_00_, 0);
//   s21::Model calc_01_(eq_01_, 0);
//   s21::Model calc_02_(eq_02_, 0);
//   s21::Model calc_03_(eq_03_, 0);
//   s21::Model calc_04_(eq_04_, 0);
//   s21::Model calc_05_(eq_05_, 0);
//   s21::Model calc_06_(eq_06_, 0);
//   s21::Model calc_07_(eq_07_, 0);
//   s21::Model calc_08_(eq_08_, 0);
//   s21::Model calc_09_(eq_09_, 0);
//   EXPECT_EQ(calc_00_.ModelProcedure(calc_00_), "FORBIDDEN SYMBOLS");
//   EXPECT_EQ(calc_01_.ModelProcedure(calc_01_), "FORBIDDEN SYMBOLS");
//   EXPECT_EQ(calc_02_.ModelProcedure(calc_02_), "FORBIDDEN SYMBOLS");
//   EXPECT_EQ(calc_03_.ModelProcedure(calc_03_), "FORBIDDEN SYMBOLS");
//   EXPECT_EQ(calc_04_.ModelProcedure(calc_04_), "FORBIDDEN SYMBOLS");
//   EXPECT_EQ(calc_05_.ModelProcedure(calc_05_), "FORBIDDEN SYMBOLS");
//   EXPECT_EQ(calc_06_.ModelProcedure(calc_06_), "FORBIDDEN SYMBOLS");
//   EXPECT_EQ(calc_07_.ModelProcedure(calc_07_), "FORBIDDEN SYMBOLS");
//   EXPECT_EQ(calc_08_.ModelProcedure(calc_08_), "FORBIDDEN SYMBOLS");
//   EXPECT_EQ(calc_09_.ModelProcedure(calc_09_), "FORBIDDEN SYMBOLS");
// }

// TEST(Errors, DecimalNumbersWithDotOrComma) {         // ДОДЕЛАТЬ ТЕСТ НА ОДНУ ТОЧКУ/ЗАПЯТУЮ В УРАВНЕНИИ
//   char eq_00_[kEqSize] = "1..2";
//   char eq_01_[kEqSize] = "1.2.";
//   char eq_02_[kEqSize] = "1.2.0";
//   char eq_03_[kEqSize] = ".1.0";
//   char eq_04_[kEqSize] = "0.2.0";
//   char eq_05_[kEqSize] = ".12.";
//   char eq_06_[kEqSize] = "1,,2";
//   char eq_07_[kEqSize] = "1,2,";
//   char eq_08_[kEqSize] = "1,2,0";
//   char eq_09_[kEqSize] = ",1,0";
//   char eq_10_[kEqSize] = "0,2,0";
//   char eq_11_[kEqSize] = ",12,";
//   char eq_12_[kEqSize] = "0,.";
//   char eq_13_[kEqSize] = ",.0";
//   char eq_14_[kEqSize] = "1.,13";
//   char eq_15_[kEqSize] = "1,.0";
//   char eq_16_[kEqSize] = "1.,,2";
//   char eq_17_[kEqSize] = "1,2.";
//   char eq_18_[kEqSize] = "1.2,0";
//   char eq_19_[kEqSize] = ".1,0";
//   char eq_20_[kEqSize] = "0,2.0";
//   char eq_21_[kEqSize] = ",12.";  
//   char eq_22_[kEqSize] = ",.";  
//   // char eq_23_[kEqSize] = ".";
//   // char eq_24_[kEqSize] = ",";
//   s21::Model calc_00_(eq_00_, 0);
//   s21::Model calc_01_(eq_01_, 0);
//   s21::Model calc_02_(eq_02_, 0);
//   s21::Model calc_03_(eq_03_, 0);
//   s21::Model calc_04_(eq_04_, 0);
//   s21::Model calc_05_(eq_05_, 0);
//   s21::Model calc_06_(eq_06_, 0);
//   s21::Model calc_07_(eq_07_, 0);
//   s21::Model calc_08_(eq_08_, 0);
//   s21::Model calc_09_(eq_09_, 0);
//   s21::Model calc_10_(eq_10_, 0);
//   s21::Model calc_11_(eq_11_, 0);
//   s21::Model calc_12_(eq_12_, 0);
//   s21::Model calc_13_(eq_13_, 0);
//   s21::Model calc_14_(eq_14_, 0);
//   s21::Model calc_15_(eq_15_, 0);
//   s21::Model calc_16_(eq_16_, 0);
//   s21::Model calc_17_(eq_17_, 0);
//   s21::Model calc_18_(eq_18_, 0);
//   s21::Model calc_19_(eq_19_, 0);
//   s21::Model calc_20_(eq_20_, 0);
//   s21::Model calc_21_(eq_21_, 0);
//   s21::Model calc_22_(eq_22_, 0);
//   // s21::Model calc_23_(eq_23_, 0);
//   // s21::Model calc_24_(eq_24_, 0);
//   try {
//     EXPECT_THROW(calc_00_.ModelProcedure(calc_00_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_01_.ModelProcedure(calc_01_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_02_.ModelProcedure(calc_02_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_03_.ModelProcedure(calc_03_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_04_.ModelProcedure(calc_04_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_05_.ModelProcedure(calc_05_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_06_.ModelProcedure(calc_06_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_07_.ModelProcedure(calc_07_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_08_.ModelProcedure(calc_08_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_09_.ModelProcedure(calc_09_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_10_.ModelProcedure(calc_10_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_11_.ModelProcedure(calc_11_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_12_.ModelProcedure(calc_12_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_13_.ModelProcedure(calc_13_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_14_.ModelProcedure(calc_14_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_15_.ModelProcedure(calc_15_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_16_.ModelProcedure(calc_06_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_17_.ModelProcedure(calc_17_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_18_.ModelProcedure(calc_18_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_19_.ModelProcedure(calc_19_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_20_.ModelProcedure(calc_20_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_21_.ModelProcedure(calc_21_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   try {
//     EXPECT_THROW(calc_22_.ModelProcedure(calc_22_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   }
//   // try {
//   //   EXPECT_THROW(calc_23_.ModelProcedure(calc_23_), std::invalid_argument);
//   // } catch (const std::exception& exception) {
//   //   EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   // }
//   // try {
//   //   EXPECT_THROW(calc_24_.ModelProcedure(calc_24_), std::invalid_argument);
//   // } catch (const std::exception& exception) {
//   //   EXPECT_STREQ(exception.what(), "WRONG DECIMAL");
//   // }
// }

TEST(Errors, IncorrectBrackets) {                       // +++ГОТОВО+++ 2 и 6 дают неправильну. ошибку
  char eq_00_[kEqSize] = "()";
  char eq_01_[kEqSize] = "(())";
  char eq_02_[kEqSize] = "))";
  char eq_03_[kEqSize] = "(";
  char eq_04_[kEqSize] = "(()";
  char eq_05_[kEqSize] = "())";
  char eq_06_[kEqSize] = ")";
  char eq_07_[kEqSize] = "((";
  char eq_08_[kEqSize] = "1+()";
  char eq_09_[kEqSize] = "1-()*4";
  char eq_10_[kEqSize] = "1-(-(4)";
  char eq_11_[kEqSize] = "1-(9))";
  char eq_12_[kEqSize] = "(9)-((1)";
  char eq_13_[kEqSize] = "3-)3(+3";
  char eq_14_[kEqSize] = "((3))-())";
  char eq_15_[kEqSize] = "(1";
  char eq_16_[kEqSize] = "1)";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  s21::Model calc_06_(eq_06_, 0);
  s21::Model calc_07_(eq_07_, 0);
  s21::Model calc_08_(eq_08_, 0);
  s21::Model calc_09_(eq_09_, 0);
  s21::Model calc_10_(eq_10_, 0);
  s21::Model calc_11_(eq_11_, 0);
  s21::Model calc_12_(eq_12_, 0);
  s21::Model calc_13_(eq_13_, 0);
  s21::Model calc_14_(eq_14_, 0);
  s21::Model calc_15_(eq_15_, 0);
  s21::Model calc_16_(eq_16_, 0);
  try {
    EXPECT_THROW(calc_00_.ModelProcedure(calc_00_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "EMPTY BRACKETS");
  }
  try {
    EXPECT_THROW(calc_01_.ModelProcedure(calc_01_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "EMPTY BRACKETS");
  }
  try {
    EXPECT_THROW(calc_02_.ModelProcedure(calc_02_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "FREE OPERATOR");
  }
  try {
    EXPECT_THROW(calc_03_.ModelProcedure(calc_03_), std::overflow_error);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "MISSING CLOSING BRACKETS");
  }
  try {
    EXPECT_THROW(calc_04_.ModelProcedure(calc_04_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "EMPTY BRACKETS");
  }
  try {
    EXPECT_THROW(calc_05_.ModelProcedure(calc_05_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "EMPTY BRACKETS");
  }
  try {
    EXPECT_THROW(calc_06_.ModelProcedure(calc_06_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "FREE OPERATOR");
  }
  try {
    EXPECT_THROW(calc_07_.ModelProcedure(calc_07_), std::overflow_error);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "MISSING CLOSING BRACKETS");
  }
  try {
    EXPECT_THROW(calc_08_.ModelProcedure(calc_08_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "EMPTY BRACKETS");
  }
  try {
    EXPECT_THROW(calc_09_.ModelProcedure(calc_09_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "EMPTY BRACKETS");
  }
  try {
    EXPECT_THROW(calc_10_.ModelProcedure(calc_10_), std::overflow_error);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "MISSING CLOSING BRACKETS");
  }
  try {
    EXPECT_THROW(calc_11_.ModelProcedure(calc_11_), std::underflow_error);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "MISSING OPENING BRACKETS");
  }
  try {
    EXPECT_THROW(calc_12_.ModelProcedure(calc_12_), std::overflow_error);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "MISSING CLOSING BRACKETS");
  }
  try {
    EXPECT_THROW(calc_13_.ModelProcedure(calc_13_), std::underflow_error);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "MISSING OPENING BRACKETS");
  }
  try {
    EXPECT_THROW(calc_14_.ModelProcedure(calc_14_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "EMPTY BRACKETS");
  }
  try {
    EXPECT_THROW(calc_15_.ModelProcedure(calc_15_), std::overflow_error);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "MISSING CLOSING BRACKETS");
  }
  try {
    EXPECT_THROW(calc_16_.ModelProcedure(calc_16_), std::underflow_error);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "MISSING OPENING BRACKETS");
  }
}

// TEST(Errors, Unary) {
  // char eq_17_[kEqSize] = "(+)";
    // char eq_00_[kEqSize] = "+";
// }

// TEST(Errors, VariousAccuracy)                                       // добавить тесты на точность на точность <0, на буквы

TEST(Errors, Trigonometry) {                            // +++ГОТОВО+++
  char eq_00_[kEqSize] = "lig(0)";
  char eq_01_[kEqSize] = "son(0)";
  char eq_02_[kEqSize] = "asls(2)";
  char eq_03_[kEqSize] = "sin()";
  char eq_04_[kEqSize] = "sin(cos(tan()))";
  char eq_05_[kEqSize] = "sin(kiss(tan()))";
  s21::Model calc_00_(eq_00_, 0);
  s21::Model calc_01_(eq_01_, 0);
  s21::Model calc_02_(eq_02_, 0);
  s21::Model calc_03_(eq_03_, 0);
  s21::Model calc_04_(eq_04_, 0);
  s21::Model calc_05_(eq_05_, 0);
  try {
    EXPECT_THROW(calc_00_.ModelProcedure(calc_00_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
  }
  try {
    EXPECT_THROW(calc_01_.ModelProcedure(calc_01_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
  }
  try {
    EXPECT_THROW(calc_02_.ModelProcedure(calc_02_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
  }
  try {
    EXPECT_THROW(calc_03_.ModelProcedure(calc_03_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "EMPTY TRIGONOMETRY BRACKETS");
  }
  try {
    EXPECT_THROW(calc_04_.ModelProcedure(calc_04_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "EMPTY TRIGONOMETRY BRACKETS");
  }
  try {
    EXPECT_THROW(calc_05_.ModelProcedure(calc_05_), std::invalid_argument);
  } catch (const std::exception& exception) {
    EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
  }
}

// TEST(Errors, FAILED_X_ERROR) {
//   char eq_00_[kEqSize] = "1*x";
//   s21::Model calc_00_(eq_00_, "");
//   s21::Model calc_01_(eq_00_, "qx");
//   s21::Model calc_02_(eq_00_, "1..");
//   s21::Model calc_03_(eq_00_, ".");
//   s21::Model calc_04_(eq_00_, "()");
//   s21::Model calc_05_(eq_00_, "-.");
//   s21::Model calc_06_(eq_00_, "1-");
//   s21::Model calc_07_(eq_00_, "(-(-0)");
//   s21::Model calc_08_(eq_00_, "-.");
//   try {
//     EXPECT_THROW(calc_00_.ModelProcedure(calc_00_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
//   }
//   try {
//     EXPECT_THROW(calc_01_.ModelProcedure(calc_01_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
//   }
//   try {
//     EXPECT_THROW(calc_02_.ModelProcedure(calc_02_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
//   }
//   try {
//     EXPECT_THROW(calc_03_.ModelProcedure(calc_03_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
//   }
//   try {
//     EXPECT_THROW(calc_04_.ModelProcedure(calc_04_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
//   }
//   try {
//     EXPECT_THROW(calc_05_.ModelProcedure(calc_05_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
//   }
//     try {
//     EXPECT_THROW(calc_06_.ModelProcedure(calc_06_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
//   }
//     try {
//     EXPECT_THROW(calc_07_.ModelProcedure(calc_07_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
//   }
//     try {
//     EXPECT_THROW(calc_08_.ModelProcedure(calc_08_), std::invalid_argument);
//   } catch (const std::exception& exception) {
//     EXPECT_STREQ(exception.what(), "WRONG TRIGONOMETRY");
//   }
// }

// TEST(Errors, Syntax) {
  // неверный порядо 1-
  // 3*20mod
  // 1%4%
// }                                      // НАПИСАТЬ ТЕСТЫ




// тесты на смешанные уравнения тесты на x со всеми вышеупомянутыми кейсами
// сделать кнопку допуска экспоненциальной записи в ответе (12148457612938346 или 1,2148457E16)
// реализовать прием inf и nan в выражении

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// clang++ -Wall -Werror -Wextra -c -g -std=c++17 test.cc -o test.o && clang++ test.o main.a -lgtest -o gtest.out && ./gtest.out