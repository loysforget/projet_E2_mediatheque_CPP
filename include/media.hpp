#ifndef MEDIA_H 
#define MEDIA_H 
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Media{
    //Attributs

    protected :
        string type;
        string titre;
        string auteur;
        string date_de_publi;
        string dispo;
        static int statID;
        int ID;

    //Methodes
    
    public :
        Media();
        Media(string null, int _id);
        Media(ifstream& _stream, string _data, int _id);
        virtual ~Media();
        
        void defType(string _type);
        void defTitre(string _titre);
        void defAuteur(string _auteur);
        void defDate_de_publi(string _date_de_publi);
        void defStatID(int _id);

        string getType();
        string getTitre();
        string getAuteur();
        string getDate_de_publi();
        string getDispo();
        int getID();

        void emprunter();
        void rendre();
        void reserver();


        virtual void show();
        virtual void load(string _data);
        virtual void save(ofstream& _stream);
        void list();

};

#endif