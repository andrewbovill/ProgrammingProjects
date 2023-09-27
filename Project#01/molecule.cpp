#include "molecule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

void Molecule::print_geom(){
    for(int i=0; i < natom; i++){
    	printf("%d %8.5f %8.5f %8.5f\n", zvals[i], geom[i][0], geom[i][1], geom[i][2]);
    }
}
