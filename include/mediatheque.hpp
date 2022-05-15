#ifndef MEDIATHEQUE_H 
#define MEDIATHEQUE_H 
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "media.hpp"

using namespace std;

class Mediatheque{
    public :
    //Attributs
    vector<Media*> alldata;
    vector<Media*> searchvector;
    Mediatheque();
    ~Mediatheque();
    //Methodes
    void bye();
    bool add(string _option);
    vector<Media*> getAlldata();
    void listAll(string _vector);
    void showAll(string _vector);
    void load(string _vector, string _filename);
    bool save(string _vector, string _filename);
    void reset();
    void clear();
    bool search(string _vecteur, string _searching);
    size_t findCaseInsensitive(std::string data, std::string toSearch, size_t pos);
    bool select_action(string _vecteur, int _num_media);
    void show(int _ID);
    void delete_id();
    void reset_all();
    void list();

    void emprunter(int _id);
    void rendre(int _id);
    void reserver(int _id);
};

#endif