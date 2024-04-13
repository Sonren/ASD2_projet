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

bool Isoloir::estPlein() {
    return listeIsoloir.size()>=nbIsoloir;
}

void Isoloir::ajouterElecteur(Electeur* elec) {
    if (estPlein()) {
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
        listeIsoloir.pop();
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

std::queue<Electeur*> Isoloir::getListeIsoloir(){
    return listeIsoloir;
}




