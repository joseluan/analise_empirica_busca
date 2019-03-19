long int bsearch(long int * first, long int * last, int value){
	long int * first_org = first;
	long int size_temp = last-first;
	long int count = size_temp/2;

	while(size_temp >= 0){
		if(*(first+count) == value) return (first+count)-first_org;
		else if(*(first+count) > value){
			last = (first+count-1);
		}else{
			first = (first+count+1);
		}
		size_temp = last-first;
		count = size_temp/2;
	}
	return -1;
}

int pbsearch(long int * first, long int * last, int value){
	int cont = 1;
	long int * first_org = first;
	cont++;
	long int size_temp = last-first;
	cont++;
	long int count = size_temp/2;
	cont++;
	while(size_temp >= 0){
		cont += 2;
		if(*(first+count) == value) return cont;
		else if(*(first+count) > value){
			cont++;
			last = (first+count-1);
		}else{
			cont++;
			first = (first+count+1);
		}
		cont++;
		size_temp = last-first;
		cont++;
		count = size_temp/2;		
	}
	return -1;
}
