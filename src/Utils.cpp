/**
 * @copyright MyProject
 * license MIT
 * @author Edoardo Righi
 * @version v1.0
 * @date August, 2018
 * @file Utils.cpp
 */

#include "Utils.hpp"

bool util::calcDim(std::fstream &input, unsigned *width, unsigned *height) {
  std::string h_w;

  // check
  if (input.is_open()) {
    while (input.good()) {
      h_w = util::checkMat(input);
    }
  }

  if (h_w == "ERROR") {
    return false;
  }

  // ottengo h e w
  unsigned a[2];
  std::stringstream str(h_w);
  int n = 0;
  int i = 0;

  // ottengo valori dalla stringa (separati da spazio) e metto in array
  while (str >> n) {
    a[i] = n;
    i++;
  }

  // salvo da array
  *width = a[0];
  *height = a[1];

  return true;
}

unsigned util::numsInRow(std::string &str) {
  unsigned counter = 0;

  // per ogni carattere nella stringa
  for (unsigned i = 0; i < str.size(); i++) {

    // se il carattere è un numero e
    // o la posizione i è 0 o il carattere precedente è uno spazio o un '-'
    if (isdigit(str[i]) &&
        (i == 0 || isspace(str[i - 1]) || str[i - 1] == '-')) {
      // incrementa il contatore
      counter++;
    }
  }
  return counter;
}

bool util::NotOnlyNum(std::string &str) {
  bool nn = false;

  // per ogni carattere nella stringa
  for (unsigned i = 0; i < str.size(); i++) {

    // se il carattere non è un numero nè uno spazio nè '-'
    if ((!isdigit(str[i])) && (!isspace(str[i])) && (str[i] != '-')) {
      // presenti caratteri non utilizzabili
      nn = true;
    }
  }

  return nn;
}

const std::string util::checkMat(std::fstream &file) {
  std::string line;

  unsigned cols = 0;
  unsigned rows = 0;
  bool error = false;

  while (std::getline(file, line)) {

    unsigned num = util::numsInRow(line);

    // Se la matrice contiene lettere
    if (util::NotOnlyNum(line)) {
      // ERRORE! Non è una matrice
      error = true;
    }

    // Se il numero di righe contate è > 0 e
    // il numero di colonne nella riga corrente è diverso dalla precedente
    if (util::differentCols(rows, cols, num)) {
      // ERRORE! Non è una matrice
      error = true;
    }
    cols = num;
    rows++;
  }

  if (error == true) {
    return "ERROR";
  }

  return std::to_string(cols) + " " + std::to_string(rows);
}

void util::readSqMatrix(std::fstream &file, matr::SquaredMatrix *matrix) {

  std::string line;
  unsigned h = 0;

  while (getline(file, line)) {

    unsigned w = 0;
    std::stringstream stream(line);
    int temp;

    while (stream >> temp) {

      (*matrix).getMatrix()[h][w] = temp;

      w++;
    }
    h++;
  }
}

void util::readMatrix(std::fstream &file, matr::NotSquaredMatrix *matrix) {

  std::string line;
  unsigned h = 0;

  while (getline(file, line)) {

    unsigned w = 0;
    std::stringstream stream(line);
    int temp;

    while (stream >> temp) {

      (*matrix).getMatrix()[h][w] = temp;

      w++;
    }
    h++;
  }
}

const std::string util::matrixToString(int ***matrix, unsigned dim) {

  std::stringstream ss;

  for (unsigned i = 0; i < dim; i++) {
    for (unsigned j = 0; j < dim; j++) {
      ss << (*matrix)[i][j] << " ";
    }
    ss << "\n";
  }

  return ss.str();
}

// SAVEOUTPUT

void util::saveOutput(const std::string &matC, const matr::SquaredMatrix *MAT) {
  // salvo matrice risultato su file esterno
  std::fstream output(matC, std::fstream::out | std::fstream::trunc);
  if (!output.good()) {
    std::cout << "Il file '" << matC << "' non esiste, verrà creato."
              << std::endl;
  }

  unsigned dim = (*MAT).getDim();
  int **mat = (*MAT).getConstMatrix();

  output << util::matrixToString(&mat, dim);

  // chiudo il file
  output.close();

  std::cout << "Il risultato del prodotto è stato salvato nel file '" << matC
            << "'" << std::endl;
}
