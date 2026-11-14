import time
def Bubble_sort(arr):
    for i in range(0,len(arr)):
        for j in range(0,len(arr)-i-1):
            if(arr[j]>arr[j+1]):
                temp=arr[j]
                arr[j]=arr[j+1]
                arr[j+1]=temp   
    return arr

nums=[]
n=int(input("Enter No. of array elements:"))
for i in range(0,n):
    ele=int(input(f"arr[{i}]:"))
    nums.append(ele)

start_time=time.time()
print(Bubble_sort(nums))
end_time=time.time()
print(f"Execution Time:{start_time-end_time} seconds")