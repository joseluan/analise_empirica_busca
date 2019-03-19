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
	int const pulo = 1000000;
	int t = 500000000;
	long int *vetor = new long int[t];

	//Preenchendo o vetor com números
	for (int i = 0; i < pulo*atoi(argv[1]); ++i){
		vetor[i] = i;
	}
	
    ofstream outfile;
    outfile.open("busca_42.txt");
    outfile << "#Entrada   Interativa   Recursiva" << endl;

	int last = pulo;
	if (argc >= 2){
		//Busca Binária
		//Vezes que vai ser rodado
		float media[2] = {0.0, 0.0};
		float mediaGeral[2] = {0.0, 0.0};
		int n = 1000; 
		for (int i = 0; i < atoi(argv[1]); ++i){
			for (int i = 0; i < n; ++i){
				//Encontrando o valor
			    int value = *(vetor+(last-1)); 
			    //--------------------- INICIO INTERATIVA -------------------------------
		
			    auto start = high_resolution_clock::now();
			 
			    int pos = bsearch(vetor, vetor+last, value);	    			    
	
			    auto stop = high_resolution_clock::now(); 
			    auto duration = duration_cast<microseconds>(stop - start);

			    if(vetor[pos] == value && pos != -1){
			    	media[0] += ((duration.count()-media[0])/n);
			    }else{
			    	cout << "ERRO:	" << vetor[pos] << " | " << pos << "!=" << value << endl;
			    }
			    //--------------------- FIM INTERATIVA -------------------------------
			    //--------------------- INICIO RECURSIVA -------------------------------
			 
			    start = high_resolution_clock::now();
			    //int value = last-1; 
			    pos = rbsearch(vetor, vetor+last, value);	    			    
			
			    stop = high_resolution_clock::now(); 
			    duration = duration_cast<microseconds>(stop - start);
		
			    if(vetor[pos] == value && pos != -1){
			    	media[1] += ((duration.count()-media[1])/n);
			    }else{
			    	cout << "ERRO:	" << vetor[pos] << " | " << pos << " != " << value << endl;
			    }
			    //--------------------- FIM RECURSIVA -------------------------------
			}
			outfile << last << "   " << media[0] << "   " << media[1] << endl;
			
			mediaGeral[1] += ((media[1]-mediaGeral[1])/atoi(argv[1]));
			mediaGeral[0] += ((media[0]-mediaGeral[0])/atoi(argv[1]));
			
			media[0] = 0.0;
			media[1] = 0.0;
			last += pulo;
		}
		
		cout << "Média interativa: " << mediaGeral[0] << endl << "Média recursiva: " << mediaGeral[1] << endl;
		last = 1;
	}

	delete vetor;
	outfile.close();
	return 0;
}