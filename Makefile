# Copyright 2024 valeryje
#
# This file contains Original Code created by Alexander Alexanyan aka valeryje.
#
# The Original Code and all software developed in the process of participation
# on learning by experimental programming educational method. The whole
# methodology was developed and distributed by autonomous non-profit
# organization «School 21» (ANO «School 21»).
#
# Redistribution and use of this file, its parts, or entire project are
# permitted by confirmation of its original creator.

# ==============================================================================

# # ----- VARIABLES AND PARAMETERS ----- #
# CC					=	gcc
# CXX					= clang++
# CFLAGS			=	-Wall -Werror -Wextra -c -g
# CXXFLAGS		=	-Wall -Werror -Wextra -c -g -std=c++17

# CXXTEST			=	-lgtest 
# GCOVFLAGS		= --coverage -fprofile-instr-generate -fcoverage-mapping
# HTMLFLAGS		= --html --html-details --html-details-syntax-highlighting

# FUNCTIONS		=	Model/model\
#          			Model/validator\
#          			Model/stacker\
#          			Model/calculator

# # ----- TASK GOALS ----- #
# all: clean install

# clean:
# 	@clear
# 	@echo "================================================================================"
# 	@sleep 0.2
# 	@echo "Turning Cleaning Manager on.."
# 	@-rm -rf report *.a *.out */*.gc* *.o Model/*.o
# 	@sleep 0.6
# 	@echo "Cleaning is complete"
# 	@sleep 0.2
# 	@echo "================================================================================"

# build: clean objects
# 	@ar rc main.a Model/*.o
# 	@rm Model/*.o

# tests: build
# 	@echo "================================================================================"
# 	@echo "Starting testing program.."
# 	@$(CXX) $(CXXFLAGS) test.cc -o test.o
# 	@$(CXX) test.o main.a $(CXXTEST) -o gtest.out
# 	@-./gtest.out
# 	@echo "================================================================================"
	
# # @clang++ test.o -L. -lmylib -lgtest -lgtest_main -pthread -o gtest.out
# # @ranlib main.a
# # @$(CXX) $(CXXFLAGS) test.cc $(CXXTEST) -o gtest.out
# # update:
# # 	eval "$(/opt/goinfre/valeryje/homebrew/bin/brew shellenv)"
# #   chmod -R go-w "$(brew --prefix)/share/zsh"
# #   export CPATH=/opt/goinfre/valeryje/homebrew/include:$CPATH
# #   export LIBRARY_PATH=/opt/goinfre/valeryje/homebrew/lib:$LIBRARY_PATH
# #   export PATH=/opt/goinfre/valeryje/homebrew/opt/llvm/bin:$PATH

# install: uninstall
# 	@-mkdir ~/SmartCalcV2.0_by_valeryje
# 	@-cp QT/Instruction.html ~/SmartCalcV2.0_by_valeryje/Instruction.html
# 	@-cp QT/TheFlash.png ~/SmartCalcV2.0_by_valeryje/TheFlash.png
# 	@-cp QT/Reverse.jpeg ~/SmartCalcV2.0_by_valeryje/Reverse.jpeg
# 	@-cd QT && cmake -S . -B ~/SmartCalcV2.0_by_valeryje
# 	@-cd QT && cmake --build ~/SmartCalcV2.0_by_valeryje

# uninstall:
# 	@-rm -rf ~/SmartCalcV2.0_by_valeryje
	
# #dvi: install
# #	@-open ~/SmartCalcV2.0_by_valeryje/Instruction.html

# dist: install
# 	@-tar -czf s21_smart_calc.tar ~/SmartCalcV2.0_by_valeryje

# # ----- REVIEW GOALS ----- #
# style:
# 	@echo "================================================================================"
# 	@sleep 0.2
# 	@echo "Copying .clang-format.."
# 	@-cp ../materials/linters/.clang-format .
# 	@sleep 0.5
# 	@echo "Applying Google Style.."
# 	@-clang-format -i -style=file *.* Model/*
# 	@sleep 0.3
# 	@echo
# 	@echo "Behold your pretty code, hooman"
# 	@-clang-format -n -style=file *.* Model/*
# 	@-rm .clang-format
# 	@echo "================================================================================"

# cppcheck:
# 	@echo "================================================================================"
# 	@sleep 0.2
# 	@echo "CPPCHECK'ing your code.."
# 	@echo "================================================================================"
# 	@sleep 1
# 	@-cppcheck --enable=all --suppress=missingIncludeSystem Model/*.cc
# 	@echo "================================================================================"

# gcov_report: clean
# 	@sleep 0.2
# 	@echo "It's time to see the coverage.."
# 	@for function in $(FUNCTIONS); do $(CXX) $(CXXFLAGS) $(GCOVFLAGS) $$function.cc -o $$function.o; done;
# 	@ar rc main.a Model/*.o
# 	@$(CXX) $(CXXFLAGS) test.cc -o test.o
# 	@echo "================================================================================"
# 	@$(CXX) $(CXXFLAGS) test.o main.a $(CXXTEST) $(GCOVFLAGS) -o gtest.out
# 	@echo "================================================================================"
# 	@-./gtest.out
# 	@-mkdir -p report
# 	@-gcovr . $(HTMLFLAGS) -o report/report.html
# 	@-rm -rf *.o *.gc*
# 	@sleep 1
# 	@echo
# 	@echo "Opening coverage report.."
# 	@-open report/report.html
# 	@echo "================================================================================"

# leaks:
# 	@echo "Checking your leaks with LEAKS utility.."
# 	@sleep 1
# 	@-leaks -atExit -- ./gtest.out
# 	@echo "================================================================================"

# # ----- SUPPORT GOALS ----- #

# objects:
# 	@for function in $(FUNCTIONS); do $(CXX) $(CXXFLAGS) $$function.cc -o $$function.o; done;

# review: style cppcheck gcov_report leaks



CXX             = clang++
CXXFLAGS        = -Wall -Werror -Wextra -g -std=c++17 --coverage
LDFLAGS         = --coverage -lgtest -pthread

# Утилиты для покрытия
GCOVFLAGS       = --gcov-tool=llvm-cov # Использование llvm-cov вместо gcov
HTMLFLAGS       = --html --html-details --html-details-syntax-highlighting

# Исходные файлы
SOURCES         = Model/model.cc Model/validator.cc Model/stacker.cc Model/calculator.cc
OBJECTS         = $(SOURCES:.cc=.o)

# Тесты
TEST_SOURCES    = test.cc
TEST_OBJECTS    = $(TEST_SOURCES:.cc=.o)
TARGET          = gtest.out

# Цель по умолчанию
all: $(TARGET)

# Сборка тестов
$(TARGET): $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(TEST_OBJECTS) $(LDFLAGS) -o $(TARGET)

# Компиляция исходных файлов
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Цель для запуска тестов и генерации отчета покрытия
coverage: $(TARGET)
	@echo "Running tests and generating coverage report..."
	./$(TARGET)
	mkdir -p report
	gcovr $(GCOVFLAGS) . $(HTMLFLAGS) -o report/coverage.html
	@echo "Coverage report generated: report/coverage.html"

# Очистка сгенерированных файлов
clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(TARGET)
	rm -rf *.gc* report/

# Полная очистка проекта, включая архивы и отчеты
distclean: clean
	rm -rf report/