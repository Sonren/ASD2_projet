/**
 * \file Electeur.hpp
 *  \author Bertrand RIVARD Hugo Piard
*/

#include "Personne.hpp"
#include <vector>


#ifndef ELECTEUR_HPP
#define ELECTEUR_HPP

class Electeur : public elections::Personne {

    public:


    // Déclaration du constructeur de la classe Electeur avec les paramètres nom, prénom, spol (probablement signifiant le sexe politique) et duree (durée)
    Electeur(const std::string& nom, const std::string& prenom, int spol, int duree);
    
    // Déclaration de la méthode getDuree() pour obtenir la durée
    int getDuree();
    
    // Déclaration de la méthode setDuree() pour définir la durée
    void setDuree(int d);
    
    // Déclaration de la méthode getChoix() pour obtenir le choix de vote de l'électeur
    elections::Personne* getChoix();
    
    // Déclaration de la méthode setChoix() pour définir le choix de vote de l'électeur
    void setChoix(elections::Personne* p);
    
    // Déclaration de la méthode ajouterBulletin() pour ajouter un bulletin de vote
    void ajouterBulletin(Personne* bult);

    private:

    std::vector<Personne*> liste_bulletin; //la liste des bulletins qu'il prends dans la table de décharge
    int duree_espace; //Durée où l'élécteur doit rester dans l'espace
    elections::Personne* choix_vote; //Pointe vers le candidat choisis 

};
#endif