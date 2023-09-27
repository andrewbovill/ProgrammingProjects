//Declaring constructor and deconstructor functions
// Constructor definition    
    Molecule(int n)
    {
        // Initialize your attributes here, e.g., zvals, point_group
        natom = 0;
        charge = 0;
        zvals = nullptr;
        geom = nullptr;

        // Allocate space

        zvals = new int[natom];
        geom = new double*[natom];
        for (int i = 0; i < natom; i++) { // Iterate up to mol.natom
            geom[i] = new double[3];
     }
    /*void print_geom(){
    for (int i = 0; i < mol.natom; i++){
        std::cout<<geom[i][0]<<" "<<geom[i][1]<<" "<<geom[i][2]<<std::endl;
    */
     

// Destructor definition
    ~Molecule()
    {
        // Clean up dynamically allocated resources, if any
        if (zvals != nullptr) {
            delete[] zvals;
        }
        if (geom != nullptr) {
        for (int i = 0; i < natom; i++) {
            delete[] geom[i];
        }
        delete[] geom;
    }
}

};



