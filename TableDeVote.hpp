/**
 * \file tableDeVote.hpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"

#ifndef TABLEDEVOTE_HPP
#define TABLEDEVOTE_HPP

// Déclaration de la classe TableDeVote qui hérite de la classe Espace
class TableDeVote : public Espace {
    public:
        // Constructeur prenant en paramètres le nombre de dés, le nom de la table et le nombre d'électeurs
        TableDeVote(const int De, const std::string& nom,const int nb_elec);
        
        // Fonction pour enregistrer la signature d'un électeur avec son ID
        void signer_liste(int ID);
        
        // Fonction pour vérifier si un électeur a déjà signé la liste d'émargement
        bool a_signer(int ID);
        
        // Fonction pour enregistrer le vote
        void vote();

    private:
        // Tableau dynamique pour enregistrer les signatures des électeurs
        bool* liste_emargement;
        
        // Nombre total d'électeurs attendus
        int nb_electeur;
    };
#endif