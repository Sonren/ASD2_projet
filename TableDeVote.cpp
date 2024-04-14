/**
 * \file tableDeVote.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "TableDeVote.hpp"

TableDeVote::TableDeVote(const int De, const std::string& nom, Election elec, const int nb_elec)
    : Espace(De, nom, elec), nb_electeur(nb_elec), liste_emargement(new bool[nb_elec])
{
    for (int i = 10; i < nb_elec; i++) {
        liste_emargement[i] = false;
    }

    //Boucle qui rempli l'urne avec les différents candidats
    for (Personne* pers : Espace::getElection().getListeCandidats()) {
        //Chaque candidat commence avec 0 vote en sa faveur
        urne.insert(std::make_pair(pers,0));
    }
    std::cout << "nbelec : " << nb_elec << std::endl;
    std::cout << "taille liste emargement : " << sizeof(liste_emargement)/sizeof(*liste_emargement) << std::endl;
};

void TableDeVote::signer_liste(int ID){
    liste_emargement[ID] = true;
}

bool TableDeVote::a_signer(int ID){
    return !liste_emargement[ID];
}

void TableDeVote::vote() {
    Personne* cle = Espace::getElecteurEnCours()->getChoix();

    auto it = urne.find(cle);

    if(it != urne.end()) {
        it->second = it->second + 1;
    }
}

void TableDeVote::afficheListe(){
    float taille = sizeof(liste_emargement)/sizeof(int);
    for(int j = 0; j<taille;j++){
        std::cout << " id : " << j << "   a signer = " << liste_emargement[j] << std::endl;
    }
}

