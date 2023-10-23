#include <string>
#include <iostream>
#include <fstream>
 
using namespace std;
 
class Molecule
{
  public:
    int natom;
    int charge;
    int *zvals;
    double **geom;
    double **Rij;
    string point_group;
 
    void print_geom();
	void print_bond_distances();

    double bond(int atom1,int atom2);
    double dot(int a,int b,int c);
    double angle(int atom1,int atom2,int atom3);
	void print_bond_angles();

    void rotate(double phi);
    void translate(double x, double y, double z);
    double torsion(int atom1, int atom2, int atom3, int atom4);

// Declaring constructor and deconstructor functions
    Molecule(const char *filename,int q);
    ~Molecule();
};

