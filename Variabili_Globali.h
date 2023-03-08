
#ifndef VARIABILI_GLOBALI_H_
#define VARIABILI_GLOBALI_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_R 17						//numero righe - intero
#define MAX_C 17						//numero colonne - intero

#define MARE '~'						//rappresenta il mare - carattere
#define NAVE '1'						//rappresenta la nave nel mare - carattere
#define COLPITO 'x' 					//cella contenente nave colpita - carattere
#define NON_COLPITO 'o' 				//bersaglio mancato - carattere
#define AFFONDATO 'Z'  					//cella contenente una nave colpita e affondata - carattere
#define MAGGIORE 'P'
#define MINORE 'A'

#define MAX_NAVE5 1  					//numero navi da 5 disponibile - intero
#define MAX_NAVE4 2  					//numero navi da 4 disponibile - intero
#define MAX_NAVE3 3  					//numero navi da 3 disponibile - intero
#define MAX_NAVE2 4  					//numero navi da 2 disponibile - intero
#define MAX_NAVE1 5  					//numero navi da 1 disponibile - intero
#define DIM_NAVE5 5  					//dimensione navi da 5 - intero
#define DIM_NAVE4 4  					//dimensione navi da 4 - intero
#define DIM_NAVE3 3  					//dimensione navi da 3 - intero
#define DIM_NAVE2 2  					//dimensione navi da 2 - intero
#define DIM_NAVE1 1  					//dimensione navi da 1 - intero
#define VERO 1							//indica il valore che assunto da un controllo in caso quest’ultimo sia positivo - intero
#define FALSO 0							//indica il valore che assunto da un controllo in caso quest’ultimo sia negativo - intero
#define INFERIORE 1						//prima riga della tabella inseribile dall'utente - intero
#define SUPERIORE 16					//max righe della tabella inseribile dall'utente - intero
#define MAX_BOMB 1						//numero massimo di bombardamenti utilizzabili - intero
#define MIN_TBOMB 10					//numero minimo di turni dopo il quale è possibile utilizzare il bombardamento - intero
#define MAX_LRAGGIO 3					//numero massimo colpi a largo raggio - intero
#define MAX_RADAR 3						//numero massimo di radar utilizzabili - intero
#define MAX_NAVI 30						//numero massimo di navi posizionate - intero




#endif /* VARIABILI_GLOBALI_H_ */
