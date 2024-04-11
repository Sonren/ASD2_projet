/**
 * \file Espace.hpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#ifndef ESPACE_HPP
#define ESPACE_HPP

#include <string>
#include "Electeur.hpp"
#include "Election.hpp"
#include <queue>

using namespace elections;

// Déclaration de la classe Espace
class Espace {
    public:
        // Constructeur prenant en paramètres le nombre de dés et le nom de l'espace
        Espace(const int De, const std::string& nom, Election elec);
        
        // Destructeur
        ~Espace();
        
        // Vérifie si l'espace est vide ou non
        bool estVide();
        
        // Ajoute une personne à l'espace
        void ajouterElecteur(Electeur* persDecharge);
        
        // Sort une personne de l'espace et renvoie cette personne
        Electeur* sortirElecteur();
        
        // Affiche la file d'attente
        void afficherFirstQueue() const;
        
        // Affiche toutes les infos sur l'espace (la personne dedans et la durée)
        virtual void afficherInfos();
        
        // Renvoie le nom de l'espace
        std::string getNom();
        
        // Renvoie la durée dans laquelle une personne reste dans l'espace
        int getDuree();
        
        // Renvoie la personne actuellement dans l'espace
        Electeur* getElecteurEnCours();
        
        // Renvoie la file d'attente de l'espace
        std::queue<Electeur*> getFile();
        
        // Définit la personne actuellement dans l'espace
        void setElecteurEnCours(Electeur* ptrElecteur);

        //Renvoie l'élection associé a l'espace
        Election getElection();

        //Définie l'élection associé a l'espace
        void setElection(Election e);

    private:
        // Nom de l'espace
        std::string nom;
        
        // Durée dans laquelle une personne reste dans l'espace
        int De;
        
        // Personne actuellement dans l'espace, NULL si il n'y a personne
        Electeur* electeurEnCours;
        
        // File d'attente de l'espace
        std::queue<Electeur*> fileEspace;

        //Election associé aux espaces
        Election election;
};

#endif