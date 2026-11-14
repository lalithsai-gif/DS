#include<stdio.h>

void swap(int *i,int *j){
    int temp=*i;
    *i=*j;
    *j=temp;
}

void heapify(int a[],int n,int i){
    int l,r,largest;
    largest=i;
    l=2*i+1;
    r=2*i+2;

    if(l<n && a[l]>a[largest]){
        largest=l;
    }

    if(r<n && a[r]>a[largest]){
        largest=r;
    }

    if(largest!=i){
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
}

void HeapSort(int a[],int n){
    int i;
    for(i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }

    for(i=n-1;i>=0;i--){
        swap(&a[0],&a[i]);
        heapify(a,i,0);
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
    HeapSort(a,n);

    printf("After Heap Sorting: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}