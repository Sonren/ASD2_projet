/**
 * \file Isoloir.hpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include <string>
#include "FileAttenteCapacite.hpp"

#ifndef ISOLOIR_HPP
#define ISOLOIR_HPP

#include "Espace.hpp"

class Isoloir : public Espace{
    public : 

    Isoloir(const int De, const std::string& nom, int nbIsoloir); /*! Constructeur*/
    ~Isoloir(); /*! Destructeur */
    bool estVide() override; /*! Vérifie si l'isoloir est vide ou non */
    void ajouterPersonne(Personne* persDecharge); /*! Ajoute une personne à l'espace Isoloir */
    Personne* sortirPersonne(); /*! Sort une personne de l'isoloir et renvoie cette personne */
    void afficherInfos() override; /*Affiche toute les infos sur l'espace (la personne dedans et la duree)*/

    private :
    int nbIsoloir; /*Nombre d'isoloir différents dans l'esapce Isoloir*/
    FileAttenteCapacite persDansIsoloir; /* Comme il y a plusieurs personnes dans différents isoloir, on utilise une fileAttenteCapacite*/
};

#endif //ISLOIR_HPP