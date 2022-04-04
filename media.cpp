#include "media.hpp"
using namespace std;

bool Media::add(){
    cout << "Entrez l'auteur : " << endl;
    getline( cin, auteur);

    cout << "Entrez le titre : " << endl;
    getline( cin, titre);

    cout << "Entrez la date de publication : " << endl;
    getline( cin, date_de_publi);

    cout << "Entrez l'ID : " << endl;
    cin >> ID;
}
