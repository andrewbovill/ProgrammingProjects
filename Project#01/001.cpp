#include "molecule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>

int main(int argc, char* argv[]) {
	
	double bond;

//Create molecule object of class type "Molecule"
  Molecule mol(argv[1],0);

//Step 1 Print
  cout << "Input Cartesian coordinates:\n";
  mol.print_geom();
 
//Step 2 Print
  cout << "Interatomic distances (bohr):\n";
	mol.print_bond_distances();

//Step 3 Print
  cout << "Bond angles:\n";
  mol.print_bond_angles();

//Step 4 Print
//oop follows crawford notation for "out of plane angles"
  cout << "Out-of-plane angles:\n";
// Trying to reproduce -0-6-4-5
  cout << "Andrew test cross product\n";
  vector<double> tmpvec1(3);
  vector<double> tmpvec2(3);
  vector<double> tmpvec3(3);
  vector<double> tmpvec4(3);

	tmpvec1[0] = (mol.geom[4][0] - mol.geom[6][0]); 
  tmpvec1[1] = (mol.geom[4][1] - mol.geom[6][1]); 
  tmpvec1[2] = (mol.geom[4][2] - mol.geom[6][2]); 

	tmpvec2[0] = (mol.geom[4][0] - mol.geom[5][0]); 
  tmpvec2[1] = (mol.geom[4][1] - mol.geom[5][1]); 
  tmpvec2[2] = (mol.geom[4][2] - mol.geom[5][2]); 

	tmpvec3[0] = (mol.geom[4][0] - mol.geom[0][0]); 
  tmpvec3[1] = (mol.geom[4][1] - mol.geom[0][1]); 
  tmpvec3[2] = (mol.geom[4][2] - mol.geom[0][2]); 

  cout<<"tmpvec1: "<<" "<<tmpvec1[0]<<" "<<tmpvec1[1]<<" "<<tmpvec1[2]<<"\n";
  cout<<"tmpvec2: "<<" "<<tmpvec2[0]<<" "<<tmpvec2[1]<<" "<<tmpvec2[2]<<"\n";
  cout<<"tmpvec3: "<<" "<<tmpvec3[0]<<" "<<tmpvec3[1]<<" "<<tmpvec3[2]<<"\n";

  tmpvec4 = mol.cross(tmpvec1,tmpvec2);
  cout<<"cross: "<<" "<<tmpvec4[0]<<" "<<tmpvec4[1]<<" "<<tmpvec4[2]<<"\n";
  
  cout<<"dot: "<<mol.dot(tmpvec4,tmpvec3)<<"\n";
	//mol.print_oop_angles();

  return 0;

}
