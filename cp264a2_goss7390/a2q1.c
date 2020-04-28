#include <stdio.h>
#include <time.h>

int *low_address;
int *high_address;

int iterative_fibonacci(int n)
{
    if (&n < low_address) low_address = &n;  // update the lowest memory address reached.
    int res;
    int fib1 = 0;
	int fib2 = 1;
	if(n == 0 || n == 1){
		res = 1;
	}
	else{
	for(int i=1; i < n; i++){
		res = fib1 + fib2;
		fib1 = fib2;
		fib2 = res;
		
		
	}}
return(res);
}

int recursive_fibonacci(int n) {
    if (&n < low_address) low_address = &n;  // update the lowest memory address reached. 
    int res;
	if (n == 0 || n == 1){
		res = 1;
	}
    else{
		res = recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
	}

}

int main(){
    int i=0, n = 40;
    clock_t t1, t2; 
    int m1, m2;
    double time_span1, time_span2;
    
    printf("Iterative algorithm measurement:\n");
    
    //measuring memory span for iterative_fibonacci function
    high_address = &i;
    low_address = high_address;
    printf("iterative_fibonacci(%d): %d\n", n, iterative_fibonacci(n));
    printf("high address: %lu\n", high_address);
    printf("low address: %lu\n", low_address);
    int memory_span1 = (unsigned long) high_address - (unsigned long) low_address;
    printf("memory span: %d\n",memory_span1);

    //measuring runtime for iterative_fibonacci function
    m1 = 500000;
    t1=clock();
    for (i=0; i< m1; i++) {
        iterative_fibonacci(n);
    }
    t2=clock();
    time_span1 = (double) t2-t1;
    printf("time_span(iterative_fibonacci(%d) for %d times): %0.1f (ms)\n", n, m1, time_span1);
    
	
    printf("\nRecursive algorithm measurement:\n");
    
    
    //measuring memory span for iterative_fibonacci function
    high_address = &i;
    low_address = high_address;
    printf("recursive_fibonacci(%d): %d\n", n, recursive_fibonacci(n));
    printf("high address: %lu\n", high_address);
    printf("low address: %lu\n", low_address);
    int memory_span2 = (unsigned long) high_address - (unsigned long) low_address;
    printf("memory span: %d\n",memory_span2);

    //measuring runtime for iterative_fibonacci function
    m2 = 10;
    t1=clock();
    for (int i=0; i< m1; i++) {
        iterative_fibonacci(n);
    }
    t2=clock();
    time_span2 = (double) t2-t1;
    printf("time_span(recursive_fibonacci(%d) for %d times): %0.1f (ms)\n", n, m2, time_span2);
    
    
    
    printf("\nComparison of recursive and iterative algorithms:\n");
    printf("memory_span(recursive_fibonacci(%d))/memory_span(iterative_fibonacci(%d)): %0.1f\n", n, n, ((double) memory_span2)/memory_span1);
    printf("time_span(recursive_fibonacci(%d))/time_span(iterative_fibonacci(%d)): %0.1f\n", n, n, (time_span2/time_span1)*(m1/m2));
    
    return 0;
}