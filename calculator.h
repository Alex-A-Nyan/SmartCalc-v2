/* Copyright 2023 valeryje
 *
 * This file contains Original Code created by Alexander Alexanyan aka valeryje.
 *
 * The Original Code and all software developed in the process of participation
 * on learning by experimental programming educational method. The whole
 * methodology was developed and distributed by autonomous non-profit
 * organization «School 21» (ANO «School 21»).
 *
 * Redistribution and use of this file, its parts, or entire project are
 * permitted by confirmation of its original creator.
 *
 */

/* ========================================================================== */

#ifndef SRC_CALCULATOR_H_
#define SRC_CALCULATOR_H_

#ifdef __cplusplus
extern "C" {
#endif

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
#define SYMBOLS_X "^[+-.0123456789e]+$"         // allowed symbols for x
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
  int *unary_c;  // checks possible unary operations
  int *oper_c;   // checks possible usual operators and functions
};

/* ========================================================================== */

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
int exponential(const char orig_eq[MAX_LENGTH], char shrt_eq[PARSED_LENGTH],
                int *i, int *j);  // keeps exponential number together
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

#ifdef __cplusplus
}
#endif

#endif  // SRC_CALCULATOR_H_
