/**
 * \file Espace.hpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#ifndef ESPACE_HPP
#define ESPACE_HPP

#include <string>
#include "Personne.hpp"
#include "FileAttente.hpp"

class Espace {
    public :

        Espace(const int De, const std::string& nom); // constructeur
        ~Espace(); // Destructeur 
        virtual bool estVide(); // Vérifie si l'espace est vide ou non 
        void ajouterPersonne(Personne* persDecharge); // ajoute une personne à l'espace 
        Personne* sortirPersonne(); // sort une personne de l'espace et renvoie cette personne 
        virtual void afficherInfos(); // Affiche toute les infos sur l'espace (la personne dedans et la duree)
        std::string getNom();
        int getDuree();
        Personne* getPersonne();
        FileAttente getFile() ;

    private : 

        std::string  nom; // Nom de l'espace 
        int De; // Durée dans lequel une personne reste dans l'espace 
        FileAttente fileEspace; // File d'attente de l'espace
        Personne* persoEnCours; // Personne actuellement dans l'espace, NULL si il n'y a personne 

};

#endif