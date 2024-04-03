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


