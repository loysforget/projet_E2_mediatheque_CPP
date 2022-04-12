#ifndef MEDIA_H 
#define MEDIA_H 
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Media{
    //Attributs

    protected :
    string titre;
    string auteur;
    string date_de_publi;
    int ID;

    //Methodes
    
    virtual bool add()=0;
    void load();
    void save();
    void clear();
    void search();
    void show_id();
    void delete_id();
    void reset_all();
    void list();
};

#endif