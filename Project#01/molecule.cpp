#include "molecule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cmath>

void Molecule::print_geom(){
    for(int i=0; i < natom; i++){
    	printf("%d %8.5f %8.5f %8.5f\n", zvals[i], geom[i][0], geom[i][1], geom[i][2]);
    }
}

void Molecule::print_bond(){

	printf("Andrew Test\n");
	for(int i = 0; i < natom; i++){
		for (int j = 0; j<i; j++){
			Rij[i][j] = pow(pow((geom[i][0]-geom[j][0]),2.0) +
				+pow((geom[i][1]-geom[j][1]),2.0) +
				+pow((geom[i][2]-geom[j][2]),2.0),0.5);
			printf("%d %d %8.5f\n", i, j, Rij[i][j]);
		}
		int j = 0;
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

	Rij = new double*[natom-1];
    for (int i = 0; i < natom; i++) { // Iterate up to natom
    	Rij[i] = new double[natom-1];
	} 

}
Molecule::~Molecule(){
  delete[] zvals;
  for(int i=0; i < natom; i++)
    delete[] geom[i];
  delete[] geom;
}

