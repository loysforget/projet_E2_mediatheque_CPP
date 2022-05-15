#ifndef REVUES_H 
#define REVUES_H 
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>
#include "livre.hpp"

using namespace std;

class Revues : public Livre {
  protected :
    string editeur;
    int nb_articles;

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