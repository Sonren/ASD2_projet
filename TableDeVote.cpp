/**
 * \file tableDeVote.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "TableDeVote.hpp"


TableDeVote::TableDeVote(const int De, const std::string& nom,const int nb_elec, float proba)
    : Espace(De, nom), proba_null(proba), nb_electeur(nb_elec), liste_emargement(new bool[nb_elec])
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

float TableDeVote::getProbaBlanc(){
    return proba_null;
}
        
void TableDeVote::setProbaBlanc(float p){
    proba_null = p;
}
