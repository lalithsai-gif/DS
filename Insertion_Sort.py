import time
import random
def Insertion_Sort(arr):
    for i in range(0,len(arr)):
        key=arr[i]
        j=i-1
        while(j>=0 and arr[j]>key):
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key
    return arr

nums=[]
n=int(input("Enter the size of the array:"))
for i in range(0,n):
    #ele=int(input(f"arr[{i}]:"))
    ele=random.randint(1,1000)
    nums.append(ele)

start_time=time.time()
print(Insertion_Sort(nums))
end_time=time.time()

print(f"Execution Time:{start_time-end_time:.7f} seconds")