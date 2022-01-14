/**
 * @file main.cpp
 * Main Minesweeper
 * @authors: DA CONCEICAO Mauro 
 * @groupe: 109
 * @date de création: 12/01/21
*/

#include <cstdlib>
#include <iostream>
#include "Demineur.h"
using namespace std;

int main(int argc, char **argv) {
    int nouveau;
    Jeu jeu;
    cout<< "Entrez le nombre de lignes, le nombre de colonnes et le nombre de mines: "<< endl;
    Probleme(jeu);
    do {
        Afficher(jeu);
        cout << "Générer un nouveau coup au hasard? 1 pour oui 0 pour non" << endl;
        cin >> nouveau;
        if (nouveau==1) NouveauCoup(jeu);
        else InterCde(jeu);
        etatJeu(jeu);
    } while (jeu.etat==en_cours);
    cout << "la " << jeu.etat << endl;
    Afficher(jeu);
    delete [] jeu.tab;
}
