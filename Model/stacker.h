// Copyright 2024 valeryje

#ifndef SRC_MODEL_STACKER_H_
#define SRC_MODEL_STACKER_H_

/* ----- LIBRARIES AND DEFINES ----- */
#include <cstring>
#include <stack>
#include <stdexcept>
#include <utility>
#include <vector>
#include <cmath>

struct technical_ {
  int bracket_counter_;
  int unary_allow_;
  int length_;
  int implicit_multiply_;
};

/* ----- NAMESPACES AND CLASSES ----- */
namespace s21 {
class Stacker {
 public:
  /* ----- CONSTANTS ----- */
  constexpr static int kEqSize = 256;
  /* ----- CONSTRUCTORS AND DESTRUCTORS ----- */
  // default and parametrized constructors
  Stacker() = default;
  explicit Stacker(char *eq_to_calc_, char *eq_to_x_);
  // copy and move constructors and their overloads
  Stacker(const Stacker &other) = default;
  Stacker(Stacker &&other) noexcept = default;
  Stacker &operator=(const Stacker &other) = default;
  Stacker &operator=(Stacker &&other) noexcept = default;
  // destructor
  virtual ~Stacker() = default;
  /* ----- ACCESSORS AND MUTATORS ----- */
  /* ----- METHODS ----- */
  // void Rebuild(char *eq_to_calc_, char *eq_to_x_,
  // std::vector<std::pair<double, char>> *reverse_polish_);
  void Rebuild(std::vector<std::pair<double, char>> *reverse_polish_);
  // void UnaryOperator(struct technical_ *tech_, std::vector<std::pair<double,
  // char>> *reverse_polish_);
  void UnaryOperator(char *eq_to_calc, int i, struct technical_ *tech_,
                     std::vector<std::pair<double, char>> *reverse_polish_,
                     std::stack<std::pair<char, int>> *lexem_stack_);
  void SpecialValue(char *eq_to_calc, int *i, struct technical_ *tech_,
                       std::vector<std::pair<double, char>> *reverse_polish_);
  void NumberCollector(char *eq_to_calc, int *i, struct technical_ *tech_,
                       std::vector<std::pair<double, char>> *reverse_polish_);
  // void XDeployer(char *eq_to_calc, char *x_value_,
  // std::vector<std::pair<double, char>> *reverse_polish_);
  void XDeployer(char *x_value_,
                 std::vector<std::pair<double, char>> *reverse_polish_);
  void TrigoBracketOperator(char *eq_to_calc, int *i, struct technical_ *tech_,
                            std::stack<std::pair<char, int>> *lexem_stack_);
  void CloseBracketOperator(
      char *eq_to_calc, int i, struct technical_ *tech_,
      std::vector<std::pair<double, char>> *reverse_polish_,
      std::stack<std::pair<char, int>> *lexem_stack_);
  void OperatorCollector(char *eq_to_calc, int i, struct technical_ *tech_,
                         std::vector<std::pair<double, char>> *reverse_polish_,
                         std::stack<std::pair<char, int>> *lexem_stack_);
  void LastOperatorChecker(
      struct technical_ *tech_,
      std::vector<std::pair<double, char>> *reverse_polish_,
      std::stack<std::pair<char, int>> *lexem_stack_);
  /* ----- SUPPORT METHODS ----- */
  int DigitChecker(char *eq_to_calc, int i);
  int DotChecker(char *eq_to_calc, int i);
  int SpecialChecker(char *eq_to_calc, int i);
  int PriorityChecker(char *eq_to_calc, int i,
                      std::stack<std::pair<char, int>> *lexem_stack_);
  int PriorityEvaluation(char *eq_to_calc, int i);

 private:
  /* ----- VARIABLES ----- */
  char *equation_;
  char *x_value_;
};  // class Stacker
};  // namespace s21

#endif  // SRC_MODEL_STACKER_H_
