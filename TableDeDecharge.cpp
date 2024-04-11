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
    int idSpolCandidat = Espace::getElection().getListeCandidats()[1]->spol();
    for(long unsigned int i =0; i< Espace::getElection().getListeCandidats().size(); ++i){
        if(Espace::getElection().getListeCandidats()[i]->spol() == Espace::getElecteurEnCours()->spol()){
            return i;
        }else{
            if(Espace::getElection().getListeCandidats()[i]->spol() < abs(Espace::getElecteurEnCours( )->spol()-idSpolCandidat)){
                idSpolCandidat = Espace::getElection().getListeCandidats()[i]->spol();
            }
        }
    }
    return idSpolCandidat;
}

std::vector<Personne*> TableDeDecharge::chercherListeChoix(int nbChoix){
    std::vector <Personne*> listeTempBulletin;
    if(Espace::getElecteurEnCours()->getChoix() == NULL || Espace::getElecteurEnCours()->getChoix() == Espace::getElection().getBulletinBlanc()){
        for(int i = 0; i < nbChoix; i++){
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
    float nbBulletinAPrendre = rand() % Espace::getElection().getListeCandidats().size() + 1;
    float RandomChoixVote = rand() % 10 + 1;
    while(RandomChoixVote <= Espace::getElection().getListeCandidats().size()) {
        RandomChoixVote = rand() % 10 + 1;
    }
    if(RandomChoixVote <= proba_null){
        Espace::getElecteurEnCours()->ajouterBulletin(Espace::getElection().getBulletinBlanc());
        Espace::getElecteurEnCours()->setChoix(NULL);   
        Espace::getElecteurEnCours()->ajouterListeBulletin(chercherListeChoix(nbBulletinAPrendre));  
    }else if(RandomChoixVote <= proba_blanc){
        //prendre + proche et prendre blanc
        Espace::getElecteurEnCours()->setChoix(Espace::getElection().getBulletinBlanc());
    }else{
        int choix = trouverVote();
        Espace::getElecteurEnCours()->setChoix(Espace::getElection().getListeCandidats()[choix]);
        Espace::getElecteurEnCours()->ajouterListeBulletin(chercherListeChoix(nbBulletinAPrendre));
    }
}
