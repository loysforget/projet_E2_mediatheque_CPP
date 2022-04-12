#include "livre.hpp"
//#define DEBUG
using namespace std;

bool Livre::add(){
    #ifdef DEBUG
        cout << "Media::add() pour LIVRE" << endl;
    #endif
    Media::add();

    cout << "Entrez le nombre de pages : " << endl;
    string temp;
    getline(cin,temp);
    nb_pages = stoi(temp);

    cout << "Entrez la collection : " << endl;
    getline( cin, collection);

    cout << "Entrez le résumé : " << endl;
    getline( cin, resume);
}