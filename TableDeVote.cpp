/**
 * \file tableDeVote.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "TableDeVote.hpp"


TableDeVote::TableDeVote(const int De, const std::string& nom,const int nb_elec)
    : Espace(De, nom), nb_electeur(nb_elec), liste_emargement(new bool[nb_elec])
{
    for (int i = 0; i < nb_elec; i++) {
        liste_emargement[i] = false;
    }
};

void TableDeVote::signer_liste(int ID){
    liste_emargement[ID] = true;
}

bool TableDeVote::a_signer(int ID){
    return liste_emargement[ID] == true;
}

