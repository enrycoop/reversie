#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "aiuto.h"
#include "carica_partita.h"
#include "impostazioni.h"
#include "nuova_partita.h"
#include "classifica.h"
#include "variabili_globali.h"

int main() 

{
	
	system("color 0A");
	int scelta;
	char torna;

	do
	{
        system("cls");
		printf("\n MENU' PRINCIPALE \n\n\n");

		/*Inizio elenco delle funzioni disponibili in output*/
		printf(" 1) Nuova Partita \n\n");
		printf(" 2) Carica Partita \n\n");
		printf(" 3) Modifica Impostazioni \n\n");
		printf(" 4) Classifica\n\n");
		printf(" 5) Aiuto \n\n\n\n");
		printf(" 6) Fine \n\n");
		/*fine elenco funzioni*/

		printf("\n\n Effettua la tua scelta: ");
		scanf("%d",&scelta);

		/*Inizio struttura di controllo per permettere la scelta
		della funzione desiderabile, è possibile inserire altre funzioni*/
		
		if(scelta==1){ 
        system("cls");
        nuova_partita();
		system("cls");}
        	
        if(scelta==2){ 
        system("cls");
        
        
        
       if(dimensionescacchiera==6)
       nuova_partita();
      else
      if(dimensionescacchiera==8)
      carica_8x8();
      else
       if(dimensionescacchiera==4)
        carica_4x4();
       else
       carica_partita();
        
        
		system("cls");	}
		
		if(scelta==3){ 
        system("cls");
        	impostazioni();
		system("cls");	}
		
		if(scelta==4){ 
            classifica();           
        system("cls");
         
		system("cls");	}
		
		if(scelta==5){ 
        system("cls");
        aiuto();
		system("cls");	}
		
		if(scelta==6){ 
        system("cls");
        uscita();
		system("cls");	}
        	
		
            system("cls");
				
			
			
		
		printf("Si desidera tornare al Menu' Principale? \n\n");
		printf("[y] Si, desidero tornare al Menu' Principale       [n] No, desidero uscire \n\n");
		
	printf("Effettua la tua scelta: ");
		scanf("%s",&torna);
	}
	while (torna!='n');
	

	return 0;
}


	
void uscita()
{
		exit(0);	
}



