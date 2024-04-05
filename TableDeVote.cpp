/**
 * \file tableDeVote.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "TableDeVote.hpp"

TableDeVote::TableDeVote(const int De, const std::string& nom,const int nb_elec, const vector<Personne*> liste_candidats)
    : Espace(De, nom), nb_electeur(nb_elec), liste_emargement(new bool[nb_elec])
{
    for (int i = 0; i < nb_elec; i++) {
        liste_emargement[i] = false;
    }

    //Boucle qui rempli l'urne avec les différents candidats
    for (Personne* pers : liste_candidats) {
        //Chaque candidat commence avec 0 vote en sa faveur
        urne.insert(std::make_pair(pers,0));
    }
};

void TableDeVote::signer_liste(int ID){
    liste_emargement[ID] = true;
}

bool TableDeVote::a_signer(int ID){
    return liste_emargement[ID];
}

void TableDeVote::vote() {
    Personne* cle = Espace::getElecteurEnCours().getChoix();

    auto it = urne.find(cle);

    if(it != urne.end()) {
        it->second = it->second + 1;
    }
}

