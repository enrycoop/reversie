#include <stdio.h>
#include <stdlib.h>

#include "aiuto.h"
#include "carica_partita.h"
#include "impostazioni.h"
#include "nuova_partita.h"
#include "classifica.h"
#include "variabili_globali.h"

void impostazioni()
{   int scelta;
    char torna;
    
	
	 do
	{
        system("cls");
		printf("\n  \n\n\n");

		/*Inizio elenco delle funzioni disponibili in output*/
		printf(" 1)campo 4x4 \n\n");
		printf(" 2)campo 6x6 (default)\n\n");
		printf(" 3)campo 8x8 \n\n");
		
		/*fine elenco funzioni*/

		printf("\n\n Effettua la tua scelta: ");
		scanf("%d",&scelta);

		/*Inizio struttura di controllo per permettere la scelta
		della funzione desiderabile, è possibile inserire altre funzioni*/
	
    if(scelta==1){ 
        system("cls");
       dimensionescacchiera = 4;
		system("cls");	}
		
    if(scelta==2){ 
        system("cls");
        dimensionescacchiera = 6;
		system("cls");	}
		
	if(scelta==3){ 
        system("cls");
        dimensionescacchiera = 8;
		system("cls");	}
    
		printf("Si desidera tornare al Menu' Principale? \n\n");
		printf("[y] Si, desidero tornare al Menu' Principale       [n] No, desidero uscire \n\n");
		
		printf("Effettua la tua scelta: ");
		scanf("%s",&torna);
		main();
	}
	while (torna!='n');
}	
	



