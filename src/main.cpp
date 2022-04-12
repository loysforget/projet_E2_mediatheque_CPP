#include "mediatheque.hpp"



int main()
{
    Mediatheque *ma_mediatheque = new Mediatheque;
    string buffer;

    while(true){
        cin >> buffer;
        if (buffer == "add"){
            ma_mediatheque->add();
        }
        else if ((buffer == "BYE") or (buffer == "bye")){
            delete ma_mediatheque;
            return 1;
        }
        else{
            cout << "Commande non reconnue, essayez de nouveau" << endl;
        }
    }

    return 0;
}
