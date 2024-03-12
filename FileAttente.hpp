/**
 * \file FileAttente.hpp
 *  \author Bertrand RIVARD
*/

#include <list>
#include "Personne.hpp"


#ifndef TABLEDECHARGE_HPP
#define TABLEDECHARGE_HPP


class FileAttente {
    public :   

        FileAttente();  /*! Constructeur par défaut */
	    ~FileAttente(); /*! Destructeur */
        void ajouter(elections::Personne* pPers); /*! Ajoute une personne à la file d'attente */
        elections::Personne sortir(); /*! Retire et renvoie le premier de la file d'attente */    


    private :

        std::list<elections::Personne*> file; /*! La file d'attente */
};


#endif