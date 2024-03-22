/**
 * \file Isoloir.hpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"

#ifndef ISOLOIR_HPP
#define ISOLOIR_HPP

class Isoloir {
    public : 

    Isoloir(const int Di, const std::string& nom, int capacite); /*! Constructeur*/
    ~Isoloir(); /*! Destructeur */
    bool estVide(); /*! Vérifie si l'isoloir est vide ou non */
    void ajouterPersonne(Personne* persDecharge); /*! Ajoute une personne à l'isoloir */
    Personne* sortirPersonne(); /*! Sort une personne de l'isoloir et renvoie cette personne */

    private :

    std::string
};

#endif //ISLOIR_HPP