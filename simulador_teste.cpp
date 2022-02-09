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
#define X 200
#define A 10
#define B 10

using namespace std;

int main() {
	queue<Vehicle *> filaA;
	queue<Vehicle *> filaB;




	gerador geradorCarro(10);
	VeiSaida saida(20);
	ambiente_obs obs;

	unsigned int i =1, soma=0,m=1,x=0,a = A,b = B;

	while(a--)
		filaA.push(new Vehicle());
	while(b--)
		filaB.push(new Vehicle());



	cout << "Size FilaA: " << filaA.size() << endl;
	cout << "Size FilaB: " << filaB.size() << endl;
	cout << "Total de carros: " << geradorCarro.total_generated() << endl;

	while(m<=X){

		while (!filaA.empty()||!filaB.empty()) {

			x = obs.obs(&filaA, &filaB);
			if(x==0){

				geradorCarro.generate_vehicle(&filaA);
				geradorCarro.generate_vehicle(&filaB);
				saida.generate_saida(&filaA);
				cout << "Aberto A"<<endl;
				cout << "Size FilaA: " << filaA.size() << endl;
				cout << "Size FilaB: " << filaB.size() << endl;
				cout << "Total de carros: " << geradorCarro.total_generated() << endl;

				i++;


			}
			else{

				geradorCarro.generate_vehicle(&filaA);
				geradorCarro.generate_vehicle(&filaB);
				saida.generate_saida(&filaB);

				cout <<"Aberto B"<<endl;
				cout << "Size FilaA: " << filaA.size() << endl;
				cout << "Size FilaB: " << filaB.size() << endl;
				cout << "Total de carros: " << geradorCarro.total_generated() << endl;
				i++;

			}







		}
		soma +=i;
		i = 1;

		m++;

		gerador geradorCarro(10);
		VeiSaida saida(20);
		ambiente_obs obs;
		a = A;
		b = B;

		while(a--)
			filaA.push(new Vehicle());
		while(b--)
			filaB.push(new Vehicle());

	}
	cout << "Size FilaA: " << filaA.size() << endl;



	cout << "Size FilaB: " << filaB.size() << endl;

	cout << "Rendimento: "<<soma/m<<endl;

	return 0;
}



