/*
 * VeiSaida.cpp
 *
 *  Created on: Feb 5, 2022
 *      Author: LENOVO
 */

#include <iostream>
#include <queue>
#include <unistd.h>
#include "gerador.h"
#include "ambienteobs.h"
#include "VeiSaida.h"
#include <ctime>

VeiSaida::VeiSaida(unsigned int saida) {
	// TODO Auto-generated constructor stub
	_saida = saida;
	_total_saida =0;

}

unsigned int VeiSaida::generate_saida(queue<Vehicle*> * fila){
	unsigned int tam=0;
	unsigned int created_saida= rand()%_saida;
	tam = fila->size();
	if(tam<created_saida)
		created_saida = tam;
	unsigned int tx_saida=0;
	tx_saida += created_saida;

	Vehicle *pt;
	_total_saida += created_saida;




	while(created_saida--){
		pt = fila->front();
		fila->pop();
		delete pt;
	}


	return tx_saida;






}

VeiSaida::~VeiSaida() {
	// TODO Auto-generated destructor stub
}

