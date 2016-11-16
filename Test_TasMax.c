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


}
