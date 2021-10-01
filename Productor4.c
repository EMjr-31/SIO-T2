#include <mqueue.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

mqd_t prod;
char cadena[1000];

int main() {
	prod= mq_open("/productorCuatro", O_WRONLY | O_CREAT, 0664, NULL);
	srand(time(NULL));
	char espacio[]="\t";
	char caracteres[1];			
	for(int i=0;i<20;i++)
	{	
		char caracter='a' + rand() % (('z' - 'a') + 1);
		printf("%c", caracter);
		printf("\t");
		caracteres[0]=caracter;
		strcat(cadena,caracteres);
		strcat(cadena,espacio);
	}
	mq_send(prod, cadena, strlen(cadena) + 1,0);
	mq_close(prod);	
  	return 0;	
}