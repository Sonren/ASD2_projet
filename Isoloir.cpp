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
    return persDansIsoloir.empty()
}

void Isoloir::ajouterPersonne(Personne* pers) {
    if (persDansIsoloir.size()>=nbIsoloir) {
        Isoloir::fileIsoloir.push(persIsoloir);
    } else {
        persDansIsoloir.push(pers);
    }
}

Personne* Isoloir::sortirPersonne() {
    if(estVide()) {
        throw std::runtime_error("L'Espace d'isoloir est vide");
    } else {
        Personne* pTemp = persDansIsoloir.front();//La personne à faire sortir
        Personne* pAttente;// La personne  qui attendait la place de pTemp
        persDansIsoloir.pop();
        /* Si il y a une personne en attente, on l'a fait rentrer dans l'isoloir */
        if(!fileIsoloir.empty()) {
            pAttente=fileIsoloir.front();
            fileIsoloir.pop();
            persDansIsoloir.push(pAttente);
        }
        return pTemp;
    }
}



