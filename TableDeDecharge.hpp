/**
 * \file tableDeDecharge.hpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"

#ifndef TABLEDEDECHARGE_HPP
#define TABLEDEDECHARGE_HPP

// Déclaration de la classe TableDeDecharge qui hérite de la classe Espace
class TableDeDecharge : public Espace {
    public:
        // Constructeur prenant en paramètres le nombre de dés, le nom de la table,
        // la probabilité de bulletins blancs et la probabilité de bulletins nuls
        TableDeDecharge(const int De, const std::string& nom, Election elec, float probaB, float  probaN);
        
        // Fonction pour obtenir la probabilité de bulletins blancs
        float getProbaBlanc();
        
        // Fonction pour définir la probabilité de bulletins blancs
        void setProbaBlanc(float p);
        
        // Fonction pour obtenir la probabilité de bulletins nuls
        float getProbaNull();
        
        // Fonction pour définir la probabilité de bulletins nuls
        void setProbaNull(float p);

        //fonction qui recupere la maximum de difference entre un electeur et un candidat
        int getMaxSensiPolitique();
        
        // Fonction pour enregistrer le bulletin d'un électeur
        void prendreBulletin();

        //Recherche le choix final (le vote) de l'electeur en fonction de sa sensibilite il renvoie l'indice a laquelle se situe le candidat
        int trouverVote();

        //recherche le bulletin corresondant a la sensibilite politique de l'electeur
        std::vector<Personne*>  chercherListeChoix(int nbChoix);


    private:
        // Probabilité de bulletins blancs
        float proba_blanc;
        
        // Probabilité de bulletins nuls
        float proba_null;

        //la distance maximum entre les sensibilités politiques d’un électeur et d’un candidat 
        int maxSensiPolitique;
};
#endif