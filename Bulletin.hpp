/**
 * \file Bulletin.hpp
 *  \author Bertrand RIVARD Hugo Piard
*/

#include "Personne.hpp"


#ifndef BULLETIN_HPP
#define BULLETIN_HPP

class Bulletin {

    public:

    Bulletin(elections::Personne* candidat);
    std::string  getCandiat(); // Le contenu du bulletin

    private:

    elections::Personne* candidat; 
};

#endif