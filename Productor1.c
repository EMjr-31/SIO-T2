#include <mqueue.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

mqd_t prod;
char cadena[1000] ;

int main ( )
{
	prod= mq_open("/productorUno", O_WRONLY | O_CREAT, 0664, NULL);
	int numeros[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499}; //numero primos
	int log=95;
	int pos;
	srand(time(NULL));
	char espacio[]="\t";	
    	char caracteres[21]; 
    	
	for(int i=0;i<20;i++)
	{
		pos=rand()%96;
		printf("%d",numeros[pos]);
		printf("\t");
		unsigned long long num = numeros[pos];
    		sprintf(caracteres, "%llu", num);
		strcat(cadena,caracteres);
		strcat(cadena,espacio);
	}
	mq_send(prod, cadena, strlen(cadena) + 1,0);
	mq_close(prod);
	return 0;
}

