#include <string>
#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
class Molecule{
  public:
    int natom;
    int charge;
    int *zvals;
    double **geom;
    double **Rij;
    string point_group;

//  Printing functions
    void print_geom();
	  void print_bond_distances();
	  void print_bond_angles();
	  void print_oop_angles();

    double bond(int atom1,int atom2);
    double dot(const vector<double>& vector1, const vector<double>& vector2);
    vector<double> cross(const vector<double>& vector1, const vector<double>& vector2);
    vector<double> div(const vector<double>& vector, double divisor);
    double angle(int atom1,int atom2,int atom3);

    void rotate(double phi);
    void translate(double x, double y, double z);
    double torsion(int atom1, int atom2, int atom3, int atom4);

// Declaring constructor and deconstructor functions
    Molecule(const char *filename,int q);
    ~Molecule();
};

