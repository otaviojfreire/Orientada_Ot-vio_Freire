//============================================================================
// Name        : projeto_final_orientada.cpp
// Author      : Otávio Augusto Joenck Freire
// Version     :
// Copyright   : Your copyright notice
// Description : Controlador de Semáforo com dados aleatórios.
//Política de sinal aberto para o maior tamanho de fila e analisando
//o tipo de veículo presente na fila
//============================================================================

#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;
int carro_A = 0;
int carro_B = 0;
int tx_A_car =0,tx_A_caminhao=0,tx_A_moto=0;
int tx_B_car=0,tx_B_caminhao =0,tx_B_moto=0;
int in_A_car=0,in_A_caminhao=0,in_A_moto=0;
int in_B_car=0,in_B_caminhao=0,in_B_moto=0;
char acao[15];
int car_A=0, car_B=0;
int caminhao_A=0,caminhao_B=0;
int moto_A=0,moto_B=0 ;

//classe veículos
class veiculo{

public:
	//gerador de carros: fila A
	int gerador_car_A(){

		car_A = (rand()%10);
		return car_A;

	}


	//gerdor de carros: fila B
	int gerador_car_B(){


		car_B = (rand()%10);
		return car_B;


	}
	//gerador de motos: fila A

	int gerador_moto_A(){

		moto_A = (rand()%10);
		return moto_A;

	}


	//gerador de motos: fila B
	int gerador_moto_B(){


		moto_B = (rand()%10);
		return moto_B;

	}



	//grador caminhao: fila A
	int gerador_caminhao_A(){

		caminhao_A = (rand()%10);
		return caminhao_A;


	}

	//gerador caminhão: fila B
	int gerador_caminhao_B(){


		caminhao_B = (rand()%10);
		return caminhao_B;


	}

	int gerador_car_A_x(){

		car_A = (rand()%2);
		return car_A;

	}


	//gerdor de carros: fila B
	int gerador_car_B_x(){


		car_B = (rand()%2);
		return car_B;


	}
	//gerador de motos: fila A

	int gerador_moto_A_x(){

		moto_A = (rand()%2);
		return moto_A;

	}


	//gerador de motos: fila B
	int gerador_moto_B_x(){


		moto_B = (rand()%2);
		return moto_B;

	}



	//grador caminhao: fila A
	int gerador_caminhao_A_x(){

		caminhao_A = (rand()%2);
		return caminhao_A;


	}

	//gerador caminhão: fila B
	int gerador_caminhao_B_x(){


		caminhao_B = (rand()%2);
		return caminhao_B;


	}

	//proteção fila carros A vazia
	int fila_car_A_vazia(){
		if(in_A_car<0){
			in_A_car = 0;

		}
		return 1;
	}

	//proteção fila caminnhão A vazia
	int fila_caminhao_A_vazia(){
		if(in_A_caminhao<0){
			in_A_caminhao = 0;

		}
		return 1;
	}

	//proteção fila moto A vazia
	int fila_moto_A_vazia(){
		if(in_A_moto<0){
			in_A_moto = 0;

		}
		return 1;
	}

	//proteção fila carro B vazia
	int fila_car_B_vazia(){
		if(in_B_car<0){
			in_B_car = 0;

		}
		return 1;
	}

	//proteção fila caminhao B vazia
	int fila_caminhao_B_vazia(){
		if(in_B_caminhao<0){
			in_B_caminhao = 0;

		}
		return 1;
	}

	//proteção fila moto B vazia
	int fila_moto_B_vazia(){
		if(in_B_moto<0){
			in_B_moto = 0;

		}
		return 1;
	}

	//taxa de saída carro A
	int gerador_car_out_A(){


		tx_A_car = (rand()%15);
		return tx_A_car;

	}

	//taxa de saída carro B
	int gerador_car_out_B(){



		tx_B_car = (rand()%15);
		return tx_B_car;


	}

	//taxa de saída caminhao A
	int gerador_caminhao_out_A(){

		tx_A_caminhao = (rand()%15);
		return tx_A_caminhao;

	}

	//taxa de saída caminhao B
	int gerador_caminhao_out_B(){


		tx_B_caminhao = (rand()%15);
		return tx_B_caminhao;

	}
	//taxa de saída moto A
	int gerador_moto_out_A(){


		tx_A_moto = (rand()%15);
		return tx_A_moto;


	}


	//taxa de saída moto B
	int gerador_moto_out_B(){


		tx_B_moto = (rand()%15);
		return tx_B_moto;

	}


	//limitar tamanho de fila B
	int fila_infinita_B(){
		if(carro_B>=50){

			return 1;

		}
		else
			return 0;
	}

	//limitar tamanho de fila A
	int fila_infinita_A(){
		if(carro_A>=50){
			return 1;
		}
		else
			return 0;
	}

	//proteção de fila vazia A
	int fila_vazia_A(){
		if(carro_A<0)
			carro_A=0;
		return carro_A;
	}
	//proteção de fila vazia B
	int fila_vazia_B(){
		if(carro_B<0)
			carro_B=0;
		return carro_B;
	}


};

//classe do controlador de transito
//Abertura do semáforo
class controlador{
public:
	char*  controla(int obs){

		if(obs==3){
			obs = (rand()%2);
		}

		if(obs==1){
			return (char*)"aberto A";
		}
		else if(obs==0){
			return (char*)"aberto B";
		}

		else{
			return (char*)"igual";

		}

	}
};

//classe representado o ambiente de observação do sistema
class ambiente_observacao{
public:
	//políticas para a abertura dos semáforos
	//priorizando o maior tamanho de fila e o maior
	//números de caminhões na fila
	//é feito vários testes antes de decidir
	//qual semáforo abrir.
	int ambiente_obs(){
		if(carro_A>carro_B&&caminhao_A>caminhao_B){
			return 1;
		}




		else if(carro_B>carro_A&&caminhao_B>caminhao_A){

			return 0;


		}
		else if(carro_A>carro_B&&car_A>car_B){
			return 1;
		}




		else if(carro_B>carro_A&&car_B>car_A){

			return 0;


		}
		else if(carro_A>carro_B&&moto_A>moto_B){
			return 1;
		}




		else if(carro_B>carro_A&&moto_B>moto_A){

			return 0;


		}

		else if(carro_A==carro_B&&caminhao_A>caminhao_B){
			return 1;
		}




		else if(carro_B==carro_A&&caminhao_B>caminhao_A){

			return 0;


		}
		else if(carro_A==carro_B&&car_A>car_B){
			return 1;
		}




		else if(carro_B==carro_A&&car_B>car_A){

			return 0;


		}
		else if(carro_A==carro_B&&moto_A>moto_B){
			return 1;
		}




		else if(carro_B==carro_A&&moto_B>moto_A){

			return 0;


		}
		//se nenhuma condição satisfazer
		//será a fila maior que terá prioridade
		else if(carro_A>carro_B){
			return 1;
		}



		else if(carro_B>carro_A){
			return 0;
		}

		else
			return 3;
	}

};

//classe representando a simulação do sistema
//o comportamento dele
class ambiente_simul{
public:
	int ambiente_simu(char* acao){
		if (strcmp(acao,"aberto A")==0){

			veiculo veic;

			//se a fila estiver vazia, apenas entram veículos no sistema
			if(carro_A<0){
				veic.gerador_car_A();
				in_A_car = in_A_car + car_A;
				carro_A += car_A;
				veic.gerador_caminhao_A();
				in_A_caminhao += caminhao_A;
				carro_A +=caminhao_A;
				veic.gerador_moto_A();
				in_A_moto +=moto_A;
				carro_A +=moto_A;

				veic.gerador_car_B_x();
				in_B_car = in_B_car + car_B;
				carro_B += car_B;
				veic.gerador_caminhao_B_x();
				in_B_caminhao += caminhao_B;
				carro_B +=caminhao_B;
				veic.gerador_moto_B_x();
				in_B_moto +=moto_B;
				carro_B +=moto_B;


			}
			else{



				//gerando carros no sistema
				veic.gerador_car_A();
				//somando a quantidade de carros que entram
				in_A_car = in_A_car + car_A;
				//adicioando carros na fila
				carro_A += car_A;
				//gerando caminhões no sistema
				veic.gerador_caminhao_A();
				//somando a quantidade de carros que entram
				in_A_caminhao += caminhao_A;
				//adicioando caminhões na fila
				carro_A +=caminhao_A;
				//gerando motos no sistema
				veic.gerador_moto_A();
				//somando a quantidade de motos que entram
				in_A_moto +=moto_A;
				//adicionando motos na fila
				carro_A +=moto_A;

				veic.gerador_car_B_x();
				in_B_car = in_B_car + car_B;
				carro_B += car_B;
				veic.gerador_caminhao_B_x();
				in_B_caminhao += caminhao_B;
				carro_B +=caminhao_B;
				veic.gerador_moto_B_x();
				in_B_moto +=moto_B;
				carro_B +=moto_B;

				//gerando taxa de saída de carros
				veic.gerador_car_out_A();
				//retirando carros da fila
				carro_A -= tx_A_car;
				//diminuindo o total de carros
				in_A_car -=tx_A_car;
				//verifica se a fila de carros está vazia
				veic.fila_car_A_vazia();
				//gerando taxa de saída de caminhões
				veic.gerador_caminhao_out_A();
				//retirando caminhões da fila
				carro_A -=tx_A_caminhao;
				//reduz o total de caminhões
				in_A_caminhao -=tx_A_caminhao;
				//verifica se a fila de caminhão esta vazia
				veic.fila_caminhao_A_vazia();
				veic.gerador_moto_out_A();
				carro_A -=tx_A_moto;
				in_A_moto -=tx_A_moto;
				veic.fila_moto_A_vazia();


			}

		}

		else if(strcmp(acao,"aberto B")==0){
			veiculo veic;
			if(carro_B<0){

				veic.gerador_car_B();
				in_B_car = in_B_car + car_B;
				carro_B += car_B;
				veic.gerador_caminhao_B();
				in_B_caminhao += caminhao_B;
				carro_B +=caminhao_B;
				veic.gerador_moto_B();
				in_B_moto +=moto_B;
				carro_B +=moto_B;

				//gerando carros no sistema
				veic.gerador_car_A_x();
				//somando a quantidade de carros que entram
				in_A_car = in_A_car + car_A;
				//adicioando carros na fila
				carro_A += car_A;
				//gerando caminhões no sistema
				veic.gerador_caminhao_A_x();
				//somando a quantidade de carros que entram
				in_A_caminhao += caminhao_A;
				//adicioando caminhões na fila
				carro_A +=caminhao_A;
				//gerando motos no sistema
				veic.gerador_moto_A_x();
				//somando a quantidade de motos que entram
				in_A_moto +=moto_A;
				//adicionando motos na fila
				carro_A +=moto_A;


			}

			else{



				veic.gerador_car_B();
				in_B_car = in_B_car + car_B;
				carro_B += car_B;
				veic.gerador_caminhao_B();
				in_B_caminhao += caminhao_B;
				carro_B +=caminhao_B;
				veic.gerador_moto_B();
				in_B_moto +=moto_B;
				carro_B +=moto_B;

				//gerando carros no sistema
				veic.gerador_car_A_x();
				//somando a quantidade de carros que entram
				in_A_car = in_A_car + car_A;
				//adicioando carros na fila
				carro_A += car_A;
				//gerando caminhões no sistema
				veic.gerador_caminhao_A_x();
				//somando a quantidade de carros que entram
				in_A_caminhao += caminhao_A;
				//adicioando caminhões na fila
				carro_A +=caminhao_A;
				//gerando motos no sistema
				veic.gerador_moto_A_x();
				//somando a quantidade de motos que entram
				in_A_moto +=moto_A;
				//adicionando motos na fila
				carro_A +=moto_A;

				veic.gerador_car_out_B();
				carro_B -= tx_B_car;
				in_B_car -=tx_B_car;
				veic.fila_car_B_vazia();
				veic.gerador_caminhao_out_B();
				carro_B -=tx_B_caminhao;
				in_B_caminhao -=tx_B_caminhao;
				veic.fila_caminhao_B_vazia();
				veic.gerador_moto_out_B();
				carro_B -=tx_B_moto;
				in_B_moto -=tx_B_moto;
				veic.fila_moto_B_vazia();

			}
		}

		else{

		}
		return carro_A + carro_B;
	}
};

int main() {

	int i=1;
	int  obs = 0;
	veiculo veic;
	ambiente_observacao amb_obs;
	controlador cont;
	ambiente_simul amb_simul;


	srand(time(NULL));

	veic.gerador_car_A();
	in_A_car += car_A;
	carro_A = carro_A + car_A;
	veic.gerador_car_B();
	in_B_car += car_B;
	carro_B = carro_B + car_B;

	veic.gerador_caminhao_A();
	in_A_caminhao += caminhao_A;
	carro_A = carro_A + caminhao_A;
	veic.gerador_caminhao_B();
	in_B_caminhao += caminhao_B;
	carro_B = carro_B + caminhao_B;

	veic.gerador_moto_A();
	in_A_moto += moto_A;
	carro_A = carro_A + moto_A;
	veic.gerador_moto_B();
	in_B_moto += moto_B;
	carro_B = carro_B + moto_B;


	obs = amb_obs.ambiente_obs();



	printf("Fila_A=%d,Fila_B=%d\n",carro_A,carro_B);





	//quando esvaziar ambas as filas o laço termina
	while(carro_A>0||carro_B>0){
		obs = amb_obs.ambiente_obs();
		veic.fila_infinita_A();
		veic.fila_infinita_B();
		veic.fila_vazia_A();
		veic.fila_vazia_B();
		amb_simul.ambiente_simu(cont.controla(obs));
		veic.fila_infinita_A();
		veic.fila_infinita_B();
		veic.fila_vazia_A();
		veic.fila_vazia_B();
		printf("Tempo = %d, situação %s,FILA A = %d,FILA B = %d\n",i,cont.controla(obs),carro_A,carro_B);
		i++;
	}


	return 0;
}
