#ifndef CD_H 
#define CD_H 
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>
#include "media.hpp"

using namespace std;

class CD : public Media {
    //Attributs

    protected :
    int duree;
    int nb_piste;
    string maison_de_prod;

    
    //Methodes
    
    virtual bool add() = 0;
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