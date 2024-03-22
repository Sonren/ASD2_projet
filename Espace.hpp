/**
 * \file Espace.hpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include <string>
#include "Personne.hpp"
#include "FileAttente.hpp"

using namespace elections;

class Espace {
    public :

        Espace(const int De, const std::string& nom); /*! constructeur*/
        ~Espace(); /*! Destructeur */
        bool estVide(); /*! Vérifie si l'espace est vide ou non */
        void ajouterPersonne(Personne* persDecharge); /* ajoute une personne à l'espace */
        Personne* sortirPersonne(); /*! sort une personne de l'espace et renvoie cette personne */


    private : 

        std::string  nom; /*! Nom de l'espace */
        int De; /*! Durée dans lequel une personne reste dans l'espace */
        Personne* persoEnCours; /*! Personne actuellement dans l'espace, NULL si il n'y a personne */
        FileAttente fileEspace; /*! File d'attente de l'espace*/
};