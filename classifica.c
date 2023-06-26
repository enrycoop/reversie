#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "aiuto.h"
#include "classifica.h"


struct classe{
       char nome[50];
       int point;
       };
struct classe vincitori[9];
struct classe aux;

int classifica()
{
	system("color 0C");
    FILE *fc;
    
    if((fc = fopen("Classifica.txt","r")) == NULL)
    {printf("errore nel caricamento della classifica!");
    system("pause");
    main();}
    
    int i=0;
    
    while(!feof(fc))
    {
                    fscanf(fc,"%s %d ",&vincitori[i].nome,&vincitori[i].point);                  
                    i++;
                    }
    
    fclose(fc);
    
    int numero=i;
    i=0;
    int j,jmax;
    
    while(i<numero-1)
    {
                     j=i+1;
                     jmax=i;
                     
                     while(j<numero)
                     {
                                    if(vincitori[j].point<vincitori[jmax].point)
                                    {
                                                                                jmax = j;
                                                                                }
                                    
                                    j++;
                     }
                                    aux.point = vincitori[jmax].point;
                                    strcpy(aux.nome,vincitori[jmax].nome);
                                    vincitori[jmax].point = vincitori[i].point;
                                    strcpy(vincitori[jmax].nome,vincitori[i].nome);
                                    vincitori[i].point = aux.point;
                                    strcpy(vincitori[i].nome,aux.nome);
                                    
                                    i++;
    }
    system("cls");
    
    
       if((fc = fopen("Classifica.txt","w")) == NULL)
    {printf("errore nel caricamento della classifica!");
    system("pause");
    main();}
    
    i=11;
    
    while(i>1)
    {
                    fprintf(fc,"%s %d ",vincitori[i].nome,vincitori[i].point);                  
                    i--;
                    }
    
    fclose(fc);
    
    i=numero-1;
    while(i>=0)
    {
                   printf("    %s %d \n \n ",vincitori[i].nome,vincitori[i].point);
                   i--;
                   }
    system("pause");
    return 0;
}
