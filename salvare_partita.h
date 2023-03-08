
#ifndef SALVARE_PARTITA_H_
#define SALVARE_PARTITA_H_

#include "Variabili_Globali.h"
#include "Strutture_Dati_e_Funzioni_d'Accesso.h"

void Salva_file_partita(partita giocatore, char nome_file[]);
void Salva_file_tabella(tabella tab, char nome_file[]);
void Salva_file_turni(turni turni);
void Salva_file_imb(imbarcazione array_imb[], char nome_file[]);


#endif /* SALVARE_PARTITA_H_ */
