#include "prototypes.h"



void InitialisationPioche(struct lettres *lettres)
{

    int taboccurence[27] = {9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 6, 6, 2, 1, 6, 6, 6, 6, 2, 1, 1, 1, 1, 2};
    int tabvaleur[27] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2, 1, 1, 3, 8, 1, 1, 1, 1, 4, 10, 10, 10, 10, 0};


    int i,j=65;

    for(i=0; i<26; i++)
    {
        lettres[i].nom = j;

        lettres[i].occurence = taboccurence[i];

        lettres[i].valeur = tabvaleur[i];

        j++;
    }


// JOKER

    lettres[26].nom = '?';
    lettres[26].occurence = 2;
    lettres[26].valeur = 0;



}


void InitialisationChevalet(struct game *partie, struct players joueur[4], struct lettres *pioche, struct cases plateau[15][15])
{
    int i,j;
    char random;


    for(i=0; i<partie->nombrejoueurs; i++)
    {

        for(j=0; j<7; j++)
        {


            RandomLetterFromPioche(pioche,&random,partie);
            joueur[i].chevalet[j] = random;


        }

    }

}

void RandomLetterFromPioche(struct lettres *pioche, char *letter,struct game *partie)
{

    int i;
    int IsValid=0;


    do
    {
        *letter = (rand() % (91 + 1 - 65)) + 65;

        if (*letter==91)
        {
            *letter = '?';
        }


        if(partie->pioche>=1)
        {

        for(i=0;i<27;i++)
        {
            if(pioche[i].nom==*letter)
            {


                if(pioche[i].occurence!=0)
                {
                    pioche[i].occurence -= 1;
                    IsValid = 1;
                    partie->pioche -=  1;
                }

            }
        }
        }
        else
        {
            *letter = ' ';
            IsValid = 1;

        }


    }while(IsValid==0);
}


void AjustementChevalet(struct players joueur[4], struct lettres *pioche,int numerodujoueuractuel, struct game *partie,int *scrabble)
{

    int i;
    char random;
    int compteur=0;


    for(i=0;i<7;i++)
    {
        if (joueur[numerodujoueuractuel-1].chevalet[i] == ' ')
        {
            RandomLetterFromPioche(pioche,&random,partie);
            joueur[numerodujoueuractuel-1].chevalet[i] = random;
            compteur++;
        }
    }

    if (compteur==7)
    {
        *scrabble = 1;
    }

}

void AjustementPioche(char letter[1], struct lettres *pioche, struct game *partie)
{

    int i;


    for(i=0;i<27;i++)
    {
        if(pioche[i].nom==letter)
        {
            pioche[i].occurence += 1;
            partie->pioche += 1;
        }
    }


}

void AjustementChevaletBis(struct players joueur[4], struct lettres *pioche,int numerodujoueuractuel, struct game *partie)
{

    int i;
    char random;


    for(i=0;i<7;i++)
    {
        if (joueur[numerodujoueuractuel-1].chevalet[i] == ' ')
        {
            RandomLetterFromPioche(pioche,&random,partie);
            joueur[numerodujoueuractuel-1].chevalet[i] = random;

        }
    }

}


/*
void AffichagePioche(struct lettres *lettres)
{

    int i;

    for(i=0;i<27;i++)
    {
        printf("Nom de la lettre : %c\n",lettres[i].nom);
        printf("Occurence de la lettre : %d\n",lettres[i].occurence);
        printf("Valeur de la lettre : %d\n\n",lettres[i].valeur);
    }



}
*/
