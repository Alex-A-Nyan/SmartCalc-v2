// Copyright 2024 valeryje

#include "model.h"

/* ----- CONSTRUCTORS AND DESTRUCTORS ----- */
s21::Model::Model(char *eq_from_view_, char *x_from_view_)
    // : equation_(eq_from_view_), x_value_(x_from_view_), respond_(NULL) {
    : equation_(eq_from_view_), x_value_(x_from_view_), accuracy_((char *)"7"), respond_(NULL) {
      // char str[50] = {0};
      // std::snprintf(str, sizeof(str), "%d", kStandartAccuracy);
      // this->accuracy_ = str;
    }
s21::Model::Model(char *result_) : respond_(result_) {}

/* ----- ACCESSORS AND MUTATORS ----- */
char *s21::Model::get_eq() noexcept { return equation_; }
char *s21::Model::get_x() noexcept { return x_value_; }
char *s21::Model::get_accuracy() noexcept { return accuracy_; }
char *s21::Model::get_respond() noexcept { return respond_; }

void s21::Model::set_eq_x(char *eq_from_view_, char *x_from_view_) {
  Model calc_model_(eq_from_view_, x_from_view_);
  *this = std::move(calc_model_);
}
// void s21::Model::set_accuracy(int accur_) {             // CДЕЛАТЬ

// }
// void s21::Model::set_respond(double answer_) {          // CДЕЛАТЬ
//   // Model calc_model_(respond_);
//   // if (isinf(answer_)) {
//   //   this->respond_ = (char *)"INFINITY";
//   // } else if (isnan(answer_)) {
//   //   this->respond_ = (char *)"NAN";
//   // } else if ((int)answer_ == answer_) {
//     // sprintf(this->respond_, "%d", (int)answer_);
//   // } else {
//     // sprintf(this->respond_, "%.7f", answer_);
//   // }
//   // *this = std::move(calc_model_);
// }

/* ----- METHODS ----- */

// double s21::Model::ModelProcedure(Model model_) {
//   char *eq_to_calc_ = model_.get_eq();
//   char *x_to_calc_ = model_.get_x();
//   double answer_ = 0.0;
//   // try {
//   s21::Validator valid_(eq_to_calc_, x_to_calc_);
//   if (valid_.Validate()) {
//     s21::Stacker stacker_(eq_to_calc_, x_to_calc_);
//     std::vector<std::pair<double, char>> reverse_polish_ = {};
//     // stacker_.Rebuild(eq_to_calc_, x_to_calc_, reverse_polish_);
//     stacker_.Rebuild(&reverse_polish_);
//     s21::Calculator calculator_;
//     answer_ = calculator_.Count(&reverse_polish_);
//   }
//   // } catch (...) {
//   // }
//   return answer_;
// }

double s21::Model::ModelProcedure(Model model_) {                        // WORKING CASE
  char *eq_to_calc_ = model_.get_eq();
  char *x_to_calc_ = model_.get_x();
  double answer_ = 0.0;
  try {
    s21::Validator valid_(eq_to_calc_, x_to_calc_);
    if (valid_.Validate()) {
      s21::Stacker stacker_(eq_to_calc_, x_to_calc_);
      std::vector<std::pair<double, char>> reverse_polish_ = {};
      // stacker_.Rebuild(eq_to_calc_, x_to_calc_, reverse_polish_);
      stacker_.Rebuild(&reverse_polish_);
      s21::Calculator calculator_;
      answer_ = calculator_.Count(&reverse_polish_);
      Accurator(&answer_);
    }
  } catch (...) {
  // } catch (const std::exception& exception) {
  //   this->respond_ = (char *)(exception.what());
  //   printf("\nthis->respond_ = %s\n", this->respond_);
    throw;
  }
  return answer_;
}

void s21::Model::Accurator(double *answer_) {
  // int length_to_check_ = strlen(this->accuracy_);
    // char *str = this->get_accuracy();
  // printf("\nstr = %s\n", str);
  // for (int i = 0; i < length_to_check_; i++)
    // if (!DigitChecker(this->accuracy_, i)) throw std::invalid_argument("UNREADABLE ACCURACY");
  // int accur_ = atoi(this->accuracy_);
  int accur_ = 7;
  if (accur_ > kMaxAccuracy) accur_ = kMaxAccuracy;
  int mult_ = std::pow(10.0, accur_);
  double precise_ = std::round(*answer_ * mult_) / mult_;
  if ((int)precise_ == precise_) {
    *answer_ = (int)precise_;
  } else {
    *answer_ = precise_;
    // printf("\nprecise_ = %.15f, answer_ = %.15f\n", precise_, *answer_);
  }
}

// char *s21::Model::ModelProcedure(Model model_) {
//   char *eq_to_calc_ = model_.get_eq();
//   char *x_to_calc_ = model_.get_x();
//   double answer_ = 0.0;
//   // char *respond_ = {0};
//   try {
//     printf("\n     1     Before calc respond = %s, answer = %f\n",this->get_respond(), answer_);
//     s21::Validator valid_(eq_to_calc_, x_to_calc_);
//     if (valid_.Validate()) {
//       s21::Stacker stacker_(eq_to_calc_, x_to_calc_);
//       std::vector<std::pair<double, char>> reverse_polish_ = {};
//       // stacker_.Rebuild(eq_to_calc_, x_to_calc_, reverse_polish_);
//       stacker_.Rebuild(&reverse_polish_);
//       s21::Calculator calculator_;
//       answer_ = calculator_.Count(&reverse_polish_);
//       set_respond(answer_);
//       printf("\n   2     Before calc respond = %s, answer = %f\n",this->get_respond(), answer_);
//     }
//   } catch (const std::exception& exception) {
//     this->respond_ = (char *)(exception.what());
//     // std::strcpy(this->respond_, exception.what());
//     // printf("\n   3    EXCEPT this->respond_ = %s\n\n", this->get_respond());
//     // *this->respond_ = exception.what();
//   }
//   return this->respond_;
// }

// void s21::Model::Transfer(double answer_) {
//   // char *result_ = new char[50];
//   if (isinf(answer_)) {
//     this->respond_ ="INFINITY";
//   } else if (isnan(answer_)) {
//     this->respond_ = "NAN";
//   } else if ((int)answer_ == answer_) {
//     sprintf(this->respond_, "%d", (int)answer_);
//   } else {
//     sprintf(this->respond_, "%.7f", answer_);
//   }
//   // delete[] result_;
// }

int s21::Model::DigitChecker(char *eq_to_calc, int i) {
  return ((eq_to_calc[i] > 47 && eq_to_calc[i] < 58)) ? 1 : 0;
}
