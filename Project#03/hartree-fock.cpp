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
  //std:cout<<"The second argument is: "<<argv[2]<<"\n";
  std::cout<<"calling read_symm_mat()"<<"\n";
}

void HF::print_matrix()
{
  printf("calling print_matrix()");
}

HF::HF(const char *filename){

	//Open filenam
  
  std::string sdat_path = std::string(filename) + "s.dat";
  std::cout<<"sdat_path is equal to: "<<sdat_path<<"\n";
  std::cout<<"\n"<<"\n";
	std::ifstream inputfile(sdat_path);
 	if (!inputfile.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
    } else { 
  		read_symm_mat();
			inputfile.close();
		}
	inputfile.close();
}

HF::~HF(){
  
}
inputfile.close();
