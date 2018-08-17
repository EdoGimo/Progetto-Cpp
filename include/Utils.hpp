/**
 * @copyright MyProject
 * license MIT
 * @author Edoardo Righi
 * @version v1.0
 * @date August, 2018
 * @file Utils.hpp
 */

#pragma once

#include "Matrix.hpp"
#include <fstream>  //std::fstream e std::istream::in
#include <iostream> //std::cout e std::endl
#include <sstream>  //std::stringstream
#include <string>   //std::string

///@brief "namespace contenente funzioni legate alla gestione dei file in input"
namespace util {

///@brief "ottiene la dimensione della matrice nel file esterno (se esiste)"
///@param[in] input "il file di input da controllare"
///@param[out] width "puntatore alla variabile nel main contenente la larghezza
/// desiderata"
///@param[out] height "puntatore alla variabile nel main contenente
/// l'altezza desiderata"
bool calcDim(std::fstream &input, unsigned *width, unsigned *height);

///@brief "numeri in una riga"
///@param[in] str "stringa contente una riga di un file esterno"
unsigned numsInRow(std::string &str);

///@brief "controlla se la linea contiene caratteri diversi da numeri, spazi e
/// '-'"
///@param[in] str "stringa contente una riga di un file esterno"
///@return 'true' se contiene caratteri diversi, 'false' altrimenti
bool NotOnlyNum(std::string &str);

///@brief "controlla la correttezza del numero di colonne per riga
/// e ritorna il numero di righe e di colonne come stringa"
///@param[in] file "il file esterno da controllare"
const std::string checkMat(std::fstream &file);

///@brief "constexpr che controlla se a partire dalla seconda riga letta il
/// numero delle colonne differisce dalla riga precedente"
///@param[in] row "numero della riga"
///@param[in] col "numero di colonne nella riga precedente"
///@param[in] num "numero di colonne nella riga corrente"
constexpr bool differentCols(unsigned row, unsigned col, unsigned num);

#include "Utils.i.hpp"

///@brief "crea una matrice quadrata in memoria dal file
/// e ritorna un doppio puntatore ad essa"
///@param[in] file "il file esterno da leggere"
///@param[out] matrix "puntatore alla matrice da popolare"
void readSqMatrix(std::fstream &file, matr::SquaredMatrix *matrix);

///@brief "crea una matrice in memoria dal file
/// e ritorna un doppio puntatore ad essa"
///@param[in] file "il file esterno da leggere"
///@param[out] matrix "puntatore alla matrice da popolare"
void readMatrix(std::fstream &file, matr::NotSquaredMatrix *matrix);

///@brief "salva il contenuto di un puntatore doppio a matrice quadrata in
/// stringa"
///@param[in] matrix "matrice da cui leggere"
///@param[in] dim "dimensione della matrice"
const std::string matrixToString(int ***matrix, unsigned dim);

///@brief "salva il contenuto della matrice risultante (sempre quadrata) in un
/// file esterno"
///@param[in] matC "stringa al file in cui salvare la matrice"
///@param[in] MAT "oggetto della matrice risultato"
void saveOutput(const std::string &matC, const matr::SquaredMatrix *MAT);

} // namespace util
