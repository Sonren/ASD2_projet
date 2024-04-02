/**
 * \file Electeur.hpp
 *  \author Bertrand RIVARD Hugo Piard
*/

#include "Personne.hpp"
#include "Bulletin.hpp"
#include <vector>


#ifndef ELECTEUR_HPP
#define ELECTEUR_HPP

class Electeur : public elections::Personne {

    public:

    Electeur(const std::string& nom, const std::string& prenom, int spol,int duree);
    int getDuree();
    void steDuree(int d);
    elections::Personne* getChoix();
    void setChoix(elections::Personne* p);
    void ajouterBulletin(Bulletin* bult);

    private:

    std::vector<Bulletin*> liste_bulletin;
    int duree_espace;
    elections::Personne* choix_vote;

};
#endif