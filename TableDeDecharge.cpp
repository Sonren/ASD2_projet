/**
 * \file tableDeDecharge.cpp
 * \author Bertrand RIVARD Hugo PIARD
 */

#include "TableDeDecharge.hpp"
#include "Election.hpp"
#include "Personne.hpp"
#include <math.h>
#include <cstdlib> 

// Constructeur de la classe TableDeDecharge
TableDeDecharge::TableDeDecharge(const int De, const std::string& nom, Election elec, float probaB, float probaN)
    : Espace(De, nom, elec), proba_blanc(probaB), proba_null(probaN)
{};

// Getter pour obtenir la probabilité de vote blanc
float TableDeDecharge::getProbaBlanc(){
    return proba_blanc;
}

// Setter pour définir la probabilité de vote blanc
void TableDeDecharge::setProbaBlanc(float p){
    proba_blanc = p;
}

// Getter pour obtenir la probabilité de vote nul
float TableDeDecharge::getProbaNull(){
    return proba_null;
}
        
// Setter pour définir la probabilité de vote nul
void TableDeDecharge::setProbaNull(float p){
    proba_null = p;
}

// Méthode pour trouver l'indice du candidat choisi par l'électeur
int TableDeDecharge::trouverVote(){
    // SpolChoixCandidat représente la sensibilité politique du candidat choisi
    int SpolChoixCandidat = Espace::getElection().getListeCandidats()[0]->spol();
    int Getindice = 0; // L'indice du candidat choisi
    // Parcourir la liste des candidats pour trouver celui qui correspond le mieux à la sensibilité politique de l'électeur
    for(long unsigned int i =0; i< Espace::getElection().getListeCandidats().size(); ++i){
        // Si l'électeur a la même sensibilité politique que le candidat
        if(Espace::getElection().getListeCandidats()[i]->spol() == Espace::getElecteurEnCours()->spol()){
            Getindice = i;
            return i;
        } else {
            // Sinon, trouver le candidat le plus proche en termes de sensibilité politique
            if(SpolChoixCandidat > abs(Espace::getElecteurEnCours( )->spol()-Espace::getElection().getListeCandidats()[i]->spol()) && Espace::getElection().getBulletinBlanc() != Espace::getElection().getListeCandidats()[i]){
                SpolChoixCandidat = abs(Espace::getElecteurEnCours( )->spol()-Espace::getElection().getListeCandidats()[i]->spol());
                Getindice = i;
            } 
        }
    }
    // Ajouter le bulletin de vote du candidat choisi à l'électeur
    Espace::getElecteurEnCours()->ajouterBulletin(Espace::getElection().getListeCandidats()[Getindice]);
    return Getindice;
}

// Méthode pour chercher la liste des choix possibles pour l'électeur
std::vector<Personne*> TableDeDecharge::chercherListeChoix(int nbChoix){
    std::vector <Personne*> listeTempBulletin;
    // Si l'électeur n'a pas encore choisi ou a choisi le vote blanc, les premiers choix possibles seront des candidats
    if(Espace::getElecteurEnCours()->getChoix() == NULL || Espace::getElecteurEnCours()->getChoix() == Espace::getElection().getBulletinBlanc()){
        for(int i = 0; i < nbChoix-1; i++){
            if(Espace::getElection().getListeCandidats()[i] != Espace::getElection().getBulletinBlanc()){
                listeTempBulletin.push_back(Espace::getElection().getListeCandidats()[i]); 
            }
        }
    } else { // Sinon, exclure le candidat déjà choisi de la liste des choix possibles
        for(int i = 0; i < nbChoix; i++){
            if(Espace::getElection().getListeCandidats()[i] != Espace::getElection().getBulletinBlanc() && Espace::getElection().getListeCandidats()[i] != Espace::getElecteurEnCours()->getChoix()){
                listeTempBulletin.push_back(Espace::getElection().getListeCandidats()[i]); 
            }
        }
    }
    return listeTempBulletin;
}

// Méthode pour que l'électeur prenne un bulletin de vote
void TableDeDecharge::prendreBulletin(){
    float nbBulletinAPrendre = 0;
    float RandomChoixVote = rand() % 10 + 1; // Choisir un nombre aléatoire entre 1 et 10
    // Choisir un nombre aléatoire de bulletins à prendre entre 2 et le nombre total de candidats
    while(nbBulletinAPrendre > Espace::getElection().getListeCandidats().size() || nbBulletinAPrendre < 2) {
        nbBulletinAPrendre = rand() % 10 + 2;
    }
    
    // Si le nombre aléatoire est inférieur ou égal à la probabilité de vote nul
    if(RandomChoixVote <= proba_null*10){
        // Ajouter un bulletin de vote nul
        Espace::getElecteurEnCours()->ajouterBulletin(Espace::getElection().getBulletinBlanc());
        Espace::getElecteurEnCours()->setChoix(NULL);  
    } else if(RandomChoixVote <= proba_blanc*10){ // Si le nombre aléatoire est inférieur ou égal à la probabilité de vote blanc
        // Choisir de voter blanc
        Espace::getElecteurEnCours()->setChoix(Espace::getElection().getBulletinBlanc());
        Espace::getElecteurEnCours()->ajouterBulletin(Espace::getElection().getBulletinBlanc());
    } else { // Sinon, choisir un candidat
        // Trouver le candidat choisi par l'électeur
        int choix = trouverVote();
        Espace::getElecteurEnCours()->setChoix(Espace::getElection().getListeCandidats()[choix]);
    }
    // Ajouter d'autres bulletins de vote pour les choix possibles de l'électeur
    Espace::getElecteurEnCours()->ajouterListeBulletin(chercherListeChoix(nbBulletinAPrendre));
    // Afficher la liste des bulletins de vote de l'électeur
    Espace::getElecteurEnCours()->afficherListeBulletin();
}
