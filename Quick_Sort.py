import random
import time

def swap(arr,i,j):
    arr[i],arr[j]=arr[j],arr[i]

def partition(arr,l,r):
    p=arr[r]
    i=l-1
    j=l
    while(j<r):
        if(arr[j]<=p):
            i=i+1
            swap(arr,i,j)
        j=j+1
    swap(arr,i+1,r)
    return i+1


def Quick_Sort(arr,l,r):
    if(l<r):
        p=partition(arr,l,r)
        Quick_Sort(arr,l,p-1)
        Quick_Sort(arr,p+1,r)
    return arr

n=int(input("Enter the size of array:"))

arr=[]

for i in range(n):
    ele=random.randint(0,10000)
    #ele=int(input(f"arr {i}:"))
    arr.append(ele)

start_time=time.time()
Quick_Sort(arr,0,n-1)
end_time=time.time()

print(f"Execution Time: {end_time-start_time} seconds")

