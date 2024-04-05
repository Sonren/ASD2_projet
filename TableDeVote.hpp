/**
 * \file tableDeVote.hpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"
#include "Personne.hpp"

#ifndef TABLEDEVOTE_HPP
#define TABLEDEVOTE_HPP

typedef std::unordered_map<elections::Personne*, int> map_Personne_int;

// Déclaration de la classe TableDeVote qui hérite de la classe Espace
class TableDeVote : public Espace {
    public:
        // Constructeur prenant en paramètres le nombre de dés, le nom de la table, le nombre d'électeurs, ainsi que la liste de candidats
        TableDeVote(const int De, const std::string& nom,const int nb_elec, const vector<Personne*> liste_candidats);
        
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

        map_Personne_int urne;
    };
#endif