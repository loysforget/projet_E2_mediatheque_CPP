#ifndef LIVRE_H 
#define LIVRE_H 
#include <iostream>
#include "media.hpp"
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Livre : public Media{
    //Attributs

    protected :
    int nb_pages;
    string collection;
    string resume;
    
    //Methodes
    public:

    Livre();  
    Livre(string null, int _id); 
    Livre(ifstream& _stream, string _data, int _id);                                                                    
    ~Livre();  

    /*
    virtual void defNb_pages(int _nb_pages);
    virtual void defCollection(string _collection);
    virtual void defResume(string _resume);

    virtual int getNb_pages();
    virtual string getCollection();
    virtual string getResume();
    */


    virtual void load(string _data);
    virtual void save(ofstream& _stream);
    virtual void show();


};

#endif