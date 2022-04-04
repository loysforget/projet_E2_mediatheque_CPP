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