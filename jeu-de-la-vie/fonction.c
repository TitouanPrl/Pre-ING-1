/*! 
 *  \file fonction.c
 *  \authors PRADAL Titouan <pradaltito@cy-tech.fr>, SERRES Valentin <serresvale@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>, BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 28 April 2021 - 11:50:28
 *
 *  \brief Corps des fonctions
 *
 *
 */

#include "fonction.h"

/*!
 *  \fn int** creatab(int a, int b)
 *  \author BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 03 May 2021 - 12:24:30
 *  \brief crée un tableau
 *  \param colonnes le nombre de colonnes de la matrice
 *  \param lignes le nombre de lignes de la matrice
 *  \return le tableau créé
 */
int** creatab(int lignes, int colonnes) {
    int** p_tab;
    int i;

    p_tab = malloc(lignes * sizeof (int*));       /*Allocation de la mémoire pour les lignes*/

    for (i = 0; i < lignes; i++){                 /*Allocation de la mémoire pour les colonnes*/
        p_tab[i] = malloc(colonnes * sizeof(int));
    }

    return p_tab;
}

/*!
 *  \proc void afficher(int** p_tab, int a, int b)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 03 May 2021 - 12:26:42
 *  \brief affiche un tableau
 *  \param colonnes le nombre de colonnes de la matrice
 *  \param lignes le nombre de lignes de la matrice
 *  \param p_tab le tableau de jeu
 */
void afficher(int** p_tab, int lignes, int colonnes) {
     printf(MAGENTA);
     printf("╔");  
     for(int i=0; i<colonnes-1; i++){
         printf("═══╦");
     }

     printf("═══╗\n");
     for(int j = 0; j<colonnes; j++){
         printf("║ ");
         if(p_tab[0][j] == MORTE){
             printf("  ");
         }
         else{
             printf(RED);
             printf("◼ ");
             printf(MAGENTA);
         }
     }
     printf("║\n");
     for(int k=1; k<lignes; k++){
         printf("╠");
         for(int i=0; i<colonnes-1; i++){
             printf("═══╬");
         }
         printf("═══╣\n");
         for (int l=0; l<colonnes; l++){
             printf("║ ");
            
             if(p_tab[k][l] == MORTE){
                 printf("  ");
             }
             else{
                 printf(RED);
                 printf("◼ ");
                 printf(MAGENTA);
             }   
         }

         printf("║\n");
     }
     printf("╚");
     for(int i=0; i<colonnes-1; i++){
         printf("═══╩");
     }
     printf("═══╝");

     printf("\n");
     printf(RESET);     /*Remet la couleur de caractère par défaut*/
}

/*!
 *  \fn int bordYFinie(int coordY, int** p_tab, int i, int colonnes)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 12 May 2021 - 22:01:59
 *  \brief fonctions qui calcule le nombre de voisin sur les lignes d'une matrice finie
 *  \param coordY la colonne de la cellule dont on cherche les voisins
 *  \param p_tab le tableau de jeu
 *  \param i la ligne en cours de vérification
 *  \param colonnes le nombre de colonnes du tableau de jeu
 *  \return le nb de voisins de la ligne sélectionnée
 */
int bordYFinie(int coordY, int** p_tab, int i, int colonnes) {
     int res = 0;
    
        /*Bord Ouest*/
        if (coordY == 0)
        {
            for (int j = coordY; j < coordY+2; j++)
            {
                if (p_tab[i][j] == VIVANTE)
                {
                    res++;
                }
                
            }
            
        }

        /*Bord Est*/
        else if (coordY == colonnes-1)
        {
            for (int j = coordY-1; j < coordY+1; j++)
            {
                if (p_tab[i][j] == VIVANTE)
                {
                    res++;
                }
                
            }
            
        }
        
        /*Autre cas*/
        else
        {
            for (int j = coordY-1; j < coordY+2; j++)
            {
                if (p_tab[i][j] == VIVANTE)
                {
                    res++;
                }
                
            }
            
        }

     return (res);
}

/*!
 *  \fn int voisinFinie(int** p_tab, int lignes, int colonnes, int coordX, int coordY)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 28 April 2021 - 12:08:58
 *  \brief permet de recenser le nombre de voisins d'une cellule dans une matrice finie
 *  \param lignes le nombre de lignes du tableau 
 *  \param colonnes le nombre de colonnes du tableau
 *  \param coordX la ligne de la cellule dont on cherche les voisins
 *  \param coordY la colonne de la cellule dont on cherche les voisins
 *  \param p_tab la matrice de jeu
 *  \return le nombre de voisin
 */
int voisinFinie(int lignes, int colonnes, int coordX, int coordY, int** p_tab) {
    int nbVoisins = 0;
    
    /*Bord Nord*/
    if (coordX == 0)
    {
        for (int i = coordX; i < coordX+2; i++)
        {
            nbVoisins = nbVoisins + bordYFinie(coordY, p_tab, i, colonnes);
        }
        
    }

    /*Bord Sud*/
    else if (coordX == lignes-1)
    {
        for (int i = coordX-1; i < coordX+1; i++)
        {
            nbVoisins = nbVoisins + bordYFinie(coordY, p_tab, i, colonnes);
        }
        
    }

    /*Autre cas*/
    else
    {
        for (int i = coordX-1; i < coordX+2; i++)
        {
            nbVoisins = nbVoisins + bordYFinie(coordY, p_tab, i, colonnes);
        }
        
    }

    /*On supprime la cellule elle-même du décompte des voisins*/
    if (p_tab[coordX][coordY] == VIVANTE)
    {
        nbVoisins = nbVoisins - 1;
    }

    return(nbVoisins);
}

/*!
 *  \fn int bordYTorique(int coordY, int** p_tab, int i, int colonnes)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 20 May 2021 - 19:13:47
 *  \brief fonctions qui calcule le nombre de voisin sur les lignes d'une matrice torique
 *  \param coordY la colonne de la cellule dont on cherche les voisins
 *  \param coordX la ligne de la cellule dont on cherche les voisins
 *  \param p_tab le tableau de jeu
 *  \param i la ligne en cours de vérification
 *  \param colonnes le nombre de colonnes du tableau de jeu
 *  \param lignes le nombre de lignes du tableau de jeu
 *  \param tmp Variable permettant de vérifier si on a déjà compter les voisins de l'aspect torique
 *  \return le nb de voisins de la ligne sélectionnée
 */
int bordYTorique(int coordY, int coordX, int** p_tab, int i, int colonnes, int lignes, int tmp) {
     int res = 0;
    
        /*Bord Ouest*/
        if (coordY == 0)
        {
            for (int j = coordY; j < coordY+2; j++)
            {
                if (p_tab[i][j] == VIVANTE)
                {
                    res++;
                }

                if (tmp == 0)
                {
                    res = res + bordXTorique(coordX, lignes, j, p_tab);
                }
                
            }

            if (p_tab[i][colonnes-1] == VIVANTE)
            {
                res++;
            }
            
        }

        /*Bord Est*/
        else if (coordY == colonnes-1)
        {
            for (int j = coordY-1; j < coordY+1; j++)
            {
                if (p_tab[i][j] == VIVANTE)
                {
                    res++;
                }

                if (tmp == 0)
                {
                    res = res + bordXTorique(coordX, lignes, j, p_tab);
                }
                
            }

            if (p_tab[i][0] == VIVANTE)
            {
                res++;
            }
            
        }
        
        /*Autre cas*/
        else
        {
            for (int j = coordY-1; j < coordY+2; j++)
            {
                if (p_tab[i][j] == VIVANTE)
                {
                    res++;
                }

                if (tmp == 0)
                {
                    res = res + bordXTorique(coordX, lignes, j, p_tab);
                }
                
            }
            
        }

     return (res);
}

/*!
 *  \fn int bordXTorique(int coordX, int lignes, int j, int** p_tab)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 20 May 2021 - 19:59:12
 *  \brief vérifie les voisins de l'aspect torique
 *  \param coordX la ligne de la cellule dont on cherche les voisins
 *  \param p_tab le tableau de jeu
 *  \param j la colonne en cours de vérification
 *  \param lignes le nombre de lignes du tableau de jeu
 *  \return les voisins au bord opposé
 */
int bordXTorique(int coordX, int lignes, int j, int** p_tab) {
     int res = 0;

    if (coordX == 0)
    {
        if (p_tab[lignes-1][j] == VIVANTE)
        {
            res++;
        }
            
    }

    else if (coordX == lignes-1)
    {
        if (p_tab[0][j] == VIVANTE)
        {
            res++;
        }
    }

     return (res);
}

/*!
 *  \fn int milieuTorique(int coordY, int** p_tab, int i, int lignes)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Thu 20 May 2021 - 19:14:04
 *  \brief fonctions qui calcule le nombre de voisin pour une cellule au milieu d'une matrice torique
 *  \param coordX la ligne de la cellule dont on cherche les voisins
 *  \param coordY la colonne de la cellule dont on cherche les voisins
 *  \param p_tab le tableau de jeu
 *  \param i la colonne en cours de vérification
 *  \param lignes le nombre de lignes du tableau de jeu
 *  \param colonnes le nombre de colonnes du tableau de jeu
 *  \return le nb de voisins de la cellule sélectionnée
 */
int milieuTorique(int coordX, int coordY, int** p_tab, int lignes, int colonnes) {
    int res = 0;
    int tmp = 0;        /*Variable permettant de vérifier si on a déjà compter les voisins de l'aspect torique*/

    /*Bord Nord*/
    if (coordX == 0)
    {
        for (int i = coordX; i < coordX+2; i++)
        {
            res = res + bordYTorique(coordY, coordX, p_tab, i, colonnes, lignes, tmp);
            tmp++;
        }
       
    }

    /*Bord Sud*/
    else if (coordX == lignes-1)
    {
        for (int i = coordX-1; i < coordX+1; i++)
        {
            res = res + bordYTorique(coordY, coordX, p_tab, i, colonnes, lignes, tmp);
            tmp++;
        }
        
    }

    /*Autre cas*/
    else
    {
        for (int i = coordX-1; i < coordX+2; i++)
        {
            res = res + bordYTorique(coordY, coordX, p_tab, i, colonnes, lignes, tmp);
            tmp++;
        }
        
    }

    return(res);
}

/*!
 *  \fn int coinSE(int lignes, int colonnes, int coordX, int coordY, int** p_tab)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 12 May 2021 - 23:21:12
 *  \brief permet de recenser le nombre de voisin spécifiques à l'aspect torique de la matrice pour le coin Sud-Est
 *  \param lignes le nombre de lignes du tableau 
 *  \param colonnes le nombre de colonnes du tableau
 *  \param coordX la ligne de la cellule dont on cherche les voisins
 *  \param coordY la colonne de la cellule dont on cherche les voisins
 *  \param p_tab la matrice de jeu
 *  \return le nombre de voisin spécifiques à l'aspect torique de la matrice
 */
int coinSE(int lignes, int colonnes, int coordX, int coordY, int** p_tab) {
    int res = 0;

    /*Coin Sud-Est*/
    if ((coordX == lignes-1) && (coordY == colonnes-1))
    {
        if (p_tab[0][0] == VIVANTE)
        {
            res++;
        }

    }
     
     return (res);
}

/*!
 *  \fn int coinNE(int lignes, int colonnes, int coordX, int coordY, int** p_tab)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 12 May 2021 - 23:21:12
 *  \brief permet de recenser le nombre de voisin d'une cellule dans une matrice torique pour le coin Nord-Est
 *  \param lignes le nombre de lignes du tableau 
 *  \param colonnes le nombre de colonnes du tableau
 *  \param coordX la ligne de la cellule dont on cherche les voisins
 *  \param coordY la colonne de la cellule dont on cherche les voisins
 *  \param p_tab la matrice de jeu
 *  \return le nombre de voisin spécifiques à l'aspect torique de la matrice
 */
int coinNE(int lignes, int colonnes, int coordX, int coordY, int** p_tab) {
    int res = 0;

    /*Coin Nord-Est*/
    if ((coordX == 0) && (coordY == colonnes-1))
    {
        if (p_tab[lignes-1][0] == VIVANTE)
        {
            res++;
        }
    }
     
     return (res);
}

/*!
 *  \fn int coinSO(int lignes, int colonnes, int coordX, int coordY, int** p_tab)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 12 May 2021 - 23:21:12
 *  \brief permet de recenser le nombre de voisin d'une cellule dans une matrice torique pour le coin Sud-Ouest
 *  \param lignes le nombre de lignes du tableau 
 *  \param colonnes le nombre de colonnes du tableau
 *  \param coordX la ligne de la cellule dont on cherche les voisins
 *  \param coordY la colonne de la cellule dont on cherche les voisins
 *  \param p_tab la matrice de jeu
 *  \return le nombre de voisin spécifiques à l'aspect torique de la matrice
 */
int coinSO(int lignes, int colonnes, int coordX, int coordY, int** p_tab) {
    int res = 0;

    /*Coin Sud-Ouest*/
    if ((coordX == lignes-1) && (coordY == 0))
    {
        if (p_tab[0][colonnes-1] == VIVANTE)
        {
            res++;
        }
    }
     
     return (res);
}

/*!
 *  \fn int coinNO(int lignes, int colonnes, int coordX, int coordY, int** p_tab)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 12 May 2021 - 23:21:12
 *  \brief permet de recenser le nombre de voisin d'une cellule dans une matrice torique pour le coin Nord-Ouest
 *  \param lignes le nombre de lignes du tableau 
 *  \param colonnes le nombre de colonnes du tableau
 *  \param coordX la ligne de la cellule dont on cherche les voisins
 *  \param coordY la colonne de la cellule dont on cherche les voisins
 *  \param p_tab la matrice de jeu
 *  \return le nombre de voisin spécifiques à l'aspect torique de la matrice
 */
int coinNO(int lignes, int colonnes, int coordX, int coordY, int** p_tab) {
    int res = 0;

    /*Coin Nord-Ouest*/
    if ((coordX == 0) && (coordY == 0))
    {
        if (p_tab[lignes-1][colonnes-1] == VIVANTE)
        {
            res++;
        }
    }
     
     return (res);
}

/*!
 *  \fn int voisinTorique(int lignes, int colonnes, int coordX, int coordY, int** p_tab)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 03 May 2021 - 12:00:28
 *  \brief permet de recenser le nombre de voisin d'une cellule dans une matrice torique
 *  \param lignes le nombre de lignes du tableau 
 *  \param colonnes le nombre de colonnes du tableau
 *  \param coordX la ligne de la cellule dont on cherche les voisins
 *  \param coordY la colonne de la cellule dont on cherche les voisins
 *  \param p_tab la matrice de jeu
 *  \return le nombre de voisin
 */
int voisinTorique(int lignes, int colonnes, int coordX, int coordY, int** p_tab) {
     int nbVoisins = 0;

     /*Voisins d'une cellule en milieu de tableau*/
     nbVoisins = nbVoisins + milieuTorique(coordX, coordY, p_tab, lignes, colonnes);

     /*Voisins Sud-Est matrice torique*/
     nbVoisins = nbVoisins + coinSE(lignes, colonnes, coordX, coordY, p_tab); 

     /*Voisins Nord-Est matrice torique*/
     nbVoisins = nbVoisins + coinNE(lignes, colonnes, coordX, coordY, p_tab);

     /*Voisins Sud-Ouest matrice torique*/
     nbVoisins = nbVoisins + coinSO(lignes, colonnes, coordX, coordY, p_tab);

     /*Voisins Nord-Ouest matrice torique*/
     nbVoisins = nbVoisins + coinNO(lignes, colonnes, coordX, coordY, p_tab);

     /*On supprime la cellule elle-même du décompte des voisins*/
     if (p_tab[coordX][coordY] == VIVANTE)
     {
         nbVoisins = nbVoisins - 1;
     }
     
     return (nbVoisins);
}

/*!
 *  \fn int** swapcase(int** p_tabres, int x, int y, int voisin)
 *  \author JAULIN Gautier <jaulingaut@cy-tech.fr>, BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 03 May 2021 - 12:31:13
 *  \brief change la valeur d'une cellule de VIVANTE à MORTE ou inversement
 *  \param p_tabres la matrice de l'état actuel du motif
 *  \param x la ligne de la cellule
 *  \param y la colonne de la cellule
 *  \param voisin le nombre de voisin
 *  \return la nouvelle valeur de la cellule
 */
int** swapcase(int** p_tabres, int x, int y, int voisin) {

    /*Les cas où la cellule vit*/
    if((p_tabres[x][y] == VIVANTE) && ((voisin == 2) || (voisin == 3))){
        p_tabres[x][y] = VIVANTE;
    }
    else if((p_tabres[x][y] == MORTE) && (voisin == 3)){
        p_tabres[x][y] = VIVANTE;
    }

    /*Les cas où la cellule meurt*/
    else{
        p_tabres[x][y] = MORTE;
    }
    
    return p_tabres;
}

/*!
 *  \fn int** newtab(int** p_tab, int lignes, int colonnes)
 *  \author JAULIN Gautier <jaulingaut@cy-tech.fr>, BIGOT Léo-Paul <bigotleopa@cy-tech.fr>, PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Mon 03 May 2021 - 12:39:26
 *  \brief permet de créer un tableau en prenant en compte les nouvelles cellules mortes et vivantes
 *  \param p_tab la matrice en entrée
 *  \param lignes le nombre de lignes du nouveau tableau
 *  \param colonnes le nombre de colonnes du nouveau tableau
 *  \return le tableau avec l'état des cellules à jour
 */
int** newtab(int** p_tab, int lignes, int colonnes, int typeMatrice) {
    int** p_tabres;
    int voisin;

    p_tabres = creatab(lignes, colonnes);   /*On alloue la mémoire pour le tableau témoin*/

    for (int i = 0; i < lignes; i++)        /*On remplit le tableau témoin avec p_tab pour pouvoir ensuite modifier directement p_tab sans rendre faux le décompte des voisins*/
    {
        for (int j = 0; j < colonnes; j++)
        {
            p_tabres[i][j] = p_tab[i][j]; 
        }
        
    }
    

    if (typeMatrice == 0)       /*Cas de la matrice finie*/
    {
        for(int i=0; i<lignes; i++){
            for (int j=0; j<colonnes; j++){
                voisin = voisinFinie(lignes,colonnes, i, j, p_tabres);
           
                p_tab = swapcase(p_tab, i, j, voisin);
            }
        }
    }
    
    else if (typeMatrice == 1)       /*Cas de la matrice torique*/
    {
        for(int i=0; i<lignes; i++){
            for (int j=0; j<colonnes; j++){
                voisin = voisinTorique(lignes,colonnes, i, j, p_tabres);
           
                p_tab = swapcase(p_tab, i, j, voisin);
            }
        }
    }

    else
    {
        ERREUR("Il y a une erreur dans le type de la matrice (veuillez rentrer un 0 ou un 1)");      /*Arrête le programme et renvoi un message d'erreur si le type de matrice rentré ne convient pas*/
        exit(ERREUR_SAISIE);        /*Arrête le programme*/
    }

    return (p_tab);
}

/*!
 *  \proc void petitBonus(int typeMatrice)
 *  \author BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1
 *  \date Sun 23 May 2021 - 20:19:49
 *  \brief petit bonus :)
 *  \param typeMatrice le type de la matrice
 */
void petitBonus(int typeMatrice) {
     if (typeMatrice == 2)
     {
         printf(RED);
         printf("You've been rolled :) ! \n");
         system("xdg-open https://www.youtube.com/watch?v=dQw4w9WgXcQ");
     }
}

/*!
 *  \proc void initTab(int lignes, int colonnes, int** p_tab)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>, BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1
 *  \date Sun 23 May 2021 - 20:26:54
 *  \brief initialise chaque case du tableau
 *  \param lignes le nombre de lignes du tableau
 *  \param colonnes le nombre de colonnes du tableau
 *  \param p_tab le tableau de jeu
 */
void initTab(int lignes, int colonnes, int** p_tab) {
     for(int i=0; i<lignes; i++){
         for (int j=0; j<colonnes; j++){        /*Remplit les cases du tableau de jeu*/
             scanf("%d", &p_tab[i][j]);
         }
     }
}

/*!
 *  \proc void jeuDeLaVie(int** p_tab, int lignes, int colonnes, int typeMatrice, int boucles)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>, JAULIN Gautier <jaulingaut@cy-tech.fr>, BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1
 *  \date Sun 23 May 2021 - 20:45:30
 *  \brief fait évoluer l'état des cellules
 *  \param lignes le nombre de lignes du tableau
 *  \param colonnes le nombre de colonnes du tableau
 *  \param p_tab le tableau de jeu
 *  \param typeMatrice le type de la matrice
 *  \param boucles le nombre de fois qu'il faut réactualiser le tableau
 */
void jeuDeLaVie(int** p_tab, int lignes, int colonnes, int typeMatrice, int boucles) {
     for(int j = 0; j < boucles; j++){      /*Fait tourner le programme autant de fois que voulu*/
         system("clear");                   /*Nettoie l'écran*/
         afficher(p_tab, lignes, colonnes);
         p_tab = newtab(p_tab, lignes, colonnes, typeMatrice);
         usleep(100000);
     }
}

/*!
 *  \proc void freeTab(int** p_tab, int lignes)
 *  \author PRADAL Titouan <pradaltito@cy-tech.fr>
 *  \version 0.1
 *  \date Sun 23 May 2021 - 21:02:25
 *  \brief libère la mémoire allouée au tableau
 *  \param p_tab le tableau que l'on veut free
 */
void freeTab(int** p_tab) {
     free(p_tab);
     p_tab = NULL;     
}