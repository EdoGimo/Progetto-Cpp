/**
 * @copyright MyProject
 * license MIT
 * @author Edoardo Righi
 * @version v1.0
 * @date August, 2018
 * @file Calcs.cpp
 */

#include "Calcs.hpp"

void calc::sqCalc(unsigned dim, const std::string &matC, std::fstream &input1,
                  std::fstream &input2) {

  // creo le matrici nella classe, inizializzandole a 0
  matr::SquaredMatrix SM1(dim);
  matr::SquaredMatrix SM2(dim);

  // leggo i valori su file e aggiorno il valore nelle classi
  util::readSqMatrix(input1, &SM1);
  util::readSqMatrix(input2, &SM2);

  // creo l'oggetto matrice risultato
  matr::SquaredMatrix SMR(dim);

  // calcolo la matrice risultato
  matr::MatrixMult(&SM1, &SM2, &SMR);

  // salvataggio matrice su file
  util::saveOutput(matC, &SMR);
}

void calc::nsqCalc(unsigned widthA, unsigned heightA, const std::string &matC,
                   std::fstream &input1, std::fstream &input2) {

  unsigned widthB = heightA;
  unsigned heightB = widthA;

  // creo le matrici nella classe, inizializzandole a 0
  matr::NotSquaredMatrix NSM1(widthA, heightA);

  matr::NotSquaredMatrix NSM2(widthB, heightB);

  // leggo i valori su file e aggiorno il valore nelle classi
  util::readMatrix(input1, &NSM1);
  util::readMatrix(input2, &NSM2);

  // creo l'oggetto matrice risultato
  matr::SquaredMatrix SMR(heightA);

  // calcolo la matrice risultato
  matr::MatrixMult(&NSM1, &NSM2, &SMR);

  // salvataggio matrice su file
  util::saveOutput(matC, &SMR);
}

// MATRIXMULT

template <>
void matr::MatrixMult<matr::SquaredMatrix>(const matr::SquaredMatrix *sm1,
                                           const matr::SquaredMatrix *sm2,
                                           matr::SquaredMatrix *res) {

  const unsigned dim = (*sm1).getDim();

  for (unsigned i = 0; i < dim; i++) {

    for (unsigned j = 0; j < dim; j++) {

      for (unsigned k = 0; k < dim; k++) {

        (*res).getMatrix()[i][j] +=
            (*sm1).getConstMatrix()[i][k] * (*sm2).getConstMatrix()[k][j];
      }
    }
  }
}

template <>
void matr::MatrixMult<matr::NotSquaredMatrix>(
    const matr::NotSquaredMatrix *nsm1, const matr::NotSquaredMatrix *nsm2,
    matr::SquaredMatrix *res) {

  const unsigned height = (*nsm1).getHeight();
  const unsigned width = (*nsm1).getWidth();

  for (unsigned i = 0; i < height; i++) {

    for (unsigned j = 0; j < height; j++) {

      for (unsigned k = 0; k < width; k++) {
        (*res).getMatrix()[i][j] +=
            (*nsm1).getConstMatrix()[i][k] * (*nsm2).getConstMatrix()[k][j];
      }
    }
  }
}