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
        int l,r,smallest;
        smallest=i;
        l=2*i+1;
        r=2*i+2;  
        if(l<n && a[l]<a[smallest])
            smallest=l;
        if(r<n && a[r]<a[smallest])
            smallest=r;
        if(smallest!=i)
        {
            swap(&a[i],&a[smallest]);
            heapify(a,n,smallest);
        }
}

void minHeap(int a[],int n)
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

    minHeap(a,n);
    printf("\nMin heap tree elements:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}