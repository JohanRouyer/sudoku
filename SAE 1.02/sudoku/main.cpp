/**
 * @file main.cpp
 * @author johan.Rouyer  dylan.Victoras
 * @brief code-game sudoku
 * @date 2023-01-07
 **/

#include <iostream>
#include "game-tools.h"
#include "sousProgrammes.h"
using namespace std;

char grilleInc[TAILLE_SUDOKU][TAILLE_SUDOKU] = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}; // tableau permetant d'afficher la grille de départ du sudoku.

char grille[TAILLE_SUDOKU][TAILLE_SUDOKU] = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}; // tableau permetant d'afficher la grille incomplete du sudoku que le joueur complète durant la partie.

int main()
{
    // VARIABLES

    bool abandon;                  // permet de savoir si le joueur abandonne la partie ou non (de base = faux).
    unsigned short int nbCoord;    // permet d'afficher des coordonée sur le bords de la grille (de 1 à 9) pour aider l'utilisateur a lire les lignes/colones.
    bool perdu;                    // booléen pour savoir si le joueur a perdu la partie ou non.
    unsigned short int erreursMax; // Nombres d'erreurs maximum réalisables par l'utilisateur supérieur ou égale à 3.
    unsigned int nbErreurs;        // Nombres d'erreurs réaliser par le joueur.
    unsigned int nbTours;          // Nombres de tours réaliser par le joueur au cours de la partie.
    bool gagner;                   // Permet de savoir si le Joueur a gagner la partie.

    // TRAITEMENTS
    gagner = false;
    abandon = false;
    perdu = false;
    nbCoord = 1;
    nbErreurs = 0;
    nbTours = 1;

    // demander le nombres d'erreurs tolérées >=3.
    cout << "veuillez saisir le nombre d'erreurs Max voulue superieur ou egale a 3 : " << endl;
    // récuperer erreursMax et verifier si >=3.
    do
    {
        cin >> erreursMax;
        pause(1);
        effacer();

        if (erreursMax < 3)
        {
            cout << "erreur !, veuillez saisir une valeur superieur ou egale a 3 : " << endl;
        }

    } while (erreursMax < 3);

    do
    {
        afficherRegles(); // affiche l'ensembles des règles de la partie

        afficherGrille(grilleInc, grille, TAILLE_SUDOKU, nbCoord); // affiche la grille du sudoku que le joueur remplis.

        afficherInfos(nbErreurs, erreursMax, nbTours); // affiche les infos de la partie composer des erreurs du joueur, du nombre d'ereurs maximum tolèré et du nombres de tours réalisé.

        verifValCoord(abandon, perdu, nbErreurs, erreursMax, grilleInc, grille); // vérifie les valeurs rentré par le joueur et l'emplacement de la grille afin de savoir si le joueur peux placer sa valeur.

        GagnerPartie(grille, gagner); // vérifie si le joueur a gagner la partie ou non.

    } while (!perdu && !abandon && !gagner);

    finPartie(abandon, perdu, gagner, nbErreurs, erreursMax, nbTours); // affiche les infos de fin de partie, pour savoir si le joueur a gagne/perdu/abandonner.

    return 0;
}