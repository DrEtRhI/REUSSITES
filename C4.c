/* Les 4 couleurs */

#include <stdio.h>

#include "C4.h"

char TexteCouleurC4[5][8] = {"", "Trefle", "Carreau", "Coeur", "Pique"};

typedef Tas SerieCouleurC4;
SerieCouleurC4 LigneC4[DerniereCouleur+1];

/* Tableau de jeu */

/* localisation des tas */
Localisation LocSeriesC4[DerniereCouleur+1];

Tas TasgenereC4;

Localisation LocTasgenereC4;

void SaisirLocTasC4()
{
  int i;
	LocTasgenereC4.NC = 0;
	LocTasgenereC4.NL = 0;

  for (i=PremiereCouleur; i<=DerniereCouleur; i++)
    {
      LocSeriesC4[i].NC = 2*i+2;
      LocSeriesC4[i].NL = 1;
    }
}

void CreerTableauInitialC4()
{
  Couleur Co;
  int i;
  SaisirLocTasC4();

  /* Création du talon avec un jeu de 32 cartes et du rebut avec un tas vide */
  CreerJeuNeuf(32, LocTasgenereC4, &TasgenereC4);
  BattreTas(&TasgenereC4);

  /* Création des séries de chaque couleur et initialisation avec le sept */

  for (Co=PremiereCouleur; Co<=DerniereCouleur; Co++)
    {
      CreerTasVide(LocSeriesC4[Co], etale, &(LigneC4[Co]));
      for (i=1; i<=8; i++) {
		  DeplacerHautSur(&TasgenereC4,&(LigneC4[Co]));
	}
 
    }
}

void ReformerTableauInitialC4()
{
 
  /* que faut il faire exactement */
 CreerTableauInitialC4();
}




int JouerUneC4(ModeTrace MT) {
  Couleur Co1;
  Couleur Co2;
  Couleur Coul;
	
  /* Generation nbre entre 1 et 4 pour selection au hasard du premier tas */
  Co1 = UnEntier(4);

  /* Mecanique de jeu */
  while( TasDecouvert(LigneC4[Co1])==0 ) {
    RetournerCarteSur(&(LigneC4[Co1]));
    if (MT==AvecTrace) {AfficherC4();}
    Co2= LaCouleur(CarteSur(LigneC4[Co1]));
    DeplacerHautSous(&(LigneC4[Co1]), &(LigneC4[Co2]));
    Co1 =Co2;
    if (MT==AvecTrace) {AfficherC4();}
  }
  /* Fin partie, gagnée ou perdue */

  /* Retourne toutes les cartes encore cachées et dit si gagné */
  struct adCarte *pcarte;
  Coul = 1;
  int gagne;
  gagne = vrai;

  while (Coul<=4) {
  pcarte = LigneC4[Coul].tete;
    while(pcarte!=NULL) {
      if (pcarte->elt.CC != Coul) {gagne = faux; }
      pcarte->elt.VC =1;     
    pcarte = pcarte->suiv;
    }
  Coul=Coul+1;
  }
  if (MT==AvecTrace) {AfficherC4();}


if (gagne == faux)
{printf("Vous avez perdu\n");}
else {printf("Vous avez gagné\n");}

return gagne; 
}

int TasDecouvert(Tas untas){
  int i;
  i=1;
	
  while ( i <= LaHauteur(untas) && EstDecouverte(IemeCarte(untas, i) ) )
		{i = i+1; }
		
  return i > LaHauteur(untas);
}

void AfficherC4()
{
  Couleur Co;

  EffacerGraphique();
  AfficherTas(TasgenereC4, "Tas");

  for (Co=PremiereCouleur; Co<=DerniereCouleur; Co++)
    AfficherTas(LigneC4[Co], TexteCouleurC4[Co]);
	
  AttendreCliquer();
}

void ObserverC4(int NP)
{
  int i;
  int succes;

  CreerTableauInitialC4();
  AfficherC4();
  succes = JouerUneC4(AvecTrace);
 
  for (i = 1; i <= NP-1; i++)
    {
      ReformerTableauInitialC4();
      succes = JouerUneC4(AvecTrace);
    }
}


void AnalyserC4(int NP)
{
  int i;
  int succes;
  int cptrGagne = 0; /* Variable pour le nombre de parties gagnées */
  float cG; /* Variable recupérant le parsing de cptrGagne en float */

  CreerTableauInitialC4();
  succes = JouerUneC4(SansTrace);

  cptrGagne = cptrGagne + succes;

  for (i = 1; i <= NP-1; i++) {
    ReformerTableauInitialC4();
    succes = JouerUneC4(SansTrace);
    cptrGagne = cptrGagne + succes; 
    }

  cG = (float) cptrGagne;

  /* Affichage des différentes statistiques de la partie */	
  printf("Sur %d partie(s), vous en avez gagne %d\n", NP, cptrGagne);
  printf("Soit un pourcentage moyen de %d %% de victoire\n", cptrGagne * 100 / NP);	 
}
