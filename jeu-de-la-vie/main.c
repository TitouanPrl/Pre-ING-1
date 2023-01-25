/*! 
 *  \file main.c
 *  \authors PRADAL Titouan <pradaltito@cy-tech.fr>, SERRES Valentin <serresvale@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>, BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 28 April 2021 - 12:00:43
 *
 *  \brief programme principal
 *
 *
 */
#include "fonction.h"

/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>, SERRES Valentin <serresvale@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>, BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 03 May 2021 - 12:20:34
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres 
 *  \return 0 si tout s'est bien passé
 */
 int main (int argc, char** argv) {

     int lignes, colonnes, boucles, typeMatrice;
     int** p_tab = NULL;
     float duree;
     clock_t debut, fin;

     debut = clock();       /*Heure de début du programme*/

     scanf("%d", &lignes);		/*Lit le nombre de lignes*/
     scanf("%d", &colonnes);	/*Lit le nombre de colonnes*/

     p_tab = creatab(lignes,colonnes);          /*Crée le tableau de jeu*/

     initTab(lignes, colonnes, p_tab);			/*Initialise le tableau aux valeurs de la matrice*/

     scanf("%d", &boucles);			/*Lit le nombre de boucles*/
     scanf("%d", &typeMatrice);		/*Lit le type de la matrice*/

     petitBonus(typeMatrice);		/*Petit bonus :) */

     jeuDeLaVie(p_tab, lignes, colonnes, typeMatrice, boucles);		/*Fait évoluer le tableau*/

     freeTab(p_tab);       /*Libère la mémoire allouée*/

     printf("Merci d'avoir exécuté le jeu de la vie du groupe Nulenk Aude ! \n");

     fin = clock();     /*Heure de fin du programme*/

     duree = (float)(fin - debut) / CLOCKS_PER_SEC;     /*On soustrait l'heure de fin à l'heure de début pour avoir le temps d'exécution du programme*/
     printf("Temps d'exécution du programme : %f \n", duree);

     return (EXIT_SUCCESS);
}