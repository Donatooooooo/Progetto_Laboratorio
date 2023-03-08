
#include <stdio.h>
#include <stdlib.h>
#include "Caricare_Partita.h"


/* Nome: Leggi_turni
 * Descrizione: Scrive i valori letti da file all'interno del record turni.
 * INPUT: turni - record in cui inserire i valori
 * 		  turni.txt - file di testo da cui lehhere i dati - file di testo
 * OUTPUT: turni - record con campi scritti - record
 * LAVORO: turnoGiocatore - intero da scrivere nel record turni - intero
 *		   tBomb - intero da scrivere nel record turni - intero
 *		   doc_partita - puntatore file
 */
void Leggi_turni(turni* turni){
    FILE *doc_partita;
    int turnoGiocatore;
    int tBomb;

	doc_partita = fopen("\\File\\turni.txt","r");

    if (doc_partita == NULL){
        printf("File non trovato!\n");
    }
    else{
        fscanf(doc_partita,"%d", &turnoGiocatore);
        fscanf(doc_partita,"%d", &tBomb);

        ScrivereturnoGiocatore(turni, turnoGiocatore);
        ScriveretBomba(turni, tBomb);

        fclose(doc_partita);
    }
}


/* Nome: Leggi_tabella
 * Descrizione: Scrive i valori letti da file all'interno del campo valori di tabella. Scrive inoltre campo righe e campo colonne.
 * INPUT:  tab - record in cui scrivere i valori - record
 *         nome_file - indica il percorso del file da leggere - stringa
 * 		   tabella - puntatore file
 * OUTPUT: tab - record con campi scritti - record
 * LAVORO: i - contatore per le righe - intero
 * 		   j - contatore per le colonne - intero
 * 		   temp - contiene l'elemento letto da file - carattere
 */
void Leggi_tabella(tabella* tab, char nome_file[]){
	FILE *tabella;
	tabella = fopen(nome_file,"r");

	int i;
	int j;
	char temp = ' ';

	ScrivereRighe(tab, MAX_R);
	ScrivereColonne(tab, MAX_C);

	if(tabella == NULL)
	{
		printf("Errore!\n");
	}
	else{
		i = 0;
		while(i < MAX_R){
			j = 0;
			while(j < MAX_C){
				fscanf(tabella,"%c", &temp);
				ScrivereValore(tab, i, j, temp);
				j++;
			}
			i++;
		}
		printf("Tabella caricata con successo.\n\n");
	}

	fclose(tabella);
}


/* Nome: Leggi_partita
 * Descrizione: Legge dal file dato in input i dati che va a scrivere nel record dato in input
 * INPUT: doc_partita - punattore file
 * 		  nome_file - indica il percorso del file da leggere - stringa
 * 		  giocatore - record a cui assegnare i valori - record
 * OUTPUT: giocatore - record con valori assegnati - record
 *
 */
void Leggi_partita(partita* giocatore, char nome_file[]){
    FILE *doc_partita;
	doc_partita = fopen(nome_file,"r");

    if (doc_partita == NULL){
        printf("File non trovato!\n");
    }
    else{
        fscanf(doc_partita,"%d", &giocatore->nLargoRaggio);
        fscanf(doc_partita,"%d", &giocatore->nBomb);
        fscanf(doc_partita,"%d", &giocatore->nRadar);

        fclose(doc_partita);
    }
}


/* Nome: Carica_file_regole
 * Descrizione: Stampa a Video il file di testo contenti le regole della battaglia navale
 * INPUT: regole.txt - file di testo da cui leggere le regole - file di testo
 * OUTPUT: Stampa a Video delle regole
 * LAVORO: c - vettore di caratteri
 */
void Carica_file_regole()
{
	FILE *regole;
	char c[100];

	printf("\n");
	regole=fopen("C:\\Users\\donat\\eclipse-workspace\\GRUPPO 15\\Debug\\regole.txt", "r");
	if(regole==NULL)
	{
		printf("Errore nell'apertura del file");
 	} else
 	{
 		while(!feof(regole))
 		{
 			fgets(c, 100, regole);
 			printf("%s", c);
 		}
 	}
	printf("\n");
    fclose(regole);
	return;
}

/* Nome: Leggi_imb
 * Descrizione: Legge dal file dato in input i dati che va a scrivere nel record dato in input
 * INPUT: doc_imb - puntatore file
 * 		  nome_file - indica il percorso del file da leggere - stringa
 * 		  array_imb - array di record a cui assegnare i valori - array di record
 * 		  array1 - per ogni ciclo, contiene i valori letti da file - record
 * OUTPUT: array_imb - array di record con valori assegnati - array di record
 * LAVORO: k - contatore per il numero navi - intero
 */
void Leggi_imb(imbarcazione* array_imb, char nome_file[]){

	imbarcazione *array1;
	FILE *doc_imb;
    int k;
	doc_imb = fopen(nome_file,"r");

    if (doc_imb == NULL){
        printf("File non trovato!\n");
    }
    else
    {

    	k=0;
    	while(k<MAX_NAVI)
    	{
    		array1=array_imb;
    		fscanf(doc_imb,"%d", &array1[k].x);
    		fscanf(doc_imb,"%d", &array1[k].y);
    		fscanf(doc_imb,"%d", &array1[k].orientamento);
    		fscanf(doc_imb,"%d", &array1[k].dimensione);
    		fscanf(doc_imb,"%d", &array1[k].affondata);
    		k++;
    	}
    	array_imb=array1;

        fclose(doc_imb);
    }
}


