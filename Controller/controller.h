/* Copyright 2024 valeryje
 *
 * This file contains Original Code created by valeryje
 * aka Alexander Alexanyan or Alex-A-Nyan.
 *
 * The Original Code and all software developed in the process of
 * participation on learning by experimental programming educational method.
 * The whole methodology was developed and distributed by
 * Autonomous non-profit organization «School 21» (ANO «School 21»).
 *
 * Redistribution and use of this file, its parts, or entire project
 * are permitted by confirmation of its original creator.
 */

/* ====================================================================================================
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

/* ----- LIBRARIES AND DEFINITIONS ----- */
#include <math.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACCURACY 1e-7  // preferred accuracy for the calculation
#define SYMBOLS_EQ \
  "^[%()\\*+-./0123456789^acdegilmnoqrstx]+=$"  // allowed symbols for
                                                // operations
#define SYMBOLS_X "^[+-.0123456789]+$"          // allowed symbols for x
#define ALLOWED_LENGTH 255  // preferred length limit for the equation

#define MAX_LENGTH ALLOWED_LENGTH + 2  // ALLOWED_LENGTH + '=' + '\0'
#define PARSED_LENGTH ALLOWED_LENGTH *ALLOWED_LENGTH

#define OK 0
#define ERROR 1  // wrong sequence

/* ----- STRUCTURES AND VARIABLES ----- */
typedef struct stack {
  char value;
  struct stack *ptr;
  int priority;
} stack;

struct flags {
  int *break_c;  // checks breaketers pairs
  int *unary_c;  // checks possible unary operparametrizedations
  int *oper_c;   // checks possible usual operators and functions
};

/* ====================================================================================================
 */

/* ----- PRIMARY FUNCTIONS ----- */
char *smartcalc(
    const char *orig_eq,
    const char *x);  // correctly calls the programm for inner function
void checker(const char orig_eq[MAX_LENGTH], char shrt_eq[PARSED_LENGTH],
             const char *x, char *err_case);  // breaks equation into entities
int processor(char shrt_eq[PARSED_LENGTH],
              char *err_case);  // calculates the equation

/* ----- CHECKER FUNCTIONS ----- */
int alienchar(const char orig_eq[MAX_LENGTH],
              char *SYMBOLS);  // checks the equation for the irrelevant symbols
void refiner(const char orig_eq[MAX_LENGTH], char shrt_eq[PARSED_LENGTH],
             int *x_value, char *answer);  // adds spaces between entities
int trigoshortener(const char orig_eq[MAX_LENGTH], char shrt_eq[PARSED_LENGTH],
                   int i, int j,
                   int *skip);  // сompresses trigonometry functions
int determ(const char *x,
           char *answer);  // defines the relevance of the x in the equation
void rewriter_x(char shrt_eq[PARSED_LENGTH],
                const char *x);  // rewrites equation using a proper value for x

/* ----- ALGORITHM FUNCTIONS ----- */
int unary(double *answer, char *token, int *pos,
          int *oper_c);  // checks a very first sign for unary operation
void numberer(char *token, double *answer, int *pos, char *err_case,
              int *unary_c, int *oper_c);  // processes numbers
stack *trigobreaketer(
    stack *operat, char *token, int *break_c, int *unary_c,
    int *oper_c);  // processes left parenthesis and trigonometry
stack *backbreaketer(stack *operat, double *answer, int *pos, char *err_case,
                     int *break_c, int *oper_c);  // processes right parenthesis
stack *lister(stack *operat, char *token, double *answer, int *pos,
              char *err_case, int *unary_c,
              int *oper_c);                   // processes operators
int prioritizer(stack *operat, char *token);  // precedences entities
int closerer(stack *operat, double *answer, int *pos,
             char *err_case);  // processes any left entities
int performer(double *answer, int *pos,
              char lexem);                 // performs one calculation
void cleaner(stack *operat, char *token);  // frees the memory

/* ----- STACK FUNCTIONS ----- */
stack *initialization(char token);        // creates "the head" of the list
stack *push(stack *operat, char *token);  // adds a node to the list
stack *pop(stack *operat);                // deletes a node of the list

/* ====================================================================================================
 */

// Copyright 2024 valeryje

/* ----- LIBRARIES AND CLASSES ----- */

#include "Model/model.h"
#include "View/view.h"
#include "controller.h"

namespace s21 {
// template <typename K, typename V>
class catcher {
 public:
  /* ----- CONSTANTS ----- */
  constexpr static double kAccuracy = 1e-7;
  /* ----- CONSTRUCTORS AND DESTRUCTORS ----- */
  // default constructor
  S21Matrix();
  // parameterized constructor
  explicit S21Matrix(int rows, int cols);
  // copy constructor
  S21Matrix(const S21Matrix &other);
  // copy constructor overload
  S21Matrix &operator=(const S21Matrix &other);
  // move constructor
  S21Matrix(S21Matrix &&other) noexcept;
  // move constructor overload
  S21Matrix &operator=(S21Matrix &&other) noexcept;
  // destructor
  virtual ~S21Matrix();

  /* ----- ACCESSORS AND MUTATORS ----- */
  // accessor for rows attribute
  int get_rows() noexcept;
  // accessor for columns attribute
  int get_cols() noexcept;
  // mutator for rows attribute and matrix change
  void set_rows(int num);
  // mutator for columns attribute and matrix change
  void set_cols(int num);

  /* ----- TASK METHODS ----- */

  /* ----- SUPPORTING METHODS ----- */
  // calculation of the minor of the matrix component
  S21Matrix MinorAssembler(int r_skip, int c_skip) const;

  /* ----- OPERATOR OVERLOADS ----- */
  // "M + M" - addition of two matrices
  S21Matrix operator+(const S21Matrix &other);

 private:
  /* ----- SUPPORTING METHODS ----- */

  /* ----- VARIABLES ----- */
};

/* ----- FUNCTIONS ----- */

class validator {
 public:
 private:
};

class shortener {
 public:
 private:
};

class answer {
 public:
 private:
};

class stack {
 public:
 private:
};

};  // namespace s21

#endif  // SRC_CONTROLLER_H_
