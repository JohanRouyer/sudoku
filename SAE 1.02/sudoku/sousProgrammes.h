/**
 * @file main.cpp
 * @author johan.Rouyer  dylan.Victoras
 * @brief sous programme sudoku
 * @date 2023-01-07
 **/

#ifndef AFFICHER_GRILLE_H
#define AFFICHER_GRILLE_H

const unsigned short int TAILLE_SUDOKU = 9; // taille de la grille du sudoku (9x9).

void afficherRegles();
/**
 * @brief affiche l'ensembles des règles de la partie à chaque tours.
 *
 */
void afficherGrille(char grilleInc[TAILLE_SUDOKU][TAILLE_SUDOKU], char grille[TAILLE_SUDOKU][TAILLE_SUDOKU], const unsigned short int TAILLE_SUDOKU, unsigned short int nbCoord);
/**
 * @brief affiche la grille du sudoku que le joueur complète au cours de la partie.
 * @param [in] grilleInc grille de depart affiché en rouge.
 * @param [in] grille grille que le joueur rempli au cours de la partie affihé en jaune.
 * @param [in] TAILLE_SUDOKU taille de la grille du sudoku (9x9).
 * @param [in] nbCoord coordonées des difèrentes lignes.
 */

void afficherInfos(unsigned int nbErreurs, unsigned short int erreursMax, unsigned int &nbTours);
/**
 * @brief affiche les infos de la partie composer des erreurs du joueur, du nombre d'ereurs maximum tolèré et du nombres de tours réalisé.
 * @param [in] nbErreurs nombres d'erreurs réalisé par le joueur.
 * @param [in] erreursMax nombres d'erreurs maximum pouvant être réaliser par le joueur.
 * @param [in] nbTours Nombres de tours réaliser par le joueur au cours de la partie.
 *
 */

void verifValCoord(bool &abandon, bool &perdu, unsigned int &nbErreurs, unsigned short int erreursMax, char grilleInc[TAILLE_SUDOKU][TAILLE_SUDOKU], char grille[TAILLE_SUDOKU][TAILLE_SUDOKU]);
/**
 * @brief vérifie les valeurs rentré par le joueur et l'emplacement de la grille afin de savoir si le joueur peux placer sa valeur.
 * @param [in] abandon booléen pour savoir si le joueur abandonne la partie ou non.
 * @param [in] perdu booléen pour savoir si le joueur a atteind le nombres d'erreurs maximum.
 * @param [in] nbErreurs nombres d'erreurs réalisé par le joueur.
 * @param [in] erreursMax nombres d'erreurs maximum pouvant être réaliser par le joueur.
 * @param [in] grilleInc grille de depart affiché en rouge.
 * @param [in] grille grille que le joueur rempli au cours de la partie affihé en jaune.
 *
 */

void GagnerPartie(char grille[TAILLE_SUDOKU][TAILLE_SUDOKU], bool &gagner);
/**
 * @brief vérifie si le joueur a gagner la partie ou non.
 * @param [in] grille grille que le joueur rempli au cours de la partie affihé en jaune.
 * @param [in] gagner Permet de savoir si le Joueur a gagner la partie.
 */

void finPartie(bool abandon, bool perdu, bool gagner, unsigned int &nbErreurs, unsigned short int erreursMax, unsigned int nbTours);
/**
 * @brief affiche les infos de fin de partie, pour savoir si le joueur a gagne/perdu/abandonner.
 * @param [in] gagner Permet de savoir si le Joueur a gagner la partie.
 * @param [in] abandon booléen pour savoir si le joueur abandonne la partie ou non.
 * @param [in] perdu booléen pour savoir si le joueur a atteind le nombres d'erreurs maximum.
 * @param [in] nbErreurs nombres d'erreurs réalisé par le joueur.
 * @param [in] erreursMax nombres d'erreurs maximum pouvant être réaliser par le joueur.
 * @param [in] nbTours Nombres de tours réaliser par le joueur au cours de la partie.
 *
 */

#endif