/**
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

void TableDeDecharge::prendreBulletin(Electeur elec){
    float nbBulletinAPrendre = rand() % Election::getListeCandidats().size() + 1;
    float RandomChoixVote = rand() % 10 + 1;
    if(RandomVote <= proba_null){
        //prendre + proche et prendre blanc
        elec.ajouterBulletin(Election::ajouter_candidat(Election::getListeCandidats()[3]))
        elec.setChoix = NULL;   
    }else if(RandomVote <= proba_blanc){
        //prendre + proche et prendre blanc
        elec.setChoix = Election::ajouter_candidat(Election::getListeCandidats()[3]);
    }else{
        //prendre les plus proche
    }
}
