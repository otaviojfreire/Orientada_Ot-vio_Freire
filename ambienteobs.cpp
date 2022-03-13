/*
 * ambienteobs.cpp
 *
 *  Created on: Feb 4, 2022
 *      Author: LENOVO
 */

#include "ambienteobs.h"
#include "gerador.h"
#include <cstdlib>
#include <ctime>
#include <queue>
#include <iostream>
using namespace std;

ambiente_obs::ambiente_obs() {
	// TODO Auto-generated constructor stub

}

int ambiente_obs::obs(queue<Vehicle*> * filaA,queue<Vehicle*> * filaB){


	if(filaA->size()>filaB->size()){

		return 0;
	}

	else if(filaB->size()>filaA->size()){

		return 1;
	}

	else{
		return rand()%2;
	}



}

ambiente_obs::~ambiente_obs() {
	// TODO Auto-generated destructor stub
}

