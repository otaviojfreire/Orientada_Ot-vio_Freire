/*
 * VeiSaida.h
 *
 *  Created on: Feb 5, 2022
 *      Author: LENOVO
 */

#ifndef VEISAIDA_H_
#define VEISAIDA_H_

#include <cstdlib>
#include <ctime>
#include <queue>
#include "gerador.h"
using namespace std;

class VeiSaida {
public:
	VeiSaida(unsigned int saida);
	unsigned int generate_saida(queue<Vehicle*> * fila);

	void set_saida(unsigned int saida){

			_saida = saida;

	}
	unsigned int  get_saida(){
		return _saida;
	}

	unsigned int total_saida(){
		return _total_saida;
	}


	virtual ~VeiSaida();

private:
	unsigned int _total_saida;
	unsigned int _saida;



};

#endif /* VEISAIDA_H_ */
