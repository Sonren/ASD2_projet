/**
 * \file main.cpp
 * \author Laurent Granvilliers Bertrand RIVARD Hugo PIARD
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include "Personne.hpp"
#include "Election.hpp"
#include "Espace.hpp"
#include "Electeur.hpp"
#include "Isoloir.hpp"
#include "TableDeDecharge.hpp"
#include "TableDeVote.hpp"

using namespace std;
using namespace elections;

//Déclaration des Variables globales
const int Tmax = 20;
int T = 0;
queue<Electeur> entree_; // Représente l'entrée du bureau de vote
bool aPrisSesBulletins = false; //vérifie que l'électeur présent dans la table de décharge à bien pris ces bulletins pour sortir de l'espace
const int Dd = 3; //Temps minimum qu'un électeur passe dans la table de décharge
const int Di = 6; //Temps minimum qu'un électeur passe dans un Isoloir
const int Dv = 4; //Temps minimum qu'un électeur passe dans la table de vote




// La fonction qui crée un pointeur vers un électeur à partir d'un pointeur vers une personne
Electeur* PersonneToElecteur (elections::Personne* pers) {
   // On crée un nouvel électeur en utilisant les informations de la personne donnée
   return new Electeur(pers->nom(), pers->prenom(), pers->spol(), 0);
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
      new Personne("Z", "pat", 8),
      new Personne (" ", "blanc", 0) //represente le vote blanc
   };

   std::vector<Electeur*> ve = {
      PersonneToElecteur(vp[0]),
      PersonneToElecteur(vp[1]), 
      PersonneToElecteur(vp[2]), 
      PersonneToElecteur(vp[3]),
      PersonneToElecteur(vp[4]),
      PersonneToElecteur(vp[5]),
      PersonneToElecteur(vp[6])
   };
   
   std::vector<Personne*> vc = {
      vp[5], vp[6], vp[7], vp[10], vp[0], vp[1], vp[2], vp[3], vp[4]
   };


   
   
   // TODO
   // Code de simulation dans lequel on manipulera les personnes
   // via des pointeurs sur les éléments du vecteur vp.

  

   Election *presidentielle = new Election("presidentielle", vc, ve);
   /*cout <<  "nom de l'election : " << presidentielle->getNom() << endl;
   cout << "liste des candidats : " << endl << endl;
   presidentielle->afficher_candidat();
   cout << "liste des electeurs : " << endl << endl; matching function for call to ‘TableDeDecharge::TableDeDecharge(int&, const char [19], double, double, Election*&)’
   96 | e(randomNumber_decharge,"table de décharge",0.35,0.15, 
   presidentielle->afficher_electeur();
   bool bol = presidentielle->est_sur_liste(0,2,vp[1]);
   cout << bol<< endl;
   presidentielle->afficher_electeur();
   bool bol1 = presidentielle->ajouter_electeur(0,2,vp[3]);
   presidentielle->afficher_electeur();
   cout << bol1<< endl;*/
   presidentielle->setBulletinBlanc(vc[3]);


   cout << " ---------------Espace--------------" << endl;

   // Pour générer un nombre aléatoire entre 1 et 10ake
   int randomNumber_vote = std::rand() % 10 + 1;

   TableDeVote *table_de_vote = new TableDeVote(randomNumber_vote,"table de vote", *(presidentielle), 10);

   // Pour générer un nombre aléatoire entre 1 et 10
   int randomNumber_decharge = std::rand() % 10 + 1;

   TableDeDecharge *table_de_decharge = new TableDeDecharge(randomNumber_decharge,"table de décharge", *(presidentielle), 0.35,0.15);

   // Pour générer un nombre aléatoire entre 1 et 10
   int randomNumber_isoloir = std::rand() % 10 + 1;

   Isoloir *isoloir = new Isoloir(randomNumber_isoloir,"isoloir", *(presidentielle), 3);


   
   /* 
   table_de_vote->afficherInfos();
   table_de_vote->ajouterElecteur(ve[0]);
   table_de_vote->afficherInfos();
   table_de_vote->ajouterElecteur(ve[1]);
   table_de_vote->afficherInfos();
   table_de_vote->sortirElecteur();
   table_de_vote->afficherInfos(); 
   */

   cout <<  endl << "decharge" << endl;
   table_de_decharge->afficherInfos();
   table_de_decharge->ajouterElecteur(ve[1]);
   table_de_decharge->prendreBulletin();
   table_de_decharge->getElecteurEnCours()->afficherListeBulletin();
   table_de_decharge->afficherInfos();

   /*cout << endl << "--------Isoloir-----" << endl;
   isoloir->ajouterElecteur(ve[1]);
   isoloir->afficherInfos();*/




   //Boucle principal 
   cout<<"BOUCLE PRINCIPAL"<<endl;
   cout<<endl;
   while (T <= Tmax && table_de_decharge->estVide() && isoloir->estVide() && table_de_vote->estVide() ) {
      cout<<"T = "<<T<<endl;

      //Insertion des électeurs dans le bureau de vote
      cout<<"ENTREE"<<endl;

      if (T=1) {
         cout<<ve[0]->nom()<<" entre"<<endl;
         entree_.pushback(ve[0]);
      }

      if (T=3) {
         cout<<ve[1]->nom()<<" entre"<<endl;
         entree_.pushback(ve[1]);
      }

      if (T=5) {
         cout<<ve[2]->nom()<<" entre"<<endl;
         entree_.pushback(ve[2]);
      }

      cout<<"DECHARGE"<<endl;

      //INSERTION 

      //Si la table de décharge est vide, on fait rentrée le premier arrivé dans l'Entrée
      if (table_de_decharge->estVide()) {
         //On vérifie que l'Entrée n'est pas vide, sinon on ne fait rien
         if(!entree_.empty()) {
            cout<<entre_.front()->nom()<<" entre"<<endl;
            table_de_decharge->ajouterElecteur(entree_.front());
            entre_.pop();
         }
      //Sinon, si la personne présente dans la table de décharge n'a pas encore pris ses bulletins, elle le fait
      } else if(!aPrisSesBulletins) {
         table_de_decharge->prendreBulletin();
         aPrisSesBulletins = true;
      }

      //RETRAIT

      //Si il y a un électeur à la table de Décharge
      if (table_de_decharge->getElecteurEnCours() != NULL) {
         //Si l'électeur présent a pris ses bulletins et que sa durée est à 0 ou moins, Il sort de l'espace
         if (table_de_decharge->getElecteurEnCours()->getDuree()<=0 && aPrisSesBulletins ) {
            //On place l'électeur qui sort de la décharge dans la fileAttente de l'espace isoloir de manière provisoire
            cout<<table_de_decharge->getElecteurEnCours()->nom()<<" sort"<<endl;
            isoloir->getFile().push(table_de_decharge->sortirElecteur());
            //On réinitialise aPrisSesBulletins
            aPrisSesBulletins = false;
         }
      }

      cout<<"ISOLOIR"<<endl;

      //INSERTION

      //On vérifie si les isoloirs ne sont pas pleins
      if (!isoloir->estPlein()) {
         //si il ne le sont pas on vérifie si il y a un électeur qui attend pour rentrer
         if (isoloir->getFile().empty()){
            //Si oui on le fait rentrer dans un isoloir
            cout<<isoloir->getFile().front()->nom()<<" entre"<<endl;
            isoloir->ajouterElecteur(isoloir->getFile().front());
            //on le supprime ensuite de la fileAttente de l'isoloir
            isoloir->getFile().pop();
         }
      }


      //RETRAIT

      //Si les isoloirs ne sont pas tous vide
      if(isoloir->listeIsoloir.empty()) {
         //Si le premier arrivée dans son isoloir a sa durée à 0 ou moins, on le sort de l'espace
         if (isoloir->listeIsoloir.front()->getDuree <= 0){

            //TODO: afficher le choix de bulletin

            //On place l'électeur qui sort de la décharge dans la fileAttente de la table de vote de manière provisoire
            isoloir->listeIsoloir.front()->nom()<<" sort"<<endl;
            table_de_vote->getFile().push(isoloir->sortirElecteur());
         }
      }

      cout<<"VOTE"<<endl;

      //INSERTION

      //Si il n'y a persone à la table de vote
      if (table_de_vote->getElecteurEnCours() == NULL) {
         //Si il y a quelqu'un dans la fileAttente de la table de vote on le fait rentrer
         if (!table_de_vote->getFile().empty()) {
            table_de_vote->getElecteurEnCours() = table_de_vote->getFile().front();
            table_de_vote->getFile().pop();
         }
      }

      //Si il y a un personne à la table de vote
      if (table_de_vote->getElecteurEnCours() != NULL) {
         table_de_vote->vote();
         table_de_vote->signer_liste(table_de_vote->getElecteurEnCours()->id());
         
      }

      //RETRAIT
      
      //Si l'électeur à signé la liste d'émargement et que sa durée est à 0 ou moins, on le sort de l'espace
      if (table_de_vote->getElecteurEnCours()->getDuree() <= 0 && table_de_vote->a_signer(table_de_vote->getElecteurEnCours()->id())) {
         cout<<table_de_vote->getElecteurEnCours()->nom()<<" sort"<<endl;
         cout<<"SORTIE"<<endl;
         cout<<table_de_vote->getElecteurEnCours()->nom()<<" sort"<<endl;
         table_de_vote->getElecteurEnCours() = NULL;
      }


      //TODO : Vérifier les actions réalisés dans les boucles
      //TODO : Décrémenter le temps des électeurs à chaque passage de boucle


      T++;
   }


    // destruction des personnes
   for (Personne* psn : vp)
   {
      delete psn;
   }

   return 0;
}
