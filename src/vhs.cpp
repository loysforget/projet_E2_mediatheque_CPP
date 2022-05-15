#include "vhs.hpp"
//#define DEBUG
using namespace std;

/* STRUCTURE D'UNE VHS :
Type#ID#Titre#Auteur#Date de publi#Dispo#Duree#Maison de prod#
*/

Vhs::Vhs() : Media(){
    duree = "";
    maison_prod = "";
    Media::defType("Vhs");
}

Vhs::Vhs(ifstream& _stream, string _data, int _id) : Media(_stream, _data, _id){
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
    maison_prod = _data.substr(0, pos);
    Media::defType("Vhs");
    cout << "Ajout du VHS [ID = " << getID() << " ]" << endl;
}


Vhs::Vhs(string null, int _id) : Media(null, _id){

    cout << "Entrez la durée : ";
    getline(cin, duree);

    cout << "Entrez la maison de production : ";
    getline(cin, maison_prod);

    Media::defType("Vhs");
}

Vhs::~Vhs(){
}


void Vhs::load(string _data){
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
        maison_prod = _data.substr(0, pos);
    }
    else{
        cout << "Le fichier est vide !" << endl;
    }
}

void Vhs::save(ofstream& _stream){
    Media::save(_stream);
    _stream << duree << '#' << maison_prod << '#';
}

void Vhs::show(){
    Media::show();
    cout << "Durée : " << duree << endl;
    cout << "Maison de production : " << maison_prod << endl;
}