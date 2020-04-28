#include<stdio.h>
#include<stdlib.h>
 
float horner(float *p, int n, float x);
float bisection(float *p, int n, float a, float b);
const float OFF = 0.000001;

float horner(float *p, int n, float x)
{
	float res = *p;
	
	for(int i = 1; i < n; i++){
		res = res * x + *(p + i);
	}
   return res;
}

//your bisection method implementation
float bisection(float *p, int n, float a, float b)
{
	float x = (a+b)/2;
	
	while (((x-a) >= OFF) || (abs(horner(p, n, x)) >= OFF)){
		
		if((horner(p,n,x) * horner(p,n,a)) < 0){
			b = x;
		}
		else{
			a = x;
		}
		x = (a+b) / 2;
	}
	return x;
}