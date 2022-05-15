#include "media.hpp"
using namespace std;

int Media::statID = 0;

Media::Media(){
    titre = "";
    auteur = "";
    date_de_publi = "";
    dispo = "";
    ID = 0;
}

Media::Media(ifstream& _stream, string _data, int _id){
    int pos = _data.find('#');
    _data.erase(0, pos+1);
    pos = _data.find('#');
    titre = _data.substr(0, pos);
    _data.erase(0, pos+1);
    pos = _data.find('#');
    auteur = _data.substr(0, pos);
    _data.erase(0, pos+1);
    pos = _data.find('#');
    date_de_publi = _data.substr(0, pos);
    _data.erase(0, pos+1);
    pos = _data.find('#');
    dispo = _data.substr(0, pos);
    _data.erase(0, pos+1);
    statID = _id;
    ID = statID++;
}

Media::Media(string null, int _id){
    type = null;
    statID = _id;
    ID = statID++;
    dispo = "Oui";

    cout << "Entrez le titre : ";
    getline(cin, titre);

    cout <<  "Entrez l'auteur : ";
    getline(cin, auteur);

    cout << "Entrez la date de publication : ";
    getline(cin, date_de_publi);
}

Media::~Media(){
    cout << "[ID : " << ID << " ] Destruction d'un media" << endl << endl;
    //delete &type, &titre, &auteur, &date_de_publi, &dispo, &ID;
}





/* Méthodes pour définir et recupérer les informations d'un média */


void Media::defType(string _type){
    type = _type;
}

int Media::getID(){
    return ID;
}

/* Méthodes pour definir la disponibilité du média */

void Media::emprunter(){
    if (dispo == "Oui"){
        dispo = "Non";
        cout << "Emprun du média [ID = " << ID << "] confirmé." << endl;
    }
    else {
        cout << "Ce média ([ID = " << ID << "]) n'est pas disponible." << endl;
    }
}

void Media::rendre(){
    if (dispo == "Non"){
        cout << "Le média [ID = " << ID << "] a bien été retourné." << endl;
        dispo = "Oui";
    }
    else if (dispo == "Oui"){
        cout << "Erreur : Le média [ID = " << ID << "] est déjà disponible." << endl;
    }
    else {
        cout << "Le média [ID = " << ID << "] n'est plus reservé." << endl;
        dispo = "Oui";
    }
}

void Media::reserver(){
    if (dispo == "Oui"){
        cout << "Le média [ID = " << ID << "] a bien été réservé";
        dispo = "Réservé";
    }
    else {
        cout << "Ce média ([ID = " << ID << "]) n'est pas disponible.";
    }
}

void Media::save(ofstream& _stream){
    _stream << endl << type << '#' << ID << '#'<< titre << '#' << auteur << '#' << date_de_publi << '#' << dispo << '#';
}

void Media::load(string _data){
    int pos = _data.find('#');
    _data.erase(0, pos+1);
    pos = _data.find('#');
    ID = stoi(_data.substr(0, pos));
    _data.erase(0, pos+1);
    pos = _data.find('#');
    titre = _data.substr(0, pos);
    _data.erase(0, pos+1);
    pos = _data.find('#');
    auteur = _data.substr(0, pos);
    _data.erase(0, pos+1);
    pos = _data.find('#');
    date_de_publi = _data.substr(0, pos);
    _data.erase(0, pos+1);
    pos = _data.find('#');
    dispo = _data.substr(0, pos);
    _data.erase(0, pos+1);
}

void Media::list(){
    cout << "[ID = " << ID << "], Type : " << type << " Titre : " << titre << endl;
}

void Media::show(){
    cout << "Type : " << type << endl;
    cout << "[ID : " << ID << "]" << endl;
    cout << "Titre : " << titre << endl;
    cout << "Auteur : " << auteur << endl;
    cout << "Date de publication : " << date_de_publi << endl;
    cout << "Disponiblité : " << dispo << endl;
}


