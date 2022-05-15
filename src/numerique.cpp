#include "numerique.hpp"
//#define DEBUG
using namespace std;

/* STRUCTURE D'UN Numerique :
Type#ID#Titre#Auteur#Date de publi#Dispo#Nature#Taille#URL#
*/

Numerique::Numerique() : Media(){
    nature = "";
    taille = "";
    url = "";
    Media::defType("Numerique");
}

Numerique::Numerique(ifstream& _stream, string _data, int _id) : Media(_stream, _data, _id){
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
    nature = _data.substr(0, pos);
    _data.erase(0, pos+1);
    pos = _data.find('#');
    taille = _data.substr(0, pos);
    _data.erase(0, pos+1);
    pos = _data.find('#');
    url = _data.substr(0, pos);
    Media::defType("Numerique");
    cout << "Ajout du Numerique [ID = " << getID() << " ]" << endl;
}


Numerique::Numerique(string null, int _id) : Media(null, _id){

    cout << "Entrez la durée : ";
    getline(cin, nature);

    cout << "Entrez le nombre de pistes : ";
    getline(cin, taille);

    cout << "Entrez la maison de production : ";
    getline(cin, url);

    Media::defType("Numerique");
}

Numerique::~Numerique(){
    //delete &nb_pages, &collection, &resume;
}


void Numerique::load(string _data){
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
        nature = _data.substr(0, pos);
        _data.erase(0, pos+1);
        pos = _data.find('#');
        taille = _data.substr(0, pos);
        _data.erase(0, pos+1);
        pos = _data.find('#');
        url = _data.substr(0, pos);
    }
    else{
        cout << "Le fichier est vide !" << endl;
    }
}

void Numerique::save(ofstream& _stream){
    Media::save(_stream);
    _stream << nature << '#' << taille << '#' << url << '#';
}

void Numerique::show(){
    Media::show();
    cout << "Nature : " << nature << endl;
    cout << "Taille : " << taille << endl;
    cout << "URL : " << url << endl;
}