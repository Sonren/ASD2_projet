/**
 * \file Bulletin.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Bulletin.hpp"

Bulletin::Bulletin(elections::Personne* candidat)
    : candidat(candidat)
{};
    
    
std::string  Bulletin::getCandiat(){
    return this->candidat->nom() + this->candidat->prenom(); //a voir si il faut mettre que le nom ou garder les deux
}