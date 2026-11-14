import time
import random

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

n=int(input("Enter Size ofx the array:"))
arr=[]
for i in range(n):
    #ele=int(input(f"arr[{i}]:"))
    ele=random.randint(0,1000)
    arr.append(ele)

start_time1=time.time()
#print(Heap_Sort(arr,n))
Heap_Sort(arr,n)
end_time1=time.time()
print(f"The Time taken By Heap Sort:{start_time1-end_time1}")

start_time2=time.time()
#print(Merge_Sort(arr,0,n-1))
Merge_Sort(arr,0,n-1)
end_time2=time.time()
print(f"The Time taken By Heap Sort:{start_time2-end_time2}")

print(f"The ratio to heap sort and merge sort: {(start_time2-end_time2)/(start_time1-end_time1)}")