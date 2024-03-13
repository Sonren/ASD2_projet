/**
 * \file TableDecharge.hpp
 * \author Bertrand RIVARD
*/

#ifndef TABLEDECHARGE_HPP
#define TABLEDECHARGE_HPP

#include "Personne.hpp"
#include "FileAttente.hpp"



class TableDecharge {

    public : 
        TableDecharge(int temps); /*! Constructeur */
        ~TableDecharge(); /*! Dest */
        bool estVide(); /*! Vérifie si la  table de déchargement est vide ou non */
        void ajouterPersonne (elections::Personne* persDecharge); /*! Ajoute une personne à la table de décharge */
        elections::Personne* sortirPersonne (); /*! Sort une personne de la décharge */

    private : 
        int Dd; /*! Durée de décharge */
        elections::Personne* persoEnCours; /*! Personne actuellement dans la décharge */
        FileAttente fileDecharge;   /*! File d'attente de la décharge */

        
};

#endif