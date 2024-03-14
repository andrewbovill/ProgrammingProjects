#include "hartree-fock.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>
#include <armadillo>
#include <cmath>
#include <vector>

void error_exit(){
  std::cerr<<"ERROR! Hartree-Fock Program terminating.\n";
  exit(0);
}
void print_mat(const arma::mat& mat){
  size_t numRows = mat.n_rows;
  size_t numCols = mat.n_cols;
  for (size_t i = 0; i < numRows; ++i) {
      std::cout << "|| "; 
      for (size_t j = 0; j < numCols; ++j) {
          // Print the element followed by a space
          std::cout << mat(i, j) << " ";
      }
      std::cout << "||" << std::endl; 
  }
}

arma::mat openfile(const char *filename,char mat){
  std::cout<<"Called open file procedure.\n";
  if (mat == 's'){
    std::cout<<"Reading S matrix.\n";
  } else if (mat =='t') {
    std::cout<<"Reading T matrix.\n";
  } else if (mat =='v') {
    std::cout<<"Reading Vne matrix.\n";
  } else {
    std::cout<<"Incorrect input for openfile argument.\n";
  }
  arma::mat A = arma::randu<arma::mat>(4,4);
  return A;
}


/*
arma::mat readsymm_mat(const char *filename,char mat){
  std::cout<<"Hello World!\n";
  }
*/
