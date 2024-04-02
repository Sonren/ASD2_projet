/**
 * \file Isoloir.cpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include "Isoloir.hpp"
#include "Personne.hpp"
#include "Election.hpp"


Isoloir::Isoloir(const int Di, const std::string& nom, int nbIsoloir) : nom(nom), Di(Di), nbIsoloir(nbIsoloir), persDansIsoloir(*(new FileAttenteCapacite(nbIsoloir)))
{};

Isoloir::~Isoloir() {
    // Libérer les ressources acquises par l'objet persDansIsoloir
    while (!persDansIsoloir.estVide()) {
        delete persDansIsoloir.defiler(); // Supprime la personne pointée par le premier élément de la file d'attenteoverride
    }

    // Libérer les ressources acquises par l'objet fileIsoloir
    while (!fileIsoloir.estVide()) {
        delete fileIsoloir.defiler(); // Supprime la personne pointée par le premier élément de la file d'attente
    }
}


bool Isoloir::estVide(){
    return persDansIsoloir.estVide() && fileIsoloir.estVide();
}

void Isoloir::ajouterPersonne(Personne* persIsoloir) {
    if (persDansIsoloir.estPleine()) {
        Isoloir::fileIsoloir.enfiler(persIsoloir);
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



