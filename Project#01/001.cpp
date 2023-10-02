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
	mol.print_bond();

	cout<<"Temp bond distance for one atom\n";
	//printf("%d %8.5f",mol.geom[1][2]);

/*	bond = pow((mol.geom[0][0]-mol.geom[1][0]),2.0) +
		+pow((mol.geom[0][1]-mol.geom[1][1]),2.0) +
		+pow((mol.geom[0][2]-mol.geom[1][2]),2.0);

	bond = pow(bond,0.5);

	//bond = (pow(mol.geom[0][1]-mol.geom[1][1]),2.0)+(pow(mol.geom[0][2]-mol.geom[1][2]),2.0)+(pow(mol.geom[0][3]-mol.geom[1][3]),2.0)
	//bond = pow(bond,0.5);
*/
	cout<<"Bond distance "<<bond<<"\n";

    return 0;

}
