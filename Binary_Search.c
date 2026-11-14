#include<stdio.h>

int Binary_Search(int arr[],int l,int h,int x){
    if(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            l=mid+1;
            return Binary_Search(arr,l,h,x);
        }
        else{
            h=mid-1;
            return Binary_Search(arr,l,h,x);
        }
    }
    return -1;
}

int main(){

    int n,x;
    printf("ENter size of the array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d",&x);
    int result = Binary_Search(a, 0, n-1, x);

    if(result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");


    return 0;
}
