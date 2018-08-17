/**
 * @copyright MyProject
 * license MIT
 * @author Edoardo Righi
 * @version v1.0
 * @date August, 2018
 * @file Calcs.hpp
 */

#pragma once

#include "Matrix.hpp"
#include "Utils.hpp"

///@brief "namespace dedicato alle operazioni da eseguire"
namespace calc {

///@brief "insieme operazioni per produrre la matrice risultato e salvarla su
/// file esterno"
///@param dim "dimensione della matrice quadrata"
///@param matC "nome file esterno in cui salvare la matrice risultato"
///@param input1 "file contenente la prima matrice"
///@param input2 "file contenente la seconda matrice"
void sqCalc(unsigned dim, const std::string &matC, std::fstream &input1,
            std::fstream &input2);

///@brief "insieme operazioni per produrre la matrice risultato e salvarla su
/// file esterno"
///@param width "larghezza della matrice"
///@param height "altezza della matrice"
///@param matC "nome file esterno in cui salvare la matrice risultato"
///@param input1 "file contenente la prima matrice"
///@param input2 "file contenente la seconda matrice"
void nsqCalc(unsigned width, unsigned height, const std::string &matC,
             std::fstream &input1, std::fstream &input2);

} // namespace calc

///@brief "namespace incentrato sulla gestione delle matrici in memoria"
namespace matr {

///@brief "prodotto di due matrici"
///@tparam T "tipo delle matrici (quadrata o non)"
///@param[in] sm1 "prima matrice"
///@param[in] sm2 "seconda matrice"
///@param[out] res "matrice risultato"
template <typename T>
void MatrixMult(const T *sm1, const T *sm2, matr::SquaredMatrix *res);

///@brief "prodotto di due matrici quadrate"
template <>
void MatrixMult<matr::SquaredMatrix>(const matr::SquaredMatrix *sm1,
                                     const matr::SquaredMatrix *sm2,
                                     matr::SquaredMatrix *res);

///@brief "prodotto di due matrici non quadrate"
template <>
void MatrixMult<matr::NotSquaredMatrix>(const matr::NotSquaredMatrix *nsm1,
                                        const matr::NotSquaredMatrix *nsm2,
                                        matr::SquaredMatrix *res);

} // namespace  matr
