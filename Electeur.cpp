/**
 * \file Electeur.cpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include "Electeur.hpp"

// Constructeur de la classe Electeur
Electeur::Electeur(const std::string& nom, const std::string& prenom, int spol,int duree)
    : Personne(nom,prenom,spol), duree_espace(duree), liste_bulletin(*(new std::vector<Personne*>)), choix_vote(NULL)
{}

// Méthode pour obtenir la durée d'espace de l'électeur
int Electeur::getDuree(){
    return duree_espace;
}

// Méthode pour définir la durée d'espace de l'électeur
void Electeur::setDuree(int d){
    duree_espace = d;
}

// Méthode pour obtenir le choix de vote de l'électeur
elections::Personne* Electeur::getChoix(){
    return choix_vote;
}

// Méthode pour définir le choix de vote de l'électeur
void Electeur::setChoix(elections::Personne* p){
    choix_vote = p;
}

// Méthode pour ajouter un bulletin à la liste de bulletins de l'électeur
void Electeur::ajouterBulletin(Personne* bult){
    liste_bulletin.push_back(bult);
}

// Méthode pour ajouter une liste de bulletins à la liste de bulletins de l'électeur
void Electeur::ajouterListeBulletin(std::vector<Personne*> listeVote){
    std::vector <Personne*> ::iterator it;
    for (it = listeVote.begin() ; it != listeVote.end(); ++it){
        ajouterBulletin(*it);
    }
}

// Méthode pour afficher la liste de bulletins de l'électeur
void Electeur::afficherListeBulletin(){
    // Parcours de la liste de bulletins et affichage de chaque bulletin
    for(std::vector <Personne*> ::iterator it = liste_bulletin.begin(); it <  liste_bulletin.end(); it++){
        std::cout <<"       "<< nom() << " prend " << *(*it) << std::endl;
    }
}
