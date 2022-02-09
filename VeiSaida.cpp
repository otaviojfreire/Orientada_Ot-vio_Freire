/*
 * VeiSaida.cpp
 *
 *  Created on: Feb 5, 2022
 *      Author: LENOVO
 */

#include "VeiSaida.h"
#include "gerador.h"
#include <iostream>

VeiSaida::VeiSaida(unsigned int saida) {
	// TODO Auto-generated constructor stub
	_saida = saida;
	_total_saida =0;

}

unsigned int VeiSaida::generate_saida(queue<Vehicle*> * fila){
	unsigned int created_saida= rand()%_saida;
	unsigned int tam=0;
	_total_saida += created_saida;

	tam = fila->size();
	if(tam<created_saida)
		created_saida = tam;

	while(created_saida--)
		fila->pop();

	return created_saida;






}

VeiSaida::~VeiSaida() {
	// TODO Auto-generated destructor stub
}

