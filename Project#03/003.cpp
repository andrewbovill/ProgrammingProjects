#include "hartree-fock.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>

/* Andrew --- Programming practice HartreeFock from Github project
 * https://github.com/CrawfordGroup/ProgrammingProjects Project #03
 * Note Procedure does not calculate 1 and 2 electron matrices, only reads
 * then in!
 */
void error_exit(){
  std::cout<<"ERROR! Hartree-Fock Program terminating.\n";
  exit(0);
}

int main(int argc, char* argv[]) {

  if (argc!= 3){ 
    std::cout <<"Incorrect number of files, need molecule name and directory where files are located.\n";
    error_exit();
  }

  std::cout << "Hartree-fock test calculation from PSI4 .dat files.\n";
  std::cout << "Location of files within: " << argv[2] << "\n";
  std::cout << "Argument count: " << argc << "\n";
//Create molecule object of class type "Molecule"
  HF mol(argv[2]);

//Step 1 Print

//Read Overlap Matrix

//Read  Nuclear Repulsion from file

//Read Overlap Matrix

//Read Kinetic Matrix

//Read Nuclear AttractionMatrix

  return 0;

}

