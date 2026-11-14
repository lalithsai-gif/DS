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

def merge(arr,l,mid,h):
    n=mid-l+1
    m=h-mid
    left=[]
    r=[]
    for i in range(n):
        left.append(arr[i+l])
    for i in range(m):
        r.append(arr[mid+1+i])
    i=0
    j=0
    k=l
    while(i<n and j<m):
        if left[i]<=r[j]:
            arr[k]=left[i]
            i+=1
            k+=1
        else:
            arr[k]=r[j]
            j+=1
            k+=1
    
    while(i<n):
        arr[k]=left[i]
        i+=1
        k+=1
    while(j<m):
        arr[k]=r[j]
        j+=1
        k+=1

    return arr

def Merge_Sort(arr,l,h):
    if(l<h):
        mid=(l+h)//2
        Merge_Sort(arr,l,mid)
        Merge_Sort(arr,mid+1,h)
        merge(arr,l,mid,h)
        return arr

n=int(input("Enter the size of array:"))

arr=[]

for i in range(n):
    ele=random.randint(0,10000)
    #ele=int(input(f"arr {i}:"))
    arr.append(ele)

start_time1=time.time()
Quick_Sort(arr,0,n-1)
end_time1=time.time()

print(f"Execution Time for Quick Sort: {end_time1-start_time1} seconds")

start_time2=time.time()
Merge_Sort(arr,0,n-1)
end_time2=time.time()

print(f"Execution Time for Merge Sort: {end_time2-start_time2} seconds")

print("ratio to Quick to merge sort ",(end_time1-start_time1)//(end_time2-start_time2))
