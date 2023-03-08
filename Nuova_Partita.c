
#include <stdio.h>
#include <stdlib.h>
#include "Nuova_Partita.h"
#include "Giocare_Partita.h"


/* Nome: DisposizioneTabelleA
 * Descrizione: Scrive righe, colonne e la tabella inserendo le etichette tra le colonne (lettere), riempie poi lo spazio di gioco con '~'
 * INPUT: tab - tabella da inizializzare - record
 * OUTPUT: tab - tabella con campi inizializzati - record
 * LAVORO: i - contatore che scandisce la posizione tra le righe - intero - >=1
 * 		   j - contatore che scandisce la posizione tra le colonne - intero - >=1
 *         n - scandisce la posizione tra i caratteri (prima riga) - carattere
 */
void DisposizioneTabellaA(tabella * tab) {
	int i;
	int j;
	char n;
	ScrivereRighe(tab, MAX_R);
	ScrivereColonne(tab, MAX_C);

	i=1;
	while(i<LeggereRighe(*tab))
	{
		j=1;
		while(j<LeggereColonne(*tab))
		{
			ScrivereValore(tab, i, j, MARE);
			j++;
		}
		i++;
	}

		//etichetta le colonne
	j=0;
	n='A';
	while(j<LeggereColonne(*tab))
	{
	    ScrivereValore(tab, 0, j+1, n++);
	    j++;
	}

	return;
}


/* Nome: DisposizioneTabelleB
 * Descrizione: Scrive righe, colonne e la tabella inserendo le etichette tra le colonne (lettere) e riempie lo spazio rimanente con vuoto.
 * INPUT: tab - tabella da inizializzare - record
 * OUTPUT: tab - tabella con campi inizializzati - record
 * LAVORO: i - contatore che scandisce la posizione tra le righe - intero - >=1
 * 		   j - contatore che scandisce la posizione tra le colonne - intero - >=1
 *         n - scandisce la posizione tra i caratteri (prima riga) - carattere
 */
void DisposizioneTabellaB(tabella * tab) {
	int i;
	int j;
	char n;
	ScrivereRighe(tab, MAX_R);
	ScrivereColonne(tab, MAX_C);

		//riempie con lo spazio
	i=1;
	while(i<LeggereRighe(*tab))
	{
		j=1;
		while(j<LeggereColonne(*tab))
		{
			ScrivereValore(tab, i, j,' ');
			j++;
		}
		i++;
	}

		//etichetta le colonne
	j=0;
	n='A';
	while(j<LeggereColonne(*tab))
	{
	    ScrivereValore(tab, 0, j+1, n++);
	    j++;
	}

	return;
}


/* Nome: PosizionareNavi
 * Descrizione:	Richiama, per un numero di volte stabilito, la funzione per posizionare le navi.
 * INPUT: Tabella_player1a - record tabella del giocatore 1 che visualizza il proprio campo - record
 * 		  array - array contenente i record imbarcazione - record
 * 		  nNave - contatore delle imbarcazioni da modificare in array - intero
 * OUTPUT: nNavi - numero navi poszionate - intero
 * LAVORO: i - contatore che viene incrementato per raggiungere il numero delle costanti di riferimento - intero
 *
 */
int PosizionareNavi(tabella * tabella_player1a, imbarcazione *array, int nNave)
{
	int i;
	int nNavi;

	printf(" NAVI A DISPOSIZIONE:\n Nave da 5 blocchi X1\n Nave da 4 blocchi X2\n Nave da 3 blocchi X3\n Nave da 2 blocchi X4\n Nave da 1 blocco X5\n");
	printf("\n\n");

	nNavi=nNave;

	i=0;
	while(i<MAX_NAVE5)
	{
		StampaTabella(*tabella_player1a);
		printf("\nNave da 5\n");
		CaricareNave(tabella_player1a, array, nNavi, DIM_NAVE5);
	    i++;
	    nNavi++;
	}

	i=0;
	while(i<MAX_NAVE4)
	{
		StampaTabella(*tabella_player1a);
		printf("\nNave da 4\n");
		CaricareNave(tabella_player1a, array, nNavi, DIM_NAVE4);
	    i++;
	    nNavi++;
	}

	i=0;
	while(i<MAX_NAVE3)
	{
		StampaTabella(*tabella_player1a);
		printf("\nNave da 3\n");
		CaricareNave(tabella_player1a, array, nNavi, DIM_NAVE3);
	    i++;
	    nNavi++;
	}

	i=0;
	while(i<MAX_NAVE2)
	{
		StampaTabella(*tabella_player1a);
		printf("\nNave da 2\n");
		CaricareNave(tabella_player1a, array, nNavi, DIM_NAVE2);
		i++;
		nNavi++;
	}

	i=0;
	while(i<MAX_NAVE1)
	{
		StampaTabella(*tabella_player1a);
		printf("\nNave da 1\n");
		CaricareNave(tabella_player1a, array, nNavi, DIM_NAVE1);
		i++;
		nNavi++;
	}
	StampaTabella(*tabella_player1a);

	return nNavi;
}


/*	Nome: CaricareNave
 *  Descrizione: Carica una nave della dimensione data in input.
 *  INPUT:	tabella_player1a - record tabella del giocatore 1 che visualizza il proprio campo - record
 *  		cords - record delle coordinate x e y - record
 *  		orientamento - rappresenta l'orientamento della nave - intero
 *  		array - array contenente i record imbarcazione - record
 * 		  	nNave - contatore delle imbarcazioni da modificare in array - intero
 * 		  	dim - dimensione della nave - intero
 *  OUTPUT: Tabella_player1a - record tabella del giocatore 2 che visualizza il proprio campo - record
 *  LAVORO: contr -controlla l'andata a buon fine del posizionamento della nave -  intero - FALSO=negativo VERO=positivo
 *			contr2 - variabile a cui viene assegnato il valore della funzione ControlloIntornoNavi - intero
 *			contr3 - controlla che la nave venga inserita solo in un campo MARE - intero - FALSO=negativo VERO=positivo
 *			k - contatore per i cicli (confrontato alla dimensione dell'imbarcazione) - intero
 *			i - contatore per le righe - intero
 *			j - contatore per le colonne - intero
 */
void CaricareNave(tabella * tabella_player1a, imbarcazione *array, int nNave, int dim) {
	cords cords;
	int orientamento;
	int contr;
	int contr2;
	int contr3;
	int k;
	int i;
	int j;

	do {
		contr3=VERO;
		if(dim!=1)
		{
			printf("Scegliere orientamento nave:\n");
			printf(" - orientamento 1 destra\n - orientamento 2 sinistra\n - orientamento 3 sopra\n - orientamento 4 sotto\n");
			do{
				scanf("%d", &orientamento);
			} while(orientamento<=0 || orientamento>4);
		}

		do{
			contr=VERO;
			cords=GetCords(cords);
			i=LeggereCordsX(cords);
			j=LeggereCordsY(cords);
			if(LeggereValore(*tabella_player1a, i, j)!=MARE)
						{
			      			printf(" --- Blocco pieno! Sceglierne un altro blocco --- ");
			      			contr=FALSO;
						}
					if(dim==1)
					{
						contr2=ControlloIntornoNavi(dim, i, j, 1, *tabella_player1a);
					} else
					{
						contr2=ControlloIntornoNavi(dim, i, j, orientamento, *tabella_player1a);
					}
					if(contr2==FALSO)
					{
						printf(" --- Blocco pieno! Sceglierne un altro blocco --- ");
					}
		} while(contr==FALSO || contr2==FALSO);

		if(dim!=1)
		{
			ModificaImbarcazione(&array[nNave], i, j, orientamento, dim);

			k=1;
			if(orientamento==1)
			{
				while(k<=dim && contr3==VERO)
				{
					if(LeggereValore(*tabella_player1a, i, j)==MARE)
					{
						j++;
						k++;
						contr3=VERO;
					} else
					{
						contr3=FALSO;
					}
				}
				k=1;
				j=LeggereCordsY(cords);
				while(k<=dim && contr3==VERO)
				{
					ScrivereValore(tabella_player1a, i, j, NAVE);
					j++;
					k++;
				}
			}
			if(orientamento==2)
			{
				while(k<=dim && contr3==VERO)
				{
					if(LeggereValore(*tabella_player1a, i, j)==MARE)
					{
						j--;
						k++;
						contr3=VERO;
					} else
					{
						contr3=FALSO;
					}
				}
				k=1;
				j=LeggereCordsY(cords);
				while(k<=dim && contr3==VERO)
				{
					ScrivereValore(tabella_player1a, i, j, NAVE);
					j--;
					k++;
				}
			}
			if(orientamento==3)
			{
				while(k<=dim && contr3==VERO)
				{
					if(LeggereValore(*tabella_player1a, i, j)==MARE)
					{
						i--;
						k++;
						contr3=VERO;
					} else
					{
						contr3=FALSO;
					}
				}
				k=1;
				i=LeggereCordsX(cords);
				while(k<=dim && contr3==VERO)
				{
					ScrivereValore(tabella_player1a, i, j, NAVE);
					i--;
					k++;
				}
			}
			if(orientamento==4)
			{
				while(k<=dim && contr3==VERO)
				{
					if(LeggereValore(*tabella_player1a, i, j)==MARE)
					{
						i++;
						k++;
						contr3=VERO;
					} else
					{
						contr3=FALSO;
					}
				}
				k=1;
				i=LeggereCordsX(cords);
				while(k<=dim && contr3==VERO)
				{
					ScrivereValore(tabella_player1a, i, j, NAVE);
					i++;
					k++;
				}
			}
		} else
		{
			ModificaImbarcazione(&array[nNave], i, j, 1, dim);
			ScrivereValore(tabella_player1a, i, j, NAVE);
		}

		if(contr3==FALSO)
		{
			printf("\n");
			printf("SCEGLIERE UN ALTRO ORIENTAMENTO\n");
			printf("\n");
		}
	}while(contr3==FALSO);

	return;
}


/* Nome: ModificaImbarcazione
 * Descrizione: Scrive il record array dato in input
 * INPUT: array - vettore di imbarcazioni da riempire - record
 * 		  i - posizione sulle righe - intero
 * 		  j - posizione sulle colonne - intero
 * 		  orientamento - stabilisce su quale orientamento la nave si estende - intero
 * 		  dim - dimensione della nave - intero
 * OUTPUT: array - vettore con campi scritti - record
 */
void ModificaImbarcazione(imbarcazione * array, int i, int j, int orientamento, int dim)
{
	ScriverexImbarcazione(array, i);
	ScrivereyImbarcazione(array, j);
	ScrivereOImbarcazione(array, orientamento);
	ScrivereDimImbarcazione(array, dim);
	ScrivereAffondata(array, FALSO);

	return;
}

/* Nome:InizializzareTurni
 * Descrizione: Inizializza il record turni
 * INPUT: turni - record da inizializzare
 * OUTPUT: turni - record inizializzato
 */
void InizializzareTurni(turni *turni)
{
	ScrivereturnoGiocatore(turni, 1);
	ScriveretBomba(turni, 0);

	return;
}


/* Nome:InizializzareGiocatore
 * Descrizione: Inizializza il record giocatore dato in input
 * INPUT: giocatore - record da inizializzare
 * OUTPUT: giocatore - record inizializzato
 */
void InizializzareGiocatore(partita *giocatore)
{
	ScrivereLRaggio(giocatore, MAX_LRAGGIO);
	ScrivereBomba(giocatore, MAX_BOMB);
	ScrivereRadar(giocatore, MAX_RADAR);

	return;
}


/* Nome:ControlloIntornoNavi
 * Descrizione: Controlla, in base alle coordinate date in input, che nell - intorno non ci siano altre navi.
 * INPUT: Dim - dimensione della nave - intero
 *		  X - indica la riga - intero
 *		  Y - indica la colonna - intero
 *		  Orientamento - orientamento della nave (1 destra, 2 sinistra, 3 sopra, 4 sotto) - intero
 *		  tabella_player2a - tabella da esaminare dato dimensione, x, y e orientamento - record
 *
 * OUTPUT: contr - rappresenta il risultato del controllo - intero - VERO = positivo(zona libera), FALSO=negativo(zona occupata)
 * LAVORO: i - contatore per le righe - intero
 *		   j - contatore per le colonne - intero
 */
int ControlloIntornoNavi(int dim, int x, int y, int orientamento, tabella tabella_player1a){
	int contr;
	int i;
	int j;
	contr=VERO;
	if(orientamento==1)
	{
		i=0;
		while(i<3  && contr==VERO)
		{
			j=0;
			while(j<dim+2)
			{
				if(LeggereValore(tabella_player1a, x-1+i, y-1+j)==NAVE)
				{
					contr=FALSO;
				}
				j++;
			}
			i++;
		}
	}
	if(orientamento==2)
		{
			i=0;
			while(i<3  && contr==VERO)
			{
				j=0;
				while(j<dim+2)
				{
					if(LeggereValore(tabella_player1a, x-1+i, y+1-j)==NAVE)
					{
						contr=FALSO;
					}
					j++;
				}
				i++;
			}
		}
	if(orientamento==3)
		{
			i=0;
			while(i<dim+2  && contr==VERO)
			{
				j=0;
				while(j<3)
				{
					if(LeggereValore(tabella_player1a, x+1-i, y-1+j)==NAVE)
					{
						contr=FALSO;
					}
					j++;
				}
				i++;
			}
		}
	if(orientamento==4)
		{
			i=0;
			while(i<dim+2 && contr==VERO)
			{
				j=0;
				while(j<3)
				{
					if(LeggereValore(tabella_player1a, x-1+i, y-1+j)==NAVE)
					{
						contr=FALSO;
					}
					j++;
				}
				i++;
			}
		}

	return contr;
}
