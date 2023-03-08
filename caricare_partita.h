
#ifndef CARICARE_PARTITA_H_
#define CARICARE_PARTITA_H_

#include "Variabili_Globali.h"
#include "Strutture_Dati_e_Funzioni_d'Accesso.h"

void Leggi_turni(turni* turno);
void Leggi_tabella(tabella* tab, char nome_file[]);
void Leggi_partita(partita* giocatore, char nome_file[]);
void Carica_file_regole();
void Leggi_imb(imbarcazione* array_imb, char nome_file[]);

#endif /* CARICARE_PARTITA_H_ */
