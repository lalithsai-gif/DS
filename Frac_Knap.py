import time

def frac_knap(values,weights,W):
    n=len(values)
    ratios=[(values[i]/weights[i],values[i],weights[i]) for i in range(n)]
    ratios.sort(reverse=True)
    total_val=0.0
    
    #print(ratios)

    for ratio,values,weights in ratios:
        if(W<=0):
            break

        if(weights<=W):
            total_val=total_val+values
            W=W-weights
        else:
            total_val+=values*(W/weights)
            break

    return total_val

n=int(input("Enter size of array:"))
arr=[]
wei=[]
for i in range(n):
    ele=int(input(f"values[{i}]:"))
    arr.append(ele)
    el=int(input(f"weights[{i}]:"))
    wei.append(el)
w=int(input("Enter the Capacity of the bag:"))

print(arr)
print()
print(wei)
# ratios=[(arr[i]/wei[i]) for i in range(n)]

s=time.time()
profit=frac_knap(arr,wei,w)
e=time.time()
print(profit,"\n","time:",s-e)

