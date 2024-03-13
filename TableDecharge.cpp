/**
 * \file FileAttente.hpp
 *  \author Bertrand RIVARD
*/

#include "TableDecharge.hpp"

TableDecharge::TableDecharge(int temps) {
    Dd = temps;
    persoEnCours = NULL;
}

TableDecharge::~TableDecharge() {}

bool TableDecharge::estVide() {
    return persoEnCours == NULL;
}

void TableDecharge::ajouterPersonne(elections::Personne* persDecharge) {
    if(estVide()) {
        persoEnCours = persDecharge;
    } else {
        // On place la personne en attente
        fileDecharge.ajouter(persDecharge);
    }
}

elections::Personne* TableDecharge::sortirPersonne() {

    if(estVide()) {
        throw "Espace vide, Personne ne peut sortir";
    } else {
        elections::Personne* pTemp = persoEnCours;
        persoEnCours = fileDecharge.sortir();
    }
    
    

}