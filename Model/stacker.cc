// Copyright 2024 valeryje

#include "stacker.h"

/* ----- CONSTRUCTORS AND DESTRUCTORS ----- */

s21::Stacker::Stacker(char *eq_to_calc_, char *eq_to_x_)
    : equation_(eq_to_calc_), x_value_(eq_to_x_) {}

/* ----- METHODS ----- */

void s21::Stacker::Rebuild(
    std::vector<std::pair<double, char>> *reverse_polish_) {
  struct technical_ tech_ = {0, 0, 0, 0};
  x_value_ = x_value_ + 1;  // потом убрать
  tech_.length_ = strlen(equation_);
  std::stack<std::pair<char, int>> lexem_stack_ = {};
  for (int i = 0; i < tech_.length_; i++) {
    if (i == 0 && (equation_[i] == '+' || equation_[i] == '-')) {
      // может добавить параметр проверки номера позиции от начала скобок или начала всего выражения, чтобы сразу домножать на +/-1; или реализовать через 0 +/- и далее.
      UnaryOperator(equation_, i, &tech_, reverse_polish_, &lexem_stack_);
    } else if (SpecialChecker(equation_, i)) {
      SpecialValue(equation_, &i, &tech_, reverse_polish_);
    } else if (DigitChecker(equation_, i) || DotChecker(equation_, i)) {
      NumberCollector(equation_, &i, &tech_, reverse_polish_);
    } else if (equation_[i] == 'x') {
      // XDeployer(eq_to_calc_, x_value_, reverse_polish_);
      XDeployer(equation_, reverse_polish_);
    } else if ((equation_[i] == '(' || equation_[i] > 96) && equation_[i] != 'm') {
      TrigoBracketOperator(equation_, &i, &tech_, &lexem_stack_);
    } else if (equation_[i] == ')') {
      CloseBracketOperator(equation_, i, &tech_, reverse_polish_, &lexem_stack_);
    } else {
      OperatorCollector(equation_, i, &tech_, reverse_polish_, &lexem_stack_);
      if (equation_[i] == 'm') i = i + 2;
    }
  }
  LastOperatorChecker(&tech_, reverse_polish_, &lexem_stack_);
}

void s21::Stacker::SpecialValue(
    char *eq_to_calc, int *i, struct technical_ *tech_,
    std::vector<std::pair<double, char>> *reverse_polish_) {
  char special_ = 0;
  if (*i + 2 < tech_->length_) {
    if (!strncmp(eq_to_calc + *i, "INF", 3)) special_ = 'i';
    if (!strncmp(eq_to_calc + *i, "Inf", 3)) special_ = 'i';
    if (!strncmp(eq_to_calc + *i, "NaN", 3)) special_ = 'n';
    if (!strncmp(eq_to_calc + *i, "NAN", 3)) special_ = 'n';
    if (!strncmp(eq_to_calc + *i, "nan", 3)) special_ = 'n';
    *i = *i + 2;
    special_++;
  }
  if (special_ == 0) throw std::invalid_argument("WRONG SPECIAL VALUE");
  std::pair<double, char> value_ = std::make_pair(0.0, 0);
  if (special_ == 'i') {
    value_ = std::make_pair(INFINITY, 0);
  } else {
    value_ = std::make_pair(NAN, 0);
  }
  reverse_polish_->push_back(value_);
  tech_->unary_allow_ = 1;
  tech_->implicit_multiply_ = 1;
}

void s21::Stacker::UnaryOperator(
    char *eq_to_calc, int i, struct technical_ *tech_,
    std::vector<std::pair<double, char>> *reverse_polish_,
    std::stack<std::pair<char, int>> *lexem_stack_) {
  // void s21::Stacker::UnaryOperator(struct technical_ *tech_,
  // std::vector<std::pair<double, char>> *reverse_polish_) {
  if (tech_->unary_allow_) {
    throw std::invalid_argument("WRONG UNARY SEQUENCE");
  } else {
    std::pair<double, char> zero = std::make_pair(0.0, 0);
    std::pair<char, int> sign = std::make_pair(eq_to_calc[i], 1);
    reverse_polish_->push_back(zero);
    lexem_stack_->push(sign);
    tech_->unary_allow_ = 1;
  }
}

void s21::Stacker::NumberCollector(
    char *eq_to_calc, int *i, struct technical_ *tech_,
    std::vector<std::pair<double, char>> *reverse_polish_) {
  char number_gatherer_[kEqSize] = {0};
  int pos = 0;
  int dot_count = 0;
  while (*i < tech_->length_ && (DigitChecker(eq_to_calc, *i) || DotChecker(eq_to_calc, *i))) {
    if (eq_to_calc[*i] == ',') {
      number_gatherer_[pos] = '.';
    } else {
      number_gatherer_[pos] = eq_to_calc[*i];
    }
    if (DotChecker(eq_to_calc, *i)) dot_count++;
    if (dot_count > 1) throw std::invalid_argument("WRONG DECIMAL");
    *i = *i + 1;
    pos++;
  }
  double number_ = atof(number_gatherer_);
  std::pair<double, char> collection_ = std::make_pair(number_, 0);
  reverse_polish_->push_back(collection_);
  tech_->unary_allow_ = 1;
  tech_->implicit_multiply_ = 1;
  *i = *i - 1;
}

void s21::Stacker::XDeployer(
    char *x_value_, std::vector<std::pair<double, char>> *reverse_polish_) {
  // if (eq_to_calc[i - 1]) // ЧТО ЭТО ТАКОЕ
  double x_ = atof(x_value_);
  std::pair<double, char> number = std::make_pair(x_, 0);
  reverse_polish_->push_back(number);
}

void s21::Stacker::TrigoBracketOperator(
    char *eq_to_calc, int *i, struct technical_ *tech_,
    std::stack<std::pair<char, int>> *lexem_stack_) {
  // = TRIGONOMETRY + OTHERS (MAX PRIORITY) = //
  // 's'= sin        'i'= asin     'l'= log10 //
  // 'c'= cos        'o'= acos     'n'= log   //
  // 't'= tan        'a'= atan     'e'= ceil  //
  //                 'q'= sqrt     'f'= floor //
  // ======================================== //
  // ======== TRIGONOMETRY + OTHERS (MAX PRIORITY) ======== //
  // 's'= sin           'i'= asin/arcsin        'e'= ceil   //
  // 'c'= cos           'o'= acos/arccos        'f'= floor  //
  // 't'= tan/tg        'a'= atan/arctan/arctg              //
  // 'l'= log10/lg/log  'n'= ln/logE/loge       'q'= sqrt   //
  // ====================================================== //
  if (tech_->implicit_multiply_) {
    std::pair<char, int> multiply_ = std::make_pair('*', 2);
    lexem_stack_->push(multiply_);
    tech_->implicit_multiply_ = 0;
  }
  char code_symbol_ = 0;
  if (eq_to_calc[*i] != '(') {
    // if (*i + 2 < tech_->length_) {
    //   if (!strncmp(eq_to_calc + *i, "tg(", 3)) code_symbol_ = 't';
    //   if (!strncmp(eq_to_calc + *i, "lg(", 3)) code_symbol_ = 'd';
    //   if (!strncmp(eq_to_calc + *i, "ln(", 3)) code_symbol_ = 'n';
    //   *i = *i + 2;
    // } else if (*i + 3 < tech_->length_) {
    //   if (!strncmp(eq_to_calc + *i, "sin(", 4)) code_symbol_ = 's';
    //   if (!strncmp(eq_to_calc + *i, "cos(", 4)) code_symbol_ = 'c';
    //   if (!strncmp(eq_to_calc + *i, "tan(", 4)) code_symbol_ = 't';
    //   if (!strncmp(eq_to_calc + *i, "log(", 4)) code_symbol_ = 'd';
    //   *i = *i + 3;
    // } else if (*i + 4 < tech_->length_) {
    //   if (!strncmp(eq_to_calc + *i, "asin(", 5)) code_symbol_ = 'i';
    //   if (!strncmp(eq_to_calc + *i, "acos(", 5)) code_symbol_ = 'o';
    //   if (!strncmp(eq_to_calc + *i, "atan(", 5)) code_symbol_ = 'a';
    //   if (!strncmp(eq_to_calc + *i, "sqrt(", 5)) code_symbol_ = 'q';
    //   if (!strncmp(eq_to_calc + *i, "ceil(", 5)) code_symbol_ = 'e';
    //   if (!strncmp(eq_to_calc + *i, "loge(", 5)) code_symbol_ = 'n';
    //   if (!strncmp(eq_to_calc + *i, "logE(", 5)) code_symbol_ = 'n';
    //   *i = *i + 4;
    // } else if (*i + 5 < tech_->length_) {
    //   if (!strncmp(eq_to_calc + *i, "log10(", 6)) code_symbol_ = 'd';
    //   if (!strncmp(eq_to_calc + *i, "arctg(", 6)) code_symbol_ = 'a';
    //   if (!strncmp(eq_to_calc + *i, "floor(", 6)) code_symbol_ = 'f';
    //   *i = *i + 5;
    // } else if (*i + 6 < tech_->length_) {
    //   if (!strncmp(eq_to_calc + *i, "arcsin(", 7)) code_symbol_ = 'i';
    //   if (!strncmp(eq_to_calc + *i, "arccos(", 7)) code_symbol_ = 'o';
    //   if (!strncmp(eq_to_calc + *i, "arctan(", 7)) code_symbol_ = 'a';
    //   *i = *i + 6;
    // }
    if (*i + 6 < tech_->length_)
      if (!strncmp(eq_to_calc + *i, "arcsin(", 7) || !strncmp(eq_to_calc + *i, "arccos(", 7) || !strncmp(eq_to_calc + *i, "arctan(", 7)) {
        code_symbol_ = eq_to_calc[*i + 4];
        *i = *i + 6;
      }
    if (*i + 5 < tech_->length_)
      if (!strncmp(eq_to_calc + *i, "log10(", 6) || !strncmp(eq_to_calc + *i, "arctg(", 6) || !strncmp(eq_to_calc + *i, "floor(", 6)) {
        code_symbol_ = eq_to_calc[*i];
        *i = *i + 5;
      }
    if (*i + 4 < tech_->length_) {
      if (!strncmp(eq_to_calc + *i, "asin(", 5) || !strncmp(eq_to_calc + *i, "acos(", 5) || !strncmp(eq_to_calc + *i, "atan(", 5)) {
        code_symbol_ = eq_to_calc[*i + 2];
        *i = *i + 4;
      }
      if (!strncmp(eq_to_calc + *i, "sqrt(", 5) || !strncmp(eq_to_calc + *i, "ceil(", 5)) {
        code_symbol_ = eq_to_calc[*i + 1];
        *i = *i + 4;
      }
      if (!strncmp(eq_to_calc + *i, "loge(", 5) || !strncmp(eq_to_calc + *i, "logE(", 5)) {
        code_symbol_ = 'n';
        *i = *i + 4;
      }
    }
    if (*i + 3 < tech_->length_)
      if (!strncmp(eq_to_calc + *i, "sin(", 4) || !strncmp(eq_to_calc + *i, "cos(", 4) ||
          !strncmp(eq_to_calc + *i, "tan(", 4) || !strncmp(eq_to_calc + *i, "log(", 4)) {
        code_symbol_ = eq_to_calc[*i];
        *i = *i + 3;
      }
    if (*i + 2 < tech_->length_) {
      if (!strncmp(eq_to_calc + *i, "tg(", 3) || !strncmp(eq_to_calc + *i, "lg(", 3)) {
        code_symbol_ = eq_to_calc[*i];
        *i = *i + 2;
      }
      if (!strncmp(eq_to_calc + *i, "ln(", 3)) {
        code_symbol_ = 'n';
        *i = *i + 2;
      }
    }
    if (code_symbol_ == 0) throw std::invalid_argument("WRONG TRIGONOMETRY");
    std::pair<char, int> trigonometry_ = std::make_pair(code_symbol_, 0);
    lexem_stack_->push(trigonometry_);
  }
  std::pair<char, int> bracket_ = std::make_pair('(', 0);
  lexem_stack_->push(bracket_);
  tech_->bracket_counter_++;
  tech_->unary_allow_ = 0;
}

void s21::Stacker::CloseBracketOperator(
    char *eq_to_calc, int i, struct technical_ *tech_,
    std::vector<std::pair<double, char>> *reverse_polish_,
    std::stack<std::pair<char, int>> *lexem_stack_) {
  tech_->bracket_counter_--;
  if (tech_->bracket_counter_ < 0) throw std::underflow_error("MISSING OPENING BRACKETS");
  if (eq_to_calc[i - 1] == '(') {
    if (i > 1) {
      if ((eq_to_calc[i - 2] > 96) && (eq_to_calc[i - 2] != 'x'))
        throw std::invalid_argument("EMPTY TRIGONOMETRY BRACKETS");
    }
    throw std::invalid_argument("EMPTY BRACKETS");
  }
  while (std::get<char>(lexem_stack_->top()) != '(') {
    if (lexem_stack_->size() == 0)
      throw std::underflow_error("MISSING OPENING BRACKETS");
    std::pair<double, char> operat_ =
        std::make_pair(0.0, std::get<char>(lexem_stack_->top()));
    reverse_polish_->push_back(operat_);
    lexem_stack_->pop();
  }
  if (std::get<char>(lexem_stack_->top()) == '(') lexem_stack_->pop();
  if (lexem_stack_->size() != 0 && std::get<char>(lexem_stack_->top()) > 96) {
    std::pair<double, char> trigonometry_ =
        std::make_pair(0.0, std::get<char>(lexem_stack_->top()));
    reverse_polish_->push_back(trigonometry_);
    lexem_stack_->pop();
  }
}

void s21::Stacker::OperatorCollector(
    char *eq_to_calc, int i, struct technical_ *tech_,
    std::vector<std::pair<double, char>> *reverse_polish_,
    std::stack<std::pair<char, int>> *lexem_stack_) {
  if (tech_->unary_allow_ == 0 && eq_to_calc[i - 1] == '(') {
    UnaryOperator(equation_, i, tech_, reverse_polish_, lexem_stack_);
  } else {
    char fix_m_ = eq_to_calc[i];
    if (fix_m_ == 'm') {
      if (i + 2 < tech_->length_) 
        if (!strncmp(eq_to_calc + i, "mod", 3)) fix_m_ = '%';
      if (fix_m_ != '%') throw std::invalid_argument("WRONG OPERATOR");
    }
    std::pair<char, int> operator_new_ =
        std::make_pair(fix_m_, PriorityEvaluation(eq_to_calc, i));
    if (lexem_stack_->size() == 0) {
      lexem_stack_->push(operator_new_);
    } else {
      while (lexem_stack_->size() != 0 &&
             (PriorityChecker(eq_to_calc, i, lexem_stack_))) {
        std::pair<double, char> operator_transfer_ =
            std::make_pair(0.0, std::get<char>(lexem_stack_->top()));
        reverse_polish_->push_back(operator_transfer_);
        lexem_stack_->pop();
      }
      lexem_stack_->push(operator_new_);
    }
  }
  tech_->unary_allow_ = 1;
  tech_->implicit_multiply_ = 0;
}

void s21::Stacker::LastOperatorChecker(
    struct technical_ *tech_,
    std::vector<std::pair<double, char>> *reverse_polish_,
    std::stack<std::pair<char, int>> *lexem_stack_) {
  while (lexem_stack_->size() != 0) {
    if (tech_->bracket_counter_ > 0)
      throw std::overflow_error("MISSING CLOSING BRACKETS");
    std::pair<double, char> last_operator_ =
        std::make_pair(0.0, std::get<char>(lexem_stack_->top()));
    reverse_polish_->push_back(last_operator_);
    lexem_stack_->pop();
  }
}

/* ----- SUPPORT METHODS ----- */

int s21::Stacker::DigitChecker(char *eq_to_calc, int i) {
  return ((eq_to_calc[i] > 47 && eq_to_calc[i] < 58)) ? 1 : 0;
}

int s21::Stacker::DotChecker(char *eq_to_calc, int i) {
  return (eq_to_calc[i] == '.' || eq_to_calc[i] == ',') ? 1 : 0;
}

int s21::Stacker::SpecialChecker(char *eq_to_calc, int i) {
  return (eq_to_calc[i] == 'i' || eq_to_calc[i] == 'I' || eq_to_calc[i] == 'n' || eq_to_calc[i] == 'N') ? 1 : 0;
}

int s21::Stacker::PriorityChecker(
    char *eq_to_calc, int i, std::stack<std::pair<char, int>> *lexem_stack_) {
  int swap_ = 0;
  int priority_ = PriorityEvaluation(eq_to_calc, i);
  // if (/*stack::lexem_stack_.size() > 0 && */ )
  if (std::get<int>(lexem_stack_->top()) >= priority_ && priority_ != 3) {
    swap_ = 1;
  }
  return swap_;
}

int s21::Stacker::PriorityEvaluation(char *eq_to_calc, int i) {
  // ===== PRIORITY  (DESCENDING ORDER) ===== //
  //                 '^'= pow                 //
  // '*'             '/'           '%'= mod   //
  // '+'             '-'                      //
  // ======================================== //
  int priority_ = 0;
  if (eq_to_calc[i] == '+' || eq_to_calc[i] == '-') {
    priority_ = 1;
  } else if (eq_to_calc[i] == '*' || eq_to_calc[i] == '/' ||
             eq_to_calc[i] == '%' || eq_to_calc[i] == 'm') {
    priority_ = 2;
  } else if (eq_to_calc[i] == '^') {
    priority_ = 3;
  }
  return priority_;
}







// // Copyright 2024 valeryje

// #include "stacker.h"

// /* ----- CONSTRUCTORS AND DESTRUCTORS ----- */

// s21::Stacker::Stacker(char *eq_to_calc_, char *eq_to_x_)
//     : equation_(eq_to_calc_), x_value_(eq_to_x_) {}

// /* ----- METHODS ----- */

// void s21::Stacker::Rebuild(std::vector<std::pair<double, char>> *reverse_polish_) {
//   struct technical_ tech_ = {0, 0, 0, 0};
//   x_value_ = x_value_ +1; //потом убрать
//   tech_.length_ = strlen(equation_);
//   std::stack<std::pair<char, int>> lexem_stack_ = {};
//   for (int i = 0; i < tech_.length_; i++) {
//     if (equation_[i] == '+' || equation_[i] == '-')
//   // может добавить параметр проверки номера позиции от начала скобок или начала всего выражения, чтобы сразу домножать на +/-1; или реализовать через 0 +/- и далее.
//       // UnaryOperator(equation_, i, &tech_, reverse_polish_, &lexem_stack_);
//       if (i == 0 || tech_.unary_allow_ == 0) 
//         UnaryOperator(&tech_, reverse_polish_);
//     if (DigitChecker(equation_, i) || DotChecker(equation_, i)) {
//       NumberCollector(equation_, &i, &tech_, reverse_polish_);
//     } else if (equation_[i] == 'x') {
//       // XDeployer(eq_to_calc_, x_value_, reverse_polish_);
//       XDeployer(equation_, reverse_polish_);
//     } else if (equation_[i] == '(' || equation_[i] > 96) {
//       TrigoBracketOperator(equation_, &i, &tech_, &lexem_stack_);
//     } else if (equation_[i] == ')') {
//       CloseBracketOperator(equation_, i, &tech_, reverse_polish_, &lexem_stack_);
//     } else {
//       OperatorCollector(equation_, i, &tech_, reverse_polish_, &lexem_stack_);
//     }
//   }
//   LastOperatorChecker(&tech_, reverse_polish_, &lexem_stack_);
// }

// // void s21::Stacker::UnaryOperator(char *eq_to_calc, int i, struct technical_ *tech_, std::vector<std::pair<double, char>> *reverse_polish_, std::stack<std::pair<char, int>> *lexem_stack_) {
// void s21::Stacker::UnaryOperator(struct technical_ *tech_, std::vector<std::pair<double, char>> *reverse_polish_) {
//   if (tech_->unary_allow_) {
//     throw std::invalid_argument("WRONG UNARY SEQUENCE");
//   } else {
//     std::pair<double, char> zero = std::make_pair(0.0, 0);
//     // std::pair<char, int> sign = std::make_pair(eq_to_calc[i], 1);
//     reverse_polish_->push_back(zero);
//     // lexem_stack_->push(sign);
//     tech_->unary_allow_ = 1;
//   }
// }

// void s21::Stacker::NumberCollector(char *eq_to_calc, int *i, struct technical_ *tech_, std::vector<std::pair<double, char>> *reverse_polish_) {
//   char number_gatherer_[kEqSize] = {0};
//   int pos = 0;
//   while (*i < tech_->length_ && (DigitChecker(eq_to_calc, *i) || DotChecker(eq_to_calc, *i))) {
//     number_gatherer_[pos] = eq_to_calc[*i];
//     *i = *i + 1;
//     pos++;
//   }
//   double number_ = atof(number_gatherer_);
//   std::pair<double, char> collection_ = std::make_pair(number_, 0);
//   reverse_polish_->push_back(collection_);
//   tech_->unary_allow_ = 1;
//   tech_->implicit_multiply_ = 1;
//   *i = *i - 1;
// }

// void s21::Stacker::XDeployer(char *x_value_, std::vector<std::pair<double, char>> *reverse_polish_) {
//   // if (eq_to_calc[i - 1]) // ЧТО ЭТО ТАКОЕ
//   double x_ = atof(x_value_);
//   std::pair<double, char> number = std::make_pair(x_, 0);
//   reverse_polish_->push_back(number);
// }

// void s21::Stacker::TrigoBracketOperator(char *eq_to_calc, int *i, struct technical_ *tech_, std::stack<std::pair<char, int>> *lexem_stack_) {
//   // == TRIGONOMETRY + SQRT (MAX PRIORITY) == //
//   // 's'= sin        'i'= asin     'd'= log10 //
//   // 'c'= cos        'o'= acos     'n'= log   //
//   // 't'= tan        'a'= atan     'e'= ceil  //
//   //                 'q'= sqrt                //
//   // ======================================== //
//   if (tech_->implicit_multiply_) {
//     std::pair<char, int> multiply_ = std::make_pair('*', 2);
//     lexem_stack_->push(multiply_);
//     tech_->implicit_multiply_ = 0;
//   }
//   char code_symbol_ = 0;
//   if (eq_to_calc[*i] != '(') {
//     if (*i + 3 < tech_->length_) {
//       if (!strncmp(eq_to_calc + *i, "sin(", 4)) code_symbol_ = 's';
//       if (!strncmp(eq_to_calc + *i, "cos(", 4)) code_symbol_ = 'c';
//       if (!strncmp(eq_to_calc + *i, "tan(", 4)) code_symbol_ = 't';
//       if (!strncmp(eq_to_calc + *i, "log(", 4)) code_symbol_ = 'n';
//       *i = *i + 3;
//     } else if (*i + 4 < tech_->length_) {
//       if (!strncmp(eq_to_calc + *i, "asin(", 5)) code_symbol_ = 'i';
//       if (!strncmp(eq_to_calc + *i, "acos(", 5)) code_symbol_ = 'o';
//       if (!strncmp(eq_to_calc + *i, "atan(", 5)) code_symbol_ = 'a';
//       if (!strncmp(eq_to_calc + *i, "sqrt(", 5)) code_symbol_ = 'q';
//       if (!strncmp(eq_to_calc + *i, "ceil(", 5)) code_symbol_ = 'e';
//       *i = *i + 4;
//     } else if (*i + 5 < tech_->length_) {
//       if (!strncmp(eq_to_calc + *i, "log10(", 6)) code_symbol_ = 'd';
//       *i = *i + 5;
//     } else {
//       throw std::range_error("WRONG TRIGONOMETRY");
//     }
//     std::pair<char, int> trigonometry_ = std::make_pair(code_symbol_, 0);
//     lexem_stack_->push(trigonometry_);
//   }
//   std::pair<char, int> bracket_ = std::make_pair('(', 0);
//   lexem_stack_->push(bracket_);
//   tech_->bracket_counter_++;
//   tech_->unary_allow_ = 0;
// }

// void s21::Stacker::CloseBracketOperator(char *eq_to_calc, int i, struct technical_ *tech_, std::vector<std::pair<double, char>> *reverse_polish_, std::stack<std::pair<char, int>> *lexem_stack_) {
//   tech_->bracket_counter_--;
//   if (eq_to_calc[i - 1] == '(') {
//     if ((eq_to_calc[i - 2] > 96) && (eq_to_calc[i - 2] != 'x')) {
//       throw std::invalid_argument("EMPTY TRIGONOMETRY BRACKETS");
//     } else {
//       throw std::invalid_argument("EMPTY BRACKETS");
//     }
//   }
//   while (std::get<char>(lexem_stack_->top()) != '(') {
//     if (lexem_stack_->size() == 0)
//       throw std::underflow_error("MISSING OPENING BRACKETS");
//     std::pair<double, char> operat_ =
//         std::make_pair(0.0, std::get<char>(lexem_stack_->top()));
//     reverse_polish_->push_back(operat_);
//     lexem_stack_->pop();
//   }
//   if (std::get<char>(lexem_stack_->top()) == '(')
//     lexem_stack_->pop();
//   if (lexem_stack_->size() != 0 &&
//       std::get<char>(lexem_stack_->top()) > 96) {
//     std::pair<double, char> trigonometry_ =
//         std::make_pair(0.0, std::get<char>(lexem_stack_->top()));
//     reverse_polish_->push_back(trigonometry_);
//     lexem_stack_->pop();
//   }
// }

// void s21::Stacker::OperatorCollector(char *eq_to_calc, int i, struct technical_ *tech_, std::vector<std::pair<double, char>> *reverse_polish_, std::stack<std::pair<char, int>> *lexem_stack_) {
//   if (tech_->unary_allow_ == 0 && eq_to_calc[i - 1] == '(') {
//     // UnaryOperator(equation_, i, tech_, reverse_polish_, lexem_stack_);
//     UnaryOperator(tech_, reverse_polish_);
//   } else {
//     std::pair<char, int> operator_new_ =
//         std::make_pair(eq_to_calc[i], PriorityEvaluation(eq_to_calc, i));
//     while (lexem_stack_->size() != 0 && (PriorityChecker(eq_to_calc, i, lexem_stack_))) {
//       std::pair<double, char> operator_transfer_ =
//           std::make_pair(0.0, std::get<char>(lexem_stack_->top()));
//       reverse_polish_->push_back(operator_transfer_);
//       lexem_stack_->pop();
//     }
//     lexem_stack_->push(operator_new_);
//   }
//   tech_->unary_allow_ = 1;
//   tech_->implicit_multiply_ = 0;
// }

// void s21::Stacker::LastOperatorChecker(struct technical_ *tech_, std::vector<std::pair<double, char>> *reverse_polish_, std::stack<std::pair<char, int>> *lexem_stack_) {
//   while (lexem_stack_->size() != 0) {
//     if (tech_->bracket_counter_ > 0)
//       throw std::invalid_argument("MISSING CLOSING BRACKETS");
//     std::pair<double, char> last_operator_ =
//         std::make_pair(0.0, std::get<char>(lexem_stack_->top()));
//     reverse_polish_->push_back(last_operator_);
//     lexem_stack_->pop();
//   }
// }

// /* ----- SUPPORT METHODS ----- */

// int s21::Stacker::DigitChecker(char *eq_to_calc, int i) {
//   return ((eq_to_calc[i] > 47 && eq_to_calc[i] < 58)) ? 1 : 0;
// }

// int s21::Stacker::DotChecker(char *eq_to_calc, int i) {
//   return (eq_to_calc[i] == '.') ? 1 : 0;
// }

// int s21::Stacker::PriorityChecker(char *eq_to_calc, int i, std::stack<std::pair<char, int>> *lexem_stack_) {
//   int swap_ = 0;
//   int priority_ = PriorityEvaluation(eq_to_calc, i);
//   // if (/*stack::lexem_stack_.size() > 0 && */ )
//   if (std::get<int>(lexem_stack_->top()) >= priority_ && priority_ != 3) {
//     swap_ = 1;
//   }
//   return swap_;
// }

// int s21::Stacker::PriorityEvaluation(char *eq_to_calc, int i) {
//   // ===== PRIORITY  (DESCENDING ORDER) ===== //
//   // '√'= sqrt       '^'= pow                 //
//   // '*'             '/'           '%'= mod   //
//   // '+'             '-'                      //
//   // ======================================== //
//   int priority_ = 0;
//   if (eq_to_calc[i] == '+' || eq_to_calc[i] == '-') {
//     priority_ = 1;
//   } else if (eq_to_calc[i] == '*' || eq_to_calc[i] == '/' ||
//              eq_to_calc[i] == '%') {
//     priority_ = 2;
//     // } else if (strncmp(eq_to_calc[i], "mod", 3)) {
//     //   priority_ = 2;
//     //   i = i + 2;
//   } else if (eq_to_calc[i] == '^') {
//     priority_ = 3;
//     // } else if (eq_to_calc[i] == "√") {
//     //   priority_ = 3;
//   }
//   return priority_;
// }
