#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aiuto.h"
#include "campo_4x4.h"
#include "nuova_partita.h"
#include "classifica.h"
#include "variabili_globali.h"



struct classe{
       char nome[50];
       int point;
       };
struct classe vincitore;      



int giocatore4;
char MAT[4][4];
int inizializza4()
{
    int emptyspace;
    FILE *fp;
    
    if((fp = fopen("SalvaPartita4.txt","r")) == NULL)
      {printf("non ci sono salvataggi precedenti!");
      system("pause");
      main();}
      
      int ifile=0,jfile;
         
         while(ifile<4)
         {
                       jfile=0;
                       while(jfile<4)
                       {
                                     fscanf(fp,"%c",&MAT[ifile][jfile]);
                                     jfile++;
                                     }
                       ifile++;
                       }
         fscanf(fp,"%d",&emptyspace);
         
         fclose(fp);
      
         return emptyspace;  
          
}
void VisualizzaGrafica4(int X,int Y)
{
int n,m;

printf("   1   2   3   4 \n");



 n=0;
    while(n<4)
    {
        m=0;

            printf(" ------------------- \n");
            printf("%d",n+1);

            while(m<4)
            {


                               if((MAT[n][m] == ' ') && ((MAT[n-1][m-1] == 'X') || (MAT[n-1][m] == 'X') || (MAT[n-1][m+1] == 'X') || (MAT[n][m+1] == 'X') || (MAT[n+1][m+1] == 'X') || (MAT[n+1][m] == 'X') || (MAT[n+1][m-1] == 'X') || (MAT[n][m-1] == 'X') || (MAT[n-1][m-1] == 'O') || (MAT[n-1][m] == 'O') || (MAT[n-1][m+1] == 'O') || (MAT[n][m+1] == 'O') || (MAT[n+1][m+1] == 'O') || (MAT[n+1][m] == 'O') || (MAT[n+1][m-1] == 'O') || (MAT[n][m-1] == 'O')))
                {printf("| - ",MAT[n][m]);
                }else{
				if(MAT[n][m] == ' ')
				printf("| %c ",MAT[n][m]);
				
                               if(MAT[n][m] == 'X')
                               { printf("| %c ",MAT[n][m]);

                               }else{if(MAT[n][m] == 'O')
                               {
                               printf("| %c ",MAT[n][m]);
                               printf("");
                               }else{
                        printf("| %c ",MAT[n][m]);
                        } } }

                m=m+1;

                }printf("|");

                 printf("\n");
                n=n+1;
            }

            printf(" ------------------- \n");

return ;
}
int StampaFeedback4(char var)
{

//punteggio
int a,b,punt=0;
  printf("\n");

           a=0;
            while(a<4)
            {
                b=0;
                while(b<4)
                {
                    if(MAT[a][b] == var)
                    {punt= punt+1;}


                    b=b+1;
                }


                a=a+1;
            }

            return punt;
}

char cambioTurno4()
{
char valore;

          if(giocatore4 == 0)
            {
                   valore= 'X';
                   giocatore4 = 1;
            }
              else{
                   valore = 'O';
                   giocatore4 = 0;}

        printf("giocatore %d \n",giocatore4+1);

return valore;
}


int carica_4x4()
{
    int turni4;
turni4=inizializza4();
	FILE *fp;
    int x,y,i,j,punt1,punt2;
    
    char var;
    int u=9;
    
    int emptyspace=0;
   // emptyspace = inizializza4();
    
   

    do{
    var = cambioTurno4();

//stampa della grafica
    VisualizzaGrafica4( x, y);
// stampa punteggio x

    punt1 = StampaFeedback4('O');
    printf("Il punteggio di giocatore 1 e': %d \n",punt1);
     punt2 = StampaFeedback4('X');
    printf("Il punteggio di giocatore 2 e': %d\n",punt2);

// assegnazione dell'indirizzo delle coordinate
    printf("\npremi 9 per salvare la partita oppure 10 per tornare al menu'\n");
    
    printf("scegli la x: ");
    scanf("%d",&x);
    if(x == 10)
    main();
    if(x == 9)
    {
         if((fp = fopen("SalvaPartita.txt","w")) == NULL)
         {printf("errore nel caricamento del file!");
         system("pause");
         }
         
         int ifile=0,jfile;
         
         while(ifile<9)
         {
                       jfile=0;
                       while(jfile<9)
                       {
                                     fprintf(fp,"%c",MAT[ifile][jfile]);
                                     jfile++;
                                     }
                       ifile++;
                       }
          fprintf(fp," %d ",emptyspace);
          fprintf(fp," %d ",dimensionescacchiera);
         
         fclose(fp);
         main();
         }
    printf("scegli la y: ");
    scanf("%d",&y);

if (MAT[x-1][y-1] == ' ')   // controllo sulla posizione
{

	//controllo posioxione adiacente
	           if((MAT[x-2][y-2] == 'X') || (MAT[x-2][y-1] == 'X') || (MAT[x-2][y] == 'X') || (MAT[x-1][y] == 'X') || (MAT[x][y] == 'X') || (MAT[x][y-1] == 'X') || (MAT[x][y-2] == 'X') || (MAT[x-1][y-2] == 'X') || (MAT[x-2][y-2] == 'O') || (MAT[x-2][y-1] == 'O') || (MAT[x-2][y] == 'O') || (MAT[x-1][y] == 'O') || (MAT[x][y] == 'O') || (MAT[x][y-1] == 'O') || (MAT[x][y-2] == 'O') || (MAT[x-1][y-2] == 'O'))
               {MAT[x-1][y-1] = var;
                turni4++;}else{var = cambioTurno4x4();} ////////////////////////////////////////////////////////////////////////////////////////////////////




}else{var = cambioTurno4(); }

system("cls");
printf("rimangono %d turni \n",12-turni4);
int iterctrl = 0;
int indicex=0,indicey;
 int si =0;
 int scorrix,scorriy;
 int count;
do{

//cambio delle variabili e ricerca intelligente (da implementare 3 o 4 volte per un ottimizzazione )
indicex=0;
 si =0;  //'0' valore non trovato - '1' valore trovato
while(indicex < 4)
{
indicey=0;
     while(indicey <4)
     {


                   if(turni4 == 0){

             //ricerca intelligente del punteggio di 'O'

     if(MAT[indicex][indicey] == 'X')  //indicex ricerca una X su tutta la matrice, quando la trova incomicnia a fare tt i controlli(orrizontale, vertical, obliquo)
     {


            //Obliquo dall'alto a sinistra
           if(MAT[indicex-1][indicey-1] == 'O')
           {


               if(MAT[indicex +1][indicey+1] == 'O')
              { MAT[indicex][indicey] = 'O';}else{ // se non trova subito la x

              count=0;
              si=0;
              scorrix = indicex;
              scorriy = indicey;

              while((scorrix <4) && (scorriy<4) && (si==0) &&  (MAT[scorrix][scorriy] == 'X'))
              {
                    if((MAT[scorrix+1][scorriy+1] == 'O'))
                    {si=1;}else{count++;}
                    scorrix++;
                    scorriy++;
              }
              scorrix = indicex;
              scorriy = indicey;

              if(si == 1) //se trova di nuovo il 'O' cambia tutte le 'X' che stanno in mezzo
              {
              while(count>0)
              {
                  MAT[scorrix][scorriy] = 'O';
                  count--;
                  scorrix++;
                  scorriy++;
                  }
               }
               }


           }
     }

     //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
                             }else{  // else del turno

     if(MAT[indicex][indicey] == 'O')  //indicex ricerca una X su tutta la matrice, quando la trova incomicnia a fare tt i controlli(orrizontale, vertical, obliquo)
     {


            //Obliquo dall'alto a sinistra
           if(MAT[indicex-1][indicey-1] == 'X')
           {


               if(MAT[indicex +1][indicey+1] == 'X')
              { MAT[indicex][indicey] = 'X';}else{ // se non trova subito la x

              count=0;
              si=0;
              scorrix = indicex;
              scorriy = indicey;

              while((scorrix <4) && (scorriy<4) && (si==0) &&  (MAT[scorrix][scorriy] == 'O'))
              {
                    if((MAT[scorrix+1][scorriy+1] == 'X'))
                    {si=1;}else{count++;}
                    scorrix++;
                    scorriy++;
              }
              scorrix = indicex;
              scorriy = indicey;

              if(si == 1) //se trova di nuovo il 'O' cambia tutte le 'X' che stanno in mezzo
              {
              while(count>0)
              {
                  MAT[scorrix][scorriy] = 'X';
                  count--;
                  scorrix++;
                  scorriy++;
                  }
               }
               }


           }
     }
}
             //fine ricerca su asse y
           indicey++;
    }
           indicex++;
//fine ricerca su asse x
    }



//cambio delle variabili e ricerca intelligente (da implementare 3 o 4 volte per un ottimizzazione )
indicex=0;
 si =0;  //'0' valore non trovato - '1' valore trovato
while(indicex < 4)
{
indicey=0;
     while(indicey <4)
     {


                   if(turni4 == 0){

             //ricerca intelligente del punteggio di 'O'

     if(MAT[indicex][indicey] == 'X')  //indicex ricerca una X su tutta la matrice, quando la trova incomicnia a fare tt i controlli(orrizontale, vertical, obliquo)
     {


            //verticale dall'alto verso il basso
           if(MAT[indicex-1][indicey] == 'O')
           {


               if(MAT[indicex +1][indicey] == 'O')
              { MAT[indicex][indicey] = 'O';}else{ // se non trova subito la x

              count=0;
              si=0;
              scorrix = indicex;
              scorriy = indicey;

              while((scorrix <4) && (si==0) &&  (MAT[scorrix][scorriy] == 'X'))
              {
                    if((MAT[scorrix+1][scorriy] == 'O'))
                    {si=1;}else{count++;}
                    scorrix++;

              }
              scorrix = indicex;
              scorriy = indicey;

              if(si == 1) //se trova di nuovo il 'O' cambia tutte le 'X' che stanno in mezzo
              {
              while(count>0)
              {
                  MAT[scorrix][scorriy] = 'O';
                  count--;
                  scorrix++;

                  }
               }
               }


           }
     }

     //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
                             }else{  // else del turno

     if(MAT[indicex][indicey] == 'O')  //indicex ricerca una X su tutta la matrice, quando la trova incomicnia a fare tt i controlli(orrizontale, vertical, obliquo)
     {


            //Obliquo dall'alto a sinistra
           if(MAT[indicex-1][indicey] == 'X')
           {


               if(MAT[indicex +1][indicey] == 'X')
              { MAT[indicex][indicey] = 'X';}else{ // se non trova subito la x

              count=0;
              si=0;
              scorrix = indicex;
              scorriy = indicey;

              while((scorrix <4 && (si==0)) &&  (MAT[scorrix][scorriy] == 'O'))
              {
                    if((MAT[scorrix+1][scorriy] == 'X'))
                    {si=1;}else{count++;}
                    scorrix++;

              }
              scorrix = indicex;
              scorriy = indicey;

              if(si == 1) //se trova di nuovo il 'O' cambia tutte le 'X' che stanno in mezzo
              {
              while(count>0)
              {
                  MAT[scorrix][scorriy] = 'X';
                  count--;
                  scorrix++;

                  }
               }
               }


           }
     }
}
             //fine ricerca su asse y
           indicey++;
    }
           indicex++;
//fine ricerca su asse x
    }



//cambio delle variabili e ricerca intelligente (da implementare 3 o 4 volte per un ottimizzazione )
indicex=0;
 si =0;  //'0' valore non trovato - '1' valore trovato
while(indicex < 4)
{
indicey=0;
     while(indicey <4)
     {


                   if(turni4 == 0){

             //ricerca intelligente del punteggio di 'O'

     if(MAT[indicex][indicey] == 'X')  //indicex ricerca una X su tutta la matrice, quando la trova incomicnia a fare tt i controlli(orrizontale, vertical, obliquo)
     {


            //Obliquo dall'alto a sinistra
           if(MAT[indicex-1][indicey+1] == 'O')
           {


               if(MAT[indicex +1][indicey-1] == 'O')
              { MAT[indicex][indicey] = 'O';}else{ // se non trova subito la x

              count=0;
              si=0;
              scorrix = indicex;
              scorriy = indicey;

              while((scorrix <4) && (scorriy>0) && (si==0) &&  (MAT[scorrix][scorriy] == 'X'))
              {
                    if((MAT[scorrix+1][scorriy-1] == 'O'))
                    {si=1;}else{count++;}
                    scorrix++;
                    scorriy--;
              }
              scorrix = indicex;
              scorriy = indicey;

              if(si == 1) //se trova di nuovo il 'O' cambia tutte le 'X' che stanno in mezzo
              {
              while(count>0)
              {
                  MAT[scorrix][scorriy] = 'O';
                  count--;
                  scorrix++;
                  scorriy--;
                  }
               }
               }


           }
     }

     //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
                             }else{  // else del turno

     if(MAT[indicex][indicey] == 'O')  //indicex ricerca una X su tutta la matrice, quando la trova incomicnia a fare tt i controlli(orrizontale, vertical, obliquo)
     {


            //Obliquo dall'alto a sinistra
           if(MAT[indicex-1][indicey+1] == 'X')
           {


               if(MAT[indicex +1][indicey-1] == 'X')
              { MAT[indicex][indicey] = 'X';}else{ // se non trova subito la x

              count=0;
              si=0;
              scorrix = indicex;
              scorriy = indicey;

              while((scorrix <4) && (scorriy>0) && (si==0  &&  (MAT[scorrix][scorriy] == 'O')))
              {
                    if((MAT[scorrix+1][scorriy-1] == 'X'))
                    {si=1;}else{count++;}
                    scorrix++;
                    scorriy--;
              }
              scorrix = indicex;
              scorriy = indicey;

              if(si == 1) //se trova di nuovo il 'O' cambia tutte le 'X' che stanno in mezzo
              {
              while(count>0)
              {
                  MAT[scorrix][scorriy] = 'X';
                  count--;
                  scorrix++;
                  scorriy--;
                  }
               }
               }


           }
     }
}
             //fine ricerca su asse y
           indicey++;
    }
           indicex++;
//fine ricerca su asse x
    }



//cambio delle variabili e ricerca intelligente (da implementare 3 o 4 volte per un ottimizzazione )
indicex=0;
 si =0;  //'0' valore non trovato - '1' valore trovato
while(indicex < 4)
{
indicey=0;
     while(indicey <4)
     {


                   if(turni4 == 0){

             //ricerca intelligente del punteggio di 'O'

     if(MAT[indicex][indicey] == 'X')  //indicex ricerca una X su tutta la matrice, quando la trova incomicnia a fare tt i controlli(orrizontale, vertical, obliquo)
     {


            //Obliquo dall'alto a sinistra
           if(MAT[indicex][indicey-1] == 'O')
           {


               if(MAT[indicex][indicey+1] == 'O')
              { MAT[indicex][indicey] = 'O';}else{ // se non trova subito la x

              count=0;
              si=0;
              scorrix = indicex;
              scorriy = indicey;

              while((si==0) && (scorriy<4) &&  (MAT[scorrix][scorriy] == 'X') )
              {
                    if((MAT[scorrix][scorriy+1] == 'O') )
                    {si=1;
				
					}else{
					
					
					
					count++;}
                    scorriy++;
              }
              scorrix = indicex;
              scorriy = indicey;
              if(si == 0)
              {count=0;
			  }

              if(si == 1) //se trova di nuovo il 'O' cambia tutte le 'X' che stanno in mezzo
              {
              while(count>0)
              {
                  MAT[scorrix][scorriy] = 'O';
                  count--;

                  scorriy++;
                  }
               }
               }


           }
     }

     //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
                             }else{  // else del turno

     if(MAT[indicex][indicey] == 'O')  //indicex ricerca una X su tutta la matrice, quando la trova incomicnia a fare tt i controlli(orrizontale, vertical, obliquo)
     {


            //Obliquo dall'alto a sinistra
           if(MAT[indicex][indicey-1] == 'X')
           {


               if(MAT[indicex ][indicey+1] == 'X')
              { MAT[indicex][indicey] = 'X';}else{ // se non trova subito la x

              count=0;
              si=0;
              scorrix = indicex;
              scorriy = indicey;

              while((scorriy<4) && (si==0)  &&  (MAT[scorrix][scorriy] == 'O'))
              {
                    if((MAT[scorrix][scorriy+1] == 'X'))
                    {si=1;}else{count++;}

                    scorriy++;
              }
              scorrix = indicex;
              scorriy = indicey;

              if(si == 1) //se trova di nuovo il 'O' cambia tutte le 'X' che stanno in mezzo
              {
              while(count>0)
              {
                  MAT[scorrix][scorriy] = 'X';
                  count--;

                  scorriy++;
                  }
               }
               }


           }
     }
}
             //fine ricerca su asse y
           indicey++;
    }
           indicex++;
//fine ricerca su asse x
    }


iterctrl++;
}while(iterctrl<2);



}while(turni4 <12);
system("cls");


if (punt1>punt2)
{
    printf("il vincitore e' giocatore 1! con %d punti! \n",punt1);
    vincitore.point = punt1;
}else{
        printf("il vincitore e' giocatore 2! con %d punti! \n",punt2);
        vincitore.point = punt2;
}

printf("nome vincitore: ");
scanf("%s",&vincitore.nome);

FILE *fw;

if((fw = fopen("Classifica.txt","a")) == NULL)
{
       printf("errore nel caricamento della classifica! ");
       system("pause");
       main();       
       }
       
       fprintf(fw,"%s %d",vincitore.nome,vincitore.point);
       
       fclose(fw);





}


