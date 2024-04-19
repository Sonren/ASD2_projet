/**
 * \file Isoloir.cpp
 * \author Bertrand RIVARD Hugo PIARD
 */

#include "Isoloir.hpp"
#include "Electeur.hpp"
#include "Election.hpp"

// Constructeur de la classe Isoloir
Isoloir::Isoloir(const int De, const std::string& nom, Election elec, int nbIsoloir) : Espace(De, nom, elec), nbIsoloir(nbIsoloir), listeIsoloir(*(new std::queue<Electeur*>))
{
    Espace::setElecteurEnCours(listeIsoloir.front()); // Définit le premier électeur dans l'isoloir comme l'électeur en cours dans l'espace
}

// Destructeur de la classe Isoloir
Isoloir::~Isoloir() {
    // Libération de la mémoire allouée pour les électeurs dans l'isoloir
    while (!listeIsoloir.empty()) {
        delete listeIsoloir.front(); // Supprime la personne pointée par le premier élément de la file
        listeIsoloir.pop(); 
    }
}

// Vérifie si l'isoloir est vide
bool Isoloir::estVide(){
    return listeIsoloir.empty();
}

// Vérifie si l'isoloir est plein
bool Isoloir::estPlein() {
    return listeIsoloir.size() >= nbIsoloir;
}

// Ajoute un électeur à l'isoloir
void Isoloir::ajouterElecteur(Electeur* elec) {
    if (estPlein()) {
        Espace::getFile().push(Espace::getElecteurEnCours()); // Ajoute l'électeur en cours dans la file d'attente de l'espace
    } else {
        elec->setDuree(Espace::getDuree());
        listeIsoloir.push(elec); // Ajoute l'électeur à la file de l'isoloir
    }
}

// Retire un électeur de l'isoloir et le retourne
Electeur* Isoloir::sortirElecteur() {
    if(estVide()) {
        throw std::runtime_error("L'Espace d'isoloir est vide");
    } else {
        Electeur* eTemp = listeIsoloir.front(); // Stocke l'électeur à faire sortir
        listeIsoloir.pop(); // Retire l'électeur de la file
        return eTemp;
    }
}

// Affiche les informations sur l'isoloir
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

// Getter pour obtenir la liste des électeurs dans l'isoloir
std::queue<Electeur*> Isoloir::getListeIsoloir(){
    return listeIsoloir;
}
