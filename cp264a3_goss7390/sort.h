#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second);
void display_array(int *a, int n);

void selection_sort(int *a, int left, int right);
void quick_sort(int *a, int left, int right);
void copy_array(int *a, int *b, int n);
int is_sorted(int *a, int n);

void display_array(int *a, int n)
{
  int i; 
  for (i=0; i<n; ++i) {
    if (i%10 == 0) printf("\n");
      printf("%3d ", *(a+i));
  }
  printf("\n"); 
}

void swap(int *first, int *second)
{
  int temp = *first;
  *first = *second;
  *second = temp;
}


void copy_array(int *a, int *b, int n)
{
	for(int i = 0; i < n; i++){
		*(b+i) = *(a+i);
	}
}

int is_sorted(int *a, int n)
{
	int sorted = 1;
	for(int i = 0; (i<n) && (sorted == 1); i++){
		if(*(a+i) = *(a+i+1)){
			sorted = 0;
		}
	}
	return (sorted);
}

void selection_sort(int *a, int left, int right)
{
	int i, j, k;  
	for(i = 0; i<right+1; i++){
		k=i;
		for(j=i+1;j<right+1;j++){
			if(*(a+j)<*(a+k)){
				k=j;
			}
		}
		if(i!=k){
			swap(a+k,a+i);
		}
	}  
}

void quick_sort(int *a, int left, int right)
{ 
int key,i,j,k;
if(left <right){ 
	k = (left + right)/2;
	swap(a+left, a+k);
	key = *(a+left);
	i = left+1;
	j = right;
	while(i <= j) {
		while( i <= right && *(a+i) <= key)
			i++;
		while( j >= left && *(a+j) > key)
			j--;
		if( i < j)
			swap(a+i, a+j);
	}
	swap(a+left, a+j);
	quick_sort(a, left, j-1);
	quick_sort(a, j+1, right);
	
	}
}