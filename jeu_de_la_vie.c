#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constantes
#define TAILLE 10
#define CYCLE 200


//Fonctions utilisees, préprocesseur
void initialiser(int **matrice);
void afficher(int **matrice);
void modifierMatrice(int **matrice);
int comptNbVoisins(int **sousmatrice);
int AnalyseMatrice(int **matrice, int l, int c);






/*
**************************
Début des fonctions outils
**************************
*/



//Initialisation de la matrice au hasard
void initialiser(int **matrice)
{
    int i,j;
    
    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            matrice[i][j]=rand()%(2);
        }
    }
    
}



//Affichage "graphique"
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



//Modification de la vie en fontion de l'entourage
void modifierMatrice(int **matrice)
{
    int i, j;
    
    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            if(matrice[i][j]==1)
            {
                if((0<=AnalyseMatrice(matrice,i,j))||(1>=AnalyseMatrice(matrice,i,j)))
                    matrice[i][j]=0;
                else if ((2<=AnalyseMatrice(matrice,i,j))||(3>=AnalyseMatrice(matrice,i,j)))
                    matrice[i][j]=1;
                else if ((4<=AnalyseMatrice(matrice,i,j))||(8>=AnalyseMatrice(matrice,i,j)))
                    matrice[i][j]=0;
                else
                    printf("Erreur : nombre de voisins inconnu");
            }
            else
            {
                if(AnalyseMatrice(matrice,i,j)==3)
                    matrice[i][j]=1;
            }
        }
    }
}



//Compte le nombre de cellule vivante ou morte autour d'une case
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
    
    if (sousmatrice[1][1] == 1)
        compteur_Nb_Voisins--;
    
    return compteur_Nb_Voisins;
}



//Analyse case par case la matrice
int AnalyseMatrice(int **matrice, int l, int c)
{
    int i, j, k, t;
    int **sous_Matrice;
    sous_Matrice=malloc(3*sizeof(int*));
    for (i=0 ; i<3 ; i++)
        sous_Matrice[i]=malloc(3*sizeof(int));
    
    for(k=0,i=l-1 ; i<=l+1 ; i++,k++)
    {
        for(t=0,j=c-1 ; j<=c+1 ; t++,j++)
        {
            sous_Matrice[k][t]=matrice[(i+TAILLE)%TAILLE][(j+TAILLE)%TAILLE];
        }
    }
    
    return comptNbVoisins(sous_Matrice);
}



//Programme principal
int main()
{
    int i;
    int **matrice;
    matrice = malloc(TAILLE*sizeof(int*));
    for (i = 0; i < TAILLE; ++i)
        matrice[i] = malloc (sizeof(int)*TAILLE);
    
    //Il faudrait vérifier si l'allocation dynamique s'est bien déroulée
    
    
    srand (time(NULL));
    
    printf("Bienvenue dans le Jeu De La Vie ! Appuyez sur 'Entrer' pour commencer...\n");
    getchar();

    
    initialiser(matrice);
    
    printf("La population au départ : \n");
    afficher(matrice);
    printf("Pressez sur ENTER pour continuer...\n");
    getchar();
    
    
    
    for(i=0;i<CYCLE;i++)
    {
        
        modifierMatrice(matrice);
        printf("La population après %d cycles: \n",i+1);
        afficher(matrice);
        printf("Pressez sur ENTER pour continuer...\n");
        getchar();
    }
    
    printf("Nombre de cycle terminé\n");
    return 0;
}

/*Tracé des lignes peut être intéressant
void ligne(int largeur) 
{
    int i;
    for(i=0; i<largeur; i++)
        printf("+-");
    printf("+\n");
}
*/
