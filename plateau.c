#include "prototypes.h"




void InitialisationPlateau(struct cases plateau[15][15])
{


    int i,j;

    int tabLettreMots[15][15] = {
    {4, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 4}, //1
    {0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0}, //2
    {0, 0, 3, 0, 0, 0, 1, 0, 1, 0, 0, 0, 3, 0, 0}, //3
    {1, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 1}, //4
    {0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0}, //5
    {0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0}, //6
    {0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0}, //7
    {4, 0, 0, 1, 0, 0, 0, 6, 0, 0, 0, 1, 0, 0, 4}, //8
    {0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0}, //9
    {0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0}, //10
    {0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0}, //11
    {1, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 1}, //12
    {0, 0, 3, 0, 0, 0, 1, 0, 1, 0, 0, 0, 3, 0, 0}, //13
    {0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0}, //14
    {4, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 4}, //15
    };


    // Remise à zéro
    for(i=0;i<15;i++)
     {
        for(j=0;j<15;j++)
        {

            if(tabLettreMots[i][j]==1)
            {
                strcpy(plateau[i][j].nom,"& ");
                plateau[i][j].bonus = 2;
                plateau[i][j].libre = 1;
                plateau[i][j].valeur = ' ';
                plateau[i][j].typebonus = 'L';
            }
            else if(tabLettreMots[i][j]==2)
            {
                strcpy(plateau[i][j].nom,"% ");
                plateau[i][j].bonus = 3;
                plateau[i][j].libre = 1;
                plateau[i][j].valeur = ' ';
                plateau[i][j].typebonus = 'L';

            }
            else if(tabLettreMots[i][j]==3)
            {
                strcpy(plateau[i][j].nom,"@ ");
                plateau[i][j].bonus = 2;
                plateau[i][j].libre = 1;
                plateau[i][j].valeur = ' ';
                plateau[i][j].typebonus = 'M';

            }

            else if(tabLettreMots[i][j]==4)
            {
                strcpy(plateau[i][j].nom,"§ ");
                plateau[i][j].bonus = 3;
                plateau[i][j].libre = 1;
                plateau[i][j].valeur = ' ';
                plateau[i][j].typebonus = 'M';

            }
            else
            {
                strcpy(plateau[i][j].nom,"  ");
                plateau[i][j].bonus = 1;
                plateau[i][j].libre = 1;
                plateau[i][j].valeur = ' ';
                plateau[i][j].typebonus = ' ';

            }



            plateau[i][j].casesuperpose = 0;
            plateau[i][j].occupeparjoueur[0] = 0;
            plateau[i][j].occupeparjoueur[1] = 0;
            plateau[i][j].occupeparjoueur[2] = 0;
            plateau[i][j].occupeparjoueur[3] = 0;
            plateau[i][j].couleur = 15;
        }
    }

    // Ajout du point de départ

    strcpy(plateau[7][7].nom,"# ");
    plateau[7][7].bonus = 2;
    plateau[7][7].libre = 1;
    plateau[7][7].valeur = ' ';
    plateau[7][7].typebonus = 'M';




}

void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


void AffichagePlateau(struct cases plateau[15][15])
{

    int i,j;
    int k=65;
    int aff;
    int pos=0;
     // Hors tableau
    printf("\n");
    printf("               ");
    for(i=0;i<15;i++)
    {
        printf("    ");
        printf("%c",k++);
    }

    printf("\n");
    printf("               ");
    printf("  ");
    printf("%c",0xDA);
    //Color(15,7);
    pos=1;
    for(i=0;i<74;i++)
    {
        if(pos!=5)
        {
            printf("%c",0xC4);
        }
        else
        {
            printf("%c",0xC2);
            pos = 0;
        }
        pos++;

    }

    printf("%c",0xBF);

    printf("\n");

    // Tableau

    for(i=0;i<15;i++)
    {
        //Color(15,0);
        printf("               ");
        printf("%d",i+1); // Hors tableau
        if (i<9)
            printf(" ");


        //Color(15,7);
        for(j=0;j<15;j++)
        {

            printf("%c",0xB3);
            printf(" ");
            printf("%c",plateau[i][j].nom[0]);
            Color(plateau[i][j].couleur ,0);
            printf("%c",plateau[i][j].nom[1]);
            Color(15,0);

            printf(" ");
        }

        if (i==14)
        {
            //Color(15,0);
        }

        printf("%c",0xB3);

        printf("\n");
        printf("  ");
        printf("               ");
        if(i!=14)
        {
            printf("%c",0xC3);
        }
        else
        {
            printf("%c",0xC0);
        }

        pos=1;
        if (i!=14)
        {

        for(aff=0;aff<74;aff++)
        {
            if(pos!=5)
        {
            printf("%c",0xC4);
        }
        else
        {
            printf("%c",0xC5);
            pos = 0;
        }
        pos++;

        }
        }
        else
        {
             for(aff=0;aff<74;aff++)
            {
                if(pos!=5)
                {
                    printf("%c",0xC4);
                }
                else
                {
                    printf("%c",0xC1);
                    pos = 0;
                }
                pos++;

            }

        }

        if(i!=14)
        {
            printf("%c",0xB4);
        }
        else
        {
            printf("%c",0xD9);
        }
        printf("\n");

    }

    printf("\n\n");

}

void AffichagePlayerAndScore(char nomdujoueur[50], int score, int tour, int color)
{

    printf("\n  Joueur actuel : ");
    Color(color,0);
    printf("%s",nomdujoueur);
    Color(15,0);
    printf(" - Score : %d", score);
    printf("\t\t\t\t\t\t\t  Tour actuel : %d",tour);


}


void AffichageChevalet(char chevalet[8],struct lettres *pioche)
{

    int i=0;

    int j;

    printf("\n\n\t\t\t     ");

    for(i=0;i<7;i++)
    {

        for(j=0;j<27;j++)
        {
            if (chevalet[i]==pioche[j].nom)
            {
                printf("%c", chevalet[i]);
                printf("(%d)", pioche[j].valeur);
                printf("    ");
            }

        }

    }

    printf("\n");
}

void AffichageRecupVerifMAP(char chevalet[8],struct lettres *pioche, int *motIsValid, struct motprovisoire *motprovisoire, struct cases plateau[15][15], int tour ,int isfirstmot)
{

    int verifprovisoire=0;

    RecupMotaPlacer(motprovisoire);

    verifprovisoire = VerifMotaPlacer(chevalet,pioche,motprovisoire,plateau,tour,isfirstmot);

    if (verifprovisoire==1)
    {
        *motIsValid = 1;
    }

    else
    {
        *motIsValid = 0;
    }



}

void RecupMotaPlacer(struct motprovisoire *motprovisoire)
{

        // La vérification de la validité du mot et donc de "motprovisoire->motaplacer" sera fait dans VerifMotaPlacer()..
        printf("\n Mot a placer :       ");
        fflush(stdin);
        scanf("%s",motprovisoire->motaplacer);

        printf("\nPosition du mot : \n");


        //Blindage des autres valeurs
        do{
        printf("N. Ligne :       ");
        fflush(stdin);
        scanf("%d",&motprovisoire->nligne);

        }while(motprovisoire->nligne>15 || motprovisoire->nligne<1 );

        do{
        printf("N. Colonne :     ");
        fflush(stdin);
        scanf("%c",&motprovisoire->ncolonne);
        }while( toupper(motprovisoire->ncolonne)>79 ||  toupper(motprovisoire->ncolonne)<65 );

        do{
        printf("Sens :           ");
        fflush(stdin);
        scanf("%c",&motprovisoire->sens);
        }while( toupper(motprovisoire->sens)!=72 && toupper(motprovisoire->sens)!=86 );

}

int VerifMotaPlacer(char chevalet[8],struct lettres *pioche, struct motprovisoire *motprovisoire, struct cases plateau[15][15], int tour, int isfirstmot)
{


    int taille=0;
    int ligne;
    char sens;
    char colonne;
    int IsValid = 0;
    taille = strlen(motprovisoire->motaplacer);

/// VerifMotaPlacerAvecChevalet
    VerifMotaPlacerAvecChevalet(chevalet,pioche,motprovisoire,&IsValid,taille);


///verif de la position du mot


    ligne=motprovisoire->nligne;
    colonne=motprovisoire->ncolonne;
    sens=motprovisoire->sens;


    colonne = toupper(colonne);




    /// le 1er mot se positionne sur la case centrale (position ligne=7 et colonne=H)
    VerifPositionMotPremierTour(&IsValid,tour,motprovisoire,isfirstmot);


    /// le mot à placer se situe toujours sur le plateau
    VerifMotBienSurLePlateau(&IsValid,sens,ligne,colonne,taille);



    /// le mot a au moins une lettre en commun avec les mots placés sur le plateau. Il ne pourra pas écraser les lettres existante
    VerifAuMoinsUneLettreCommune(&IsValid,sens,ligne,colonne,taille,plateau,motprovisoire,tour,isfirstmot);

    // la validation de l’orthographe ou la justesse du mot placé se fait par le joueur (ou par le dictionnaire prévu dans les bonus)
    // la validation de toutes les connexions avec les autres mots se fait par les joueurs

    /// deux voyelles entre deux mots ne marche pas
    VerifPasDeuxVoyellesCoteACote(&IsValid,sens,ligne,colonne,taille,plateau,motprovisoire);


    return IsValid;



}

void AffichageRecupVerifMAPIA(char chevalet[8],struct lettres *pioche, int *motIsValid, struct motprovisoire *motprovisoire, struct cases plateau[15][15], int tour ,int isfirstmot)
{
    int verifprovisoire=0;

    verifprovisoire = VerifMotaPlacerIA(chevalet,pioche,motprovisoire,plateau,tour,isfirstmot);

    if (verifprovisoire==1)
    {
        *motIsValid = 1;
    }

    else
    {
        *motIsValid = 0;
    }


}

int VerifMotaPlacerIA(char chevalet[8],struct lettres *pioche, struct motprovisoire *motprovisoire, struct cases plateau[15][15], int tour, int isfirstmot)
{


    int taille=0;
    int ligne;
    char sens;
    char colonne;
    int IsValid = 0;
    taille = strlen(motprovisoire->motaplacer);

/// VerifMotaPlacerAvecChevalet
    VerifMotaPlacerAvecChevaletIA(chevalet,pioche,motprovisoire,&IsValid,taille);


///verif de la position du mot


    ligne=motprovisoire->nligne;
    colonne=motprovisoire->ncolonne;
    sens=motprovisoire->sens;


    colonne = toupper(colonne);




    /// le 1er mot se positionne sur la case centrale (position ligne=7 et colonne=H)
    VerifPositionMotPremierTourIA(&IsValid,tour,motprovisoire,isfirstmot);


    /// le mot à placer se situe toujours sur le plateau
    VerifMotBienSurLePlateauIA(&IsValid,sens,ligne,colonne,taille);



    /// le mot a au moins une lettre en commun avec les mots placés sur le plateau. Il ne pourra pas écraser les lettres existante
    VerifAuMoinsUneLettreCommuneIA(&IsValid,sens,ligne,colonne,taille,plateau,motprovisoire,tour,isfirstmot);

    // la validation de l’orthographe ou la justesse du mot placé se fait par le joueur (ou par le dictionnaire prévu dans les bonus)
    // la validation de toutes les connexions avec les autres mots se fait par les joueurs

    /// deux voyelles entre deux mots ne marche pas
    VerifPasDeuxVoyellesCoteACoteIA(&IsValid,sens,ligne,colonne,taille,plateau,motprovisoire);


    return IsValid;



}

void AffichageMotaPlacer(struct motprovisoire *motprovisoire)
{

        printf("\nMot a placer :       %s",motprovisoire->motaplacer);

        printf("\nPosition du mot : \n");
        printf("N. Ligne :       %d\n",motprovisoire->nligne);
        printf("N. Colonne :     %c\n",motprovisoire->ncolonne);
        printf("Sens :           %c\n",motprovisoire->sens);

}


void AffichageConfirmationMot(int* confirmationjoueur)
{
    char preconf[100];

    do
    {

    printf("\nVoulez-vous vraiment placer ce mot ? (O / N)");

    fflush(stdin);
    scanf("%s",preconf);

    }
    while(preconf[0]!=79 && preconf[0]!=78 && preconf[0]!=110 && preconf[0]!=111);

    if(preconf[0]==79 || preconf[0]==111)
    {
        *confirmationjoueur = 1;

    }
    if(preconf[0]==78||preconf[0]==110)
    {
        *confirmationjoueur = 0;
    }

}

void MinusToUpper(struct motprovisoire *motprovisoire)
{
    int i=0;

    for(i=0;i<strlen(motprovisoire->motaplacer);i++)
    {
        motprovisoire->motaplacer[i] = toupper(motprovisoire->motaplacer[i]);
    }

}



void DeleteChevaletLetter(struct motprovisoire motprovisoire,struct players joueur[4],int numerodujoueuractuel)
{
    int i=0;

    while(motprovisoire.motaplacer[i]!='\0')
    {

        if (motprovisoire.motaplacer[i]==joueur[numerodujoueuractuel-1].chevalet[0])
        {
            joueur[numerodujoueuractuel-1].chevalet[0]=' ';
        }

        if (motprovisoire.motaplacer[i]==joueur[numerodujoueuractuel-1].chevalet[1])
        {
            joueur[numerodujoueuractuel-1].chevalet[1]=' ';
        }

        if (motprovisoire.motaplacer[i]==joueur[numerodujoueuractuel-1].chevalet[2])
        {
            joueur[numerodujoueuractuel-1].chevalet[2]=' ';
        }

        if (motprovisoire.motaplacer[i]==joueur[numerodujoueuractuel-1].chevalet[3])
        {
            joueur[numerodujoueuractuel-1].chevalet[3]=' ';
        }

        if (motprovisoire.motaplacer[i]==joueur[numerodujoueuractuel-1].chevalet[4])
        {
            joueur[numerodujoueuractuel-1].chevalet[4]=' ';
        }

        if (motprovisoire.motaplacer[i]==joueur[numerodujoueuractuel-1].chevalet[5])
        {
            joueur[numerodujoueuractuel-1].chevalet[5]=' ';
        }

        if (motprovisoire.motaplacer[i]==joueur[numerodujoueuractuel-1].chevalet[6])
        {
            joueur[numerodujoueuractuel-1].chevalet[6]=' ';
        }

    i++;
    }
}

void DeleteChevaletLetterBis(char lettre[8],struct players joueur[4],int numerodujoueuractuel,struct lettres *pioche,struct game *partie)
{
    int i=0,j;

    while(lettre[i]!='\0')
    {

        if (lettre[i]==joueur[numerodujoueuractuel-1].chevalet[0])
        {
            joueur[numerodujoueuractuel-1].chevalet[0]=' ';
            for(j=0;j<27;j++)
            {
                if (pioche[j].nom==lettre[i])
                {
                   pioche[j].occurence += 1;
                   partie->pioche += 1;
                }
            }
        }

        if (lettre[i]==joueur[numerodujoueuractuel-1].chevalet[1])
        {
            joueur[numerodujoueuractuel-1].chevalet[1]=' ';
            for(j=0;j<27;j++)
            {
                if (pioche[j].nom==lettre[i])
                {
                   pioche[j].occurence += 1;
                   partie->pioche += 1;
                }
            }
        }

        if (lettre[i]==joueur[numerodujoueuractuel-1].chevalet[2])
        {
            joueur[numerodujoueuractuel-1].chevalet[2]=' ';
            for(j=0;j<27;j++)
            {
                if (pioche[j].nom==lettre[i])
                {
                   pioche[j].occurence += 1;
                   partie->pioche += 1;
                }
            }
        }

        if (lettre[i]==joueur[numerodujoueuractuel-1].chevalet[3])
        {
            joueur[numerodujoueuractuel-1].chevalet[3]=' ';
            for(j=0;j<27;j++)
            {
                if (pioche[j].nom==lettre[i])
                {
                   pioche[j].occurence += 1;
                   partie->pioche += 1;
                }
            }
        }

        if (lettre[i]==joueur[numerodujoueuractuel-1].chevalet[4])
        {
            joueur[numerodujoueuractuel-1].chevalet[4]=' ';
            for(j=0;j<27;j++)
            {
                if (pioche[j].nom==lettre[i])
                {
                   pioche[j].occurence += 1;
                   partie->pioche += 1;
                }
            }
        }

        if (lettre[i]==joueur[numerodujoueuractuel-1].chevalet[5])
        {
            joueur[numerodujoueuractuel-1].chevalet[5]=' ';
            for(j=0;j<27;j++)
            {
                if (pioche[j].nom==lettre[i])
                {
                   pioche[j].occurence += 1;
                   partie->pioche += 1;
                }
            }
        }

        if (lettre[i]==joueur[numerodujoueuractuel-1].chevalet[6])
        {
            joueur[numerodujoueuractuel-1].chevalet[6]=' ';
            for(j=0;j<27;j++)
            {
                if (pioche[j].nom==lettre[i])
                {
                   pioche[j].occurence += 1;
                   partie->pioche += 1;
                }
            }
        }

    i++;
    }
}

void MiseEnPlaceLettres(struct motprovisoire motprovisoire,int numerodujoueuractuel, struct cases plateau[15][15],int color)
{
    int i=0;
    int ligne=0, colonne=0;

    int j=0;

    if ( toupper(motprovisoire.sens) == 72 ) // HORIZONTALE
    {
        i=0;
        ligne = motprovisoire.nligne - 1;
        colonne = toupper(motprovisoire.ncolonne)-64 - 1;
        while(motprovisoire.motaplacer[i]!='\0')
        {
            plateau[ligne][colonne].nom[1] = motprovisoire.motaplacer[i];

            plateau[ligne][colonne].libre = 0;
            plateau[ligne][colonne].valeur = motprovisoire.motaplacer[i];

            for(j=0;j<4;j++)
            {
                if(plateau[ligne][colonne].occupeparjoueur[j] == 1)
                {
                    plateau[ligne][colonne].casesuperpose = 1;
                }
            }

            plateau[ligne][colonne].occupeparjoueur[numerodujoueuractuel-1] = 1;
            plateau[ligne][colonne].couleur = color;

            colonne++;
            i++;
        }

    }



    if ( toupper(motprovisoire.sens) == 86 ) // VERTICALE
    {
        i=0;
        ligne = motprovisoire.nligne - 1;
        colonne = toupper(motprovisoire.ncolonne)-64 - 1;
        while(motprovisoire.motaplacer[i]!='\0')
        {
            plateau[ligne][colonne].nom[1] = motprovisoire.motaplacer[i];

            plateau[ligne][colonne].libre = 0;
            plateau[ligne][colonne].valeur = motprovisoire.motaplacer[i];

            for(j=0;j<4;j++)
            {
                if(plateau[ligne][colonne].occupeparjoueur[j] == 1)
                {
                    plateau[ligne][colonne].casesuperpose = 1;
                }
            }

            plateau[ligne][colonne].occupeparjoueur[numerodujoueuractuel-1] = 1;
            plateau[ligne][colonne].couleur = color;

            ligne++;
            i++;
        }

    }

}

void EnleverLettres(struct motprovisoire motprovisoire,int numerodujoueuractuel, struct cases plateau[15][15])
{
    int i=0;
    int ligne=0, colonne=0;

    if ( toupper(motprovisoire.sens) == 72 ) // HORIZONTALE
    {
        i=0;
        ligne = motprovisoire.nligne - 1;
        colonne = toupper(motprovisoire.ncolonne)-64 - 1;
        while(motprovisoire.motaplacer[i]!='\0')
        {
            plateau[ligne][colonne].nom[1] = ' ';

            plateau[ligne][colonne].libre = 1;
            plateau[ligne][colonne].valeur = ' ';

            plateau[ligne][colonne].casesuperpose = 0;
            plateau[ligne][colonne].couleur = 15;


            plateau[ligne][colonne].occupeparjoueur[numerodujoueuractuel-1] = 0;

            colonne++;
            i++;
        }

    }



    if ( toupper(motprovisoire.sens) == 86 ) // VERTICALE
    {
        i=0;
        ligne = motprovisoire.nligne - 1;
        colonne = toupper(motprovisoire.ncolonne)-64 - 1;
        while(motprovisoire.motaplacer[i]!='\0')
        {
            plateau[ligne][colonne].nom[1] = ' ';

            plateau[ligne][colonne].libre = 1;
            plateau[ligne][colonne].valeur = ' ';


            plateau[ligne][colonne].casesuperpose = 0;
            plateau[ligne][colonne].couleur = 15;
            plateau[ligne][colonne].occupeparjoueur[numerodujoueuractuel-1] = 0;

            ligne++;
            i++;
        }

    }

}

