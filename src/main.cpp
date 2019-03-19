#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> 
#include <chrono>
#include <cmath>
#include <stdlib.h>

#include "../include/bsearch.h"
#include "../include/rbsearch.h"
#include "../include/tsearch.h"
#include "../include/rtsearch.h"
#include "../include/jsearch.h"
#include "../include/fsearch.h"

using namespace std;
using namespace std::chrono;


int main(int argc, char const *argv[]){
	int const pulo = 10000;
	int t = 500000000;
	long int *vetor = new long int[t];

	//Preenchendo o vetor com números
	for (int i = 0; i < pulo*atoi(argv[2]); ++i){
		vetor[i] = i;
	}
	
    ofstream outfile;
    outfile.open("busca.txt");
    
	int last = pulo;
	if (argc >= 3){
		//Busca Binária
		//Vezes que vai ser rodado
		float media = 0.0;
		int n = 1000;
		for (int i = 0; i < atoi(argv[2]); ++i){
			for (int i = 0; i < n; ++i){
			    // Get starting timepoint 
			    auto start = high_resolution_clock::now();
			    //Encontrando o valor
			    //int value = *(vetor+(rand()%((int) (last*0.25))));
			    int value = *(vetor+(last-1)); 
			    int pos = -1;

			    switch(atoi(argv[1])){
			    	case 1:
			    		pos = bsearch(vetor, vetor+last, value);
			    		break;
			    	case 2:
			    		pos = pbsearch(vetor, vetor+last, value);
			    		break;
			    	case 3:
			    		pos = prbsearch(vetor, vetor+last, value);
			    		break;
			    	case 4:
			    		pos = rbsearch(vetor, vetor+last, value);
			    		break;
			    	case 5:
			    		pos = jsearch(vetor, vetor+last, value);
			    		break;
			    	case 6:
			    		pos = fsearch(vetor, vetor+last, value);
			    		break;
			    	case 7:
			    		pos = tsearch(vetor, vetor+last, value);
			    		break;
			    	case 8:
			    		pos = rtsearch(vetor, vetor+last, value);
			    		break;
			    }
			    			    
			    // Get ending timepoint 
			    auto stop = high_resolution_clock::now(); 
			  
			    // Get duration. Substart timepoints to  
			    // get durarion. To cast it to proper unit 
			    // use duration cast method 
			    auto duration = duration_cast<microseconds>(stop - start);
			    //Fazendo a media
			    if(atoi(argv[1]) == 2 || atoi(argv[1]) == 3){
			    	media += pos;
			    }else{
				    if(vetor[pos] == value && pos != -1){
				    	media += ((duration.count()-media)/n);
				    }else{
				    	cout << "ERRO:	" << vetor[pos] << " | " << pos << "!=" << value << endl;
				    }
				}
			}
			outfile << last << " " << media << endl;
			media = 0;
			last += pulo;
		}
		last = 1;
	}

	delete vetor;
	outfile.close();
	return 0;
}