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
    
    bool add();
    void load();
    void save();
    void clear();
    void search();
    void show_id();
    void delete_id();
    void reset_all();
    void list();
};

#endifid delete_id();
    void reset_all();
    void list();
};

#endif