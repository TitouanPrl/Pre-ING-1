#ifndef __FONCTION_H
#define __FONCTION_H

/*! 
 *  \file fonction.h
 *  \authors PRADAL Titouan <pradaltito@cy-tech.fr>, SERRES Valentin <serresvale@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>, BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 28 April 2021 - 11:47:07
 *
 *  \brief Prototypes des fonctions
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

/*! 
 \def EXIT_SUCCESS
  Code confirmant la bonne exécution du programme
*/
#define EXIT_SUCCESS 0
/*! 
 \def ERREUR_SAISIE
  Code d'erreur attestant qu'une erreur de saisie s'est produite
*/
#define ERREUR_SAISIE -1
/*! 
 \def ERREUR
  Message affiché quand il y a une erreur
*/
#define ERREUR(message) fprintf(stderr, "%s\n", message)

/*! 
 *  \def RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, RESET
 *  \brief ajout des différentes couleurs utilisables pour le texte, reset permet de remettre la couleur par défaut
 */
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

/*!
 *  \enum etat
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 14 January 2021 - 14:30:49
 *  \brief etat de la cellule
 *  \param VIVANTE si la case est pleine
 *  \param MORTE si la case est vide
 */

typedef enum {
   VIVANTE = 1,
   MORTE = 0,
}etat;

/*FONCTIONS PRINCIPALES*/

int** creatab(int lignes, int colonnes); 

void afficher(int** p_tab, int lignes, int colonnes);

int voisinFinie(int lignes, int colonnes, int coordX, int coordY, int** p_tab);

int voisinTorique(int lignes, int colonnes, int coordX, int coordY, int** p_tab);

int** swapcase(int** p_tab1, int x, int y, int voisin);

int** newtab(int** p_tab, int lignes, int colonnes, int typeMatrice);

/*SOUS-FONCTIONS*/

int bordYFinie(int coordY, int** p_tab, int i, int colonnes);

int bordYTorique(int coordY, int coordX, int** p_tab, int i, int colonnes, int lignes, int tmp);

int bordXTorique(int coordX, int lignes, int j, int** p_tab);

int milieuTorique(int coordX, int coordY, int** p_tab, int lignes, int colonnes);

int coinSE(int lignes, int colonnes, int coordX, int coordY, int** p_tab);

int coinNE(int lignes, int colonnes, int coordX, int coordY, int** p_tab);

int coinSO(int lignes, int colonnes, int coordX, int coordY, int** p_tab);

int coinNO(int lignes, int colonnes, int coordX, int coordY, int** p_tab);

void petitBonus(int typeMatrice);

void initTab(int lignes, int colonnes, int** p_tab);

void jeuDeLaVie(int** p_tab, int lignes, int colonnes, int typeMatrice, int boucles);

void freeTab(int** p_tab);

#endif