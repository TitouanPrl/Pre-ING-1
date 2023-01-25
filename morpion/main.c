/*! 
 *  \file Morpion.c
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 11 December 2020 - 10:50:29
 *
 *  \brief Morpion avec deux joueurs (aled)
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
 *  \def MAX_NAME_SIZE 20
 *  \brief Taille maximale de la chaine "prenom" du joueur
 */
#define MAX_NAME_SIZE 20 
/*! 
 *  \def N
 *  \brief Taille du tableau
 */
#define N 3

/*!
 *  \struct joueur
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 18 December 2020 - 08:20:22
 *  \brief Définit la structure qui peut prendre les différents choix du joueur, vide, rond, croix
 *  \param prenom : prenom du joueur
 *  \param age : age du joueur
 */

typedef struct {
    char prenom[MAX_NAME_SIZE];
    int age;
}joueur;

/*!
 *  \enum valeur
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 18 December 2020 - 16:29:46
 *  \brief remplace VIDE, ROND, et CROIX par les caractères demandés
 *  \param VIDE : permet d'afficher un espace
 *  \param ROND : permet d'afficher O
 *  \param CROIX : permet d'afficher X
 */
typedef enum {
    VIDE=' ', 
    ROND='O', 
    CROIX='X',
} valeur; 



/*!
 *  \fn void affGrille(valeur grille[N][N])
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 18 December 2020 - 08:05:27
 *  \brief procédure qui crée la grille du morpion
 *  \param grille : taille du tableau servant de grille pour le morpion
 */
 void affGrille(valeur grille[N][N]) {

     int i;
     int j;

        for (j=0; j<N; j++){
            for (i=0; i<N; i++){
                printf("|%c|",grille[j][i]);
            }
            printf("\n");
        }
}

/*!
 *  \fn void joue(valeur grille[N][N], int joueur, int coordX, int coordY)
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.2
 *  \date Fri 18 December 2020 - 08:31:08
 *  \brief procédure qui attribue à une case la valeur jouée
 *  \param grille : tableau de jeu
 *  \param joueur : numéro du joueur
 *  \param coordX : coordonnée où placer le jeton selon X
 *  \param coordY : coordonnée où placer le jeton selon Y
 */

void joue(valeur grille[N][N], int joueur, int coordX, int coordY) {
     if (joueur == 1){
         grille[coordY][coordX] = CROIX;
     }
     else if (joueur == 2) {
         grille[coordY][coordX] = ROND;
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
 *  \fn void tour(valeur grille [N][N], int joueur)
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 1.1
 *  \date Fri 18 December 2020 - 09:10:21
 *  \brief Permet au joueur dont c'est le tour, de jouer 
 *  \param grille : tableau de jeu
 *  \param joueur : joueur dont c'est le tour
 */
void tour(valeur grille [N][N], int joueur) {
     int coordX;
     int coordY;
    do {
        printf("Jouez dans une case comprise entre 0 et 2 et qui soit encore vide. (0 étant la première case et 2 la dernière) \n");
        printf("\n Coordonnée de X : ");
        coordX = demandeValeur();
        printf("\n Coordonnée de Y : ");
        coordY = demandeValeur();
    } while ((coordX < 0 || coordX >= N) || (coordY < 0 || coordY >= N) || !(grille[coordY][coordX] == VIDE));
    joue(grille, joueur, coordX, coordY); 

}

/*!
 *  \fn int gagne(valeur grille[N][N])
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 18 December 2020 - 10:44:53
 *  \brief Vérifie si un joueur a gagné
 *  \param grille : tableau de jeu
 *  \return le nom du gagnant s'il y en a un et continue la partie sinon
 */
int gagne(valeur grille[N][N]) {
    int i = 0;
    int valeur = 0; //Numéro du joueur
    char res = VIDE; //Permet de récupérer la valeur de la première case de la ligne gagnante pour savoir quel joueur a gagné

    while ((i < N) && (res == VIDE)) {
        if ((grille[2][0] != VIDE) && (grille[2][0] == grille[1][1]) && (grille[1][1] == grille[0][2])) {
            res = grille[2][0];
        }
        else if ((grille[0][2] != VIDE) && (grille[0][2] == grille[1][1]) && (grille[1][1] == grille[2][0])) {
            res = grille[0][2];
        }
        else if  ((grille[i][0] != VIDE) && (grille[i][0] == grille[i][1]) && (grille[i][1] == grille[i][2])) {             
            res = grille[i][0];
        }
        else if ((grille[0][i] != VIDE) && (grille[0][i] == grille[1][i]) && (grille[1][i] == grille[2][i])) {
            res = grille[0][i];
        }
      
        else {
            res = VIDE;
        }
        i++;      
    }   
    if (res == CROIX)
    {
        valeur = 1;
    }
    else if (res == ROND)
    {
        valeur = 2;
    }
    return (valeur); 
}
     
/*!
 *  \fn int demandeAvis(char prenom[MAX_NAME_SIZE], char bis[MAX_NAME_SIZE])
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 18 December 2020 - 12:51:56
 *  \brief retourne l'id de celui qui commence
 *  \param prenom[MAX_NAME_SIZE] : prenom de la personne pour l'affichage
 *  \param bis[MAX_NAME_SIZE] : prenom de la personne pour le random
 *  \return entier représetant le joueur qui commence
 */
int demandeAvis(char prenom[MAX_NAME_SIZE], char bis[MAX_NAME_SIZE]) {
     int retour = 0;
     if (prenom[0] == '\0')
     {
         retour = rand()%2 + 1;
         if (retour == 1)
         {
             printf("Par le pouvoir du random %s jouera avec les X (donc en premier) \n", bis);
         }
         else
         {
             printf("Par le pouvoir du random %s jouera avec les O (donc en deuxième) \n", bis);
         }             
     }
     else
     {
         do
         {
            printf("Tapez 1 pour prendre les X (et commencer) et 2 pour prendre les O (et ne pas commencer) : \n");
            retour = demandeValeur();
            printf("\n");
         } while (retour != 1 && retour != 2);     
     }
    return (retour);
}

/*!
 *  \fn int quiCommence(joueur joueur1, joueur joueur2)
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 18 December 2020 - 08:13:12
 *  \brief fonction qui choisit le joueur qui peut choisir le caractère qu'il veut jouer, affiche son prénom, et lui demande de choisir entre X et O
 *  \param joueur1 : premier joueur
 *  \param joueur2 : deuxième joueur
 *  \return 
 */
int quiCommence(joueur joueur1, joueur joueur2) {

    if (joueur1.age > joueur2.age) {
        printf("C'est à %s de choisir\n", joueur1.prenom);
        return(demandeAvis(joueur1.prenom, ""));
    }
    else if (joueur1.age < joueur2.age) {
        printf("C'est à %s de choisir\n", joueur2.prenom);
        return(demandeAvis(joueur2.prenom, ""));
    }
    else {
        if (strcmp(joueur1.prenom, joueur2.prenom) < 0) {
            printf("C'est à %s de choisir\n", joueur2.prenom);
            return(demandeAvis(joueur2.prenom, ""));
        }
        else if (strcmp(joueur1.prenom, joueur2.prenom) > 0) {
            printf("C'est à %s de choisir\n", joueur1.prenom);
            return(demandeAvis(joueur1.prenom, ""));
        }
        else {
            printf("Démerdez-vous...");
            return (demandeAvis("", joueur1.prenom));
        }                                                                                                     
    }
}

/*!
 *  \fn joueur demandeInfos(char prenom[MAX_NAME_SIZE])
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 18 December 2020 - 13:06:56
 *  \brief demande au joueur ses infos
 *  \param nom : nom du joueur
 *  \return un joueur complété
 */
joueur demandeInfos(char prenom[MAX_NAME_SIZE]) {
    joueur joueurACompleter;
    printf("Informations du %s : \n", prenom);
    printf("Votre age : ");
    joueurACompleter.age = demandeValeur();
    printf("Votre prénom (moins de 20 caractères) : \n");
    scanf("%s", joueurACompleter.prenom);
     return (joueurACompleter);
}

/*!
 *  \fn void jeu(valeur grille[N][N])
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 18 December 2020 - 12:19:41
 *  \brief permet de jouer
 *  \param grille : tableau de jeu
 */
void jeu(valeur grille[N][N], joueur joueur1, joueur joueur2) {
    int nbTours = 0;
    int idJoueur;
    int gagnant = 0;

     idJoueur = quiCommence(joueur1, joueur2);
     do
     {
         affGrille(grille);
         nbTours++;
        tour(grille, idJoueur);
        if (nbTours >=5)
        {
            gagnant = gagne(grille);
        }
        
         idJoueur = (idJoueur%2)+1;
     } while (gagnant == 0 && nbTours < 9);
     if (gagnant ==1)
     {
         printf("Félicitations, c'est le joueur aux (X) qui a gagné ! \n");
     }
     else if (gagnant == 2)
     {
         printf("Féliciations, c'est le joueur aux (O) qui a gagné ! \n");
     }
     else
     {
         printf("Match nul... Better luck next time ! \n");
     }      
}


/*!
 *  \fn int main (int argc, char** argv)
 *  \author PRADAL Titouan <pradaltito@eisti.eu>
 *  \version 0.1
 *  \date Fri 11 December 2020 - 10:50:40
 *  \brief Affiche un morpion et permet à deux personnes d'y jouer (en choisissant qui joue en premier en fonction de prenom/age)
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres 
 *  \return 0 si tout s'est bien passé
 */
int main (int argc, char** argv) {
    printf("Bienvenue dans ce Morpion ! \n\
    Il faut être deux pour jouer. \n\
    \n Bon jeu ! \n\n");

    srand(time(NULL));

    joueur joueur1;
    joueur joueur2;
    valeur grille[N][N]= {{VIDE, VIDE, VIDE}, {VIDE, VIDE, VIDE}, {VIDE, VIDE, VIDE}}; 

    joueur1 = demandeInfos("Joueur 1");
    joueur2 = demandeInfos ("Joueur 2");
    jeu(grille, joueur1, joueur2);
    return (EXIT_SUCCESS);
}