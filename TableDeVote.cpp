/**
 * \file tableDeVote.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "TableDeVote.hpp"
#include <iostream>


TableDeVote::TableDeVote(const int De, const std::string& nom, Election elec)
    : Espace(De, nom, elec)
{
    //Boucle qui rempli l'urne avec les différents candidats
    for (Personne* pers : Espace::getElection().getListeCandidats()) {
        //Chaque candidat commence avec 0 vote en sa faveur
        urne.insert(std::make_pair(pers,0));
        
    }
};

void TableDeVote::vote() {
    Personne* cle = Espace::getElecteurEnCours()->getChoix();

    auto it = urne.find(cle);

    if(it != urne.end()) {  
        it->second = it->second + 1;
    }
}

map_Personne_int TableDeVote::getUrne() const {
    return urne;
}

void TableDeVote::afficherUrne(int nbAbsent) {
    for (const auto& pair : urne) {
        if ((*pair.first).prenom() == "blanc") {
            std::cout << "vote blanc : " << pair.second << "(" <<static_cast<double>(pair.second) / Espace::getElection().getListeElecteur().size() * 100 <<"% )" << std::endl;
        } else {
        std::cout << *pair.first << " : " << pair.second << "(" <<static_cast<double>(pair.second) / Espace::getElection().getListeElecteur().size() * 100 <<"% )" << std::endl;
        }
    }
}



