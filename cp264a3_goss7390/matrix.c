#include  <stdio.h>
//---------------------------------------------------------
void magic_square(int *m, int n) {
    /* assign 3X3 matrix to following values
     8     1     6
     3     5     7
     4     9     2
     */
    int values[9] = { 8, 1, 6, 3, 5, 7, 4, 9, 2 };
    int i, len = n*n, *p = values;
    for (i = 0; i < len; i++) *m++ = *p++;
}


//---------------------------------------------------------
void display_matrix(int *m, int n) {
    int *p = m, i, j;
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n; j++) printf("%4d", *p++); 
    }
    printf("\n");
}

//---------------------------------------------------------
int is_magic_square(int *m, int n) {
	int row_sum = 0;
	int column_sum = 0;
	int diagonal_sum = 0;
	int n_diagonal_sum = 0;
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j < n; j++){
			if(i==j){
				diagonal_sum += *(m+(i*n)+j);
			}
		}
	}
	
	for(int i = 0; i<n; i++){
		for(int j = n; j>0; j--){
			if(i==j){
				n_diagonal_sum += *(m+(i*n)+j);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		row_sum = 0;
		for(int j = 0; j<n; j++) {
			row_sum += *(m+(i*n) +j);
		}
		if(row_sum != diagonal_sum){
			return 0;
		}
	}
	for(int i=0; i < n; i++){
		column_sum = 0;
		for(int j = 0; j < n; j++){
			column_sum += *(m+(n*j)+i);
		}
		if(column_sum != diagonal_sum){
			return 0;
		}
	}
	return 1;
}

//---------------------------------------------------------
void transpose_matrix(int *m1, int *m2, int n) {
int i, j;
for(i = 0; i<n;i++)
		for(j = 0;j<n;j++)
			*(m2 + j*n + i) = *(m1 + i*n + j);
}			

//---------------------------------------------------------
void multiply_matrix(int *m1, int *m2, int *m3, int n) {   
	int i, j, k, sum;
	for(i=0; i<n; i++){
		for(j=0; j<4; j++){
			sum = 0;
			for(k = 0; k<n; k++){
				sum += *(m1 + i*n +k) * (*(m2 + j + n*k));
			}
			*(m3 + i*n + j) = sum;
		}
	}

}