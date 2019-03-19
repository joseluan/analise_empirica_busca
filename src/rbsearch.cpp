long int rbsearch(long int * first, long int * last, int value, long int * first_org){
	
	long int count = (last-first)/2;
	if ((last-first) >= 0){
		if((last-first) == 0) return first-first_org;
		else if(*(first+count) == value) return (first+count)-first_org;
		else if(*(first+count) > value){
			last = (first+count-1);
			return rbsearch(first, last, value, first_org);
		}else{
			first = (first+count+1);
			return rbsearch(first, last, value, first_org);
		}
	}
}

long int rbsearch(long int * first, long int * last, int value){
	return rbsearch(first, last, value, first);
}

int prbsearch(long int * first, long int * last, int value, long int * first_org, int cont){
	cont++;
	long int count = (last-first)/2;
	cont++;
	if ((last-first) >= 0){
		cont++;
		if((last-first) == 0){
			cont++;
			return first-first_org;
		}
		cont++;
		if(*(first+count) == value){
			cont++;
			return (first+count)-first_org;
		}
		cont++;
		if(*(first+count) > value){
			cont++;
			last = (first+count-1);
			cont++;
			return prbsearch(first, last, value, first_org, cont);
		}else{
			cont++;
			first = (first+count+1);
			cont++;
			return prbsearch(first, last, value, first_org, cont);
		}
	}
}

int prbsearch(long int * first, long int * last, int value){
	return prbsearch(first, last, value, first, 1);
}