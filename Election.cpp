/**
 * \file Election.cpp
 *  \author Bertrand RIVARD Hugo Piard
*/

#include <vector>
#include <iostream>
#include "Election.hpp"
#include "Personne.hpp"

Election::Election(const std::string& nom){
    nom_election = nom;
    candidats = std::vector<Personne*>();
    bulletin_blanc = NULL;
}

Election::Election(const std::string& nom, std::vector <Personne*> liste_candidat){
    nom_election = nom;
    candidats = liste_candidat;
    bulletin_blanc = NULL;
}

Election::Election(const std::string& nom, std::vector <Personne*> liste_candidat, std::vector <Electeur*> liste_electeur){
    nom_election = nom;
    candidats = liste_candidat;
    liste_electorale = liste_electeur;
    bulletin_blanc = NULL;
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

std::vector<Personne*>  Election::getListeCandidats(){
    return this->candidats;
}

void Election::setBulletinBlanc(Personne* personneBlanc){
    bulletin_blanc = personneBlanc;
}

Personne* Election::getBulletinBlanc(){
    return bulletin_blanc;
}

void Election::ajouter_candidat(int deb, int end, Personne* p){
    // Comparateur pour la comparaison alphabétique
    Personne::CompAlpha cmp;
    
    bool a_été_ajouté; // Variable pour indiquer si l'électeur a été ajouté avec succès
    int mediane; // Indice médian de la plage de recherche
        
    // Vérification des bornes de recherche
    if (deb > end) {
        std::cout << "les valeurs de début et fin sont incorrects " << std::endl;
        return a_été_ajouté = false; // Retourne false si les bornes sont incorrectes
    }
    
    // Cas de base : Liste vide
    if (candidats.empty()) {
        candidats.push_back(p); // Ajoute la personne à la liste
        return a_été_ajouté = true; // Retourne true car l'électeur a été ajouté
    }
    
    // Calcul de l'indice médian
    mediane = (end + deb) / 2;
    
    // Comparaison avec l'élément médian de la liste
    if (cmp.operator()(p, candidats[mediane])) { // Si la personne est "inférieure" à l'élément médian
        // Cas où la personne doit être insérée avant l'élément médian
        if (mediane == deb) {
            candidats.insert(candidats.begin(), p); // Insère la personne au début de la liste
            std::cout << "le candidat a été ajouté avec succès " << std::endl;
            return a_été_ajouté = true;
        }
        if (!cmp.operator()(p, candidats[mediane - 1])) {
            candidats.insert(candidats.begin() + mediane - 1, p); // Insère la personne à l'indice médian - 1
            std::cout << "le candidat a été ajouté avec succès " << std::endl;
            return a_été_ajouté = true;
        } else {
            // Recherche récursive dans la première moitié de la liste
            ajouter_candidat(deb, mediane - 1, p);
        }
    } else { // Si la personne est "supérieure" à l'élément médian
        // Cas où la personne doit être insérée après l'élément médian
        if (mediane == end) {
            candidats.insert(candidats.begin() + mediane + 1, p); // Insère la personne à la fin de la liste
            std::cout << "le candidat a été ajouté avec succès " << std::endl;
            return a_été_ajouté = true;
        }
        if (!cmp.operator()(p, candidats[mediane + 1]) || mediane == end) {
            candidats.insert(candidats.begin() + mediane + 1, p); // Insère la personne à l'indice médian + 1
            std::cout << "le candidat a été ajouté avec succès " << std::endl;
            return a_été_ajouté = true;
        } else {
            // Recherche récursive dans la deuxième moitié de la liste
            ajouter_candidat(mediane + 1, end, p);
        }
    }
}



void  Election::retirer_candidat(int id){
    for(long unsigned int i=0; i<this->candidats.size();i++){
        if ((*(candidats[i])).id() == id) { 
            if (i < this->candidats.size() - 1) {
             this->candidats[i] = this->candidats.back(); //on place la personne sur la derniere place de vecteur pour pouvoir le supprimer
            }                                             //cela va permettre d'éviter de supprimer en dehors des limites du vecteur
        this->candidats.pop_back();
        }   
    }
}

bool Election::est_sur_liste(int deb, int end , Electeur* p){
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
// Fonction pour ajouter un électeur dans la liste électorale
bool Election::ajouter_electeur(int deb, int end, Electeur* e) {
    // Comparateur pour la comparaison alphabétique
    Personne::CompAlpha cmp;
    
    bool a_été_ajouté; // Variable pour indiquer si l'électeur a été ajouté avec succès
    int mediane; // Indice médian de la plage de recherche
        
    // Vérification des bornes de recherche
    if (deb > end) {
        std::cout << "les valeurs de début et fin sont incorrects " << std::endl;
        return a_été_ajouté = false; // Retourne false si les bornes sont incorrectes
    }
    
    // Cas de base : Liste vide
    if (liste_electorale.empty()) {
        liste_electorale.push_back(p); // Ajoute la personne à la liste
        return a_été_ajouté = true; // Retourne true car l'électeur a été ajouté
    }
    
    // Calcul de l'indice médian
    mediane = (end + deb) / 2;
    
    // Comparaison avec l'élément médian de la liste
    if (cmp.operator()(p, liste_electorale[mediane])) { // Si la personne est "inférieure" à l'élément médian
        // Cas où la personne doit être insérée avant l'élément médian
        if (mediane == deb) {
            liste_electorale.insert(liste_electorale.begin(), p); // Insère la personne au début de la liste
            std::cout << "l'electeur a été ajouté avec succès " << std::endl;
            return a_été_ajouté = true;
        }
        if (!cmp.operator()(p, liste_electorale[mediane - 1])) {
            liste_electorale.insert(liste_electorale.begin() + mediane - 1, p); // Insère la personne à l'indice médian - 1
            std::cout << "l'electeur a été ajouté avec succès " << std::endl;
            return a_été_ajouté = true;
        } else {
            // Recherche récursive dans la première moitié de la liste
            ajouter_electeur(deb, mediane - 1, p);
        }
    } else { // Si la personne est "supérieure" à l'élément médian
        // Cas où la personne doit être insérée après l'élément médian
        if (mediane == end) {
            liste_electorale.insert(liste_electorale.begin() + mediane + 1, p); // Insère la personne à la fin de la liste
            std::cout << "l'electeur a été ajouté avec succès " << std::endl;
            return a_été_ajouté = true;
        }
        if (!cmp.operator()(p, liste_electorale[mediane + 1]) || mediane == end) {
            liste_electorale.insert(liste_electorale.begin() + mediane + 1, p); // Insère la personne à l'indice médian + 1
            std::cout << "l'electeur a été ajouté avec succès " << std::endl;
            return a_été_ajouté = true;
        } else {
            // Recherche récursive dans la deuxième moitié de la liste
            ajouter_electeur(mediane + 1, end, p);
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


