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

// Returns the value of the unit vector between atoms a and b
// in the cart direction (cart=0=x, cart=1=y, cart=2=z)
double Molecule::unit(int cart, int a, int b)
{
  return -(geom[a][cart]-geom[b][cart])/bond(a,b);
}

// Returns the angle between atoms a, b, and c in radians
double Molecule::angle(int a, int b, int c)
{
  return acos(unit(0,b,a) * unit(0,b,c) + unit(1,b,a) * unit(1,b,c) + unit(2,b,a) * unit(2,b,c));
}

double Molecule::bond(int a, int b)
{
  return sqrt( (geom[a][0]-geom[b][0])*(geom[a][0]-geom[b][0])
             + (geom[a][1]-geom[b][1])*(geom[a][1]-geom[b][1])
             + (geom[a][2]-geom[b][2])*(geom[a][2]-geom[b][2]) );
}

double Molecule::oop(int a, int b, int c, int d)
{
  double ebcd_x = (unit(1,c,b) * unit(2,c,d) - unit(2,c,b) * unit(1,c,d));
  double ebcd_y = (unit(2,c,b) * unit(0,c,d) - unit(0,c,b) * unit(2,c,d));
  double ebcd_z = (unit(0,c,b) * unit(1,c,d) - unit(1,c,b) * unit(0,c,d));

  double exx = ebcd_x * unit(0,c,a);
  double eyy = ebcd_y * unit(1,c,a);
  double ezz = ebcd_z * unit(2,c,a);

  cout<<"\n";
  double hold_x = ebcd_x;
  double hold_y = ebcd_y;
  double hold_z = ebcd_z;
  cout<<hold_x<<" "<<hold_y<<" "<<hold_z;

  cout<<"\n";
  double temp = exx + eyy + ezz;
  cout<<"Cross * dot: "<<temp<<"\n";
  double sina = sin(angle(b,c,d));
  cout<<"Angle: "<<sina<<"\n";
  double theta = (exx + eyy + ezz)/sin(angle(b,c,d));

  if(theta < -1.0) theta = asin(-1.0);
  else if(theta > 1.0) theta = asin(1.0);
  else theta = asin(theta);

  return theta;
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
  for(int i=0; i < natom; i++){
    delete[] geom[i];
  }
  delete[] geom;
}

