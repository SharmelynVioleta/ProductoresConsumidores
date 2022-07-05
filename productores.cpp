/*#include <stdio.h>
#include <thread>
#include <stdlib.h>

using namespace std;

void *productores(void *arg);
int numproductores;
int comida = 3500;
int estomagos[];
int comio = 0;
int comidaRestaurada = 2;
int derrochandoEnergia = 0;
pthread_mutex_t tenedor[5];

const char letras[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main(void)
{
	printf("Iniciando programa de productoress COmensales\n");
	printf("\tFILÓSOFOS:\n");
	printf("Ingrese el numero de productoress: ");
	scanf("%d", &numproductores);
	pthread_t productoress[numproductores];
	int id[5];
	int i;

	for (i = 0; i < numproductores; i++)
	{
		pthread_mutex_init(&tenedor[i], NULL);
	}
	for (i = 0; i < numproductores; i++)
	{
		id[i] = i + 1;
		pthread_create(&productoress[i], NULL, &productores, &id[i]);
	}
	printf("%d", numproductores);

	for (i = 0; i < numproductores; i++)
	{
		pthread_join(productoress[i], NULL);
	}

	return 0;
}

// El productores coge el tenedor, esta funcion obtiene el Nro del productores y el tenedor

void cogiendoTenedor(int a, int b)
{
	pthread_mutex_lock(&tenedor[b]);
	printf("El filósofo número %d está usando el tenedor %d \n", a, b);
}

// El productores suelta el tenedor, esta funcion obtiene el numero del tenedor a dejar

void soltarTenedor(int s1, int s2)
{
	pthread_mutex_unlock(&tenedor[s1]);
	pthread_mutex_unlock(&tenedor[s2]);
}

// El productores piensa, esta funcion manda a pensar al productores

void piensa(int n)
{

	printf("Al productores %d se le envio a pensar\n,", n);
	estomagos[n] -= 10;
	comio -= 10;
	derrochandoEnergia += 10;
	int aleatorio = rand() % 10;
	sleep(aleatorio);
}

// En esta función se halla la sección crítica

void comiendo(int arg)
{

	int t1 = arg - 2;
	int t2 = arg - 1;

	// Arreglando el deadlock

	if (t1 == -1)
	{
		t1 = t2;
		t2 = numproductores - 1;
	}

	cogiendoTenedor(arg, t1);
	cogiendoTenedor(arg, t2);

	printf("FILÓSOFO %d ESTA COMIENDO \n", arg);
	comida = comida - 50;
	estomagos[arg] += 50;
	comio += 50;

	// Se verifica si los recursos deben restaurarse

	if (comida == 0 && comidaRestaurada > 0)
	{
		printf("TOTAL COMIDA EN ESTOMAGOS %d ... \n", comio);
		printf("TOTAL DE ENERGIA DERROCHADA %d ...\n", derrochandoEnergia);
		printf("LA CANTIDAD QUE SE COMIO %d ...\n", comio + derrochandoEnergia);
		comida = 3500;
		printf("YEY,COMIDA RESTAURADA \n");
	}

	printf("Verificando elestomao del productores %d: %d ... \n", arg, estomagos[arg]);
	printf("Cantidad de comida que queda: %d ... \n", comida);
	soltarTenedor(t1, t2);
}

void *productores(void *arg)
{
	int arg2 = *((int *)arg);
	while (comida > 0)
	{
		piensa(arg2);
		comiendo(arg2);
	}
	return NULL;
}
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// gcc productores00.cpp -pthread

#define NUM_PRODUCTORES 2

const char letras[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void *productor(void *arg);

int main(void)
{
	pthread_t productores[NUM_PRODUCTORES];
	int identificadores[NUM_PRODUCTORES];

	int i;

	for (i = 0; i < NUM_PRODUCTORES; i++)
	{
		identificadores[i] = i;
		pthread_create(&productores[i], NULL, &productor, &identificadores[i]);
	}

	for (i = 0; i < NUM_PRODUCTORES; i++)
	{
		pthread_join(productores[i], NULL);
	}

	return 0;
}

void *productor(void *arg)
{
	int arg2 = *((int *)arg);
	int aleatorio;
	for (int i = 1; true; i++)
	{
		aleatorio = rand() % 26;
		printf("(%d) Productor-%d estoy produciendo : %c \n", i, arg2, letras[aleatorio]);
	}
}