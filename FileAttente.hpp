/**
 * \file FileAttente.hpp
 *  \author Bertrand RIVARD
*/

#include <list>
#include "Personne.hpp"


#ifndef FILEATTENTE_HPP
#define FILEATTENTE_HPP


class FileAttente {
    public :   

        FileAttente();  /*! Constructeur par défaut */
	    ~FileAttente(); /*! Destructeur */
        void ajouter(elections::Personne* pPers); /*! Ajoute une personne à la file d'attente */
        elections::Personne* sortir(); /*! Retire et renvoie le premier de la file d'attente */   
        bool estVide();       /*! Renvoie vrai si la file d'attente est vide */


    private :

        std::list<elections::Personne*> file; /*! La file d'attente */
};


#endif