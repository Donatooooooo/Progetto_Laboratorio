
#include <stdio.h>
#include <stdlib.h>
#include "Salvare_Partita.h"


/* Nome: Salva_file_partita
 * Descrizione: Salva su file le strutture dati giocatore date in input
 * INPUT: giocatore - partita del primo giocatore - record
		  doc_partita - punatatore_file
          nome_file - indica il percorso del file su cui salvare - stringa
 * OUTPUT: partita.txt - file di testo con i dati salvati - file di testo
 */
void Salva_file_partita(partita giocatore, char nome_file[]){
    FILE *doc_partita;
	doc_partita = fopen(nome_file,"w");

    if(doc_partita == NULL)
	{
        printf("Errore!\n");
	}
	else{
        fprintf(doc_partita,"%d\n", LeggereLRaggio(giocatore));
        fprintf(doc_partita,"%d\n", LeggereBomba(giocatore));
        fprintf(doc_partita,"%d\n", LeggereRadar(giocatore));

        printf("Scrittura avvenuta con successo\n");
    }

    fclose(doc_partita);
}


/* Nome: Salva_file_tabella
 * Descrizione: Salva su file la tabella data in input
 * INPUT: tabella - puntatore file
 * 		  tab - record contenente la tabella da salvare - record
 * 		  nome_file - indica il percorso del file su cui salvare - stringa
 * OUTPUT: tabella.txt - file di testo con i dati salvati - file di testo
 * LAVORO: i - contatore per le righe - intero
 * 		   j - contatore per le colonne - intero
 */
void Salva_file_tabella(tabella tab, char nome_file[]){
    FILE *tabella;
	tabella = fopen(nome_file,"w");

    int i;
    int j;

    if(tabella == NULL)
	{
        printf("Errore!\n");
	}
	else{
		i = 0;
        while(i < MAX_R){
        	j = 0;
            while(j < MAX_C){
                fprintf(tabella,"%c", LeggereValore(tab, i,j));
                j++;
            }
            i++;
        }

        printf("Scrittura avvenuta con successo\n");
    }

    fclose(tabella);
}


/* Nome: Salva_file_turni
 * Descrizione: Salva su file il turno del giocatore e conteggio turno del colpo Bombardamento Aereo
 * INPUT: turni.txt - file di testo in cui salvare i dati - file di testo
 * 		  turni - record contenente i turni - record
 * OUTPUT: turni.txt - file di testo con i dati salvati - file di testo
 * LAVORO: doc_partita - puntatore file
 */
void Salva_file_turni(turni turni){
    FILE *doc_partita;
	doc_partita = fopen("\\File\\turni.txt","w");

    if(doc_partita == NULL)
	{
        printf("Errore!\n");
	}
	else{
        fprintf(doc_partita,"%d\n", LeggereturnoGiocatore(turni));
        fprintf(doc_partita,"%d\n", LeggeretBomba(turni));

        printf("Scrittura avvenuta con successo\n");
    }

    fclose(doc_partita);
}


/* Nome: Salva_file_imb
 * Descrizione: Salva su file le strutture dati imbarcazione date in input come array di strutture dati
 * INPUT: array_imb - array delle imbarcazioni - array di record
		  doc_imb - punatatore_file
          nome_file - indica il percorso del file su cui salvare - stringa
 * OUTPUT: imbarcazioni.txt - file di testo con i dati salvati - file di testo
 * LAVORO: k - contatore per il numero delle nati - intero
 */
void Salva_file_imb(imbarcazione array_imb[], char nome_file[]){
    FILE *doc_imb;
    int k;
	doc_imb = fopen(nome_file,"w");

    if(doc_imb == NULL)
	{
        printf("Errore!\n");
	}
	else
	{
		k=0;
		while(k<MAX_NAVI)
		{
			fprintf(doc_imb,"%d\n", LeggerexImbarcazione(array_imb[k]));
			fprintf(doc_imb,"%d\n", LeggereyImbarcazione(array_imb[k]));
			fprintf(doc_imb,"%d\n", LeggereOImbarcazione(array_imb[k]));
	        fprintf(doc_imb,"%d\n", LeggereDimImbarcazione(array_imb[k]));
	        fprintf(doc_imb,"%d\n", LeggereAffondata(array_imb[k]));
	        k++;
		}

        printf("Scrittura avvenuta con successo\n");
    }

    fclose(doc_imb);
}

