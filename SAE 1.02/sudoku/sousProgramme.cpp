/**
 * @file main.cpp
 * @author johan.Rouyer  dylan.Victoras
 * @brief sous programme sudoku
 * @date 2023-01-07
 **/

#include "sousProgrammes.h"
#include "game-tools.h"
#include <iostream>
using namespace std;

void afficherRegles()
{
    cout << "Le joueur doit completer une grille (9 x 9) de valeurs, de sorte a ce que :" << endl;
    cout << "- chaque ligne de la grille," << endl;
    cout << "- chaque colonne de la grille" << endl;
    cout << "- et chaque zone (3 x 3) de la grille contienne les valeurs 1, 2, 3, 4, 5, 6, 7, 8 et 9." << endl;
    cout << "Une grille incomplete est proposee au joueur en debut de partie.A chaque tour le joueur propose une valeur a placer sur la grille." << endl;
    cout << "Le joueur gagne lorsqu il complete la grille correctement." << endl
         << "Le joueur perd lorsqu il a consomme un nombre de droits a l erreur predefini." << endl
         << endl;
}

void afficherGrille(char grilleInc[TAILLE_SUDOKU][TAILLE_SUDOKU], char grille[TAILLE_SUDOKU][TAILLE_SUDOKU], const unsigned short int TAILLE_SUDOKU, unsigned short int nbCoord)
{
    cout << "     1 2 3    4 5 6    7 8 9 " << endl
         << "    -------  -------  -------" << endl;
    // afficher les diffèrentes valeurs de la grille.

    for (unsigned short int x = 0; x <= TAILLE_SUDOKU - 1; x++)
    {
        cout << nbCoord << " || ";
        nbCoord++;
        // afficher les valeurs en couleur.
        for (unsigned short int y = 0; y <= TAILLE_SUDOKU - 1; y++)
        {
            // verifier les valeurs et l'afficher dans la couleur correspondante.
            if (grille[x][y] == '.')
            {
                afficherTexteEnCouleur(grille[x][y], bleu);
            }
            else if (grille[x][y] != '.' && grilleInc[x][y] != '.')
            {
                afficherTexteEnCouleur(grille[x][y], jaune);
            }
            else
            {
                afficherTexteEnCouleur(grille[x][y], rouge);
            }

            cout << " ";
            // afficher la barre de séparation verticale.
            if (y == 2 || y == 5)
            {
                cout << "|| ";
            }
        }
        cout << "|| " << nbCoord - 1 << endl;

        // afficher la barre de séparation horizontale.
        if (x == 2 || x == 5 || x == TAILLE_SUDOKU - 1)
        {
            cout << "    -------  -------  -------" << endl;
        }
    }
    cout << "     1 2 3    4 5 6    7 8 9 " << endl;
}

void afficherInfos(unsigned int nbErreurs, unsigned short int erreursMax, unsigned int &nbTours)
{

    cout << "tour numero " << nbTours << ", erreurs numero " << nbErreurs << "/" << erreursMax << endl
         << "Proposition (cf. ligne colonne valeur) ? ";
    nbTours++;
}

void verifValCoord(bool &abandon, bool &perdu, unsigned int &nbErreurs, unsigned short int erreursMax, char grilleInc[TAILLE_SUDOKU][TAILLE_SUDOKU], char grille[TAILLE_SUDOKU][TAILLE_SUDOKU])
{
    unsigned short int coordX;
    unsigned short int coordY;
    char valJoueur;
    bool valPossibles = false;
    bool tabValPossibles[TAILLE_SUDOKU] = {
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
    }; // tableau permetant de savoir les valeurs possible  pouvant etre placer à l'emplacement du sudoku

    cin >> coordX >> coordY >> valJoueur;

    // verifier la saisie du joueur.
    if (coordX == 0 && coordY == 0 && valJoueur == '0')
    {
        // abandon
        abandon = true;
    }
    else if ((coordX < 1 || coordY < 1 || valJoueur < '1') && (coordX > 1 || coordY > 1 || valJoueur > '1'))
    {
        // saisie incorrect.
        cout << "ERREUR DE SAISIE, ressayer !!!" << endl;
        nbErreurs++;
        pause(1);
        effacer();
    }
    else if (grilleInc[coordX - 1][coordY - 1] != '.')
    {
        // saisie grille sur grille de depart.
        cout << "SAISIE SUR GRILLE DE DEPART, ressayer !!!" << endl;
        nbErreurs++;
        pause(1);
        effacer();
    }
    else
    {
        // valeurs possibles

        // verifier les valeurs présente dans la ligne.
        for (unsigned short int i = 0; i <= TAILLE_SUDOKU - 1; i++)
        {
            // verifier et ajouter la valeurs au tableau valTabPossibles.
            for (char o = '1'; o <= '9'; o++)
            {

                if (grille[coordX - 1][i] == o) // verifie si il y a une valeur
                {
                    tabValPossibles[o - '1'] = true;
                    if (o == valJoueur) // verifie si la valeurs est égale a celle du joueurs
                    {
                        valPossibles = true;
                    }
                }
            }
        }
        // verifier les valeurs présente dans la colonne.
        for (unsigned short int i = 0; i <= TAILLE_SUDOKU - 1; i++)
        {
            // verifier et ajouter la valeurs au tableau valTabPossibles.
            for (char o = '1'; o <= '9'; o++)
            {
                if (grille[i][coordY - 1] == o) // verifie si il y a une valeur
                {
                    tabValPossibles[o - '1'] = true;
                    if (o == valJoueur) // verifie si la valeurs est égale a celle du joueurs
                    {
                        valPossibles = true;
                    }
                }
            }
        }
        // Vérifie les valeurs présentes dans le carré 3 par 3.

        // Calcule les coordonnées du coin supérieur gauche du carré 3x3.
        int debutLigne = (coordX - 1) - (coordX - 1) % 3;
        int debutColonne = (coordY - 1) - (coordY - 1) % 3;

        // Parcours les lignes du carré 3x3
        for (int l = debutLigne; l < debutLigne + 3; l++)
        {
            // Parcours les colonnes du carré 3x3
            for (int c = debutColonne; c < debutColonne + 3; c++)
            {
                for (char o = '1'; o <= '9'; o++)
                {
                    if (grille[l][c] == o) // verifie si il y a une valeur
                    {
                        tabValPossibles[o - '1'] = true;
                        if (o == valJoueur) // verifie si la valeurs est égale a celle du joueurs
                        {
                            valPossibles = true;
                        }
                    }
                }
            }
        }
        // verifier si la valeur du joueur est compat.
        if (valPossibles)
        {
            // afficher les valeurs possibles
            cout << "Erreur # valeur incompatible # " << endl
                 << "Les valeurs possibles sont : ";

            for (unsigned short int o = 0; o <= TAILLE_SUDOKU - 1; o++)
            {
                if (tabValPossibles[o] == false)
                {
                    cout << o + 1 << " ";
                }
            }
            nbErreurs++;
            cout << endl;
            pause(5);
        }
        else if (!valPossibles)
        {
            // placer valJoueur dans la grille
            cout << "oui ! " << endl;
            if (grille[coordX - 1][coordY - 1] != '.')
            {
                cout << "valeur " << grille[coordX - 1][coordY - 1] << " modifiee en ";

                grille[coordX - 1][coordY - 1] = valJoueur;

                cout << grille[coordX - 1][coordY - 1] << endl;
            }
            else
            {

                grille[coordX - 1][coordY - 1] = valJoueur;
            }
        }
        pause(3);
        effacer();
    }
    // verifier si le nombres d'erreurs est égale au nombre d'erreurMax
    if (nbErreurs == erreursMax)
    {
        perdu = true;
    }
}

void GagnerPartie(char grille[TAILLE_SUDOKU][TAILLE_SUDOKU], bool &gagner)
{
    bool trouver;
    trouver = false;
    // parcourir les lignes de la grille.
    for (unsigned short int i = 0; i <= TAILLE_SUDOKU - 1; i++)
    {
        // parcourir les colonnes de la grille.
        for (unsigned short int o = 0; o <= TAILLE_SUDOKU - 1; o++)
        {
            if (grille[i][o] == '.') // verifier si il y a un points
            {
                trouver = true;
            }
        }
    }
    // verifier si un point a était trouver
    if (!trouver)
    {
        gagner = true;
    }
}

void finPartie(bool abandon, bool perdu, bool gagner, unsigned int &nbErreurs, unsigned short int erreursMax, unsigned int nbTours)
{

    // verifier l'état de fin.
    if (abandon)
    {
        cout << "ABANDON PARTIE !!!";
    }
    else if (perdu)
    {
        cout << "PARTIE PERDU, vous avez fais " << nbErreurs << " erreurs sur " << erreursMax << ".";
    }
    else if (gagner)
    {
        cout << "PARTIE GANER, bravos vous avez gagner en " << nbTours << "tours et avec " << nbErreurs << " erreurs sur " << erreursMax;
    }
}