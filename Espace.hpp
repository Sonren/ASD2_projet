/**
 * \file Espace.hpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#ifndef ESPACE_HPP
#define ESPACE_HPP

#include <string>
#include "Electeur.hpp"
#include <queue>

using namespace elections;

class Espace {
    public :

        Espace(const int De, const std::string& nom); /*! constructeur*/
        ~Espace(); /*! Destructeur */
        bool estVide(); /*! Vérifie si l'espace est vide ou non */
        void ajouterElecteur(Electeur* persDecharge); /* ajoute une personne à l'espace */
        Electeur* sortirElecteur(); /*! sort une personne de l'espace et renvoie cette personne */
        void afficherFirstQueue() const; 	/*! Affiche la file d'attente */
        virtual void afficherInfos(); /*Affiche toute les infos sur l'espace (la personne dedans et la duree)*/
        std::string getNom();
        int getDuree();
        Electeur* getElecteurEnCours();
        std::queue<Electeur*> getFile();
        void setElecteurEnCours(Electeur* ptrElecteur);
        



    private : 

        std::string  nom; /*! Nom de l'espace */
        int De; /*! Durée dans lequel une personne reste dans l'espace */
        Electeur* electeurEnCours; /*! Personne actuellement dans l'espace, NULL si il n'y a personne */
        std::queue<Electeur*> fileEspace; /*! File d'attente de l'espace*/
};

#endif