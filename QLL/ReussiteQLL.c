/*--------------------------------------------------------------*/
/* Reussites. Cecile Dumas, Catherine Parent, octobre 2005, 
   d'apres les algorithmes de Pierre-Claude Scholl              */
/*--------------------------------------------------------------*/

#include <stdio.h>

/* Programme principal */

#include "QLL.h"
#include "InteractionQLL.h"

/* -------------------------------------------------------------------
 *      PROGRAMME PRINCIPAL AVEC MENU D'INTERACTION
 * -------------------------------------------------------------------
 */
#define         TexteBienvenue           "Bienvenue \n" 
#define         TexteNbASimuler          "Choisissez le nombre de parties a simuler : "
#define         TexteNbAAnalyser         "Choisissez le nombre de parties a analyser : "
#define         TexteAuRevoir            "Au revoir \n" 
#define					TexteNbCartes						 "Combien de carte voulez vous 32 ou 52 ?? : "

int main(void)
{

  CodeCommande    Commande ;
  int nbparties ;
	int nbcartes ;
  InitAlea();
 
  printf (TexteBienvenue) ;
  SaisirCommande (&Commande) ;
  while (Commande != FIN) {
    switch  (Commande) {
    case SIMULQLL : 
      printf(TexteNbASimuler);
      scanf("%d",&nbparties);
			printf(TexteNbCartes);
			scanf("%d", &nbcartes);
			while (nbcartes != 32 && nbcartes != 52){
				printf("Nombre de cartes errone !!!");
				printf(TexteNbCartes);
				scanf("%d", &nbcartes);
			}
      OuvrirGraphique("QLL");
      ObserverQLL(nbparties, nbcartes);
      FermerGraphique();
      break ;

    case ANALYSEQLL :
      printf(TexteNbAAnalyser);
      scanf("%d",&nbparties);
			printf(TexteNbCartes);
			scanf("%d", &nbcartes);
			while (nbcartes != 32 && nbcartes != 52){
				printf("Nombre de cartes errone !!!");
				printf(TexteNbCartes);
				scanf("%d", &nbcartes);
			}
      AnalyserQLL(nbparties, nbcartes);
      break;
    } 
    SaisirCommande (&Commande) ;
    
  } 
  printf (TexteAuRevoir) ;
}
