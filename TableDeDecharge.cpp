/**
 * 
 * \file tableDeDecharge.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "TableDeDecharge.hpp"
#include "Election.hpp"
#include "Personne.hpp"
#include <math.h>
#include <cstdlib> 

TableDeDecharge::TableDeDecharge(const int De, const std::string& nom, Election elec, float probaB, float probaN)
    : Espace(De, nom, elec), proba_blanc(probaB), proba_null(probaN)
{};


float TableDeDecharge::getProbaBlanc(){
    return proba_blanc;
}


void TableDeDecharge::setProbaBlanc(float p){
    proba_blanc = p;
}

float TableDeDecharge::getProbaNull(){
    return proba_null;
}
        
void TableDeDecharge::setProbaNull(float p){
    proba_null = p;
}

int TableDeDecharge::getMaxSensiPolitique(){
    return maxSensiPolitique;
}

int TableDeDecharge::trouverVote(){
    int SpolChoixCandidat = Espace::getElection().getListeCandidats()[0]->spol();
    int Getindice = 0;
    for(long unsigned int i =0; i< Espace::getElection().getListeCandidats().size(); ++i){
        if(Espace::getElection().getListeCandidats()[i]->spol() == Espace::getElecteurEnCours()->spol()){
            Getindice = i;
            return i;
        }else{
            //std::cout << " spol i de la liste : " << Espace::getElection().getListeCandidats()[i]->spol() << std::endl;
            // std::cout << " resultat du calcul : " << abs(Espace::getElecteurEnCours( )->spol()-SpolChoixCandidat) << std::endl;
            if(SpolChoixCandidat > abs(Espace::getElecteurEnCours( )->spol()-Espace::getElection().getListeCandidats()[i]->spol()) || Espace::getElection().getBulletinBlanc() != Espace::getElection().getListeCandidats()[i]){
                SpolChoixCandidat = Espace::getElection().getListeCandidats()[i]->spol();
                Getindice = i;
            }
        }
    }
    Espace::getElecteurEnCours()->ajouterBulletin(Espace::getElection().getListeCandidats()[Getindice]);
    return SpolChoixCandidat;
}

std::vector<Personne*> TableDeDecharge::chercherListeChoix(int nbChoix){
    std::vector <Personne*> listeTempBulletin;
    if(Espace::getElecteurEnCours()->getChoix() == NULL || Espace::getElecteurEnCours()->getChoix() == Espace::getElection().getBulletinBlanc()){
        for(int i = 0; i < nbChoix-1; i++){
            if(Espace::getElection().getListeCandidats()[i] != Espace::getElection().getBulletinBlanc()){
                listeTempBulletin.push_back(Espace::getElection().getListeCandidats()[i]); 
            }
        }
    }else{
        for(int i = 0; i < nbChoix; i++){
            if(Espace::getElection().getListeCandidats()[i] != Espace::getElection().getBulletinBlanc() || Espace::getElection().getListeCandidats()[i] != Espace::getElecteurEnCours()->getChoix()){
                //std::cout <<  " Boucle if push dans liste : " <<  *(Espace::getElection().getListeCandidats()[i]) << std::endl;
                listeTempBulletin.push_back(Espace::getElection().getListeCandidats()[i]); 
            }
        }

    }
    return listeTempBulletin;
}


void TableDeDecharge::prendreBulletin(){
    float nbBulletinAPrendre = 0;
    float RandomChoixVote = rand() % 10 + 1;
    while(nbBulletinAPrendre > Espace::getElection().getListeCandidats().size() || nbBulletinAPrendre < 2) {
        nbBulletinAPrendre = rand() % 10 + 2;
    }
    //std::cout << "NbBulletin : " << nbBulletinAPrendre << std::endl;
    //std::cout << " proba null : " << proba_null << " proba blanc : " << proba_blanc << std::endl;
   // std::cout << "randomChoixVote : " <<  RandomChoixVote << std::endl;
    //std::cout << "liste de candidat : " << std::endl;
    //Espace::getElection().afficher_candidat();
  //  std::cout << " electeur : " <<  Espace::getElecteurEnCours()->spol() << std::endl;
    if(RandomChoixVote <= proba_null*10){
        std::cout << "Coucou null" << std::endl;
        Espace::getElecteurEnCours()->ajouterBulletin(Espace::getElection().getBulletinBlanc());
        Espace::getElecteurEnCours()->setChoix(NULL);   
    }else if(RandomChoixVote <= proba_blanc*10){
        std::cout << "Coucou blanc" << std::endl;
        Espace::getElecteurEnCours()->setChoix(Espace::getElection().getBulletinBlanc());
        Espace::getElecteurEnCours()->ajouterBulletin(Espace::getElection().getBulletinBlanc());
    }else{
        std::cout << "Coucou normal" << std::endl;
        int choix = trouverVote();
        Espace::getElecteurEnCours()->setChoix(Espace::getElection().getListeCandidats()[choix]);
        std::cout << " Choix vote : " << *(Espace::getElecteurEnCours()->getChoix()) << std::endl;
    }
    Espace::getElecteurEnCours()->ajouterListeBulletin(chercherListeChoix(nbBulletinAPrendre));
}
