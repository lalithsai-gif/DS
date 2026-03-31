#include<stdio.h>

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void SelectionSort(int a[],int n){
    int i,j,min_index;
    for(i=0;i<n-1;i++){
        min_index=i;
        for(j=i+1;j<n;j++){
            if(a[min_index]>a[j]){
                min_index=j;
            }
        }

       swap(&a[i],&a[min_index]);
    }
}

int main(){

    int n;
    printf("ENter size of the array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    SelectionSort(a,n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}