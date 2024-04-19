/**
 * \file tableDeVote.cpp
 * \author Bertrand RIVARD Hugo PIARD
 */

#include "TableDeVote.hpp"
#include <iostream>

// Constructeur de la classe TableDeVote
TableDeVote::TableDeVote(const int De, const std::string& nom, Election elec)
    : Espace(De, nom, elec)
{
    // Boucle qui remplit l'urne avec les différents candidats
    for (Personne* pers : Espace::getElection().getListeCandidats()) {
        // Chaque candidat commence avec 0 vote en sa faveur
        urne.insert(std::make_pair(pers,0));
    }
}

// Méthode pour enregistrer le vote de l'électeur dans l'urne
void TableDeVote::vote() {
    // Récupérer le choix de l'électeur
    Personne* cle = Espace::getElecteurEnCours()->getChoix();

    // Rechercher le candidat choisi dans l'urne
    auto it = urne.find(cle);

    // Si le candidat est trouvé dans l'urne, incrémenter son nombre de votes
    if(it != urne.end()) {  
        it->second = it->second + 1;
    }
}

// Getter pour obtenir l'urne (le tableau des votes)
map_Personne_int TableDeVote::getUrne() const {
    return urne;
}

// Méthode pour afficher le contenu de l'urne (les résultats des votes)
void TableDeVote::afficherUrne(int nbAbsent) {
    // Parcourir chaque élément de l'urne
    for (const auto& pair : urne) {
        // Afficher le nombre de votes pour chaque candidat
        if ((*pair.first).prenom() == "blanc") { // Si le candidat est le vote blanc
            // Afficher le nombre de votes blancs avec le pourcentage par rapport au nombre total d'électeurs
            std::cout << "vote blanc : " << pair.second << " (" << static_cast<double>(pair.second) / (Espace::getElection().getListeElecteur().size() - nbAbsent) * 100 << "%)" << std::endl;
        } else {
            // Afficher le nom du candidat, le nombre de votes et le pourcentage de votes par rapport au nombre total d'électeurs
            std::cout << *pair.first << " : " << pair.second << " (" << static_cast<double>(pair.second) / (Espace::getElection().getListeElecteur().size() - nbAbsent) * 100 << "%)" << std::endl;
        }
    }
}
