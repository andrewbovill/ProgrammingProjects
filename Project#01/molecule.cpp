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

	for(int i = 0; i < natom; i++){
		for (int j = 0; j<i; j++){
			Rij[i][j] = pow(pow((geom[i][0]-geom[j][0]),2.0) +
				+pow((geom[i][1]-geom[j][1]),2.0) +
				+pow((geom[i][2]-geom[j][2]),2.0),0.5);
			printf("%d %d %8.5f\n", i, j, Rij[i][j]);
		}
	}
}
double Molecule::bond(int a,int b)
{
    return Rij[a][b];
}

double Molecule::dot(int a,int b,int c)
{
    //gives the dot product between two vectors ba and bc 
    //vector 1 = ba
    //vector 2 = bc

    double dot = 0.0;
	dot += (geom[a][0] - geom[b][0]) * (geom[c][0] - geom[b][0]); 
	dot += (geom[a][1] - geom[b][1]) * (geom[c][1] - geom[b][1]); 
	dot += (geom[a][2] - geom[b][2]) * (geom[c][2] - geom[b][2]); 

    return dot;
}

double Molecule::angle(int a,int b,int c)
{
    double angle = 0.0;
    angle = acos(dot(a,b,c)/(bond(a,b)*bond(b,c)));
    angle *= 180.0/acos(-1.0);
    return angle;
}

void Molecule::print_bond_angles(){

	printf("Andrew Test inside bond angle\n");
    for(int i = 0; i < natom; i++){
        for (int j = 0; j<i; j++){
            for (int k = 0; k<j; k++){
                if (i!=j && i!=k && j!=k){
			        printf("%2d-%2d-%2d %10.6f\n", i,j,k, angle(i,j,k));
                }
             }
		 }
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

	Rij = new double*[natom];
    for (int i = 0; i < natom; i++) { // Iterate up to natom
    	Rij[i] = new double[natom];
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
  
}

