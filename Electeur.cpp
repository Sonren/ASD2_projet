/**
 * \file Electeur.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Electeur.hpp"

Electeur::Electeur(const std::string& nom, const std::string& prenom, int spol,int duree)
    : Personne(nom,prenom,spol), duree_espace(duree), liste_bulletin(*(new std::vector<Personne*>)), choix_vote(NULL)
{};

int Electeur::getDuree(){
    return duree_espace;
}
    
void Electeur::setDuree(int d){
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

void Electeur::ajouterListeBulletin(std::vector<Personne*> listeVote){
    std::vector <Personne*> ::iterator it;
    for (it = listeVote.begin() ; it != listeVote.end(); ++it){
        ajouterBulletin(*it);
    }
}

void Electeur::afficherListeBulletin(){
    
    for(std::vector <Personne*> ::iterator it = liste_bulletin.begin(); it <  liste_bulletin.end(); it++){
        std::cout <<"       "<< nom() << " prend " << *(*it) << std::endl;
    }
}
