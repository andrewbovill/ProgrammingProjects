#include "molecule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

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

    mol.zvals = new int[mol.natom];
    mol.geom = new double*[mol.natom];
    for (int i = 0; i < mol.natom; i++) { // Iterate up to mol.natom
            mol.geom[i] = new double[3];
    }

    for (int i = 0; i < mol.natom; i++){
        inputFile >> mol.zvals[i]>>mol.geom[i][0]>>mol.geom[i][1]>>mol.geom[i][2];
    } 
    //cout << "Input Cartesian coordinates:\n";
    
    mol.print_geom();

    return 0;

}
