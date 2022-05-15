#ifndef RESSOURCES_NUM_H 
#define RESSOURCES_NUM_H 
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>
#include "media.hpp"

using namespace std;

class Ressources_num : public Media {
    //Attributs

  protected :
      string type;
      int taille;
      string URL;
    
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