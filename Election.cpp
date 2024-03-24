/**
 * \file Election.cpp
 *  \author Bertrand RIVARD Hugo Piard
*/

#include <vector>
#include <iostream>
#include "Election.hpp"
#include "Personne.hpp"

Election::Election(const std::string& nom){
    this->nom_election = nom;
    this->candidats = std::vector<Personne*>();
}

Election::Election(const std::string& nom, std::vector <Personne*> liste_candidat){
    this->nom_election = nom;
    this->candidats = liste_candidat;
}

Election::Election(const std::string& nom, std::vector <Personne*> liste_candidat, std::vector <Personne*> liste_electeur){
    this->nom_election = nom;
    this->candidats = liste_candidat;
    this->liste_electorale = liste_electeur;
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

void Election::ajouter_candidat(Personne* p){
    this->candidats.push_back(p);
}

void  Election::retirer_candidat(int id){//a voir pour changer pour plus rapide
    for(long unsigned int i=0; i<this->candidats.size();i++){
        if ((*(candidats[i])).id() == id) { 
            if (i < this->candidats.size() - 1) {
             this->candidats[i] = this->candidats.back(); //on place la personne sur la derniere place de vecteur pour pouvoir le supprimer
            }                                             //cela va permettre d'éviter de supprimer en dehors des limites du vecteur
        this->candidats.pop_back();
        }   
    }
}

bool Election::est_sur_liste(int deb, int end , Personne* p){
    Personne::CompAlpha cmp;
    bool est_dessus = false;
    int mediane;
    if(deb > end){
        std::cout << "les valeurs de début et fin sont incorrects "<< std::endl;
        return est_dessus;
    }else{
        mediane  = (end + deb)/2;
        if((*p).id() == (*(liste_electorale[mediane])).id()){
            std::cout << "trouvé! " << liste_electorale[mediane]->id() << " " << liste_electorale[mediane]->nom() << " " << liste_electorale[mediane]->prenom() << std::endl;
            est_dessus = true;
            return est_dessus;
        }else if(cmp.operator()(p, liste_electorale[mediane]) == true){
            est_sur_liste(deb, mediane-1, p);
        }else{
            est_sur_liste(mediane+1, end, p);
        }
    }
}

bool Election::ajouter_electeur( int deb, int end, Personne* p){
    Personne::CompAlpha  cmp;
    bool a_été_ajouté = false;
    int mediane;
    std::cout << "coucou" << std::endl;
    if(deb > end){
        std::cout << "les valeurs de début et fin sont incorrects "<< std::endl;
        return a_été_ajouté;
    }else{
        mediane  = (end + deb)/2;
        if(mediane == end){
            liste_electorale.insert(liste_electorale.begin() + end+1, p); 
            std::cout << "l'electeur a été ajouté avec succès " << std::endl;
            a_été_ajouté = true;
            return a_été_ajouté;
        }
        if(((cmp.operator()(p, liste_electorale[mediane]) == true && cmp.operator()(liste_electorale[mediane], p) == false)) || (cmp.operator()(p,liste_electorale[mediane]) == false && cmp.operator()(liste_electorale[mediane], p) == false)){
            liste_electorale.insert(liste_electorale.begin() + mediane-1, p); 
            std::cout << "l'electeur a été ajouté avec succès " << std::endl;
            a_été_ajouté = true;
            return a_été_ajouté;
        }else if(cmp.operator()(p, liste_electorale[mediane]) == true){
            ajouter_electeur(deb, mediane-1, p);
        }else{
            ajouter_electeur(mediane+1, end, p);
        }
    }
    return a_été_ajouté;
}


void Election::afficher_candidat(){
    for(long unsigned int i = 0; i<this->candidats.size(); i++){
        std::cout << (*this->candidats[i]) << std::endl;
    }
    std::cout << std::endl;
}

void Election::afficher_electeur(){
    for(long unsigned int i = 0; i<this->liste_electorale.size(); i++){
        std::cout << (*this->liste_electorale[i]) << std::endl;
    }
    std::cout << std::endl;
}
