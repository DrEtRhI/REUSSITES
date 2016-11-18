

#include <stdio.h>
#include "MDtest.h"

char TexteCouleurMD[5][8] = {"", "Trefle", "Carreau", "Coeur", "Pique"};

typedef Tas SerieMD;
SerieMD LigneCouleurMD[DerniereCouleur+1];
SerieMD LigneStockMD[4];
Tas TalonMD;
Localisation LocSeriesCouleurMD[DerniereCouleur+1];
Localisation LocSeriesStockMD[4];
Localisation LocTalonMD;
int cptrGagne = 0;
ModeTrace MTMD;

void SaisirLocTasMD()
{
  int i;

  LocTalonMD.NC = 1;
  LocTalonMD.NL = 1;

  for (i=PremiereCouleur; i<=DerniereCouleur; i++)
    {
      LocSeriesCouleurMD[i].NC = 2*i+2;
      LocSeriesCouleurMD[i].NL = 1;
    }

  for (i=0; i<4; i++)
    {
      LocSeriesStockMD[i].NC = 2*i+4;
      LocSeriesStockMD[i].NL = 3;
    }
}

void CreerTableauInitialMD()
{
  Couleur Co;
	int i;
  SaisirLocTasMD();

  /* Création du talon avec un jeu de 52 cartes et du rebut avec un tas vide */
  CreerJeuNeuf(32, LocTalonMD, &TalonMD);
  BattreTas(&TalonMD);

  /* Création des séries de chaque couleur et initialisation avec le sept */

	for (Co=PremiereCouleur; Co<=DerniereCouleur; Co++)
		{
			CreerTasVide(LocSeriesCouleurMD[Co], empile, &(LigneCouleurMD[Co]));
		}

	for (i=0; i<4; i++)
		{
			CreerTasVide(LocSeriesStockMD[i], empile, &(LigneStockMD[i]));
		}

}

void ReformerTableauInitialMD(){

	Couleur Co;
	int i;
	
	if (!TasVide(TalonMD)){
		RetournerTas(&TalonMD);
		RetournerCarteSous(&TalonMD);
	}

	for (Co=PremiereCouleur; Co<=DerniereCouleur; Co++)
	{
		PoserTasSurTas(&LigneCouleurMD[Co], &TalonMD);
	}

	for (i=0; i<4; i++)
	{
		PoserTasSurTas(&LigneStockMD[i], &TalonMD);
	}

	RetournerTas(&TalonMD);
  BattreTas(&TalonMD);
}

void AfficherMD()
{
  Couleur Co;
	int i;

  EffacerGraphique();
  AfficherTas(TalonMD, "Talon");

  for (Co=PremiereCouleur; Co<=DerniereCouleur; Co++)
    AfficherTas(LigneCouleurMD[Co], TexteCouleurMD[Co]);

	for (i=0; i<4; i++)
		AfficherTas(LigneStockMD[i], "");

  AttendreCliquer();
}

void DescendreTalon(booleen *joueTalon){
		
	int i,j, iDifferenceRang, iDifferenceRangMinimum, iPosition;
	iPosition = 4; 
	iDifferenceRangMinimum = 15; /*Difference fictive plus grande qu'un possible réelle différence*/
	booleen stockVide = vrai;
	booleen mouvementRealise; /*booleen pour la strategie "As"*/

	for (i = 0; i < 4; i ++) /*Traitement du cas particulier ou tous les stocks sont vides*/
		stockVide &= TasVide(LigneStockMD[i]);
	if (stockVide){ 	
		DeplacerHautSur(&TalonMD, &LigneStockMD[0]);
		*joueTalon = vrai;
			if (MTMD == AvecTrace)
		AfficherMD();
	}
	else { 						/*Traitement des autres cas*/

/*-------------------------------------------------------------------*/
/*-----------------------StrategieAs---------------------------------*/
	booleen estAs = faux;
  booleen ilExisteAs= faux;
	booleen ilExisteTrou = faux;
	booleen ilExisteDeplacement = faux;
	booleen ilExisteDeplacementAutreAs = faux;
	int iDifferenceRangAs;
	int iDifferenceRangMinimumAs = 15;
	int iPositionAs = 4;
	int indiceDuTrou = 4;

	for (i=0; i<4; i++){									/*Existe t il un trou ?*/
		ilExisteTrou |= TasVide(LigneStockMD[i]);
		if(TasVide(LigneStockMD[i]))
			indiceDuTrou = i;
	}
	
	for (i=0; i<4; i++){ /*Recuperation de l'indice le plus judicieux*/
		if(!TasVide(LigneStockMD[i])){
				iDifferenceRangAs = LeRang(CarteSur(LigneStockMD[i])) - LeRang(CarteSur(TalonMD));
				if ((iDifferenceRangMinimumAs >= iDifferenceRangAs) && (iDifferenceRangAs >= 0)){
					iDifferenceRangMinimumAs = iDifferenceRangAs;
					if (LeRang(CarteSur(LigneStockMD[i])) != 14)
							ilExisteDeplacementAutreAs = vrai;
					iPositionAs = i;
				}
			}
	}
	if (iPositionAs = 4 && !ilExisteTrou){
		ilExisteDeplacement = faux;	/*Il existe deplacement possible*/
		ilExisteDeplacementAutreAs = faux;
	}
	else {
		ilExisteDeplacement = vrai;	/*Il n'existe pas de placement possible*/
	}
	
	for (i=0; i<4; i++){
		if (!TasVide(LigneStockMD[i])&&(LeRang(CarteSur(LigneStockMD[i])) == 14)){			
			ilExisteAs = vrai;
		}
	}
	
	if (LeRang(CarteSur(TalonMD)) == 14)
		estAs = vrai;

	if (ilExisteAs && ilExisteTrou && !ilExisteDeplacementAutreAs && !estAs){
		DeplacerHautSur(&TalonMD, &LigneStockMD[indiceDuTrou]);
		*joueTalon = vrai;
			if (MTMD == AvecTrace)
		AfficherMD();
	} else {

/*-------------------------------------------------------------------*/
		/*Stratégie pour récuperer l'indice le plus judicieux*/
		for (i=0; i<4; i++){
		
			if(!TasVide(LigneStockMD[i])){
				iDifferenceRang = LeRang(CarteSur(LigneStockMD[i])) - LeRang(CarteSur(TalonMD));
				if ((iDifferenceRangMinimum >= iDifferenceRang) && (iDifferenceRang >= 0)){
					iDifferenceRangMinimum = iDifferenceRang;
					iPosition = i;
				}
			}
		
		}
	
		/*On Descent la carte si possible sur iPosition*/
		if (iPosition <4){ /* Test descente possible */
			DeplacerHautSur(&TalonMD, &LigneStockMD[iPosition]);
			*joueTalon = vrai;
				if (MTMD == AvecTrace)
			AfficherMD();
		} else { /*Descente impossible sur une carte*/
			j = 0;				/*On regarde si il y a un tas vide*/
			while (j<4 && !TasVide(LigneStockMD[j])){
			j ++;
			}
			if (j < 4){		/*Si oui, on pose la carte sur ce tas vide*/
				DeplacerHautSur(&TalonMD, &LigneStockMD[j]);
				*joueTalon = vrai;
					if (MTMD == AvecTrace)
				AfficherMD();
			} else {
			*joueTalon = faux; /*Sinon, il est impossible de jouer*/
			}
		}
	}

/*-------------*/
	}
/*-------------*/
	
}

void JouerTalonMD(ModeTrace MT, booleen *talonMonte, booleen *joueTalon){

	Couleur CoTalon, Co;
	Rang RcTalon;
	RetournerCarteSur(&TalonMD);
	if (MTMD == AvecTrace)
		AfficherMD();

	/*On regarde la couleur et le rang de la carte sur la talon*/
	RcTalon = LeRang(CarteSur(TalonMD));
	CoTalon = LaCouleur(CarteSur(TalonMD));
	

	if(RcTalon == Sept){ /*Si c'est un sept, on la place en haut sur sa couleur */
		DeplacerHautSur(&TalonMD, &LigneCouleurMD[CoTalon]);
		*talonMonte = vrai;
		*joueTalon = vrai;
		if (MTMD == AvecTrace)
			AfficherMD();
	} else if ((!TasVide(LigneCouleurMD[CoTalon]))&&(RcTalon -1 == LeRang(CarteSur(LigneCouleurMD[CoTalon])))){ /* Peut on la place en haut ?*/
		DeplacerHautSur(&TalonMD, &LigneCouleurMD[CoTalon]);
		*talonMonte = vrai;
		*joueTalon = vrai;
		if (MTMD == AvecTrace)
			AfficherMD();
	} else { /*Peut on la placer en bas ? */
		*talonMonte = faux;
		DescendreTalon(joueTalon);
	}
}

void MonteStockMD(booleen *monteStock){

	booleen monteEffectue = vrai;		
	booleen monteEffectueParStock = vrai;
	Rang RcStock;
	Couleur CoStock;	
	*monteStock = faux;
	int i;	

	while(monteEffectue){ /*Tant qu'on effectue une montee, on continue a verifier un tour complet*/
		monteEffectue = faux;
		for (i=0; i<4; i++){ /*Pour tous les tas*/
			if (!TasVide(LigneStockMD[i])){ /*Si le tas n'est pas vide*/
				monteEffectueParStock = vrai;
				while ((monteEffectueParStock == vrai)&&(!TasVide(LigneStockMD[i]))){ /*Si on monte une carte, on reCheck si on peut sur le meme tas*/
					monteEffectueParStock = faux;
					RcStock = LeRang(CarteSur(LigneStockMD[i]));
					CoStock = LaCouleur(CarteSur(LigneStockMD[i]));
					if ((!TasVide(LigneCouleurMD[CoStock]))&&(RcStock -1 == LeRang(CarteSur(LigneCouleurMD[CoStock])))){
						DeplacerHautSur(&LigneStockMD[i], &LigneCouleurMD[CoStock]);
						monteEffectueParStock = vrai;
						monteEffectue = vrai;
						*monteStock = vrai;
						if (MTMD == AvecTrace)
							AfficherMD();
					}
				
				}
			}

		}
	}
	
	
}

void JouerUneMD(ModeTrace MT){

	booleen talonMonte = faux;
	booleen joueTalon = vrai;
	booleen monteStock = faux;
	booleen stockVide;
	int i;	
	
	while(!TasVide(TalonMD) && joueTalon){

			/*Jouer le talon*/
			JouerTalonMD(MT, &talonMonte,&joueTalon);
			if (talonMonte){ /*Si on a joué une carte sur la ligne du haut : */
				MonteStockMD(&monteStock);			
			}
	}
	
	monteStock = vrai;

	MonteStockMD(&monteStock); /*une montée restante pour le dernier coup*/

	
	stockVide = vrai;
	for (i = 0; i < 4; i ++){
		stockVide &= TasVide(LigneStockMD[i]); 
	}
	
	if (TasVide(TalonMD) && stockVide){
		printf("Vous avez gagne\n");
		cptrGagne ++;
	}
	else
		printf("Vous avez perdu\n");
}

void ObserverMD(int NP)
{
	int i;
	MTMD = AvecTrace;
	CreerTableauInitialMD();
	AfficherMD();
	JouerUneMD(AvecTrace);
  for (i = 1; i <= NP-1; i++)
    {
      ReformerTableauInitialMD();
			AfficherMD();
      JouerUneMD(AvecTrace);1
1
    }
}


void AnalyserMD(int NP)
{
	int i;
	MTMD = SansTrace;
	CreerTableauInitialMD();
	JouerUneMD(SansTrace);

  for (i = 1; i <= NP-1; i++)
  {
    ReformerTableauInitialMD();
    JouerUneMD(SansTrace);
  }
	printf("Vous avez gagne %d fois \n", cptrGagne);

}
