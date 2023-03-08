
#ifndef STRUTTURE_DATI_E_FUNZIONI_D_ACCESSO_H_
#define STRUTTURE_DATI_E_FUNZIONI_D_ACCESSO_H_
#include "Variabili_Globali.h"

//STRUTTURE DATI MODULO

typedef struct
{
	char valori[MAX_R][MAX_C];	//I caratteri verranno modificati a seconda del loro contenuto (~=MARE, 1=NAVE, x=COLPITO, o=NON_COLPITO) - array bidimensionale di caratteri - 17x17
	int righe;	//righe della tabella - intero – MAX_R
	int colonne;	//colonne della tabella - intero – MAX_C
}tabella;

typedef struct
{
	int nLargoRaggio;	//stabilisce la quantità di colpi a largo raggio rimasti – intero - 0<=nLargoRaggio<=3
	int nBomb;	//stabilisce se il bombardamento aereo è stato utilizzato o meno e se è disponibile – intero - =0 (utilizzato) o =1 (non ancora utilizzato)
	int nRadar;	//stabilisce la quantità di utilizzi rimasti per il radar – intero - 0<=nRadar<=3
}partita;

typedef struct
{
	int turnoGiocatore;	//stabilisce a quale giocatore spetta colpire - intero - =0 (turno player 2) o =1 (turno player 1)
	int tBomb;	//conta quanti turni sono passati prima di poter utilizzare il bombardamento aereo (minimo 10) - 0>=tBomba
}turni;


typedef struct
{
	int X;	//indica la riga della tabella presa in considerazione – intero
	int Y;	//indica la colonna della tabella presa in considerazione – intero

}cords;


typedef struct
{
	int x;
	int y;
	int orientamento;
	int dimensione;
	int affondata;
}imbarcazione;

//FUNZIONI SECONDARIE
char LeggereCarattere();
int ConvertireColonna(char valoreColonna);
char LeggereValore(tabella tabella, int r, int c);

//FUNZIONI DI ACCESSO ALLA TABELLA
int LeggereRighe(tabella tabella);
void ScrivereRighe(tabella * t, int r);
int LeggereColonne(tabella tabella);
void ScrivereColonne(tabella * t, int c);
char LeggereValore(tabella tabella, int r, int c);
void ScrivereValore(tabella * t, int r, int c, char v);

//FUNZIONI DI ACCESSO ALLA PARTITA
int LeggereLRaggio(partita p);
void ScrivereLRaggio(partita *p, int valore);
int LeggereRadar(partita p);
void ScrivereRadar(partita *p, int valore);
int LeggereBomba(partita p);
void ScrivereBomba(partita *p, int valore);

//FUNZIONI DI ACCESSO A TURNI
int LeggereturnoGiocatore(turni t);
void ScrivereturnoGiocatore(turni *t, int valore);
void ModificaTurno(turni *t);
int LeggeretBomba(turni t);
void ScriveretBomba(turni *t,int valore);

//FUNZIONI DI ACCESSO A CORDS
cords GetCords(cords c);
int LeggereCordsX(cords c);
cords ScrivereCordsX(cords c, int valore);
int LeggereCordsY(cords c);
cords ScrivereCordsY(cords c, int valore);


//FUNZIONI DI ACCESSO A IMBARCAZIONE
int LeggerexImbarcazione(imbarcazione imbarcazione);
void ScriverexImbarcazione(imbarcazione *imbarcazione, int x);
int LeggereyImbarcazione(imbarcazione imbarcazione);
void ScrivereyImbarcazione(imbarcazione *imbarcazione, int y);
int LeggereOImbarcazione(imbarcazione imbarcazione);
void ScrivereOImbarcazione(imbarcazione *imbarcazione, int o);
int LeggereDimImbarcazione(imbarcazione imbarcazione);
void ScrivereDimImbarcazione(imbarcazione *imbarcazione, int dim);
int LeggereAffondata(imbarcazione imbarcazione);
void ScrivereAffondata(imbarcazione *imbarcazione, int affondata);

#endif /* STRUTTURE_DATI_E_FUNZIONI_D_ACCESSO_H_ */
