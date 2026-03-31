#include<stdio.h>
#define MAX 30

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void heapify(int a[],int n,int i)
{
        int l,r,largest;
        largest=i;
        l=2*i+1;
        r=2*i+2;
        if(l<n && a[l]>a[largest])
            largest=l;
        if(r<n && a[r]>a[largest])
            largest=r;
        if(largest!=i)
        {
            swap(&a[i],&a[largest]);
            heapify(a,n,largest);
        }
}

void maxHeap(int a[],int n)
{
    for(int i=(n/2)-1; i>=0; i--)
    {
        heapify(a,n,i);
    }
}

void main()
{
    int a[20],n,i;
    printf("Enter no.of elements :");
    scanf("%d",&n);
    printf("Enter %d elements into array:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("\nArray elements:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    maxHeap(a,n);
    printf("\nMax heap tree elements:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}