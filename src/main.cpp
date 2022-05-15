#include "mediatheque.hpp"

size_t findCaseInsensitive(std::string data, std::string toSearch, size_t pos = 0)
{
    // Convert complete given String to lower case
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    // Convert complete given Sub String to lower case
    std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
    // Find sub string in given string
    return data.find(toSearch, pos);
}

int funcsearch(Mediatheque* ma_mediatheque){
    system("clear");
    string recherche;
    string commande;
    string numero_media;
    cout << "=---------------------------------------------=" << endl;
    cout << "-------------- MODE DE RECHERCHE --------------" << endl;
    cout << "=---------------------------------------------=" << endl << endl;
    cout << "Recherche : ";
    getline(cin, recherche);
    if(ma_mediatheque->search("alldata", recherche)){
        while(true){
            cout << endl << "=----- LISTE DES MÉDIAS -----=" << endl << endl;
            ma_mediatheque->listAll("searchvector");
            cout << endl << "=-----------------------------------------=" << endl;
            cout << "------ AFFINER LA RECHERCHE (search) ------" << endl;
            cout << "------ SELECTIONNER UN MEDIA (select) -----" << endl;
            cout << "---- QUITTER LE MODE RECHERCHE (clear) ----" << endl;
            cout << "=-----------------------------------------=" << endl << endl;
            while(true){
                cout << "SEARCH COMMANDE : ";
                getline(cin, commande);
                if(findCaseInsensitive("search", commande) != string::npos){
                    cout << endl << "Recherche : ";
                    recherche.clear();
                    getline(cin, recherche);
                    ma_mediatheque->search("searchvector", recherche);
                    break;
                }
                else if(findCaseInsensitive("select", commande) != string::npos){
                    cout << endl << "Sélectionner un média par son numéro : ";
                    getline(cin, numero_media);
                    if (stoi(numero_media)<ma_mediatheque->searchvector.size()){
                        commande.clear();
                        cout << "=----------------------------------------------------=" << endl;
                        cout << "------------ LES ACTIONS POSSIBLES SONT : ------------" << endl;
                        cout << "---- show, delete, emprunter, rendre, reserver ----" << endl;
                        cout << "=----------------------------------------------------=" << endl << endl;
                        if(ma_mediatheque->select_action("searchvector", stoi(numero_media))){
                            ma_mediatheque->clear();
                            return 0;
                        }
                    }
                    break;
                }
                else if(findCaseInsensitive("clear", commande) != string::npos){
                    ma_mediatheque->clear();
                    return 0;
                    
                }
                else{
                    cout << endl << "=----- Commande non reconnue, rééssayer... -----=" << endl << endl;
                }
            }
        }
        system("clear");
        cout << "=---------------------------------------------=" << endl;
        cout << "-------------- MODE DE RECHERCHE --------------" << endl;
        cout << "=---------------------------------------------=" << endl << endl;
    }
    return 1;
}

int run(){
    system("clear");
    Mediatheque *ma_mediatheque = new Mediatheque();
    string buffer_option;
    string buffer_commande;
    cout << "ROOT COMMANDE : ";
    getline(cin, buffer_commande);
    while(true){
        if (findCaseInsensitive("add", buffer_commande) != string::npos){
            system("clear");
            cout << "=----------------------------------------------=" << endl;
            cout << "--------------- OPTION DE L'AJOUT --------------" << endl;
            cout << "-------- FICHIER => À PARTIR D'UN .TXT ---------" << endl;
            cout << "----- DIRECT => INTERACTIF DANS LE TERMINAL ----" << endl;
            cout << "=----------------------------------------------=" << endl << endl;
            while(true){
                cout << "ADD COMMANDE : ";
                getline(cin, buffer_option);
                if(ma_mediatheque->add(buffer_option)){
                    break;
                }
            }
        }

        else if(findCaseInsensitive("list", buffer_commande) != string::npos){
            system("clear");
            cout << "=-----------------------------------------------------=" << endl;
            cout << "----- Affichage des élements de la bibliothèque : -----" << endl;
            cout << "=-----------------------------------------------------=" << endl << endl;
            ma_mediatheque->listAll("alldata");
        }

        else if (findCaseInsensitive("load", buffer_commande) != string::npos){
            string decision;
            system("clear");
            if (ma_mediatheque->alldata.size() != 0){
                cout << "=---------------------------------------------------------------------=" << endl;
                cout << "-------------- ATTENTION : la médiathèque n'est pas vide --------------" << endl;
                cout << "----- Si vous continuez sans sauvegarder les médias seront perdus -----" << endl;
                cout << "----------------- Voulez vous sauvegarder ? (oui/non) -----------------" << endl;
                cout << "=---------------------------------------------------------------------=" << endl << endl;
                cout << "Décision :";
                getline(cin, decision);
                if (decision.find("oui") != string::npos){
                    string filename;
                    cout << endl << "Entrer un nom de fichier de sauvegarde : ";
                    getline(cin, filename);
                    for (int i = 0; i<ma_mediatheque->alldata.size(); i++){
                        ma_mediatheque->save("alldata", filename);
                    }
                    cout << "La sauvegarde est terminée !" << endl << endl;
                }
            }
            string filename;
            ma_mediatheque->reset();
            cout << "Entrer le nom du fichier à charger : ";
            getline(cin, filename);
            ma_mediatheque->load("alldata", filename);
        }

        else if(findCaseInsensitive("reset", buffer_commande) != string::npos){
            ma_mediatheque->reset();
        }
        

        else if (findCaseInsensitive("search", buffer_commande) != string::npos){
            funcsearch(ma_mediatheque);
        }

        else if (findCaseInsensitive("save", buffer_commande) != string::npos){
            string _filename;
            cout << endl << "Nom du fichier de sauvegarde : ";
            getline(cin, _filename);
            ma_mediatheque->save("alldata", _filename);
            cout << endl << "=----- Sauvegarde de la médiathèque dans" << _filename << " terminée ! -----=" <<endl;
        }


        else if (findCaseInsensitive("bye", buffer_commande) != string::npos){
                delete ma_mediatheque;
                system("clear");
                cout << "=---- Au revoir ! ----=" << endl;
            return 1;
        }

        else{
            cout << "=---- Commande non reconnue, essayez de nouveau... ----=" << endl;
        }

        cout << endl << "ROOT COMMANDE : ";
        getline(cin, buffer_commande);
        
    }

    return 0;
}

int main()
{   
    system("clear");
    string enter;
    cout << "=-----------------------------------------------------------------------=" << endl;
    cout << "----- Projet de programation C++ PG208 : Gestion d'une bibliothèque -----" << endl;
    cout << "------------------- Par Loys FORGET & Martin CASSANY --------------------" << endl;
    cout << "------------- APPUYER SUR ENTRER POUR LANCER LA MÉDIATHÈQUE -------------" << endl;
    cout << "=-----------------------------------------------------------------------=" << endl;
    getline(cin, enter);
    if (enter.find("") != string::npos){
        run();
    }
    return 1;
}
