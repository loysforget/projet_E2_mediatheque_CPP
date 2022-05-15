#include "dvd.hpp"
//#define DEBUG
using namespace std;

/* STRUCTURE D'UNE DVD :
Type#ID#Titre#Auteur#Date de publi#Dispo#Duree#Maison de prod#Nb de chapitres#
*/

Dvd::Dvd() : Vhs(){
    chapitre = "";
    defType("Dvd");
}

Dvd::Dvd(ifstream& _stream, string _data, int _id) : Vhs(_stream, _data, _id){
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
    _data.erase(0, pos+1);
    pos = _data.find('#');
    chapitre = _data.substr(0, pos);
    defType("Dvd");
    cout << "Ajout du Dvd [ID = " << getID() << " ]" << endl;
}


Dvd::Dvd(string null, int _id) : Vhs(null, _id){

    cout << "Entrez le nombre de chapitres : ";
    getline(cin, chapitre);

    defType("Dvd");
}

Dvd::~Dvd(){
}


void Dvd::load(string _data){
    if (_data.size() != 0){
        Vhs::load(_data);
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
        _data.erase(0, pos+1);
        pos = _data.find('#');
        _data.erase(0, pos+1);
        pos = _data.find('#');
        chapitre = _data.substr(0, pos);
    }
    else{
        cout << "Le fichier est vide !" << endl;
    }
}

void Dvd::save(ofstream& _stream){
    Vhs::save(_stream);
    _stream << chapitre << '#';
}

void Dvd::show(){
    Vhs::show();
    cout << "Nombre de chapitres : " << chapitre << endl;
}