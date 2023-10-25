#include "molecule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

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

double Molecule::dot(const vector<double>& vector1, const vector<double>& vector2)
{
    //gives the dot product between two vectors ba and bc 
    //vector 1 = ba
    //vector 2 = bc

    if (vector1.size() != vector2.size())
    {
        // You can add proper error handling here.
        cerr << "Error: Vectors have different dimensions.\n";
        return 0.0;
    }

    double dot = 0.0;
    for (size_t i = 0; i < vector1.size(); i++)
    {
        dot += vector1[i] * vector2[i];
    }

    return dot;
}


vector<double> Molecule::cross(const vector<double>& vector1, const vector<double>& vector2)
{
    cout<<"Vector size 1 :"<< vector1.size()<<endl;
    cout<<"Vector size 2 :"<< vector2.size()<<endl;
    
    if (vector1.size() != 3 || vector2.size() != 3)
    {
        // You can add proper error handling here.
        cerr << "Error: Cross product requires 3D vectors.\n";
        return vector<double>(); // Return an empty vector for error case.
    }

    vector<double> cross(3);

    cross[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    cross[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    cross[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];

    return cross;
}

double Molecule::angle(int a,int b,int c)
{
    //gives the dot product between two vectors ba and bc 
    //vector 1 = ba
    //vector 2 = bc
    
    vector<double> vectorba;
	vectorba.push_back(geom[a][0] - geom[b][0]);
	vectorba.push_back(geom[a][1] - geom[b][1]);
	vectorba.push_back(geom[a][2] - geom[b][2]);

    vector<double> vectorbc;
	vectorbc.push_back(geom[c][0] - geom[b][0]); 
	vectorbc.push_back(geom[c][1] - geom[b][1]); 
	vectorbc.push_back(geom[c][2] - geom[b][2]); 

    double angle = 0.0;
    angle = acos(dot(vectorba,vectorbc)/(bond(a,b)*bond(b,c)));
    angle *= 180.0/acos(-1.0);
    return angle;
}

void Molecule::print_bond_angles(){

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

void Molecule::print_oop_angles(){

    for(int i = 0; i < natom; i++){
        for (int j = 0; j<natom; j++){
            for (int k = 0; k<natom; k++){
                for (int l = 0; l<k; l++){
                    //generate tmpvec as left vector
                    vector<double> vectorkj(3);
	                vectorkj[0] = (geom[k][0] - geom[j][0]); 
	                vectorkj[1] = (geom[k][1] - geom[j][1]); 
	                vectorkj[2] = (geom[k][2] - geom[j][2]); 

                    vector<double> vectorkl(3);
	                vectorkl[0] = (geom[k][0] - geom[l][0]); 
	                vectorkl[1] = (geom[k][1] - geom[l][1]); 
	                vectorkl[2] = (geom[k][2] - geom[l][2]); 

                    vector<double> tmpvec(3);
                    tmpvec = cross(vectorkj,vectorkl);

                    //generate ki as right vector
                    vector<double> vectorki(3);
	                vectorki[0] = (geom[k][0] - geom[i][0]); 
	                vectorki[1] = (geom[k][1] - geom[i][1]); 
	                vectorki[2] = (geom[k][2] - geom[i][2]); 

                    //double oop
                    double oop = dot(tmpvec,vectorki);

//                    cout << "Checking function cross: " << cross(vectorkj,vectorkl) << std::endl;
//				    cout << "Checking function angle: " << sin(angle(i,j,k))<< std::endl;
   // 				cout << "Checking function div: " << div(cross(vectorkj,vectorkl),sin(angle(i,j,k))) << std::endl;
 //   				cout << "Checking function oop: " << dot(tmpvec,vectorki) << std::endl;
  			        printf("%2d-%2d-%2d-%2d %10.6f\n", i,j,k,l, oop);
    				cout << std::endl;
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

