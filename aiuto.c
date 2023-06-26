#include <stdio.h>
#include <stdlib.h>

#include "aiuto.h"


void aiuto()
{
       
	int scelta;
	char torna;
	do
	{
        system("cls");
        printf("\n AIUTO \n\n\n\n\n\n\n");
		
		printf("                              1) regole del gioco \n\n\n\n");
		printf("                              2) comandi del gioco \n\n\n\n\n\n");
		
		printf("\n\n\n 0) Ritorna al menu");
		
		printf("\n\n Effettua la tua scelta: ");
        scanf("%d",&scelta);

		/*Inizio struttura di controllo per permettere la scelta
		della funzione desiderabile, è possibile inserire altre funzioni*/
		
		if(scelta==1){ 
        system("cls");
        regolegioco();
		system("cls");	}
		
		if(scelta==2){ 
        system("cls");
        comandigioco();
		system("cls");	}
		
		if(scelta==3){ 
        system("cls");
        main();
		system("cls");	}
	
		printf("Si desidera tornare al Menu' Principale? \n\n");
		printf("[y] Si, desidero tornare al Menu' Principale       [n] No, desidero uscire \n\n");
		
		printf("Effettua la tua scelta: ");
		scanf("%s",&torna);
	}
	while (torna!='n');
	
}
	
		
void regolegioco()
{
	
	int scelta;
	char torna;
	do
	{
	
	
printf("\nAIUTO - REGOLE DEL GIOCO \n\n");	
		
FILE *fd;
  char buf[200];
  char *res;


		/* apre il file */
  fd=fopen("regole.txt", "r");
  if( fd==NULL ) {
    perror("Errore in apertura del file");
    exit(1);
  }


		/* legge e stampa ogni riga */
  while(1) {
    res=fgets(buf, 200, fd);
    if( res==NULL )
      break;
    printf("%s", buf);
  }

	
	printf("\n\n 0) Ritorna al menu: ");
	printf("\n\n Effettua la tua scelta: ");
    scanf("%d",&scelta);
		
		

		/*Inizio struttura di controllo per permettere la scelta
		della funzione desiderabile, è possibile inserire altre funzioni*/
		
			
		if(scelta==0){ 
        system("cls");
        main();
		system("cls");	}
		
		printf("Si desidera tornare al Menu' Principale? \n\n");
		printf("[y] Si, desidero tornare al Menu' Principale       [n] No, desidero uscire \n\n");
		
		printf("Effettua la tua scelta: ");
		scanf("%s",&torna);
	}
	while (torna!='n');
	
}	

void comandigioco()
{
		
	FILE *fr;
    char buf[200];
    char *res;	
	int scelta;
	char torna;
	
	do
	{
        printf("\n AIUTO - COMANDI DEL GIOCO \n\n");
		
		
		
		
		/* apre il file */
        fr=fopen("comandi.txt", "r");
        if( fr==NULL ) {
          perror("Errore in apertura del file");
          exit(1);
        }


		/* legge e stampa ogni riga */
    while(1) {
        res=fgets(buf, 200, fr);
        if( res==NULL )
           break;
           printf("%s", buf);
        }
		
		
		
		printf("\n \n \n \n \n \n\n\n 0) Ritorna al menu\n\n");
		
		scanf("%d",&scelta);
		
		

		/*Inizio struttura di controllo per permettere la scelta
		della funzione desiderabile, è possibile inserire altre funzioni*/
		
		if(scelta==0){ 
        system("cls");
        main();
		system("cls");	}
		printf("Si desidera tornare al Menu' Principale? \n\n");
		printf("[y] Si, desidero tornare al Menu' Principale       [n] No, desidero uscire \n\n");
		
		printf("Effettua la tua scelta: ");
		scanf("%s",&torna);
	}
	while (torna!='n');
		
		
}
