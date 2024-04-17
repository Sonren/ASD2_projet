/**
 * \file Election.hpp
 *  \author Bertrand RIVARD Hugo Piard
*/

#include <string>
#include <vector>
#include "Personne.hpp"
#include "Electeur.hpp"


#ifndef ELECTION_HPP
#define ELECTION_HPP

using namespace elections;


// Déclaration de la classe Election
class Election {
public:
    // Constructeur de la classe Election avec un vecteur vide que l'utilisateur devra remplir
    Election(const std::string& nom);
    
    // Constructeur de la classe Election avec une liste d'électeurs et une liste de candidats
    Election(const std::string& nom, std::vector<Personne*> liste_candidat, std::vector<Electeur*> liste_electeur);
    
    // Constructeur de la classe Election avec une liste de candidats
    Election(const std::string& nom, std::vector<Personne*> liste_candidat);

    // Destructeur
    ~Election();
    
    // Renvoie le nom de l'élection
    std::string getNom() const;
    
    // Définit le nom de l'élection
    void setNom(std::string nom_election);

    //Renvoie la liste des candidats
    std::vector<Personne*>  getListeCandidats();

    //permet de set le bulletin blanc qui  correspond à un vote blanc pour un électeur 
    void setBulletinBlanc(Personne* personneBLanc);

    //permet de recuperer l'adresse de la personne qui represente le bulletin blanc
    Personne* getBulletinBlanc();
    
    // Ajoute un candidat à la liste des candidats
    void ajouter_candidat(Personne* candi);
    
    // Retire un candidat de la liste des candidats par son ID
    void retirer_candidat(int id);
    
    // Affiche la liste des candidats
    void afficher_candidat();
    
    // Vérifie si une personne est sur la liste des électeurs entre deux indices
    bool est_sur_liste(int deb, int end, Electeur* p);
    
    // Ajoute un électeur à la liste électorale entre deux indices
    bool ajouter_electeur(int deb, int end, Electeur* e);
    
    // Affiche la liste des électeurs
    void afficher_electeur();

    //Afficher les informations d'une élection
    void afficher_election();


private:
    // Nom de l'élection
    std::string nom_election;
    
    // Liste des candidats
    std::vector<Personne*> candidats;
    
    // Liste électorale
    std::vector<Electeur*> liste_electorale;

    // pointeur vers le candidat blanc (bulletin blanc)
    Personne * bulletin_blanc;

};

#endif