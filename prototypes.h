#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h> // Utilisation de la fonction toupper
#include <windows.h>

/// https://www.programming-techniques.com/2011/09/how-to-resize-console-window-using-c.html
// Changer la taille de la console.
HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.



/*

Prototype des sous-programmes

*/

/// main.c
void GameMenu();



/// pioche.c

void InitialisationPioche();
void AffichagePioche();
void InitialisationChevalet();
void AjustementChevalet();
void RandomLetterFromPioche();
void AjustementPioche();
void AjustementChevaletBis();


/// plateau.c


void InitialisationPlateau();
void AffichagePlateau();
void AffichagePlayerAndScore();
void AffichageChevalet();
void RecupMotaPlacer();
int VerifMotaPlacer();
void AffichageRecupVerifMAP();
void AffichageMotaPlacer();
void AffichageConfirmationMot();

void MinusToUpper();
void DeleteChevaletLetter();
void DeleteChevaletLetterBis();

void MiseEnPlaceLettres();
void EnleverLettres();

void Color();

void AffichageRecupVerifMAPIA();
int VerifMotaPlacerIA();


/// partie.c

void EndGame();
void CurrentGame();
void InitialisationNomdesjoueurs();
void InitialisationPartie();

void CalculScorePlayer();
int CalculJoueurActuel();
int valueToBonus();

void InitialisationNomdesjoueursavecIA();

void VictorySound();

/// fichiers.c

void SauvegarderGame();
void ChargerGame();
void ChargerPlateau();

/// verifmot.c

void VerifMotaPlacerAvecChevalet();
void VerifPositionMotPremierTour();
void VerifMotBienSurLePlateau();
void VerifAuMoinsUneLettreCommune();
void VerifPasDeuxVoyellesCoteACote();

void VerifMotaPlacerAvecChevaletIA();
void VerifPositionMotPremierTourIA();
void VerifMotBienSurLePlateauIA();
void VerifAuMoinsUneLettreCommuneIA();
void VerifPasDeuxVoyellesCoteACoteIA();



/// Structures

// Plateau

struct lettres
{
    char nom;
    int occurence;
    int valeur;
};


struct cases
{
    char nom[3];
    int bonus;
    int libre;
    char valeur;
    char typebonus;
    int casesuperpose;
    int occupeparjoueur[4];
    int couleur;
};

struct motprovisoire
{
    char motaplacer[20];
    int nligne;
    char ncolonne;
    char sens;

};

// Jeu et joueurs

struct players
{
    char nomdujoueur[50];
    int score;
    char chevalet[8];
    int color;
    int isIA;
};

struct game
{
    int encours;
    int nombrejoueurs;
    int touractuel;
    int pioche;
};
