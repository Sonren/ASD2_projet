/**
 * \file FileAttenteCapacite.hpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "FileAttente.hpp"

#ifndef FILEATTENTECAPACITE_HPP
#define FILEATTENTECAPACITE_HPP



class FileAttenteCapacite : public FileAttente {
public:
    FileAttenteCapacite(int capacite); /*! Constructeur avec capacité maximale */
    ~FileAttenteCapacite(); /*! Destructeur */
    void enfiler(Personne* pPers) override; /*! Ajoute une personne à la file d'attente */
    bool estPleine(); /*! Renvoie vrai si la file d'attente est pleine */

private:
    int capaciteMax; /*! Capacité maximale de la file d'attente */
};

#endif // FILEATTENTECAPACITE_HPP
