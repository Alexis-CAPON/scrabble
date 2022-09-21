#include "prototypes.h"


void VerifMotaPlacerAvecChevalet(char chevalet[8],struct lettres *pioche, struct motprovisoire *motprovisoire,int *IsValid,int taille)
{
    int i,j,compteur=0,boucle=0;
    char copie[8] = "";

    strcpy(copie, chevalet);

    if(taille > 7 || taille==0)//verif taille du mot
    {
    }
    else
    {

        for(i=0;i<taille;i++)
        {
            boucle=0;
            for(j=0;j<7;j++)
            {
                if ((motprovisoire->motaplacer[i]==copie[j] || motprovisoire->motaplacer[i]==copie[j]-'A'+'a') && boucle==0 )
                {
                    copie[j]=0;
                    compteur+=1;
                    boucle=1;
                }
            }
        }
        if(compteur==taille)
        {
            *IsValid=1;
        }
    }
}



void VerifPositionMotPremierTour(int *IsValid,int tour,struct motprovisoire *motprovisoire, int isfirstmot)
{
    if (*IsValid==1 &&  isfirstmot==1)
    {
        if (  motprovisoire->nligne!=8 || motprovisoire->ncolonne != 'H')
        {

        motprovisoire->ncolonne='H';
        motprovisoire->nligne=8;


        printf("\nLe mot a ete place au centre car nous sommes au tour 1 !\n\n");

        }

    }
}


void VerifMotBienSurLePlateau(int *IsValid,char sens[1],int ligne,char colonne[1],int taille)
{

    if (*IsValid==1)

    {
        if (colonne>='a' && colonne<='o')
        {
            colonne=colonne-'a'+'A';
        }
        if (sens=='h'||sens=='H')
        {
            if (colonne<'A' || colonne>'O'-taille+1  || ligne<1 || ligne>15 )
            {
                *IsValid=0;
                printf("\nLe mot est mal place et depasse du plateau !\n\n");
            }
        }
        if (sens=='v'||sens=='V')
        {
            if ( colonne<'A' || colonne>'O'|| ligne<1 || ligne>15 -taille+1 )
            {
                *IsValid=0;
                printf("\nLe mot est mal place et depasse du plateau !\n\n");
            }
        }
    }
}



void VerifAuMoinsUneLettreCommune(int *IsValid,char sens[1],int ligne,char colonne[1],int taille,struct cases plateau[15][15],struct motprovisoire *motprovisoire,int tour,int isfirstmot)
{
    int j;
    int occ=0;
    int lettrecommune=0;
    int col;

    col=colonne - 64;


    if (*IsValid==1 && isfirstmot!=1)
    {
        if (sens=='v'||sens=='V')
        {
            for (j=ligne-1;j<ligne-1+taille;j++)
            {
                if (plateau[j][col-1].nom[1] !=' ')
                {
                    if (plateau[ligne-1][j].nom[1]=='?'||plateau[j][col-1].nom[1]==motprovisoire->motaplacer[j-ligne+1] || plateau[j][col-1].nom[1]==motprovisoire->motaplacer[j-ligne+1]-'a'+'A')
                    {
                        occ+=1;
                        lettrecommune+=1;    //au moins une lettre commune

                    }
                    else
                    {
                        occ=occ;
                    }
                }
                else
                {
                    occ+=1;
                }
            }
            if(occ==taille && lettrecommune>=1)*IsValid=1;
            else
            {
                *IsValid=0;
                printf("\nle mot doit avoir au moins une lettre en commun avec les mots places sur le plateau et ne peut pas ecraser les mots deja en places !\n");
            }

        }
        if (sens=='h'||sens=='H')
        {
            for (j=col-1;j<col-1+taille;j++)
            {
                if (plateau[ligne-1][j].nom[1] !=' ')
                {
                    if (plateau[ligne-1][j].nom[1]=='?'||plateau[ligne-1][j].nom[1]==motprovisoire->motaplacer[j-col+1] || plateau[ligne-1][j].nom[1]==motprovisoire->motaplacer[j-col+1]-'a'+'A')
                    {
                        occ+=1;
                        lettrecommune+=1;    //au moins une lettre commune
                    }
                    else
                    {
                        occ=occ;
                    }
                }
                else
                {
                    occ+=1;
                }
            }
            if(occ==taille && lettrecommune>=1)*IsValid=1;
            else
            {
                *IsValid=0;
                printf("\nle mot doit avoir au moins une lettre en commun avec les mots places sur le plateau et ne peut pas remplacer les mots deja en places !\n");
            }

        }
    }
}



void VerifPasDeuxVoyellesCoteACote(int *IsValid,char sens[1],int ligne,char colonne[1],int taille,struct cases plateau[15][15],struct motprovisoire *motprovisoire)
{

    int j,col;
    col=colonne -'A';

    if (*IsValid==1)
    {
        if (sens=='v'||sens=='V')
        {


            if ((ligne-2>=0)&&(plateau[ligne-2][col].nom[1]=='A' || plateau[ligne-2][col].nom[1]=='E' ||plateau[ligne-2][col].nom[1]=='I' ||plateau[ligne-2][col].nom[1]=='O' ||plateau[ligne-2][col].nom[1]=='U' ||plateau[ligne-2][col].nom[1]=='Y'))
            {
                if (motprovisoire->motaplacer[0]=='a' || motprovisoire->motaplacer[0]=='e' ||motprovisoire->motaplacer[0]=='i' ||motprovisoire->motaplacer[0]=='o' ||motprovisoire->motaplacer[0]=='u' ||motprovisoire->motaplacer[0]=='y'||motprovisoire->motaplacer[0]=='A' || motprovisoire->motaplacer[0]=='E' ||motprovisoire->motaplacer[0]=='I' ||motprovisoire->motaplacer[0]=='O' ||motprovisoire->motaplacer[0]=='U' ||motprovisoire->motaplacer[0]=='Y')
                {
                    *IsValid=0;
                    printf("\nErreur, des voyelles de 2 mots differents sont collees entre elles\n");

                }
            }
            if ((ligne-1+taille<15)&&(plateau[ligne-1+taille][col].nom[1]=='A' || plateau[ligne-1+taille][col].nom[1]=='E' || plateau[ligne-1+taille][col].nom[1]=='I' || plateau[ligne-1+taille][col].nom[1]=='O' || plateau[ligne-1+taille][col].nom[1]=='U' ||plateau[ligne-1+taille][col].nom[1]=='Y'))
            {
                if (motprovisoire->motaplacer[taille-1]=='a' || motprovisoire->motaplacer[taille-1]=='e' ||motprovisoire->motaplacer[taille-1]=='i' ||motprovisoire->motaplacer[taille-1]=='o' ||motprovisoire->motaplacer[taille-1]=='u' ||motprovisoire->motaplacer[taille-1]=='y'||motprovisoire->motaplacer[taille-1]=='A' || motprovisoire->motaplacer[taille-1]=='E' ||motprovisoire->motaplacer[taille-1]=='I' ||motprovisoire->motaplacer[taille-1]=='O' ||motprovisoire->motaplacer[taille-1]=='U' ||motprovisoire->motaplacer[taille-1]=='Y')
                {
                    *IsValid=0;
                     printf("\nErreur, des voyelles de 2 mots differents sont collees entre elles\n");
                }
            }


            for (j=ligne-1;j<ligne-1+taille;j++)
            {

                if ((j<15&&j>=0)&&(plateau[j][col-1].nom[1]=='A' || plateau[j][col-1].nom[1]=='E' ||plateau[j][col-1].nom[1]=='I' ||plateau[j][col-1].nom[1]=='O' ||plateau[j][col-1].nom[1]=='U' ||plateau[j][col-1].nom[1]=='Y'))
                {
                    if (motprovisoire->motaplacer[j-ligne+1]=='a' || motprovisoire->motaplacer[j-ligne+1]=='e' ||motprovisoire->motaplacer[j-ligne+1]=='i' ||motprovisoire->motaplacer[j-ligne+1]=='o' ||motprovisoire->motaplacer[j-ligne+1]=='u' ||motprovisoire->motaplacer[j-ligne+1]=='y'||motprovisoire->motaplacer[j-ligne+1]=='A' || motprovisoire->motaplacer[j-ligne+1]=='E' ||motprovisoire->motaplacer[j-ligne+1]=='I' ||motprovisoire->motaplacer[j-ligne+1]=='O' ||motprovisoire->motaplacer[j-ligne+1]=='U' ||motprovisoire->motaplacer[j-ligne+1]=='Y')
                    {
                        *IsValid=0;
                        printf("\nErreur, des voyelles de 2 mots differents sont collees entre elles\n");
                    }
                }
                if ((j<15&&j>=0)&&(plateau[j][col+1].nom[1]=='A' || plateau[j][col+1].nom[1]=='E' ||plateau[j][col+1].nom[1]=='I' ||plateau[j][col+1].nom[1]=='O' ||plateau[j][col+1].nom[1]=='U' ||plateau[j][col+1].nom[1]=='Y'))
                {
                    if (motprovisoire->motaplacer[j-ligne+1]=='a' || motprovisoire->motaplacer[j-ligne+1]=='e' ||motprovisoire->motaplacer[j-ligne+1]=='i' ||motprovisoire->motaplacer[j-ligne+1]=='o' ||motprovisoire->motaplacer[j-ligne+1]=='u' ||motprovisoire->motaplacer[j-ligne+1]=='y'||motprovisoire->motaplacer[j-ligne+1]=='A' || motprovisoire->motaplacer[j-ligne+1]=='E' ||motprovisoire->motaplacer[j-ligne+1]=='I' ||motprovisoire->motaplacer[j-ligne+1]=='O' ||motprovisoire->motaplacer[j-ligne+1]=='U' ||motprovisoire->motaplacer[j-ligne+1]=='Y')
                    {
                        *IsValid=0;
                        printf("\nErreur, des voyelles de 2 mots differents sont collees entre elles\n");
                    }
                }
            }
        }





        if (sens=='h'||sens=='H')
        {
            if ((col-1>=0)&&(plateau[ligne-1][col-1].nom[1]=='A' || plateau[ligne-1][col-1].nom[1]=='E' ||plateau[ligne-1][col-1].nom[1]=='I' ||plateau[ligne-1][col-1].nom[1]=='O' ||plateau[ligne-1][col-1].nom[1]=='U' ||plateau[ligne-1][col-1].nom[1]=='Y'))
            {
                if (motprovisoire->motaplacer[0]=='a' || motprovisoire->motaplacer[0]=='e' ||motprovisoire->motaplacer[0]=='i' ||motprovisoire->motaplacer[0]=='o' ||motprovisoire->motaplacer[0]=='u' ||motprovisoire->motaplacer[0]=='y'||motprovisoire->motaplacer[0]=='A' || motprovisoire->motaplacer[0]=='E' ||motprovisoire->motaplacer[0]=='I' ||motprovisoire->motaplacer[0]=='O' ||motprovisoire->motaplacer[0]=='U' ||motprovisoire->motaplacer[0]=='Y')
                {
                    *IsValid=0;
                     printf("\nErreur, des voyelles de 2 mots differents sont collees entre elles\n");
                }
            }
            if ((col+taille<15)&&(plateau[ligne-1][col+taille].nom[1]=='A' || plateau[ligne-1][col+taille].nom[1]=='E' ||plateau[ligne-1][col+taille].nom[1]=='I' ||plateau[ligne-1][col+taille].nom[1]=='O' ||plateau[ligne-1][col+taille].nom[1]=='U' ||plateau[ligne-1][col+taille].nom[1]=='Y'))
            {
                if (motprovisoire->motaplacer[taille-1]=='a' || motprovisoire->motaplacer[taille-1]=='e' ||motprovisoire->motaplacer[taille-1]=='i' ||motprovisoire->motaplacer[taille-1]=='o' ||motprovisoire->motaplacer[taille-1]=='u' ||motprovisoire->motaplacer[taille-1]=='y'||motprovisoire->motaplacer[taille-1]=='A' || motprovisoire->motaplacer[taille-1]=='E' ||motprovisoire->motaplacer[taille-1]=='I' ||motprovisoire->motaplacer[taille-1]=='O' ||motprovisoire->motaplacer[taille-1]=='U' ||motprovisoire->motaplacer[taille-1]=='Y')

                {
                    *IsValid=0;
                     printf("\nErreur, des voyelles de 2 mots differents sont collees entre elles\n");
                }
            }
            for (j=col;j<col+taille;j++)
            {

                if ((j<15&&j>=0)&&(plateau[ligne-2][j].nom[1]=='A' || plateau[ligne-2][j].nom[1]=='E' ||plateau[ligne-2][j].nom[1]=='I' ||plateau[ligne-2][j].nom[1]=='O' ||plateau[ligne-2][j].nom[1]=='U' ||plateau[ligne-2][j].nom[1]=='Y'))
                {
                    if (motprovisoire->motaplacer[j-col]=='a' || motprovisoire->motaplacer[j-col]=='e' ||motprovisoire->motaplacer[j-col]=='i' ||motprovisoire->motaplacer[j-col]=='o' ||motprovisoire->motaplacer[j-col]=='u' ||motprovisoire->motaplacer[j-col]=='y'||motprovisoire->motaplacer[j-col]=='A' || motprovisoire->motaplacer[j-col]=='E' ||motprovisoire->motaplacer[j-col]=='I' ||motprovisoire->motaplacer[j-col]=='O' ||motprovisoire->motaplacer[j-col]=='U' ||motprovisoire->motaplacer[j-col]=='Y')
                    {
                        *IsValid=0;
                        printf("\nErreur, des voyelles de 2 mots differents sont collees entre elles\n");
                    }
                }
                if ((j<15&&j>=0)&&(plateau[ligne][j].nom[1]=='A' || plateau[ligne][j].nom[1]=='E' ||plateau[ligne][j].nom[1]=='I' ||plateau[ligne][j].nom[1]=='O' ||plateau[ligne][j].nom[1]=='U' ||plateau[ligne][j].nom[1]=='Y'))
                {
                    if (motprovisoire->motaplacer[j-col]=='a' || motprovisoire->motaplacer[j-col]=='e' ||motprovisoire->motaplacer[j-col]=='i' ||motprovisoire->motaplacer[j-col]=='o' ||motprovisoire->motaplacer[j-col]=='u' ||motprovisoire->motaplacer[j-col]=='y'||motprovisoire->motaplacer[j-col]=='A' || motprovisoire->motaplacer[j-col]=='E' ||motprovisoire->motaplacer[j-col]=='I' ||motprovisoire->motaplacer[j-col]=='O' ||motprovisoire->motaplacer[j-col]=='U' ||motprovisoire->motaplacer[j-col]=='Y')
                    {
                        *IsValid=0;
                        printf("\nErreur, des voyelles de 2 mots differents sont collees entre elles\n");
                    }
                }
            }
        }
    }
}












/// IA


void VerifMotaPlacerAvecChevaletIA(char chevalet[8],struct lettres *pioche, struct motprovisoire *motprovisoire,int *IsValid,int taille)
{
    int i,j,compteur=0,boucle=0;
    char copie[8] = "";

    strcpy(copie, chevalet);

    if(taille > 7 || taille==0)//verif taille du mot
    {
    }
    else
    {

        for(i=0;i<taille;i++)
        {
            boucle=0;
            for(j=0;j<7;j++)
            {
                if ((motprovisoire->motaplacer[i]==copie[j] || motprovisoire->motaplacer[i]==copie[j]-'A'+'a') && boucle==0 )
                {
                    copie[j]=0;
                    compteur+=1;
                    boucle=1;
                }
            }
        }
        if(compteur==taille)
        {
            *IsValid=1;
        }
    }
}



void VerifPositionMotPremierTourIA(int *IsValid,int tour,struct motprovisoire *motprovisoire, int isfirstmot)
{
    if (*IsValid==1 &&  isfirstmot==1)
    {
        if (  motprovisoire->nligne!=8 || motprovisoire->ncolonne != 'H')
        {

        motprovisoire->ncolonne='H';
        motprovisoire->nligne=8;



        }

    }
}


void VerifMotBienSurLePlateauIA(int *IsValid,char sens[1],int ligne,char colonne[1],int taille)
{

    if (*IsValid==1)

    {
        if (colonne>='a' && colonne<='o')
        {
            colonne=colonne-'a'+'A';
        }
        if (sens=='h'||sens=='H')
        {
            if (colonne<'A' || colonne>'O'-taille+1  || ligne<1 || ligne>15 )
            {
                *IsValid=0;

            }
        }
        if (sens=='v'||sens=='V')
        {
            if ( colonne<'A' || colonne>'O'|| ligne<1 || ligne>15 -taille+1 )
            {
                *IsValid=0;

            }
        }
    }
}



void VerifAuMoinsUneLettreCommuneIA(int *IsValid,char sens[1],int ligne,char colonne[1],int taille,struct cases plateau[15][15],struct motprovisoire *motprovisoire,int tour,int isfirstmot)
{
    int j;
    int occ=0;
    int lettrecommune=0;
    int col;

    col=colonne - 64;


    if (*IsValid==1 && isfirstmot!=1)
    {
        if (sens=='v'||sens=='V')
        {
            for (j=ligne-1;j<ligne-1+taille;j++)
            {
                if (plateau[j][col-1].nom[1] !=' ')
                {
                    if (plateau[ligne-1][j].nom[1]=='?'||plateau[j][col-1].nom[1]==motprovisoire->motaplacer[j-ligne+1] || plateau[j][col-1].nom[1]==motprovisoire->motaplacer[j-ligne+1]-'a'+'A')
                    {
                        occ+=1;
                        lettrecommune+=1;    //au moins une lettre commune

                    }
                    else
                    {
                        occ=occ;
                    }
                }
                else
                {
                    occ+=1;
                }
            }
            if(occ==taille && lettrecommune>=1)*IsValid=1;
            else
            {
                *IsValid=0;

            }

        }
        if (sens=='h'||sens=='H')
        {
            for (j=col-1;j<col-1+taille;j++)
            {
                if (plateau[ligne-1][j].nom[1] !=' ')
                {
                    if (plateau[ligne-1][j].nom[1]=='?'||plateau[ligne-1][j].nom[1]==motprovisoire->motaplacer[j-col+1] || plateau[ligne-1][j].nom[1]==motprovisoire->motaplacer[j-col+1]-'a'+'A')
                    {
                        occ+=1;
                        lettrecommune+=1;    //au moins une lettre commune
                    }
                    else
                    {
                        occ=occ;
                    }
                }
                else
                {
                    occ+=1;
                }
            }
            if(occ==taille && lettrecommune>=1)*IsValid=1;
            else
            {
                *IsValid=0;

            }

        }
    }
}



void VerifPasDeuxVoyellesCoteACoteIA(int *IsValid,char sens[1],int ligne,char colonne[1],int taille,struct cases plateau[15][15],struct motprovisoire *motprovisoire)
{

    int j,col;
    col=colonne -'A';

    if (*IsValid==1)
    {
        if (sens=='v'||sens=='V')
        {


            if ((ligne-2>=0)&&(plateau[ligne-2][col].nom[1]=='A' || plateau[ligne-2][col].nom[1]=='E' ||plateau[ligne-2][col].nom[1]=='I' ||plateau[ligne-2][col].nom[1]=='O' ||plateau[ligne-2][col].nom[1]=='U' ||plateau[ligne-2][col].nom[1]=='Y'))
            {
                if (motprovisoire->motaplacer[0]=='a' || motprovisoire->motaplacer[0]=='e' ||motprovisoire->motaplacer[0]=='i' ||motprovisoire->motaplacer[0]=='o' ||motprovisoire->motaplacer[0]=='u' ||motprovisoire->motaplacer[0]=='y'||motprovisoire->motaplacer[0]=='A' || motprovisoire->motaplacer[0]=='E' ||motprovisoire->motaplacer[0]=='I' ||motprovisoire->motaplacer[0]=='O' ||motprovisoire->motaplacer[0]=='U' ||motprovisoire->motaplacer[0]=='Y')
                {
                    *IsValid=0;


                }
            }
            if ((ligne-1+taille<15)&&(plateau[ligne-1+taille][col].nom[1]=='A' || plateau[ligne-1+taille][col].nom[1]=='E' || plateau[ligne-1+taille][col].nom[1]=='I' || plateau[ligne-1+taille][col].nom[1]=='O' || plateau[ligne-1+taille][col].nom[1]=='U' ||plateau[ligne-1+taille][col].nom[1]=='Y'))
            {
                if (motprovisoire->motaplacer[taille-1]=='a' || motprovisoire->motaplacer[taille-1]=='e' ||motprovisoire->motaplacer[taille-1]=='i' ||motprovisoire->motaplacer[taille-1]=='o' ||motprovisoire->motaplacer[taille-1]=='u' ||motprovisoire->motaplacer[taille-1]=='y'||motprovisoire->motaplacer[taille-1]=='A' || motprovisoire->motaplacer[taille-1]=='E' ||motprovisoire->motaplacer[taille-1]=='I' ||motprovisoire->motaplacer[taille-1]=='O' ||motprovisoire->motaplacer[taille-1]=='U' ||motprovisoire->motaplacer[taille-1]=='Y')
                {
                    *IsValid=0;

                }
            }


            for (j=ligne-1;j<ligne-1+taille;j++)
            {

                if ((j<15&&j>=0)&&(plateau[j][col-1].nom[1]=='A' || plateau[j][col-1].nom[1]=='E' ||plateau[j][col-1].nom[1]=='I' ||plateau[j][col-1].nom[1]=='O' ||plateau[j][col-1].nom[1]=='U' ||plateau[j][col-1].nom[1]=='Y'))
                {
                    if (motprovisoire->motaplacer[j-ligne+1]=='a' || motprovisoire->motaplacer[j-ligne+1]=='e' ||motprovisoire->motaplacer[j-ligne+1]=='i' ||motprovisoire->motaplacer[j-ligne+1]=='o' ||motprovisoire->motaplacer[j-ligne+1]=='u' ||motprovisoire->motaplacer[j-ligne+1]=='y'||motprovisoire->motaplacer[j-ligne+1]=='A' || motprovisoire->motaplacer[j-ligne+1]=='E' ||motprovisoire->motaplacer[j-ligne+1]=='I' ||motprovisoire->motaplacer[j-ligne+1]=='O' ||motprovisoire->motaplacer[j-ligne+1]=='U' ||motprovisoire->motaplacer[j-ligne+1]=='Y')
                    {
                        *IsValid=0;

                    }
                }
                if ((j<15&&j>=0)&&(plateau[j][col+1].nom[1]=='A' || plateau[j][col+1].nom[1]=='E' ||plateau[j][col+1].nom[1]=='I' ||plateau[j][col+1].nom[1]=='O' ||plateau[j][col+1].nom[1]=='U' ||plateau[j][col+1].nom[1]=='Y'))
                {
                    if (motprovisoire->motaplacer[j-ligne+1]=='a' || motprovisoire->motaplacer[j-ligne+1]=='e' ||motprovisoire->motaplacer[j-ligne+1]=='i' ||motprovisoire->motaplacer[j-ligne+1]=='o' ||motprovisoire->motaplacer[j-ligne+1]=='u' ||motprovisoire->motaplacer[j-ligne+1]=='y'||motprovisoire->motaplacer[j-ligne+1]=='A' || motprovisoire->motaplacer[j-ligne+1]=='E' ||motprovisoire->motaplacer[j-ligne+1]=='I' ||motprovisoire->motaplacer[j-ligne+1]=='O' ||motprovisoire->motaplacer[j-ligne+1]=='U' ||motprovisoire->motaplacer[j-ligne+1]=='Y')
                    {
                        *IsValid=0;

                    }
                }
            }
        }





        if (sens=='h'||sens=='H')
        {
            if ((col-1>=0)&&(plateau[ligne-1][col-1].nom[1]=='A' || plateau[ligne-1][col-1].nom[1]=='E' ||plateau[ligne-1][col-1].nom[1]=='I' ||plateau[ligne-1][col-1].nom[1]=='O' ||plateau[ligne-1][col-1].nom[1]=='U' ||plateau[ligne-1][col-1].nom[1]=='Y'))
            {
                if (motprovisoire->motaplacer[0]=='a' || motprovisoire->motaplacer[0]=='e' ||motprovisoire->motaplacer[0]=='i' ||motprovisoire->motaplacer[0]=='o' ||motprovisoire->motaplacer[0]=='u' ||motprovisoire->motaplacer[0]=='y'||motprovisoire->motaplacer[0]=='A' || motprovisoire->motaplacer[0]=='E' ||motprovisoire->motaplacer[0]=='I' ||motprovisoire->motaplacer[0]=='O' ||motprovisoire->motaplacer[0]=='U' ||motprovisoire->motaplacer[0]=='Y')
                {
                    *IsValid=0;

                }
            }
            if ((col+taille<15)&&(plateau[ligne-1][col+taille].nom[1]=='A' || plateau[ligne-1][col+taille].nom[1]=='E' ||plateau[ligne-1][col+taille].nom[1]=='I' ||plateau[ligne-1][col+taille].nom[1]=='O' ||plateau[ligne-1][col+taille].nom[1]=='U' ||plateau[ligne-1][col+taille].nom[1]=='Y'))
            {
                if (motprovisoire->motaplacer[taille-1]=='a' || motprovisoire->motaplacer[taille-1]=='e' ||motprovisoire->motaplacer[taille-1]=='i' ||motprovisoire->motaplacer[taille-1]=='o' ||motprovisoire->motaplacer[taille-1]=='u' ||motprovisoire->motaplacer[taille-1]=='y'||motprovisoire->motaplacer[taille-1]=='A' || motprovisoire->motaplacer[taille-1]=='E' ||motprovisoire->motaplacer[taille-1]=='I' ||motprovisoire->motaplacer[taille-1]=='O' ||motprovisoire->motaplacer[taille-1]=='U' ||motprovisoire->motaplacer[taille-1]=='Y')

                {
                    *IsValid=0;

                }
            }
            for (j=col;j<col+taille;j++)
            {

                if ((j<15&&j>=0)&&(plateau[ligne-2][j].nom[1]=='A' || plateau[ligne-2][j].nom[1]=='E' ||plateau[ligne-2][j].nom[1]=='I' ||plateau[ligne-2][j].nom[1]=='O' ||plateau[ligne-2][j].nom[1]=='U' ||plateau[ligne-2][j].nom[1]=='Y'))
                {
                    if (motprovisoire->motaplacer[j-col]=='a' || motprovisoire->motaplacer[j-col]=='e' ||motprovisoire->motaplacer[j-col]=='i' ||motprovisoire->motaplacer[j-col]=='o' ||motprovisoire->motaplacer[j-col]=='u' ||motprovisoire->motaplacer[j-col]=='y'||motprovisoire->motaplacer[j-col]=='A' || motprovisoire->motaplacer[j-col]=='E' ||motprovisoire->motaplacer[j-col]=='I' ||motprovisoire->motaplacer[j-col]=='O' ||motprovisoire->motaplacer[j-col]=='U' ||motprovisoire->motaplacer[j-col]=='Y')
                    {
                        *IsValid=0;

                    }
                }
                if ((j<15&&j>=0)&&(plateau[ligne][j].nom[1]=='A' || plateau[ligne][j].nom[1]=='E' ||plateau[ligne][j].nom[1]=='I' ||plateau[ligne][j].nom[1]=='O' ||plateau[ligne][j].nom[1]=='U' ||plateau[ligne][j].nom[1]=='Y'))
                {
                    if (motprovisoire->motaplacer[j-col]=='a' || motprovisoire->motaplacer[j-col]=='e' ||motprovisoire->motaplacer[j-col]=='i' ||motprovisoire->motaplacer[j-col]=='o' ||motprovisoire->motaplacer[j-col]=='u' ||motprovisoire->motaplacer[j-col]=='y'||motprovisoire->motaplacer[j-col]=='A' || motprovisoire->motaplacer[j-col]=='E' ||motprovisoire->motaplacer[j-col]=='I' ||motprovisoire->motaplacer[j-col]=='O' ||motprovisoire->motaplacer[j-col]=='U' ||motprovisoire->motaplacer[j-col]=='Y')
                    {
                        *IsValid=0;

                    }
                }
            }
        }
    }
}


