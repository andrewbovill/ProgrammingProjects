#include "molecule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>

void Molecule::print_geom(){
    for(int i=0; i < natom; i++){
    	printf("%d %8.5f %8.5f %8.5f\n", zvals[i], geom[i][0], geom[i][1], geom[i][2]);
    }
}

Molecule::Molecule(const char *filename,int q){

	charge = q;

	//Open filename
	std::ifstream inputfile(filename);
 	if (!inputfile.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
    } 

	inputfile >> natom;

    zvals = new int[natom];
    geom = new double*[natom];
    for (int i = 0; i < natom; i++) { // Iterate up to natom
    	geom[i] = new double[3];
    }

    for (int i = 0; i < natom; i++){
    	inputfile>>zvals[i]>>geom[i][0]>>geom[i][1]>>geom[i][2];
    } 

}
Molecule::~Molecule(){
  delete[] zvals;
  for(int i=0; i < natom; i++)
    delete[] geom[i];
  delete[] geom;
}

