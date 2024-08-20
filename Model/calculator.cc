// Copyright 2024 valeryje

#include "calculator.h"

/* ----- CONSTRUCTORS AND DESTRUCTORS ----- */

/* ----- METHODS ----- */

double s21::Calculator::Count(std::vector<std::pair<double, char>> *reverse_polish_) {
  double answer_ = 0.0;
  for (int i = 1; i < (int)reverse_polish_->size(); i++) {
    std::pair<double, char> new_number_ = {0.0, 0};
    if (std::get<char>((*reverse_polish_)[i]) != 0) {
      double number_one_ = std::get<double>((*reverse_polish_)[i - 1]);
      double number_two_ = 0.0;
      if (i > 1) number_two_ = std::get<double>((*reverse_polish_)[i - 2]);
      char lexem_ = std::get<char>((*reverse_polish_)[i]);
      if (lexem_ < 97) {
        new_number_ = std::make_pair(OperatorSimple(number_two_, number_one_, lexem_), 0);
        i = i - 2;
        reverse_polish_->erase(reverse_polish_->begin() + i);
        reverse_polish_->erase(reverse_polish_->begin() + i);
      } else {
        new_number_ = std::make_pair(OperatorComplex(number_one_, lexem_), 0);
        i = i - 1;
        reverse_polish_->erase(reverse_polish_->begin() + i);
      }
      (*reverse_polish_)[i] = new_number_;
    }
  }
  if (reverse_polish_->size() > 1)
    throw std::underflow_error("UNFINISHED CALCULATION");
  answer_ = std::get<double>((*reverse_polish_)[0]);
  return answer_;
}

double s21::Calculator::OperatorSimple(double number_one_, double number_two_, char lexem_) {
  double result_ = 0.0;
  if (lexem_ == '^') {
    result_ = pow(number_one_, number_two_);
  } else if (lexem_ == '%') {
    result_ = fmod(number_one_, number_two_);
  } else if (lexem_ == '/') {
    result_ = number_one_ / number_two_;
  } else if (lexem_ == '*') {
    result_ = number_one_ * number_two_;
  } else if (lexem_ == '-') {
    result_ = number_one_ - number_two_;
  } else if (lexem_ == '+') {
    result_ = number_one_ + number_two_;
  }
  return result_;
}

double s21::Calculator::OperatorComplex(double number_, char lexem_) {
  double result_ = 0.0;
  if (lexem_ == 's') {
    result_ = sin(number_);
  } else if (lexem_ == 'c') {
    result_ = cos(number_);
  } else if (lexem_ == 't') {
    result_ = tan(number_);
  } else if (lexem_ == 'i') {
    result_ = asin(number_);
  } else if (lexem_ == 'o') {
    result_ = acos(number_);
  } else if (lexem_ == 'a') {
    result_ = atan(number_);
  } else if (lexem_ == 'l') {
    result_ = log10(number_);
  } else if (lexem_ == 'n') {
    result_ = log(number_);
  } else if (lexem_ == 'q') {
    result_ = sqrt(number_);
  } else if (lexem_ == 'e') {
    result_ = ceil(number_);
  } else if (lexem_ == 'f') {
    result_ = floor(number_);
  }
  return result_;
}
