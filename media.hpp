#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>
#ifndef MEDIATHEQUE_H 
#define MEDIATHEQUE_H 

class Media{
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