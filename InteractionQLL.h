/*--------------------------------------------------------------*/
/* Reussites. Cecile Dumas, Catherine Parent, octobre 2005, 
   d'apres les algorithmes de Pierre-Claude Scholl              */
/*--------------------------------------------------------------*/


/* Interaction avec l'utilisateur */

/* -------------------------------------------------------------------
 * CodeCommande   : le type [SIMULQLL, ANALYSEQLL, FIN]
 * -------------------------------------------------------------------
*/

typedef enum {SIMULQLL, ANALYSEQLL, ANALYSESERIEQLL, FIN}     CodeCommande ;

void SaisirCommande (CodeCommande *);
