#include <stdlib.h>

#include "Tas.h"
#include <stdio.h>

void AfficheTaspourtest(Tas T);
void Creertasdunecarte( Localisation L, Mode M, Tas *T);

int main () {

/*Tests fonctions CouleurSuivante */
printf("**********************Test de CouleurSuivante*************************\n");
printf("La couleur suivante de %d est %d\n", 1, CouleurSuivante(Trefle));	
printf("La couleur suivante de %d est %d\n", 2, CouleurSuivante(Carreau));	
printf("La couleur suivante de %d est %d\n", 3, CouleurSuivante(Coeur));	
printf("La couleur suivante de %d est %d\n", 4, CouleurSuivante(Pique));	
printf("**********************************************************************\n\n");

/* Tests fonction TasActif */

printf("************************Test de TasActif******************************\n");
Tas MCT_t1;
MCT_t1.RT = actif;
printf("Le tas est mis actif. TasActif vaut %d\n", TasActif(MCT_t1));

MCT_t1.RT = inactif;
printf("Le tas est mis inactif. TasActif vaut %d\n", TasActif(MCT_t1));
printf("**********************************************************************\n\n");


/* Tests fonction TasEmpile */
printf("************************Test de TasEmpile*****************************\n");
MCT_t1.MT = empile;
printf("Le tas est mis empile. TasEmpile vaut %d\n", TasEmpile(MCT_t1));

MCT_t1.MT = etale;
printf("Le tas est mis etale. TasEmpile vaut %d\n", TasEmpile(MCT_t1));
printf("**********************************************************************\n\n");

/* Tests fonction LaHauteur */
printf("************************Test de LaHauteur*****************************\n");
MCT_t1.HT = 5;
printf("La hauteur est 5. LaHauteur vaut %d\n", LaHauteur(MCT_t1));
printf("**********************************************************************\n\n");

/* Tests fonction CreeTasVide */
printf("************************Test de CreeTasVide***************************\n");
Tas T;
Mode M;
Localisation L;

L.NL=1;
L.NC=1;
M=empile;
CreerTasVide(L,M,&T);
printf("%p",T.tete);
printf("%p",T.queue);
printf("Le tas vide est cree (hauteur=0). LaHauteur vaut %d\n", LaHauteur(T));
printf("**********************************************************************\n\n");


printf("**********************************************************************\n\n");







printf("************************Test de EchangerCarte************************\n");

Tas MCT_T6;

Localisation MCT_Loc6;
MCT_Loc6.NL = 1;
MCT_Loc6.NC = 3;

CreerJeuNeuf(32, MCT_Loc6, &MCT_T6);
AfficheTaspourtest(MCT_T6);
EchangerCartes(5,15,&MCT_T6);
AfficheTaspourtest(MCT_T6);

printf("************************Test de BattreTas************************\n");

Tas MCT_T7;

Localisation MCT_Loc7;
MCT_Loc7.NL = 1;
MCT_Loc7.NC = 3;

CreerJeuNeuf(52, MCT_Loc7, &MCT_T7);
AfficheTaspourtest(MCT_T7);
BattreTas(&MCT_T7);
AfficheTaspourtest(MCT_T7);

printf("************************Test de RetournerTas************************\n");

Tas MCT_T8;

Localisation MCT_Loc8;
MCT_Loc8.NL = 1;
MCT_Loc8.NC = 3;

CreerJeuNeuf(32, MCT_Loc8, &MCT_T8);
AfficheTaspourtest(MCT_T8);
RetournerTas(&MCT_T8);
AfficheTaspourtest(MCT_T8);
RetournerTas(&MCT_T8);
AfficheTaspourtest(MCT_T8);

printf("************************Test de AjouterCarteSurTas************************\n");
Tas MCT_T9;
Localisation MCT_Loc9;
MCT_Loc9.NL = 1;
MCT_Loc9.NC = 3;
struct adCarte* uneCarte;
uneCarte = (struct adCarte*) malloc (sizeof(struct adCarte));
uneCarte->elt.CC = 3;
uneCarte->elt.VC = Decouverte;
uneCarte->elt.RC = 5;

CreerJeuNeuf(32, MCT_Loc9, &MCT_T9);
AjouterCarteSousTas(uneCarte,&MCT_T9);
AfficheTaspourtest(MCT_T9);

/* tests fonction DeplacerHautSur */
printf("************************Test de deplacerHautSous************************\n");
Localisation MCT_L2, MCT_L3;
Tas MCT_T2, MCT_T3;
L.NC=1;
L.NL=1;

CreerJeuNeuf(32, MCT_L2, &MCT_T2);
/*Ajout d'une carte dans le tas vide*/
CreerTasVide(L, empile, &MCT_T3);
struct adCarte *MCT_pcarte;
MCT_pcarte = (struct adCarte *) malloc (sizeof(struct adCarte));
MCT_pcarte->elt.CC = 1;
MCT_pcarte->elt.VC = 1;
MCT_pcarte->elt.RC = 1;
MCT_pcarte->prec = NULL;
MCT_pcarte->suiv = NULL;

MCT_T3.tete = MCT_pcarte;
MCT_T3.queue = MCT_pcarte;
MCT_T3.HT=1;
/* fin*/


/*Affichage tas */
printf("Tas source avant operation. Sa hauteur est %d\n\n", MCT_T2.HT);
AfficheTaspourtest(MCT_T2);
printf("Tas destination avant operation. Sa hauteur est %d\n\n", MCT_T3.HT);
AfficheTaspourtest(MCT_T3);

DeplacerHautSous(&MCT_T2,&MCT_T3);

/*Affichage tas */

printf("Tas source apres operation. Sa hauteur est %d\n\n", MCT_T2.HT);
AfficheTaspourtest(MCT_T2);
printf("Tas destination apres operation. Sa hauteur est %d \n\n", MCT_T3.HT);
AfficheTaspourtest(MCT_T3);


printf("**********************************************************************\n\n");


/* tests fonction DeplacerHautSous */
printf("************************Test de deplacerHautSur************************\n");
Localisation MCT_L4, MCT_L5;
Tas MCT_T4, MCT_T5;
L.NC=1;
L.NL=1;

CreerJeuNeuf(32, MCT_L4, &MCT_T4);
/*Ajout d'une carte dans le tas vide*/
CreerTasVide(L, empile, &MCT_T5);
struct adCarte *MCT_pcarte2;
MCT_pcarte2 = (struct adCarte *) malloc (sizeof(struct adCarte));
MCT_pcarte2->elt.CC = 1;
MCT_pcarte2->elt.VC = 1;
MCT_pcarte2->elt.RC = 1;
MCT_pcarte2->prec = NULL;
MCT_pcarte2->suiv = NULL;

MCT_T5.tete = MCT_pcarte2;
MCT_T5.queue = MCT_pcarte2;
MCT_T5.HT=1;
/* fin*/

/*Affichage tas */
printf("Tas source avant operation. Sa hauteur est %d\n\n", MCT_T4.HT);
AfficheTaspourtest(MCT_T4);
printf("Tas destination avant operation. Sa hauteur est %d\n\n", MCT_T5.HT);
AfficheTaspourtest(MCT_T5);

/*DeplacerHautSur(&MCT_T4,&MCT_T5);*/

DeplacerCarteSur(Coeur, 10,&MCT_T4,&MCT_T5);

/*Affichage tas */

printf("Tas source apres operation. Sa hauteur est %d\n\n", MCT_T4.HT);
AfficheTaspourtest(MCT_T4);
printf("Tas destination apres operation. Sa hauteur est %d \n\n", MCT_T5.HT);
AfficheTaspourtest(MCT_T5);

printf("************************Test de DeplacerTasSurTas************************\n");

Tas MCT_T10, MCT_T11;
MCT_L4.NC=1;
MCT_L4.NL=1;

CreerJeuNeuf(32, MCT_L4, &MCT_T10);
CreerJeuNeuf(32, MCT_L4, &MCT_T11);
BattreTas(&MCT_T10);
printf("Tas source apres operation. Sa hauteur est %d\n\n", MCT_T10.HT);
AfficheTaspourtest(MCT_T10);
printf("Tas destination apres operation. Sa hauteur est %d \n\n", MCT_T11.HT);
AfficheTaspourtest(MCT_T11);
PoserTasSurTas(&MCT_T10, &MCT_T11);
printf("Tas source apres operation. Sa hauteur est %d\n\n", MCT_T10.HT);
AfficheTaspourtest(MCT_T10);
printf("Tas destination apres operation. Sa hauteur est %d \n\n", MCT_T11.HT);
AfficheTaspourtest(MCT_T11);

printf("**********************************************************************\n\n");
}


void AfficheTaspourtest(Tas T){
  struct adCarte *AC;
  AC = T.queue;
  
  printf("1ere ligne = haut du tas; derniere ligne = bas du tas\n");
  if (AC == NULL) 
    {printf("Ce tas est vide\n");}
  
  while (AC != NULL){
	printf("|couleur: %d | rang: %d | Visibilite: %d |\n", AC->elt.CC, AC->elt.RC, AC->elt.VC );
	AC = AC->prec;
	}
	AC = T.tete;
	while (AC != NULL){
	AC = AC->suiv;
  }

}



