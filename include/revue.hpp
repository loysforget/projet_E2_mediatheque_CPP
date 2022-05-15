#ifndef Revue_H 
#define Revue_H 
#include <iostream>
#include "livre.hpp"
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Revue : public Livre{
    //Attributs

    protected :
    string editeur;
    string nb_article;
    
    //Methodes
    public:

    Revue();  
    Revue(string null, int _id); 
    Revue(ifstream& _stream, string _data, int _id);                                                                    
    ~Revue();  

    /*
    virtual void defNb_pages(int _nb_pages);
    virtual void defCollection(string _collection);
    virtual void defResume(string _resume);

    virtual int getNb_pages();
    virtual string getCollection();
    virtual string getResume();
    */


    void load(string _data);
    void save(ofstream& _stream);
    void show();


};

#endif