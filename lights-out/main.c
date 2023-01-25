/*! 
 *  \file main.c
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Tue 12 January 2021 - 16:58:33
 *
 *  \brief Lights Out
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
 *  \def N 5
 *  \brief définit la taille du tableau
 */
#define N 5 

/*!
 *  \enum etat
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Thu 14 January 2021 - 14:30:49
 *  \brief etat de la lumière
 *  \param ALLUME
 *  \param ETEINT
 */

typedef enum {
   ALLUME = 1,
   ETEINT = 0,
}etat;

/*!
 *  \fn void afficher(etat grille[N][N])
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Thu 14 January 2021 - 14:32:02
 *  \brief affiche la grille de jeu
 *  \param N : nb de lignes et de colonnes
 */
void afficher(etat grille[N][N]) {

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        printf("|%d|", grille [i][j]);
      }
      printf("\n");
    
    }
}

/*!
 *  \fn joue(etat grille[N][N])
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Thu 14 January 2021 - 15:00:13
 *  \brief permet de choisir la case où jouer
 *  \param grille : tableau de jeu
 *  \return coordonnées de la case jouée
 */
void joue(etat grille[N][N],int coordX, int coordY) {
     if (grille[coordY][coordX] == ALLUME){
         grille[coordY][coordX] = ETEINT;
     }
     else if (grille[coordY][coordX] == ETEINT) {
         grille[coordY][coordX] = ALLUME;
     }
     else {
         fprintf(stderr, "une erreur de lecture s'est produite. \n");
     }
}

/*!
 *  \fn int demandeValeur()
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 18 December 2020 - 09:15:35
 *  \brief renvoit la valeur saisie par le joueur
 *  \return entier saisi
 */
int demandeValeur() {
    int valeur = 0;
    int retour = 0;
    retour = scanf("%d", &valeur);
    if (retour == 0){
        fprintf(stderr, "une erreur de lecture s'est produite. \n");
        exit(ERREUR_SAISIE);
    }
     
     return (valeur);
}

/*!
 *  \fn void basculer(etat grille[N][N])
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Thu 14 January 2021 - 14:40:06
 *  \brief remplace les valeurs des cases autour de la case jouée, si une des cases autour de la case jouée n'est pas dans le tableau alors on l'ignore
 *  \param grille : tableau de jeu
 */
void basculer(etat grille[N][N]) {
   int coordX;
   int coordY;
    do {
        printf("Jouez dans une case comprise entre 0 et 4. (0 étant la première case et 4 la dernière) \n");
        printf("\n Coordonnée de X : ");
        coordX = demandeValeur();
        printf("\n Coordonnée de Y : ");
        coordY = demandeValeur();
    } while ((coordX < 0 || coordX >= N) || (coordY < 0 || coordY >= N));
    joue(grille, coordX, coordY); 

if (coordY < N-1) {
    if (grille[coordY+1][coordX] == ALLUME)
    {
      grille[coordY+1][coordX] = ETEINT;
    }
    else if (grille[coordY+1][coordX] == ETEINT)
    {
      grille[coordY+1][coordX] = ALLUME;
    }
}

if (coordY > 0) {
    if (grille[coordY-1][coordX] == ALLUME)
    {
      grille[coordY-1][coordX] = ETEINT;
    }
    else if (grille[coordY-1][coordX] == ETEINT)
    {
      grille[coordY-1][coordX] = ALLUME;
    }
}

if (coordX < N-1) {
    if (grille[coordY][coordX+1] == ALLUME)
    {
      grille[coordY][coordX+1] = ETEINT;
    }
    else if (grille[coordY][coordX+1] == ETEINT)
    {
      grille[coordY][coordX+1] = ALLUME;
    }
}

if (coordX > 0) {
    if (grille[coordY][coordX-1] == ALLUME)
    {
      grille[coordY][coordX-1] = ETEINT;
    }
    else if (grille[coordY][coordX-1] == ETEINT)
    {
      grille[coordY][coordX-1] = ALLUME;
    }
}
    

}

/*!
 *  \fn void finDeJeu(etat grille[N][N])
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Thu 14 January 2021 - 14:45:13
 *  \brief vérifie si le jeu est fini 
 *  \param grille : tableau de jeu
 */
int finDeJeu(etat grille[N][N]) {
  int res = 0;
  int nbCase = 0;
  int nbOff = 0;

   while (res == 0 && nbCase < 25)
   {
     for (int i = 0; i < 5; i++)
     {
       for (int j = 0; j < 5; j++)
       {
         if (grille[i][j] == ETEINT)
         {
           res = 0;
           nbOff++; 
         }
         else
         {
           res = 1;
         }
        nbCase++;
        }
       
     }
     
   }
   return(nbOff);
   
}

/*!
 *  \fn int abandon()
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 15 January 2021 - 14:01:37
 *  \brief demande au joueur s'il veut abandonner
 *  \return 0 si le joueur continue et 1 si le joueur abandonne
 */
int abandon() {
   int res = 0;
   int retour = 0;

   printf("Voulez-vous abandonner ? (Entrer 0 pour non et 1 pour oui) \n");
   retour = scanf("%d", &res);

   if (retour == 0 && (res != 0 || res != 1))
   {
     fprintf(stderr, "une erreur de lecture s'est produite. \n");
        exit(ERREUR_SAISIE);
    }   

   if (res == 1)
   {
     printf("C'est dommage, tu auras plus de chance la prochaine fois ! \n");
   }
   
   return (res);
}


/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.3
 *  \date Thu 14 January 2021 - 15:20:05
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres 
 *  \return 0 si tout s'est bien passé
 */
int main (int argc, char** argv) {
  int res = 0;
  int nbTours = 1;
  int giveUp = 0;
  etat grille[N][N] = {{ETEINT, ETEINT, ETEINT, ETEINT, ETEINT}, {ETEINT, ETEINT, ETEINT, ETEINT, ETEINT}, {ALLUME, ETEINT, ALLUME, ETEINT, ALLUME}, {ETEINT, ETEINT, ETEINT, ETEINT, ETEINT}, {ETEINT, ETEINT, ETEINT, ETEINT, ETEINT}};
   
   while (res !=25 && giveUp == 0)
   {
     printf("===== Tour : %d ===== \n\n", nbTours);
     afficher(grille);
     basculer(grille);
     res = finDeJeu(grille);
     
     if (nbTours % 5 == 0 && nbTours != 0)      //Demande tous les 5 tours si le joueur veut abandonner
     {
       giveUp = abandon();
     }

     nbTours++;
     
   }

   if (giveUp == 0)
   {
     printf("Bravo tu as gagné en %d tours ! \n", nbTours);
   }
   
   
   return (EXIT_SUCCESS);
}