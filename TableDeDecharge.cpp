/**
 * 
 * \file tableDeDecharge.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "TableDeDecharge.hpp"
#include "Election.hpp"
#include "Personne.hpp"
#include <math.h>
#include <cstdlib> 

TableDeDecharge::TableDeDecharge(const int De, const std::string& nom, Election elec, float probaB, float probaN)
    : Espace(De, nom, elec), proba_blanc(probaB), proba_null(probaN)
{};


float TableDeDecharge::getProbaBlanc(){
    return proba_blanc;
}


void TableDeDecharge::setProbaBlanc(float p){
    proba_blanc = p;
}

float TableDeDecharge::getProbaNull(){
    return proba_null;
}
        
void TableDeDecharge::setProbaNull(float p){
    proba_null = p;
}

int TableDeDecharge::getMaxSensiPolitique(){
    return maxSensiPolitique;
}

int TableDeDecharge::trouverVote(){
    int SpolChoixCandidat = Espace::getElection().getListeCandidats()[0]->spol();
    int Getindice = 0;
    for(long unsigned int i =0; i< Espace::getElection().getListeCandidats().size(); ++i){
        if(Espace::getElection().getListeCandidats()[i]->spol() == Espace::getElecteurEnCours()->spol()){
            Getindice = i;
            return i;
        }else{
            if(SpolChoixCandidat > abs(Espace::getElecteurEnCours( )->spol()-Espace::getElection().getListeCandidats()[i]->spol()) && Espace::getElection().getBulletinBlanc() != Espace::getElection().getListeCandidats()[i]){
                SpolChoixCandidat = abs(Espace::getElecteurEnCours( )->spol()-Espace::getElection().getListeCandidats()[i]->spol());
                Getindice = i;

            } 
        }
    }
    Espace::getElecteurEnCours()->ajouterBulletin(Espace::getElection().getListeCandidats()[Getindice]);
    return Getindice;
}

std::vector<Personne*> TableDeDecharge::chercherListeChoix(int nbChoix){
    std::vector <Personne*> listeTempBulletin;
    if(Espace::getElecteurEnCours()->getChoix() == NULL || Espace::getElecteurEnCours()->getChoix() == Espace::getElection().getBulletinBlanc()){
        for(int i = 0; i < nbChoix-1; i++){
            if(Espace::getElection().getListeCandidats()[i] != Espace::getElection().getBulletinBlanc()){
                listeTempBulletin.push_back(Espace::getElection().getListeCandidats()[i]); 
            }
        }
    }else{
        for(int i = 0; i < nbChoix; i++){
            if(Espace::getElection().getListeCandidats()[i] != Espace::getElection().getBulletinBlanc() || Espace::getElection().getListeCandidats()[i] != Espace::getElecteurEnCours()->getChoix()){
                listeTempBulletin.push_back(Espace::getElection().getListeCandidats()[i]); 
            }
        }

    }
    return listeTempBulletin;
}


void TableDeDecharge::prendreBulletin(){
    float nbBulletinAPrendre = 0;
    float RandomChoixVote = rand() % 10 + 1;
    while(nbBulletinAPrendre > Espace::getElection().getListeCandidats().size() || nbBulletinAPrendre < 2) {
        nbBulletinAPrendre = rand() % 10 + 2;
    }
    
    if(RandomChoixVote <= proba_null*10){
        Espace::getElecteurEnCours()->ajouterBulletin(Espace::getElection().getBulletinBlanc());
        Espace::getElecteurEnCours()->setChoix(NULL);  
    }else if(RandomChoixVote <= proba_blanc*10){
        Espace::getElecteurEnCours()->setChoix(Espace::getElection().getBulletinBlanc());
        Espace::getElecteurEnCours()->ajouterBulletin(Espace::getElection().getBulletinBlanc());
    }else{
        int choix = trouverVote();
        Espace::getElecteurEnCours()->setChoix(Espace::getElection().getListeCandidats()[choix]);
    }
    Espace::getElecteurEnCours()->ajouterListeBulletin(chercherListeChoix(nbBulletinAPrendre));
    Espace::getElecteurEnCours()->afficherListeBulletin();
}
