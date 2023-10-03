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

void Molecule::print_bond_distances(){

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

void Molecule::print_bond_angles(){

    ex[1][0] = (geom[1][0]-geom[0][0])/(Rij[1][0]);
    ey[1][0] = (geom[1][1]-geom[0][1])/(Rij[1][0]);
    ez[1][0] = (geom[1][2]-geom[0][2])/(Rij[1][0]);

    ex[2][0] = (geom[2][0]-geom[0][0])/(Rij[2][0]);
    ey[2][0] = (geom[2][1]-geom[0][1])/(Rij[2][0]);
    ez[2][0] = (geom[2][2]-geom[0][2])/(Rij[2][0]);
    
    double dot_product = ex[1][0]*ex[2][0] + ey[1][0]*ey[2][0] + ez[1][0]*ez[2][0];
    double angle = acos(dot_product);

    cout << ez[1][0]<<"\n";
    cout << dot_product<<"\n";
    cout << angle<<"\n";

	/*printf("Andrew Test\n");
    for(int i = 0; i < natom; i++){
        for (int j = 0; j<i; j++){
            for (int k = 0; k<j; j++){
                if (i!=j && i!=k && j!=k){
                    ex[j][k] = (geom[j][0]-geom[k][0])/(Rij[j][k]);
                    ey[j][k] = (geom[j][1]-geom[k][1])/(Rij[j][k]);
                    ez[j][k] = (geom[j][2]-geom[k][2])/(Rij[j][k]);
                }

		}
		int j = 0;
	}*/
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

	ex = new double*[natom-1];
    for (int i = 0; i < natom; i++) { // Iterate up to natom
    	ex[i] = new double[natom-1];
	} 
    
	ey = new double*[natom-1];
    for (int i = 0; i < natom; i++) { // Iterate up to natom
    	ey[i] = new double[natom-1];
	} 
	ez = new double*[natom-1];
    for (int i = 0; i < natom; i++) { // Iterate up to natom
    	ez[i] = new double[natom-1];
	} 

}
Molecule::~Molecule(){
  delete[] zvals;
  for(int i=0; i < natom; i++){
    delete[] geom[i];
  }
  delete[] geom;
 
  for(int i=0; i < natom; i++){
    delete[] Rij[i];
  }
  delete[] Rij;

  for(int i=0; i < natom; i++){
    delete[] ex[i]; delete[] ey[i]; delete[] ez[i];
  }
  delete[] ex; delete[] ey; delete[] ez; 
}

