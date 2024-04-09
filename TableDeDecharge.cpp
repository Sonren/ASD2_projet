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

TableDeDecharge::TableDeDecharge(const int De, const std::string& nom,float probaB, float probaN)
    : Espace(De, nom), proba_blanc(probaB), proba_null(probaN)
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
    int idSpolCandidat = Election::getListeCandidats()[1]->spol();
    for(int i =0; i< Election::getListeCandidats().size(); ++i){
        if(Election::getListeCandidats()[i]->spol() == Espace::getElecteurEnCours()->spol()){
            return i;
        }else{
            if(Election::getListeCandidats()[i]->spol() < abs(Espace::getElecteurEnCours( )->spol()-idSpolCandidat)){
                idSpolCandidat = Election::getListeCandidats()[i]->spol();
            }
        }
    }
    return idSpolCandidat;
}

std::vector<Personne*> TableDeDecharge::chercherListeChoix(int nbChoix){
    std::vector <Personne*> listeTempBulletin;
    if(Espace::getElecteurEnCours()->getChoix() == NULL || Espace::getElecteurEnCours()->getChoix() == Election::getBulletinBlanc()){
        for(std::vector<Personne*>::iterator it = Election::getListeCandidats().begin(); it<nbChoix; it++){
            if(Election::getListeCandidats()[it] != Election::getBulletinBlanc()){
                listeTempBulletin.push_back(*it); 
            }
        }
    }else{
        int Choix;
        Choix = trouverVote();
        for(std::vector<Personne*>::iterator it = Election::getListeCandidats().begin(); it<nbChoix; it++){
            if(Election::getListeCandidats()[it] != Election::getBulletinBlanc() || Election::getListeCandidats()[it] != Espace::getElecteurEnCours()->getChoix()){
                listeTempBulletin.push_back(*it); 
            }
        }

    }
    return listeTempBulletin;
}


void TableDeDecharge::prendreBulletin(){
    float nbBulletinAPrendre = rand() % Election::getListeCandidats().size() + 1;
    float RandomChoixVote = rand() % 10 + 1;
    while(RandomChoixVote <= Election::getListeCandidats().size()) {
        RandomChoixVote = rand() % 10 + 1;
    }
    if(RandomVote <= proba_null){
        Espace::getElecteurEnCours().ajouterBulletin(Election::ajouter_candidat(Election::getBulletinBlanc()));
        Espace::getElecteurEnCours().setChoix = NULL;   
        Espace::getElecteurEnCours()->ajouterListeBulletin(chercherListeChoix(nbBulletinAPrendre));  
    }else if(RandomVote <= proba_blanc){
        //prendre + proche et prendre blanc
        Espace::getElecteurEnCours().setChoix() = Election::ajouter_candidat(Election::getBulletinBlanc());
    }else{
        Espace::getElecteurEnCours()->setChoix() = trouverVote();
        Espace::getElecteurEnCours()->ajouterBulletin(chercherListeChoix(nbBulletinAPrendre));
    }
}
