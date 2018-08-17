/**
 * @copyright MyProject
 * license MIT
 * @author Edoardo Righi
 * @version v1.0
 * @date August, 2018
 * @file test1.cpp
 */

#define CATCH_CONFIG_MAIN

#include "../include/Calcs.hpp"
#include "../include/Matrix.hpp"
#include "../include/Utils.hpp"
#include "../src/Calcs.cpp"
#include "../src/Matrix.cpp"
#include "../src/Utils.cpp"

#include "../lib/catch.hpp"

TEST_CASE("Numeri in una riga", "[numsInRow]") {
  SECTION("5 numeri") {
    std::string test = "1 2 3 4 5";
    REQUIRE(util::numsInRow(test) == 5);
  }

  SECTION("Nessun numero") {
    std::string test = "questo è un test";
    REQUIRE(util::numsInRow(test) == 0);
  }
}

TEST_CASE("Solo numeri in una stringa", "[NotOnlyNum]") {
  SECTION("Non solo numeri") {
    std::string test = "1 2 ciao 3 4 5";
    REQUIRE(util::NotOnlyNum(test) == true);
  }

  SECTION("Solo numeri") {
    std::string test = "1 2 3 4 5 22222";
    REQUIRE(util::NotOnlyNum(test) == false);
  }
}

TEST_CASE("Numero colonne differente", "[differentCols]") {
  REQUIRE(util::differentCols(0, 0, 0) == false);
  REQUIRE(util::differentCols(0, 1, 1) == false);
  REQUIRE(util::differentCols(0, 2, 1) == false);
  REQUIRE(util::differentCols(1, 1, 1) == false);
  REQUIRE(util::differentCols(1, 1, 2) == true);
}

TEST_CASE("Da matrice a stringa", "[matrixToString") {

  SECTION("Matrice quadrata") {
    int **matrix;
    matrix = new int *[2];

    for (unsigned i = 0; i < 2; i++) {

      matrix[i] = new int[2];

      for (unsigned j = 0; j < 2; j++) {

        // inizializzazione
        matrix[i][j] = 1;
      }
    }

    std::string result = "1 1\n1 1\n";

    REQUIRE(result.compare(util::matrixToString(&matrix, 2)));

    for (unsigned i = 0; i < 2; i++) {
      delete[] matrix[i];
    }
    delete[] matrix;
  }

  SECTION("Matrice non quadrata") {
    int **matrix;
    matrix = new int *[2];

    for (unsigned i = 0; i < 2; i++) {

      matrix[i] = new int[3];

      for (unsigned j = 0; j < 3; j++) {

        // inizializzazione
        matrix[i][j] = 1;
      }
    }

    std::string result = "1 1 1\n1 1 1\n";

    REQUIRE(result.compare(util::matrixToString(&matrix, 2)));

    for (unsigned i = 0; i < 2; i++) {
      delete[] matrix[i];
    }
    delete[] matrix;
  }
}