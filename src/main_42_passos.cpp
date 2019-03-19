#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> 
#include <chrono>
#include <cmath>
#include <stdlib.h>

#include "../include/bsearch.h"
#include "../include/rbsearch.h"

using namespace std;
using namespace std::chrono;


int main(int argc, char const *argv[]){
	int const pulo = 10;
	int t = 500000000;
	long int *vetor = new long int[t];

	//Preenchendo o vetor com números
	for (int i = 0; i < pulo*atoi(argv[1]); ++i){
		vetor[i] = i;
	}
	
    ofstream outfile;
    outfile.open("busca_42_passos.txt");
    outfile << "#Entrada   Interativa   Recursiva" << endl;

	int last = pulo;
	if (argc >= 2){
		//Busca Binária
		//Vezes que vai ser rodado
		float media[2] = {0.0, 0.0};
		int n = 1000; 
		for (int i = 0; i < atoi(argv[1]); ++i){
			for (int i = 0; i < n; ++i){
				//Encontrando o valor
			    int value = *(vetor+(last-1)); 
			    //--------------------- INICIO INTERATIVA -------------------------------
			    media[0] += pbsearch(vetor, vetor+last, value);	
			    //--------------------- FIM INTERATIVA -------------------------------
			    
			    //--------------------- INICIO RECURSIVA -------------------------------
			    media[1] += prbsearch(vetor, vetor+last, value);
			    //--------------------- FIM RECURSIVA -------------------------------
			}
			outfile << last << "   " << media[0]/n << "   " << media[1]/n << endl;
			
			media[0] = 0.0;
			media[1] = 0.0;
			last += pulo;
		}

		last = 1;
	}

	delete vetor;
	outfile.close();
	return 0;
}