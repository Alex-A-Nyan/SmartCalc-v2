// Copyright 2024 valeryje

#include "controller.h"

int main() {
  s21::View view_;
  char *eq_to_calc_ = view_.get_eq();
  char *x_to_calc_ = view_.get_x();
  s21::Model model_;
  model_.set_eq_x(eq_to_calc_, x_to_calc_);
  double eq_result = model_.ModelProcedure(model_);
  view_.set_eq(eq_result);
  return 0;
}

// try {
// } catch (...) {
// printf("blah-blah");
// }
// } catch (std::length_error("EXCEEDED MAX LENGTH")) {
//   char *eq_result = catch (...) {
//   }
