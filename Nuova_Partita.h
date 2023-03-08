
#ifndef NUOVA_PARTITA_H_
#define NUOVA_PARTITA_H_


#include "Variabili_Globali.h"
#include "Strutture_Dati_e_Funzioni_d'Accesso.h"

void DisposizioneTabellaA(tabella * tab);
void DisposizioneTabellaB(tabella * tab);
int PosizionareNavi(tabella * tabella_player1a, imbarcazione *array, int nNave);
void CaricareNave(tabella * tabella_player1a, imbarcazione *array, int nNave, int dim);
void InizializzareTurni(turni *turni);
void InizializzareGiocatore(partita *giocatore);
int ControlloIntornoNavi(int dim, int x, int y, int orientamento, tabella tabella_player1a);
void ModificaImbarcazione(imbarcazione * array, int i, int j, int orientamento, int dim);

#endif /* NUOVA_PARTITA_H_ */
