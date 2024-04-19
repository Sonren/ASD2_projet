/**
 * \file Isoloir.hpp
 * \author Bertrand RIVARD Hugo PIARD
*/

#include <string>
#include "Espace.hpp"
#include "Electeur.hpp"
#include <queue>

#ifndef ISOLOIR_HPP
#define ISOLOIR_HPP

// Déclaration de la classe Isoloir qui hérite de la classe Espace
class Isoloir : public Espace {
    public:
        // Constructeur prenant en paramètres le nombre de dés, le nom de l'isoloir et le nombre d'isoloirs
        Isoloir(const int De, const std::string& nom, Election elec, int nbIsoloir);
        
        // Destructeur
        ~Isoloir();
        
        // Vérifie si les différents isoloirs sont tous vide ou non
        bool estVide();

        //Vérifie si les différents isoloir sont tous pleins ou non
        bool estPlein();
        
        // Ajoute une personne à l'espace Isoloir
        void ajouterElecteur(Electeur* pers);
        
        // Sort une personne de l'isoloir et renvoie cette personne
        Electeur* sortirElecteur();
        
        // Affiche toutes les infos sur l'espace (la personne dedans et la durée)
        void afficherInfos() override;

        //permet de recuperer la liste d'isoloir 
        std::queue<Electeur*> getListeIsoloir();

    private:
        // Nombre d'isoloirs différents dans l'espace Isoloir
        long unsigned int nbIsoloir;
        
        // On utilise une queue pour représenter les différents isoloir
        std::queue<Electeur*> listeIsoloir;
};
#endif //ISOLOIR_HPP