/**
 * \file tableDeDecharge.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "TableDeDecharge.hpp"

TableDeDecharge::TableDeDecharge(const int De, const std::string& nom,float proba)
    : Espace(De, nom), proba_blanc(proba)
{};


float TableDeDecharge::getProbaBlanc(){
    return this->proba_blanc;
}


void TableDeDecharge::setProbaBlanc(float p){
    this->proba_blanc = p;
}