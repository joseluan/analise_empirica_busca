long int * lsearch(long int * first, long int * last, int value){
	long int size = last-first;
	for (int i = 0; i < size; ++i){
		if(value == *(first+i)) return (first+i);
	}
}

long int jsearch(long int * first, long int * last, int value){

	long int * first_org = first;
	long int jump = 100000;
	while(last-first > 0){
		if (value == *(first+jump)) return (first+jump)-first_org; 
		else if(value <= *(first+jump)) return lsearch(first-jump, first+jump, value)-first_org;

		first = first + jump;
	}

	return lsearch(first-jump, last, value)-first_org;
}
