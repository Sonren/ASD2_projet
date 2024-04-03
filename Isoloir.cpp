/**
 * \file Isoloir.cpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include "Isoloir.hpp"
#include "Personne.hpp"
#include "Election.hpp"


Isoloir::Isoloir(const int De, const std::string& nom, int nbIsoloir) : Espace(De, nom), nbIsoloir(nbIsoloir), persDansIsoloir(*(new FileAttenteCapacite(nbIsoloir)))
{};

Isoloir::~Isoloir() {
    // Libérer les ressources acquises par l'objet persDansIsoloir
    while (!persDansIsoloir.estVide()) {
        delete persDansIsoloir.defiler(); // Supprime la personne pointée par le premier élément de la file d'attenteoverride
    }
}


bool Isoloir::estVide(){
    return persDansIsoloir.estVide() && Espace::getFile().estVide();
}

void Isoloir::ajouterPersonne(Personne* persIsoloir) {
    if (persDansIsoloir.estPleine()) {
        Espace::getFile().enfiler(persIsoloir);
    } else {
        persDansIsoloir.enfiler(persIsoloir);
    }
}

Personne* Isoloir::sortirPersonne() {
    if(estVide()) {
        throw std::runtime_error("L'Espace d'isoloir est vide");
    } else {
        Personne* pTemp = persDansIsoloir.defiler();
        return pTemp;
    }
}


void Isoloir::afficherInfos(){
        if(estVide()){
        std::cout << "l'espace est vide " << std::endl;
    }else{
        std::cout << "l'espace " << Espace::getNom() <<  " contient une personne : " << Espace::getPersonne() << std::endl ;
        std::cout << "elle doit rester : " << Espace::getDuree() << " en temps" << std::endl;
        std::cout << "Affichage de la file d'attente : " << std::endl;
        Espace::getFile().afficherFile(); 
    }
}


