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
    }
    if (liste_electorale.empty() == true){
            std::cout << "le vecteur est vide " << std::endl;
            return est_dessus;
    }
    mediane  = (end + deb)/2;
    if((*p).id() == (*(liste_electorale[mediane])).id()){
        std::cout << "trouvé! " << liste_electorale[mediane]->id() << " " << liste_electorale[mediane]->nom() << " " << liste_electorale[mediane]->prenom() << std::endl;
        return est_dessus = true;
    }else if(cmp.operator()(p, liste_electorale[mediane]) == true){
        est_sur_liste(deb, mediane-1, p);
    }else{
        est_sur_liste(mediane+1, end, p);
    }
}
/**
 * @brief  Cette fonction sert à ajouter un nouvel électeur à la liste électorale dans une plage spécifiée ([deb, end])
 *         et dans l'ordre alphabétique selon le nom de l'électeur (utilisant le comparateur CompAlpha).
 *         Si la plage n'est pas valide ou que la personne existe déjà dans la liste, la fonction ne l'ajoutera pas.
 *
 * @param deb: La valeur de début de la plage de recherche dans la liste.
 * @param end: La valeur de fin de la plage de recherche dans la liste.
 * @param p: Un pointeur vers l'objet Personne à ajouter à la liste.
 *
 * @return true si l'électeur a été ajouté avec succès, false sinon.
 */
bool Election::ajouter_electeur( int deb, int end, Personne* p){
    Personne::CompAlpha  cmp;
    bool a_été_ajouté;
    int mediane;
    std::cout << "coucou" << std::endl;
    if(deb > end){
        std::cout << "les valeurs de début et fin sont incorrects "<< std::endl;
        return a_été_ajouté = false;
    }
    if (liste_electorale.empty() == true){
        // Si la liste est vide, ajouter la personne à la liste
        liste_electorale.push_back(p);
        return a_été_ajouté = true;
    }
    mediane  = (end + deb)/2; // Calculer l'indice médian de la plage de recherche
    if(cmp.operator()(p, liste_electorale[mediane]) == true){
        if(mediane == deb){
            liste_electorale.insert(liste_electorale.begin(), p);
            std::cout << "l'electeur a été ajouté avec succès " << std::endl;
            return a_été_ajouté = true;
        }
        if((cmp.operator()(p,liste_electorale[mediane-1]) == false)){
            liste_electorale.insert(liste_electorale.begin() + mediane-1, p);
            std::cout << "l'electeur a été ajouté avec succès " << std::endl;
            return a_été_ajouté = true;
        }else{
            // Recherche de manière récursive la première moitié de la liste.
            ajouter_electeur(deb, mediane - 1 , p);
        }
    }else if(cmp.operator()(p,liste_electorale[mediane]) == false){
            if (mediane == end){
                liste_electorale.insert(liste_electorale.begin() + mediane+1, p);
                std::cout << "l'electeur a été ajouté avec succès " << std::endl;
                return a_été_ajouté = true;
            }
            if(cmp.operator()(p,liste_electorale[mediane+1]) == true  || (mediane == end)){
                liste_electorale.insert(liste_electorale.begin() + mediane+1, p);
                std::cout << "l'electeur a été ajouté avec succès " << std::endl;
                return a_été_ajouté = true;
            }else{
                // Recherche de manière récursive la deuxième moitié de la liste.
                ajouter_electeur(mediane+1, end, p);
            }
    }
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


