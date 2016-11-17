/*--------------------------------------------------------------*/
/* Reussites. Michel Bonin, Catherine Parent, octobre 2005, 
   d'apres les algorithmes de Pierre-Claude Scholl              
   modifie par F. Carrier, juillet 2012
   --> types enumeres : Couleur, Rang
   --> tas representes par des listes chainees
----------------------------------------------------------------*/
#include <stdlib.h>
#include "Tas.h"
#include "Alea.h"
#include <stdlib.h>

/*-----------------------------------*/
/* Specifications des objets de base */
/*-----------------------------------*/

/* Couleurs et rangs */


/* Couleurs */
/* Ordre croissant sur les couleurs: trefle, carreau, coeur, pique */

Couleur CouleurSuivante(Couleur C) {
	if (C < DerniereCouleur){
		C+=1; 
	}else{
		C = PremiereCouleur;
	}  

	return C;
}

/* Rangs */
/* Ordre croissant sur les rangs: deux, ..., dix, valet, dame, roi, as */

Rang RangSuivant(Rang R) {
	if (R == As){
		R = Deux;
	}else{
		R ++;
	}

	return R;
}

/*--------------------------------------------------------------------*/
/* Representation des primitives de manipulation des cartes et des tas*/
/*--------------------------------------------------------------------*/

/* Representation des cartes */

	/* Testeurs et selecteurs */
	
Rang LeRang(Carte C) {
	
	return C.RC ;
}

Couleur LaCouleur(Carte C) {
	
	return C.CC ;
}

Visibilite EstCachee(Carte C) {

	return !C.VC ;
}

Visibilite EstDecouverte(Carte C) {

	return C.VC ;
}

	/* Comparaison de cartes */
	
booleen RangInferieur(Carte C1, Carte C2) {

	return LeRang(C1)<=LeRang(C2) ;
}

booleen MemeRang(Carte C1, Carte C2) {

	return LeRang(C1) == LeRang(C2) ;
}

booleen CouleurInferieure(Carte C1, Carte C2) {

	return (C1.CC < C2.CC);
}

booleen MemeCouleur(Carte C1, Carte C2) {

	return (C1.CC == C2.CC);
}

booleen EstCarteAvant(Carte C1, Carte C2) {
  booleen test = faux;
	if (CouleurInferieure(C1, C2)){
		test = vrai;
	}else if (MemeCouleur(C1, C2)){
		test = RangInferieur(C1, C2);
	}else{
	test = faux;
	}
	
	return test;
}


/* Representation des tas */
	
	/* Testeurs et selecteurs */

booleen TasActif(Tas T) {

	return T.RT;
}

booleen TasVide(Tas T) {

	return T.HT == 0;
}

booleen TasEmpile(Tas T) {

	return T.MT;
}

booleen TasEtale(Tas T) {

	return T.MT == etale;
}

int LaHauteur(Tas T) {

	return T.HT;
}

Localisation LaPlace(Tas T) {

	return T.LT;
}

	/* Constructeurs */
	
/* *************************************************************
void CreerTasVide(Localisation L, Mode M, Tas *T)
associe à T un tas vide actif placé en L et de mode d'étalement M.
Pré-condition : l'emplacement L est disponible
**************************************************************** */
void CreerTasVide(Localisation L, Mode M, Tas *T) {
	T -> MT = M;
	T -> LT = L;
	T -> RT = actif;
	T -> HT = 0;
	T -> tete = NULL;
	T -> queue = NULL;
}

/* *************************************************************
void SupprimerTasVide(Tas *T)
rend le tas vide inactif. En particulier, la place qu'il occupait
devient libre pour un autre tas.
Pré-condition : le tas T est vide et actif
**************************************************************** */
void SupprimerTasVide(Tas *T) {
	T->RT = inactif;
	T->LT.NC = 0;
	T->LT.NL = 0;
}

/* *************************************************************
void CreerJeuNeuf(int N, Localisation L, Tas *T)
forme en L le tas empilé T avec l'ensemble des N cartes du jeu dans
l'ordre des cartes et faces cachées.
Donne leur valeur aux variables globales NbCartes et PremierRang.
Pré-condition : l'emplacement L est libre
                N==52 ou N==32
**************************************************************** */
void CreerJeuNeuf(int N, Localisation L, Tas *T) {
	Couleur Co = PremiereCouleur;
	struct adCarte *nouvelleCarte, *fictif;
	int i;
	NbCartes = N;
	if (N == 32) PremierRang = 7;
	if (N == 52) PremierRang = 2;

	/*Initialisation du tas vide*/
	CreerTasVide(L,empile,T);
	
	/*Création d'un fictif*/
	fictif = (struct adCarte*) malloc(sizeof(struct adCarte));
	T->tete = fictif;

  /*chainage de la queue*/
	T->queue = T->tete;

	for (Co; Co <= DerniereCouleur; Co ++){
		for (i = PremierRang; i <= DernierRang; i++){

				/*Création et initialisation de la ième carte*/
				nouvelleCarte = (struct adCarte*) malloc(sizeof(struct adCarte));
				nouvelleCarte->elt.CC = Co;
				nouvelleCarte->elt.RC = i;
				nouvelleCarte->elt.VC = Cachee;

				/*Chainage*/
				T->queue->suiv = nouvelleCarte;
 				nouvelleCarte->prec = T->queue;
				T->queue = nouvelleCarte;
		}
  }
  T->queue->suiv = NULL;

	/*liberer le Fictif!*/
	T->tete = T->tete->suiv;
	T->tete->prec = NULL;
	free(fictif);
	
	T->HT = N;
}

	/* Consultation des cartes d'un tas: ne deplace pas la carte */
	
/* *************************************************************
Carte CarteSur(Tas T) {
carte situee au dessus du tas
**************************************************************** */
Carte CarteSur(Tas T) {

	return T.queue->elt;	
}

/* *************************************************************
Carte CarteSous(Tas T) {
carte situee au dessous du tas
**************************************************************** */
Carte CarteSous(Tas T) {

	return T.tete->elt ;
}

/* *************************************************************
Carte IemeCarte(Tas T, int i)
ieme carte dans T (de bas en haut).
Précondition : i <= LaHauteur(T)
**************************************************************** */
Carte IemeCarte(Tas T, int i) {
	int j = 1;
	struct adCarte *AC;

	AC = T.tete;
	while (j != i) {		
		AC = AC->suiv;
		j++;
	}		
	return AC->elt;	
}


	/* Retournement d'une carte sur un tas */
	
/* *************************************************************
void RetournerCarteSur(Tas *T)
retourne la carte située au dessus du tas T.
Pré-condition : T non vide
**************************************************************** */
void RetournerCarteSur(Tas *T) {
	if (T->queue->elt.VC == Cachee)
	T->queue->elt.VC = Decouverte;
	else
	T->queue->elt.VC = Cachee;
}

/* *************************************************************
void RetournerCarteSous(Tas *T)
retourne la carte située au dessous du tas T.
Pré-condition : T non vide
**************************************************************** */
void RetournerCarteSous(Tas *T) {
	if (T->tete->elt.VC == Cachee)
	T->tete->elt.VC = Decouverte;
	else
	T->tete->elt.VC = Cachee;
}

	/* Modification d'un tas */

/* *************************************************************
void EmpilerTas(Tas *T)
void EtalerTas(Tas *T)
modification du mode d'etalement d'un tas
**************************************************************** */
void EmpilerTas(Tas *T) {
	T->MT = empile;
}

void EtalerTas(Tas *T) {
	T->MT = etale;
}

	
/* *************************************************************
void EchangerCartes(int i, int j, Tas *T)
echange les cartes i et j du tas T
Precondition : les deux cartes existent i,j <= LaHauteur(T)
**************************************************************** */
void EchangerCartes(int i, int j, Tas *T) {
	struct adCarte *AC;
	int cptr;

	Carte carteTemporaire = IemeCarte(*T,i); /*carteTemporaire stock la ième carte*/

	AC = T->tete;
	for (cptr = 1; cptr < i; cptr++)
			AC = AC->suiv;
	AC->elt = IemeCarte(*T,j);	/*La carte i devient la carte j*/

	AC = T->tete;
	for (cptr = 1; cptr < j; cptr++)
			AC = AC->suiv;
	AC->elt = carteTemporaire;	/*La carte j devient la carte i, par l'intermédiaire de la carteTemporaire*/
}

/* *************************************************************
void BattreTas(Tas *T)
bas le tas T
**************************************************************** */
void BattreTas(Tas *T) {
	int totalCarte = T->HT;
	int iAlea, jAlea, cptr;
	cptr = 0;	
	while (cptr != 1000){
		InitAlea();
		iAlea = UnEntier(totalCarte);
		jAlea = UnEntier(totalCarte);
		EchangerCartes(iAlea, jAlea, T);
		cptr ++;
	}
}

/* ******************************************************************************
void RetournerTas(Tas *T)
retourne le tas T : la premiere devient la derniere et la visibilite est inversee
********************************************************************************* */
void RetournerTas(Tas *T) {

	struct adCarte *AC, *ACchainage; /*AC parcours les cartes du tas alors que ACchainage stock temporairement un chainage*/
	
	AC = T->tete;

	while (AC != NULL){

		/*Inversion des chainage*/
		ACchainage = AC->suiv; /*Stockage de AC->suiv dans ACchainage*/
		AC->suiv = AC->prec;
		AC->prec = ACchainage;

		/*Inversion de la visibilité*/
		if(AC->elt.VC == Cachee)
			AC->elt.VC = Decouverte;
		if(AC->elt.VC == Decouverte)
			AC->elt.VC = Cachee;

		/*Passage à la carte suivante (qui est devenu la carte précedente)*/
		AC = AC->prec;
	}

	/*Inversion de la tête et de la queue*/
	AC = T->tete;
	T->tete = T->queue;
	T->queue = AC;
}

	/* Deplacements de cartes d'un tas sur un autre */


/* ******************************************************************************
void AjouterCarteSurTas (adCarte *ac, Tas *T)
ajoute la carte d'adresse ac sur le tas T
********************************************************************************* */
void AjouterCarteSurTas (struct adCarte *ac, Tas *T) {
	T->queue->suiv = ac;
	ac->prec = T->queue;
	T->queue = T->queue->suiv;
	T->queue->suiv = NULL;	
}

/* ******************************************************************************
void AjouterCarteSousTas (adCarte *ac, Tas *T)
ajoute la carte d'adresse ac sous le tas T
********************************************************************************* */
void AjouterCarteSousTas (struct adCarte *ac, Tas *T) {
	T->tete->prec = ac;
	ac->suiv = T->tete;
	T->tete = T->tete->prec;
	T->tete->prec = NULL;
}

/* ******************************************************************************
void DeplacerHautSur(Tas *T1, Tas *T2)
enlève la carte située au dessus de T1 et la place au dessus de T2
Pré-condition : T1 n'est pas vide, T2 est actif.
********************************************************************************* */
void DeplacerHautSur(Tas *T1, Tas *T2) {
 /*
 * T1 tas source
 * T2 Tas destination
 */
  struct adCarte *AC;
  AC = T1->queue; 
  T1->queue = T1->queue->prec;
  T1->queue->suiv = NULL;
  AC-> prec = T2->queue;
  T2->queue = AC;

  T1 -> HT = T1 ->HT-1;
  T2 -> HT = T2 ->HT+1;
}

/* ******************************************************************************
void DeplacerHautSous(Tas *T1, Tas *T2)
enlève la carte située au dessus de T1 et la place au dessous de T2.
Pré-condition : T1 n'est pas vide, T2 est actif.
********************************************************************************* */
void DeplacerHautSous(Tas *T1, Tas *T2) {
 /*
 * T1 tas source
 * T2 Tas destination
 */
  struct adCarte *AC;
  AC = T1->queue; 
  T1->queue = T1->queue->prec;
  T1->queue->suiv = NULL;
  AC->suiv = T2->tete;
  AC->prec = NULL;
  T2->tete = AC;

  T1 -> HT = T1 ->HT-1;
  T2 -> HT = T2 ->HT+1;
}

/* ******************************************************************************
void DeplacerBasSur(Tas *T1, Tas *T2)
enlève la carte située au dessous de T1 et la place au dessus de T2.
Pré-condition : T1 n'est pas vide, T2 est actif.
********************************************************************************* */
void DeplacerBasSur(Tas *T1, Tas *T2) {
}

/* ******************************************************************************
void DeplacerBasSous(Tas *T1, Tas *T2) {
enlève la carte située au dessous de T1 et la place au dessous de T2.
Pré-condition : T1 n'est pas vide, T2 est actif.
********************************************************************************* */
void DeplacerBasSous(Tas *T1, Tas *T2) {
	struct adCarte *AC;
	AC = T1->tete ;
	T1->tete = T1->tete->suiv ;
	T1->tete->prec = AC ;
	AC->suiv = T2 ;
	T2->tete->prec = AC ;
	T2.tete = T2->tete->prec ;
	T1->HT = T1->HT - 1 ;
	T2->HT = T2->HT +1 ;
}

/* ******************************************************************************
void DeplacerCarteSur(Couleur C, Rang R, Tas *T1, Tas *T2)
enlève du tas T1, la carte de couleur C et de rang R et la place au dessus de T2.
Pré-condition : T1 contient la carte et T2 est actif.
********************************************************************************* */
void DeplacerCarteSur(Couleur C, Rang R, Tas *T1, Tas *T2) {
	struct adCarte *AC;
	AC = T1->tete;
	while (T1->AC->elt.CC != C || T1->AC->elt.RC != R) {
		AC=AC->suiv;
	}
	
	T2->queue = AC ;
	AC->prec->suiv = AC->suiv ;
	AC->suiv->prec = AC->prec ;
	AC->suiv = NULL ;
	AC->prec = T2->queue ;
	AC->prec->suiv = AC ;
	T1->HT = T1->HT - 1 ;
	T2->HT = T2->HT +1 ;
}

/* ******************************************************************************
void PoserTasSurTas(Tas *T1, Tas *T2)
pose le tas T1 sur le tas T2.
Les deux tas doivent avoir le même mode d'étalement.
A l'état final, le tas T1 est vide mais toujours actif, et le tas T2 comporte (de bas en
haut) toutes les cartes qu'il avait au départ puis toutes les cartes de T1 dans l'ordre
qu'elles avaient au départ dans chacun des tas.
Cette opération ne modifie ni la visibilité des cartes, ni la localisation des tas T1 et T2,
ni leur mode d'étalement.
********************************************************************************* */
void PoserTasSurTas(Tas *T1, Tas *T2) {
	T2->queue->suiv = T1.tete ;
	T1->tete->prec = T2->queue ;
	T2->queue = T1->queue ;
	
	T2->HT = T1->HT + T2->HT ;
	
	CreerTasVide(T1.LT, T1.MT, Tas *T1) ;
}


