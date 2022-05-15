#include "revue.hpp"
//#define DEBUG
using namespace std;

/* STRUCTURE D'UN Revue :
Type#ID#Titre#Auteur#Date de publi#Dispo#Nb de pages#Collection#Resume#Editeur#Nb d'aritcles#
*/

Revue::Revue() : Livre(){
    editeur = "";
    nb_article = "";
    defType("Revue");
}

Revue::Revue(ifstream& _stream, string _data, int _id) : Livre(_stream, _data, _id){
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
    editeur = _data.substr(0, pos);
    _data.erase(0, pos+1);
    pos = _data.find('#');
    nb_article = _data.substr(0, pos);
    defType("Revue");
    cout << "Ajout de la Revue [ID = " << getID() << " ]" << endl;
}


Revue::Revue(string null, int _id) : Livre(null, _id){

    cout << "Entrez l'éditeur : ";
    getline(cin, collection);

    cout << "Entrez le nombre d'articles : ";
    getline(cin, resume);

    defType("Revue");
}

Revue::~Revue(){
    //delete &nb_pages, &collection, &resume;
}

/*
void Revue::defCollection(string _collection){
    collection = _collection;
}

void Revue::defNb_pages(int _nb_pages){
    nb_pages = _nb_pages;
}

void Revue::defResume(string _resume){
    resume = _resume;
}

string Revue::getCollection(){
    return collection;
}

int Revue::getNb_pages(){
    return nb_pages;
}

string Revue::getResume(){
    return resume;
}
*/

void Revue::load(string _data){
    if (_data.size() != 0){
        Livre::load(_data);
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
        _data.erase(0, pos+1);
        pos = _data.find('#');
        editeur = _data.substr(0, pos);
        _data.erase(0, pos+1);
        pos = _data.find('#');
        nb_article = _data.substr(0, pos);
    }
    else{
        cout << "Le fichier est vide !" << endl;
    }
}

void Revue::save(ofstream& _stream){
    Livre::save(_stream);
    _stream << editeur << '#' << nb_article << '#';
}

void Revue::show(){
    Livre::show();
    cout << "Éditeur : " << editeur << endl;
    cout << "Nombre d'articles : " << nb_article << endl;
}