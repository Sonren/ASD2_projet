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

using namespace std;
using namespace elections;

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

   Espace *table_de_vote = new Espace(randomNumber_vote,"table de vote");

   // Pour générer un nombre aléatoire entre 1 et 10
   int randomNumber_decharge = std::rand() % 10 + 1;

   Espace *table_de_decharge = new Espace(randomNumber_decharge,"table de décharge");
   
   table_de_vote->afficherInfos();
   table_de_vote->ajouterPersonne(vp[0]);
   table_de_vote->afficherInfos();
   table_de_vote->ajouterPersonne(vp[1]);
   table_de_vote->afficherInfos();
   table_de_vote->sortirPersonne();
   table_de_vote->afficherInfos();

   cout <<  endl << "decharge" << endl;
   table_de_decharge->afficherInfos();
   table_de_decharge->ajouterPersonne(vp[1]);
   table_de_decharge->afficherInfos();

    // destruction des personnes
   for (Personne* psn : vp)
   {
      delete psn;
   }

   return 0;
}
