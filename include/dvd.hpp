#ifndef Dvd_H 
#define Dvd_H 
#include <iostream>
#include "vhs.hpp"
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Dvd : public Vhs{
    //Attributs

    protected :
    string chapitre;

    
    //Methodes
    public:

    Dvd();
    Dvd(string null, int _id);
    Dvd(ifstream& _stream, string _data, int _id);                                                                        
    ~Dvd();

    void load(string _data);
    void save(ofstream& _stream);
    void show();


};

#endif