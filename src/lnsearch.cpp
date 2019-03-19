long int lnsearch(long int * first, long int * last, int value){
	long int size = last-first;
	for (int i = 0; i < size; ++i){
		if(value == *(first+i)) return i;
	}
}