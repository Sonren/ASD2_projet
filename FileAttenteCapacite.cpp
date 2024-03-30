/**
 * \file FileAttenteCapacite.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "FileAttenteCapacite.hpp"

FileAttenteCapacite::FileAttenteCapacite(int capacite) : capaciteMax(capacite) {
    // Constructeur avec capacité maximale
}

FileAttenteCapacite::~FileAttenteCapacite() {
    // Destructeur
    // Supprime tous les éléments de la liste "file"
    while (!file.empty()) {
        delete file.front(); // Supprime la personne pointée par le premier élément de la liste
        file.pop_front(); // Supprime le premier élément de la liste
    }
}

void FileAttenteCapacite::enfiler(Personne* pPers) override{
    // Ajoute une personne à la file d'attente
    if (estPleine()) {
        throw std::runtime_error("La file d'attente est pleine"); // Lève une exception si la file d'attente est pleine
    }
    FileAttente::enfiler(pPers); // Appel de la méthode enfiler de la classe de base
}

bool FileAttenteCapacite::estPleine() {
    return file.size() >= capaciteMax; // Renvoie vrai si la taille de la file d'attente atteint la capacité maximale
}
