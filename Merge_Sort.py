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

n=int(input("Enter No. of elements in array:"))
arr=[]
for i in range(0,n):
    #ele=int(input(f"arr[{i}]:"))
    ele=random.randint(1,1000)
    arr.append(ele)
#print(f"Original arr:{arr}")
start_time=time.time()
#print("After Sorting:")
Merge_Sort(arr,0,n-1)
end_time=time.time()
print(f"execution time:{end_time-start_time:.7f} seconds")
