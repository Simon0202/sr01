/*
 
 Ex5 : jeu de la vie ex5.c
 (pour tester le jeu vous pouvez lancer ~sr01/td/td4/jeuvie2)

 Le jeu de la vie évolue normalement sur un damier infini. Chaque case est occupée par une cellule qui peut être vivante ou morte.
 A chaque génération, chaque cellule peut naître, mourir, ou rester dans son état. Les règles qui permettent de passer d'une
 génération à l'autre sont précises et ont été choisies avec soin pour que l'évolution des organismes soit intéressante et imprévisible.
 En premier lieu, notons que sur un damier infini, chaque case a exactement 8 voisins. Pour créer la génération suivante à partir
 de la génération courante, J. Conway a fixé les règles suivantes :
 • Une cellule ayant exactement 2 ou 3 voisins vivants survit la génération suivante.
 • Une cellule ayant au moins 4 cellules voisines vivantes meurt d'étouffement à la génération suivante.
 • Une cellule ayant au plus une cellule voisine vivante meurt d'isolement à la génération suivante.
 • Sur une case vide ayant exactement 3 voisins vivants, une cellule naîtra à la génération suivante.
 Afin d'implémenter ce jeu, on considère le damier infini comme une matrice "torique". Le damier sera représenté par une matrice
 dont les bords droite et gauche sont reliés entre eux, ainsi que les bords supérieur et inférieur.
 ￼￼￼￼￼￼￼￼￼
 Codez ce jeu, en découpant soigneusement votre programme en plusieurs fonctions (fonction d'initialisation du damier , fonction
 de calcul de nombre de voisins, fonction d'affichage, ...)
 Vous pouvez utiliser la fonction rand() pour l'initialisation du damier.
 Soignez l'affichage, pour pouvoir suivre l'évolution des cellules d'une génération à l'autre.
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 50
#define CYCLE 200


int comptNbVoisins(int **sousmatrice)
{
    int i, j;
    int compteur_Nb_Voisins;
    
    for (i=0 ; i<3 ; i++){
        for (j=0 ; j<3 ; j++)
        {
            if(sousmatrice[i][j]==1)
                compteur_Nb_Voisins++;
        }
    }
    //Fin Comptage
    
    if (sousmatrice[1][1] == 1)
        compteur_Nb_Voisins--;
    
    return compteur_Nb_Voisins;
}






int AnalyseMatrice(int **matrice, int l, int c)
{
    int i, j, k, t;
    int sous_Matrice[3][3];
    
    for(k=0,i=l-1 ; i<=l+1 ; i++,k++)
    {
        for(t=0,j=c-1 ; j<=c+1 ; t++,j++)
        {
            sous_Matrice[k][t]=matrice[(i+TAILLE)%TAILLE][(j+TAILLE)%TAILLE];
        }
    }
    
    return comptNbVoisins(sous_Matrice);
}




void initialiser(int matrice[TAILLE][TAILLE])
{
    int i,j;
    
    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            matrice[i][j]=rand()%(1);
        }
    }
    
}

void modifierMatrice(int **matrice)
{
    int i, j;
    
    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            if(matrice[i][j]==1)
            {
                switch(AnalyseMatrice(matrice,i,j))
                {
                       case '0..1':
                           matrice[i][j]=0;
                           break;
                       case '2..3':
                           matrice[i][j]=1;
                           break;
                       case '4..8':
                           matrice[i][j]=0;
                           break;
                       default:
                           printf("Erreur : nombre de voisins inconnu");
                           break;
                       }
                       }
                       else
                       {
                           if(AnalyseMatrice(matrice,i,j)==3)
                               matrice[i][j]=1;
                       }
                       }
                       }
                       }
                       
void afficher(int **matrice)
{
    int i, j;
    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            printf("%d",matrice[i][j]);
        }
        printf("\n");
    }
}
                       

                       int main()
                {
                    int matrice[TAILLE][TAILLE];
                    int i;
                    printf("Bienvenue dans le Jeu De La Vie ! Appuyez sur 'Entrer' pour commencer...\n");
                    getchar();
                    
                    initialiser(matrice);
                    
                    for(i=0;i<CYCLE;i++)
                    { 
                        afficher(matrice);
                        modifierMatrice(matrice);
                    }
                    
                    printf("Nombre de cycle terminé\n");
                    return 0;
                }

    
    
    
    
    
    
    
    
    /*
    if (((1<=l)&&(l<=TAILLE-2))&&((1<=c)&&(c<=TAILLE-2)))
    {
        for (i=l-1,k=0 ; i<=l+1 ; i++,k++){
            for (j=c-1,t=0 ; c<=c+1 ; c++,t++)
            {
                sous_Matrice[k][t]=matrice[i][j];
            }
        }
        return comptNbVoisins(sous_Matrice);
    }
    //Fin de la condition d'appartenance au coeur de la matrice
    
    else
    {
        if (l=0)
        {
            if (c=0)
            {
                sous_Matrice[0][0]=matrice[TAILLE-1][TAILLE-1];
                sous_Matrice[0][1]=matrice[TAILLE-1][0];
                sous_Matrice[0][2]=matrice[TAILLE-1][1];
                sous_Matrice[1][0]=matrice[0][TAILLE-1];
                sous_Matrice[0][0]=matrice[1][TAILLE-1];
                for (i=l ; i<=l+1 ; i++)
                {
                    for (j=c ; j<=c+1 ; j++)
                    {
                        sous_Matrice[i+1][j+1]=matrice[i][j];
                    }
                }
                return comptNbVoisins(sous_Matrice);
            }
            else if (c=TAILLE-1)
            {
                sous_Matrice[0][0]=matrice[TAILLE-1][TAILLE-2];
                sous_Matrice[0][1]=matrice[TAILLE-1][TAILLE-1];
                sous_Matrice[0][2]=matrice[TAILLE-1][0];
                sous_Matrice[1][2]=matrice[0][0];
                sous_Matrice[2][2]=matrice[1][0];
                for (i=l ; i<=l+1 ; i++)
                {
                    for (j=c ; j<=c+1 ; j++)
                    {
                        sous_Matrice[i+1][j+1]=matrice[i][j];
                    }
                }
                return comptNbVoisins(sous_Matrice);
            }
            else
            {
                
            }
        }
    }*/
    



