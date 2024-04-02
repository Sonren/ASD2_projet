/**
 * \file Electeur.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Electeur.hpp"
#include "Bulletin.hpp"

Electeur::Electeur(const std::string& nom, const std::string& prenom, int spol,int duree)
    : Personne(nom,prenom,spol), duree_espace(duree), liste_bulletin(*(new std::vector<Bulletin*>)), choix_vote(NULL)
{};

int Electeur::getDuree(){
    return this->duree_espace;
}
    
void Electeur::steDuree(int d){
    this->duree_espace = d;
}
    
elections::Personne* Electeur::getChoix(){
    return this->choix_vote;
}
   
void Electeur::setChoix(elections::Personne* p){
    this->choix_vote = p;
}

void Electeur::ajouterBulletin(Bulletin* bult){
    this->liste_bulletin.push_back(bult);
}