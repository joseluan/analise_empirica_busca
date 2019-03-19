#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> 
#include <chrono>
#include <cmath>
#include <stdlib.h>

#include "../include/bsearch.h"
#include "../include/lnsearch.h"

using namespace std;
using namespace std::chrono;


int main(int argc, char const *argv[]){
	int const pulo = 5;
	int t = 1000000;
	long int *vetor = new long int[t];

	//Preenchendo o vetor com números
	for (int i = 0; i < pulo*atoi(argv[1]); ++i){
		vetor[i] = i;
	}
	
    ofstream outfile;
    outfile.open("busca_44.txt");
    outfile << "#Entrada   Binária   Linear" << endl;

	int last = 100;
	if (argc >= 2){
		//Busca Binária
		//Vezes que vai ser rodado
		float media[2] = {0.0, 0.0};
		int n = 10000; 
		for (int i = 0; i < atoi(argv[1]); ++i){
			for (int i = 0; i < n; ++i){
				//Encontrando o valor
			    int value = *(vetor+(last-1)); 
			    //--------------------- INICIO BINARIA -------------------------------
		
			    auto start = high_resolution_clock::now();
			 
			    int pos = bsearch(vetor, vetor+last, value);	    			    
	
			    auto stop = high_resolution_clock::now(); 
			    auto duration = duration_cast<microseconds>(stop - start);

			    if(vetor[pos] == value && pos != -1){
			    	media[0] += ((duration.count()-media[0])/n);
			    }else{
			    	cout << "ERRO:	" << vetor[pos] << " | " << pos << "!=" << value << endl;
			    }
			    //--------------------- FIM BINARIA -------------------------------
			    //--------------------- INICIO LINEAR -------------------------------
			 
			    start = high_resolution_clock::now();
			    //int value = last-1; 
			    pos = lnsearch(vetor, vetor+last, value);	    			    
			
			    stop = high_resolution_clock::now(); 
			    duration = duration_cast<microseconds>(stop - start);
		
			    if(vetor[pos] == value && pos != -1){
			    	media[1] += ((duration.count()-media[1])/n);
			    }else{
			    	cout << "ERRO:	" << vetor[pos] << " | " << pos << " != " << value << endl;
			    }
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
	outfile.close();
	return 0;
}