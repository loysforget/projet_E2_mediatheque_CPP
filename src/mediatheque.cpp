#include "mediatheque.hpp"
#include "livre.hpp"




using namespace std;
bool Mediatheque::add(){
    string buffer;
    cout << "Format :\n" << endl;
    
    while(true){
        cin >> buffer;
        if ((buffer == "Livre") or (buffer == "livre")){
            // Appel fonction add
            Livre *new_livre = new Livre;
            new_livre -> add();
            
            return true;
        }

        else if((buffer == "Revue") or (buffer == "revue")){
            // Appel fonction add
            return true;
        }

        else if((buffer == "CD") or (buffer == "cd")){
            // Appel fonction add
            return true;
        }

        else if((buffer == "VHS") or (buffer == "vhs")){
            // Appel fonction add
            return true;
        }

        else if((buffer == "DVD") or (buffer == "dvd")){
            // Appel fonction add
            return true;
        }

        else if((buffer == "Autre") or (buffer == "autre")){
            // Appel fonction add
            return true;
        }

        else {
            cout << "Le format n'est pas reconnu, réessayez : \n" << endl;
        }  
    }  
}
