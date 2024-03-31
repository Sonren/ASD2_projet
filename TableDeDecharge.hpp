/**
 * \file tableDeDecharge.hpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"

#ifndef TABLEDEDECHARGE_HPP
#define TABLEDEDECHARGE_HPP



class tableDeDecharge : public Espace {
    public:
        tableDeDecharge(int nb_electeur);
        float getProbaBlanc();
        void setProbaBlanc();

    private:
        float proba_blanc;



};

#endif