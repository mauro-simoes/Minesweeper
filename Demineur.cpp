/**
 * @file Operation1.cpp
 * Demineur
 * @authors: DA CONCEICAO Mauro et NOUIRA Meriem
 * @groupe: 109
 * @date de création: 12/01/21
*/


#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cassert>
#include "Demineur.h"
#include "ConteneurTDE.h"
using namespace std;


// OPÉRATION 1 

/**
* @brief Vérifie si le nombre entré en paramètre est deja dans le tableau d'entiers
* @param[in] nombre : le nombre
* @param[in] tab : tableau d'entiers
* @param[in] taille : taille du tableau
* @return vrai si le nombre est dans le tableau, faux sinon
*/
bool In(unsigned int nombre, unsigned int* tab, const unsigned int taille){
    int i;
    for (i=0;i<taille;i++){
        if (nombre == tab[i]){
            return true;
        }
    }
    return false;
}

/**
* @brief Génere au hasard un tableau d'entiers sans doublons
* @param[in-out] grille : le jeu
* @param[in-out] tab : tableau des positions des mines
*/
void RandomPos(const Jeu& jeu,unsigned int tab[jeu.nbMines]){ 
    srand (time(NULL));
    unsigned int positionR, limite=(jeu.nbColonnes*jeu.nbLignes)-1;
    unsigned int taille=0;
    for(int i=0; i<jeu.nbMines;i++){
        positionR=rand()%limite;
        while (In(positionR,tab,taille)){
            // tant que le nombre genéré au hasard est deja dans le tableau de nombre on genere à nouveau un nombre
            positionR=rand()%limite;
        }
        tab[i]=positionR;
        taille++;
    }
}


/**
* @brief Ajoute 1 au nombre de mines adjacentes des cases qui l'entourent
* @param[in-out] grille : la jeu
* @param[in] x : la ligne sur laquelle la case minée se trouve
* @param[in] y : la colonne sur laquelle la case minée se trouve
* @pre : x et y compris entre 0 et le nombre de cases du jeu
*/
void Mines(Jeu& jeu, int x, int y){
    assert((x>=0 && y>=0) && (x<jeu.nbColonnes*jeu.nbLignes && y<jeu.nbColonnes*jeu.nbLignes ));
    if (x>0){
        jeu.tab[x-1][y].minesAdj++;
    }  
    if (x<jeu.nbLignes-1){
        jeu.tab[x+1][y].minesAdj++;
    }
    if (y>0){
        jeu.tab[x][y-1].minesAdj++;
    }  
    if (y<jeu.nbColonnes){
        jeu.tab[x][y+1].minesAdj++;
    } 
    if (x>0 && y>0){
        jeu.tab[x-1][y-1].minesAdj++;
    } 
    if (x>0 && y< jeu.nbColonnes-1){
        jeu.tab[x-1][y+1].minesAdj++;
    } 
    if (x<jeu.nbLignes-1 && y>0){
        jeu.tab[x+1][y-1].minesAdj++;
    } 
    if (x<jeu.nbLignes-1 && y< jeu.nbColonnes-1){
        jeu.tab[x+1][y+1].minesAdj++;
    } 
}


/**
* @brief Produit un probleme a partir du nombre de lignes, colonnes et mines entrées dans le flot d'entrée standard
* @param[in-out] grille : le jeu
* @param[in] afficher : booléen pour afficher ou non l'emplacement des mines
*/
void Probleme(Jeu& jeu){
    int i,j,x,y,position;
    cin >> jeu.nbLignes >> jeu.nbColonnes >> jeu.nbMines;
    jeu.tab= new Case*[jeu.nbLignes];
    for(i = 0; i < jeu.nbLignes; ++i){
        jeu.tab[i] = new Case[jeu.nbColonnes];
    }
    for (i=0;i<jeu.nbLignes;i++){
        for (j=0;j<jeu.nbColonnes;j++){
            jeu.tab[i][j].demasque=false;
            jeu.tab[i][j].mine=false;
            jeu.tab[i][j].marque=false;
            jeu.tab[i][j].visite=false;
            jeu.tab[i][j].minesAdj=0;
        }
    }
    unsigned int nombres[jeu.nbMines];
    RandomPos(jeu,nombres);
    for (i=0;i<jeu.nbMines;i++){
        position=nombres[i];
        jeu.tab[position/jeu.nbColonnes][position%jeu.nbColonnes].mine=true;
        Mines(jeu, position/jeu.nbColonnes, position%jeu.nbColonnes);
    }
}

/**
* @brief Demasque les cases qui entourent des cases ayant 0 mines adjacentes
* @param[in-out] grille : le jeu
* @param[in] x : la ligne sur laquelle la case vide se trouve
* @param[in] y : la colonne sur laquelle la case vide se trouve
* @pre : x et y compris entre 0 et le nombre de cases du jeu
*/
void Vide(Jeu& jeu, int x, int y){
    assert((x>=0 && y>=0) && (x<jeu.nbColonnes*jeu.nbLignes && y<jeu.nbColonnes*jeu.nbLignes ));
    // condition d'arret: si la case a deja été visité ou la case a au moins une mine adjacente
    if (!jeu.tab[x][y].visite && jeu.tab[x][y].minesAdj==0){
        jeu.tab[x][y].visite=true;
        if (x>0){
            jeu.tab[x-1][y].demasque=true;
            if (jeu.tab[x-1][y].minesAdj==0){
                Vide(jeu,x-1,y);
            }
            jeu.tab[x-1][y].visite=true;
        }  
        if (x<jeu.nbLignes-1){
            jeu.tab[x+1][y].demasque=true;
            if (jeu.tab[x+1][y].minesAdj==0){
                Vide(jeu,x+1,y);
            }
            jeu.tab[x+1][y].visite=true;
        }
        if (y>0){
            jeu.tab[x][y-1].demasque=true;
            if (jeu.tab[x][y-1].minesAdj==0){
                Vide(jeu,x,y-1);
            }
            jeu.tab[x][y-1].visite=true;
        }  
        if (y<jeu.nbColonnes){
            jeu.tab[x][y+1].demasque=true;
            if (jeu.tab[x][y+1].minesAdj==0){
                Vide(jeu,x,y+1);
            }
            jeu.tab[x][y+1].visite=true;
        } 
        if (x>0 && y>0){
            jeu.tab[x-1][y-1].demasque=true;
            if (jeu.tab[x-1][y-1].minesAdj==0){
                Vide(jeu,x-1,y-1);
            }
            jeu.tab[x-1][y-1].visite=true;
        } 
        if (x>0 && y< jeu.nbColonnes-1){
            jeu.tab[x-1][y+1].demasque=true;
            if (jeu.tab[x-1][y+1].minesAdj==0){
                Vide(jeu,x-1,y+1);
            }
            jeu.tab[x-1][y+1].visite=true;
        } 
        if (x<jeu.nbLignes-1 && y>0){
            jeu.tab[x+1][y-1].demasque=true;
            if (jeu.tab[x+1][y-1].minesAdj==0){
                Vide(jeu,x+1,y-1);
            }
            jeu.tab[x+1][y-1].visite=true;
        } 
        if (x<jeu.nbLignes-1 && y< jeu.nbColonnes-1){
            jeu.tab[x+1][y+1].demasque=true;
            if (jeu.tab[x+1][y+1].minesAdj==0){
                Vide(jeu,x+1,y+1);
            }
            jeu.tab[x+1][y+1].visite=true;
        } 
    }
}


/**
* @brief Marque la case à la position entrée en paramètre
* @param[in-out] grille : le jeu
* @param[in] position : position de la case à marquer
*/
void Marquer(Jeu& jeu, const int position){
    int i = position/jeu.nbColonnes, j = position%jeu.nbColonnes;
    if  ( jeu.tab[i][j].mine == false){
        jeu.etat = perdu;
        jeu.tab[i][j].marque = true;
    }
    else{
        jeu.etat=en_cours;
        jeu.tab[i][j].marque = true;
        jeu.tab[i][j].visite = true;
    }
}


/**
* @brief Démasque la case à la position entrée en paramètre
* @param[in-out] grille : la grille du jeu
* @param[in] position : position de la case à démasquer
*/
void Demasquer(Jeu& jeu, const int position){
    int i = position/jeu.nbColonnes, j = position%jeu.nbColonnes;
    if  ( jeu.tab[i][j].mine == true){
        jeu.etat = perdu;
    }
    else{
        jeu.etat=en_cours;
        jeu.tab[i][j].demasque = true;
        if (jeu.tab[i][j].minesAdj==0){
            Vide(jeu,i,j);
        }
        jeu.tab[i][j].visite = true;
    }
}


/**
* @brief Interprète les commandes entrées dans le flot d'entrée standard
* @param[in-out] grille : le jeu
*/
void InterCde(Jeu& jeu){
    jeu.etat = en_cours;
    int nbCommandes,i,nombre;
    string commande;
    cin >> commande;
    string nombreS ="";
    // on extrait la position de la commande puis on le convertit en un entier
    for (i=1;i<commande.length();i++){
        nombreS += commande[i];
    }
    nombre= stoi(nombreS);
    int ligne = nombre/jeu.nbColonnes;
    int colonnes = nombre % jeu.nbColonnes;
    if (commande[0]=='M'){
        Marquer(jeu,nombre);
    }
    else if (commande[0]=='D'){
        Demasquer(jeu,nombre);
    }
}


/**
* @brief Affiche la grille d'un jeu à partir d'un probleme et un historique 
* de coups entrés dans le flot d'entrée standard
* @param[in-out] grille : le jeu
*/
void Afficher(Jeu& jeu){
    int i,j;
    for (i=0;i<jeu.nbLignes;i++){
        for (j=0;j<jeu.nbColonnes;j++){
            cout << " ___";
        }
        cout << endl;
        cout << "|";
        for (j=0;j<jeu.nbColonnes;j++){
            if (jeu.tab[i][j].mine==true){
                if (jeu.etat==perdu){
                    cout << " m" << " |";
                }
                else if (jeu.tab[i][j].marque==true){
                    cout << " x |";
                }
                else{
                    cout << " . |";
                }
            }
            else if (jeu.tab[i][j].demasque==true){
                if (jeu.tab[i][j].minesAdj>0){
                    cout << " " << jeu.tab[i][j].minesAdj << " |";
                }
                else{
                    cout << "   |";
                }
            }
            else if (jeu.tab[i][j].marque==true){
                cout << " x |";
            }
            else{
                cout << " . |";
            }
        }
        cout << endl;
    }
    for (i=0;i<jeu.nbColonnes;i++){
        cout << " ___";
    }
    cout << endl;
    cout << endl;
}



/**
* @brief Determine si le jeu est gagné ou perdu
* @param[in-out] grille : le jeu
*/
void etatJeu(Jeu& jeu){
    if (jeu.etat == perdu){
        cout << "game lost" << endl;
    }
    else{
        int i,j;
        bool fin=true;
        // on parcours le jeu afin de savoir si toutes les cases qui ne sont pas minées ont été démasquées
        for (i=0;i<jeu.nbLignes;++i){
            for (j=0;j<jeu.nbColonnes;j++){
                if (jeu.tab[i][j].mine==false){
                    if (jeu.tab[i][j].demasque==false){
                        fin=false;
                    }
                }
            }
        }
        if (fin==true){
            jeu.etat=gagne;
            cout << "game won" << endl;
        }
    }
}



/**
* @brief Genere un nouveau coup à partir d'un jeu
* @param [in-out]: le jeu
*/
void NouveauCoup(Jeu& jeu){
    // le conteneur va stocker les positions des cases libres
    ConteneurTDE c;
    initialiser(c,1,1);
    int i,j,position=0,nbPos=0;
    for (i=0;i<jeu.nbLignes;i++){
        for (j=0;j<jeu.nbColonnes;j++){
            if(jeu.tab[i][j].visite == false){
                ecrire(c,nbPos,position); 
                nbPos++;
            }
            position++;
        }
    } 
    srand(time(NULL));
    // on genere un indice au hasard afin de selectionner une des cases libres
    int idx=rand()%nbPos;
    // le coup peut etre soit démasqué ou marqué donc on tire soit 0 ou 1 au hasard
    int coup=rand()%2;
    position = lire(c,idx);
    if (coup==1){
        cout << "D" << position << endl;
        Demasquer(jeu,position);
    }
    else{
        cout << "M" << position<< endl;
        Marquer(jeu,position);
    }
    detruire(c);
}