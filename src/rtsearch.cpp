long int rtsearch(long int * first, long int * last, int value, long int * first_org){
	
	long int step = (last-first)/3;
	long int *t1 = first+step;
	long int *t2 = t1+step;

	if(last-first > 0){
		
		if(value == *first)
			return (first-first_org);
		if(value == *last)
			return (last-first_org);
		if(value == *t1)
			return (t1-first_org);
		if(value == *t2)
			return (t2-first_org);
		

		if(value <= *(t1-1)){
			last = t1-1;
			return rtsearch(first, last, value, first_org);
		}else if(value <= *(t2-1)){
			first = t1+1;
			last = (t2-1);
			return rtsearch(first, last, value, first_org);
		}else{
			first = t2+1;
			return rtsearch(first, last, value, first_org);
		}
	}

	return -1;
}

int rtsearch(long int * first, long int * last, int value){
	return rtsearch(first, last, value, first);
}