#include "hf.h"
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

arma::mat openfile_mat(const char *filename,char mat){
  //Variable Declarations
  arma::mat A;
  std::ifstream file;
  std::string sdat_path, tdat_path, vdat_path;


  std::cout<<"Called open file procedure.\n";

  switch (mat) {
    case 's':
      std::cout<<"Reading S matrix.\n";
      sdat_path = std::string(filename) + "s.dat";
      file.open(sdat_path);
      if (!file.is_open()){
        std::cerr<<"s.dat file does not exist in this location\n";
        error_exit();
      }
      A = arma::randu<arma::mat>(4,4);
      break;
    case 't':
      std::cout<<"Reading t matrix.\n";
      tdat_path = std::string(filename) + "t.dat";
      file.open(tdat_path);
      if (!file.is_open()){
        std::cerr<<"t.dat file does not exist in this location\n";
        error_exit();
      }
      A = arma::randu<arma::mat>(3,3);
      break;
    case 'v':
      std::cout<<"Reading Vne Matrix.\n";
      vdat_path = std::string(filename) + "v.dat";
      file.open(vdat_path);
      if (!file.is_open()){
        std::cerr<<"v.dat file does not exist in this location\n";
        error_exit();
      }
      A = arma::randu<arma::mat>(5,5);
      break;
    default: 
      std::cout<<"Incorrect input for openfile argument.\n";
      error_exit();
      break;
  }
  return A;
}


/*
arma::mat readsymm_mat(const char *filename,char mat){
  std::cout<<"Hello World!\n";
  }
*/
