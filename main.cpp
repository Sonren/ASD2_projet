/**
 * \file main.cpp
 * \author Laurent Granvilliers Bertrand RIVARD Hugo PIARD
 */

#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include <iomanip>
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
const int Tmax = 30;
int T = 0;
queue<Electeur*> entree_; // Représente l'entrée du bureau de vote
bool aPrisSesBulletins = false; //vérifie que l'électeur présent dans la table de décharge à bien pris ces bulletins pour sortir de l'espace
bool aVoter = false; //vérifie que l'électeur présent dan sla table de vote a bien voté pour sortir de l'espace
const int Dd = 3; //Temps minimum qu'un électeur passe dans la table de décharge
const int Di = 6; //Temps minimum qu'un électeur passe dans un Isoloir
const int Dv = 4; //Temps minimum qu'un électeur passe dans la table de vote
int numeroListe = 0;
int nbVote = 0;//nombre de vote effectué dans le bureau
int nbVoteNul = 0; // Nombre de vote nul
int nbElecteurInVector = 16; //nombre d'électeur dans le bureau
int nbCandidatInVector = 5; //nombre de candidat se présentant a l'élection



// La fonction qui crée un pointeur vers un électeur à partir d'un pointeur vers une personne
Electeur* PersonneToElecteur(elections::Personne* pers) {
   // On crée un nouvel électeur en utilisant les informations de la personne donnée
   return new Electeur(pers->nom(), pers->prenom(), pers->spol(), 0);
}

void entrer(Electeur* e){
   cout << e->nom() << " entre " << endl;
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
      new Personne (" ", "blanc", 0), //represente le vote blanc
      new Personne("Jacques", "jean", 4), //le président

      new Personne("Arthur", "bic", 7),
      new Personne("Baptiste", "gad", 9),
      new Personne("Charles", "ann", 2),
      new Personne("Damien", "pol", 5),
      new Personne("Eva", "lam", 1),
      new Personne("Fifi", "bul", 10),
      new Personne("Gerard", "yap", 3),
      new Personne("Xav", "nel", 5),
      new Personne("Yvonne", "rik", 2),
      new Personne("Zizou", "pat", 8)
   };

   if(vp.size() == 0){
      cout << " Il n'y a aucune personne dans la liste" << endl <<  "Fin de l'élection " << endl;
      exit(0);
   }

   Personne* president = vp[11];
   
   //on remplit le vecteur candiadat car on connait déja a l'avance qui se presente 
   std::vector<Personne*> vc = {
      vp[5], vp[6], vp[7], vp[10], vp[0]
   };

   //vecteur ou tous les électeurs sont stocké, il est vide car on compte le remplir après
   std::vector<Electeur*> ve = {};
  
   //Déclaration de l'élection
   
   Election *presidentielle = new Election("Euro 2024", vc, ve);
   presidentielle->setBulletinBlanc(vc[3]);

   //ajout des électeurs et dans candidats dans leurs vecteur respactifs
   for(int i=0; i<nbElecteurInVector; i++){
      int finVect =0;
      presidentielle->ajouter_electeur(0, finVect, PersonneToElecteur(vp[i]));
      finVect++;
   }

   //Déclarations de la liste d'émargements
   bool liste_emargement[presidentielle->getListeElecteur().size() + vp.size()] ={false} ;

   presidentielle->afficher_election();
   

   //Déclaration des différents espace du bureau de vote

   TableDeVote *table_de_vote = new TableDeVote(Dv,"table de vote", *(presidentielle));

   TableDeDecharge *table_de_decharge = new TableDeDecharge(Dd,"table de décharge", *(presidentielle), 0.35,0.15);

   Isoloir *isoloir = new Isoloir(Di,"isoloir", *(presidentielle), 3);


   //verification des vecteurs pour voir si ils ne sont pas vide et que l'élection peut se dérouler correctement
   if(presidentielle->getListeElecteur().size() == 0){
      cout<< "Aucun électeur ne s'est présenté au bureau de vote " << endl << "Le bureau ferme ses portes " << endl;
      exit(0);
   }

   if(vc.size() == 0){
      cout << "Aucun candidat ne se présente pour cette élection"  << endl << "L'élection se finie par un non lieu'" << endl;
      exit(0);
   }

   //gestion des entrées dans le bureau de vote de manière aléatoire 
   int nbElecteurInOffice = rand() % presidentielle->getListeElecteur().size() + (presidentielle->getListeElecteur().size()/2); // ici on cherche a déterminer le nombre d'électeur qui vont entrer dans le bureau de vote pour avoir un algorithme un minimum plus realiste nous avons décider qu'au moins la moitié des électeurs allait voter
   int* tabTempEntrée = new int[nbElecteurInOffice]{0};
   for(int i = 0; i < nbElecteurInOffice; i++){
      int tempTemps = rand() % (Tmax+1)/4;
      if(tabTempEntrée[i-1] != Tmax){
         while(tempTemps <= tabTempEntrée[i-1] || tempTemps == 0 || tempTemps-tabTempEntrée[i-1] > 5){
            tempTemps = rand() % (Tmax+1);
         }
         tabTempEntrée[i] = tempTemps;
         for(int k=0; k<nbElecteurInOffice; k++){
         }
      }else{
         tabTempEntrée[i] = -1; //on met le temps a -1 pour être sur que plus personne ne rentre comme le temps est décroissant
      }
   }

   //Boucle principal 
   
   cout<<endl;

   cout<<"OUVERTURE DU BUREAU n°254"<<endl;
   //Tant que le T est inférieur à Tmax ou que l'intégralité des espaces sont vides
   while (T <= Tmax || !( table_de_decharge->estVide() && isoloir->estVide() && table_de_vote->estVide() && table_de_decharge->getFile().empty() == true && isoloir->getFile().empty() == true && table_de_vote->getFile().empty() == true) ) {
      cout<< endl << "T = "<<T<<endl;
      
      //Insertion des électeurs dans le bureau de vote
      cout<<"  ENTREE"<<endl;

      if(tabTempEntrée[numeroListe] == T){
         if(liste_emargement[presidentielle->getListeElecteur()[numeroListe]->id()] == false){
            entrer(presidentielle->getListeElecteur()[numeroListe]);
            numeroListe++;
         }else{
            cout << " L'electeur " << *(presidentielle->getListeElecteur()[numeroListe]) << " a déja voté " << endl;
            numeroListe++;
         }
      }
      
      //ancienne version pour enter dans le bureau sans aléatoire 
      /*if (T==0 || T == 3 || T == 5 || T == 9 || T == 15 || T == 17 || T == 19) { // on choisit ici les auquels les différents électeurs vont entrer 
         if(liste_emargement[presidentielle->getListeElecteur()[numeroListe]->id()] == false){
            entrer(presidentielle->getListeElecteur()[numeroListe]);
            numeroListe++;
         }else{
            cout << " L'electeur " << *(presidentielle->getListeElecteur()[numeroListe]) << " a déja voté " << endl;
            numeroListe++;
         }
      }*/

      cout<<"  DECHARGE"<<endl;
   
      //INSERTION 

      //Si la table de décharge est vide, on fait rentrée le premier arrivé dans l'Entrée
      if (table_de_decharge->estVide()) {
         //On vérifie que l'Entrée n'est pas vide, sinon on ne fait rien
         if(!entree_.empty()) {
            cout << "      " << entree_.front()->nom() << " entre"<<endl;
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

      cout<<"  ISOLOIR"<<endl;
   
      //INSERTION

      //On vérifie si les isoloirs ne sont pas pleins
      if (!isoloir->estPlein()) {
         
         //cout<<!isoloir->getFile().empty()<<endl;
         //si il ne le sont pas on vérifie si il y a un électeur qui attend pour rentrer
         if (!isoloir->getFile().empty()){
            
            //Si oui on le fait rentrer dans un isoloir
            cout << "      " << isoloir->getFile().front()->nom() << " entre"<<endl;
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
            if(isoloir->getListeIsoloir().front()->getChoix() != NULL){
               cout << "      " << isoloir->getListeIsoloir().front()->nom() << " choisi " << *(isoloir->getListeIsoloir().front()->getChoix()) << endl;
            }else{
               cout << "      " << isoloir->getListeIsoloir().front()->nom() << " choisi bulletin NULL " << endl;
            }

            //On place l'électeur qui sort de la décharge dans la fileAttente de la table de vote de manière provisoire
            cout << "      " << isoloir->getListeIsoloir().front()->nom() <<" sort"<<endl;
            table_de_vote->setFileEspace(isoloir->getListeIsoloir().front());
            isoloir->sortirElecteur();

            
         }
      }
      
      cout<<"  VOTE"<<endl;

      //INSERTION

      //Si la table de vote est vide, on fait rentrée le premier arrivé dans la file d'attente entre l'isoloir et la table de vote
      if (table_de_vote->estVide()) {
         //On vérifie que la file d'attente n'est pas vide, sinon on ne fait rien
         if(!table_de_vote->getFile().empty()) {
            cout << "     " <<table_de_vote->getFile().front()->nom() << " entre"<<endl;
            table_de_vote->ajouterElecteur(table_de_vote->getFile().front());
            table_de_vote->popFileEspace();
         }
      //Sinon, si la personne présente dans la table de vote n'a pas encore voter, elle le fait
      } else if(!aVoter) {
         if (table_de_vote->getElecteurEnCours()->getChoix() == NULL) {
            nbVoteNul++;
         } else {
         table_de_vote->vote();
         }
         aVoter = true;
         liste_emargement[table_de_vote->getElecteurEnCours()->id()] = true;
         cout << "     " << table_de_vote->getElecteurEnCours()->nom() << " vote"<<endl;
         nbVote++;
      }

      //RETRAIT

      //Si il y a un électeur à la table de vote
      if (table_de_vote->getElecteurEnCours() != NULL) {
         //Si l'électeur présent a voter et qu'il a signer la liste et que sa durée est à 0 ou moins, Il sort de l'espace
         if (table_de_vote->getElecteurEnCours()->getDuree()<=0 && aVoter && liste_emargement[table_de_vote->getElecteurEnCours()->id()] == true) {
            cout << "      " << table_de_vote->getElecteurEnCours()->nom()<<" sort"<<endl;
            //On le retire de la table de décharge
            cout<<"  SORTIE"<<endl;
            cout<<"      " << table_de_vote->getElecteurEnCours()->nom() <<" sort"<<endl;
            table_de_vote->sortirElecteur();
            //On réinitialise aPrisSesBulletins
            aVoter = false;
         }
      }
      
      
      //Désincrémentation des durée de chaque électeur
      for ( long unsigned int k = 0 ; k < presidentielle->getListeElecteur().size() ; k++){
         presidentielle->getListeElecteur()[k]->setDuree(presidentielle->getListeElecteur()[k]->getDuree()-1);
      }

      if(T==Tmax){
         cout<<"FERMETURE ENTREE"<<endl;
      }

      T++; 


   }//Fin BOUCLE PRINCIPAL


   cout<<endl;
   cout<<"RESULTAT DU BUREAU 254:"<<endl;
   cout<<"PRESIDENT : " << *(president)<<endl;
   cout<<endl;

   cout << "nb electeurs : " << presidentielle->getListeElecteur().size() << endl;
   cout << "nb vote : " << nbVote << endl;

   std::cout << std::fixed << std::setprecision(2); // Limite à 4 décimales
   cout << "Participation : " << static_cast<double>(nbVote) / presidentielle->getListeElecteur().size() * 100 <<"%" << endl;
   cout << "Abstention : " <<100 - static_cast<double>(nbVote) / presidentielle->getListeElecteur().size() * 100 << "%" << endl;

   cout<<endl;
   cout << "Dépouillement : " << endl;
   cout<<endl;

   int nbVotant = (static_cast<double>(nbVote)+nbVoteNul / presidentielle->getListeElecteur().size());
   
   table_de_vote->afficherUrne(nbVotant);
   cout << "vote nul : " << nbVoteNul << " (" << static_cast<double>(nbVoteNul) / presidentielle->getListeElecteur().size() * 100 << "% )" << endl;



    // destruction des personnes
   for (Personne* psn : vp)
   {
      delete psn;
   }

   return 0;

   //destruction des objets
   table_de_vote->~Espace();
   table_de_decharge->~Espace();
   isoloir->~Isoloir();
   presidentielle->~Election();
   delete tabTempEntrée;
   
}
