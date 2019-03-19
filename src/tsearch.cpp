long int tsearch(long int * first, long int * last, int value){
	
	long int step = (last-first)/3;
	long int *t1 = first+step;
	long int *t2 = t1+step;
	long int *first_org = first;

	while(last-first > 0){
		
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
		}else if(value <= *(t2-1)){
			first = t1+1;
			last = (t2-1);
		}else{
			first = t2+1;
		}

		step = (last-first)/3;
		t1 = first+step;
		t2 = t1+step;
	}

	return -1;
}