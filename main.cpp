/**
 * \file main.cpp
 * \author Laurent Granvilliers Bertrand RIVARD Hugo PIARD
 */

#include <cstdlib>
#include <unistd.h>
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
const int Tmax = 10;
int T = 0;
queue<Electeur*> entree_; // Représente l'entrée du bureau de vote
bool aPrisSesBulletins = false; //vérifie que l'électeur présent dans la table de décharge à bien pris ces bulletins pour sortir de l'espace
bool aVoter = false; //vérifie que l'électeur présent dan sla table de vote a bien voté pour sortir de l'espace
const int Dd = 3; //Temps minimum qu'un électeur passe dans la table de décharge
const int Di = 6; //Temps minimum qu'un électeur passe dans un Isoloir
const int Dv = 4; //Temps minimum qu'un électeur passe dans la table de vote




// La fonction qui crée un pointeur vers un électeur à partir d'un pointeur vers une personne
Electeur* PersonneToElecteur(elections::Personne* pers) {
   // On crée un nouvel électeur en utilisant les informations de la personne donnée
   return new Electeur(pers->nom(), pers->prenom(), pers->spol(), 0);
}

void entrer(Electeur* e){
   cout << e->nom() << " entre " << endl;
   cout << "id : " << e->id() << endl;
   entree_.push(e);
}



int main(void){

   // initialisation du générateur de nombres aléatoires
   std::srand(std::time(nullptr));

   // création des personnes
   std::vector<Personne*> vp = {
      new Personne("Albert", "bic", 7),
      new Personne("Bernard", "gad", 9),
      new Personne("Christian", "ann", 2),
      new Personne("Dominique", "pol", 5),
      new Personne("Evelyne", "lam", 1),
      new Personne("François", "bul", 10),
      new Personne("Grégory", "yap", 3),
      new Personne("Xavier", "nel", 5),
      new Personne("Yves", "rik", 2),
      new Personne("Zinedine", "pat", 8),
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
      vp[5], vp[6], vp[7], vp[10], vp[0]
   };

   //liste qui permet a un electeur de signer et donc de valider son vote
   bool liste_emargement[ve.size() +11] ={false} ;
   
   
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
   //int randomNumber_vote = std::rand() % 10 + 1;

   TableDeVote *table_de_vote = new TableDeVote(Dv,"table de vote", *(presidentielle));

   // Pour générer un nombre aléatoire entre 1 et 10
   //int randomNumber_decharge = std::rand() % 10 + 1;

   TableDeDecharge *table_de_decharge = new TableDeDecharge(Dd,"table de décharge", *(presidentielle), 0.35,0.15);

   // Pour générer un nombre aléatoire entre 1 et 10
   //int randomNumber_isoloir = std::rand() % 10 + 1;

   Isoloir *isoloir = new Isoloir(Di,"isoloir", *(presidentielle), 3);


   
   /* 
   table_de_vote->afficherInfos();
   table_de_vote->ajouterElecteur(ve[0]);
   table_de_vote->afficherInfos();
   table_de_vote->ajouterElecteur(ve[1]);
   table_de_vote->afficherInfos();
   table_de_vote->sortirElecteur();
   table_de_vote->afficherInfos(); 
   */

   /*
   cout <<  endl << "decharge" << endl;
   table_de_decharge->afficherInfos();
   table_de_decharge->ajouterElecteur(ve[6]);
   table_de_decharge->prendreBulletin();
   table_de_decharge->getElecteurEnCours()->afficherListeBulletin();
   table_de_decharge->afficherInfos();

   cout << endl << "--------Isoloir-----" << endl;
   isoloir->ajouterElecteur(ve[1]);
   isoloir->afficherInfos();
   */



   //Boucle principal 
   cout<<"BOUCLE PRINCIPAL"<<endl;
   cout<<endl;

   int numeroListe = 0;
   //Tant que le T est inférieur à Tmax ou que l'intégralité des espaces sont vides
   while (T <= Tmax || !( table_de_decharge->estVide() && isoloir->estVide() && table_de_vote->estVide()) ) {
      cout<< endl << endl << "T = "<<T<<endl;
      cout << " table de decharge : " << table_de_decharge->estVide() << endl;
      cout << " table de vote : " << table_de_vote->estVide() << endl;
      cout << " isoloir : " << isoloir->estVide() << endl;
      

      //Insertion des électeurs dans le bureau de vote
      cout<<"ENTREE"<<endl;

      if (T==0 || T == 3 || T == 5) {
         cout << " liste emargement : " << liste_emargement[ve[numeroListe]->id()] << endl;
         if(liste_emargement[ve[numeroListe]->id()] == false){
            entrer(ve[numeroListe]);
            numeroListe++;
         }else{
            cout << " L'electeur " << *(ve[numeroListe]) << " a déja voté " << endl;
         }
      }

      cout<<"DECHARGE"<<endl;
   
      //INSERTION 

      //Si la table de décharge est vide, on fait rentrée le premier arrivé dans l'Entrée
      if (table_de_decharge->estVide()) {
         //On vérifie que l'Entrée n'est pas vide, sinon on ne fait rien
         if(!entree_.empty()) {
            cout<<entree_.front()->nom() <<" entre"<<endl;
            table_de_decharge->ajouterElecteur(entree_.front());
            entree_.pop();
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
            isoloir->setFileEspace(table_de_decharge->getElecteurEnCours());
            cout<<"taille file Attente isoloir :"<<isoloir->getFile().size()<<endl;
            //On le retire de la table de décharge
            table_de_decharge->sortirElecteur();
            //On réinitialise aPrisSesBulletins
            aPrisSesBulletins = false;
         }
      }

      cout<<"ISOLOIR"<<endl;
   
      //INSERTION

      //On vérifie si les isoloirs ne sont pas pleins
      if (!isoloir->estPlein()) {
         
         //cout<<!isoloir->getFile().empty()<<endl;
         //si il ne le sont pas on vérifie si il y a un électeur qui attend pour rentrer
         if (!isoloir->getFile().empty()){
            
            //Si oui on le fait rentrer dans un isoloir
            cout<<isoloir->getFile().front()->nom()<<" entre"<<endl;
            isoloir->ajouterElecteur(isoloir->getFile().front());
            isoloir->setElecteurEnCours(isoloir->getFile().front()); //pointe vers l'electeur qui est rentrer en dernier dans l'isoloir 
            //on le supprime ensuite de la fileAttente de l'isoloir
            isoloir->popFileEspace();
         }
      }
      
      
      //RETRAIT

      //Si les isoloirs ne sont pas tous vide
      if(!isoloir->getListeIsoloir().empty()) {
         //Si le premier arrivée dans son isoloir a sa durée à 0 ou moins, on le sort de l'espace
         if (isoloir->getListeIsoloir().front()->getDuree() <= 0){

            //TODO: afficher le choix de bulletin

            //On place l'électeur qui sort de la décharge dans la fileAttente de la table de vote de manière provisoire
            cout << isoloir->getListeIsoloir().front()->nom() <<" sort"<<endl;
            table_de_vote->setFileEspace(isoloir->sortirElecteur());
         }
      }
      
      cout<<"VOTE"<<endl;
   
     /* //INSERTION

      //Si il n'y a persone à la table de vote
      if (table_de_vote->getElecteurEnCours() == NULL) {
         //Si il y a quelqu'un dans la fileAttente de la table de vote on le fait rentrer
         if (!table_de_vote->getFile().empty()) {
            table_de_vote->setElecteurEnCours(table_de_vote->popFileEspace()); //ici on recupere l'electeur en front tout en l'elevant de la file d'attente
         }
      }

      //RETRAIT

      //Si il y a une personne à la table de vote
      if (table_de_vote->getElecteurEnCours() != NULL) {
         table_de_vote->vote();
         liste_emargement[table_de_vote->getElecteurEnCours()->id()] = true;
         //Si l'électeur à signé la liste d'émargement et que sa durée est à 0 ou moins, on le sort de l'espace
         if (table_de_vote->getElecteurEnCours()->getDuree() <= 0 && liste_emargement[table_de_vote->getElecteurEnCours()->id()] == true) {
            cout<<table_de_vote->getElecteurEnCours()->nom()<<" sort"<<endl;
            cout<<"SORTIE"<<endl;
            cout<< table_de_vote->getElecteurEnCours()->nom() <<" sort"<<endl;
            table_de_vote->sortirElecteur();
         }
      } */

      //INSERTION

      //Si la table de vote est vide, on fait rentrée le premier arrivé dans la file d'attente entre l'isoloir et la table de vote
      if (table_de_vote->estVide()) {
         //On vérifie que la file d'attente n'est pas vide, sinon on ne fait rien
         if(!table_de_vote->getFile().empty()) {
            cout<<table_de_vote->getFile().front()->nom() <<" entre"<<endl;
            table_de_vote->ajouterElecteur(isoloir->getFile().front());
            table_de_vote->popFileEspace();
         }
      //Sinon, si la personne présente dans la table de vote n'a pas encore voter, elle le fait
      } else if(!aVoter) {
         table_de_vote->vote();
         aVoter = true;
         liste_emargement[table_de_vote->getElecteurEnCours()->id()] = true;
      }

      //RETRAIT

      //Si il y a un électeur à la table de vote
      if (table_de_vote->getElecteurEnCours() != NULL) {
         //Si l'électeur présent a voter et qu'il a signer la liste et que sa durée est à 0 ou moins, Il sort de l'espace
         if (table_de_vote->getElecteurEnCours()->getDuree()<=0 && aVoter && liste_emargement[table_de_vote->getElecteurEnCours()->id()] == true) {
            cout<<table_de_vote->getElecteurEnCours()->nom()<<" sort"<<endl;
            //On le retire de la table de décharge
            table_de_vote->sortirElecteur();
            //On réinitialise aPrisSesBulletins
            aVoter = false;
         }
      }
      
      
      
      
      


      //TODO : Vérifier les actions réalisés dans les boucles
      //TODO : Décrémenter le temps des électeurs à chaque passage de boucle
      cout<<"durée de albert"<<endl;
      cout<<ve[0]->getDuree()<<endl;
      ve[0]->setDuree(ve[0]->getDuree()-1);
      cout<<ve[0]->getDuree()<<endl;

      ve[1]->setDuree(ve[1]->getDuree()-1);

      ve[2]->setDuree(ve[2]->getDuree()-1);

      T++;
      //sleep(1); 

      if(table_de_decharge->estVide()){
         cout << "Il n'y a personne dans la table de decharge " << endl;
      }else{
         if (table_de_decharge->getElecteurEnCours() != NULL){
            cout << *(table_de_decharge->getElecteurEnCours()) << " est dans la table de decharge" << endl;
         }else{
            cout << "NULL table de decharge" << endl;
         }
      }
      if(isoloir->estVide()){
         cout << "Il n'y a personne dans l'isoloir' " << endl;
      }else{
         if (isoloir->getElecteurEnCours() != NULL){
            cout << *(isoloir->getElecteurEnCours()) << " est dans l'isoloir'" << endl;
         }else{
            cout << "NULL isoloir" << endl;
         }
      }
      if(table_de_vote->estVide()){
         cout << "Il n'y a personne dans la table de vote " << endl;
      }else{
         if (table_de_vote->getElecteurEnCours() != NULL){
            cout << *(table_de_vote->getElecteurEnCours()) << " est dans la table de vote" << endl;
         }else{
            cout << "NULL table de vote" << endl;
         }
      }
   
   }
   isoloir->setFileEspace(ve[0]);
   cout << "taille file d'attente isoloir :" << isoloir->getFile().size() << endl;
   cout << " pop : " << *(isoloir->popFileEspace()) << endl;
   cout << "taille file d'attente isoloir :" << isoloir->getFile().size() << endl;
   entree_.push(ve[5]);
   cout<<"taille file Attente entre :"<<entree_.size()<<endl;


    // destruction des personnes
   for (Personne* psn : vp)
   {
      delete psn;
   }

   return 0;
}
