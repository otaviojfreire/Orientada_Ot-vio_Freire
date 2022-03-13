/*
 * gerador.cpp
 *
 *  Created on: Feb 4, 2022
 *      Author: LENOVO
 */


#include <iostream>
#include <queue>
#include <unistd.h>
#include "gerador.h"
#include "ambienteobs.h"
#include "VeiSaida.h"
#include <ctime>

gerador::gerador(unsigned int rate) {

	// TODO Auto-generated constructor stub
	_rate = rate;
	_total_generated = 0;


}

unsigned int gerador::generate_vehicle(queue<Vehicle*> * fila){

	unsigned int created = rand()%_rate;
	unsigned int tx_entrada=0;
	tx_entrada += created;
	_total_generated += created;

	while(created--)
		fila->push(new Vehicle());
	return tx_entrada;

}



gerador::~gerador() {
	// TODO Auto-generated destructor stub


}

