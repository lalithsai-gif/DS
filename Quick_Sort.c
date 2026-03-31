#include<stdio.h>

void swap(int *i,int *j){
    int temp=*i;
    *i=*j;
    *j=temp;
}

int partition(int a[],int l,int h){
    int pivot,i,j;
    pivot=a[h];
    i=l-1;
    for(j=l;j<=h-1;j++){
        if(a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[h]);

    return (i+1);
}

void QuickSort(int a[],int l,int h){
    if(l<h){
        int PI=partition(a,l,h);
        QuickSort(a,l,PI-1);
        QuickSort(a,PI+1,h);
    }
}

void main(){
    int n;
    printf("ENter size of the array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    QuickSort(a,0,n-1);

    printf("Sorted array after QuickSort: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    
}