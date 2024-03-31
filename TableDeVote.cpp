/**
 * \file tableDeVote.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "TableDeVote.hpp"

TableDeVote::TableDeVote(int nb_electeur){
    
}

void TableDeVote::signer_liste(int ID){
    this->liste_emargement[ID] = true;
}

bool TableDeVote::a_signer(int ID){
    return this->liste_emargement[ID] == true;
}

