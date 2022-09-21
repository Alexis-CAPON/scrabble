#include "prototypes.h"

void InitialisationPartie(struct game *partie, struct players joueur[4], struct lettres *pioche, struct cases plateau[15][15], int nouvellepartie)
{
    int nombredejoueurs=1;
    int nombredejoueursisvalid=0;
    int avecIA = 0;
    int nombredeIA = 0;
    int nombredeIAisvalid = 0;
    int nombredeIAmax = 0;
    int nombredeIAmin = 1;


    if (nouvellepartie ==1)
    {

            printf("\nBien, c'est parti !");

            sleep(1); // TEMPS D'ATTENTE
            system("cls");
            printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
            printf("/         ######       #####       ######              #####        ####       #####        ####        #####         /\n");
            printf("/         #           ##   ##      #                   ##  ##      ##  ##      ##  ##        ##        ##             /\n");
            printf("/         #####       ##           ######              #####       ######      ######        ##         ####          /\n");
            printf("/         #           ##   ##      #                   ##          ##  ##      #####         ##            ##         /\n");
            printf("/         ######       #####       ######              ##          #    #      ##  ##       ####       #####          /\n");
            printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
            printf("\n\n");

            // Configuration de la nouvelle partie

            printf("Configuration de la nouvelle partie !\n\n");
            do
            {
                printf("Voulez-vous jouer avec ou sans IA ? (1 - Avec / 2 - Sans)\n\n");

                fflush(stdin);
                avecIA = getchar();

            }while(avecIA!=49 && avecIA !=50);

            if(avecIA==49)
            {
                system("cls");
                printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
                printf("/         ######       #####       ######              #####        ####       #####        ####        #####         /\n");
                printf("/         #           ##   ##      #                   ##  ##      ##  ##      ##  ##        ##        ##             /\n");
                printf("/         #####       ##           ######              #####       ######      ######        ##         ####          /\n");
                printf("/         #           ##   ##      #                   ##          ##  ##      #####         ##            ##         /\n");
                printf("/         ######       #####       ######              ##          #    #      ##  ##       ####       #####          /\n");
                printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
                printf("\n\n");
                do
                {


                printf("Combien voulez-vous de joueur humains ? (0, 1, 2 ou 3 ?)\n");

                fflush(stdin);
                scanf("%d",&nombredejoueurs);


                if (nombredejoueurs>3)
                {
                    printf("Votre partie ne peut pas comporter plus de 3 joueurs humains !\n");
                }
                else
                {
                    if (nombredejoueurs<0)
                    {
                        printf("Hum les nombres negatifs...\n");
                    }
                    else
                    {
                        nombredejoueursisvalid=1;
                    }
                }

                }
                while(nombredejoueursisvalid!=1);


                do
                {
                nombredeIAmax = 4 - nombredejoueurs;
                nombredeIAmin = 1;
                if (nombredejoueurs==0)
                {
                    nombredeIAmin = 2;
                }
                printf("Combien voulez-vous de IA ?(de %d a %d?)\n",nombredeIAmin,nombredeIAmax);

                fflush(stdin);
                scanf("%d",&nombredeIA);

                if (nombredeIA>nombredeIAmax)
                {
                    printf("Votre partie ne peut pas comporter plus de %d IA !\n",nombredeIAmax);
                }
                else
                {
                    if (nombredeIA<nombredeIAmin)
                    {
                        printf("Vous devez avoir au minimum %d IA !\n",nombredeIAmin);
                    }
                    else
                    {
                        nombredeIAisvalid=1;
                    }
                }

                }while(nombredeIAisvalid!=1);

                nombredejoueurs = nombredejoueurs + nombredeIA;
                printf("\n\nBien ! Creation de la partie pour %d joueurs !\n\n",nombredejoueurs);

                partie->nombrejoueurs = nombredejoueurs;
                partie->encours = 1;
                partie->touractuel = 1;
                partie->pioche = 102;


                InitialisationNomdesjoueursavecIA(partie,joueur,nombredeIA);

                system("cls");
                printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
                printf("/         ######       #####       ######              #####        ####       #####        ####        #####         /\n");
                printf("/         #           ##   ##      #                   ##  ##      ##  ##      ##  ##        ##        ##             /\n");
                printf("/         #####       ##           ######              #####       ######      ######        ##         ####          /\n");
                printf("/         #           ##   ##      #                   ##          ##  ##      #####         ##            ##         /\n");
                printf("/         ######       #####       ######              ##          #    #      ##  ##       ####       #####          /\n");
                printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
                printf("\n\n");
                printf("Les nom des joueurs ont ete sauvegarde !\n\n");

                sleep(1); // TEMPS D'ATTENTE
                printf("Lancement de la partie en cours !!\n\n");

                sleep(2); // TEMPS D'ATTENTE

                //Remise à zéro du plateau de jeu et de la pioche
                InitialisationPioche(pioche);
                InitialisationPlateau(plateau);


                // Creation du chevalet de départ
                InitialisationChevalet(partie,joueur,pioche,plateau);

                //Lancement du jeu
                CurrentGame(partie,joueur,pioche,plateau);


            }
            else
            {
                system("cls");
                printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
                printf("/         ######       #####       ######              #####        ####       #####        ####        #####         /\n");
                printf("/         #           ##   ##      #                   ##  ##      ##  ##      ##  ##        ##        ##             /\n");
                printf("/         #####       ##           ######              #####       ######      ######        ##         ####          /\n");
                printf("/         #           ##   ##      #                   ##          ##  ##      #####         ##            ##         /\n");
                printf("/         ######       #####       ######              ##          #    #      ##  ##       ####       #####          /\n");
                printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
                printf("\n\n");

            do
            {

                printf("Combien voulez-vous de joueurs ?\n");

                fflush(stdin);
                scanf("%d",&nombredejoueurs);


                if (nombredejoueurs>4)
                {
                    printf("Vous ne pouvez pas jouer a plus de 4 joueurs !\n");
                }
                else
                {
                    if (nombredejoueurs<2)
                    {
                        printf("Il est triste de jouer seul ! Vous devez etre au minimum 2 !\n");
                    }
                    else
                    {
                        nombredejoueursisvalid=1;
                    }
                }

            }
            while(nombredejoueursisvalid!=1);


            printf("\n\nBien ! Creation de la partie pour %d joueurs !\n\n",nombredejoueurs);

            partie->nombrejoueurs = nombredejoueurs;
            partie->encours = 1;
            partie->touractuel = 1;
            partie->pioche = 102;

            InitialisationNomdesjoueurs(partie,joueur);


            system("cls");
            printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
            printf("/         ######       #####       ######              #####        ####       #####        ####        #####         /\n");
            printf("/         #           ##   ##      #                   ##  ##      ##  ##      ##  ##        ##        ##             /\n");
            printf("/         #####       ##           ######              #####       ######      ######        ##         ####          /\n");
            printf("/         #           ##   ##      #                   ##          ##  ##      #####         ##            ##         /\n");
            printf("/         ######       #####       ######              ##          #    #      ##  ##       ####       #####          /\n");
            printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
            printf("\n\n");
            printf("Les nom des joueurs ont ete sauvegarde !\n\n");

            sleep(1); // TEMPS D'ATTENTE
            printf("Lancement de la partie en cours !!\n\n");

            sleep(2); // TEMPS D'ATTENTE

            //Remise à zéro du plateau de jeu et de la pioche
            InitialisationPioche(pioche);
            InitialisationPlateau(plateau);


            // Creation du chevalet de départ
            InitialisationChevalet(partie,joueur,pioche,plateau);

            //Lancement du jeu
            CurrentGame(partie,joueur,pioche,plateau);
            }
    }
    else
    {
        // Lecture des fichiers txt
        InitialisationPlateau(plateau);
        ChargerPlateau(partie, joueur, pioche, plateau);

        //AffichagePlateau(plateau);
        CurrentGame(partie, joueur, pioche, plateau);
    }

}

void InitialisationNomdesjoueurs(struct game *partie, struct players joueur[4])
{
    int i;

    // Remise à zéro des noms

    for(i=0; i<4; i++)
    {
        strcpy(joueur[i].nomdujoueur,"");
    }

    for(i=0; i<partie->nombrejoueurs; i++)
    {
        printf("Veuillez rentrer le nom du joueur %d !\n",i+1);

        fflush(stdin);
        gets(joueur[i].nomdujoueur);
        joueur[i].score=0;
        joueur[i].isIA = 0;
        joueur[i].color = (rand() % (14 + 1 - 1)) + 1;
    }




}

void InitialisationNomdesjoueursavecIA(struct game *partie, struct players joueur[4], int nombreIA)
{
    int i,j=49;
    char chaine1[4] = "IA-";
    char chaine2[2] = "";

    int nombrevraijoueur = partie->nombrejoueurs - nombreIA;

    // Remise à zéro des noms

    for(i=0; i<4; i++)
    {
        strcpy(joueur[i].nomdujoueur,"");
    }

    if (nombrevraijoueur!=0)
    {
    for(i=0; i<nombrevraijoueur; i++)
    {
        printf("Veuillez rentrer le nom du joueur %d !\n",i+1);

        fflush(stdin);
        gets(joueur[i].nomdujoueur);
        joueur[i].score=0;
        joueur[i].isIA = 0;
        joueur[i].color = (rand() % (14 + 1 - 1)) + 1;
    }
    }

    for(i=nombrevraijoueur; i<partie->nombrejoueurs; i++)
    {
        strcpy(chaine1,"IA-");
        chaine2[0] = j;
        strcat(chaine1,chaine2);
        strcpy(joueur[i].nomdujoueur,chaine1);
        joueur[i].score=0;
        joueur[i].isIA = 1;
        joueur[i].color = (rand() % (14 + 1 - 1)) + 1;
        j++;
    }

}

void CurrentGame(struct game *partie, struct players joueur[4], struct lettres *pioche, struct cases plateau[15][15] )
{
    char vainqueur[80] = "";
    int numerodujoueuractuel = CalculJoueurActuel(partie->nombrejoueurs,partie->touractuel);
    int motIsValid = 0;
    int joueurconfirmation = 0;
    struct motprovisoire motprovisoire = {};
    strcpy(motprovisoire.motaplacer,"");
    motprovisoire.ncolonne=' ';
    motprovisoire.nligne=0;
    motprovisoire.sens=' ';

    int choixpretour = 0;
    int scrabble = 0;

    int choixfintour = 0;
    char choixechangelettre[80] = "";
    char pixelechangelettre[8] = "";
    int i,j,k,random;

    int conditionfindepartie = 0;
    int validitemot = 0;
    int validitemotjoueur = 0;

    int ancienscore = 0;
    char ancienchevalet[8] = "";

    int quitterlapartie = 0;

    int choixjoueur = 0;

    int isfirstmot = 1;

    int isIAplayed = 0;
    FILE* dico = NULL;

    for(i=0;i<partie->nombrejoueurs;i++)
    {
        if(joueur[i].score!=0)
        {
            isfirstmot = 0;
        }
    }



    /* DEBUT DE RESIZE
    SOURCE :
    https://www.programming-techniques.com/2011/09/how-to-resize-console-window-using-c.html
    De la ligne 173 à ligne 184 : Le code vient directement de ce site.
    */

    int largeur = 110, hauteur = 50;
    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, largeur, hauteur};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    // Change the console window size:
    // Create a COORD to hold the buffer size:
    COORD bufferSize = {10, 10};
    SetConsoleScreenBufferSize(wHnd, bufferSize);

    /*
        FIN DU PROGRAMME DE RESIZE
    */



    /// Tours
   do
   {
       if (joueur[numerodujoueuractuel-1].isIA == 1)
       {
           system("cls");
           AffichagePlateau(plateau);
           AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
           AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

           printf("\n L'%s reflechit.",joueur[numerodujoueuractuel-1].nomdujoueur);
           sleep(1);
           printf(".");
           sleep(1);
           printf(".");

           /// Trouver un mot
            dico = fopen("data/dico/francais.txt","r");

            for(i=0;i<208913;i++)
            {
                if (motIsValid==0)
                {
                    strcpy(motprovisoire.motaplacer,"");
                    fscanf(dico,"%s",motprovisoire.motaplacer);
                    if (strlen(motprovisoire.motaplacer)<=7)
                    {
                        for(j=1;j<16;j++)
                        {
                            for(k='A';k<'P';k++)
                            {
                                if (motIsValid==0)
                                {
                                    motprovisoire.ncolonne = k;
                                    motprovisoire.nligne = j;
                                    motprovisoire.sens = 'H';

                                    AffichageRecupVerifMAPIA(joueur[numerodujoueuractuel-1].chevalet, pioche, &motIsValid, &motprovisoire, plateau, partie->touractuel, isfirstmot);

                                }
;
                                if (motIsValid==0)
                                {
                                    motprovisoire.ncolonne = k;
                                    motprovisoire.nligne = j;
                                    motprovisoire.sens = 'V';
                                    AffichageRecupVerifMAPIA(joueur[numerodujoueuractuel-1].chevalet, pioche, &motIsValid, &motprovisoire, plateau, partie->touractuel, isfirstmot);
                                }

                            }
                        }



                    }
                }
                else
                {
                    break;
                }
            }


            fclose(dico);
            sleep(4);

           /// Résultat de la recherche si aucun mot trouvé ou si un mot a été trouvé

            if (motIsValid==1)
            {

                MinusToUpper(&motprovisoire);
                //Suppression des lettres du mots dans le chevalet
                DeleteChevaletLetter(motprovisoire,joueur,numerodujoueuractuel);
                //Réajustement du chevalet en fonction du nombre de lettre manquante
                AjustementChevalet(joueur,pioche,numerodujoueuractuel,partie,&scrabble);
                //Mise en place des lettres dans le tableau
                //Pour chaque cases dans le plateau, l'attribuer au bon joueur pour le calcul des scores
                MiseEnPlaceLettres(motprovisoire,numerodujoueuractuel,plateau,joueur[numerodujoueuractuel-1].color);
                //Calcul du score en fonction des cases et des lettres
                CalculScorePlayer(partie,joueur,pioche,plateau,numerodujoueuractuel,motprovisoire);

                /// Affichage du nouveau plateau, nouveau score et nouveau chevalet
                system("cls");
                AffichagePlateau(plateau);
                AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
                AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

                if (scrabble ==1)
                {
                    printf("\n[Console] %s vient de faire un Scrabble !!",joueur[numerodujoueuractuel-1].nomdujoueur);
                    joueur[numerodujoueuractuel-1].score += 50;
                    sleep(2);
                }

                printf("\n\n\tL'%s termine maintenant son tour..",joueur[numerodujoueuractuel-1].nomdujoueur);
                sleep(3);

                if(isfirstmot==1)
                {
                    isfirstmot=0;
                }

            }
            else
            {

                isIAplayed = (rand() % (1 + 1 - 0)) + 0;
                 if (isIAplayed==1)
                {
                printf("\n\n\tL'%s echange une ou plusieurs lettres..",joueur[numerodujoueuractuel-1].nomdujoueur);
                sleep(3);
                random = (rand() % (7 + 1 - 1)) + 1;
                for(i=0;i<random;i++)
                {
                    pixelechangelettre[i] = joueur[numerodujoueuractuel-1].chevalet[i];
                }

                DeleteChevaletLetterBis(pixelechangelettre,joueur,numerodujoueuractuel,pioche,partie);
                AjustementChevaletBis(joueur,pioche,numerodujoueuractuel,partie);

                system("cls");
                AffichagePlateau(plateau);
                AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
                AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

                printf("\n\n\t[Console] Echange effectue ! L'%s termine maintenant son tour..",joueur[numerodujoueuractuel-1].nomdujoueur);
                sleep(3);

                }

                if (isIAplayed==0)
                {
                printf("\n\n\tL'%s passe son tour !",joueur[numerodujoueuractuel-1].nomdujoueur);
                sleep(3);
                isIAplayed = 1;
                }
            }


       }
       else
       {
       if (quitterlapartie==1)
       {
           break;
       }

       /// Debut d'un tour
       // Selection du mot à placer
        do
        {
            system("cls");
            AffichagePlateau(plateau);
            AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
            AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

            printf("\n Que voulez-vous faire ce tour ?");
            printf("\n\n 1 - Poser un mot");
            if (isfirstmot==1)
            {
                printf("\n 2 - Echanger une ou plusieurs lettres");
                printf("\n 3 - Retour au menu principal");

            }
            else
            {
                printf("\n 2 - Passer mon tour");
                printf("\n 3 - Echanger une ou plusieurs lettres");
                printf("\n 4 - Retour au menu principal");

            }

            printf("\n\n Votre choix : ");

            fflush(stdin);
            choixpretour = getchar();

            if (isfirstmot==1)
            {
                if(choixpretour==49 || choixpretour== 50 || choixpretour== 51)
                {
                    choixjoueur = 1;
                    if (choixpretour== 50 || choixpretour== 51)
                    {
                        choixpretour+=1;
                    }
                }

            }
            else
            {
                if(choixpretour==49 || choixpretour== 50 || choixpretour== 51 || choixpretour==52)
                {
                    choixjoueur = 1;
                }

            }

        }while( choixjoueur == 0 );


        if (choixpretour==50)
        {
            system("cls");
            AffichagePlateau(plateau);
            AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
            AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

            printf("\n\n\tVous passez votre tour !");
            sleep(1);

        }

        if (choixpretour==52)
        {
            system("cls");
            AffichagePlateau(plateau);
            AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
            AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

            printf("\n\n\tRetour au menu principale..");
            quitterlapartie = 1;
            sleep(1);

        }

        if (choixpretour==51)
        {
            system("cls");
            AffichagePlateau(plateau);
            AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
            AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);
            printf("\n Quelle(s) lettre(s) voulez-vous echanger ?(entrez le nom des lettres)");

            printf("\n\n Votre choix : ");

            fflush(stdin);
            gets(choixechangelettre);
            j=0;
            for(i=0;i<80;i++)
            {
                if(choixechangelettre[i]!=' ' && j<7)
                {
                    pixelechangelettre[j] = choixechangelettre[i];
                    j++;
                }
            }

            printf("\n\n Tres bien.. echange des lettres en cours..");

            DeleteChevaletLetterBis(pixelechangelettre,joueur,numerodujoueuractuel,pioche,partie);
            AjustementChevaletBis(joueur,pioche,numerodujoueuractuel,partie);
            sleep(2);

            system("cls");
            AffichagePlateau(plateau);
            AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
            AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

            printf("\n\n\t[Console] Echange effectue ! Vous terminez maintenant votre tour..");
            sleep(3);

        }

        if (choixpretour==49)
        {

       do
       {

        /// Début du tour
        // Selection, (1 - Poser un mot / 2- Passer son tour ou et changer lettres)
        do
        {

        system("cls");
        AffichagePlateau(plateau);
        AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);

        AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

        printf("[Console] Entrez le mot a placer..");

        /// Mot a placer

        AffichageRecupVerifMAP(joueur[numerodujoueuractuel-1].chevalet, pioche, &motIsValid, &motprovisoire, plateau, partie->touractuel, isfirstmot);

        if (motIsValid==0)
        {
            printf("\t[Console] Le mot n'est pas valide ! Appuyer sur Entrer pour mettre un nouveau mot..");

            fflush(stdin);
            while (getchar() != '\n');
        }

        }while(motIsValid==0);
        /// Preconfirmation joueur


        MinusToUpper(&motprovisoire); // Passage en majuscule du mot

        system("cls");
        AffichagePlateau(plateau);
        AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
        AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);


        AffichageMotaPlacer(&motprovisoire);

        printf("\t\t[Console] Le mot est valide !");


        /// Confirmation joueur

        AffichageConfirmationMot(&joueurconfirmation);

        }while(joueurconfirmation==0);



        /// Mise en place du mot dans le plateau et actualisation du score et du chevalet et de la pioche
        //Suppression des lettres du mots dans le chevalet
        //Réajustement du chevalet en fonction du nombre de lettre manquante
        //Mise en place des lettres dans le tableau
        //Pour chaque cases dans le plateau, l'attribuer au bon joueur pour le calcul des scores
        //Calcul du score en fonction des cases et des lettres

        for(i=0;i<7;i++)
        {
            ancienchevalet[i] = joueur[numerodujoueuractuel-1].chevalet[i];
        }
        ancienscore = joueur[numerodujoueuractuel-1].score;

        //Suppression des lettres du mots dans le chevalet
        DeleteChevaletLetter(motprovisoire,joueur,numerodujoueuractuel);
        //Réajustement du chevalet en fonction du nombre de lettre manquante
        AjustementChevalet(joueur,pioche,numerodujoueuractuel,partie,&scrabble);
        //Mise en place des lettres dans le tableau
        //Pour chaque cases dans le plateau, l'attribuer au bon joueur pour le calcul des scores
        MiseEnPlaceLettres(motprovisoire,numerodujoueuractuel,plateau,joueur[numerodujoueuractuel-1].color);
        //Calcul du score en fonction des cases et des lettres
        CalculScorePlayer(partie,joueur,pioche,plateau,numerodujoueuractuel,motprovisoire);

        /// Affichage du nouveau plateau, nouveau score et nouveau chevalet
        system("cls");
        AffichagePlateau(plateau);
        AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
        AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

        if (scrabble ==1)
        {
            printf("\n[Console] %s vient de faire un Scrabble !!",joueur[numerodujoueuractuel-1].nomdujoueur);
            joueur[numerodujoueuractuel-1].score += 50;
            sleep(2);
        }


        // Confirmation fin de tour
        // 1 - Finir le tour
        // 2 - Verification du mot
        do
        {
            system("cls");
            AffichagePlateau(plateau);
            AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
            AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

            printf("\n  Fin de votre tour ! Que voulez-vous faire ?");
            printf("\n\n 1 - Finir mon tour");
            printf("\n 2 - Verification du mot");

            printf("\n\n Votre choix : ");

            fflush(stdin);
            choixfintour = getchar();


        }while(choixfintour!=49 && choixfintour!=50);

        if (choixfintour==49)
        {
            printf("Vous terminez votre tour..");
            if(isfirstmot==1)
            {
                isfirstmot=0;
            }
            sleep(1);
        }

        if (choixfintour==50)
        {
            do
            {
            system("cls");
            AffichagePlateau(plateau);
            AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
            AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

            printf("\n  Quel joueur souhaite verifier le mot de %s ? (entrer le numero correspondant)",joueur[numerodujoueuractuel-1].nomdujoueur);
            printf("\n");

            for(i=0;i<partie->nombrejoueurs;i++)
            {
                printf("\n %d - %s",i+1,joueur[i].nomdujoueur);
            }

            printf("\n");

            printf("\n\n Votre choix : ");

                fflush(stdin);
                validitemotjoueur = getchar();
                if (validitemotjoueur==49||validitemotjoueur==50||validitemotjoueur==51||validitemotjoueur==52)
                {
                    if(validitemotjoueur-48<=partie->nombrejoueurs)
                    {
                        validitemot = 1 ;
                    }
                }



            }while(validitemot==0);
            validitemot = 0;
            system("cls");
            AffichagePlateau(plateau);
            AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
            AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

            printf("\n %s souhaite verifier le mot !",joueur[validitemotjoueur-48-1].nomdujoueur);


            printf("\n\n [Console] Les joueurs doivent se consulter pour verifier le mot !");

            sleep(2);
            do
            {
                printf("\n  Le mot est-il correcte ?");

                printf("\n\n 1 - Oui");
                printf("\n 2 - Non");
                printf("\n\n Votre choix : ");

                fflush(stdin);
                validitemot = getchar();

            }while(validitemot!=49&&validitemot!=50);


            system("cls");
            AffichagePlateau(plateau);
            AffichagePlayerAndScore(joueur[numerodujoueuractuel-1].nomdujoueur, joueur[numerodujoueuractuel-1].score, partie->touractuel,joueur[numerodujoueuractuel-1].color);
            AffichageChevalet(joueur[numerodujoueuractuel-1].chevalet, pioche);

            printf("\n  Ajustement en cours suivant le resultat de la validation..");

            if (validitemot==49)
            {
                printf("\n\n [Console] Le mot est valide !\n");
                printf(" [Console] Aie aie aie, coup dur pour %s ! Il perd 10 point !\n",joueur[validitemotjoueur-48-1].nomdujoueur);
                joueur[validitemotjoueur-48-1].score -= 10;
                if(isfirstmot==1)
                {
                    isfirstmot=0;
                }
                sleep(3);
            }
            else if(validitemot==50)
            {
                printf("\n\n [Console] Le mot n'est pas correcte !\n");
                joueur[numerodujoueuractuel-1].score = ancienscore;
                for(i=0;i<7;i++)
                {
                    if (joueur[numerodujoueuractuel-1].chevalet[i] != ancienchevalet[i])
                    {
                        AjustementPioche(joueur[numerodujoueuractuel-1].chevalet[i],pioche,partie);
                    }
                    joueur[numerodujoueuractuel-1].chevalet[i] = ancienchevalet[i];
                }

                EnleverLettres(motprovisoire,numerodujoueuractuel,plateau);

                sleep(3);
            }



        }


        }
}
        /// Fin du tour
        if(quitterlapartie==0)
        {

       numerodujoueuractuel+=1;
       if (numerodujoueuractuel>partie->nombrejoueurs)
            numerodujoueuractuel=1;

        partie->touractuel += 1;
        ///Reset
        motIsValid=0;
        joueurconfirmation = 0;
        choixpretour = 0;
        scrabble = 0;
        choixfintour = 0;

        strcpy(choixechangelettre,"");
        strcpy(pixelechangelettre,"");

        validitemot = 0;
        validitemotjoueur = 0;

        ancienscore = 0;
        strcpy(ancienchevalet,"");

        choixjoueur = 0;

        isIAplayed = 0;

        /// Reset Structure
        strcpy(motprovisoire.motaplacer,"");
        motprovisoire.ncolonne=' ';
        motprovisoire.nligne=0;
        motprovisoire.sens=' ';

        ///Sauvegarde des fichiers
        SauvegarderGame(partie, joueur, pioche, plateau);
    }

        ///Test fin de partie

        if(partie->pioche<=0)
        {
            conditionfindepartie = 1;
        }

   }while(conditionfindepartie==0);




   /// Fin de partie
   if(quitterlapartie==1)
   {
        GameMenu(partie, joueur, pioche, plateau);
   }
   else
   {
    EndGame(partie,joueur,pioche,plateau,vainqueur);
    }

}


void EndGame(struct game *partie, struct players joueur[4], struct lettres *pioche, struct cases plateau[15][15], char vainqueur[80])
{
    system("cls");
   /* DEBUT DE RESIZE
    SOURCE :
    https://www.programming-techniques.com/2011/09/how-to-resize-console-window-using-c.html
    De la ligne 572 à ligne 584 : Le code vient directement de ce site.
    */
    int largeur = 120, hauteur = 30;
    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, largeur, hauteur};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    // Change the console window size:
    // Create a COORD to hold the buffer size:
    COORD bufferSize = {10, 10};
    SetConsoleScreenBufferSize(wHnd, bufferSize);

    /*
        FIN DU PROGRAMME DE RESIZE
    */
    sleep(1);
    system("cls");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("/         ######       #####       ######              #####        ####       #####        ####        #####         /\n");
    printf("/         #           ##   ##      #                   ##  ##      ##  ##      ##  ##        ##        ##             /\n");
    printf("/         #####       ##           ######              #####       ######      ######        ##         ####          /\n");
    printf("/         #           ##   ##      #                   ##          ##  ##      #####         ##            ##         /\n");
    printf("/         ######       #####       ######              ##          #    #      ##  ##       ####       #####          /\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

    // Menu
    printf("\n\n");

    printf("\t\t\t\t\t /////////////////////////////////\n");
    printf("\t\t\t\t\t /          FIN DE PARTIE        /\n");
    printf("\t\t\t\t\t /////////////////////////////////\n");

    printf("\n\n");


    int max = joueur[0].score;
    int i = 0;

    for(i=0;i<partie->nombrejoueurs;i++)
    {
        if(joueur[i].score>=max)
        {
            max = joueur[i].score;
            strcpy(vainqueur,joueur[i].nomdujoueur);
        }
    }

    printf("\t%s a gagne la partie !! ",vainqueur);
    partie->encours=0;
    VictorySound();
    SauvegarderGame(partie, joueur, pioche, plateau);
    printf("\t\tAppuyez sur entrer pour revenir au menu principale..");
    fflush(stdin);
    while (getchar() != '\n');
    GameMenu(partie, joueur, pioche, plateau);
}

int CalculJoueurActuel(int nombredejoueurs, int touractuel)
{
    int joueur = 1;

    joueur = touractuel%nombredejoueurs;

    return joueur;
}


void CalculScorePlayer(struct game *partie, struct players joueur[4], struct lettres *pioche, struct cases plateau[15][15], int numerodujoueuractuel,struct motprovisoire motprovisoire)
{

    int ancienscore = joueur[numerodujoueuractuel-1].score;
    int prescore = 0;

    int i=0;
    int ligne=0, colonne=0;
    int bonus = 0;

    int nombrebonusmot = 1;

    if ( toupper(motprovisoire.sens) == 72 ) // HORIZONTALE
    {
        i=0;
        ligne = motprovisoire.nligne - 1;
        colonne = toupper(motprovisoire.ncolonne)-64 - 1;
        while(motprovisoire.motaplacer[i]!='\0')
        {
            if (plateau[ligne][colonne].typebonus == 'M')
            {
                bonus = valueToBonus(pioche, motprovisoire.motaplacer[i]);
                prescore += bonus;
                if (nombrebonusmot!=1)
                {
                    nombrebonusmot *= plateau[ligne][colonne].bonus;
                }
                else
                {
                    nombrebonusmot = plateau[ligne][colonne].bonus;
                }
            }
            else
            {
                bonus = valueToBonus(pioche, motprovisoire.motaplacer[i]);
                prescore += plateau[ligne][colonne].bonus * bonus;

            }

            colonne++;
            i++;
        }


        prescore *= nombrebonusmot;

    }



    if ( toupper(motprovisoire.sens) == 86 ) // VERTICALE
    {
        i=0;
        ligne = motprovisoire.nligne - 1;
        colonne = toupper(motprovisoire.ncolonne)-64 - 1;
        while(motprovisoire.motaplacer[i]!='\0')
        {
            if (plateau[ligne][colonne].typebonus == 'M')
            {
                bonus = valueToBonus(pioche, motprovisoire.motaplacer[i]);
                prescore += bonus;

                if (nombrebonusmot!=1)
                {
                    nombrebonusmot *= plateau[ligne][colonne].bonus;
                }
                else
                {
                    nombrebonusmot = plateau[ligne][colonne].bonus;
                }
            }
            else
            {
                bonus = valueToBonus(pioche, motprovisoire.motaplacer[i]);
                prescore += plateau[ligne][colonne].bonus * bonus;

            }

            ligne++;
            i++;
        }
        prescore *= nombrebonusmot;

    }


    joueur[numerodujoueuractuel-1].score = ancienscore + prescore;

}

int valueToBonus(struct lettres *pioche, char lettredubonus[1])
{
    int i=0;

    for(i=0;i<27;i++)
    {
        if (pioche[i].nom==lettredubonus)
        {
            return (pioche[i].valeur);
        }
    }
    return 0;

}


void VictorySound()
{

    Beep(130, 100 );
    Beep(262, 100 );
    Beep(330, 100 );
    Beep(392, 100 );
    Beep(523, 100 );
    Beep(660, 100 );
    Beep(784, 300 );
    Beep(660, 300 );
    Beep(146, 100 );
    Beep(262, 100 );
    Beep(311, 100 );
    Beep(415, 100 );
    Beep(523, 100 );
    Beep(622, 100 );
    Beep(831, 300 );
    Beep(622, 300 );
    Beep(155, 100 );
    Beep(294, 100 );
    Beep(349, 100 );
    Beep(466, 100 );
    Beep(588, 100 );
    Beep(699, 100 );
    Beep(933, 300 );
    Beep(933, 100 );
    Beep(933, 100 );
    Beep(933, 100 );
    Beep(1047, 400);


}
