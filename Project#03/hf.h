#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <armadillo>

void error_exit();
void print_mat(const arma::mat& mat);
arma::mat openfile_mat(const char *filename,char mat);
//arma::mat readsymm_mat(const char *filename,char mat);
