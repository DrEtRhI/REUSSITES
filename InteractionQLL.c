/*--------------------------------------------------------------*/
/* Reussites. Cecile Dumas, Catherine Parent, octobre 2005, 
   d'apres les algorithmes de Pierre-Claude Scholl              */
/*--------------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

/* Interaction avec l'utilisateur */

/* ----------------------------------------------------------
 * CONSTANTES 
 * ----------------------------------------------------------
*/

#define         NbMaxEssais              5 
#define         Invite                   "Votre Choix (? pour liste des commandes) : " 
#define         TexteSimulationQLL        '1' 
#define         TexteAnalyseQLL           '2' 
#define         TexteFin                  'F' 
#define         TexteAide                 '?' 

#define         TexteAnalyseSerieQLL           '3' 

/* -------------------------------------------------------------------
 * CodeCommande   : le type [SIMULQLL, ANALYSEQLL, FIN]
 * -------------------------------------------------------------------
*/

typedef enum {SIMULQLL, ANALYSEQLL, ANALYSESERIEQLL,FIN}     CodeCommande ;

/* -------------------------------------------------------------------
 *      INTERACTION
 *
 *      EstTexteCommande : un caract�re ---> un bool�en
 *      EcrireMenu       : une action
 *      SaisirCommande   : une action (le r�sultat : un CodeCommande)
 * -------------------------------------------------------------------
*/

void	LireCar (char	*c)
{	int l ;
	while (isspace ( l=getchar ())) ;  *c = l ; 
}

int EstTexteCommande (char c)
{
  return
    ((c == TexteSimulationQLL) ||
     (c == TexteAnalyseQLL) ||
		 (c == TexteAnalyseSerieQLL) ||
     (c == TexteFin)) ;
}

void EcrireMenu ()
{
  printf ("Tapez \n") ; 
  printf ("%c pour Simulation graphique de la reussite QLL, \n",TexteSimulationQLL) ; 
  printf (" %c pour Analyse d une serie de reussites QLL (sans affichage graphique), \n",TexteAnalyseQLL);
	printf (" %c pour Analyse de 200 tour de 20 000 reussites QLL (sans affichage graphique), \n",TexteAnalyseSerieQLL);
  printf (" %c pour Fin, \n",TexteFin);
  printf (" %c pour Aide.\n",TexteAide); 
}

void SaisirCommande (CodeCommande *CC) 
{
  char C  ;
  int  NbEssais ;

  printf (Invite) ; LireCar (&C) ;
  NbEssais = 0 ;
  while ((NbEssais < NbMaxEssais) && (! EstTexteCommande (C))) 
    {
      if (C == TexteAide) 
	{
	  EcrireMenu ()  ; 
	  LireCar (&C) ;
	}
      else 
	{
	  printf ("Commande incorrecte.");
	  NbEssais++ ;
	  if (NbEssais < NbMaxEssais)
	    {
	      printf (Invite) ; 
	      LireCar (&C) ;
	    } 
	}
    } 
  if (NbEssais == NbMaxEssais) 
    *CC = FIN  ;
  else switch (C)  
    {
    case TexteSimulationQLL : *CC = SIMULQLL ; break ;
    case TexteAnalyseQLL :    *CC = ANALYSEQLL ; break ;
		case TexteAnalyseSerieQLL :    *CC = ANALYSESERIEQLL ; break ;
    case TexteFin :          *CC = FIN ; break ;
    } 
} 
