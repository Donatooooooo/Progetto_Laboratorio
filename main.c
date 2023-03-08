
#include <stdio.h>
#include <stdlib.h>

#include "Caricare_Partita.h"
#include "Variabili_Globali.h"
#include "Strutture_Dati_e_Funzioni_d'Accesso.h"
#include "Nuova_Partita.h"
#include "Giocare_Partita.h"
#include "Salvare_Partita.h"
#include "Caricare_Partita.h"


int main(void) {

	turni turni;						//turni che indicano di che giocatore è il turno  - record
	partita giocatore1;					//partita del primo giocatore - record
	partita giocatore2;					//partita del secondo giocatore - record
	tabella tabella_player1a;			//tabella del giocatore 2 che visualizza il proprio campo - record
	tabella tabella_player1b;			//tabella in cui il primo giocatore vede il campo avversario con le zone colpite - record
	tabella tabella_player2a;			//tabella in cui il secondo giocatore vede il proprio campo con le navi posizionate - record
	tabella tabella_player2b;			//tabella in cui il giocatore 2 vede il campo avversario
	imbarcazione array_imb[MAX_NAVI]; 	//array con i record imbarcazione

	int contr_partita;					//stabilisce se la partita è terminata o meno – intero - =VERO(Partita in corso) =FALSO (Partita terminata)
	int contr_gioco;					//stabilisce se il gioco va chiuso o no – intero - =VERO(continuare gioco) =FALSO (chiudere gioco)
	int contr_menu;						//stabilisce quale operazione del menù utilizzare – intero - =1(Nuova partita) =2(Carica Partita) =3(Regole) =4(Esci)
	int contr_save;						//stabilisce se la partita deve essere salvata o meno ï¿½ intero - =FALSO(partita non da salvare) =VERO (partita da salvare)
	int nNave;							//contatore delle imbarcazioni da modificare nell’array di record imbarcazione - intero
	int k;								//contatore usato per numerare i record imbarcazione per i controlli fine partita - intero


	contr_gioco=VERO;
	while(contr_gioco==VERO)
	{
		printf("-Menu' di gioco- \nScrivere il numero dell'operazione desiderata:\n1: Nuova Partita\n2: Carica Partita\n3: Regole\n4: Esci\n");

		do
		{
		scanf("%d", &contr_menu);
		}while((contr_menu<1) || (contr_menu>4));

		//Nuova partita
		if(contr_menu==1)
		{

			//Creazione e disposizione tabelle
			DisposizioneTabellaA(&tabella_player1a);
			DisposizioneTabellaA(&tabella_player2a);
			DisposizioneTabellaB(&tabella_player1b);
			DisposizioneTabellaB(&tabella_player2b);

			//Posizionamento Navi
			nNave=0;
			printf("\n\nIl giocatore 1 deve posizionare le sue navi \n");
			nNave=PosizionareNavi(&tabella_player1a, array_imb, nNave);
			system("pause");
			StampareSpazio(80);
			printf("Il giocatore 2 deve posizionare le sue navi \n");
			system("pause");
			StampareSpazio(80);
			nNave=PosizionareNavi(&tabella_player2a, array_imb, nNave);
			system("pause");

			//Salvataggio turni per i giocatori nei record partita(giocatore1), partita(giocatore2) e turni

			InizializzareTurni(&turni);
			InizializzareGiocatore(&giocatore1);
			InizializzareGiocatore(&giocatore2);

			//Inizio partita vera e propria
			contr_partita=VERO;
			do
			{
				contr_save=FALSO;
				if(LeggereturnoGiocatore(turni)==1)
				{
					//Turno giocatore1
					StampareSpazio(80);
					printf("Turno del giocatore 1\n");
					system("pause");
					StampareSpazio(80);

					printf("\nCampo alleato:\n");
					StampaTabella(tabella_player1a);
					printf("\nCampo nemico:\n");
					StampaTabella(tabella_player1b);

					contr_save=GiocarePartita(&giocatore1, &tabella_player1b, &tabella_player2a, &turni);
					system("pause");
				}
				else
				{
					//Turno giocatore2
					StampareSpazio(80);
					printf("Turno del giocatore 2\n");
					system("pause");
					StampareSpazio(80);

					printf("\nCampo alleato:\n");
					StampaTabella(tabella_player2a);
					printf("\nCampo nemico:\n");
					StampaTabella(tabella_player2b);

					contr_save=GiocarePartita(&giocatore2, &tabella_player2b, &tabella_player1a, &turni);
					system("pause");
				}

				if(contr_save==VERO)
				{
					//Salvataggio partita
					StampareSpazio(80);
					Salva_file_partita(giocatore1, "File\\partita1.txt");
					Salva_file_partita(giocatore2, "File\\partita2.txt");
					Salva_file_tabella(tabella_player1a, "File\\tab1a.txt");
					Salva_file_tabella(tabella_player1b, "\\File\\tab1b.txt");
					Salva_file_tabella(tabella_player2a, "\\File\\tab2a.txt");
					Salva_file_tabella(tabella_player2b, "\\File\\tab2b.txt");
					Salva_file_turni(turni);
					Salva_file_imb(array_imb, "\\File\\imb.txt");

					contr_partita=FALSO;
				}

				k=0;
				while(k<MAX_NAVI/2-1)
				{
					ControlloColpitoAffondato(&tabella_player1a, &tabella_player2b, &array_imb[k]);
					k++;
				}
				while(k<MAX_NAVI)
				{
					ControlloColpitoAffondato(&tabella_player2a, &tabella_player1b, &array_imb[k]);
					k++;
				}


				if(ControlloFinePartita(tabella_player1a)==VERO)
				{
					printf("Il giocatore 2 ha vinto!");
					contr_partita=FALSO;
				}
				else
				{
					if(ControlloFinePartita(tabella_player2a)==VERO)
					{
						printf("Il giocatore 1 ha vinto!");
						contr_partita=FALSO;
					}
				}
			}while(contr_partita==VERO);
		}

		//Carica partita
		if(contr_menu==2)
		{
			Leggi_turni(&turni);
			Leggi_partita(&giocatore1, "\\File\\partita1.txt");
			Leggi_partita(&giocatore2, "\\File\\partita2.txt");
			Leggi_tabella(&tabella_player1a,"\\File\\tab1a.txt");
			Leggi_tabella(&tabella_player1b,"\\File\\tab1b.txt");
			Leggi_tabella(&tabella_player2a,"\\File\\tab2a.txt");
			Leggi_tabella(&tabella_player2b,"\\File\\tab2b.txt");
			Leggi_imb(array_imb, "\\File\\imb.txt");

			contr_partita=VERO;
			do
			{
				contr_save=FALSO;
				if(LeggereturnoGiocatore(turni)==1)
				{
					//Turno giocatore1
					StampareSpazio(80);
					printf("Turno del giocatore 1\n");
					system("pause");
					StampareSpazio(80);

					printf("\nCampo alleato:\n");
					StampaTabella(tabella_player1a);
					printf("\nCampo nemico:\n");
					StampaTabella(tabella_player1b);

					contr_save=GiocarePartita(&giocatore1, &tabella_player1b, &tabella_player2a, &turni);
					system("pause");
				}
				else
				{
					//Turno giocatore2
					StampareSpazio(80);
					printf("Turno del giocatore 2\n");
					system("pause");
					StampareSpazio(80);

					printf("\nCampo alleato:\n");
					StampaTabella(tabella_player2a);
					printf("\nCampo nemico:\n");
					StampaTabella(tabella_player2b);

					contr_save=GiocarePartita(&giocatore2, &tabella_player2b, &tabella_player1a, &turni);
					system("pause");
				}

				if(contr_save==VERO)
				{
					//Salvataggio partita
					StampareSpazio(80);
					Salva_file_partita(giocatore1, "\\File\\partita1.txt");
					Salva_file_partita(giocatore2, "\\File\\partita2.txt");
					Salva_file_tabella(tabella_player1a, "\\File\\tab1a.txt");
					Salva_file_tabella(tabella_player1b, "\\File\\tab1b.txt");
					Salva_file_tabella(tabella_player2a, "\\File\\tab2a.txt");
					Salva_file_tabella(tabella_player2b, "\\File\\tab2b.txt");
					Salva_file_turni(turni);
					Salva_file_imb(array_imb, "File\\imb.txt");

					contr_partita=FALSO;
				}

				k=0;
				while(k<MAX_NAVI/2-1)
				{
					ControlloColpitoAffondato(&tabella_player1a, &tabella_player2b, &array_imb[k]);
					k++;
				}
				while(k<MAX_NAVI)
				{
					ControlloColpitoAffondato(&tabella_player2a, &tabella_player1b, &array_imb[k]);
					k++;
				}

				if(ControlloFinePartita(tabella_player1a)==VERO)
				{
					printf("Il giocatore 2 ha vinto!");
					contr_partita=FALSO;
				}
				else
				{
					if(ControlloFinePartita(tabella_player2a)==VERO)
					{
						printf("Il giocatore 1 ha vinto!");
						contr_partita=FALSO;
					}
				}
			}while(contr_partita==VERO);
		}

		//Regole
		if(contr_menu==3)
		{
			Carica_file_regole();
		}

		//Esci
		if(contr_menu==4)
		{
			contr_gioco=FALSO;
		}
	}

	return 0;
}

