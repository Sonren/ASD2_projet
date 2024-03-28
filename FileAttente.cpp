/**
 * \file FileAttente.cpp
 *  \author Bertrand RIVARD Hugo PIARD
*/

#include "FileAttente.hpp"

FileAttente::FileAttente() {
    // constructeur par défaut,
    // aucune initialisation nécessaire pour l'attribut "file"
}

FileAttente::~FileAttente() {
    //destructeur
    //supprime tous les éléments de la liste "file"
    while (!file.empty()) {
        delete file.front(); // supprime la personne pointée par le premier élément de la liste
        file.pop_front(); // supprime le premier élément de la liste
    }
}

void FileAttente::enfiler(elections::Personne* pPers) {
    // ajoute une personne à la file d'attente
    file.push_back(pPers); // ajoute la personne à la fin de la liste
}

elections::Personne* FileAttente::defiler() {
    // retire et renvoie le premier de la file d'attente
    if (file.empty()) {
        throw std::runtime_error("La file d'attente est vide"); // lève une exception si la file d'attente est vide
    }
    elections::Personne* pPers = file.front(); // récupère le premier élément de la liste
    file.pop_front(); // supprime le premier élément de la liste
    return pPers; // renvoie la personne pointée par le premier élément de la liste
}

bool FileAttente::estVide() {
    return file.empty(); // si la liste est vide, renvoie vrai
}

