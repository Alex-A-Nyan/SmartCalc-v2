// Copyright 2024 valeryje

#ifndef SRC_MODEL_CALCULATOR_H_
#define SRC_MODEL_CALCULATOR_H_

/* ----- LIBRARIES AND DEFINES ----- */
#include <cmath>
#include <stdexcept>
#include <utility>
#include <vector>

/* ----- NAMESPACES AND CLASSES ----- */
namespace s21 {
class Calculator {
 public:
  /* ----- CONSTANTS ----- */
  /* ----- CONSTRUCTORS AND DESTRUCTORS ----- */
  // default and parametrized constructors
  Calculator() = default;
  // copy and move constructors and their overloads
  Calculator(const Calculator &other) = default;
  Calculator(Calculator &&other) noexcept = default;
  Calculator &operator=(const Calculator &other) = default;
  Calculator &operator=(Calculator &&other) noexcept = default;
  // destructor
  virtual ~Calculator() = default;
  /* ----- ACCESSORS AND MUTATORS ----- */

  /* ----- METHODS ----- */
  double Count(std::vector<std::pair<double, char>> *reverse_polish_);
  double OperatorSimple(double number_one_, double number_two_, char lexem_);
  double OperatorComplex(double number_, char lexem_);

 private:
  /* ----- VARIABLES ----- */
};  // class Calculator
};  // namespace s21

#endif  // SRC_MODEL_CALCULATOR_H_
