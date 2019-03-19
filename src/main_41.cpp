#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> 
#include <chrono>
#include <cmath>
#include <stdlib.h>

#include "../include/lnsearch.h"
#include "../include/jsearch.h"

using namespace std;
using namespace std::chrono;


int main(int argc, char const *argv[]){
	int const pulo = 1000;
	int t = 100000000;
	long int *vetor = new long int[t];

	//Preenchendo o vetor com números
	for (int i = 0; i < pulo*atoi(argv[1]); ++i){
		vetor[i] = i;
	}
	
    ofstream outfile;
    outfile.open("busca_41.txt");
    outfile << "#Entrada   Jump   Linear" << endl;

	int last = pulo;
	if (argc >= 2){
		//Busca Binária
		//Vezes que vai ser rodado
		float media[2] = {0.0, 0.0};
		float mediaGeral[2] = {0.0, 0.0};
		int n = 1000; 
		for (int i = 0; i < atoi(argv[1]); ++i){
			for (int i = 0; i < n; ++i){
				//--------------------- INICIO JUMP -------------------------------
				
			    auto start = high_resolution_clock::now();
			 
			    int pos = jsearch(vetor, vetor+last, *(vetor+last-1));//ultimo elemento	    			    
	
			    auto stop = high_resolution_clock::now(); 
			    auto duration = duration_cast<microseconds>(stop - start);

			    media[0] += ((duration.count()-media[0])/n);
			    
			    //--------------------- FIM JUMP -------------------------------
			    //--------------------- INICIO LINEAR -------------------------------
			 
			    start = high_resolution_clock::now();
			    //int value = last-1; 
			    pos = lnsearch(vetor, vetor+last, *(vetor+last-1));//ultimo elemento	    			    
			
			    stop = high_resolution_clock::now(); 
			    duration = duration_cast<microseconds>(stop - start);
		
			    media[1] += ((duration.count()-media[1])/n);
			    
			    //--------------------- FIM LINEAR -------------------------------
			}
			outfile << last << "   " << media[0] << "   " << media[1] << endl;

			media[0] = 0.0;
			media[1] = 0.0;
			last += pulo;
		}
		last = 1; 
	}

	delete vetor;
	delete media;
	delete mediaGeral;
	outfile.close();
	return 0;
}