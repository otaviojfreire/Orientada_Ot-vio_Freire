/*
 * ambienteobs.h
 *
 *  Created on: Feb 4, 2022
 *      Author: LENOVO
 */

#ifndef AMBIENTEOBS_H_
#define AMBIENTEOBS_H_

#include "ambienteobs.h"
#include "gerador.h"
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

class ambiente_obs {
public:
	ambiente_obs();
	int obs(queue<Vehicle*> * filaA,queue<Vehicle*> * filaB);
	virtual ~ambiente_obs();
};

#endif /* AMBIENTEOBS_H_ */
