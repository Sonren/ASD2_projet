/**
 * \file FileAttente.hpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include <list>
#include "Personne.hpp"


#ifndef FILEATTENTE_HPP
#define FILEATTENTE_HPP

using namespace elections;

class FileAttente {
    public :   

        FileAttente();  /*! Constructeur par défaut */
	    ~FileAttente(); /*! Destructeur */
        void enfiler(Personne* pPers); /*! Ajoute une personne à la file d'attente */
        Personne* defiler(); /*! Retire et renvoie le premier de la file d'attente */   
        bool estVide();       /*! Renvoie vrai si la file d'attente est vide */


    private :

        std::list<Personne*> file; /*! La file d'attente */
};


#endif //FILEATTENTE_HPP