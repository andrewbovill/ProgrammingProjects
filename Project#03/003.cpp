#include "hartree-fock.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <armadillo>
#include <vector>

/* Andrew --- Programming practice HartreeFock from Github project
 * https://github.com/CrawfordGroup/ProgrammingProjects Project #03
 * Note Procedure does not calculate 1 and 2 electron matrices, only reads
 * then in!
 */

int main(int argc, char* argv[]) {

  if (argc!= 2){ 
    std::cerr <<"Incorrect number of files, need molecule name and directory where files are located.\n";
    error_exit();
  }

  std::cout << "Hartree-fock test calculation from PSI4 .dat files.\n";
  std::cout << "Location of files within: " << argv[1] << "\n\n";

//Read Overlap Matrix
  arma::mat S_Mat = openfile(argv[1],'s');
  print_mat(S_Mat);
  //arma::S_Mat = readsymm_mat(argv[1],'s');
//Read Kinetic Matrix
//  openfile(argv[1],'t');
  //arma::T_Mat = readsymm_mat(argv[1],'t');
//Read Kinetic Matrix
 // openfile(argv[1],'v');
  //arma::V_Mat = readsymm_mat(argv[1],'v');



  return 0;

}

