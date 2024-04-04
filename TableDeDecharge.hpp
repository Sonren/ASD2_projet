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
        TableDeDecharge(const int De, const std::string& nom,float probaB, float  probaN);
        
        // Fonction pour obtenir la probabilité de bulletins blancs
        float getProbaBlanc();
        
        // Fonction pour définir la probabilité de bulletins blancs
        void setProbaBlanc(float p);
        
        // Fonction pour obtenir la probabilité de bulletins nuls
        float getProbaNull();
        
        // Fonction pour définir la probabilité de bulletins nuls
        void setProbaNull(float p);
        
        // Fonction pour enregistrer le bulletin d'un électeur
        void prendreBulletin(Electeur elec);

    private:
        // Probabilité de bulletins blancs
        float proba_blanc;
        
        // Probabilité de bulletins nuls
        float proba_null;
};
#endif