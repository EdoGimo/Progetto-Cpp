/**
 * @copyright MyProject
 * license MIT
 * @author Edoardo Righi
 * @version v1.0
 * @date August, 2018
 * @file Matrix.hpp
 */

#pragma once

///@brief "namespace incentrato sulla gestione delle matrici in memoria"
namespace matr {

/// @brief "classe di una matrice generica (no dimensioni)""
template <typename T> class Matrix {

public:
  ///@brief "costruttore della matrice"
  ///@param width "larghezza della matrice"
  ///@param height "altezza della matrice"
  explicit Matrix(unsigned width, unsigned height);

  ///@brief "distruttore (vuoto)"
  virtual ~Matrix();

  ///@brief "ritorna il doppio puntatore alla matrice di un oggetto"
  T getMatrix();

  ///@brief "ritorna il doppio puntatore costante alla matrice di un oggetto"
  T getConstMatrix() const;

protected:
  ///@brief "doppio puntatore alla matrice"
  T _matrice;

private:
  ///@brief "per non permettere l'uso di copy constructors"
  Matrix(const Matrix &);
};

///@brief "classe di una matrice quadrata"
class SquaredMatrix : public Matrix<int **> {

public:
  ///@brief "costruttore matrice quadrata"
  ///@param[in] dim "dimensione della matrice"
  explicit SquaredMatrix(unsigned dim);

  ///@brief "distruttore della matrice quadrata"
  ~SquaredMatrix();

  ///@brief "funzione che ritorna la dimensione"
  unsigned getDim() const;

  ///@brief "ritorna il numero degli elementi nella matrice quadrata"
  ///@param l "lunghezza del lato (dimensione)"
  static unsigned getNumElem(unsigned l);

private:
  ///@brief "dimensione della matrice"
  unsigned _dim;
};

///@brief "classe di una matrice non quadrata"
class NotSquaredMatrix : public Matrix<int **> {

public:
  ///@brief "costruttore della matrice non quadrata"
  ///@param[in] height "altezza della matrice"
  ///@param[in] width "lunghezza della matrice"
  explicit NotSquaredMatrix(unsigned width, unsigned height);

  ///@brief "distruttore della matrice non quadrata"
  ~NotSquaredMatrix();

  ///@brief "funzione che ritorna l'altezza"
  unsigned getHeight() const;

  ///@brief "funzione che ritorna la larghezza"
  unsigned getWidth() const;

  ///@brief "ritorna il numero degli elementi nella matrice non quadrata"
  ///@param w "larghezza della matrice"
  ///@param h "altezza della matrice"
  static unsigned getNumElem(unsigned w, unsigned h);

private:
  ///@brief "altezza della matrice"
  unsigned _height;
  ///@brief "larghezza della matrice"
  unsigned _width;
};

} // namespace matr