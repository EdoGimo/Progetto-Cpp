/**
 * @copyright MyProject
 * license MIT
 * @author Edoardo Righi
 * @version v1.0
 * @date August, 2018
 * @file main.cpp
 */

#include "Calcs.hpp"
#include "Matrix.hpp"
#include "Utils.hpp"

int main(int argc, char *argv[]) {

  if (argc != 4) {
    std::cout << "Numero di parametri in input non corretto" << std::endl;
    return -1;
  }

  const std::string matA = argv[1];
  const std::string matB = argv[2];
  const std::string matC = argv[3];

  unsigned widthA;
  unsigned heightA;
  unsigned widthB;
  unsigned heightB;

  // primo file
  std::fstream input1(matA, std::istream::in);

  // controllo se il file non esiste
  if (!input1.good()) {
    std::cout << "Il file '" << matA << "' non esiste!" << std::endl;
    return -1;
  }

  // controllo se il file è vuoto
  if (input1.peek() == std::ifstream::traits_type::eof()) {
    std::cout << "Il file '" << matA << "' è vuoto!" << std::endl;
    return -1;
  }

  // secondo file
  std::fstream input2(matB, std::istream::in);

  // controllo se il file non esiste
  if (!input2.good()) {
    std::cout << "Il file '" << matB << "' non esiste!" << std::endl;
    return -1;
  }

  // controllo se il file è vuoto
  if (input2.peek() == std::ifstream::traits_type::eof()) {
    std::cout << "Il file '" << matB << "' è vuoto!" << std::endl;
    return -1;
  }

  // ottengo le dimensioni della prima matrice
  if (!util::calcDim(input1, &widthA, &heightA)) {
    std::cout << "Il primo file non contiene una matrice!" << std::endl;
    input1.close();
    return -1;
  }

  std::cout << "La prima matrice ha dimensioni " << heightA << "x" << widthA
            << "." << std::endl;

  // ottengo le dimensioni della seconda matrice
  if (!util::calcDim(input2, &widthB, &heightB)) {
    std::cout << "Il secondo file non contiene una matrice!" << std::endl;
    input2.close();
    return -1;
  }

  std::cout << "La seconda matrice ha dimensioni " << heightB << "x" << widthB
            << "." << std::endl;

  // pulisco buffer
  input1.clear();
  // reset della posizione da cui legge all'inizio
  input1.seekg(0, std::ios::beg);
  // pulisco buffer
  input2.clear();
  // reset della posizione da cui legge all'inizio
  input2.seekg(0, std::ios::beg);

  // salvo il valore di dimensione risultato (se esiste)
  unsigned dim = heightA;

  if ((heightA == widthA) && (widthA == heightB) && (heightB == widthB)) {

    calc::sqCalc(dim, matC, input1, input2);

  } else if ((heightA == widthB) && (widthA == heightB)) {

    calc::nsqCalc(widthA, heightA, matC, input1, input2);

  } else {
    std::cout << "Il prodotto delle due matrici non è possibile!" << std::endl;
  }

  input1.close();
  input2.close();

  return 0;
}
