#include "molecule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

    //Create molecule object of class type "Molecule"
    Molecule mol(argv[1],0);

    cout << "Input Cartesian coordinates:\n";
    
    mol.print_geom();

    return 0;

}
