
#ifndef GIOCARE_PARTITA_H_
#define GIOCARE_PARTITA_H_
#include "Variabili_Globali.h"
#include "Strutture_Dati_e_Funzioni_d'Accesso.h"


int GiocarePartita(partita *partita, tabella *tabella_player1b, tabella *tabella_player2a, turni *turni);
void ControlloColpitoAffondato(tabella * tabella_player2a, tabella *tabella_player2b, imbarcazione *imbarcazione);
int ControlloFinePartita(tabella tab);
void ColpoLRaggio(tabella *tabella_player1b, tabella *tabella_player2a);
void Radar(tabella *tabella_player2a, tabella *tabella_player1b);
int ControlloArea(int coordinata_x, int coordinata_y);
void ColpireNave(tabella *tabella_player1b, tabella *tabella_player2a);
void BombardamentoAereo(tabella *tabella_player1b, tabella *tabella_player2a);
void ModificaTabella2a(tabella *tabella_player2a, int x, int y);
void ModificaTabella1a(tabella *tabella_player1a, int x, int y);
void ModificaLRaggio(partita *partita);
void ModificaRadar(partita *partita);
void ModificaBomba(partita *partita);
void StampaTabella(tabella tab);
void StampareSpazio(int spazio);

#endif /* GIOCARE_PARTITA_H_ */
