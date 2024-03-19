/**
 * \file Election.cpp
 *  \author Bertrand RIVARD Hugo Piard
*/

#include <vector>
#include "Election.hpp"

Election::Election(const std::string& nom){
    this->nom_election = nom;
    this->candidats = std::vector<Personne>();
}

Election::Election(const std::string& nom, std::vector <Personne> liste_candidat){
    this->nom_election = nom;
    this->candidats = liste_candidat;
}

Election::~Election(){
    this->candidats.clear();
}

std::string Election::getNom() const {
    return nom_election;
}

void Election::setNom(std::string new_nom){
    this->nom_election = new_nom;
}

void Election::ajouter_candidat(Personne p){
    this->candidats.push_back(p);
}

Personne Election::retirer_candidat(int id){//a voir pour changer pour plus rapide
    for(int i=0; i<this->candidats.size();i++){
        if (this->candidats[i].id() == id) { 
            if (i < this->candidats.size() - 1) {
             this->candidats[i] = this->candidats.back(); //on place la personne sur la derniere place de vecteur pour pouvoir le supprimer
            }                                             //cela va permettre d'éviter de supprimer en dehors des limites du vecteur
        this->candidats.pop_back();
        }   
    }
}

