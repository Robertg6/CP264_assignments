#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
float horner(float p[], int n, float x)
{
char res;
float store;
store = p[0];
for (int i=1; i<n; i++){ 
        res = store*x + p[i];
		
}
return(res);
}
 
int main(int argc, char* args[])
{   
    //get polynomial efficients from command line arguments
    if (argc <= 1) {
        printf("Need more than one arguments, e.g.: 1 2 3 4\n");
        return 0;
    }
    
    int n = argc-1;  
    
    float p[n];
	for(int i = 0; i < argc; i++){
		p[i] = atof(args[i+1]);
	}
		
	

    
    // repetitive polynomial evaluation for user input of x value
    float x = 0.0;
    float res;
	do{
        //get x value from keyboard
        do {
            printf("\nPlease enter x value (Ctrl+C or 999 to quit):\n");
            if (scanf("%f", &x) != 1) {
                printf("Invalid input\n");
            } else {            
                break;
            }
            // flush the input buffer 
            while(getchar() !='\n'); 
        } while (1);
		if(x == 999){
			break;
		}
		else{
		
		res = horner(p, n, x);
		}
		for(int i = 1; i <= n; i++){
		printf("%.1f*%.1f*%^%d", atof(args[i]), x, atoi(args[n - (i)]));
		if(i != n){
			printf(" + ");
		}
		
		
	}
    printf("= %.1f", res);} while (1);
	

    return 0;
}