//============================================================================
// Name        : simulador_teste.cpp
// Author      : Otávio Augusto Joenck Freire
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <queue>
#include <unistd.h>
#include "gerador.h"
#include "ambienteobs.h"
#include "VeiSaida.h"
#include <ctime>
#define X 4
#define A 0
#define B 0

using namespace std;

int main() {
	srand(time(NULL));
	queue<Vehicle *> filaA;
	queue<Vehicle *> filaB;
	gerador geradorCarro(0);
	VeiSaida saida(0);
	ambiente_obs obs;
	int entrada_tx = 0, saida_tx=0;




	unsigned int i =1, soma_a=0,soma_b=0,m=1,x=0,a=0,b=0,sa=0,sb=0,saida_soma=0,entrada_soma;
	unsigned int saida_A = 0, saida_B=0,entrada_A=0,entrada_B=0;
	Vehicle *ref_a, *ref_b;



	while(m<=X){


		cout<<"Entre o valor limite de taxa de entrada: "<<endl;
		cin>>entrada_tx;
		cout<<"Entre o valor limite de taxa de saída: "<<endl;
		cin>>saida_tx;

		gerador geradorCarro(entrada_tx);
		VeiSaida saida(saida_tx);


		a = filaA.size();
		while(a--){

			ref_a = filaA.front();
			filaA.pop();
			delete ref_a;
		}

		b = filaB.size();
		while(b--){
			ref_b = filaB.front();
			filaB.pop();
			delete ref_b;
		}

		soma_a = 0;
		soma_b = 0;
		saida_soma = 0;
		entrada_soma = 0;
		saida_A = 0;
		saida_B = 0;
		entrada_A=0;
		entrada_B =0;
		i=1;
		entrada_A += geradorCarro.generate_vehicle(&filaA);
		entrada_B += geradorCarro.generate_vehicle(&filaB);
		cout<<"i: "<<i<<" A: "<<filaA.size()<< " B: "<<filaB.size()<<endl;

		while (i<=10) {

			x = obs.obs(&filaA, &filaB);
			if(x==0){

				saida_A += saida.generate_saida(&filaA);
				entrada_A +=geradorCarro.generate_vehicle(&filaA);
				entrada_B += geradorCarro.generate_vehicle(&filaB);



				soma_a += filaA.size();
				soma_b += filaB.size();

				cout<<"i: "<<i<<" Aberto A: "<<filaA.size()<< "Fechado B: "<<filaB.size()<<endl;


				i++;



			}
			else{

				saida_B +=saida.generate_saida(&filaB);
				entrada_A += geradorCarro.generate_vehicle(&filaA);
				entrada_B += geradorCarro.generate_vehicle(&filaB);



				soma_a += filaA.size();
				soma_b += filaB.size();

				cout<<"i: "<<i<<" Aberto B: "<<filaB.size()<<" Fechado A: "<<filaA.size()<<endl;

				i++;


			}








		}
		i = i -1;
		sa += soma_a/i;
		sb += soma_b/i;
		saida_soma =+ saida.total_saida();
		entrada_soma =+ geradorCarro.total_generated();

		m++;
		cout <<"Tentativa: "<<m<<" "<<" A: "<<(float)soma_a/(i)<<" B: "<<(float)soma_b/(i)<<endl;
		cout<<"Total Entrada A: "<<entrada_A<<" Total Entrada B: "<<entrada_B<<endl;;
		cout<<"Total Saida A: "<<saida_A<<" Total Saida B: "<<saida_B<<endl;;



	}




	cout <<"Média Geral: "<<m<<" "<<" A:"<<(float)sa/m<<" B:"<<(float)sb/m<<endl;
	cout<<"Total Saida: "<<(float)saida_soma<<" Total Entrada: "<<(float)entrada_soma<<endl;

	return 0;
}



