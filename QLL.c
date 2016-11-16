/*--------------------------------------------------------------*/
/* Reussites. Michel Bonin, Catherine Parent, octobre 2005, 
   d'apres les algorithmes de Pierre-Claude Scholl              */
/*--------------------------------------------------------------*/

/* Le relais des 7 */

#include <stdio.h>

#include "QLL.h"
typedef int booleen;

#define true 1
#define false 0
/* Tableau de jeu */

int nbcartesQLL;
int cptrPartie;
typedef Tas SerieQLL;
SerieQLL TableauQLL[52];
Tas TalonQLL;
Tas TempT1, TempT2;	/*Création de tas temporaires pour ne pas les éffacer lors de la recopie de tous les tas deplacés*/
	/* localisation des tas */
Localisation LocSeriesQLL[4][13];
Localisation LocTalonQLL;
Localisation LocTempT1, LocTempT2;

int premiereVictoire;
booleen victoire;

/* Formation du tableau de jeu initial */

void SaisirLocTasQLL()
{
	int i, j;

  LocTalonQLL.NC = 1;
  LocTalonQLL.NL = 1;
	LocTempT1.NC = 4;
	LocTempT1.NL = 1;	
	LocTempT2.NC = 5;
	LocTempT2.NL = 1;	
	
	  

  for (i=0; i<=3; i++){
  	for (j=0; j<=12; j++)
    {
			LocSeriesQLL[i][j].NL = 2+i;
    	LocSeriesQLL[i][j].NC = 1+j;
    	
    }
	}
}

/* Fonction renvoyant l'indice de la première case vide du tableau de tas*/
int IndiceTasVideQLL(){
	int tVide = 0;

	while ( tVide<nbcartesQLL && !TasVide(TableauQLL[tVide])) {
		tVide++;
	}
	return tVide;
}

void CreerTableauInitialQLL()
{
	int i, j, t;
	t = 0;
	SaisirLocTasQLL();

  /* Création du talon avec un jeu de nbcartesQLL cartes */
  CreerJeuNeuf(nbcartesQLL, LocTalonQLL, &TalonQLL);
  BattreTas(&TalonQLL);
	CreerTasVide(LocTempT1, empile, &TempT1);
	CreerTasVide(LocTempT2, empile, &TempT2);

	/* Création de la matrice de jeu */
	for (i=0; i<=3; i++){
  	for (j=0; j<=12; j++)
    {
			CreerTasVide(LocSeriesQLL[i][j], empile, &(TableauQLL[t]));
			t++;
    }
	}
	
	/* Positionnement des deux première cartes sur les deux premiers tas de la matrice*/
	DeplacerHautSur(&TalonQLL, &(TableauQLL[0]));
  RetournerCarteSur(&(TableauQLL[0]));
	DeplacerHautSur(&TalonQLL, &(TableauQLL[1]));
  RetournerCarteSur(&(TableauQLL[1]));


}

void ReformerTableauInitialQLL()
{

	int tVide = 0;
	int t;

	tVide = IndiceTasVideQLL();

	for(t = 0; t < tVide-1; t ++){
	PoserTasSurTas(&(TableauQLL[t]),&(TableauQLL[t+1]));
	}	
	
	RetournerTas(&(TableauQLL[tVide-1]));
  PoserTasSurTas(&(TableauQLL[tVide-1]),&TalonQLL);

	DeplacerHautSur(&TalonQLL, &(TableauQLL[0]));
  RetournerCarteSur(&(TableauQLL[0]));
	DeplacerHautSur(&TalonQLL, &(TableauQLL[1]));
  RetournerCarteSur(&(TableauQLL[1]));
}



void AfficherQLL()
{
	int t;

  EffacerGraphique();
  AfficherTas(TalonQLL, "");
	AfficherTas(TempT1, "");
	AfficherTas(TempT2, "");
	for (t=0; t<=nbcartesQLL - 1; t++){
  	
    
			AfficherTas(TableauQLL[t], "");
    
	}

	
  AttendreCliquer();
}



void JouerCarteQLL(){
	int tVide;
	tVide = IndiceTasVideQLL();

	/*Pas besoin de vérifier si tVide = nbcartesQLL car si c'est le cas, toutes les cartes ont été jouées*/
	DeplacerHautSur(&TalonQLL, &TableauQLL[tVide]); 
}

void DeplacementQLL(ModeTrace MT){

	int tVide = IndiceTasVideQLL();
	int i, j, tTestAffichage;
	booleen OK1 = true;
	booleen OK2 = true;
	booleen dejaDeplace = false;
	while (OK2){
		while (tVide !=2 && OK1){	
			if (LeRang(CarteSur(TableauQLL[tVide-1])) == LeRang(CarteSur(TableauQLL[tVide-3])) || LaCouleur(CarteSur(TableauQLL[tVide-1])) == LaCouleur(CarteSur(TableauQLL[tVide-3]))){
				PoserTasSurTas(&(TableauQLL[tVide-2]),&(TableauQLL[tVide-3]));
				if (MT == AvecTrace)
  	  		AfficherQLL();
				PoserTasSurTas(&(TableauQLL[tVide-1]),&(TableauQLL[tVide-2]));
				if (MT == AvecTrace)
  	  		AfficherQLL();
				tVide = IndiceTasVideQLL();
			} else {
			OK1 = false;
			}
		}
		OK2 = false;
		dejaDeplace = false;
		for (i = tVide - 1; i > 2; i--){
			if ((LeRang(CarteSur(TableauQLL[i-1])) == LeRang(CarteSur(TableauQLL[i-3])) || LaCouleur(CarteSur(TableauQLL[i-1])) == LaCouleur(CarteSur(TableauQLL[i-3])))&& dejaDeplace == false){
			OK2 = true;
			dejaDeplace = true;
			for(j = i - 3; j < tVide - 1; j++){
				PoserTasSurTas(&(TableauQLL[j+1]),&(TableauQLL[j]));
				tTestAffichage = IndiceTasVideQLL();
				if (tTestAffichage != tVide){
				if (MT == AvecTrace)
  	  		AfficherQLL();
				}
			}
			}
		}
		tVide = IndiceTasVideQLL();
	}	
} 


int JouerUnTourQLL(ModeTrace MT)
{
	int gagneQLL;

  if (MT == AvecTrace)
    AfficherQLL();

  do	{
      
    RetournerCarteSur(&TalonQLL);
	  if (MT == AvecTrace)
	  	AfficherQLL();	
		
    JouerCarteQLL();
		if (MT == AvecTrace)
    	AfficherQLL();

		DeplacementQLL(MT);
	}
  while (!TasVide(TalonQLL));


/* Test de la possibilité de jouer après que le Talon soit vidé*/

	booleen OK = true;
	int tVide, tVideApresDeplacement, i;
	
	while (!TasVide(TableauQLL[2]) && OK){
		tVide = IndiceTasVideQLL();
		PoserTasSurTas(&(TableauQLL[0]), &TempT1);
		if (MT == AvecTrace)
    	AfficherQLL();
		PoserTasSurTas(&(TableauQLL[1]), &TempT2);
		if (MT == AvecTrace)
    	AfficherQLL();
		for (i = 2; i < tVide; i++){
			PoserTasSurTas(&(TableauQLL[i]),&(TableauQLL[i-2]) );
			if (MT == AvecTrace)
    	AfficherQLL();
		}
		PoserTasSurTas(&TempT1, &(TableauQLL[tVide-2]));
		if (MT == AvecTrace)
    	AfficherQLL();
		PoserTasSurTas(&TempT2, &(TableauQLL[tVide-1]));
		if (MT == AvecTrace)
    	AfficherQLL();

		DeplacementQLL(MT);
		tVideApresDeplacement = IndiceTasVideQLL();
		if (tVideApresDeplacement == tVide)
		OK = false;
	}


	tVide = IndiceTasVideQLL();
	if (MT == AvecTrace){	
		if (tVide == 2){
			printf("Vous avez gagne !!!\n");
		}else{
			printf("Vous avez perdu !!!\n");
		}
	}else{
		if (victoire == false){
			premiereVictoire++;
		}
		if (tVide == 2){
			/*printf("Vous avez gagne !!!111111111111\n");*/
			victoire = true;
			gagneQLL = 1;
		}else if (tVide > 2){
			/*printf("Vous avez perdu !!!000000000000\n");*/
			gagneQLL = 0;
		} else {
		printf("Bug !!!22222222222\n");
		}
	}
return gagneQLL;
}


int JouerUneQLL(int nbPartie, ModeTrace MT) 
{
  
 	cptrPartie = nbPartie - 1;
	int cptrPartieGagne = 0;
	int y;
	int i;

	cptrPartieGagne = JouerUnTourQLL(MT);

  while (cptrPartie != 0)  
    {
      ReformerTableauInitialQLL();
			cptrPartieGagne += JouerUnTourQLL(MT);
			cptrPartie--;
/*-----------------------------------------------------*/	
			if (cptrPartie == 5000){
			printf("Partie 15000\n");
		y = IndiceTasVideQLL(); 
		for (i = 0; i < y; i++){
				printf("Carte i = %d, Rang : %d, Couleur : %d, HT : %d\n", i+1, LeRang(CarteSur(TableauQLL[i])), LaCouleur(CarteSur(TableauQLL[i])), LaHauteur(TableauQLL[i]));
		}
	}
if (cptrPartie == 10000){
printf("Partie 10000\n");
		y = IndiceTasVideQLL(); 
		for (i = 0; i < y; i++){
				printf("Carte i = %d, Rang : %d, Couleur : %d, HT : %d\n", i+1, LeRang(CarteSur(TableauQLL[i])), LaCouleur(CarteSur(TableauQLL[i])), LaHauteur(TableauQLL[i]));
		}
	}
if (cptrPartie == 15000){
printf("Partie 5000\n");
		y = IndiceTasVideQLL(); 
		for (i = 0; i < y; i++){
				printf("Carte i = %d, Rang : %d, Couleur : %d, HT : %d\n", i+1, LeRang(CarteSur(TableauQLL[i])), LaCouleur(CarteSur(TableauQLL[i])), LaHauteur(TableauQLL[i]));
		}
	}
/*------------------------------------------------------*/
    }
return cptrPartieGagne;
}
		
void ObserverQLL(int NP, int nbcartes)
{
  nbcartesQLL = nbcartes;
  CreerTableauInitialQLL();
  JouerUneQLL(NP, AvecTrace);

}

void AnalyserQLL(int NP, int nbcartes)
{
	int nombreVictoire;
	int i;
	int x = 0;
	int y = IndiceTasVideQLL();
	nbcartesQLL = nbcartes;	
	premiereVictoire = 0;
	victoire = false;	
  CreerTableauInitialQLL();
  nombreVictoire = JouerUneQLL(NP, SansTrace);
	printf("Vous avez gagne : %d partie(s) sur : %d.\n", nombreVictoire, NP);
	printf("Soit un pourcentage de victoire de %d %%\n", nombreVictoire * 100 / NP);
	if (victoire == true)
	printf("Vous avez gagne pour la premiere fois a la partie numero : %d.\n", premiereVictoire);
	for (i = 0; i < y; i++){
		x = x + TableauQLL[i].HT;
	}
	printf(" %d\n", x);
	if (cptrPartie == 0){
	printf("Partie 20000\n");
		for (i = 0; i < y; i++){
				printf("Carte i = %d, Rang : %d, Couleur : %d, HT : %d\n", i+1, LeRang(CarteSur(TableauQLL[i])), LaCouleur(CarteSur(TableauQLL[i])), LaHauteur(TableauQLL[i]));
		}
	}
	
}






	
