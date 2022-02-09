/*
 * gerador.cpp
 *
 *  Created on: Feb 4, 2022
 *      Author: LENOVO
 */

#include "gerador.h"

gerador::gerador(unsigned int rate) {
	srand(time(NULL));
	// TODO Auto-generated constructor stub
	_rate = rate;
	_total_generated = 0;

}

void gerador::generate_vehicle(queue<Vehicle*> * fila){
	unsigned int created = rand()%_rate;
	_total_generated += created;

	while(created--)
		fila->push(new Vehicle());

}



gerador::~gerador() {
	// TODO Auto-generated destructor stub


}

