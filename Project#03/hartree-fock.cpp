#include "hartree-fock.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cmath>
#include <vector>

void HF::read_symm_mat()
{
  printf("calling read_symm_mat()");
}

void HF::print_matrix()
{
  printf("calling print_matrix()");
}

HF::HF(const char *filename){

	//Open filename
	std::ifstream inputfile(filename);
 	if (!inputfile.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
    } 

}

HF::~HF(){
  
}

