#include "cd.hpp"
//#define DEBUG
using namespace std;

bool CD::add(){
    #ifdef DEBUG
        cout << "Media::add() pour LIVRE" << endl;
    #endif
    Media::add();

    cout << "Entrez la durée du CD : " << endl;
    string temp;
    getline( cin, temp);
    duree = stoi(temp);

    cout << "Entrez le nombre de pistes : " << endl;
    string temp2;
    getline( cin, temp2);
    nb_piste = stoi(temp2);

    cout << "Entrez la maison de production : " << endl;
    getline( cin, maison_de_prod);

    return true;
}