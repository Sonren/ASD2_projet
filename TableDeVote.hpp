/**
 * \file tableDeVote.hpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"

#ifndef TABLEDEVOTE_HPP
#define TABLEDEVOTE_HPP



class TableDeVote : public Espace {
    public:

        TableDeVote(const int De, const std::string& nom,const int nb_elec);
        void signer_liste(int ID);
        bool a_signer(int ID);
        void vote();

    private:
    
        bool* liste_emargement;
        int nb_electeur;




};

#endif