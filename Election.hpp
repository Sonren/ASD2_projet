/**
 * \file Election.hpp
 *  \author Bertrand RIVARD Hugo Piard
*/

#include <string>
#include <vector>
#include "Personne.hpp"


#ifndef ELECTION_HPP
#define ELECTION_HPP

using namespace elections;

class Election {

    public :
        Election(const std::string& nom, int nb_electeur); //constructeur  de la classe election avec un vecteur vide que l'utilisateur devra remplir
        Election(const std::string& nom, std::vector <Personne*> liste_electeur, std::vector <Personne*> liste_candidat, int nb_electeur);
        Election(const std::string& nom, std::vector <Personne*> liste_candidat, int nb_electeur); // constructeur  de la classe election avec le vecteur qui va permettre de remplir la liste 
        ~Election();
        std::string getNom() const;
        void setNom(std::string nom_election);
        void ajouter_candidat(Personne* p);
        void retirer_candidat(int id);//a voir si retourner la personne est pertinent (gain de temps ?)
        void afficher_candidat();
        bool est_sur_liste(int deb, int end, Personne* p);
        bool ajouter_electeur(int deb, int end, Personne* p);
        void afficher_electeur();
        void signer_liste(int ID);
        bool a_signer(int ID);

    private :
        std::string nom_election;
        std::vector <Personne*> candidats;
        std::vector <Personne*> liste_electorale;
        bool* liste_emargement;
};
#endif