#include <stdio.h>
#include <pthread.h>

#define ROZMIAR 10

int dane[ROZMIAR];
int wyniki[2];

typedef struct{
	int start;
	int end;
	int thread_id;
}ParametryWatek;

void* sumujFragment(void* arg){
	
	ParametryWatek* par = (ParametryWatek*) arg;

	int suma = 0;
	
	for(int i = par->start;i<par->end;i++){
		suma+=dane[i];
	}
	
	wyniki[par->thread_id] = suma;
	return NULL;
}

int main(){
	for(int i = 0; i < ROZMIAR; i++){
		dane[i] = i + 1;
	}
	int srodek = ROZMIAR / 2;
	ParametryWatek p1 = {0,srodek,0};
	ParametryWatek p2 = {srodek, ROZMIAR, 1};

	pthread_t t1, t2;
	pthread_create(&t1, NULL, sumujFragment, &p1);
	pthread_create(&t2, NULL, sumujFragment, &p2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	int suma_calkowita = wyniki[0]+wyniki[1];
	printf("Wyniki watku 1: %d\n", wyniki[0]);
	printf("Wyniki watku2 : %d\n", wyniki[1]);
	printf("Suma koncowa: %d\n", suma_calkowita);

	return 0;
}
