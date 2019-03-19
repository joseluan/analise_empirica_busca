#include <cmath>

long int fibonacci(int n){
	return ((pow(((1+sqrt(5))/2),(n+1))-pow(((1-sqrt(5))/2),(n+1))) / sqrt(5));
}

long int fsearch(long int * first, long int * last, int value){
	
	long int * first_org = first;
	long int c;
	while((last-first) > 1){

		if(*last == value) return last-first_org;
		if(*first == value) return first-first_org;
		
		c = 0;
		while((last-first) >= fibonacci(c)){
			c++;
		}

		if(*(first+fibonacci(c-2)) == value){
			return (first+fibonacci(c-2))-first_org;
		}else if(*(first+fibonacci(c-2)) < value){
			first = (first+fibonacci(c-2));
		}else{
			last = (first+fibonacci(c-2));
		}
	}

	return -1;
}