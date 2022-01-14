#ifndef _DEMINEUR_
#define _DEMINEUR_

// @brief Etats du jeu
enum Etat {en_cours,gagne,perdu};


// @brief Case de la grille  
struct Case{
    bool demasque; // permet de savoir si la case est démasqué
    bool mine; // permet de savoir si la case est une mine
    bool marque; // permet de savoir si la case est marqué
    bool visite; // permet de savoir si la case a deja été visité
    int minesAdj; // nombre de mines adjacentes
};


// @brief Jeu du démineur
struct Jeu{
    int nbLignes; // nombre de lignes
    int nbColonnes; // nombre de colonnes
    int nbMines; // nombre de mines
    Case** tab; // tableau des cases alloué en mémoire dynamique 
    Etat etat;  // etat du jeu
};

/**
* @brief Vérifie si le nombre entré en paramètre est deja dans le tableau d'entiers
* @param[in] nombre : le nombre
* @param[in] tab : tableau d'entiers
* @param[in] taille : taille du tableau
* @return vrai si le nombre est dans le tableau, faux sinon
*/
bool In(unsigned int nombre, unsigned int* tab, const unsigned int taille);


/**
* @brief Génere au hasard un tableau d'entiers sans doublons
* @param[in-out] grille : le jeu
* @param[in-out] tab : tableau des positions des mines
*/
void RandomPos(const Jeu& grille,unsigned int tab[grille.nbMines]);

/**
* @brief Ajoute 1 au nombre de mines adjacentes des cases qui l'entourent
* @param[in-out] grille : la jeu
* @param[in] x : la ligne sur laquelle la case minée se trouve
* @param[in] y : la colonne sur laquelle la case minée se trouve
*/
void Mines(Jeu& jeu, int x, int y);

/**
* @brief Produit un probleme a partir du nombre de lignes, colonnes et mines entrées dans le flot d'entrée standard
* @param[in-out] grille : le jeu
*/
void Probleme(Jeu& jeu);

/**
* @brief Demasque les cases qui entourent des cases ayant 0 mines adjacentes
* @param[in-out] grille : le jeu
* @param[in] x : la ligne sur laquelle la case vide se trouve
* @param[in] y : la colonne sur laquelle la case vide se trouve
*/
void Vide(Jeu& jeu, const int x, const int y);

/**
* @brief Marque la case à la position entrée en paramètre
* @param[in-out] grille : le jeu
* @param[in] position : position de la case à marquer
*/
void Marquer(Jeu& jeu, const int position);

/**
* @brief Démasque la case à la position entrée en paramètre
* @param[in-out] grille : la grille du jeu
* @param[in] position : position de la case à démasquer
*/
void Demasquer(Jeu& jeu, const int position);

/**
* @brief Interprète les commandes entrées dans le flot d'entrée standard
* @param[in-out] grille : le jeu
*/
void InterCde(Jeu& jeu);

/**
* @brief Affiche la grille d'un jeu à partir d'un probleme et un historique 
* de coups entrés dans le flot d'entrée standard
* @param[in-out] grille : le jeu
*/
void Afficher(Jeu& jeu);

/**
* @brief Determine si le jeu est gagné ou perdu
* @param[in-out] grille : le jeu
*/
void etatJeu(Jeu& jeu);

/**
* @brief Genere un nouveau coup à partir d'un jeu
* @param [in-out]: le jeu
*/
void NouveauCoup(Jeu& jeu);

#endif