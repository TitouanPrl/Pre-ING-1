#ifndef __PUISSANCE4_H
#define __PUISSANCE4_H
/*! 
 *  \file puissance4.h
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Thu 04 February 2021 - 16:41:46
 *
 *  \brief prototypes des fonctions du puissance 4
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
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
 *  \def ERREUR_ALLOCATION -1
 *  \brief erreur renvoyée pour une erreur d'allocation
 */
#define ERREUR_ALLOCATION -1 
/*! 
 \def ERREUR
  Message affiché quand il y a une erreur
*/
#define ERREUR(message) fprintf(stderr, '%s\n', message)
/*! 
 *  \def RED "\e[0;31m"
 *  \brief couleur rouge
 */
#define RED "\e[0;31m" 
/*! 
 *  \def YEL "\e[0;33m"
 *  \brief couleur jaune
 */
#define YEL "\e[0;33m" 
/*! 
 *  \def reset "\e[0m"
 *  \brief couleur par défaut
 */
#define reset "\e[0m" 




int** allouer(int taille);

void initialiser(int** p_tab, int taille);

void afficher(int** p_tab, int taille);

int jouer(int** p_tab, int taille, int joueur);

int aGagne(int** p_tab,int taille);

void tourDeJeu(int** p_tab,int taille);

#endif 