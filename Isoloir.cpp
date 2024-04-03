/**
 * \file Isoloir.cpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include "Isoloir.hpp"
#include "Personne.hpp"
#include "Election.hpp"


Isoloir::Isoloir(const int De, const std::string& nom, int nbIsoloir) : Espace(De, nom), nbIsoloir(nbIsoloir), listeIsoloir(*(new std::queue<Personne*>))
{}

Isoloir::~Isoloir() {
    // Libérer les ressources acquises par l'objet persDansIsoloir
    while (!listeIsoloir.empty()) {
        delete listeIsoloir.front(); // Supprime la personne pointée par le premier élément de queue
        listeIsoloir.pop(); 
    }
}


bool Isoloir::estVide(){
    return listeIsoloir.empty();
}

void Isoloir::ajouterPersonne(Personne* pers) {
    if (listeIsoloir.size()>=nbIsoloir) {
        Espace::getFile().push(Espace::getPersonne());
    } else {
        listeIsoloir.push(pers);
    }
}

Personne* Isoloir::sortirPersonne() {
    if(estVide()) {
        throw std::runtime_error("L'Espace d'isoloir est vide");
    } else {
        Personne* pTemp = listeIsoloir.front();//La personne à faire sortir
        Personne* pAttente;// La personne  qui attendait la place de pTemp
        listeIsoloir.pop();
        /* Si il y a une personne en attente, on l'a fait rentrer dans l'isoloir */
        if(!Espace::getFile().empty()) {
            pAttente=Espace::getFile().front();
            Espace::getFile().pop();
            listeIsoloir.push(pAttente);
        }
        return pTemp;
    }
}


void Isoloir::afficherInfos() override{
    if(estVide()){
        std::cout << "l'espace est vide " << std::endl;
    }else{
        std::cout << "l'espace " << Espace::getNom() <<  " contient une personne : " << Espace::getPersonne() << std::endl ;
        std::cout << "elle doit rester : " << Espace::getDuree() << " en temps" << std::endl;
        std::cout << "Affichage de la premiere personne de la file d'attente : " << std::endl;
        Espace::afficherFirstQueue();
        std::cout << "coucou" << std::endl;
    }
}




