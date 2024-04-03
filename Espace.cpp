/**
 * \file Espace.hpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"
#include <queue>

Espace::Espace(const int De, const std::string& nom) : De(De), nom(nom), persoEnCours(nullptr), fileEspace(*(new std::queue<Personne*>)) 
{}

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
        fileEspace.push(persDecharge);
    }
}

Personne* Espace::sortirPersonne() {

    if(estVide()) {
        throw std::runtime_error("La Table de décharge est vide");
    } else {
        Personne* pTemp = persoEnCours;
        if(fileEspace.empty()) {
            persoEnCours = NULL;
        } else {
            persoEnCours = fileEspace.front();
            fileEspace.pop();
        }
        return pTemp;
    }
}

void Espace::afficherFirstQueue() const {
    if(!fileEspace.empty()) {
        std::cout << " Premiere personne de la file : " << *(fileEspace.front()) << std::endl;
        std::cout << "\n";
    } else {
        std::cout << "Aucune personne dans la file d'attente\n";
    }
}

void Espace::afficherInfos(){
    if(estVide()){
        std::cout << "l'espace est vide " << std::endl;
    }else{
        std::cout << "l'espace " << nom <<  " contient une personne : " << *persoEnCours << std::endl ;
        std::cout << "elle doit rester : " << De << " en temps" << std::endl;
        std::cout << "Affichage de la file d'attente : " << std::endl;
        afficherFirstQueue();
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

std::queue<Personne*> Espace::getFile(){
    return this->fileEspace;
}

void Espace::setPersonne(Personne* ptrPersonne){
    this->persoEnCours = ptrPersonne;
}