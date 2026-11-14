import time
import random

def heapify(arr,n,i):
    largest=i
    l=2*i+1
    r=2*i+2
    if(l<n and arr[l]>arr[largest]):
        largest=l
    if(r<n and arr[r]>arr[largest]):
        largest=r
    
    if(largest!=i):
        arr[i],arr[largest]=arr[largest],arr[i]
        heapify(arr,n,largest)
    return arr

def Heap_Sort(arr,n):
    for i in range(n//2-1,-1,-1):
        heapify(arr,n,i)
    for i in range(n-1,0,-1):
        arr[0],arr[i]=arr[i],arr[0]
        heapify(arr,i,0)
    return arr

n=int(input("Enter Size of the array:"))
arr=[]
for i in range(n):
    #ele=int(input(f"arr[{i}]:"))
    ele=random.randint(0,1000)
    arr.append(ele)

start_time1=time.time()
print(Heap_Sort(arr,n))
end_time1=time.time()
print(f"The Time taken By Heap Sort:{start_time1-end_time1}")

