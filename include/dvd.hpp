#ifndef DVD_H 
#define DVD_H 
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>
#include "vhs.hpp"

using namespace std;

class DVD : public VHS {
    //Attributs

    protected :
 int chapitre;

    
    //Methodes
    
    virtual bool add(int media_type) = 0;
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