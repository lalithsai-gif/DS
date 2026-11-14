#include<stdio.h>
int LinearSearch(int a[],int n,int x){
    int i,flag=-1;
        for(i=0;i<n;i++){
        if(a[i]==x){
            flag=1;
            return flag;
        }
    }
    return flag;
}

int main(){
    int n,i;
    printf("Enter the array size:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int x;
    printf("Enter the element to search: ");
    scanf("%d",&x);

    int ans=LinearSearch(a,n,x);
    if(ans==1){
        printf("Search is Successfull!");
    }
    else{
        printf("Serach is not successful!");
    }

    return 0;
}
