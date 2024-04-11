/**
 * \file Isoloir.cpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include "Isoloir.hpp"
#include "Electeur.hpp"
#include "Election.hpp"


Isoloir::Isoloir(const int De, const std::string& nom, Election elec, int nbIsoloir) : Espace(De, nom, elec), nbIsoloir(nbIsoloir), listeIsoloir(*(new std::queue<Electeur*>))
{
    Espace::setElecteurEnCours(listeIsoloir.front());
}

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

void Isoloir::ajouterElecteur(Electeur* elec) {
    if (listeIsoloir.size()>=nbIsoloir) {
        Espace::getFile().push(Espace::getElecteurEnCours());
    } else {
        listeIsoloir.push(elec);
    }
}

Electeur* Isoloir::sortirElecteur() {
    if(estVide()) {
        throw std::runtime_error("L'Espace d'isoloir est vide");
    } else {
        Electeur* eTemp = listeIsoloir.front();//La personne à faire sortir
        Electeur* eAttente;// La personne  qui attendait la place de pTemp
        listeIsoloir.pop();
        /* Si il y a une personne en attente, on l'a fait rentrer dans l'isoloir */
        if(!Espace::getFile().empty()) {
            eAttente=Espace::getFile().front();
            Espace::getFile().pop();
            listeIsoloir.push(eAttente);
        }
        return eTemp;
    }
}


void Isoloir::afficherInfos(){
    if(estVide()){
        std::cout << "l'espace est vide " << std::endl;
    }else{
        std::cout << "l'espace " << Espace::getNom() <<  " a pour premiere personne : " << *(listeIsoloir.front()) << std::endl ;
        std::cout << "elle doit rester : " << Espace::getDuree() << " en temps" << std::endl;
        std::cout << "Affichage de la premiere personne de la file d'attente : " << std::endl;
        Espace::afficherFirstQueue();
    }
}




