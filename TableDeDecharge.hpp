/**
 * \file tableDeDecharge.hpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"

#ifndef TABLEDEDECHARGE_HPP
#define TABLEDEDECHARGE_HPP



class TableDeDecharge : public Espace {
    public:
        TableDeDecharge(const int De, const std::string& nom,float probaB, float  probaN);
        float getProbaBlanc();
        void setProbaBlanc(float p);
        float getProbaNull();
        void setProbaNull(float p);
        void prendreBulletin(Electeur elec);

    private:
        float proba_blanc;
        float proba_null;
};

#endif