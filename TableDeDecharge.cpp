/**
 * 
 * \file tableDeDecharge.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "TableDeDecharge.hpp"
#include "Election.hpp"
#include <cstdlib> 

TableDeDecharge::TableDeDecharge(const int De, const std::string& nom,float probaB, float probaN)
    : Espace(De, nom), proba_blanc(probaB), proba_null(probaN)
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

std::vector <Personne*> TableDeDecharge::chercherChoix(int nbChoix){
    std::vector <Personne*> choixBulletin;
    int debutRecherche = Espace::getElecteurEnCours()->spol() * Election::getListeCandidats().size();
    Electeur::ajouterBulletin(Election::getListeCandidats()[debutRecherche]);
    Electeur::setChoix(Election::getListeCandidats()[debutRecherche]); // a revoir surement pas la meilleure facon 
    for(int i = 1; i<nbChoix; i++){    
        if((Election::getListeCandidats()[debutRecherche + 1] != NULL) && (Election::getListeCandidats()[debutRecherche - 1] != NULL)){
            //faire du recursif 
        }else if(){

        }else if(){

        }
    }
}


void TableDeDecharge::prendreBulletin(){
    float nbBulletinAPrendre = rand() % Election::getListeCandidats().size() + 1;
    float RandomChoixVote = rand() % 10 + 1;
    while(RandomChoixVote <= Election::getListeCandidats().size()) {
        RandomChoixVote = rand() % 10 + 1;
    }
    if(RandomVote <= proba_null){
        //prendre + proche et prendre blanc
        Espace::getElecteurEnCours().ajouterBulletin(Election::ajouter_candidat(Election::getListeCandidats()[3]))
        Espace::getElecteurEnCours().setChoix = NULL;   
    }else if(RandomVote <= proba_blanc){
        //prendre + proche et prendre blanc
        Espace::getElecteurEnCours().setChoix() = Election::ajouter_candidat(Election::getListeCandidats()[3]);
    }else{
        //prendre les plus proche
    }
}
