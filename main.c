#include "prototypes.h"

void GameMenu(struct game *partie, struct players joueur[4], struct lettres *pioche, struct cases plateau[15][15])
{
    int choixjoueur = 0;
    int nouvellepartie = 0;
    int answer = 0;
    int i = 0;
    char sautdeligneperfect[50] = "";


    /* DEBUT DE RESIZE
    SOURCE :
    https://www.programming-techniques.com/2011/09/how-to-resize-console-window-using-c.html
    De la ligne 18 à ligne 30 : Le code vient directement de ce site.
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




    ///Lecture des fichiers du jeu s'ils existent( struct player et game )


    ChargerGame(partie, joueur);


    ///Affichage du menu
    do
    {

    do
    {

    // PIXEL ART (parce que c bo, j'lé fé moi même en plus !)
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
    printf("\t\t\t\t\t /          Menu du Jeu          /\n");
    printf("\t\t\t\t\t /////////////////////////////////\n");

    printf("\n\n");


    printf("\t\t\tQue souhaitez-vous faire ?");
    printf("\n\n");
    printf("\t\t\t\t1 - Lancer une nouvelle partie");
    printf("\n\n");
    printf("\t\t\t\t2 - Reprendre la partie");
    printf("\n\n");
    printf("\t\t\t\t3 - Afficher l'aide");
    printf("\n\n");
    printf("\t\t\t\t4 - Afficher le score de la partie sauvegardee");
    printf("\n\n");
    printf("\t\t\t\t5 - Quitter le jeu");


    printf("\n\n\n");
    printf("\tVotre choix : ");
    fflush(stdin);
    choixjoueur = getchar();
    }while(choixjoueur>53 || choixjoueur<49);


    switch(choixjoueur)
    {
        case 49:
            {
                system("cls");
                printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
                printf("/         ######       #####       ######              #####        ####       #####        ####        #####         /\n");
                printf("/         #           ##   ##      #                   ##  ##      ##  ##      ##  ##        ##        ##             /\n");
                printf("/         #####       ##           ######              #####       ######      ######        ##         ####          /\n");
                printf("/         #           ##   ##      #                   ##          ##  ##      #####         ##            ##         /\n");
                printf("/         ######       #####       ######              ##          #    #      ##  ##       ####       #####          /\n");
                printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");


                if (partie->encours==1)
                {

                    printf("\n\n");
                    printf("\t\t\t\t\t /////////////////////////////////\n");
                    printf("\t\t\t\t\t /            ATTENTION          /\n");
                    printf("\t\t\t\t\t /////////////////////////////////\n");
                    printf("\n\n");

                    printf("\tUne partie est deja en cours !\n\n");
                    printf("\tEn creer une nouvelle supprimera l'ancienne !!");
                    do
                    {
                        printf("\n\n\t\tEtes-vous sur de vouloir continuer ? (1 pour Oui - 0 pour Non)\n");
                        printf("\n\n\n");
                        printf("\tVotre choix : ");
                        fflush(stdin);
                        answer = getchar();
                    }while(answer>49 || answer<48);


                    if (answer==48)
                        break;
                    if (answer==49)
                    {
                        ///Parametres
                        nouvellepartie = 1;
                        partie->encours=1;
                        ///Lancement du jeu
                        InitialisationPartie(partie, joueur, pioche, plateau, nouvellepartie);

                    }

                }
                else
                {
                    printf("\n\n");
                    printf("\t\t\t\t\t /////////////////////////////////\n");
                    printf("\t\t\t\t\t /         Nouvelle Partie       /\n");
                    printf("\t\t\t\t\t /////////////////////////////////\n");
                    printf("\n\n");

                    ///Parametres
                    nouvellepartie = 1;
                    ///Lancement du jeu
                    InitialisationPartie(partie, joueur, pioche, plateau, nouvellepartie);

                }

            }
        break;

        case 50:
            {

                system("cls");
                printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
                printf("/         ######       #####       ######              #####        ####       #####        ####        #####         /\n");
                printf("/         #           ##   ##      #                   ##  ##      ##  ##      ##  ##        ##        ##             /\n");
                printf("/         #####       ##           ######              #####       ######      ######        ##         ####          /\n");
                printf("/         #           ##   ##      #                   ##          ##  ##      #####         ##            ##         /\n");
                printf("/         ######       #####       ######              ##          #    #      ##  ##       ####       #####          /\n");
                printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

                if (partie->encours==1)
                {

                    ///Parametres
                    nouvellepartie = 0;
                    ///Lancement du jeu
                    InitialisationPartie(partie, joueur, pioche, plateau, nouvellepartie);
                }
                else
                {

                    printf("\n\n");
                    printf("\t\t\t\t\t /////////////////////////////////\n");
                    printf("\t\t\t\t\t /            ATTENTION          /\n");
                    printf("\t\t\t\t\t /////////////////////////////////\n");
                    printf("\n\n");

                    printf("\tIl n'y a pas de partie en cours !!");
                    sleep(1);
                    printf("\n\n");
                    printf("\t\tRetour au menu principale");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    break;
                }

            }
        break;

        case 51:
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
                printf("\t\t\t\t\t /////////////////////////////////\n");
                printf("\t\t\t\t\t /              Aide             /\n");
                printf("\t\t\t\t\t /////////////////////////////////\n");
                printf("\n\n");

                system("start https://www.ffsc.fr/files/public/fichiers/reglements/classique/Reglement.international.du.Scrabble.classique.pdf");

                printf("\t\t\t Vous avez ete redirige vers le lien officiel des regles du Scrabble.");
                printf("\n\n");
                printf("\t   Le Scrabble est un jeu de societe et un jeu de lettres ou l'objectif est de cumuler des points,\n\t     sur la base de tirages aleatoires de lettres, en creant des mots sur une grille carree,\n\t\t\t\t        dont certaines cases sont primees.");
                printf("\n\n\n\tLegendes :\n");
                printf("\n");
                printf("\t\t# : point de depart\n");
                printf("\t\t& : lettre double\n");
                printf("\t\t%c : lettre triple\n",'%');
                printf("\t\t@ : mot double\n");
                printf("\t\t§ : mot triple\n");

                printf("\t\t\t\t\t\t\t\tAppuyez sur entrer pour revenir au menu principale..");
                fflush(stdin);
                while (getchar() != '\n');

            }
        break;

        case 52:
            {
                system("cls");
                printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
                printf("/         ######       #####       ######              #####        ####       #####        ####        #####         /\n");
                printf("/         #           ##   ##      #                   ##  ##      ##  ##      ##  ##        ##        ##             /\n");
                printf("/         #####       ##           ######              #####       ######      ######        ##         ####          /\n");
                printf("/         #           ##   ##      #                   ##          ##  ##      #####         ##            ##         /\n");
                printf("/         ######       #####       ######              ##          #    #      ##  ##       ####       #####          /\n");
                printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");

                if (partie->encours==1)
                {
                    printf("\n\n");
                    printf("\t\t\t\t\t /////////////////////////////////\n");
                    printf("\t\t\t\t\t /             SCORES            /\n");
                    printf("\t\t\t\t\t /////////////////////////////////\n");
                    printf("\n\n");

                    printf("\tLes scores sont :\n\n");

                    for(i=0;i<partie->nombrejoueurs;i++)
                    {
                        printf("\n");
                        printf("\t\t%s : %d points\n",joueur[i].nomdujoueur, joueur[i].score);
                    }
                    if (partie->nombrejoueurs==1)
                        strcpy(sautdeligneperfect,"\n\n\n\n\n\n\n\n\n\n");
                    if (partie->nombrejoueurs==2)
                        strcpy(sautdeligneperfect,"\n\n\n\n\n\n\n\n");
                    if (partie->nombrejoueurs==3)
                        strcpy(sautdeligneperfect,"\n\n\n\n\n\n");
                    if (partie->nombrejoueurs==4)
                        strcpy(sautdeligneperfect,"\n\n\n\n");

                    printf("%s",sautdeligneperfect);
                    printf("\t\t\t\t\t\t\t\tAppuyez sur entrer pour revenir au menu principale..");
                    fflush(stdin);
                    while (getchar() != '\n');

                }
                else
                {

                    printf("\n\n");
                    printf("\t\t\t\t\t /////////////////////////////////\n");
                    printf("\t\t\t\t\t /            ATTENTION          /\n");
                    printf("\t\t\t\t\t /////////////////////////////////\n");
                    printf("\n\n");

                    printf("\tIl n'y a pas de partie sauvegardee!!");
                    sleep(1);
                    printf("\n\n");
                    printf("\t\tRetour au menu principale");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    break;
                }

            }
        break;


        default:
            break;
    }


    }while(choixjoueur!=53);
    system("cls");

}



int main()
{

    ///Struct Initialize
    srand(time(NULL));
    struct lettres pioche[27] = {};
    struct cases plateau[15][15] = {};
    struct game partie = {};
    struct players joueur[4] = {};

    SetConsoleTitle("Scrabble - ECE Paris - 2020");

    ///Lancement du jeu
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t    ECE Scrabble 2020 - TDS04B\n");
    printf("\t\t\t\t        created by Alexis, Edouard, Morgan\n");

    sleep(2);

    GameMenu(&partie, joueur, pioche, plateau);




    return 0;
}
