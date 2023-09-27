#include "molecule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/*Code to get introduced to C++ programming techniques
  Pulled from the following git repository:

  https://github.com/andrewbovill/ProgrammingProjects/tree/master

  This code achieves the following:
  1. Opening and closing file stream
  2. Reading in atomic masses and x,y,z coordinates
  3. Calculate bond lengths between interatomic coordinates
  4. Calculate all possible bond angles
  5. Calculate all possible out-of-plane angles
  6. Calculate Torsion/Dihedral angles
  7. Calculate Principal Moments of Inertia
  8. Calculate Rotational Constants 


  --Andrew Bovill September 2023
  --Note: Using given "molecule.h" to declare molecule class
*/


int main(int argc, char* argv[]) {
    //Variable declaration

    ifstream inputFile;
    inputFile.open(argv[1]);
    //Check to see if file exists.
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    } 
    //Create molecule object of class type "Molecule"
    Molecule mol;

    inputFile >> mol.natom;
    cout <<"Number of atoms: "<<mol.natom<< endl;

    cout<<"Andrew test here."<<endl;
    mol.zvals = new int[mol.natom];
    mol.geom = new double*[mol.natom];
    for (int i = 0; i < mol.natom; i++) { // Iterate up to mol.natom
            mol.geom[i] = new double[3];
    }

    for (int i = 0; i < mol.natom; i++){
        inputFile >> mol.zvals[i]>>mol.geom[i][0]>>mol.geom[i][1]>>mol.geom[i][2];
    } 

    for(int i=0; i < mol.natom; i++){
    printf("%d %8.5f %8.5f %8.5f\n", mol.zvals[i], mol.geom[i][0], mol.geom[i][1], mol.geom[i][2]);
    }
    //cout << "Input Cartesian coordinates:\n";
    
    //mol.print_geom();

    return 0;

}
