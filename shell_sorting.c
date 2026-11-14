#include<stdio.h>

void shellSort(int arr[],int n){
    int i,j,temp,interval;
    for(interval=n/2;interval>0;interval/=2){
        for(i=interval;i<n;i++){
            temp=arr[i];
            for(j=i;j>=interval && arr[j-interval]>temp;j=j-interval){
                arr[j]=arr[j-interval];
            }
            arr[j]=temp;
        }
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
    shellSort(a,n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

}