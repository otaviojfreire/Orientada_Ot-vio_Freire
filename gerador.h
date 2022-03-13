/*
 * gerador.h
 *
 *  Created on: Feb 4, 2022
 *      Author: LENOVO
 */



#ifndef GERADOR_H_
#define GERADOR_H_

#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

class Vehicle{
public:
	Vehicle(){
		created = time(NULL);
	}
	unsigned int elapsed(){
		return time(NULL) - created;
	}

private:
	  time_t created;
};

class gerador {
public:
	gerador(unsigned int rate);

	unsigned int generate_vehicle(queue<Vehicle *> * fila);


	void set_rate(unsigned int rate){

			_rate = rate;

	}
	unsigned int  get_rate(){
		return _rate;
	}


	unsigned int total_generated(){
		return _total_generated;
	}

	virtual ~gerador();

private:
	unsigned int _rate;
	unsigned int _total_generated;

};

#endif /* GERADOR_H_ */
