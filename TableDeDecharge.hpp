/**
 * \file tableDeDecharge.hpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "Espace.hpp"

#ifndef TABLEDEDECHARGE_HPP
#define TABLEDEDECHARGE_HPP



class TableDeDecharge : public Espace {
    public:
        TableDeDecharge(const int De, const std::string& nom,float proba);
        float getProbaBlanc();
        void setProbaBlanc(float p);

    private:
        float proba_blanc;
};

#endif