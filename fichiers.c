#include "prototypes.h"


void SauvegarderGame(struct game *partie, struct players joueur[4], struct lettres *pioche, struct cases plateau[15][15])
{
    int i = 0,j = 0;


    FILE* fichier1 = NULL;
    FILE* fichier2 = NULL;
    FILE* fichier3 = NULL;
    FILE* fichier4 = NULL;

    // Struct "lettres"
    fichier1 = fopen("data/struct_lettres.txt","w");

    if (fichier1 != NULL)
    {
        for(i=0;i<27;i++)
        {

            fprintf(fichier1," %c",pioche[i].nom);
            fprintf(fichier1," %d",pioche[i].occurence);
            fprintf(fichier1," %d",pioche[i].valeur);
        }

        fclose(fichier1);
    }
    else
    {
        printf("ERREUR SAUVEGARDE !!");
    }



    // Struct "cases"
    fichier2 = fopen("data/struct_cases.txt","w");

    if (fichier2 != NULL)
    {
        for(i=0;i<15;i++)
        {
            for(j=0;j<15;j++)
            {
                fprintf(fichier2,";%c",plateau[i][j].nom[0]);
                fprintf(fichier2,";%c",plateau[i][j].nom[1]);
                fprintf(fichier2,";%d",plateau[i][j].bonus);
                fprintf(fichier2,";%d",plateau[i][j].libre);
                fprintf(fichier2,";%c",plateau[i][j].valeur);
                fprintf(fichier2,";%c",plateau[i][j].typebonus);
                fprintf(fichier2,";%d",plateau[i][j].casesuperpose);
                fprintf(fichier2,";%d",plateau[i][j].occupeparjoueur[0]);
                fprintf(fichier2,";%d",plateau[i][j].occupeparjoueur[1]);
                fprintf(fichier2,";%d",plateau[i][j].occupeparjoueur[2]);
                fprintf(fichier2,";%d",plateau[i][j].occupeparjoueur[3]);
                fprintf(fichier2,";%d",plateau[i][j].couleur);
            }
        }



        fclose(fichier2);
    }
    else
    {
        printf("ERREUR SAUVEGARDE !!");
    }



    // Struct "players"
    fichier3 = fopen("data/struct_players.txt","w");

    if (fichier3 != NULL)
    {
        for(i=0;i<partie->nombrejoueurs;i++)
        {

            fprintf(fichier3," %s",joueur[i].nomdujoueur);
            fprintf(fichier3," %d",joueur[i].score);
            fprintf(fichier3," %s",joueur[i].chevalet);
            fprintf(fichier3," %d",joueur[i].color);
            fprintf(fichier3," %d",joueur[i].isIA);


        }



        fclose(fichier3);
    }
    else
    {
        printf("ERREUR SAUVEGARDE !!");
    }



    // Struct "game"
    fichier4 = fopen("data/struct_game.txt","w");

    if (fichier4 != NULL)
    {
        fprintf(fichier4," %d",partie->encours);
        fprintf(fichier4," %d",partie->nombrejoueurs);
        fprintf(fichier4," %d",partie->pioche);
        fprintf(fichier4," %d",partie->touractuel);

        fclose(fichier4);
    }
    else
    {
        printf("ERREUR SAUVEGARDE !!");
    }


}


void ChargerGame(struct game *partie, struct players joueur[4])
{
    int i = 0;

    FILE* fichier4 = NULL;
    FILE* fichier3 = NULL;



    // Struct "game"
    fichier4 = fopen("data/struct_game.txt","r");

    if (fichier4 != NULL)
    {
        fscanf(fichier4, " %d %d %d %d", &partie->encours,&partie->nombrejoueurs, &partie->pioche, &partie->touractuel);

        fclose(fichier4);

    }
    else
    {
        partie->encours = 0;
        partie->nombrejoueurs = 1;

    }


    // Struct "players"
    fichier3 = fopen("data/struct_players.txt","r");

    if (fichier3 != NULL)
    {
        for(i=0;i<partie->nombrejoueurs;i++)
        {

            fscanf(fichier3," %s %d %s %d %d",joueur[i].nomdujoueur,&joueur[i].score,joueur[i].chevalet,&joueur[i].color,&joueur[i].isIA);
        }

        fclose(fichier3);
    }


}

void ChargerPlateau(struct game *partie, struct players joueur[4], struct lettres *pioche, struct cases plateau[15][15])
{

     int i = 0,j = 0;


    FILE* fichier1 = NULL;
    FILE* fichier2 = NULL;

    // Struct "lettres"
    fichier1 = fopen("data/struct_lettres.txt","r");

    if (fichier1 != NULL)
    {
        for(i=0;i<27;i++)
        {
            fscanf(fichier1, " %c %d %d", &pioche[i].nom,&pioche[i].occurence, &pioche[i].valeur);


        }

        fclose(fichier1);
    }
    else
    {
        printf("ERREUR CHARGEMENT !!");
    }





     // Struct "cases"
    fichier2 = fopen("data/struct_cases.txt","r");

    if (fichier2 != NULL)
    {
        for(i=0;i<15;i++)
        {
            for(j=0;j<15;j++)
            {
                fscanf(fichier2,";%c;%c;%d;%d;%c;%c;%d;%d;%d;%d;%d;%d",&plateau[i][j].nom[0],&plateau[i][j].nom[1],&plateau[i][j].bonus,&plateau[i][j].libre,&plateau[i][j].valeur,&plateau[i][j].typebonus,&plateau[i][j].casesuperpose,&plateau[i][j].occupeparjoueur[0],&plateau[i][j].occupeparjoueur[1],&plateau[i][j].occupeparjoueur[2],&plateau[i][j].occupeparjoueur[3],&plateau[i][j].couleur);
            }
        }



        fclose(fichier2);
    }
    else
    {
        printf("ERREUR CHARGEMENT !!");

    }

}
