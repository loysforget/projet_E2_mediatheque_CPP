#include "livre.hpp"
//#define DEBUG
using namespace std;

/* STRUCTURE D'UN LIVRE :
Type#ID#Titre#Auteur#Date de publi#Dispo#Nb de pages#Collection#Resume#
*/

Livre::Livre() : Media(){
    nb_pages = 0;
    collection = "";
    resume = "";
    Media::defType("Livre");
}

Livre::Livre(ifstream& _stream, string _data, int _id) : Media(_stream, _data, _id){
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
    nb_pages = stoi(_data.substr(0, pos));
    _data.erase(0, pos+1);
    pos = _data.find('#');
    collection = _data.substr(0, pos);
    _data.erase(0, pos+1);
    pos = _data.find('#');
    resume = _data.substr(0, pos);
    Media::defType("Livre");
    cout << "Ajout du Livre [ID = " << getID() << " ]" << endl;
}


Livre::Livre(string null, int _id) : Media(null, _id){

    cout << "Entrez le nombre de pages : ";
    string temp;
    getline(cin, temp);
    nb_pages = stoi(temp);

    cout << "Entrez la collection : ";
    getline(cin, collection);

    cout << "Entrez le résumé : ";
    getline(cin, resume);

    Media::defType("Livre");
}

Livre::~Livre(){
    //delete &nb_pages, &collection, &resume;
}

/*
void Livre::defCollection(string _collection){
    collection = _collection;
}

void Livre::defNb_pages(int _nb_pages){
    nb_pages = _nb_pages;
}

void Livre::defResume(string _resume){
    resume = _resume;
}

string Livre::getCollection(){
    return collection;
}

int Livre::getNb_pages(){
    return nb_pages;
}

string Livre::getResume(){
    return resume;
}
*/

void Livre::load(string _data){
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
        nb_pages = stoi(_data.substr(0, pos));
        _data.erase(0, pos+1);
        pos = _data.find('#');
        collection = _data.substr(0, pos);
        _data.erase(0, pos+1);
        pos = _data.find('#');
        resume = _data.substr(0, pos);
    }
    else{
        cout << "Le fichier est vide !" << endl;
    }
}

void Livre::save(ofstream& _stream){
    Media::save(_stream);
    _stream << nb_pages << '#' << collection << '#' << resume << '#';
}

void Livre::show(){
    Media::show();
    cout << "Nombre de page : " << nb_pages << endl;
    cout << "Collection : " << collection << endl;
    cout << "Résumé : " << resume << endl;
}