#ifndef CD_H 
#define CD_H 
#include <iostream>
#include "media.hpp"
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Cd : public Media{
    //Attributs

    protected :
    string duree;
    string nb_piste;
    string maison_prod;
    
    //Methodes
    public:

    Cd();
    Cd(string null, int _id);
    Cd(ifstream& _stream, string _data, int _id);                                                                        
    ~Cd();


    void load(string _data);
    void save(ofstream& _stream);
    void show();


};

#endif