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
    return duree_espace;
}
    
void Electeur::steDuree(int d){
    duree_espace = d;
}
    
elections::Personne* Electeur::getChoix(){
    return choix_vote;
}
   
void Electeur::setChoix(elections::Personne* p){
    choix_vote = p;
}

void Electeur::ajouterBulletin(Personne* bult){
    liste_bulletin.push_back(bult);
}