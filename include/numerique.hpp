#ifndef Numerique_H 
#define Numerique_H 
#include <iostream>
#include "media.hpp"
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Numerique : public Media{
    //Attributs

    protected :
    string nature;
    string taille;
    string url;
    
    //Methodes
    public:

    Numerique();
    Numerique(string null, int _id);
    Numerique(ifstream& _stream, string _data, int _id);                                                                        
    ~Numerique();

    void load(string _data);
    void save(ofstream& _stream);
    void show();


};

#endif