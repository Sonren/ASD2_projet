/**
 * \file Isoloir.hpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include <string>
#include "Espace.hpp"
#include "FileAttenteCapacite.hpp"

#ifndef ISOLOIR_HPP
#define ISOLOIR_HPP

class Isoloir {
    public : 

    Isoloir(const int Di, const std::string& nom, int nbIsoloir); /*! Constructeur*/
    ~Isoloir(); /*! Destructeur */
    bool estVide(); /*! Vérifie si l'isoloir est vide ou non */
    void ajouterPersonne(Personne* persDecharge); /*! Ajoute une personne à l'espace Isoloir */
    Personne* sortirPersonne(); /*! Sort une personne de l'isoloir et renvoie cette personne */

    private :

    int Di; /*Durée dans lequel une personne reste dans l'isoloir */
    int nbIsoloir; /*Nombre d'isoloir différents dans l'esapce Isoloir*/
    FileAttenteCapacite persDansIsoloir; /* Comme il y a plusieurs personnes dans différents isoloir, on utilise une fileAttenteCapacite*/
    FileAttente fileIsoloir; /* Soit la file des personnes qui attendent qu'un isoloir se libère*/

};

#endif //ISLOIR_HPP