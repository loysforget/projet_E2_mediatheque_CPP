#include "cd.hpp"
//#define DEBUG
using namespace std;

/* STRUCTURE D'UN CD :
Type#ID#Titre#Auteur#Date de publi#Dispo#Duree#Nb de piste#Maison de prod#
*/

Cd::Cd() : Media(){
    duree = "";
    nb_piste = "";
    maison_prod = "";
    Media::defType("Cd");
}

Cd::Cd(ifstream& _stream, string _data, int _id) : Media(_stream, _data, _id){
    int pos = _data.find('#');
    _data.erase(0, pos+1);
    pos = _data.find('#');
    _data.erase(0, pos+1);
    pos = _data.find('#');
    _data.erase(0, pos+1);
    pos = _data.find('#');
    _data.erase(0, pos+1);
    pos = _data.find('#');
    _data.erase(0, pos+1);
    pos = _data.find('#');
    duree = _data.substr(0, pos);
    _data.erase(0, pos+1);
    pos = _data.find('#');
    nb_piste = _data.substr(0, pos);
    _data.erase(0, pos+1);
    pos = _data.find('#');
    maison_prod = _data.substr(0, pos);
    Media::defType("Cd");
    cout << "Ajout du CD [ID = " << getID() << " ]" << endl;
}


Cd::Cd(string null, int _id) : Media(null, _id){

    cout << "Entrez la durée : ";
    getline(cin, duree);

    cout << "Entrez le nombre de pistes : ";
    getline(cin, nb_piste);

    cout << "Entrez la maison de production : ";
    getline(cin, maison_prod);

    Media::defType("Cd");
}

Cd::~Cd(){
    //delete &nb_pages, &collection, &resume;
}


void Cd::load(string _data){
    if (_data.size() != 0){
        Media::load(_data);
        int pos = _data.find('#');
        _data.erase(0, pos+1);
        pos = _data.find('#');
        _data.erase(0, pos+1);
        pos = _data.find('#');
        _data.erase(0, pos+1);
        pos = _data.find('#');
        _data.erase(0, pos+1);
        pos = _data.find('#');
        _data.erase(0, pos+1);
        pos = _data.find('#');
        _data.erase(0, pos+1);
        pos = _data.find('#');
        duree = _data.substr(0, pos);
        _data.erase(0, pos+1);
        pos = _data.find('#');
        nb_piste = _data.substr(0, pos);
        _data.erase(0, pos+1);
        pos = _data.find('#');
        maison_prod = _data.substr(0, pos);
    }
    else{
        cout << "Le fichier est vide !" << endl;
    }
}

void Cd::save(ofstream& _stream){
    Media::save(_stream);
    _stream << duree << '#' << nb_piste << '#' << maison_prod << '#';
}

void Cd::show(){
    Media::show();
    cout << "Durée : " << duree << endl;
    cout << "Nombre de pistes : " << nb_piste << endl;
    cout << "Maison de production : " << maison_prod << endl;
}