/**
 * \file tableDeVote.hpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"
#include "Personne.hpp"
#include <unordered_map>

#ifndef TABLEDEVOTE_HPP
#define TABLEDEVOTE_HPP

typedef std::unordered_map<elections::Personne*, int> map_Personne_int;

// Déclaration de la classe TableDeVote qui hérite de la classe Espace
class TableDeVote : public Espace {
    public:
        // Constructeur prenant en paramètres le nombre de dés, le nom de la table, le nombre d'électeurs, ainsi que la liste de candidats
        TableDeVote(const int De, const std::string& nom, Election elec);
        
        // Fonction pour enregistrer le vote
        void vote();

        //Retourne l'urne
        map_Personne_int getUrne() const;

    private:
        //represente l'urne pour voter sous forme de table de hchage 
        map_Personne_int urne;
    };
#endif