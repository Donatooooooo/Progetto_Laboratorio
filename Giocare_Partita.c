
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Giocare_Partita.h"

/* Nome: GiocarePartita
 * Descrizione: Permette di giocare la partita scegliendo tra le varie azioni possibili
 * INPUT:  partita – record da cui estrarre il turno e la disponibilità delle variabili del primo giocatore – record
 *		   tabella_player1b – tabella in cui il primo giocatore vede il campo avversario con le zone colpite - record
 *		   tabella_player2a – tabella in cui il secondo giocatore vede il proprio campo con le navi posizionate - record
 *		   turni – record che indica il turno dei giocatori e i turni passati per rendere disponibile il bombardamento (minimo 10) – record
 * OUTPUT: contr_save – stabilisce se la partita deve essere salvata o meno – intero - =FALSO(partita non da salvare) =VERO (partita da salvare)
 * LAVORO: contr_avvio – stabilisce se l’azione del turno può essere eseguita o meno – intero – =VERO(Eseguibile) =FALSO(Non eseguibile)
 *		   contr_azione – stabilisce quale operazione di attacco è stata scelta dal giocatore – intero - =1(Colpo normale) =2(Colpo a largo raggio) =3(Radar) =4(Bombardamento aereo) =5(Salva partita)
 */
int GiocarePartita(partita *partita, tabella *tabella_player1b, tabella *tabella_player2a, turni *turni)
{
	int contr_avvio;
	int contr_azione;
	int contr_save;

	contr_avvio=FALSO;
	contr_save=FALSO;
	do
	{
		printf("Scrivere il numero dell'operazione desiderata: \n1: Colpo normale \n2: Colpo a largo raggio \n3: Radar \n4: Bombardamento aereo \n5: Salva partita");
		do
		{
			scanf("%d", &contr_azione);
		}while((contr_azione<1) || (contr_azione>5));

		//Colpo normale
		if(contr_azione==1)
		{
			ColpireNave(tabella_player1b, tabella_player2a);
			contr_avvio=VERO;
		}

		//Colpo a largo raggio
		if(contr_azione==2)
		{
			if(LeggereLRaggio(*partita)>0)
			{
				ColpoLRaggio(tabella_player1b, tabella_player2a);
				ModificaLRaggio(partita);
				contr_avvio=VERO;
			}
			else
			{
				printf("I colpi a largo raggio sono terminati");
			}
		}

		//Radar
		if(contr_azione==3)
		{
			if(LeggereRadar(*partita)>0)
			{
				Radar(tabella_player2a, tabella_player1b);
				ModificaRadar(partita);
				contr_avvio=VERO;
			}
			else
			{
				printf("I radar sono terminati");
			}
		}

		//BombardamentoAereo
		if(contr_azione==4)
		{
			if((LeggereBomba(*partita)==MAX_BOMB) && (LeggeretBomba(*turni)>=MIN_TBOMB))
			{
				BombardamentoAereo(tabella_player1b, tabella_player2a);
				ModificaBomba(partita);
				contr_avvio=VERO;
			}
			else
			{
				printf("I bombardamenti sono terminati o non sono disponibili");
			}
		}

		//Salva Partita
		if(contr_azione==5)
		{
			contr_save=VERO;
			contr_avvio=VERO;
		}
	}while(contr_avvio==FALSO);

	ScriveretBomba(turni, LeggeretBomba(*turni)+1);
	//DA CAMBIARE NELLO PSEUDO
	if(contr_save==FALSO)
	{
		ModificaTurno(turni);
	}

	return contr_save;
}


/* Nome: ControlloColpitoAffondato
 * Descrizione: Controlla se nella tabella ci siano navi colpite e affondate. In caso positivo le X vengono sostituite con AFFONDATO.
 * INPUT: 	tabella_player1a – tabella con il campo da gioco del giocatore – record
 * 			imbarcazione – record imbarcazione del giocatore – record
 * OUTPUT: 	tabella_player2b – modificata con le navi affondate - record
 * LAVORO:  i - contatore per le righe - intero
 * 			j - contatore per le colonne - intero
 * 		  	k – contatore per generare il ciclo - intero
 * 		  	contr – controllo per verificare se la nave è affondata o meno - intero
 * 		   	trovato - indica se il controllo continua a trovare parti colpite o meno - intero - VERO(1) o FALSO(0)
 */
void ControlloColpitoAffondato(tabella * tabella_player1a, tabella *tabella_player2b, imbarcazione *imbarcazione)
{
	int i;
	int j;
	int k;
	int contr;
	int trovato;

	if(LeggereAffondata(*imbarcazione)==FALSO)
	{
		k=0;
		i=LeggerexImbarcazione(*imbarcazione);
		j=LeggereyImbarcazione(*imbarcazione);
		trovato=VERO;
		contr=0;


		if(LeggereOImbarcazione(*imbarcazione)==1)
		{
			while(k<LeggereDimImbarcazione(*imbarcazione) && trovato==VERO)
			{
				if(LeggereValore(*tabella_player1a, i, j)==COLPITO)
				{
					contr++;
				}
				else
				{
					trovato=FALSO;
				}
				k++;
				j++;
			}
		}

		if(LeggereOImbarcazione(*imbarcazione)==2)
		{
			while(k<LeggereDimImbarcazione(*imbarcazione) && trovato==VERO)
			{
				if(LeggereValore(*tabella_player1a, i, j)==COLPITO)
				{
					contr++;
				}
				else
				{
					trovato=FALSO;
				}
				k++;
				j--;
			}
		}

		if(LeggereOImbarcazione(*imbarcazione)==3)
		{
			while(k<LeggereDimImbarcazione(*imbarcazione) && trovato==VERO)
			{
				if(LeggereValore(*tabella_player1a, i, j)==COLPITO)
				{
					contr++;
				}
				else
				{
					trovato=FALSO;
				}
				k++;
				i--;
			}
		}

		if(LeggereOImbarcazione(*imbarcazione)==4)
		{
			while(k<LeggereDimImbarcazione(*imbarcazione) && trovato==VERO)
			{
				if(LeggereValore(*tabella_player1a, i, j)==COLPITO)
				{
					contr++;
				}
				else
				{
					trovato=FALSO;
				}
				k++;
				i++;
			}
		}
	}

	if(contr==LeggereDimImbarcazione(*imbarcazione))
	{
	printf("Imbarcazione da %d affondata!", LeggereDimImbarcazione(*imbarcazione));
	ScrivereAffondata(imbarcazione, VERO);
	system("pause");
	k=0;
	i=LeggerexImbarcazione(*imbarcazione);
	j=LeggereyImbarcazione(*imbarcazione);
	if(LeggereOImbarcazione(*imbarcazione)==1)
	{
		while(k<LeggereDimImbarcazione(*imbarcazione))
			{
				ModificaTabella1a(tabella_player1a, i, j);
				ScrivereValore(tabella_player2b, i, j, AFFONDATO);
				k++;
				j++;
			}
		}

	if(LeggereOImbarcazione(*imbarcazione)==2)
		{
			while(k<LeggereDimImbarcazione(*imbarcazione))
			{
				ModificaTabella1a(tabella_player1a, i, j);
				ScrivereValore(tabella_player2b, i, j, AFFONDATO);
				k++;
				j--;
			}
		}

		if(LeggereOImbarcazione(*imbarcazione)==3)
		{
			while(k<LeggereDimImbarcazione(*imbarcazione))
			{
				ModificaTabella1a(tabella_player1a, i, j);
				ScrivereValore(tabella_player2b, i, j, AFFONDATO);
				k++;
				i--;
			}
		}

		if(LeggereOImbarcazione(*imbarcazione)==4)
		{
			while(k<LeggereDimImbarcazione(*imbarcazione))
			{
				ModificaTabella1a(tabella_player1a, i, j);
				ScrivereValore(tabella_player2b, i, j, AFFONDATO);
				k++;
				i++;
			}
		}
	}

	return;
}




/* Nome: ControlloFinePartita
 * Descrizione: Controlla che nella tabella in input non siano più presenti navi non colpite e quindi dichiara la fine della partita.
 * INPUT: tab - tabella da analizzare - record
 * OUTPUT: contr - afferma se ci sono ancora o no navi - intero - FALSO=navi presenti, VERO=navi colpite
 * LAVORO: i - contatore che scandisce la posizione tra le righe - intero - >=1
 *         j - contatore che scandisce la posizione tra le colonne - intero - >=1
 */
int ControlloFinePartita(tabella tab) {
	int contr;
	int i;
	int j;
	contr=VERO;

	i=1;
	while(i<=LeggereRighe(tab) && contr==VERO)
	{
		j=1;
	    while(j<LeggereColonne(tab) && contr==VERO)
	    {
	    	if(LeggereValore(tab, i,j)==NAVE)
	    	{
	    		contr=FALSO;
	    	}
	    	j++;
		}
	    i++;
	}

	return contr;
}

/* Nome: ColpoLRaggio
 * Descrizione: Oltre alla casella indicata (ovvero la casella centrale) ha effetto anche sulle caselle intorno (raggio 1 per un totale di 9 caselle). Massimo di colpi a largo raggio utilizzabili 3.
 * INPUT: tabella_player1b - record tabella del giocatore 1 che visualizza il campo nemico - record
 *		  tabella_player2a - record tabella del giocatore 2 che visualizza il proprio campo - record
 *		  cords - record che contiene le coordinate X e Y della tabella da prendere in considerazione - record
 * OUTPUT: tabella_player1b - record tabella del giocatore 1 che visualizza il campo nemico con le nuove zone colpite - record
 * LAVORO: nave_colpita – contatore per stabilire se si è colpita o meno una nave – intero
 *		   i – contatore per le righe – intero - >=0
 *         j – contatore per le colonne – intero - >=0
 */
void ColpoLRaggio(tabella *tabella_player1b, tabella *tabella_player2a)
{
	int nave_colpita;	//contatore per stabilire se si ï¿½ colpita o meno una nave ï¿½ intero
	int i;	//contatore per le righe ï¿½ intero - >=0
	int j;	//contatore per le colonne ï¿½ intero - >=0
	cords cords;	//record contenente X e Y - record

	nave_colpita=0;
	do
	{
		cords=GetCords(cords);
	}while(ControlloArea(LeggereCordsX(cords), LeggereCordsY(cords))==FALSO);

	i=0;
	while(i<3)
	{
		j=0;
		while(j<3)
		{
			if(LeggereValore(*tabella_player2a, LeggereCordsX(cords)-1+i, LeggereCordsY(cords)-1+j)==NAVE)
			{
				ModificaTabella2a(tabella_player2a, LeggereCordsX(cords)-1+i, LeggereCordsY(cords)-1+j);
				ScrivereValore(tabella_player1b, LeggereCordsX(cords)-1+i, LeggereCordsY(cords)-1+j, COLPITO);
				nave_colpita++;
			}
			else
			{
				if(LeggereValore(*tabella_player1b, LeggereCordsX(cords)-1+i, LeggereCordsY(cords)-1+j)!=COLPITO)
				{
					ScrivereValore(tabella_player1b, LeggereCordsX(cords)-1+i, LeggereCordsY(cords)-1+j, NON_COLPITO);
				}
			}
			j++;
		}
		i++;
	}

	if(nave_colpita>0)
	{
		printf("Colpito!");
	}
	else
	{
		printf("Mancato!");
	}

	return;
}

/* Nome: Radar
 * Descrizione: Scansiona, oltre alla casella indicata, un totale di 9 celle sulla tabella dell’avversario. Radar è utilizzabile per un massimo di 3 volte.
 * INPUT: tabella_player1b - record tabella del giocatore 1 che visualizza il campo nemico - record
 *		  tabella_player2a - record tabella del giocatore 2 che visualizza il proprio campo - record
 *		  cords - record che contiene le coordinate X e Y della tabella da prendere in considerazione - record
 * OUTPUT: tabella_player1b - record tabella del giocatore 1 che visualizza il campo nemico con le nuove zone scoperte - record
 * LAVORO: nave_spotted – contatore per stabilire se si è trovata o meno una nave – intero
 *		   i – contatore per le righe – intero - >=0
 *         j – contatore per le colonne – intero - >=0
 */
void Radar(tabella *tabella_player2a, tabella *tabella_player1b)
{
	int nave_spotted;
	int i;
	int j;
	cords cords;

	nave_spotted=0;
	do
	{
		cords=GetCords(cords);
	}while(ControlloArea(LeggereCordsX(cords), LeggereCordsY(cords))==FALSO);

	i=0;
	while(i<3)
	{
		j=0;
		while(j<3)
		{
			if(LeggereValore(*tabella_player2a, LeggereCordsX(cords)-1+i, LeggereCordsY(cords)-1+j)==NAVE)
			{
				nave_spotted++;
				ScrivereValore(tabella_player1b, LeggereCordsX(cords)-1+i, LeggereCordsY(cords)-1+j, NAVE);
			}
			j++;
		}
		i++;
	}

	if(nave_spotted>0)
	{
		printf("Nave trovata!");
	}
	else
	{
		printf("Nessuna nave trovata!");
	}

	return;
}

/* Nome: ControlloArea
 * Descrizione: Controlla che il colpo non prenda in considerazione la prima riga e la prima colonna (dove sono etichettate righe e colonne)
 * INPUT: coordinata_x - indica la riga della cella centrale da colpire - intero
 *		  coordinata_y - indica la riga della cella centrale da colpire - intero
 * OUTPUT: risultato - dice se il controllo ha dato esito positivo o negativo - intero -  VERO=positivo  FALSO=negativo
 */
int ControlloArea(int coordinata_x, int coordinata_y)
{
	int risultato;

	risultato=VERO;
	if(coordinata_x<2)
	{
		risultato=FALSO;
	}
	if(coordinata_y<2)
	{
		risultato=FALSO;
	}


	return risultato;
}

/* Nome: ColpireNave
 * Descrizione: A turno, i giocatori indicano una coppia di coordinate (x,y) da colpire sulla tabella dell’avversario. Se una casella che contiene una nave è centrata, viene esclamato “colpito” (incrementando il contatore colpi della nave), se è un colpo a vuoto “mancato”. In ogni caso viene segnata la coppia di coordinate (x,y) colpite sulla seconda tabella del giocatore che ha scagliato il colpo.
 * INPUT: tabella_player1b - record tabella del giocatore 1 che visualizza il campo nemico - record
 *		  tabella_player2a - record tabella del giocatore 2 che visualizza il proprio campo - record
 *		  cords - record che contiene le coordinate X e Y della tabella da prendere in considerazione - record
 * OUTPUT: tabella_player1b - record tabella del giocatore 1 che visualizza il campo nemico con le nuove zone colpite - record
 * LAVORO: colpi – contatore dei colpi a buon fine – intero - =FALSO o =VERO
 */
void ColpireNave(tabella *tabella_player1b, tabella *tabella_player2a)
{
	int colpi;
	cords cords;

	colpi=VERO;

	do
	{
		cords=GetCords(cords);
		if((LeggereValore(*tabella_player1b, LeggereCordsX(cords), LeggereCordsY(cords))==COLPITO) || (LeggereValore(*tabella_player1b, LeggereCordsX(cords), LeggereCordsY(cords))==NON_COLPITO))
		{
			printf("Cella gia colpita, riprovare");
			colpi=FALSO;
		}
		else
		{
			if(LeggereValore(*tabella_player2a, LeggereCordsX(cords), LeggereCordsY(cords))==NAVE)
			{
				ModificaTabella2a(tabella_player2a, LeggereCordsX(cords), LeggereCordsY(cords));
				ScrivereValore(tabella_player1b, LeggereCordsX(cords), LeggereCordsY(cords), COLPITO);
				printf("Nave colpita!");
				colpi=VERO;
			}
			else
			{
				ScrivereValore(tabella_player1b, LeggereCordsX(cords), LeggereCordsY(cords), NON_COLPITO);
				printf("Mancato!");
				colpi=VERO;
			}
		}
	}while(colpi==FALSO);

	return;
}

/* Nome: BombardamentoAereo
 * Descrizione: Dopo 10 tuni i giocatori possono scegliere di utilizzare il bombardamento aereo che colpirà un’intera riga o un’intera colonna a scelta dell’utente. Ogni giocatore ha a disposizione un unico utilizzo di bombardamento aereo.
 * INPUT: tabella_player1b - record tabella del giocatore 1 che visualizza il campo nemico - record
 *		  tabella_player2a - record tabella del giocatore 2 che visualizza il proprio campo - record
 *		  coordinata_x - indica la riga della cella centrale da colpire - intero
 *		  carattere_y - indica la colonna della cella centrale da colpire - intero
 * OUTPUT: tabella_player1b - record tabella del giocatore 1 che visualizza il campo nemico con le nuove zone colpite - record
 * LAVORO: coordinata_y - indica la colonna della tabella da colpire - intero
 * 		   tipologia - stabilisce se l'utente vuole colpire una riga(0) o una colonna(1) - intero
 * 		   scelta - valore della riga o della colonna - intero
 * 		   nave_colpita – contatore per stabilire se si è colpita o meno una nave – intero
 * 		   i - contatore per righe e colonne durante il bombardamento - intero
 */
void BombardamentoAereo(tabella *tabella_player1b, tabella *tabella_player2a)
{
	int coordinata_x;
	int coordinata_y;
	char carattere_y;
	int tipologia;
	int nave_colpita;
	int i;
	do
	{
		printf("Colpire riga(0) o colonna(1)?");
		scanf("%d", &tipologia);
	}while(tipologia<0 || tipologia>1);

	i=1;
	nave_colpita=0;

	//Righe
	if(tipologia==0)
	{
		printf("Inserire la riga da bombardare: \n");
		coordinata_x=LeggereInteroPositivo();

		while(i<LeggereColonne(*tabella_player2a))
		{
			if(LeggereValore(*tabella_player2a, coordinata_x, i)==NAVE)
			{
			ModificaTabella2a(tabella_player2a, coordinata_x, i);
			ScrivereValore(tabella_player1b, coordinata_x, i, COLPITO);
			nave_colpita++;
			}
			else
			{
			ScrivereValore(tabella_player1b, coordinata_x, i, NON_COLPITO);
			}
			i++;
		}
	}

	//Colonne
	else
	{
		printf("Inserire la colonna da bombardare: ");
		carattere_y=LeggereCarattere();
		coordinata_y=ConvertireColonna(carattere_y);

		while(i<LeggereRighe(*tabella_player2a))
		{
			if(LeggereValore(*tabella_player2a, i, coordinata_y)==NAVE)
			{
				ModificaTabella2a(tabella_player2a, i, coordinata_y);
				ScrivereValore(tabella_player1b, i, coordinata_y, COLPITO);
				nave_colpita++;
			}
			else
			{
				ScrivereValore(tabella_player1b, i, coordinata_y, NON_COLPITO);
			}
			i++;
		}

	}

	if(nave_colpita>0)
	{
		printf("Colpito!");
	}
	else
	{
		printf("Mancato!");
	}

	return;
}

/* Nome: ModificaTabella2a
 * Descrizione: Scrive un valore (COLPITO) all'interno della tabella data in input
 * INPUT: tabella_player2a - record in cui scrivere il nuovo valore - record
 * 		  x - riga del valore da modificare - intero
 * 		  y - colonna del valore da modificare - intero
 * OUTPUT: tabella_player2a - record con valore modificato - record
 */
void ModificaTabella2a(tabella *tabella_player2a, int x, int y)
{
	ScrivereValore(tabella_player2a, x, y, COLPITO);

	return;
}

/* Nome: ModificaTabella1a
 * Descrizione: Scrive un valore (AFFONDATO) all'interno della tabella data in input
 * INPUT: tabella_player1a - record in cui scrivere il nuovo valore - record
 * 		  x - riga del valore da modificare - intero
 * 		  y - colonna del valore da modificare - intero
 * OUTPUT: tabella_player1a - record con valore modificato - record
 */
void ModificaTabella1a(tabella *tabella_player1a, int x, int y)
{
	ScrivereValore(tabella_player1a, x, y, AFFONDATO);

	return;
}

/* Nome: ModificaLRaggio
 * Descrizione: Modifica il colpo a largo raggio, decrementandolo di 1
 * INPUT: partita - record in cui scrivere il nuovo valore - record
 * OUTPUT: partita - record con valore modificato - record
 */
void ModificaLRaggio(partita *partita)
{
	ScrivereLRaggio(partita, LeggereLRaggio(*partita)-1);

	return;
}


/* Nome: ModificaRadar
 * Descrizione: Modifica il Radar, decrementandolo di 1
 * INPUT: partita - record in cui scrivere il nuovo valore - record
 * OUTPUT: partita - record con valore modificato - record
 */
void ModificaRadar(partita *partita)
{
	ScrivereRadar(partita, LeggereRadar(*partita)-1);

	return;
}

/* Nome: ModificaBomba
 * Descrizione: Modifica il colpo Bomba, decrementandolo di 1
 * INPUT: partita - record in cui scrivere il nuovo valore - record
 * OUTPUT: partita - record con valore modificato - record
 */
void ModificaBomba(partita *partita)
{
	ScrivereBomba(partita, LeggereBomba(*partita)-1);

	return;
}

/*
 * Nome: StampaTabella
 * Descrizione: Stampa a schermo tutti i valori presenti nella tabella, etichettando le colonne
 * INPUT: tab - record tabella di cui stampare tutti gli elementi
 * OUTPUT: Stampa a video la tabella data in input
 * LAVORO: i - contatore delle righe della tabella - intero - >=0
 * 		   j - contatore delle colonne della tabella - intero - >=0
 * 		   k - etichetta le righe - intero
 */
void StampaTabella(tabella tab) {
	int i;
	int j;
	int k;

	k=0;
	i=0;
	while (i<LeggereRighe(tab))
	{
		j=1;
		if(k<10)
		{
			printf(" %d  ", k);
			k++;
		}
		else
		{
			printf(" %d ", k);
			k++;
		}
		while (j<LeggereColonne(tab))
		{

			printf(" %c ", LeggereValore(tab, i, j));
			j++;
		}
		i++;
		printf("\n");
	}
	return;
}


/* Nome: StampaSpazio
 * Descrizione: stampa lo spazio tra un turno e l'altro finche il valore dato in input si azzera.
 * INPUT: spazio - stabilisce quianto spazio stampare - intero
 * OUTPUT Stampa a video le andate a capo (spazio)
 */
void StampareSpazio(int spazio)
{
	while(spazio>0)
	{
		printf("\n");
		spazio--;
	}
	return;
}
