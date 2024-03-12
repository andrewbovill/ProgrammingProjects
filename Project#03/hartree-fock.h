#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class HF{
  public:

//  Printing functions

    void print_matrix();
    void read_symm_mat();

// Declaring constructor and deconstructor functions
    HF(const char *filename);
    ~HF();
};


