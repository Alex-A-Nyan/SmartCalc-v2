// Copyright 2024 valeryje

#ifndef SRC_MODEL_VALIDATOR_H_
#define SRC_MODEL_VALIDATOR_H_

/* ----- LIBRARIES AND DEFINES ----- */
#include <cstring>
#include <regex>
#include <stdexcept>

/* ----- NAMESPACES AND CLASSES ----- */
namespace s21 {
class Validator {
 public:
  /* ----- CONSTANTS ----- */
  constexpr static int kEqSize = 256;
  //   constexpr static char *kSymbolsEq =
  //       "^[%()\\*+-./0123456789^acdegilmnoqrstx]+$";  // allowed symbols for
  //                                                     // operations
  //   constexpr static char *kSymbolsX =
  //       "^[+-.0123456789]+$";  // allowed symbols for x
  /* ----- CONSTRUCTORS AND DESTRUCTORS ----- */
  // default and parametrized constructors
  Validator() = default;
  explicit Validator(char *eq_to_calc_, char *eq_to_x_);
  // copy and move constructors and their overloads
  Validator(const Validator &other) = default;
  Validator(Validator &&other) noexcept = default;
  Validator &operator=(const Validator &other) = default;
  Validator &operator=(Validator &&other) noexcept = default;
  // destructor
  virtual ~Validator() = default;
  /* ----- ACCESSORS AND MUTATORS ----- */
  /* ----- METHODS ----- */
  //   int Validate(char *eq_to_calc_, char *eq_to_x_);
  int Validate();
  int ValidateX(char *eq_to_x_);

 private:
  /* ----- METHODS ----- */
  /* ----- VARIABLES ----- */
  char *equation_;
  char *x_value_;

};  // class Validator
};  // namespace s21

#endif  // SRC_MODEL_VALIDATOR_H_
