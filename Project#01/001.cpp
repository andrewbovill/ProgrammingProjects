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

    cout << "Bond angles:\n";

    cout << "Andrew test dot:\n";
    cout << mol.dot(2,1,0)<<"\n";
    cout << mol.angle(2,1,0)<<"\n";
    cout << mol.angle(3,1,0)<<"\n";

	mol.print_bond_angles();

    return 0;

}
