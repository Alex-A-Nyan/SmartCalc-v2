// Copyright 2024 valeryje

#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

/* ----- LIBRARIES AND DEFINES ----- */
#include <stdexcept>
#include <iostream>
#include <string>

#include "calculator.h"
#include "stacker.h"
#include "validator.h"

/* ----- NAMESPACES AND CLASSES ----- */
namespace s21 {
class Model {
 public:
  /* ----- CONSTANTS ----- */
  constexpr static int kEqSize = 256;
  constexpr static int kStandartAccuracy = 7;
  constexpr static int kMaxAccuracy = 20;

  /* ----- CONSTRUCTORS AND DESTRUCTORS ----- */
  // default and parametrized constructors
  Model() = default;
  explicit Model(char *eq_from_view_, char *x_from_view_);
  explicit Model(char *result_);
  // copy and move constructors and their overloads
  Model(const Model &other) = default;
  Model(Model &&other) noexcept = default;
  Model &operator=(const Model &other) = default;
  Model &operator=(Model &&other) noexcept = default;
  // destructor
  virtual ~Model() = default;
  /* ----- ACCESSORS AND MUTATORS ----- */
  char *get_eq() noexcept;
  char *get_x() noexcept;
  char *get_accuracy() noexcept;
  char *get_respond() noexcept;
  void set_eq_x(char *eq_from_view_, char *x_from_view_);
  // void set_accuracy(int accur_);
  // void set_respond(double answer_);
  // void set_x(char *x_from_view_);
  // Model set_answer(double answer_calc_);

  /* ----- METHODS ----- */
  double ModelProcedure(Model model_);
  // char *ModelProcedure(Model model_);

 private:
  /* ----- METHODS ----- */
  void Accurator(double *answer_);
  int DigitChecker(char *eq_to_calc, int i);
  // void Transfer(double answer_);
  /* ----- VARIABLES ----- */
  char *equation_;
  char *x_value_;
  char *accuracy_;
  char *respond_;
};  // class Model
};  // namespace s21

#endif  // SRC_MODEL_MODEL_H_
