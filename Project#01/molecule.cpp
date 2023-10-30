#include "molecule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

void Molecule::print_geom()
{
  for(int i=0; i < natom; i++)
  {
    printf("%d %8.5f %8.5f %8.5f\n", zvals[i], geom[i][0], geom[i][1], geom[i][2]);
  }
}

void Molecule::print_bond_distances()
{
  for(int i = 0; i < natom; i++)
  {
		for (int j = 0; j<i; j++)
    {
			Rij[i][j] = pow(pow((geom[i][0]-geom[j][0]),2.0) +
				+pow((geom[i][1]-geom[j][1]),2.0) +
				+pow((geom[i][2]-geom[j][2]),2.0),0.5);
			printf("%d %d %8.5f\n", i, j, Rij[i][j]);
		}
	}
}
double Molecule::bond(int a,int b)
{
    //Rij[a][b] transpose values don't exist, just do transpose on the fly
    if (Rij[a][b] == 0.0)
    {
      double bond_distance = Rij[b][a];
      return bond_distance;
    }
    else
    {
      return Rij[a][b];
    }
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

double Molecule::unit(int cart, int a, int b)
{
  return -(geom[a][cart]-geom[b][cart])/bond(a,b);
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
        if(bond(i,j) < 4.0 && bond(j,k) < 4.0)
        {
			    printf("%2d-%2d-%2d %10.6f\n", i,j,k, angle(i,j,k));
        }
             }
		 }
	 }
}

void Molecule::print_oop_angles(){
  for(int i=0; i < natom; i++) {
    for(int k=0; k < natom; k++) {
      for(int j=0; j < natom; j++) {
        for(int l=0; l < j; l++) {
          if(i!=j && i!=k && i!=l && j!=k && k!=l && bond(i,k) < 4.0 && bond(k,j) < 4.0 && bond(k,l) < 4.0){
          //generate tmpvec as left vector
          //bond(k,j) is to normalize
          vector<double> vectorkj(3);
	        vectorkj[0] = (geom[j][0] - geom[k][0])/bond(k,j); 
	        vectorkj[1] = (geom[j][1] - geom[k][1])/bond(k,j); 
	        vectorkj[2] = (geom[j][2] - geom[k][2])/bond(k,j); 

          vector<double> vectorkl(3);
	        vectorkl[0] = (geom[l][0] - geom[k][0])/bond(k,l); 
	        vectorkl[1] = (geom[l][1] - geom[k][1])/bond(k,l); 
	        vectorkl[2] = (geom[l][2] - geom[k][2])/bond(k,l); 

          vector<double> tmpvec(3);
          tmpvec = cross(vectorkj,vectorkl);
          //cout<<"cross product: "<<tmpvec[0]<<" "<<tmpvec[1]<<" "<<tmpvec[2]<<endl;
          //cout<<endl;

           //generate ki as right vector
          vector<double> vectorki(3);
	        vectorki[0] = (geom[i][0] - geom[k][0])/bond(k,i); 
	        vectorki[1] = (geom[i][1] - geom[k][1])/bond(k,i); 
	        vectorki[2] = (geom[i][2] - geom[k][2])/bond(k,i); 

          //Down below... there's a bunch of conversions from radians to degrees
          //Some day I'll make a function for it...whatever
          double oop = dot(tmpvec,vectorki)/sin(angle(j,k,l)*acos(-1.0)/180.0);
          //oop /= sin(angle(j,k,l));

          if(oop < -1.0) oop = asin(-1.0);
          else if(oop > 1.0) oop = asin(1.0);
          else oop = asin(oop);

          oop = oop*180.0/acos(-1.0);
  			  printf("%2d-%2d-%2d-%2d %10.6f\n", i,j,k,l, oop);
          }
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

