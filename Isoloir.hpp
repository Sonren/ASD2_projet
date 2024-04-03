/**
 * \file Isoloir.hpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include <string>
#include "Espace.hpp"
#include <queue>

#ifndef ISOLOIR_HPP
#define ISOLOIR_HPP

#include "Espace.hpp"

class Isoloir : public Espace{
    public : 

    Isoloir(const int De, const std::string& nom, int nbIsoloir); /*! Constructeur*/
    ~Isoloir(); /*! Destructeur */
    bool estVide(); /*! Vérifie si l'isoloir est vide ou non */
    void ajouterPersonne(Personne* pers); /*! Ajoute une personne à l'espace Isoloir */
    Personne* sortirPersonne(); /*! Sort une personne de l'isoloir et renvoie cette personne */
    void afficherInfos() override; /*Affiche toute les infos sur l'espace (la personne dedans et la duree)*/

    private :
    int nbIsoloir; /*Nombre d'isoloir différents dans l'esapce Isoloir*/
    std::queue<Personne*> persDansIsoloir; /* Comme il y a plusieurs personnes dans différents isoloir, on utilise une fileAttenteCapacite*/
    std::queue<Personne*> fileIsoloir; /* Soit la file des personnes qui attendent qu'un isoloir se libère*/
};

#endif //ISLOIR_HPP