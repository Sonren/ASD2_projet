/**
 * \file Espace.hpp
 * \author Bertrand RIVARD Hugo PIARD
 */

#include "Espace.hpp"
#include "Election.hpp"
#include <queue>

// Constructeur de la classe Espace
Espace::Espace(const int De, const std::string& nom, Election elec) : De(De), nom(nom), electeurEnCours(nullptr), fileEspace(*(new std::queue<Electeur*>)), election(elec) 
{}

// Destructeur de la classe Espace
Espace::~Espace() {
    // Libération de la mémoire allouée pour la personne actuellement dans l'espace
    if (electeurEnCours != nullptr) {
        delete electeurEnCours;
    }

    // Aucune libération de mémoire n'est nécessaire pour la file d'attente,
    // car elle se charge de libérer la mémoire de ses éléments dans son propre destructeur
}

// Vérifie si l'espace est vide
bool Espace::estVide() {
    return electeurEnCours == NULL;
}

// Ajoute un électeur à l'espace
void Espace::ajouterElecteur(Electeur* elecDecharge) {
    if(estVide()) {
        electeurEnCours = elecDecharge;
        elecDecharge->setDuree(De);
    } else {
        // On place la personne en attente dans la file d'attente
        fileEspace.push(elecDecharge);
        elecDecharge->setDuree(De);
    }
}

// Retire un électeur de l'espace et le retourne
Electeur* Espace::sortirElecteur() {

    if(estVide()) {
        throw std::runtime_error("L'espace est vide");
    } else {
        Electeur* eTemp = electeurEnCours;
        electeurEnCours = NULL;
        return eTemp;
    }
}

// Affiche le premier électeur dans la file d'attente
void Espace::afficherFirstQueue() const {
    if(!fileEspace.empty()) {
        std::cout << " Première personne de la file : " << *(fileEspace.front()) << std::endl;
        std::cout << "\n";
    } else {
        std::cout << "Aucune personne dans la file d'attente\n";
    }
}

// Affiche les informations sur l'espace
void Espace::afficherInfos(){
    if(estVide()){
        std::cout << nom << " : l'espace est vide " << std::endl;
    }else{
        std::cout << "L'espace " << nom <<  " contient une personne : " << *electeurEnCours << std::endl ;
        std::cout << "Elle doit rester : " << De << " en temps" << std::endl;
        std::cout << "Affichage de la file d'attente : " << std::endl;
        afficherFirstQueue();
    }
}

// Getter pour obtenir le nom de l'espace
std::string Espace::getNom(){
    return nom;
}

// Getter pour obtenir la durée de séjour dans l'espace
int Espace::getDuree(){
    return De;
}

// Getter pour obtenir l'électeur actuellement dans l'espace
Electeur* Espace::getElecteurEnCours(){
    return electeurEnCours;
}

// Getter pour obtenir la file d'attente de l'espace
std::queue<Electeur*> Espace::getFile(){
    return fileEspace;
}

// Setter pour définir l'électeur actuellement dans l'espace
void Espace::setElecteurEnCours(Electeur* ptrElecteur){
    electeurEnCours = ptrElecteur;
}

// Getter pour obtenir l'élection associée à l'espace
Election Espace::getElection(){
    return election;
}   

// Setter pour définir l'élection associée à l'espace
void Espace::setElection(Election e){
    election = e;
}

// Setter pour définir la file d'attente de l'espace
void Espace::setFileEspace(Electeur* e){
    fileEspace.push(e);
}

// Retire et retourne le premier électeur de la file d'attente de l'espace
Electeur* Espace::popFileEspace(){
    Electeur* temp = fileEspace.front(); 
    fileEspace.pop();
    return temp;
}
