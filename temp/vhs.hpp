#ifndef VHS_H 
#define VHS_H
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>
#include "media.hpp"

using namespace std;

class VHS : public Media {
    //Attributs

    protected :
    int duree;
    string maison_de_prod;
    
    //Methodes
    
    virtual bool add(int media_type)=0;
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