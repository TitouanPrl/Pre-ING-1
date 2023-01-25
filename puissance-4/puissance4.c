/*! 
 *  \file puissance4.c
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Thu 04 February 2021 - 21:26:01
 *
 *  \brief corps des fonctions
 *
 *
 */

#include "puissance4.h"


/*!
 *  \fn int** allouer(int taille)
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Thu 04 February 2021 - 15:54:03
 *  \brief alloue la mémoire pour le tableau de jeu
 *  \param taille : taille du tableau de jeu du puissance 4
 *  \return p_tab 
 */
int** allouer(int taille) {

    int** p_tab;
    /* Allocation première dimension */
    p_tab = malloc(taille * sizeof(int *));

    /* Vérification allocation première dimension */
    if (p_tab == NULL)
    {
        ERREUR ("Une erreur s'est produite lors de l'allocation de la première dimension.");
        exit(ERREUR_ALLOCATION);
    }

    /* Allocation seconde dimension */
    for (int i = 0; i < taille; i++)
    {
        (p_tab)[i] = malloc(taille * sizeof(int));

        /* Vérification allocation seconde dimension */
        if ((p_tab)[i] == NULL)
        {
        ERREUR ("Une erreur s'est produite lors de l'allocation de la deuxième dimension.");
        exit(ERREUR_ALLOCATION);
        }
    }
     
     return (p_tab);
}

/*!
 *  \proc void initialiser(int** p_tab, int taille)
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Thu 04 February 2021 - 16:22:39
 *  \brief initialise les cases à -1
 *  \param p_tab : tableau de jeu
 *  \param taille : taille du tableau de jeu
 */
void initialiser(int** p_tab, int taille) {
     for (int i = 0; i < taille; i++)
     {
         for (int j = 0; j < taille; j++)
         {
             p_tab[i][j] = -1;
         }
         
     }
     
}

/*!
 *  \proc void afficher(int** p_tab, int taille)
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Thu 04 February 2021 - 17:03:55
 *  \brief affiche le tableau
 *  \param p_tab : grille de jeu
 *  \param taille : taille de la grille de jeu
 */
void afficher(int** p_tab, int taille) {
    for (int i = 0; i < taille; i++)
    {
        printf("---------- \n");
        for (int j = 0; j < taille; j++)
        {
            switch(p_tab[i][j]){
                case 1 :
                    printf("| " RED "X ", reset);
                break;

                case 2 :
                    printf("| " YEL "O ", reset);
                break;

                default :
                    printf("|   ");
                break;
            }
            
        }
    printf("\n");

    }
         
}
/*!
 *  \fn int demandeValeur()
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Thu 04 February 2021 - 18:13:14
 *  \brief demande la valeur à jouer
 *  \return la valeur à jouer
 */
int demandeValeur() {
    int valeur = 0;
    int retour = 0;

    printf("Veuillez saisir la colonne où vous voulez jouer (entre 0 et %d) \n");
    retour = scanf("%d", &valeur);
    if (retour == 0){
        ERREUR("une erreur de lecture s'est produite. \n");
        exit(ERREUR_SAISIE);
    }
     
     return (valeur);
}


/*!
 *  \fn int jouer (int** plateau, int taille, int joueur)
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Thu 04 February 2021 - 17:34:29
 *  \brief permet de jouer
 *  \param p_tab : grille de jeu
 *  \param taille : taille de la grille de jeu
 *  \param joueur : joueur dont c'est le tour
 *  \return 
 */
int jouer (int** p_tab, int taille, int joueur) {
     int res;
     int colonne;
     int i = taille-1;
     colonne = demandeValeur();

     if (colonne > -1 && colonne < taille-1){
         if (p_tab[0][colonne] == -1){
             res = 1;
             while (p_tab[i][colonne] !=1)      //remonte dans la colonne tant que la case n'est pas vide
             {
                 i--;
             }
             if (joueur == 1){                  //définit le symbole à jouer en fonction du joueur dont c'est le tour
                 p_tab[i][colonne] = 1;
             }
             else if (joueur == 2){
                 p_tab[i][colonne] = 2;
             }
             else {
                 ERREUR ("une erreur de lecture s'est produite. \n");
             }
             
         }
         else {
             res = -1;
         }
     }
     else {
         res = -1;
     }
    
     return (res);
}

/*!
 *  \fn int aGagne (int** plateau, int taille)
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Mon 15 February 2021 - 17:07:21
 *  \brief permet de savoir si un joueur a gagné
 *  \param plateau : plateau de jeu
 *  \param taille : taille du plateau de jeu
 *  \return 1 ou 2 (le numéro du joueur) s'il y a un gagnant, 0 si match nul, et -1 si pas terminée
 */
int aGagne (int** p_tab, int taille) {
    int gagne = -1;

    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            //Tests des colonnes
            if (p_tab[i][j] != -1 && p_tab[i][j+1] == p_tab[i][j] && p_tab[i][j+2] == p_tab[i][j] && p_tab[i][j+3] == p_tab[i][j] && j+3 < taille) 
            {
                gagne = p_tab[i][j];
            }
            
            else if (p_tab[i][j] != -1 && p_tab[i][j-1] == p_tab[i][j] && p_tab[i][j+1] == p_tab[i][j] && p_tab[i][j+2] == p_tab[i][j] && j+2 < taille && j-1 > -1) 
            {
                gagne = p_tab[i][j];
            }

            else if (p_tab[i][j] != -1 && p_tab[i][j-2] == p_tab[i][j] && p_tab[i][j-1] == p_tab[i][j] && p_tab[i][j+1] == p_tab[i][j] && j+1 < taille && j-2 > -1) 
            {
                gagne = p_tab[i][j];
            }

            else if (p_tab[i][j] != -1 && p_tab[i][j-3] == p_tab[i][j] && p_tab[i][j-2] == p_tab[i][j] && p_tab[i][j-1] == p_tab[i][j] && j-3 > -1) 
            {
                gagne = p_tab[i][j];
            }

            // Test des lignes
            else if (p_tab[i][j] != -1 && p_tab[i+1][j] == p_tab[i][j] && p_tab[i+2][j] == p_tab[i][j] && p_tab[i+3][j] == p_tab[i][j] && i+3 < taille) 
            {
                gagne = p_tab[i][j];
            }
            
            else if (p_tab[i][j] != -1 && p_tab[i-1][j] == p_tab[i][j] && p_tab[i+1][j] == p_tab[i][j] && p_tab[i+2][j] == p_tab[i][j] && i+2 < taille && i-1 > -1) 
            {
                gagne = p_tab[i][j];
            }

            else if (p_tab[i][j] != -1 && p_tab[i-2][j] == p_tab[i][j] && p_tab[i-1][j] == p_tab[i][j] && p_tab[i+1][j] == p_tab[i][j] && i+1 < taille && i-2 > -1) 
            {
                gagne = p_tab[i][j];
            }

            else if (p_tab[i][j] != -1 && p_tab[i-3][j] == p_tab[i][j] && p_tab[i-2][j] == p_tab[i][j] && p_tab[i-1][j] == p_tab[i][j] && i-3 > -1) 
            {
                gagne = p_tab[i][j];
            }

            //Tests des diagonales ==> fucked up (à refaire)
            else if (p_tab[i][j] != -1 && p_tab[i+1][j+1] == p_tab[i][j] && p_tab[i+2][j+2] == p_tab[i][j] && p_tab[i+3][j+3] == p_tab[i][j] && j+3 < taille && i+3 < taille) 
            {
                gagne = p_tab[i][j];
            }
            
            else if (p_tab[i][j] != -1 && p_tab[i-1][j-1] == p_tab[i][j] && p_tab[i+1][j+1] == p_tab[i][j] && p_tab[i+2][j+2] == p_tab[i][j] && j+2 < taille && j-1 > -1 && i+2 < taille && i-1 > -1) 
            {
                gagne = p_tab[i][j];
            }

            else if (p_tab[i][j] != -1 && p_tab[i-2][j-2] == p_tab[i][j] && p_tab[i-1][j-1] == p_tab[i][j] && p_tab[i+1][j+1] == p_tab[i][j] && j+1 < taille && j-2 > -1 && i+1 < taille && i-2 > -1) 
            {
                gagne = p_tab[i][j];
            }

            else if (p_tab[i][j] != -1 && p_tab[i-3][j-3] == p_tab[i][j] && p_tab[i-2][j-2] == p_tab[i][j] && p_tab[i-1][j-1] == p_tab[i][j] && j-3 > -1 && i-3 > -1) 
            {
                gagne = p_tab[i][j];
            }

            //Match nul
            else if (p_tab[][] != {-1})
            {
                gagne = 0;
            }
            

            //Cas où rien n'est validé
            else{
                gagne = -1;
            }
            
        }
        
    }
    
     
     return (gagne);
}

/*!
 *  \proc void tourDeJeu(int** p_tab, int taille)
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 19 February 2021 - 10:05:41
 *  \brief permet de jouer
 *  \param p_tab : tableau de jeu
 *  \param taille: taille du tableau de jeu
 */
void tourDeJeu(int** p_tab, int taille) {
    int gagne = -1;
    int joueur = 1;

    allouer(taille);
    initialiser(p_tab, taille);
    while (gagne == -1)
    {
        afficher(p_tab, taille);
        jouer(p_tab, taille, joueur);
        gagne = aGagne(p_tab, taille);

        joueur = (joueur % 2) + 1;
    }

    if (gagne == 1)
    {
        printf("Bravo Joueur 1 ! Tu as gagné ! \n");
    }
    else if (gagne == 2)
    {
        printf("Bravo Joueur 2 ! Tu as gagné ! \n");
    }
    else if (gagne == 0)
    {
        printf("C'est match nul ! Laisse le gagner la prochaine fois ! \n");
    }
    else
    {
        ERREUR("Ah il y a eu une erreur \n");
    }

}