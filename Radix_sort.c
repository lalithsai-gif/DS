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

int getMaxHelper(int a[],int n,int place){
    int max=(a[0]/place)%10;
    for(int i=0;i<n;i++){
        if(((a[i]/place)%10)>max){
            max=(a[i]/place)%10;
        }
    }
    return max;
}

void CountingSort(int a[],int n,int place){
    int i,max,output[n];

    max=getMaxHelper(a,n,place);
    int count[max+1];

    for(i=0;i<=max;i++){
        count[i]=0;
    }

    for(i=0;i<n;i++){
        count[(a[i]/place)%10]++;
    }

    for(i=1;i<=max;i++){
        count[i]=count[i]+count[i-1];
    }

    for(i=n-1;i>=0;i--){
        output[count[(a[i]/place)%10]-1]=a[i];
        count[(a[i]/place)%10]--;
    }

    for(i=0;i<n;i++){
        a[i]=output[i];
    }
}

void RadixSort(int a[],int n){
    int max,place;
    max=getMax(a,n);
    for(place=1;max/place>0;place*=10){
        CountingSort(a,n,place);
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
    RadixSort(a,n);
    printf("Sorted array after RadixSort: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}