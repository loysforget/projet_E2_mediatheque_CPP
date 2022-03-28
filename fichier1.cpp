#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Media{
    protected :
    string titre;
    string auteur;
    string date_de_publi;
    int ID;

    public :
    string titre(){
        cout << titre << endl;
        return titre;
    }

    string auteur(){
        cout << auteur << endl;
        return auteur;
    }

    string date_de_publi(){
        cout << date_de_publi << endl;
        return date_de_publi;
    }

    int show_ID(){
        cout << ID << endl;
        return ID;
    }

    void search(){

    }

    void clear(){

    }

    void save(int ID, string _filename){

    }

};

class Livres : public Media{
    protected :
    int nb_pages;
    string collection;
    string resume;

};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
