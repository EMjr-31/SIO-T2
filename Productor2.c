#include <mqueue.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

mqd_t prod;
char cadena[1000];

int main() {
	prod= mq_open("/productorDos", O_WRONLY | O_CREAT, 0664, NULL);
	int numero; //numero aleatorio
	int cont=0;//control de ciclo
	srand(time(NULL));
	char espacio[]="\t";	
    	char caracteres[21];
	do
	{
		numero=rand() %500;
		if (numero % 2 == 0) {
    			printf("%d",numero); //Mostramos si es par
    			cont++;
			printf("\t");
			unsigned long long num = numero;
    			sprintf(caracteres, "%llu", num);
			strcat(cadena,caracteres);
			strcat(cadena,espacio);
  		}
	}while(cont<20);
	mq_send(prod, cadena, strlen(cadena) + 1,0);
	mq_close(prod);
  	return 0;	
}