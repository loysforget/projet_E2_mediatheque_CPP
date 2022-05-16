#include "mediatheque.hpp"
#include "livre.hpp"
#include "revue.hpp"
#include "cd.hpp"
#include "vhs.hpp"
#include "dvd.hpp"
#include "numerique.hpp"

using namespace std;

size_t Mediatheque::findCaseInsensitive(std::string data, std::string toSearch, size_t pos = 0)
{
    // Convert complete given String to lower case
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    // Convert complete given Sub String to lower case
    std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
    // Find sub string in given string
    return data.find(toSearch, pos);
}

Mediatheque::Mediatheque(){
    string yorn;
    string filename;
    cout << "=------------------------------------=" << endl;
    cout << "----- Création de la médiathèque -----" << endl;
    cout << "=------------------------------------=" << endl << endl;
    cout << "INITIALISATION : Il est possible d'importer une médiathèque ou de commencer une vierge " << endl;
    cout << "Voulez-vous LOAD un fichier ~Archive~ ? (oui/non) : ";
    getline(cin, yorn);
    if (yorn.find("oui") != string::npos){
        cout << endl << "Entrer le nom du fichier : ";
        getline(cin, filename);
        this->load("alldata", filename);
    }
}

Mediatheque::~Mediatheque(){
    save("alldata", "backup.txt");
    for (int i = 0; i < alldata.size(); i++)
    {   
        delete alldata[i]; //fonction reset !!!
    }
    
}

bool Mediatheque::save(string _vector, string _filename){
    ofstream stream;
    stream.open(_filename);
    stream << "=----- SAUVEGARDE DE LA MÉDIATHÈQUE -----=";
    if(_vector.find("alldata") != string::npos){
        for (int i = 0; i < alldata.size(); i++)
        {   
            alldata[i]->save(stream);
        }
        return true;
    }
    else if(_vector.find("searchvector") != string::npos){
        for (int i = 0; i < searchvector.size(); i++)
        {   
            searchvector[i]->save(stream);
        }
        return true;
    }
    stream.close();
    return false;
}

void Mediatheque::reset(){
    //FONCTION DE DELETE LES ELEMENTS !!
    alldata.clear();
    cout << "=---- La médiathèque a bien été réinitialisée ----=" << endl << endl;
}

bool Mediatheque::add(string _option){
    if(_option.find("fichier") != string::npos){
        string _filename;
        string line;
        cout << "Entrer le nom du fichier : ";
        getline(cin, _filename);
        ifstream stream(_filename.c_str());
        while(getline(stream, line)){
            if (line.size() != 0){
                if (line.substr(0,1) == "L"){
                    Livre* _livre_ = new Livre(stream, line, alldata.size()+1);
                    cout << "Ajout du Livre avec l'ID = " << _livre_->getID() << endl;
                    alldata.push_back(_livre_);
                }
                else if(line.substr(0,1) == "R"){
                    Revue* _revue_ = new Revue(stream, line, alldata.size()+1);
                    cout << "Ajout de la Revue avec l'ID = " << _revue_->getID() << endl;
                    alldata.push_back(_revue_);
                }
                else if(line.substr(0,1) == "C"){
                    Cd* _cd_ = new Cd(stream, line, alldata.size()+1);
                    cout << "Ajout du CD avec l'ID = " << _cd_->getID() << endl;
                    alldata.push_back(_cd_);
                }
                else if(line.substr(0,1) == "V"){
                    Vhs* _vhs_ = new Vhs(stream, line, alldata.size()+1);
                    cout << "Ajout de la VHS avec l'ID = " << _vhs_->getID() << endl;
                    alldata.push_back(_vhs_);
                }
                else if(line.substr(0,1) == "D"){
                    Dvd* _dvd_ = new Dvd(stream, line, alldata.size()+1);
                    cout << "Ajout du DVD avec l'ID = " << _dvd_->getID() << endl;
                    alldata.push_back(_dvd_);
                }
                else if(line.substr(0,1) == "N"){
                    Numerique* _num_ = new Numerique(stream, line, alldata.size()+1);
                    cout << "Ajout de la ressource numérique avec l'ID = " << _num_->getID() << endl;
                    alldata.push_back(_num_);
                }
                else{
                    continue;
                }
            }
            else {
                cout << "ERREUR : La ligne de donnée est vide !" << endl << endl;
                continue;
            }
        }
        stream.close();
        return true;
    }
    else if(_option.find("direct") != string::npos){
        string _type;
        while(true){
            cout << "Entrer le type : ";
            getline(cin, _type);
            if (findCaseInsensitive("Livre", _type) != string::npos){
                Livre* _livre_ = new Livre("Livre", alldata.size());
                cout << "Ajout du Livre avec l'ID = " << _livre_->getID() << endl;
                alldata.push_back(_livre_);
                break;
            }
            else if(findCaseInsensitive("revue", _type) != string::npos){
                Revue* _revue_ = new Revue("Revue", alldata.size());
                cout << "Ajout de la Revue avec l'ID = " << _revue_->getID() << endl;
                alldata.push_back(_revue_);
                break;
            }
            else if(findCaseInsensitive("cd", _type) != string::npos){
                Cd* _cd_ = new Cd("Cd", alldata.size());
                cout << "Ajout du CD avec l'ID = " << _cd_->getID() << endl;
                alldata.push_back(_cd_);
                break;
            }
            else if(findCaseInsensitive("vhs", _type) != string::npos){
                Vhs* _vhs_ = new Vhs("Vhs", alldata.size());
                cout << "Ajout de la VHS avec l'ID = " << _vhs_->getID() << endl;
                alldata.push_back(_vhs_);
                break;
            }
            else if(findCaseInsensitive("dvd", _type) != string::npos){
                Dvd* _dvd_ = new Dvd("Livre", alldata.size());
                cout << "Ajout du DVD avec l'ID = " << _dvd_->getID() << endl;
                alldata.push_back(_dvd_);
                break;
            }
            else if(findCaseInsensitive("numerique", _type) != string::npos){
                Numerique* _numerique_ = new Numerique("Numerique", alldata.size());
                cout << "Ajout de la ressource numérique avec l'ID = " << _numerique_->getID() << endl;
                alldata.push_back(_numerique_);
                break;
            }
            else if(findCaseInsensitive("annuler", _type) != string::npos){
                cout << "=---- L'opération de l'ajout est annulé, retour au menu principal... ----=" << endl << endl;
                break;
            }
            else {
                cout << "ERREUR : Le type n'est pas reconnu !" <<endl;
            }
        }
        return true;
    }
    else {
        cout << "=---- L'opération n'est pas reconnu, rééssayer... ----=" << endl;
        return false;
    }
}

void Mediatheque::listAll(string _vector){
    if(_vector.find("alldata") != string::npos){
        for (int i = 0; i < alldata.size(); i++){
            cout << "Média nº " << i <<" : ";
            alldata[i]->list();
        }
        cout << endl << "Fin de la liste" << endl << endl;
    }
    else if(_vector.find("searchvector") != string::npos){
        for (int i = 0; i < searchvector.size(); i++){
            cout << "Média nº " << i <<" : ";
            searchvector[i]->list();
        }
        cout << endl << "=---- Fin de la liste ----=" << endl << endl;
    }
}

void Mediatheque::showAll(string _vector){
    if(_vector.find("alldata") != string::npos){
        for (int i = 0; i < alldata.size(); i++){
            cout << "Média nº " << i <<" : ";
            alldata[i]->show();
        }
        cout << endl << "Fin de la liste" << endl;
    }
    else if(_vector.find("searchvector") != string::npos){
        for (int i = 0; i < searchvector.size(); i++){
            cout << "Média nº " << i <<" : ";
            searchvector[i]->show();
        }
        cout << endl << "Fin de la liste" << endl;
    }
}

void Mediatheque::load(string _vector, string _filename){
    string null;
    ifstream stream(_filename.c_str());
    getline(stream, null);
    while(getline(stream, null)){
        if (null.size() != 0){
            if (null.substr(0,1) == "L"){
                Livre* _livre_ = new Livre();
                _livre_->load(null);
                if(_vector.find("alldata") != string::npos){
                    alldata.push_back(_livre_);
                }
                else if(_vector.find("searchvector") != string::npos){
                    searchvector.push_back(_livre_);
                }
            }
            else if(null.substr(0,1) == "R"){
                Revue* _revue_ = new Revue();
                _revue_->load(null);
                if(_vector.find("alldata") != string::npos){
                    alldata.push_back(_revue_);
                }
                else if(_vector.find("searchvector") != string::npos){
                    searchvector.push_back(_revue_);
                }
            }
            else if(null.substr(0,1) == "C"){
                Cd* _cd_ = new Cd();
                _cd_->load(null);
                if(_vector.find("alldata") != string::npos){
                    alldata.push_back(_cd_);
                }
                else if(_vector.find("searchvector") != string::npos){
                    searchvector.push_back(_cd_);
                }
            }
            else if(null.substr(0,1) == "V"){
                Vhs* _vhs_ = new Vhs();
                _vhs_->load(null);
                if(_vector.find("alldata") != string::npos){
                    alldata.push_back(_vhs_);
                }
                else if(_vector.find("searchvector") != string::npos){
                    searchvector.push_back(_vhs_);
                }
            }
            else if(null.substr(0,1) == "D"){
                Dvd* _dvd_ = new Dvd();
                _dvd_->load(null);
                if(_vector.find("alldata") != string::npos){
                    alldata.push_back(_dvd_);
                }
                else if(_vector.find("searchvector") != string::npos){
                    searchvector.push_back(_dvd_);
                }
            }
            else if(null.substr(0,1) == "N"){
                Numerique* _num_ = new Numerique();
                _num_->load(null);
                if(_vector.find("alldata") != string::npos){
                    alldata.push_back(_num_);
                }
                else if(_vector.find("searchvector") != string::npos){
                    searchvector.push_back(_num_);
                }
            }
            else{
                continue;
            } 
        }
        else {
            cout << "ERREUR : La ligne de donnée est vide !" << endl << endl;
            continue;
        }
    }
    cout << endl << "=----- Initialisation des médias terminée ! -----=" << endl << endl;   
    stream.close(); 
}

bool Mediatheque::select_action(string _vecteur, int _num_media){
    string _action;
    int _id = searchvector[_num_media]->getID();
    Media* _le_media;
    int i;
    for (i=0; i<alldata.size(); i++){
        if(alldata[i]->getID() == _id){
            break;
        }
    }
    while(true){
        cout << "Action : ";
        getline(cin, _action);
        if(findCaseInsensitive("show", _action) != string::npos){
        alldata[i]->show();
        return true;
        }
        else if(findCaseInsensitive("delete", _action) != string::npos){
            alldata.erase(alldata.begin()+i);
            cout << endl << "=---- Média supprimé ! ----=" << endl;
            return true;
        }
        else if(findCaseInsensitive("emprunter", _action) != string::npos){
            alldata[i]->emprunter();
            break;
        }
        else if(findCaseInsensitive("rendre", _action) != string::npos){
            alldata[i]->rendre();
            break;
        }
        else if(findCaseInsensitive("reserver", _action) != string::npos){
            alldata[i]->reserver();
            break;
        }
        else{
            cout << endl << "=----- Commande non reconnue, rééssayer... -----=" << endl << endl;
        }
    }
    
    return false;
}

void Mediatheque::clear(){
    searchvector.clear();
    std::ofstream ofs;
    ofs.open("data_search.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

bool Mediatheque::search(string _vector, string _searching){
    string line;
    int flag = 0;
    if(_vector.find("alldata") != string::npos){
        save("alldata", "data_search.txt");
    }
    else if(_vector.find("searchvector") != string::npos){
        save("searchvector", "data_search.txt");
        searchvector.clear();
    }

    ifstream _inStreamSearch;
    _inStreamSearch.open("data_search.txt");
    while(getline(_inStreamSearch, line)){
        if(findCaseInsensitive(line, _searching) != string::npos){
            flag = 1;
            if (line.substr(0,1) == "L"){
                Livre* _livre_ = new Livre();
                _livre_->load(line);
                searchvector.push_back(_livre_);
            }
            else if (line.substr(0,1) == "R"){
                Revue* _revue_ = new Revue();
                _revue_->load(line);
                searchvector.push_back(_revue_);
            }
            else if (line.substr(0,1) == "C"){
                Cd* _cd_ = new Cd();
                _cd_->load(line);
                searchvector.push_back(_cd_);
            }
            else if (line.substr(0,1) == "V"){
                Vhs* _vhs_ = new Vhs();
                _vhs_->load(line);
                searchvector.push_back(_vhs_);
            }
            else if (line.substr(0,1) == "D"){
                Dvd* _dvd_ = new Dvd();
                _dvd_->load(line);
                searchvector.push_back(_dvd_);
            }
            else if (line.substr(0,1) == "N"){
                Numerique* _num_ = new Numerique();
                _num_->load(line);
                searchvector.push_back(_num_);
            }
            
        }
    }
    if (flag==1){
        cout << endl << "=---- Des éléments ont été trouvés ! ----=" << endl << endl;
        save("searchvector", "data_search.txt");
        return true;
    }
    else {
        cout << endl << "=---- Aucun éléments ne correspond à votre recherche... ----=" << endl << endl;
        return false;
    }
    _inStreamSearch.close();
}
