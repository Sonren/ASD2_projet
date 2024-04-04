/**
 * \file main.cpp
 * \author Laurent Granvilliers
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "Personne.hpp"
#include "Election.hpp"
#include "Espace.hpp"
#include "Electeur.hpp"
#include "Isoloir.hpp"
#include "TableDeDecharge.hpp"
#include "TableDeVote.hpp"

using namespace std;
using namespace elections;

// La fonction qui crée un pointeur vers un électeur à partir d'un pointeur vers une personne
Electeur* PersonneToElecteur (elections::Personne* pers) {
   // On crée un nouvel électeur en utilisant les informations de la personne donnée
   return new Electeur(&pers.nom, &pers.prenom, &pers.spol(), 0);
}

int main(void)
{

   // initialisation du générateur de nombres aléatoires
   std::srand(std::time(nullptr));

   // création des personnes
   std::vector<Personne*> vp = {
      new Personne("A", "bic", 7),
      new Personne("B", "gad", 9),
      new Personne("C", "ann", 2),
      new Personne("D", "pol", 5),
      new Personne("E", "lam", 1),
      new Personne("F", "bul", 10),
      new Personne("G", "yap", 3),
      new Personne("X", "nel", 5),
      new Personne("Y", "rik", 2),
      new Personne("Z", "pat", 8)
   };

   std::vector<Personne*> ve = {
      vp[0], vp[1], vp[2], vp[3], vp[4], vp[5], vp[6]
   };
   
   std::vector<Personne*> vc = {
      vp[5], vp[6], vp[7]
   };


   
   
   // TODO
   // Code de simulation dans lequel on manipulera les personnes
   // via des pointeurs sur les éléments du vecteur vp.

  

   Election *presidentielle = new Election("presidentielle", vc, ve);
   /*cout <<  "nom de l'election : " << presidentielle->getNom() << endl;
   cout << "liste des candidats : " << endl << endl;
   presidentielle->afficher_candidat();
   cout << "liste des electeurs : " << endl << endl;
   presidentielle->afficher_electeur();
   bool bol = presidentielle->est_sur_liste(0,2,vp[1]);
   cout << bol<< endl;
   presidentielle->afficher_electeur();
   bool bol1 = presidentielle->ajouter_electeur(0,2,vp[3]);
   presidentielle->afficher_electeur();
   cout << bol1<< endl;*/


   cout << " ---------------Espace--------------" << endl;

   // Pour générer un nombre aléatoire entre 1 et 10
   int randomNumber_vote = std::rand() % 10 + 1;

   TableDeVote *table_de_vote = new TableDeVote(randomNumber_vote,"table de vote", 10);

   // Pour générer un nombre aléatoire entre 1 et 10
   int randomNumber_decharge = std::rand() % 10 + 1;

   TableDeDecharge *table_de_decharge = new TableDeDecharge(randomNumber_decharge,"table de décharge",0.35,0.15);

   // Pour générer un nombre aléatoire entre 1 et 10
   int randomNumber_isoloir = std::rand() % 10 + 1;

   Isoloir *isoloir = new Isoloir(randomNumber_isoloir,"isoloir", 3);


   
   table_de_vote->afficherInfos();
   table_de_vote->ajouterElecteur(vp[0]);
   table_de_vote->afficherInfos();
   table_de_vote->ajouterElecteur(vp[1]);
   table_de_vote->afficherInfos();
   table_de_vote->sortirElecteur();
   table_de_vote->afficherInfos();

   cout <<  endl << "decharge" << endl;
   table_de_decharge->afficherInfos();
   table_de_decharge->ajouterElecteur(vp[1]);
   table_de_decharge->afficherInfos();

   cout << endl << "--------Isoloir-----" << endl;
   isoloir->ajouterElecteur(vp[1]);
   isoloir->afficherInfos();

    // destruction des personnes
   for (Personne* psn : vp)
   {
      delete psn;
   }

   return 0;
}
