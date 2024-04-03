/**
 * \file tableDeVote.hpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"

#ifndef TABLEDEVOTE_HPP
#define TABLEDEVOTE_HPP



class TableDeVote : public Espace {
    public:
        TableDeVote(const int De, const std::string& nom,const int nb_elec, float proba);
        void signer_liste(int ID);
        bool a_signer(int ID);
        float getProbaBlanc();
        void setProbaBlanc(float p);

    private:
        bool* liste_emargement;
        float proba_null;
        int nb_electeur;




};

#endif