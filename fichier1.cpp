#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Media{
    protected :
    string titre;
    string auteur;
    string date_de_publi;
    int ID;

    public :
    string titre(){
        cout << titre << endl;
        return titre;
    }

    string auteur(){
        cout << auteur << endl;
        return auteur;
    }

    string date_de_publi(){
        cout << date_de_publi << endl;
        return date_de_publi;
    }

    int show_ID(){
        cout << ID << endl;
        return ID;
    }

    void search(){

    }

    void clear(){

    }

    void save(int ID, string _filename){

    }

};

class Livres : public Media{
    protected :
    int nb_pages;
    string collection;
    string resume;
};

class CD : public Media {
    protected :
    int duree;
    int nb_piste;
    string maison_de_prod;
};

class VHS : public Media {
  protected :
    int duree;
    string maison_de_prod;
};

class Ressources_Num : public Media {
  protected :
      string type;
      int taille;
      string URL;
};

class Revues : public Livres {
  protected :
    string editeur;
    int nb_articles;
};

class DVD : public VHS {
  protected :
  int chapitre;
};

// Class Media

cout << "Entrez l'auteur : " << endl;
getline( cin, auteur);

cout << "Entrez le titre : " << endl;
getline( cin, titre);

cout << "Entrez la date de publication : " << endl;
getline( cin, date_de_publi);

cout << "Entrez l'ID : " << endl;
getline( cin, ID);

// Class Livres

cout << "Entrez le nombre de pages : " << endl;
getline( cin, nb_pages);

cout << "Entrez la collection : " << endl;
getline( cin, collection);

cout << "Entrez le résumé : " << endl;
getline( cin, resume);

// Class Revues

cout << "Entrez l'éditeur : " << endl;
getline( cin, editeur);

cout << "Entrez le nombre d'articles :  : " << endl;
getline( cin, nb_articles);

// Class CD

cout << "Entrez la durée du CD : " << endl;
getline( cin, duree);

cout << "Entrez le nombre de pistes : " << endl;
getline( cin, nb_piste);

cout << "Entrez la maison de production : " << endl;
getline( cin, maison_de_prod);

// Class VHS

cout << "Entrez la durée : " << endl;
getline( cin, duree);

cout << "Entrez la maison de production : " << endl;
getline( cin, maison_de_prod);

// CLass DVD

cout << "Entrez le nombres de chapitres : " << endl;
getline( cin, chapitre);

// Class Ressources_Num

cout << "Entrez le Type : " << endl;
getline( cin, type);

cout << "Entrez la taille : " << endl;
getline( cin, taille);

cout << "Entrez le chemin d'accès : " << endl;
getline( cin, URL);


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
