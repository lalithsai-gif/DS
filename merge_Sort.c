#include<stdio.h>

void merge(int a[],int l,int mid,int h){
    int n1=mid-l+1;
    int n2=h-mid;

    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=a[i+l];
    }
    for(int i=0;i<n2;i++){
        R[i]=a[mid+1+i];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k++]=L[i++];
        }
        else{
            a[k++]=R[j++];
        }
    }

    while(i<n1){
        a[k++]=L[i++];
    }

    while(j<n2){
        a[k++]=R[j++];
    }
}

void merge_Sort(int a[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        merge_Sort(a,l,mid);
        merge_Sort(a,mid+1,h);
        merge(a,l,mid,h);
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
    merge_Sort(a,0,n-1);

    printf("Sorted array after MergeSort: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}