// Copyright 2024 valeryje

#include "validator.h"

/* ----- CONSTRUCTORS AND DESTRUCTORS ----- */
s21::Validator::Validator(char *eq_to_calc_, char *eq_to_x_)
    : equation_(eq_to_calc_), x_value_(eq_to_x_) {}

int s21::Validator::Validate() {
  x_value_++;
  // if (x_value_ != NULL) {  
  int length_ = strlen(equation_);
  if (length_ == 0) throw std::underflow_error("EMPTY EQUATION");
  if (length_ >= kEqSize) throw std::overflow_error("EXCEEDED MAX LENGTH");
  if (equation_[0] == ')' || equation_[0] == '^' || equation_[0] == '*' ||
      equation_[0] == '/' || equation_[0] == 'm' || equation_[length_] == '^' ||
      equation_[length_] == '*' || equation_[length_] == '/' ||
      equation_[length_] == '+' || equation_[length_] == '-' ||
      equation_[length_] == '(' || equation_[length_] == 'd' ||
      (length_ == 1 && (equation_[1] == '+' || equation_[1] == '-')))
    throw std::invalid_argument("FREE OPERATOR");
  // int x_value = 0;
  // try {
  //   check_.ForbidChar(eq_to_calc_, kSymbolsEq, x_value);
  // } catch (...) {
  //   throw regex_error("FORBIDDEN SYMBOLS");
  //   throw regex_error("WRONG TRIGONOMETRY");
  //   throw regex_error("IMPOSSIBLE DECIMAL");
  //   throw regex_error("EMPTY DECIMAL");
  //   throw regex_error("WRONG SEQUENCE");
  //   throw regex_error("MISSING BRACKETS");
  // }
  // try {
  //   if (*this.eq_to_x_ != nullptr) ValidateX(eq_to_x_);
  // } catch (...) {
  // }
  // }
  return 1;
}

int s21::Validator::ValidateX(char *eq_to_x_) {
  int length_ = strlen(eq_to_x_);
  if (length_ == 0) throw std::underflow_error("EMPTY X-NUMBER");
  if (length_ >= kEqSize) throw std::overflow_error("EXCEEDED MAX X-LENGTH");
  if (length_ == 1 && (eq_to_x_[1] == '+' || eq_to_x_[1] == '-'))
    throw std::invalid_argument("INCORRECT X-NUMBER");
  if ((strchr(eq_to_x_, '-') != strrchr(eq_to_x_, '-')) ||
      (strchr(eq_to_x_, '+') != strrchr(eq_to_x_, '+')) ||
      (strchr(eq_to_x_, '-') != eq_to_x_) ||
      (strchr(eq_to_x_, '+') != eq_to_x_))
    throw std::invalid_argument("OPERATIONS INSIDE X-FIELD");
  if (strchr(eq_to_x_, '.') != strrchr(eq_to_x_, '.') ||
      strchr(eq_to_x_, ',') != strrchr(eq_to_x_, ',')
      // || (strchr(eq_to_x_, '.') > 0 && strchr(eq_to_x_, ',') > 0) // придумать, как иначе считать сумму символов
      )
    throw std::invalid_argument("INCORRECT DECIMAL X-NUMBER");
  // try {
  //   check_.ForbidChar(eq_to_x_, kSymbolsX, 1);
  // } catch (...) {
  // throw regex_error("FORBIDDEN X-SYMBOLS");
  // }
  return 0;  // исправить тип данных
}
