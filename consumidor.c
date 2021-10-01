#include <mqueue.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#define BUF_SIZE 8192

mqd_t prod;
mqd_t prod2;
mqd_t prod3;
mqd_t prod4;
char cadena[BUF_SIZE];

int main (void)
{
	prod = mq_open("/productorUno", O_RDONLY);
	mq_receive(prod, cadena, BUF_SIZE, NULL);
	printf("Numeros primos: \n %s",cadena);
	mq_close(prod);
	
	printf("\n \n",cadena);
	prod2 = mq_open("/productorDos", O_RDONLY);
	mq_receive(prod2, cadena, BUF_SIZE, NULL);
	printf("Numeros pares: \n %s",cadena);
	mq_close(prod2);
	
	printf("\n \n",cadena);
	prod3 = mq_open("/productorTres", O_RDONLY);
	mq_receive(prod3, cadena, BUF_SIZE, NULL);
	printf("Numeros impares: \n %s",cadena);
	mq_close(prod3);
	
	printf("\n \n",cadena);
	prod4 = mq_open("/productorCuatro", O_RDONLY);
	mq_receive(prod4, cadena, BUF_SIZE, NULL);
	printf("Caracteres: \n %s",cadena);
	mq_close(prod4);
return 0;
}