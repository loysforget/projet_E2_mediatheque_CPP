#ifndef VHS_H 
#define VHS_H 
#include <iostream>
#include "media.hpp"
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Vhs : public Media{
    //Attributs

    protected :
    string duree;
    string maison_prod;
    
    //Methodes
    public:

    Vhs();
    Vhs(string null, int _id);
    Vhs(ifstream& _stream, string _data, int _id);                                                                        
    ~Vhs();


    virtual void load(string _data);
    virtual void save(ofstream& _stream);
    virtual void show();


};

#endif