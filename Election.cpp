/**
 * \file Election.cpp
 *  \author Bertrand RIVARD Hugo Piard
*/

#include <vector>
#include <iostream>
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

void  Election::retirer_candidat(int id){//a voir pour changer pour plus rapide
    for(long unsigned int i=0; i<this->candidats.size();i++){
        if (this->candidats[i].id() == id) { 
            if (i < this->candidats.size() - 1) {
             this->candidats[i] = this->candidats.back(); //on place la personne sur la derniere place de vecteur pour pouvoir le supprimer
            }                                             //cela va permettre d'éviter de supprimer en dehors des limites du vecteur
        this->candidats.pop_back();
        }   
    }
}

bool Election::est_sur_liste(int deb, int end , int id){
    bool est_dessus = false;
    int mediane = 0;
    if(deb > end){
        std::cout << "les valeurs de début et fin sont incorrects "<< std::endl;
        return est_dessus;
    }else{
        mediane  = (end + deb)/2;
        if(id = this->candidats[mediane].id()){
            est_dessus = true;
        }else if(id < this->candidats[mediane].id()){
            est_sur_liste(deb, mediane-1, id);
        }else{
            est_sur_liste(mediane+1, end, id);
        }
    }
    return est_dessus;
}

/*bool Election::ajouter_electeur(Personne p, int deb, int end){
    bool a_été_ajouté = false;
    int mediane = 0;
    if(deb > end){
        std::cout << "les valeurs de début et fin sont incorrects "<< std::endl;
        return a_été_ajouté;
    }else{
        mediane  = (end + deb)/2;
        if(id = this->candidats[mediane].id()){
            est_dessus = true;
        }else if(id < this->candidats[mediane].id()){
            est_sur_liste(deb, mediane-1, id);
        }else{
            est_sur_liste(mediane+1, end, id);
        }
    }
}*/
