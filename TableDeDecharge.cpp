/**
 * \file tableDeDecharge.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "TableDeDecharge.hpp"
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
    float RandomVote = = ((double)rand() / RAND_MAX);
    if(RandomVote <= proba_null){
        //vprendre bulletin null
    }else if(RandomVote <= proba_blanc){
        //prendre bulletin blanc
    }
}
