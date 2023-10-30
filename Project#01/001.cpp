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
  cout <<"\n";

//Step 3 Print
  cout << "Bond angles:\n";
  mol.print_bond_angles();
  cout <<"\n";

//Step 4 Print
//oop follows crawford notation for "out of plane angles"
  cout << "Out-of-plane angles:\n";
  mol.print_oop_angles();

  return 0;

}
