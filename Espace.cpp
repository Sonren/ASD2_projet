/**
 * \file Espace.hpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"

Espace::Espace(const int De, const std::string& nom) : De(De), nom(nom), persoEnCours(nullptr), fileEspace(*(new FileAttente())) {}

Espace::~Espace() {
    // Libération de la mémoire allouée pour la personne actuellement dans l'espace
    if (persoEnCours != nullptr) {
        delete persoEnCours;
    }

    // Aucune libération de mémoire n'est nécessaire pour la file d'attente,
    // car elle se charge de libérer la mémoire de ses éléments dans son propre destructeur
}

bool Espace::estVide() {
    return persoEnCours == NULL;
}

void Espace::ajouterPersonne(Personne* persDecharge) {
    if(estVide()) {
        persoEnCours = persDecharge;
    } else {
        // On place la personne en attente
        fileEspace.enfiler(persDecharge);
    }
}

Personne* Espace::sortirPersonne() {

    if(estVide()) {
        throw std::runtime_error("La Table de décharge est vide");
    } else {
        Personne* pTemp = persoEnCours;
        persoEnCours = NULL;
        return pTemp;
    }
}

void Espace::afficherInfos(){
    if(estVide()){
        std::cout << "l'espace est vide " << std::endl;
    }else{
        std::cout << "l'espace " << nom <<  " contient une personne : " << *persoEnCours << std::endl ;
        std::cout << "elle doit rester : " << De << " en temps" << std::endl;
        std::cout << "Affichage de la file d'attente : " << std::endl;
        fileEspace.afficherFile(); 
    }
}

std::string Espace::getNom(){
    return this->nom;
}

int Espace::getDuree(){
    return this->De;
}

Personne* Espace::getPersonne(){
    return this->persoEnCours;
}

FileAttente Espace::getFile(){
    return this->fileEspace;
}