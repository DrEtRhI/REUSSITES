#include <stdlib.h>

#include "Tas.h"
#include <stdio.h>

void AfficheTaspourtest(Tas T);
void Creertasdunecarte(Localisation L, Mode M, Tas *T);
void CreerCartepourtest(struct adCarte *C);

	
void Test_CouleurSuivante(){
 printf("**********************Test de CouleurSuivante*************************\n");
 printf("La couleur suivante de %d est %d\n", 1, CouleurSuivante(Trefle));	
 printf("La couleur suivante de %d est %d\n", 2, CouleurSuivante(Carreau));	
 printf("La couleur suivante de %d est %d\n", 3, CouleurSuivante(Coeur));	
 printf("La couleur suivante de %d est %d\n", 4, CouleurSuivante(Pique));	
 printf("\n\n");
}

void Test_TasActif(){
 printf("************************Test de TasActif******************************\n");
 Tas T;
 T.RT = actif;
 printf("Le tas est mis actif. TasActif vaut %d\n", TasActif(T));
 T.RT = inactif;
 printf("Le tas est mis inactif. TasActif vaut %d\n", TasActif(T));
 printf("\n\n");
}

void Test_TasEmpile(){
 printf("************************Test de TasEmpile*****************************\n");
 Tas T;
 T.MT = empile;
 printf("Le tas est mis empile. TasEmpile vaut %d\n", TasEmpile(T));
 T.MT = etale;
 printf("Le tas est mis etale. TasEmpile vaut %d\n", TasEmpile(T));
 printf("\n\n");
}

void Test_LaHauteur(){
 printf("************************Test de LaHauteur*****************************\n");
 Tas T;
 T.HT = 5;
 printf("La hauteur est 5. LaHauteur vaut %d\n", LaHauteur(T));
 printf("\n\n");
}


void Test_CreerTasVide(){
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
 printf("\n\n");
}

void Test_EchangerCarte(){
 printf("************************Test de EchangerCarte************************\n");
 Tas T;
 Localisation L;

 L.NL = 1;
 L.NC = 3;
 CreerJeuNeuf(32, L, &T);
 AfficheTaspourtest(T);
 EchangerCartes(5,15,&T);
 AfficheTaspourtest(T);
 printf("\n\n");
}

void Test_BattreTas(){
printf("************************Test de BattreTas************************\n");
 Tas T;
 Localisation L;
 L.NL = 1;
 L.NC = 3;

 CreerJeuNeuf(52, L, &T);
 AfficheTaspourtest(T);
 BattreTas(&T);
 AfficheTaspourtest(T);
 printf("\n\n");
}


void Test_RetournerTas(){
 printf("************************Test de RetournerTas************************\n");
 Tas T;
 Localisation L;
 L.NL = 1;
 L.NC = 3;

 CreerJeuNeuf(32, L, &T);
 AfficheTaspourtest(T);
 RetournerTas(&T);
 AfficheTaspourtest(T);
 RetournerTas(&T);
 AfficheTaspourtest(T);
}

void TestAjouterCarteSurTas(){
 printf("************************Test de AjouterCarteSurTas************************\n");

 printf("Cas 1: Ajout de carte sur tas non vide \n");
 Tas T1;
 Localisation L1;
 struct adCarte carte1;
 L1.NL = 1;
 L1.NC = 3;

 CreerCartepourtest(&carte1);
 CreerJeuNeuf(32, L1, &T1);
 AjouterCarteSurTas(&carte1,&T1);
 AfficheTaspourtest(T1);
 printf("Sa hauteur est %d \n",T1.HT);
 
 printf("Cas 2: Ajout de carte sur tas vide\n");
 Tas T2;
 Localisation L2;
 struct adCarte carte2;
 L2.NL = 1;
 L2.NC = 3;
 
 CreerCartepourtest(&carte2);
 CreerTasVide(L2, empile, &T2);
 printf("avant operation:\n");
 AfficheTaspourtest(T2);
 AjouterCarteSurTas(&carte2,&T2);
 printf("apres operation:\n");
 AfficheTaspourtest(T2);
 printf("Sa hauteur est %d \n",T2.HT);
}

void TestAjouterCarteSousTas(){
 printf("************************Test de AjouterCarteSousTas************************\n");

 printf("Cas 1: Ajout de carte sur tas non vide \n");
 Tas T1;
 Localisation L1;
 struct adCarte carte1;
 L1.NL = 1;
 L1.NC = 3;

 CreerCartepourtest(&carte1);
 CreerJeuNeuf(32, L1, &T1);
 AjouterCarteSousTas(&carte1,&T1);
 AfficheTaspourtest(T1);
 printf("Sa hauteur est %d \n",T1.HT);
 
 printf("Cas 2: Ajout de carte sur tas vide\n");
 Tas T2;
 Localisation L2;
 struct adCarte carte2;
 L2.NL = 1;
 L2.NC = 3;
 
 CreerCartepourtest(&carte2);
 CreerTasVide(L2, empile, &T2);
 printf("avant operation:\n");
 AfficheTaspourtest(T2);
 AjouterCarteSousTas(&carte2,&T2);
 printf("apres operation:\n");
 AfficheTaspourtest(T2);
 printf("Sa hauteur est %d \n",T2.HT);
}



void Test_DeplacerHautSous(){
 printf("************************Test de deplacerHautSous************************\n");
 Localisation L1, L2, L3, L4;
 Tas T1, T2, T3, T4; 
 L1.NC=1;
 L1.NL=1;
 L2.NC=2;
 L2.NL=2;


 printf("Cas 1: Tas source (plusieurs cartes), Tas dest (vide)\n");
 CreerJeuNeuf(32, L1, &T1);
 CreerTasVide(L2, empile, &T2);
 
 printf("Tas source avant operation. Sa hauteur est %d\n\n", T1.HT);
 AfficheTaspourtest(T1);
 printf("Tas destination avant operation. Sa hauteur est %d\n\n", T2.HT);
 AfficheTaspourtest(T2);

 DeplacerHautSous(&T1,&T2);

 printf("Tas source apres operation. Sa hauteur est %d\n\n", T1.HT);
 AfficheTaspourtest(T1);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T2.HT);
 AfficheTaspourtest(T2);
 printf("\n\n");
 
 
 
 
 printf("Cas 2: Tas source (1 seule carte), Tas dest (vide)\n");
 struct adCarte carte1;
 L3.NC=3;
 L3.NL=3;
 L4.NC=4;
 L4.NL=4;
 
 /*T3: tas source d'une carte*/
 CreerTasVide(L3, empile, &T3); 
 CreerCartepourtest(&carte1);
 AjouterCarteSurTas(&carte1,&T3);
 
 /*T4: tas destination */
 CreerTasVide(L4, empile, &T4); 
 
 printf("Tas source avant operation. Sa hauteur est %d\n\n", T3.HT);
 AfficheTaspourtest(T3);
 printf("Tas destination avant operation. Sa hauteur est %d\n\n", T4.HT);
 AfficheTaspourtest(T4);

 DeplacerHautSous(&T3,&T4);

 printf("Tas source apres operation. Sa hauteur est %d\n\n", T3.HT);
 AfficheTaspourtest(T3);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T4.HT);
 AfficheTaspourtest(T4);
 printf("\n\n");
 
 
 
}










int main () {
 Test_CouleurSuivante();
 Test_TasActif();
 Test_TasEmpile();
 Test_LaHauteur();
 Test_CreerTasVide();
 Test_EchangerCarte();
 Test_BattreTas();
 Test_RetournerTas();
 TestAjouterCarteSurTas();
 TestAjouterCarteSousTas();
 Test_DeplacerHautSous();












/* tests fonction DeplacerHautSous */
printf("************************Test de deplacerHautSur************************\n");
printf("*******d'un jeu neuf vers un tas vide\n******");
Localisation MCT_L4, MCT_L5;
Tas MCT_T4, MCT_T5;
MCT_L4.NC=1;
MCT_L4.NL=1;
MCT_L5.NC=2;
MCT_L5.NL=2;


CreerJeuNeuf(32, MCT_L4, &MCT_T4);
/*Ajout d'une carte dans le tas vide*/
CreerTasVide(MCT_L5, empile, &MCT_T5);
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


printf("Tas source avant operation. Sa hauteur est %d\n\n", MCT_T4.HT);
AfficheTaspourtest(MCT_T4);
printf("Tas destination avant operation. Sa hauteur est %d\n\n", MCT_T5.HT);
AfficheTaspourtest(MCT_T5);

DeplacerHautSur(&MCT_T4,&MCT_T5);

printf("Tas source apres operation. Sa hauteur est %d\n\n", MCT_T4.HT);
AfficheTaspourtest(MCT_T4);
printf("Tas destination apres operation. Sa hauteur est %d \n\n", MCT_T5.HT);
AfficheTaspourtest(MCT_T5);

printf("d'une tas de une carte vers tas vide\n");
/*creation tas source de 1 carte et tas destination vide*/
Tas MCT_T12, MCT_T13;
Localisation MCT_L12, MCT_L13;
CreerTasVide(MCT_L12, empile, &MCT_T12);
CreerTasVide(MCT_L13, empile, &MCT_T13);
struct adCarte *MCT_C12;
MCT_C12 = (struct adCarte *) malloc (sizeof(struct adCarte));
MCT_C12->elt.CC = 1;
MCT_C12->elt.VC = 1;
MCT_C12->elt.RC = 1;
MCT_C12->prec = NULL;
MCT_C12->suiv = NULL;

MCT_T12.tete = MCT_C12;
MCT_T12.queue = MCT_C12;
MCT_T12.HT=1;

printf("Tas source avant operation. Sa hauteur est %d\n\n", MCT_T12.HT);
AfficheTaspourtest(MCT_T12);
printf("Tas destination avant operation. Sa hauteur est %d\n\n", MCT_T13.HT);
AfficheTaspourtest(MCT_T13);

DeplacerHautSur(&MCT_T12,&MCT_T13);

printf("Tas source apres operation. Sa hauteur est %d\n\n", MCT_T12.HT);
AfficheTaspourtest(MCT_T12);
printf("Tas destination apres operation. Sa hauteur est %d \n\n", MCT_T13.HT);
AfficheTaspourtest(MCT_T13);



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

/* fonctions creer pour faciliter les tests, utiliser ici seulement*/
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
void CreerCartepourtest(struct adCarte *C){ 
 C->elt.CC = 3;
 C->elt.VC = Decouverte;
 C->elt.RC = 5;
 C->suiv =NULL;
 C->prec =NULL;
}

