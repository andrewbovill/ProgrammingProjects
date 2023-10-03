#include "molecule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
	
	double bond;

    //Create molecule object of class type "Molecule"
    Molecule mol(argv[1],0);

    cout << "Input Cartesian coordinates:\n";
    mol.print_geom();
    
    cout << "Interatomic distances (bohr):\n";
	mol.print_bond_distances();

    cout << "Interatomic distances (bohr):\n";
	mol.print_bond_angles();

    cout << "Andrew test: " << mol.Rij[1][0]<<"\n";
    return 0;

}
