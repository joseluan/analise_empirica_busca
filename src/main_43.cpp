#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> 
#include <chrono>
#include <cmath>
#include <stdlib.h>

#include "../include/bsearch.h"
#include "../include/tsearch.h"
#include "../include/fsearch.h"

using namespace std;
using namespace std::chrono;


int main(int argc, char const *argv[]){
	int const pulo = 1000000;
	int t = 150000000;
	long int *vetor = new long int[t];

	//Preenchendo o vetor com números
	for (int i = 0; i < pulo*atoi(argv[1]); ++i){
		vetor[i] = i;
	}
	
    ofstream outfile;
    outfile.open("busca_43.txt");
    outfile << "#Entrada   BináriaInterativa   TernáriaInterativa   Fibonacci" << endl;
    
	int last = pulo;
	if (argc >= 2){
		//Busca Binária
		//Vezes que vai ser rodado
		float media[3] = {0.0, 0.0, 0.0};
		int n = 1000; 
		for (int i = 0; i < atoi(argv[1]); ++i){
			for (int i = 0; i < n; ++i){
				//Encontrando o valor
			    int value = *(vetor+(last-2)); 
			    //--------------------- INICIO BINÀRIA INTERATIVA -------------------------------
		
			    auto start = high_resolution_clock::now();
			 
			    int pos = bsearch(vetor, vetor+last, value);	    			    
	
			    auto stop = high_resolution_clock::now(); 
			    auto duration = duration_cast<microseconds>(stop - start);

			    if(vetor[pos] == value && pos != -1){
			    	media[0] += ((duration.count()-media[0])/n);
			    }else{
			    	cout << "BINARIA: ERRO:	" << vetor[pos] << " | " << pos << "!=" << value << endl;
			    }
			    //--------------------- FIM BINÁRIA INTERATIVA -------------------------------
			    
			    //--------------------- INICIO TERNÀRIA INTERATIVA -------------------------------
			 
			    start = high_resolution_clock::now();
			    //int value = last-1; 
			    pos = tsearch(vetor, vetor+last, value);	    			    
			
			    stop = high_resolution_clock::now(); 
			    duration = duration_cast<microseconds>(stop - start);
		
			    if(vetor[pos] == value && pos != -1){
			    	media[1] += ((duration.count()-media[1])/n);
			    }else{
			    	cout << "TERNARIA: ERRO:	" << vetor[pos] << " | " << pos << " != " << value << endl;
			    }
			    //--------------------- FIM TERNÀRIA INTERATIVA -------------------------------
			    
			    //--------------------- INICIO FIBONACCI -------------------------------
			 
			    start = high_resolution_clock::now();
			    //int value = last-1; 
			    pos = fsearch(vetor, vetor+last, value);	    			    
			
			    stop = high_resolution_clock::now(); 
			    duration = duration_cast<microseconds>(stop - start);
		
			    if(vetor[pos] == value && pos != -1){
			    	media[2] += ((duration.count()-media[1])/n);
			    }else{
			    	cout << "FIBONACCI: ERRO:	" << vetor[pos] << " | " << pos << " != " << value << endl;
			    }
			    //--------------------- FIM FIBONACCI -------------------------------
			}
			outfile << last << "   " << media[0] << "   " << media[1] << "   " << media[2] << endl;
			media[0] = 0.0;
			media[1] = 0.0;
			media[2] = 0.0;
			last += pulo;
		}
		last = 1;
	}

	delete vetor;
	outfile.close();
	return 0;
}