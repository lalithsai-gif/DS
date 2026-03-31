#include<stdio.h>

int getMax(int a[],int n){
    int max=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}

void CountingSort(int a[],int n){
    int i,max,output[n];

    max=getMax(a,n);
    int count[max+1];

    for(i=0;i<=max;i++){
        count[i]=0;
    }

    for(i=0;i<n;i++){
        count[a[i]]++;
    }

    for(i=1;i<=max;i++){
        count[i]=count[i]+count[i-1];
    }

    for(i=n-1;i>=0;i--){
        output[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }

    for(i=0;i<n;i++){
        a[i]=output[i];
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
    CountingSort(a,n);
    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}