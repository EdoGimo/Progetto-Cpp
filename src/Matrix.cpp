/**
 * @copyright MyProject
 * license MIT
 * @author Edoardo Righi
 * @version v1.0
 * @date August, 2018
 * @file Matrix.cpp
 */

#include "Matrix.hpp"

template <typename T> T matr::Matrix<T>::getMatrix() { return _matrice; }

template <typename T> T matr::Matrix<T>::getConstMatrix() const {
  return _matrice;
}

template int **matr::Matrix<int **>::getMatrix();

template int **matr::Matrix<int **>::getConstMatrix() const;

template <> matr::Matrix<int **>::Matrix(unsigned width, unsigned height) {
  (_matrice) = new int *[height];

  for (unsigned i = 0; i < height; i++) {
    (_matrice)[i] = new int[width];

    for (unsigned j = 0; j < width; j++) {
      // inizializzazione
      (_matrice)[i][j] = 0;
    }
  }
}

template <> matr::Matrix<int **>::~Matrix() {}

// SQUARED
matr::SquaredMatrix::SquaredMatrix(unsigned dim)
    : Matrix<int **>::Matrix(dim, dim) {

  _dim = dim;
}

matr::SquaredMatrix::~SquaredMatrix() {
  for (unsigned i = 0; i < _dim; i++) {
    delete[] _matrice[i];
  }
  delete[] _matrice;
}

unsigned matr::SquaredMatrix::getDim() const { return _dim; }

unsigned matr::SquaredMatrix::getNumElem(unsigned l) { return l * l; }

// NOT SQUARED
matr::NotSquaredMatrix::NotSquaredMatrix(unsigned width, unsigned height)
    : Matrix<int **>::Matrix(width, height) {

  _width = width;
  _height = height;
}

matr::NotSquaredMatrix::~NotSquaredMatrix() {
  for (unsigned i = 0; i < _height; i++) {
    delete[] _matrice[i];
  }
  delete[] _matrice;
}

unsigned matr::NotSquaredMatrix::getWidth() const { return _width; }

unsigned matr::NotSquaredMatrix::getHeight() const { return _height; }

unsigned matr::NotSquaredMatrix::getNumElem(unsigned h, unsigned w) {
  return h * w;
}
