#include <stdlib.h>

#include "Tas.h"
#include <stdio.h>

void AfficheTaspourtest(Tas T);
void CreerCartepourtest(struct adCarte *C);
void CreerCartepourtest2(struct adCarte *C);

	
void Test_CouleurSuivante(){
 printf("**********************Test de CouleurSuivante*************************\n");
 printf("La couleur suivante de %d est %d\n", 1, CouleurSuivante(Trefle));	
 printf("La couleur suivante de %d est %d\n", 2, CouleurSuivante(Carreau));	
 printf("La couleur suivante de %d est %d\n", 3, CouleurSuivante(Coeur));	
 printf("La couleur suivante de %d est %d\n", 4, CouleurSuivante(Pique));	
 printf("\n\n");
}

void Test_RangSuivant(){
 printf("**********************Test de RangSuivant*************************\n");
 printf("Le rang suivant %d est %d\n", 2, RangSuivant(Deux));
 printf("Le rang suivant %d est %d\n", 11, RangSuivant(Valet));
 printf("Le rang suivant %d est %d\n", 13, RangSuivant(Dame));
 printf("Le rang suivant %d est %d\n", 14, RangSuivant(As));
 printf("\n\n");
}

void Test_LeRang(){
 printf("**********************Test de LeRang*************************\n");
 struct adCarte carte1;
 CreerCartepourtest(&carte1); 
 printf("Le rang de carte1: %d est %d\n",(&carte1)->elt.RC, LeRang((&carte1)->elt));
 printf("\n\n");
}

void Test_LaCouleur(){
 printf("**********************Test de LaCouleur*************************\n");
 struct adCarte carte1;
 CreerCartepourtest(&carte1); 
 printf("La couleur de carte1: %d est %d\n",(&carte1)->elt.CC, LaCouleur((&carte1)->elt));
 printf("\n\n");
}

void Test_EstCachee(){
 printf("**********************Test de EstCachee*************************\n");
 struct adCarte carte1;
 CreerCartepourtest(&carte1); 
 printf("La carte1 est cachee: %d resultat: %d\n",!(&carte1)->elt.VC, EstCachee((&carte1)->elt));
 printf("\n\n");
}

void Test_EstDecouverte(){
 printf("**********************Test de EstCachee*************************\n");
 struct adCarte carte1;
 CreerCartepourtest(&carte1); 
 printf("La carte1 est decouverte %d resultat %d\n",(&carte1)->elt.VC, EstDecouverte((&carte1)->elt));
 printf("\n\n");
}

void Test_RangInferieur(){
 printf("**********************Test de RangInferieur*************************\n");
 struct adCarte carte1;
 struct adCarte carte2;
 CreerCartepourtest(&carte1);
 CreerCartepourtest2(&carte2); 
 printf("rang de la carte1 :%d rang de la carte 2:%d resultat : %d\n",(&carte1)->elt.RC, (&carte2)->elt.RC,RangInferieur((&carte1)->elt,(&carte2)->elt));
 printf("\n\n");
}

void Test_MemeRang(){
 printf("**********************Test de MemeRang*************************\n");
 struct adCarte carte1;
 struct adCarte carte2;
 CreerCartepourtest(&carte1);
 CreerCartepourtest2(&carte2); 
 printf("rang de la carte1 :%d rang de la carte 2:%d resultat : %d\n",(&carte1)->elt.RC, (&carte2)->elt.RC,MemeRang((&carte1)->elt,(&carte2)->elt));
 printf("\n\n");
}

void Test_CouleurInferieure(){
 printf("**********************Test de CouleurInferieure*************************\n");
 struct adCarte carte1;
 struct adCarte carte2;
 CreerCartepourtest(&carte1);
 CreerCartepourtest2(&carte2); 
 printf("couleur de la carte1 :%d couleur de la carte 2:%d resultat : %d\n",(&carte1)->elt.CC, (&carte2)->elt.CC,CouleurInferieure((&carte1)->elt,(&carte2)->elt));
 printf("\n\n");
}

void Test_MemeCouleur(){
 printf("**********************Test de MemeCouleur*************************\n");
 struct adCarte carte1;
 struct adCarte carte2;
 CreerCartepourtest(&carte1);
 CreerCartepourtest2(&carte2); 
 printf("couleur de la carte1 :%d couleur de la carte 2:%d resultat : %d\n",(&carte1)->elt.CC, (&carte2)->elt.CC,MemeCouleur((&carte1)->elt,(&carte2)->elt));
 printf("\n\n");
}

void Test_EstCarteAvant(){
 printf("**********************Test de EstCarteAvant*************************\n");
 struct adCarte carte1;
 struct adCarte carte2;
 CreerCartepourtest(&carte1);
 CreerCartepourtest2(&carte2); 
 printf("rang,couleur de la carte1 :%d %d rang,couleur de la carte 2:%d %d resultat : %d\n",(&carte1)->elt.RC, (&carte1)->elt.CC, (&carte2)->elt.RC, (&carte2)->elt.CC, EstCarteAvant((&carte1)->elt,(&carte2)->elt));
 printf("\n\n");
}

void Test_TasActif(){
 printf("************************Test de TasActif******************************\n");
 Tas T;
 T.RT = actif;
 printf("Le tas est mis actif. TasActif retourne %d (valeur attendue: 1)\n", TasActif(T));
 T.RT = inactif;
 printf("Le tas est mis inactif. TasActif retourne %d (valeur attendue: 0)\n", TasActif(T));
 printf("\n\n");
}

void Test_TasEmpile(){
 printf("************************Test de TasEmpile*****************************\n");
 Tas T;
 T.MT = empile;
 printf("Le tas est mis empile. TasEmpile retourne: %d (valeure attendue: 1)\n", TasEmpile(T));
 T.MT = etale;
 printf("Le tas est mis etale. TasEmpile retourne: %d (valeure attendue: 0)\n", TasEmpile(T));
 printf("\n\n");
}

void Test_TasEtale(){
 printf("*************************Test de TasEtale******************************\n");
 Tas T;
 T.MT = empile;
 printf("Le Tas est mis empile. TasEtale retourne (doit etre 0): %d\n", TasEtale(T));
 T.MT = etale;
 printf("La Tas est mis etale. TasEtale retourne (doit etre 1): %d\n", TasEtale(T));
 printf("\n\n");
}

void Test_LaHauteur(){
 printf("************************Test de LaHauteur*****************************\n");
 Tas T;
 T.HT = 5;
 printf("La hauteur est 5. LaHauteur vaut %d\n", LaHauteur(T));
 printf("\n\n");
}

void Test_LaPlace(){
 printf("***********************Test de LaPlace*******************************\n");
 Tas T1, T2;	
 T1.LT.NC = 1;
 T1.LT.NL = 1;
 T2.LT.NC = 2;
 T2.LT.NL = 2;
 Localisation Loc1, Loc2;
 Loc1 = LaPlace(T1);
 Loc2 = LaPlace(T2);
 printf("Localisation Tas T1 : %d . %d (doit etre 1 . 1)\n", Loc1.NC, Loc1.NL);
 printf("Localisation Tas T2 : %d . %d (doit etre 2 . 2)\n", Loc2.NC, Loc2.NL);
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
 printf("La tete vaut: %p\n",T.tete);
 printf("La queue vaut: %p\n",T.queue);
 printf("Le tas vide est cree (hauteur=0). LaHauteur vaut %d\n", LaHauteur(T));
 printf("\n\n");
}

void Test_IemeCarte(){
 printf("************************Test de IemeCarte************************\n");
 Tas T;
 Localisation L;

 L.NL = 1;
 L.NC = 3;
 
 CreerJeuNeuf(32, L, &T);
 int i;
 i=21;
 AfficheTaspourtest(T);
 printf("la 21eme carte du tas (couleur,rang,visibilite) est: %d, %d, %d\n",IemeCarte(T,i).CC, IemeCarte(T,i).RC, IemeCarte(T,i).VC);
 IemeCarte(T,i);
printf("\n\n");
}
 
void Test_RetournerCarteSur(){
 printf("************************Test de RetournerCarteSur************************\n");
 Tas T;
 Localisation L;

 L.NL = 1;
 L.NC = 3;
 
 CreerJeuNeuf(32, L, &T);
 printf("la carte sur le tas a la visibilite %d\n",T.queue->elt.VC);
 printf("l'avant derniere carte du tas a la visibilite %d\n",T.queue->prec->elt.VC);
 RetournerCarteSur(&T);
 printf("la carte sous le tas a la visibilite %d\n",T.queue->elt.VC);
 printf("l'avant derniere carte du tas a la visibilite %d\n",T.queue->prec->elt.VC);
 printf("\n\n");
}

void Test_RetournerCarteSous(){
 printf("************************Test de RetournerCarteSous************************\n");
 Tas T;
 Localisation L;

 L.NL = 1;
 L.NC = 3;
 
 CreerJeuNeuf(32, L, &T);
 printf("la carte sous le tas a la visibilite %d\n",T.tete->elt.VC);
 printf("la 2e carte du tas a la visibilite %d\n",T.tete->suiv->elt.VC);
 RetournerCarteSous(&T);
 printf("la carte sous le tas a la visibilite %d\n",T.tete->elt.VC);
 printf("la 2e carte du tas a la visibilite %d\n",T.tete->suiv->elt.VC);
 printf("\n\n");
}

void Test_EmpilerTas(){
 printf("************************Test de EmpilerTas************************\n");
 Tas T;
 T.MT = 1;
 printf("Avant opération, le tas est en mode etale. T.MT vaut: %d\n", T.MT);
 EmpilerTas(&T);
 printf("Apres opération, le tas doit etre empiler. T.MT vaut: %d (valeur attendue 0)\n", T.MT);
 printf("\n\n");
}

void Test_EtalerTas(){
 printf("************************Test de EtalerTas************************\n");
 Tas T;
 T.MT = 0;
 printf("Avant opération, le tas est en mode empile. T.MT vaut: %d\n", T.MT);
 EtalerTas(&T);
 printf("Apres opération, le tas doit etre etaler. T.MT vaut: %d (valeur attendue 1)\n", T.MT);
 printf("\n\n");
}

void Test_SupprimerTasVide(){
 printf("************************Test de SupprimerTasVide***************************\n");
 Tas T;
 Mode M; 
 Localisation L;

 L.NL=1;
 L.NC=1;
 CreerTasVide(L,empile,&T);
 T.RT = actif; 
 printf("Le role du tas avant operation est (0 pour actif): %d\n",T.RT);
 printf("Sa location est: %d,%d\n",T.LT.NC, T.LT.NL);
 AfficheTaspourtest(T);
 SupprimerTasVide(&T);
 
 printf("Le role du tas apres operation est : %d\n",T.RT);
 printf("Sa location est: %d,%d\n",T.LT.NC, T.LT.NL);
 AfficheTaspourtest(T);
 printf("\n\n");
}

void Test_CreerJeuNeuf(){
 printf("************************Test de CreeJeuNeuf***************************\n");
 
 printf("Cas 1 : Jeu de 32 cartes\n");
 Tas T1;
 Localisation L1;

 L1.NL = 1;
 L1.NC = 3;
 CreerJeuNeuf(32, L1, &T1);
 
 printf("La position du tas est %d,%d (doit etre 3,1)\n", T1.LT.NC, T1.LT.NL);
 printf("Le mode du tas est %d (doit etre 0)\n", T1.MT);
 printf("La visibilite des cartes doit etre cachee (=0), voir ci-dessous\n");
 printf("NbCartes vaut (doit etre 32) : %d \n", NbCartes);
 printf("PremierRang vaut (doit etre 7) : %d \n", PremierRang);
 AfficheTaspourtest(T1);
 
 printf("Cas 2 : Jeu de 52 cartes\n");
 Tas T2;
 Localisation L2;

 L2.NL = 1;
 L2.NC = 3;
 CreerJeuNeuf(52, L2, &T2);
 
 printf("La position du tas est %d,%d (doit etre 3,1)\n", T2.LT.NC, T2.LT.NL);
 printf("Le mode du tas est %d (doit etre 0)\n", T2.MT);
 printf("La visibilite des cartes doit etre cachee (=0), voir ci-dessous\n");
 printf("NbCartes vaut (doit etre 32) : %d \n", NbCartes);
 printf("PremierRang vaut (doit etre 7) : %d \n", PremierRang);
 AfficheTaspourtest(T2);
 printf("\n\n");
}

void Test_CarteSur(){
 printf("************************Test de CarteSur***************************\n");
 Tas T;
 Localisation L;

 L.NL = 1;
 L.NC = 3;
 CreerJeuNeuf(32, L, &T);
 printf("Info sur la carte qui est sur le tas (jeu neuf de 32 cartes): sa couleur: %d, son rang: %d, sa visibilite: %d.\n", CarteSur(T).CC, CarteSur(T).RC, CarteSur(T).VC);
 printf("\n\n");
}

void Test_CarteSous(){
 printf("************************Test de CarteSous***************************\n");
 Tas T;
 Localisation L;

 L.NL = 1;
 L.NC = 3;
 CreerJeuNeuf(32, L, &T);
 printf("Info sur la carte qui est sous le tas (jeu neuf de 32 cartes): sa couleur: %d, son rang: %d, sa visibilite: %d.\n", CarteSous(T).CC, CarteSous(T).RC, CarteSous(T).VC);
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
 printf("On part d'un jeu neuf:\n");
 AfficheTaspourtest(T);
 RetournerTas(&T);
 printf("Apres retournement du tas on obtient:\n");
 AfficheTaspourtest(T);
 RetournerTas(&T);
 printf("Apres 2eme retournement, on doit revenir au point de départ:\n")
 AfficheTaspourtest(T);
 printf("\n\n");
}

void Test_AjouterCarteSurTas(){
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
 printf("\n\n");
}

void Test_AjouterCarteSousTas(){
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
 printf("\n\n");
}

void Test_DeplacerHautSous(){
 printf("************************Test de deplacerHautSous************************\n");
 Localisation L1, L2;
 Tas T1, T2; 
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
 Localisation L3, L4;
 Tas T3, T4; 
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
 
 printf("Cas 3: Tas source (1 seule carte), Tas dest (plusieurs cartes)\n");
 Localisation L5, L6;
 Tas T5, T6; 
 struct adCarte carte2;
 L5.NC=3;
 L5.NL=3;
 L6.NC=4;
 L6.NL=4;
 
 /*T5: tas source d'une carte*/
 CreerTasVide(L5, empile, &T5); 
 CreerCartepourtest(&carte2);
 AjouterCarteSurTas(&carte2,&T5);
 
 /*T6: tas destination */
 CreerJeuNeuf(32, L6, &T6);
 
 printf("Tas source avant operation. Sa hauteur est %d\n\n", T5.HT);
 AfficheTaspourtest(T5);
 printf("Tas destination avant operation. Sa hauteur est %d\n\n", T6.HT);
 AfficheTaspourtest(T6);

 DeplacerHautSous(&T5,&T6);

 printf("Tas source apres operation. Sa hauteur est %d\n\n", T5.HT);
 AfficheTaspourtest(T5);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T6.HT);
 AfficheTaspourtest(T6);
 printf("\n\n");
}


void Test_DeplacerHautSur(){
 printf("************************Test de deplacerHautSur************************\n");
 Localisation L1, L2;
 Tas T1, T2; 
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

 DeplacerHautSur(&T1,&T2);

 printf("Tas source apres operation. Sa hauteur est %d\n\n", T1.HT);
 AfficheTaspourtest(T1);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T2.HT);
 AfficheTaspourtest(T2);
 printf("\n\n");
 
 printf("Cas 2: Tas source (1 seule carte), Tas dest (vide)\n");
 Localisation L3, L4;
 Tas T3, T4; 
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

 DeplacerHautSur(&T3,&T4);

 printf("Tas source apres operation. Sa hauteur est %d\n\n", T3.HT);
 AfficheTaspourtest(T3);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T4.HT);
 AfficheTaspourtest(T4);
 printf("\n\n");
 
 printf("Cas 3: Tas source (1 seule carte), Tas dest (plusieurs cartes)\n");
 Localisation L5, L6;
 Tas T5, T6; 
 struct adCarte carte2;
 L5.NC=3;
 L5.NL=3;
 L6.NC=4;
 L6.NL=4;
 
 /*T5: tas source d'une carte*/
 CreerTasVide(L5, empile, &T5); 
 CreerCartepourtest(&carte2);
 AjouterCarteSurTas(&carte2,&T5);
 
 /*T6: tas destination */
 CreerJeuNeuf(32, L6, &T6);
 
 printf("Tas source avant operation. Sa hauteur est %d\n\n", T5.HT);
 AfficheTaspourtest(T5);
 printf("Tas destination avant operation. Sa hauteur est %d\n\n", T6.HT);
 AfficheTaspourtest(T6);

 DeplacerHautSur(&T5,&T6);

 printf("Tas source apres operation. Sa hauteur est %d\n\n", T5.HT);
 AfficheTaspourtest(T5);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T6.HT);
 AfficheTaspourtest(T6);
 printf("\n\n");
}

void Test_DeplacerBasSur(){
 printf("************************Test de DeplacerBasSur************************\n");
 Localisation L1, L2;
 Tas T1, T2; 
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

 DeplacerBasSur(&T1,&T2);

 printf("Tas source apres operation. Sa hauteur est %d\n\n", T1.HT);
 AfficheTaspourtest(T1);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T2.HT);
 AfficheTaspourtest(T2);
 printf("\n\n");
 
 printf("Cas 2: Tas source (1 seule carte), Tas dest (vide)\n");
 Localisation L3, L4;
 Tas T3, T4; 
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

 DeplacerBasSur(&T3,&T4);

 printf("Tas source apres operation. Sa hauteur est %d\n\n", T3.HT);
 AfficheTaspourtest(T3);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T4.HT);
 AfficheTaspourtest(T4);
 printf("\n\n");
 
 printf("Cas 3: Tas source (1 seule carte), Tas dest (plusieurs cartes)\n");
 Localisation L5, L6;
 Tas T5, T6; 
 struct adCarte carte2;
 L5.NC=3;
 L5.NL=3;
 L6.NC=4;
 L6.NL=4;
 
 /*T5: tas source d'une carte*/
 CreerTasVide(L5, empile, &T5); 
 CreerCartepourtest(&carte2);
 AjouterCarteSurTas(&carte2,&T5);
 
 /*T6: tas destination */
 CreerJeuNeuf(32, L6, &T6);
 
 printf("Tas source avant operation. Sa hauteur est %d\n\n", T5.HT);
 AfficheTaspourtest(T5);
 printf("Tas destination avant operation. Sa hauteur est %d\n\n", T6.HT);
 AfficheTaspourtest(T6);

 DeplacerBasSur(&T5,&T6);

 printf("Tas source apres operation. Sa hauteur est %d\n\n", T5.HT);
 AfficheTaspourtest(T5);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T6.HT);
 AfficheTaspourtest(T6);
 printf("\n\n");
}

void Test_DeplacerBasSous(){
 printf("************************Test de DeplacerBasSous************************\n");
 Localisation L1, L2;
 Tas T1, T2; 
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

 DeplacerBasSous(&T1,&T2);

 printf("Tas source apres operation. Sa hauteur est %d\n\n", T1.HT);
 AfficheTaspourtest(T1);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T2.HT);
 AfficheTaspourtest(T2);
 printf("\n\n");
 
 printf("Cas 2: Tas source (1 seule carte), Tas dest (vide)\n");
 Localisation L3, L4;
 Tas T3, T4; 
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

 DeplacerBasSous(&T3,&T4);

 printf("Tas source apres operation. Sa hauteur est %d\n\n", T3.HT);
 AfficheTaspourtest(T3);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T4.HT);
 AfficheTaspourtest(T4);
 printf("\n\n");
 
 printf("Cas 3: Tas source (1 seule carte), Tas dest (plusieurs cartes)\n");
 Localisation L5, L6;
 Tas T5, T6; 
 struct adCarte carte2;
 L5.NC=3;
 L5.NL=3;
 L6.NC=4;
 L6.NL=4;
 
 /*T5: tas source d'une carte*/
 CreerTasVide(L5, empile, &T5); 
 CreerCartepourtest(&carte2);
 AjouterCarteSurTas(&carte2,&T5);
 
 /*T6: tas destination */
 CreerJeuNeuf(32, L6, &T6);
 
 printf("Tas source avant operation. Sa hauteur est %d\n\n", T5.HT);
 AfficheTaspourtest(T5);
 printf("Tas destination avant operation. Sa hauteur est %d\n\n", T6.HT);
 AfficheTaspourtest(T6);

 DeplacerBasSous(&T5,&T6);

 printf("Tas source apres operation. Sa hauteur est %d\n\n", T5.HT);
 AfficheTaspourtest(T5);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T6.HT);
 AfficheTaspourtest(T6);
 printf("\n\n");
}


void Test_DeplacerCarteSur(){
 printf("************************Test de DeplacerCarteSur************************\n");
 Localisation L1, L2;
 Tas T1, T2; 
 L1.NC=1;
 L1.NL=1;
 L2.NC=2;
 L2.NL=2;
 
 CreerJeuNeuf(32, L1, &T1);
 CreerTasVide(L2, empile, &T2);
 printf("Tas source avant operation. Sa hauteur est %d\n\n", T1.HT);
 AfficheTaspourtest(T1);
 printf("Tas destination avant operation. Sa hauteur est %d\n\n", T2.HT);
 AfficheTaspourtest(T2);
 printf("Deplacement de la carte de couleur 2 et de rang 10\n");
 DeplacerCarteSur(2,10,&T1,&T2);
 
 printf("Tas source apres operation. Sa hauteur est %d\n\n", T1.HT);
 AfficheTaspourtest(T1);
 printf("Tas destination apres operation. Sa hauteur est %d\n\n", T2.HT);
 AfficheTaspourtest(T2);
}

void Test_PoserTasSurTas(){
 printf("************************Test de DeplacerTasSurTas************************\n");
 Tas T1, T2;
 Localisation L1,L2;

 L1.NC=1;
 L1.NL=1;
 L2.NC=2;
 L2.NL=2;

 CreerJeuNeuf(32, L1, &T1);
 BattreTas(&T1); /* pour differentiation entre les 2 tas*/
 CreerJeuNeuf(32, L2, &T2);
 
 printf("Tas source avant operation. Sa hauteur est %d\n\n", T1.HT);
 AfficheTaspourtest(T1);
 printf("Tas destination avant operation. Sa hauteur est %d \n\n", T2.HT);
 AfficheTaspourtest(T2);
 
 PoserTasSurTas(&T1, &T2);
 
 printf("Tas source apres operation. Sa hauteur est %d\n\n", T1.HT);
 AfficheTaspourtest(T1);
 printf("Tas destination apres operation. Sa hauteur est %d \n\n", T2.HT);
 AfficheTaspourtest(T2);
 printf("\n\n");
}


int main () {
 Test_CouleurSuivante();
 Test_RangSuivant();
 Test_LeRang();
 Test_LaCouleur();
 Test_EstCachee();
 Test_EstDecouverte();
 Test_RangInferieur();
 Test_MemeRang();
 Test_CouleurInferieure();
 Test_MemeCouleur();
 Test_EstCarteAvant();
 Test_TasActif();
 Test_TasEmpile();
 Test_TasEtale();
 Test_LaHauteur();
 Test_LaPlace();
 Test_CreerTasVide();
 Test_IemeCarte();
 Test_RetournerCarteSur();
 Test_RetournerCarteSous();
 Test_EmpilerTas();
 Test_EtalerTas();
 Test_SupprimerTasVide();
 Test_CreerJeuNeuf();
 Test_CarteSur();
 Test_CarteSous();
 Test_EchangerCarte();
 Test_BattreTas();
 Test_RetournerTas();
 Test_AjouterCarteSurTas();
 Test_AjouterCarteSousTas();
 Test_DeplacerHautSous();
 Test_DeplacerHautSur();
 Test_DeplacerBasSur();
 Test_DeplacerBasSous();
 Test_PoserTasSurTas();
 Test_DeplacerCarteSur();
}



/* fonctions creer pour faciliter les tests, a utiliser ici seulement*/
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

void CreerCartepourtest2(struct adCarte *C){ 
 C->elt.CC = 2;
 C->elt.VC = Cachee;
 C->elt.RC = 12;
 C->suiv =NULL;
 C->prec =NULL;
}
