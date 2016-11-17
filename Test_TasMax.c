#include <stdlib.h>

#include "Tas.h"
#include <stdio.h>

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

/* tests fonction DeplacerHautSur */
printf("************************Test de deplacerHautSur************************\n");
Localisation MCT_L2, MCT_L3;
Tas MCT_T2, MCT_T3;
L.NC=1;
L.NL=1;

CreerJeuNeuf(32, MCT_L2, MCT_T2);
CreerTasVide(MCT_L3, empile,MCT_T3);
/*Affichage tas */
printf("Tas source avant operation. Sa hauteur est %d\n", MCT_T2.HT);
AfficheTaspourtest(MCT_T2);
printf("Tas destination avant operation (vide). Sa hauteur est %d\n", MCT_T3.HT);
AfficheTaspourtest(MCT_T3);

DeplacerHautSur(Tas &MCT_T2, Tas &MCT_T3);

/*Affichage tas */

printf("Tas source apres operation. Sa hauteur est %d", MCT_T2.HT);
AfficheTaspourtest(MCT_T2);
printf("Tas destination apres operation. Sa hauteur est %d \n", MCT_T3.HT);
AfficheTaspourtest(MCT_T3);

printf("**********************************************************************\n\n");
}

void AfficheTaspourtest(Tas *T){
  struct adCarte *AC;
  AC = T->queue;
  
  printf("Affichage du tas (premiere ligne = haut du tas; derniere ligne = bas du tas\n");
  if (AC = NULL) 
    {printf("Ce tas est vide\n");}
  
  while (AC != NULL){
	printf("|couleur: %d | rang: %d | Visibilite: %d |\n", AC->elt.CC, AC->elt.RC, AC->elt.VC );
	AC = AC->prec;
  }
}
