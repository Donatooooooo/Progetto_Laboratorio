
#include <stdio.h>
#include <stdlib.h>
#include "Strutture_Dati_e_Funzioni_d'Accesso.h"

//FUNZIONI SECONDARIE
int ConvertireColonna(char valoreColonna)
{
	char carattere;
	int c;
	int n;
	n=0;
	carattere='A';
	c=1;
	while(valoreColonna!=(carattere+n))
	{
		c++;
		n++;
	}

	return c;
}

char LeggereCarattere(){
	char carattere;
	do{
		printf("Inserire un carattere compreso tra A e P: ");
		scanf(" %c", &carattere);
	}while(carattere<MINORE || carattere>MAGGIORE);
	return carattere;
}


int LeggereInteroPositivo(){
	int valore;
	do {
		printf("Inserire il valore dell'intero maggiore di 1 e minore o uguale di 16: ");
		scanf("%d", &valore);
	} while(valore<INFERIORE || valore>SUPERIORE);

    return valore;
}

//FUNZIONI DI ACCESSO ALLA TABELLA
int LeggereRighe(tabella tabella)
{
	return tabella.righe;
}

void ScrivereRighe(tabella * t, int r)
{
	t->righe = r;
	return;
}

int LeggereColonne(tabella tabella)
{
	return tabella.colonne;
}

void ScrivereColonne(tabella * t, int c)
{
	t->colonne = c;
	return;
}

char LeggereValore(tabella tabella, int r, int c)
{
	char valore;	//singolo valore contenuto in due coordinate - carattere
	valore=tabella.valori[r][c];
	return valore;
}

void ScrivereValore(tabella * t, int r, int c, char v)
{
	t->valori[r][c] = v;
	return;
}

//FUNZIONI DI ACCESSO ALLA PARTITA
int LeggereLRaggio(partita p)
{
	int LargoRaggio;
	LargoRaggio = p.nLargoRaggio;
	return LargoRaggio;
}

void ScrivereLRaggio(partita *p, int valore)
{
	p->nLargoRaggio = valore;
	return;
}

int LeggereRadar(partita p)
{
	int Radar;
	Radar = p.nRadar;
	return Radar;
}


void ScrivereRadar(partita *p, int valore)
{
	p->nRadar = valore;
	return;
}

int LeggereBomba(partita p)
{
	int Bomba;
	Bomba = p.nBomb;
	return Bomba;
}


void ScrivereBomba(partita *p, int valore)
{
	p->nBomb = valore;
	return;
}

//FUNZIONI DI ACCESSO A TURNI
int LeggereturnoGiocatore(turni t)
{
	int turno;
	turno = t.turnoGiocatore;
	return turno;
}

void ScrivereturnoGiocatore(turni *t, int valore)
{
	t->turnoGiocatore = valore;
	return;
}

void ModificaTurno(turni *t)
{
	if(LeggereturnoGiocatore(*t) == 0)
	{
		ScrivereturnoGiocatore(t, 1);
	}
	else
	{
		ScrivereturnoGiocatore(t, 0);
	}
	return;
}

int LeggeretBomba(turni t)
{
	int tBomba;
	tBomba = t.tBomb;
	return tBomba;
}

void ScriveretBomba(turni *t,int valore)
{
	t->tBomb = valore;
	return;
}

//FUNZIONI DI ACCESSO A CORDS
cords GetCords(cords c)
{
	int y;
	printf("\nInserire la riga: \n");
	c=ScrivereCordsX(c, LeggereInteroPositivo());
	printf("\nInserire la colonna: \n");
	y = ConvertireColonna(LeggereCarattere());
	c=ScrivereCordsY(c, y);
	return c;
}

int LeggereCordsX(cords c)
{
	int cordX;
	cordX = c.X;
	return cordX;
}

cords ScrivereCordsX(cords c, int valore)
{
	c.X = valore;
	return c;
}

int LeggereCordsY(cords c)
{
	int cordY;
	cordY = c.Y;
	return cordY;
}

cords ScrivereCordsY(cords c, int valore)
{
	c.Y = valore;
	return c;
}

//FUNZIONI DI ACCESSO A IMBARCAZIONE
int LeggerexImbarcazione(imbarcazione imbarcazione)
{
	int x;
	x=imbarcazione.x;
	return x;
}

void ScriverexImbarcazione(imbarcazione *imbarcazione, int x)
{
	imbarcazione->x=x;
	return;
}

int LeggereyImbarcazione(imbarcazione imbarcazione)
{
	int y;
	y=imbarcazione.y;
	return y;
}

void ScrivereyImbarcazione(imbarcazione *imbarcazione, int y)
{
	imbarcazione->y=y;
	return;
}

int LeggereOImbarcazione(imbarcazione imbarcazione)
{
	int o;
	o=imbarcazione.orientamento;
	return o;
}

void ScrivereOImbarcazione(imbarcazione *imbarcazione, int o)
{
	imbarcazione->orientamento=o;
	return;
}

int LeggereDimImbarcazione(imbarcazione imbarcazione)
{
	int dim;
	dim=imbarcazione.dimensione;
	return dim;
}

void ScrivereDimImbarcazione(imbarcazione *imbarcazione, int dim)
{
	imbarcazione->dimensione=dim;
	return;
}

int LeggereAffondata(imbarcazione imbarcazione)
{
	int affondata;
	affondata=imbarcazione.affondata;
	return affondata;
}

void ScrivereAffondata(imbarcazione *imbarcazione, int affondata)
{
	imbarcazione->affondata=affondata;
	return;
}













