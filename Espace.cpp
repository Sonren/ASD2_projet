/**
 * \file Espace.hpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"
#include "Election.hpp"
#include <queue>

Espace::Espace(const int De, const std::string& nom, Election elec) : De(De), nom(nom), electeurEnCours(nullptr), fileEspace(*(new std::queue<Electeur*>)), election(elec) 
{}

Espace::~Espace() {
    // Libération de la mémoire allouée pour la personne actuellement dans l'espace
    if (electeurEnCours != nullptr) {
        delete electeurEnCours;
    }

    // Aucune libération de mémoire n'est nécessaire pour la file d'attente,
    // car elle se charge de libérer la mémoire de ses éléments dans son propre destructeur
}

bool Espace::estVide() {
    return electeurEnCours == NULL;
}

void Espace::ajouterElecteur(Electeur* elecDecharge) {
    if(estVide()) {
        electeurEnCours = elecDecharge;
    } else {
        // On place la personne en attente
        fileEspace.push(elecDecharge);
    }
}

Electeur* Espace::sortirElecteur() {

    if(estVide()) {
        throw std::runtime_error("La Table de décharge est vide");
    } else {
        Electeur* eTemp = electeurEnCours;
        if(fileEspace.empty()) {
            electeurEnCours = NULL;
        } else {
            electeurEnCours = fileEspace.front();
            fileEspace.pop();
        }
        return eTemp;
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
        std::cout << "l'espace " << nom <<  " contient une personne : " << *electeurEnCours << std::endl ;
        std::cout << "elle doit rester : " << De << " en temps" << std::endl;
        std::cout << "Affichage de la file d'attente : " << std::endl;
        afficherFirstQueue();
    }
}

std::string Espace::getNom(){
    return nom;
}

int Espace::getDuree(){
    return De;
}

Electeur* Espace::getElecteurEnCours(){
    return electeurEnCours;
}

std::queue<Electeur*> Espace::getFile(){
    return fileEspace;
}

void Espace::setElecteurEnCours(Electeur* ptrElecteur){
    electeurEnCours = ptrElecteur;
}

Election Espace::getElection(){
    return election;
}   

void Espace::setElection(Election e){
    election = e;
}